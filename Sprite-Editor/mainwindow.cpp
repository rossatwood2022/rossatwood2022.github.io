/*
 * 11/14/2024
 *
 * Didar Jaff, Adam Kaufmann, Ahmad Al Najjar,
 * Nikiel Meeks, Quinn Sakelaris, and Milo Atwood
 *
 * This is the .cpp file for MainWindow. Here is where each widget is connected from the
 * ui to the model, or model to the ui. The Editor Frame also runs out of this class.
 *
 * Reviewed by Milo
*/
#include "mainwindow.h"
#include "editorframe.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Setup of ui component styles.
    ui->setupUi(this);
    ui->canvas->setStyleSheet("#canvas {border: 3px solid black;} ");
    ui->optionsBox->setStyleSheet("#optionsBox {border: 3px solid black;}");
    ui->previewView->setStyleSheet("#previewView {border: 3px solid black;}");
    ui->fpsSlider->setRange(3,24);
    ui->fpsSlider->setSingleStep(3);
    ui->fpsSlider->setTickInterval(3);
    ui->fpsSlider->setTickPosition(QSlider::TicksBelow);
    ui->colorDisplay->setEnabled(false);
    ui->colorDisplay->setStyleSheet("background-color: black;");
    ui->frameSizeDisplay->setText("Frame Size: 16x16");
    ui->penSizeDisplay->setText("Pen Size: 1");


    // Frame Editing
    connect(ui->frame, &EditorFrame::mousePress, &model, &Model::mousePressed);
    connect(ui->frame, & EditorFrame::mouseMove, &model, &Model::mouseMoved);
    connect(ui->frame, &EditorFrame::mouseRelease, &model, &Model::mouseReleased);
    connect(&model, &Model::updateFrame, ui->frame, &EditorFrame::updateFrame);
    connect(&model, &Model::sendColor, this, &MainWindow::updateColor);

    // Show color selection
    connect(ui->colorButton, &QPushButton::clicked, &model, &Model::setColor);

    // Show erase buttons
    connect(ui->eraseButton, &QPushButton::clicked, this, &MainWindow::drawClicked);
    // Toggle erase mode
    connect(ui->eraseButton, &QPushButton::clicked, &model, &Model::changeErasing);

    // Frame manipulations buttons
    connect(ui->addFrame, &QPushButton::clicked, &model, &Model::addFrame);
    connect(ui->subFrame, &QPushButton::clicked, &model, &Model::subFrame);
    connect(ui->moveLeft, &QPushButton::clicked, &model, &Model::moveLeft);
    connect(ui->moveRight, &QPushButton::clicked, &model, &Model::moveRight);
    connect(ui->duplicateFrame, &QPushButton::clicked, &model, &Model::duplicateFrame);
    connect(&model, &Model::updateCurrentFrameText, this, &MainWindow::updateCurrentFrameText);
    connect(&model, &Model::updateTotalFrameText, this, &MainWindow::updateTotalFrameText);

    // Clear the current frame
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clearClicked);
    connect(this, &MainWindow::clear, &model, &Model::clearFrame);

    // Show Frame Size buttons
    connect(ui->sizeButton, &QPushButton::clicked, this, &MainWindow::sizeClicked);
    // Frame Size Buttons
    connect(ui->size8Button, &QPushButton::clicked, this, &MainWindow::changeSizeTo8);
    connect(ui->size16Button, &QPushButton::clicked, this, &MainWindow::changeSizeTo16);
    connect(ui->size32Button, &QPushButton::clicked, this, &MainWindow::changeSizeTo32);
    connect(ui->size64Button, &QPushButton::clicked, this, &MainWindow::changeSizeTo64);
    connect(this, &MainWindow::editFrameSize, &model, &Model::editFrameSize);

    // Show Pen Size Buttons
    connect(ui->drawButton, &QPushButton::clicked, this, &MainWindow::drawClicked);
    // Pen Size Buttons
    connect(ui->penSize1, &QPushButton::clicked, this, &MainWindow::changePenSize1);
    connect(ui->penSize2, &QPushButton::clicked, this, &MainWindow::changePenSize2);
    connect(ui->penSize3, &QPushButton::clicked, this, &MainWindow::changePenSize3);
    connect(ui->penSize4, &QPushButton::clicked, this, &MainWindow::changePenSize4);
    connect(this, &MainWindow::editPenSize, &model, &Model::editPenSize);

    // Undo and Redo Buttons
    connect(ui->undoButton, &QPushButton::clicked, &model, &Model::undo);
    connect(ui->redoButton, &QPushButton::clicked, &model, &Model::redo);

    // Show File buttons
    connect(ui->fileButton, &QPushButton::clicked, this, &MainWindow::fileClicked);
    // File Buttons
    connect(ui->SaveBu, &QPushButton::clicked, &model, &Model::saveFrame);
    connect(ui->LoadButton, &QPushButton::clicked, &model, &Model::loadFrame);
    connect(&model, &Model::sendFrameSize, this, &MainWindow::updateLoadedSize);

    // Preview window functionality
    connect(&model, &Model::updatePreviewImage, this, &MainWindow::updatePreviewImage);
    connect(ui->fpsSlider, &QSlider::sliderMoved, this, &MainWindow::getFps);
    connect(this, &MainWindow::changeTimeout, &model, &Model::startTimeout);
    connect(ui->pauseButton, &QPushButton::clicked, &model, &Model::updatePause);

    // Show symmetry buttons
    connect(ui->symmetricalButton, &QPushButton::clicked, this, &MainWindow::symmetricalClicked);
    // Symmetry buttons
    connect(ui->HorizontalButton, &QPushButton::clicked, &model, &Model::changeHorizontal);
    connect(ui->VerticalButton, &QPushButton::clicked, &model, &Model::changeVertical);
    connect(&model, &Model::unCheckVertical, this, &MainWindow::unCheckVertical);
    connect(&model, &Model::unCheckHorizontal, this, &MainWindow::unCheckHorizontal);

    // Show shift buttons
    connect(ui->shiftButton, &QPushButton::clicked, this, &MainWindow::shiftClicked);
    // Shift buttons
    connect(ui->shiftRightButton, &QPushButton::clicked, this, &MainWindow::shiftOptionRight);
    connect(ui->shiftLeftButton, &QPushButton::clicked, this, &MainWindow::shiftOptionLeft);
    connect(ui->shiftUpButton, &QPushButton::clicked, this, &MainWindow::shiftOptionUp);
    connect(ui->shiftDownButton, &QPushButton::clicked, this, &MainWindow::shiftOptionDown);
    connect(this, &MainWindow::updateShift, &model, &Model::shift);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::symmetricalClicked(){
    ui->optionsBox->setCurrentWidget(ui->symmetryView);
}

