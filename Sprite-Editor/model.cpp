/*
 * 11/13/2024
 * Didar Jaff and Adam Kaufmann, Ahmad Al Najjar,
 * Nikel Meeks, Quinn Sakelaris, and Milo Atwood
 * Assignment 8: Qt Sprite Editor
 *
 * This file implements the model class defined in the model.h file. The model object handles
 * all of the logic for the sprite editor.
 *
 * Reviewed by Adam
 */

#include "model.h"

// Model Constructor
Model::Model(QObject *parent) : QObject(parent) {
    currentCanvas = createFrame();
    frames.push_back(currentCanvas);
    undoFrames.push_back(QStack<QImage>());
    redoFrames.push_back(QStack<QImage>());
    frameSize = 16;
    pixelSize = 512/frameSize;
    penSize = 1;
    erasing = false;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Model::changePreviewImage);
}

// Slot to update the preview view
void Model::changePreviewImage() {
    if(frameIndex >= frames.size()){
        frameIndex = 0;
    }
    if(!paused) {
        QImage image = frames[frameIndex++].scaled(190, 190, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        emit updatePreviewImage(image);
    }
}

// Starts the timer with given fps
void Model::startTimeout(int fps) {
    timer->start(1000/fps);
}

// Updates the preview view to be paused on the current canvas, or play the animation that the canvas frames create
void Model::updatePause() {
    paused = !paused;
    frames[currentFrameIndex] = currentCanvas;
    QImage image = currentCanvas.scaled(190, 190, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    emit updatePreviewImage(image);
}

// Creates a blank canvas
QImage Model::createFrame() {
    QImage newFrame = QImage(512, 512, QImage::Format_ARGB32);
    newFrame.fill(Qt::transparent); // Initialize with a white background
    return newFrame;
}

// Handles drawing on mouse pressed events in addition to drawing with bigger pen sizes
void Model::mousePressed(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        isDrawing = true;
        undoFrames[currentFrameIndex].push_back(currentCanvas);
        redoFrames[currentFrameIndex].clear();
        QPoint snappedPos = QPoint(event->pos().x() / pixelSize * pixelSize, event->pos().y() / pixelSize * pixelSize);
        if(penSize == 1) { //If statements handle different pen sizes
            drawAt(snappedPos);
        }
        if(penSize == 2) {
            draw2By2(snappedPos);
        }
        if(penSize == 3) {
            draw3By3(snappedPos);
        }
        if(penSize == 4) {
            draw4By4(snappedPos);
        }
    }

}

// handles drawing on mouse moved events in addition to drawing with bigger pen sizes
void Model::mouseMoved(QMouseEvent *event) {
    if (isDrawing) {
        QPoint snappedPos = QPoint(event->pos().x() / pixelSize * pixelSize, event->pos().y() / pixelSize * pixelSize);
        if(penSize == 1) {
            drawAt(snappedPos); //If statements handle different pen sizes
        }
        if(penSize == 2) {
            draw2By2(snappedPos);
        }
        if(penSize == 3) {
            draw3By3(snappedPos);
        }
        if(penSize == 4) {
            draw4By4(snappedPos);
        }
    }
}

// Handles drawing stopping on mouse released events
void Model::mouseReleased(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        isDrawing = false;
    }
    updateView();
}

// Clears the current canvas of all drawn pixels
void Model::clearFrame() {
    undoFrames[currentFrameIndex].push_back(currentCanvas);
    currentCanvas.fill(Qt::transparent);
    updateView();
}

// Changes the size of all of the canvases based on selected size
void Model::editFrameSize(int size) {
    frameSize = size;
    pixelSize = 512/frameSize;
    frames.clear();
    currentCanvas = createFrame();
    frames.push_back(currentCanvas);
    currentFrameIndex = 0;
    emit updateCurrentFrameText(QString("Current frame: %1").arg(currentFrameIndex +1 ));
    emit updateTotalFrameText(QString("Total frames: %1").arg(frames.size()));
}

// Changes pen size
void Model::editPenSize(int size) {
    penSize = size;
}

