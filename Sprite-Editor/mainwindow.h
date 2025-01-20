/*
 * 11/14/2024
 *
 * Didar Jaff, Adam Kaufmann, Ahmad Al Najjar,
 * Nikiel Meeks, Quinn Sakelaris, and Milo Atwood
 *
 * This .h file holds all of the components of the Main Window. Here is where each widget is connected from the
 * ui to the model, or model to the ui. The Editor Frame also runs out of this class.
 *
 * Reviewed by Ahmad
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief MainWindow This constructor initializes our MainWindow by forming all necessary connections,
     *        and storing the necessary components for model <-> window <-> frame editor communication.
     *
     * @param model A model object to open communication between model and MainWindow
     * @param parent A reference from QWidget to be able to inherit all necessary methods
     */
    MainWindow(Model& model, QWidget *parent = nullptr);
    
    /**
     * A destructor for a MainWindow
     */
    ~MainWindow();

public slots:

    /**
     * @brief symmetricalClicked This method receives a signal from the Ui to activate the symmetry options.
     */
    void symmetricalClicked();

    /**
     * @brief colorClicked This method receives a signal from the Ui to activate the color options.
     */
    void colorClicked();

    /**
     * @brief fileClicked This method receives a signal from the Ui to activate the file options.
     */
    void fileClicked();

    /**
     * @brief drawClicked This method receives a signal from the Ui to activate the pen options.
     */
    void drawClicked();

    /**
     * @brief shiftClicked This method receives a signal from the Ui to activate the shift options.
     */
    void shiftClicked();

    /**
     * @brief sizeClicked This method receives a signal from the Ui to activate the frame size options.
     */
    void sizeClicked();

    /**
     * @brief clearClicked This method receives a signal from the Ui to prompt the user if they want to clear.
     */
    void clearClicked();

    /**
     * @brief changeSizeTo8 This method receives a signal from the Ui to change the frame size to 8x8
     *        Note that this button is only visible if the size button has already been clicked
     */
    void changeSizeTo8();

    /**
     * @brief changeSizeTo16 This method receives a signal from the Ui to change the frame size to 16x16
     *        Note that this button is only visible if the size button has already been clicke
     */
    void changeSizeTo16();

    /**
     * @brief changeSizeTo32 This method receives a signal from the Ui to change the frame size to 32x32
     *        Note that this button is only visible if the size button has already been clicked.
     */
    void changeSizeTo32();

    /**
     * @brief changeSizeTo64 This method receives a signal from the Ui to change the frame size to 64x64
     *        Note that this button is only visible if the size button has already been clicked.
     */
    void changeSizeTo64();

    /**
     * @brief changePenSize1 This method receives a signal from the Ui to change pen size to 1x1 pixels.
     *        Note that this button is only visible if the draw butotn has already been clicked.
     */
    void changePenSize1();

    /**
     * @brief changePenSize2 This method receives a signal from the Ui to change pen size to 2x2 pixels.
     *        Note that this button is only visible if the draw button has already been clicked.
     */
    void changePenSize2();

    /**
     * @brief changePenSize3 This method receives a signal from the Ui to change pen size to 3x3 pixels.
     *        Note that this button is only visible if the draw button has already been clicked.
     */
    void changePenSize3();

    /**
     * @brief changePenSize4 This method receives a signal from the Ui to change pen size to 4x4 pixels.
     *        Note that this button is only visible if the draw butotn has already been clicked.
     */
    void changePenSize4();

   void shiftOptionRight();
   void shiftOptionLeft();
   void shiftOptionUp();
   void shiftOptionDown();

   void unCheckVertical();
   void unCheckHorizontal();

    /**
     * @brief updateCurrentFrameText This method receives a signal from the model to update the frame text to reflect
     *        the current focused frame It only updates if the current focused frame is moved
     *        left, right, added to, duplicated to, or subtracted.
     *
     * @param newText The new quantity to be reflected.
     */
    void updateCurrentFrameText(QString newText);

    /**
     * @brief updateLoadedSize This method receives a signal from the model. When a file is loaded it updates the frame size of the loaded file
     */
    void updateLoadedSize(int);

    /**
     * @brief updateTotalFrameText This method receives a signal from the model to update the total frame text to reflect
     *        the total amount of frames. It only updates if the total is added or subtracted to.
     *
     * @param newText The new quantity to be reflected.
     */
    void updateTotalFrameText(QString newText);

    /**
     * @brief updatePreviewImage This method receives a signal from the model to update the preview image to reflect the
     *        current animation of frames.
     *
     * @param image The image to update the preview with
     */
    void updatePreviewImage(QImage image);

    /**
     * @brief getFps This method receives a signal from the Ui to retreive the fps from the slider.
     */
    void getFps();

    /**
     * @brief updateColor This method receives a signal from the model to update the color
     * @param color The color to update
     */
    void updateColor(QColor color);

private:
    // This Ui object is how the model speaks to
    Ui::MainWindow *ui;

signals:
    /**
     * @brief clear Tells the model to clear
     */
    void clear();

    /**
     * @brief editFrameSize Tells the model to change the frame size
     * @param size The size of the new frame
     */
    void editFrameSize(int size);

    /**
     * @brief editPenSize Tells the model to change the size of the edit
     * @param size The new size of the pen
     */
    void editPenSize(int size);

    void updateShift(int i);

    /**
     * @brief changeTimeout Changes the speed at which the frames are cycled through in the preview
     * @param fps
     */
    void changeTimeout(int fps);
};
#endif // MAINWINDOW_H