void MainWindow::colorClicked(){
    ui->optionsBox->setCurrentWidget(ui->colorView);
}

void MainWindow::fileClicked(){
    QMessageBox::question(this , "Warning", "Loading files will lose any unsaved progress!", QMessageBox::Ok);
    ui->optionsBox->setCurrentWidget(ui->fileView);
}

void MainWindow::drawClicked(){
    ui->optionsBox->setCurrentWidget(ui->penView);
}

void MainWindow::shiftClicked(){
    ui->optionsBox->setCurrentWidget(ui->shiftView);
}

void MainWindow::sizeClicked(){
    ui->optionsBox->setCurrentWidget(ui->sizeView);
}

void MainWindow::clearClicked(){
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this , "Warning", "Are you sure you want to clear? All unsaved progress will be lost!");
    if(button == QMessageBox::Yes){
        emit clear();
    }
}

void MainWindow::changeSizeTo8(){
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this , "Warning", "Are you sure you want to clear? All unsaved progress will be lost!");
    if(button == QMessageBox::Yes){
        emit clear();
        ui->frameSizeDisplay->setText("Frame Size: 8x8");
        ui->size16Button->setChecked(false);
        ui->size32Button->setChecked(false);
        ui->size64Button->setChecked(false);
        emit editFrameSize(8);
    }
    else {
        ui->size8Button->setChecked(false);
    }
}

void MainWindow::changeSizeTo16(){
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this , "Warning", "Are you sure you want to clear? All unsaved progress will be lost!");
    if(button == QMessageBox::Yes){
        emit clear();
        ui->frameSizeDisplay->setText("Frame Size: 16x16");
        ui->size8Button->setChecked(false);
        ui->size32Button->setChecked(false);
        ui->size64Button->setChecked(false);
        emit editFrameSize(16);
    }
    else {
        ui->size16Button->setChecked(false);
    }
}