// Draws pixels at current position of the mouse
void Model::drawAt(const QPoint &snappedPos) {
    QPainter painter(&currentCanvas);
    painter.setPen(Qt::NoPen);
    if(erasing) { //Erases pixels if eraser is selected
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.setBrush(Qt::transparent);
    }
    else {
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        painter.setBrush(currentColor);
    }
    QRect rect(snappedPos.x(),snappedPos.y(),pixelSize,pixelSize);
    painter.drawRect(rect);
    if(isHorizontal) { //If symmetry options are enabled, draws additional pixels
        QRect mirrorRect(snappedPos.x(), 512 - pixelSize - snappedPos.y(),pixelSize,pixelSize);
        painter.drawRect(mirrorRect);
    }
    else if(isVertical) {
        QRect mirrorRect(512 - pixelSize - snappedPos.x(), snappedPos.y(),pixelSize,pixelSize);
        painter.drawRect(mirrorRect);
    }
    emit updateFrame(currentCanvas); // Update only the modified area
}

// Updates drawing fuctionality to draw horizontally symmetric
void Model::changeHorizontal() {
    isHorizontal = !isHorizontal;
    isVertical = false;
    emit unCheckVertical(); //true means unCheck vertical
}

// Updates drawing fuctionality to draw vertically symmetric
void Model::changeVertical() {
    isVertical = !isVertical;
    isHorizontal = false;
    emit unCheckHorizontal(); //false means unCheck horizontal
}


// Adds a new canvas to the right of the current canvas and refocuses on it
void Model::addFrame(){
    if(frames.size() >= 99){
        return;
    }
    // Save any updates that were drawn on currentCanvas
    frames[currentFrameIndex] = currentCanvas;
    QImage newFrame = createFrame();
    undoFrames.insert(undoFrames.begin() + currentFrameIndex + 1, QStack<QImage>());
    redoFrames.insert(redoFrames.begin() + currentFrameIndex + 1, QStack<QImage>());
    frames.insert(frames.begin() + currentFrameIndex + 1, newFrame);
    currentCanvas = newFrame;
    currentFrameIndex++;
    updateView();
}

// Deletes the current canvas and refocuses on the canvas to the left
void Model::subFrame() {
    if(frames.size() == 1) {
        return;
    }
    undoFrames.erase(undoFrames.begin() + currentFrameIndex);
    redoFrames.erase(redoFrames.begin() + currentFrameIndex);
    frames.erase(frames.begin() + currentFrameIndex);
    if(currentFrameIndex > 0){
        currentFrameIndex--;
    }
    currentCanvas = frames.at(currentFrameIndex);
    updateView();
}

// Changes focus to the canvas on the left
void Model::moveLeft() {
    if(currentFrameIndex == 0) {
        return;
    }
    // Save any updates that were drawn on currentCanvas and refocus
    frames[currentFrameIndex] = currentCanvas;
    currentCanvas = frames[--currentFrameIndex];
    updateView();
}

// Changes focus to the canvas on the right
void Model::moveRight() {
    if(currentFrameIndex == frames.size() - 1) {
        return;
    }
    // Save any updates that were drawn on currentCanvas and refocus
    frames[currentFrameIndex] = currentCanvas;
    currentCanvas = frames[++currentFrameIndex];
    updateView();
}

// Adds a duplicate of the current canvas to the right and refocuses on it
void Model::duplicateFrame() {
    if(frames.size() >= 99){
        return;
    }
    frames[currentFrameIndex] = currentCanvas;
    QImage duplicate(currentCanvas);
    undoFrames.insert(undoFrames.begin() + currentFrameIndex + 1, QStack<QImage>());
    redoFrames.insert(redoFrames.begin() + currentFrameIndex + 1, QStack<QImage>());
    frames.insert(frames.begin() + currentFrameIndex + 1, duplicate);
    currentCanvas = duplicate;
    currentFrameIndex++;
    updateView();
}

// Sets the color based on the selected color
void Model::setColor() {
    currentColor = QColorDialog::getColor(currentColor, nullptr, "SelectColor");
    emit sendColor(currentColor);
}

// Turns erasing on and off
void Model::changeErasing() {
    erasing = !erasing;
}

// Changes the size of the brush to draw a two by two rectangle of pixels
void Model::draw2By2(const QPoint& pixel) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            drawAt(QPoint(pixel.x() - pixelSize * i, pixel.y() - pixelSize * j));
        }
    }
}

// Changes the size of the brush to draw a three by three rectangle of pixels
void Model::draw3By3(const QPoint& pixel) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            drawAt(QPoint(pixel.x() - pixelSize * i, pixel.y() - pixelSize * j));
        }
    }
}

// Changes the size of the brush to draw a four by four rectangle of pixels
void Model::draw4By4(const QPoint& pixel) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            drawAt(QPoint(pixel.x() - pixelSize * i, pixel.y() - pixelSize * j));
        }
    }
}

