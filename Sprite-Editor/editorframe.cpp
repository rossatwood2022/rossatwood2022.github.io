/*
 * 11/14/2024
 *
 * Didar Jaff, Adam Kaufmann, Ahmad Al Najjar
 * Nikiel Meeks, Quinn Sakelaris, Milo Atwood
 *
 * The editor frame class overrides QWidget mouse events that are connected to the model.
 *
 * Reviewed by Quinn
 */
#include "editorframe.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

EditorFrame::EditorFrame(QWidget * parent) : QWidget(parent) {}

void EditorFrame::mousePressEvent(QMouseEvent *event) {
    emit mousePress(event);
}

void EditorFrame::mouseMoveEvent(QMouseEvent *event) {
    emit mouseMove(event);
}

void EditorFrame::mouseReleaseEvent(QMouseEvent *event) {
    emit mouseRelease(event);
}

void EditorFrame::updateFrame(QImage canvas){
    frame = canvas;
    this->update();
}

void EditorFrame::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawImage(0, 0, frame);
}
