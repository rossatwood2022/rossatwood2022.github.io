/*
 * 11/14/2024
 *
 * Didar Jaff, Adam Kaufmann, Ahmad Al Najjar
 * Nikiel Meeks, Quinn Sakelaris, Milo Atwood
 *
 * This is the header for the editor frame class, which extends a QWidget.
 * This allows the developers to place an editor frame in the ui that symbolizes a canvas,
 * in order to override mouse events that can be connected to the model, and its drawing functionality.
 *
 * Reviewed by Didar
 */
#ifndef EDITORFRAME_H
#define EDITORFRAME_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QObject>
#include <QMouseEvent>
#include <QImage>

class EditorFrame : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief EditorFrame constructor, extends QWidget
     */
    explicit EditorFrame(QWidget* parent = nullptr);

    /**
     * @brief mousePressEvent emits a signal to tell model to draw
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief mouseMoveEvent emits a signal to tell model to draw
     */
    void mouseMoveEvent(QMouseEvent *event) override;

    /**
     * @brief mouseReleaseEvent emits a signal to tell model that drawing is finished
     */
    void mouseReleaseEvent(QMouseEvent *event) override;

    /**
     * @brief updateFrame updates the frame variable and calls update
     * @param canvas the image to be held in frame
     */
    void updateFrame(QImage canvas);

private:
    /**
     * @brief paintEvent draws the frame onto this widget
     */
    void paintEvent(QPaintEvent *event) override;

    /**
     * @brief frame the image to be drawn onto the widget
     */
    QImage frame;

signals:
    /**
     * @brief mousePress tells model to draw
     */
    void mousePress(QMouseEvent *event);
    /**
     * @brief mouseMove tells model to draw
     */
    void mouseMove(QMouseEvent *event);
    /**
     * @brief mouseRelease tells model that drawing is finished
     */
    void mouseRelease(QMouseEvent *event);
};

#endif // EDITORFRAME_H
