/*
 * 11/13/2024
 * Didar Jaff and Adam Kaufmann, Ahmad Al Najjar,
 * Nikel Meeks, Quinn Sakelaris, and Milo Atwood
 * Assignment 8: Qt Sprite Editor
 *
 * This is the header file that the model.cpp file uses
 *
 * Reviewed by Nikiel
 */

#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QPoint>
#include <QImage>
#include <QColor>
#include <QRect>
#include <QColorDialog>
#include <QTimer>
#include <QVector>
#include <QStack>
#include <QFileDIalog>
#include <QJsonArray>
#include <QJsonObject>
#include <QBuffer>
#include <QJsonDocument>
#include <QJsonObject>

/**
 * @class Model
 * @brief The Model class handels the core logic of a sprite editor, including
 * drawing on a canvas with different features, managing multiple canvases,
 * and a preview of an animated sprite.
 */
class Model : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief This constructor creates an instance of a model object. Drawing attributes,
     * canvas storage, and animation settings are initialized.
     * @param parent object inherits from QObject
     */
    explicit Model(QObject *parent = nullptr);

private:
    // Number of pixels in the frame
    int frameSize;

    // The size of each pixel to draw
    int pixelSize;

    // Number of pixels the pen draw as penSize x penSize
    int penSize;

    // The flag for erasing pixels instead of drawing them
    bool erasing;

    // The color that is selected to draw on the canvas
    QColor currentColor;

    // The QImage that is displayed on the canvas
    QImage currentCanvas;

    // The different QImage frames of the sprite
    QVector<QImage> frames;

    // A vector of undo stacks for each frame
    QVector<QStack<QImage>> undoFrames;

    // A vector of redo stacks for each frame
    QVector<QStack<QImage>> redoFrames;

    // The index of the frame that is currently displayed and edited
    int currentFrameIndex = 0;

    // The timer to change the displayed frame in the preview
    QTimer* timer;

    // A flag to enable or disable the preview animation
    bool paused;

    // T\he index of the frames that is displayed in the preview
    int frameIndex;

    // Flag used for mouse events to determine when to draw based on the current state of the mouse.
    bool isDrawing;

    // The flag used to draw pixels that are horrizontally symmetric to the selected position
    bool isHorizontal = false;

    // The flag used to draw pixels that are vertically symmetric to the selected position
    bool isVertical = false;

    // Private methods for drawing and managing both the preview view and canvases

    /**
     * @brief Draws a pixel or square of pixels at a specifed position on the canvas.
     * @param pos The x and y position of the mouse on the canvas where the pixel is drawn.
     */
    void drawAt(const QPoint& pos);

    /**
     * @brief Draws pixels symmetrically across the x-axis.
     * @param pos The x and y position of the mouse on the canvas where the pixel is drawn.
     */
    void drawHorizontal(const QPoint& pos);

    /**
     * @brief Draws pixels symmetrically across the y-axis
     * @param pos The x and y position of the mouse on the canvas where the pixel is drawn.
     */
    void drawVertical(const QPoint& pos);

    /**
     * @brief Creates a blank canvas where every pixel is transparent.
     * @return Returns a blank QImage canvas.
     */
    QImage createFrame();
    
    /**
     * @brief Sets the brush size to a two by two sqaure of pixels.
     * @param pixel The starting position for drawing.
     */
    void draw2By2(const QPoint& pixel);

    /**
     * @brief Sets the brush size to a three by three square of pixels.
     * @param pixel The starting position for drawing.
     */
    void draw3By3(const QPoint& pixel);

    /**
     * @brief Sets the brush size to a three by three square of pixels.
     * @param pixel The starting position for drawing.
     */
    void draw4By4(const QPoint& pixel);

    /**
     * @brief Updates the preview view and the current canvas view.
     */
    void updateView();
    
signals:
    /**
     * @brief Signal emitted to update the canvas in the UI.
     * @param canvas The updated QImage that is the current canvas.
     */
    void updateFrame(QImage canvas);

    /**
     * @brief Signal emitted when horizontal symmetry mode is on.
     */
    void horizontalSignal();

    /**
     * @brief Signal emitted when vertical symmetry mode is on.
     */
    void verticalSignal();

    /**
     * @brief Signal emitted
     * @param newText
     */
    void updateCurrentFrameText(QString newText);

    /**
     * @brief updateTotalFrameText
     * @param newText
     */
    void updateTotalFrameText(QString newText);

    /**
     * @brief sendColor
     * @param color
     */
    void sendColor(QColor color);

    /**
     * @brief updatePreviewImage
     * @param image
     */
    void updatePreviewImage(QImage image);
    void sendFrameSize(int size);

    void unCheckVertical();

    void unCheckHorizontal();

public slots:
    /**
     * @brief mousePressed
     * @param event
     */
    void mousePressed(QMouseEvent *event);

    /**
     * @brief mouseMoved
     * @param event
     */
    void mouseMoved(QMouseEvent *event);

    /**
     * @brief mouseReleased
     * @param event
     */
    void mouseReleased(QMouseEvent *event);
    
    /**
     * @brief addFrame
     */
    void addFrame();

    /**
     * @brief subFrame
     */
    void subFrame();

    /**
     * @brief duplicateFrame
     */
    void duplicateFrame();

    /**
     * @brief clearFrame
     */
    void clearFrame();

    /**
     * @brief moveLeft
     */
    void moveLeft();

    /**
     * @brief moveRight
     */
    void moveRight();

    /**
     * @brief editFrameSize
     * @param size
     */
    void editFrameSize(int size);

    /**
     * @brief editPenSize
     * @param size
     */
    void editPenSize(int size);
    
    /**
     * @brief setColor
     */
    void setColor();

    /**
     * @brief changeErasing
     */
    void changeErasing();

    /**
     * @brief undo
     */
    void undo();

    /**
     * @brief redo
     */
    void redo();

    /**
     * @brief saveFrame
     */
    void saveFrame();

    /**
     * @brief loadFrame
     */
    void loadFrame();

    /**
     * @brief changePreviewImage
     */
    void changePreviewImage();

    /**
     * @brief startTimeout
     * @param fps
     */
    void startTimeout(int fps);

    /**
     * @brief updatePause
     */
    void updatePause();

    /**
     * @brief changeHorizontal
     */
    void changeHorizontal();

    /**
     * @brief changeVertical
     */
    void changeVertical();

    /**
     * @brief shift
     * @param i
     */
    void shift(int i);
};

#endif // MODEL_H