void MainWindow::changeSizeTo32(){
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this , "Warning", "Are you sure you want to clear? All unsaved progress will be lost!");
    if(button == QMessageBox::Yes){
        emit clear();
        ui->frameSizeDisplay->setText("Frame Size: 32x32");
        ui->size8Button->setChecked(false);
        ui->size16Button->setChecked(false);
        ui->size64Button->setChecked(false);
        emit editFrameSize(32);
    }
    else {
        ui->size32Button->setChecked(false);
    }
}

void MainWindow::changeSizeTo64(){
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this , "Warning", "Are you sure you want to clear? All unsaved progress will be lost!");
    if(button == QMessageBox::Yes){
        emit clear();
        ui->frameSizeDisplay->setText("Frame Size: 64x64");
        ui->size8Button->setChecked(false);
        ui->size16Button->setChecked(false);
        ui->size32Button->setChecked(false);
        emit editFrameSize(64);
    }
    else {
        ui->size64Button->setChecked(false);
    }
}

void MainWindow::changePenSize1(){
    ui->penSizeDisplay->setText("Pen Size: 1");
    ui->penSize2->setChecked(false);
    ui->penSize3->setChecked(false);
    ui->penSize4->setChecked(false);
    emit editPenSize(1);
}

void MainWindow::changePenSize2(){
    ui->penSizeDisplay->setText("Pen Size: 2");
    ui->penSize1->setChecked(false);
    ui->penSize3->setChecked(false);
    ui->penSize4->setChecked(false);
    emit editPenSize(2);
}

void MainWindow::changePenSize3(){
    ui->penSizeDisplay->setText("Pen Size: 3");
    ui->penSize1->setChecked(false);
    ui->penSize2->setChecked(false);
    ui->penSize4->setChecked(false);
    emit editPenSize(3);
}

void MainWindow::changePenSize4(){
    ui->penSizeDisplay->setText("Pen Size: 4");
    ui->penSize1->setChecked(false);
    ui->penSize2->setChecked(false);
    ui->penSize3->setChecked(false);
    emit editPenSize(4);
}

void MainWindow::updateCurrentFrameText(QString newText) {
    ui->currFrameLabel->setText(newText);
}

void MainWindow::updateTotalFrameText(QString newText) {
    ui->totalFrameLabel->setText(newText);
}

void MainWindow::updatePreviewImage(QImage image) {
    ui->previewImage->setPixmap(QPixmap::fromImage(image));
    emit changeTimeout(ui->fpsSlider->sliderPosition());

}

void MainWindow::getFps() {
    emit changeTimeout(ui->fpsSlider->sliderPosition());
}

void MainWindow::updateColor(QColor color){
    QString colorStyle = QString("background-color: %1; color: white;").arg(color.name());
    ui->colorDisplay->setStyleSheet(colorStyle);
}

void MainWindow::shiftOptionRight(){
    emit updateShift(0);
}

void MainWindow::shiftOptionLeft(){
    emit updateShift(1);
}

void MainWindow::shiftOptionUp(){
    emit updateShift(2);
}

void MainWindow::shiftOptionDown(){
    emit updateShift(3);
}

void MainWindow::unCheckVertical(){
    ui->VerticalButton->setChecked(false);
}

void MainWindow::unCheckHorizontal(){
    ui->HorizontalButton->setChecked(false);
}

void MainWindow::updateLoadedSize(int size){
    switch(size){
        case 8:
            ui->frameSizeDisplay->setText("Frame Size: 8x8");
            ui->size8Button->setChecked(true);
            ui->size16Button->setChecked(false);
            ui->size32Button->setChecked(false);
            ui->size64Button->setChecked(false);
            break;
        case 16:
            ui->frameSizeDisplay->setText("Frame Size: 16x16");
            ui->size8Button->setChecked(false);
            ui->size16Button->setChecked(false);
            ui->size32Button->setChecked(false);
            ui->size16Button->setChecked(true);
            break;
        case 32:
            ui->frameSizeDisplay->setText("Frame Size: 32x32");
            ui->size8Button->setChecked(false);
            ui->size16Button->setChecked(false);
            ui->size32Button->setChecked(false);
            ui->size32Button->setChecked(true);
            break;
        case 64:
            ui->frameSizeDisplay->setText("Frame Size: 64x64");
            ui->size8Button->setChecked(false);
            ui->size16Button->setChecked(false);
            ui->size32Button->setChecked(false);
            ui->size64Button->setChecked(true);
            break;
    }
}