// Undoes the last action of the user
void Model::undo() {
    if(undoFrames[currentFrameIndex].size() > 0) {
        QImage undoCanvas = undoFrames[currentFrameIndex].pop();
        redoFrames[currentFrameIndex].push_back(currentCanvas);
        currentCanvas = undoCanvas;
        updateView();
    }
}

// Redoes what undo does
void Model::redo() {
    if(redoFrames[currentFrameIndex].size() > 0) {
        QImage redoCanvas = redoFrames[currentFrameIndex].pop();
        undoFrames[currentFrameIndex].push_back(currentCanvas);
        currentCanvas = redoCanvas;
        updateView();
    }
}

// Updates the preview view, current canvas view and the labels of for frame numbers
void Model::updateView() {
    frames[currentFrameIndex] = currentCanvas;
    emit updateFrame(currentCanvas);
    QImage image = currentCanvas.scaled(190, 190, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    emit updatePreviewImage(image);
    emit updateCurrentFrameText(QString("Current frame: %1").arg(currentFrameIndex + 1));
    emit updateTotalFrameText(QString("Total frames: %1").arg(frames.size()));
}

// Shifts every pixel right, left, up, or down based on which button is clicked
void Model::shift(int i) {
    undoFrames[currentFrameIndex].push_back(currentCanvas);
    redoFrames[currentFrameIndex].clear();
    QImage tempCanvas = currentCanvas.copy();
    currentCanvas.fill(Qt::transparent);
    QPainter painter(&currentCanvas);
    switch(i) {
    case 0:
        painter.drawImage(pixelSize, 0, tempCanvas);
        break;
    case 1:
        painter.drawImage(-pixelSize, 0, tempCanvas);
        break;
    case 2:
        painter.drawImage(0, -pixelSize, tempCanvas);
        break;
    case 3:
         painter.drawImage(0, pixelSize, tempCanvas);
        break;
    default :
        break;
    }
    updateView();
}

// Saves entire sprite as a .json file
void Model::saveFrame() {
    QString filename = QFileDialog::getSaveFileName(nullptr, "Save File" , "", "JSON Files (*.json);;All Files (*)");
    if(filename.isEmpty()) {
        return;
    }
    QFile file(filename);
    QJsonArray jsonArray;
    QJsonObject jsonobject;
    for(const QImage &image: frames){
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        image.save(&buffer, "PNG");
        QString s = QString::fromLatin1(byteArray.toBase64());
        jsonArray.append(s);
    }
    jsonobject["size"] = frameSize;
    jsonobject["frames"] = jsonArray;
    file.open(QIODevice::WriteOnly);
    QJsonDocument jsonDocument(jsonobject);
    file.write(jsonDocument.toJson(QJsonDocument::Indented));
    file.close();
}

// Loads a valid .json file
void Model::loadFrame(){
    QString filename = QFileDialog::getOpenFileName(nullptr, tr("Open File"), "/home", "JSON Files (*.json);;All Files (*)");
    if(filename.isEmpty()) {
        return;
    }
    undoFrames.clear();
    redoFrames.clear();
    QByteArray byteArray;
    QJsonObject jsonobject;
    QVector<QImage> loadedVector;
    QFile file(filename);
  
    file.open(QIODevice::ReadOnly);
    byteArray = file.readAll();
    QJsonDocument jdoc = QJsonDocument::fromJson(byteArray);
    frameSize = jdoc["size"].toInt();
    editFrameSize(frameSize);
    emit sendFrameSize(frameSize);
    for(const QJsonValue &frame : jdoc["frames"].toArray()){

        QString base64Frame = frame.toString();
        QByteArray imageData = QByteArray::fromBase64(base64Frame.toLatin1());
        QImage image;
        QBuffer buffer(&imageData);
        buffer.open(QIODevice::ReadOnly);
        image.load(&buffer, "PNG");
        loadedVector.push_back(image);
    }
    frames.clear();
    for(const QImage &img : loadedVector) {
        frames.push_back(img);
        undoFrames.push_back(QStack<QImage>());
        redoFrames.push_back(QStack<QImage>());
    }
    emit updateTotalFrameText(QString("Total frames: %1").arg(frames.size()));
    currentCanvas = loadedVector[currentFrameIndex];
    emit updateFrame(currentCanvas);
    QImage preview = currentCanvas.scaled(190, 190, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    emit updatePreviewImage(preview);
    file.close();
}
