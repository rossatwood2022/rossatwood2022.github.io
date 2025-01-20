/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "editorframe.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *canvas;
    EditorFrame *frame;
    QPushButton *subFrame;
    QPushButton *moveLeft;
    QPushButton *addFrame;
    QPushButton *moveRight;
    QLabel *currFrameLabel;
    QLabel *totalFrameLabel;
    QPushButton *duplicateFrame;
    QWidget *toolsWidget;
    QPushButton *sizeButton;
    QPushButton *eraseButton;
    QPushButton *drawButton;
    QPushButton *fileButton;
    QPushButton *symmetricalButton;
    QPushButton *colorButton;
    QPushButton *shiftButton;
    QPushButton *undoButton;
    QPushButton *clearButton;
    QLabel *frameSizeDisplay;
    QLabel *penSizeDisplay;
    QLabel *colorDisplayLabel;
    QPushButton *colorDisplay;
    QPushButton *redoButton;
    QWidget *previewView;
    QPushButton *pauseButton;
    QSlider *fpsSlider;
    QLabel *previewImage;
    QStackedWidget *optionsBox;
    QWidget *penView;
    QPushButton *penSize1;
    QPushButton *penSize2;
    QPushButton *penSize3;
    QPushButton *penSize4;
    QLabel *label;
    QWidget *colorView;
    QWidget *symmetryView;
    QPushButton *HorizontalButton;
    QPushButton *VerticalButton;
    QWidget *fileView;
    QPushButton *LoadButton;
    QPushButton *SaveBu;
    QWidget *sizeView;
    QPushButton *size8Button;
    QPushButton *size16Button;
    QPushButton *size64Button;
    QPushButton *size32Button;
    QLabel *label_3;
    QWidget *shiftView;
    QPushButton *shiftLeftButton;
    QPushButton *shiftRightButton;
    QPushButton *shiftUpButton;
    QPushButton *shiftDownButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(898, 801);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        canvas = new QWidget(centralwidget);
        canvas->setObjectName("canvas");
        canvas->setGeometry(QRect(360, 0, 531, 571));
        frame = new EditorFrame(canvas);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 512, 512));
        subFrame = new QPushButton(canvas);
        subFrame->setObjectName("subFrame");
        subFrame->setGeometry(QRect(10, 530, 31, 31));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        subFrame->setFont(font);
        moveLeft = new QPushButton(canvas);
        moveLeft->setObjectName("moveLeft");
        moveLeft->setGeometry(QRect(50, 530, 31, 31));
        moveLeft->setFont(font);
        addFrame = new QPushButton(canvas);
        addFrame->setObjectName("addFrame");
        addFrame->setGeometry(QRect(360, 530, 30, 31));
        addFrame->setFont(font);
        moveRight = new QPushButton(canvas);
        moveRight->setObjectName("moveRight");
        moveRight->setGeometry(QRect(320, 530, 31, 31));
        moveRight->setFont(font);
        currFrameLabel = new QLabel(canvas);
        currFrameLabel->setObjectName("currFrameLabel");
        currFrameLabel->setGeometry(QRect(90, 540, 121, 16));
        QFont font1;
        font1.setBold(false);
        currFrameLabel->setFont(font1);
        totalFrameLabel = new QLabel(canvas);
        totalFrameLabel->setObjectName("totalFrameLabel");
        totalFrameLabel->setGeometry(QRect(210, 540, 111, 16));
        duplicateFrame = new QPushButton(canvas);
        duplicateFrame->setObjectName("duplicateFrame");
        duplicateFrame->setGeometry(QRect(400, 530, 121, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        duplicateFrame->setFont(font2);
        toolsWidget = new QWidget(centralwidget);
        toolsWidget->setObjectName("toolsWidget");
        toolsWidget->setGeometry(QRect(0, 230, 361, 561));
        sizeButton = new QPushButton(toolsWidget);
        sizeButton->setObjectName("sizeButton");
        sizeButton->setGeometry(QRect(10, 290, 150, 75));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        sizeButton->setFont(font3);
        eraseButton = new QPushButton(toolsWidget);
        eraseButton->setObjectName("eraseButton");
        eraseButton->setGeometry(QRect(190, 100, 150, 75));
        QFont font4;
        font4.setPointSize(45);
        font4.setBold(true);
        eraseButton->setFont(font4);
        eraseButton->setCheckable(true);
        drawButton = new QPushButton(toolsWidget);
        drawButton->setObjectName("drawButton");
        drawButton->setGeometry(QRect(10, 100, 150, 75));
        drawButton->setFont(font4);
        fileButton = new QPushButton(toolsWidget);
        fileButton->setObjectName("fileButton");
        fileButton->setGeometry(QRect(190, 190, 150, 75));
        fileButton->setFont(font4);
        symmetricalButton = new QPushButton(toolsWidget);
        symmetricalButton->setObjectName("symmetricalButton");
        symmetricalButton->setGeometry(QRect(10, 390, 150, 75));
        symmetricalButton->setFont(font3);
        symmetricalButton->setStyleSheet(QString::fromUtf8(""));
        colorButton = new QPushButton(toolsWidget);
        colorButton->setObjectName("colorButton");
        colorButton->setGeometry(QRect(10, 190, 150, 75));
        QFont font5;
        font5.setPointSize(40);
        font5.setBold(true);
        colorButton->setFont(font5);
        shiftButton = new QPushButton(toolsWidget);
        shiftButton->setObjectName("shiftButton");
        shiftButton->setGeometry(QRect(190, 390, 150, 75));
        shiftButton->setFont(font4);
        undoButton = new QPushButton(toolsWidget);
        undoButton->setObjectName("undoButton");
        undoButton->setGeometry(QRect(10, 480, 150, 75));
        undoButton->setFont(font4);
        clearButton = new QPushButton(toolsWidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(190, 290, 150, 75));
        clearButton->setFont(font4);
        frameSizeDisplay = new QLabel(toolsWidget);
        frameSizeDisplay->setObjectName("frameSizeDisplay");
        frameSizeDisplay->setGeometry(QRect(10, 40, 121, 31));
        penSizeDisplay = new QLabel(toolsWidget);
        penSizeDisplay->setObjectName("penSizeDisplay");
        penSizeDisplay->setGeometry(QRect(140, 40, 101, 31));
        colorDisplayLabel = new QLabel(toolsWidget);
        colorDisplayLabel->setObjectName("colorDisplayLabel");
        colorDisplayLabel->setGeometry(QRect(240, 40, 51, 31));
        colorDisplay = new QPushButton(toolsWidget);
        colorDisplay->setObjectName("colorDisplay");
        colorDisplay->setGeometry(QRect(290, 40, 31, 31));
        redoButton = new QPushButton(toolsWidget);
        redoButton->setObjectName("redoButton");
        redoButton->setGeometry(QRect(190, 480, 150, 75));
        redoButton->setFont(font4);
        previewView = new QWidget(centralwidget);
        previewView->setObjectName("previewView");
        previewView->setGeometry(QRect(0, 0, 351, 251));
        pauseButton = new QPushButton(previewView);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(10, 205, 101, 41));
        QFont font6;
        font6.setPointSize(13);
        font6.setBold(true);
        pauseButton->setFont(font6);
        fpsSlider = new QSlider(previewView);
        fpsSlider->setObjectName("fpsSlider");
        fpsSlider->setGeometry(QRect(130, 210, 211, 31));
        fpsSlider->setOrientation(Qt::Orientation::Horizontal);
        previewImage = new QLabel(previewView);
        previewImage->setObjectName("previewImage");
        previewImage->setGeometry(QRect(80, 10, 190, 190));
        optionsBox = new QStackedWidget(centralwidget);
        optionsBox->setObjectName("optionsBox");
        optionsBox->setGeometry(QRect(360, 590, 531, 211));
        penView = new QWidget();
        penView->setObjectName("penView");
        penSize1 = new QPushButton(penView);
        penSize1->setObjectName("penSize1");
        penSize1->setGeometry(QRect(20, 60, 101, 111));
        QFont font7;
        font7.setPointSize(32);
        font7.setBold(true);
        penSize1->setFont(font7);
        penSize1->setCheckable(true);
        penSize1->setChecked(true);
        penSize2 = new QPushButton(penView);
        penSize2->setObjectName("penSize2");
        penSize2->setGeometry(QRect(150, 60, 101, 111));
        penSize2->setFont(font7);
        penSize2->setCheckable(true);
        penSize3 = new QPushButton(penView);
        penSize3->setObjectName("penSize3");
        penSize3->setGeometry(QRect(280, 60, 101, 111));
        penSize3->setFont(font7);
        penSize3->setCheckable(true);
        penSize4 = new QPushButton(penView);
        penSize4->setObjectName("penSize4");
        penSize4->setGeometry(QRect(410, 60, 101, 111));
        penSize4->setFont(font7);
        penSize4->setCheckable(true);
        label = new QLabel(penView);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 10, 111, 41));
        QFont font8;
        font8.setPointSize(20);
        font8.setBold(true);
        font8.setKerning(false);
        label->setFont(font8);
        optionsBox->addWidget(penView);
        colorView = new QWidget();
        colorView->setObjectName("colorView");
        optionsBox->addWidget(colorView);
        symmetryView = new QWidget();
        symmetryView->setObjectName("symmetryView");
        HorizontalButton = new QPushButton(symmetryView);
        HorizontalButton->setObjectName("HorizontalButton");
        HorizontalButton->setGeometry(QRect(60, 50, 191, 121));
        QFont font9;
        font9.setPointSize(30);
        font9.setBold(true);
        HorizontalButton->setFont(font9);
        HorizontalButton->setCheckable(true);
        VerticalButton = new QPushButton(symmetryView);
        VerticalButton->setObjectName("VerticalButton");
        VerticalButton->setGeometry(QRect(290, 50, 191, 121));
        VerticalButton->setFont(font9);
        VerticalButton->setCheckable(true);
        optionsBox->addWidget(symmetryView);
        fileView = new QWidget();
        fileView->setObjectName("fileView");
        LoadButton = new QPushButton(fileView);
        LoadButton->setObjectName("LoadButton");
        LoadButton->setGeometry(QRect(50, 40, 191, 121));
        QFont font10;
        font10.setPointSize(50);
        font10.setBold(true);
        LoadButton->setFont(font10);
        SaveBu = new QPushButton(fileView);
        SaveBu->setObjectName("SaveBu");
        SaveBu->setGeometry(QRect(280, 40, 191, 121));
        SaveBu->setFont(font4);
        optionsBox->addWidget(fileView);
        sizeView = new QWidget();
        sizeView->setObjectName("sizeView");
        size8Button = new QPushButton(sizeView);
        size8Button->setObjectName("size8Button");
        size8Button->setGeometry(QRect(20, 60, 101, 111));
        QFont font11;
        font11.setPointSize(64);
        font11.setBold(true);
        size8Button->setFont(font11);
        size8Button->setCheckable(true);
        size16Button = new QPushButton(sizeView);
        size16Button->setObjectName("size16Button");
        size16Button->setGeometry(QRect(150, 60, 101, 111));
        size16Button->setFont(font11);
        size16Button->setCheckable(true);
        size16Button->setChecked(true);
        size64Button = new QPushButton(sizeView);
        size64Button->setObjectName("size64Button");
        size64Button->setGeometry(QRect(410, 60, 101, 111));
        size64Button->setFont(font11);
        size64Button->setCheckable(true);
        size32Button = new QPushButton(sizeView);
        size32Button->setObjectName("size32Button");
        size32Button->setGeometry(QRect(280, 60, 101, 111));
        size32Button->setFont(font11);
        size32Button->setCheckable(true);
        label_3 = new QLabel(sizeView);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 10, 131, 41));
        QFont font12;
        font12.setPointSize(24);
        font12.setBold(true);
        label_3->setFont(font12);
        optionsBox->addWidget(sizeView);
        shiftView = new QWidget();
        shiftView->setObjectName("shiftView");
        shiftLeftButton = new QPushButton(shiftView);
        shiftLeftButton->setObjectName("shiftLeftButton");
        shiftLeftButton->setGeometry(QRect(150, 50, 101, 111));
        shiftRightButton = new QPushButton(shiftView);
        shiftRightButton->setObjectName("shiftRightButton");
        shiftRightButton->setGeometry(QRect(20, 50, 101, 111));
        shiftUpButton = new QPushButton(shiftView);
        shiftUpButton->setObjectName("shiftUpButton");
        shiftUpButton->setGeometry(QRect(280, 50, 101, 111));
        shiftDownButton = new QPushButton(shiftView);
        shiftDownButton->setObjectName("shiftDownButton");
        shiftDownButton->setGeometry(QRect(410, 50, 101, 111));
        optionsBox->addWidget(shiftView);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        optionsBox->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "David & the Johnsons", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        subFrame->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        moveLeft->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        addFrame->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        moveRight->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        currFrameLabel->setText(QCoreApplication::translate("MainWindow", "Current Frame: 1", nullptr));
        totalFrameLabel->setText(QCoreApplication::translate("MainWindow", "Total Frames: 1", nullptr));
        duplicateFrame->setText(QCoreApplication::translate("MainWindow", "Duplicate Frame", nullptr));
        sizeButton->setText(QCoreApplication::translate("MainWindow", "Frame Size", nullptr));
        eraseButton->setText(QCoreApplication::translate("MainWindow", "Erase", nullptr));
        drawButton->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        fileButton->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
        symmetricalButton->setText(QCoreApplication::translate("MainWindow", "Symmetry", nullptr));
        colorButton->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        shiftButton->setText(QCoreApplication::translate("MainWindow", "Shift", nullptr));
        undoButton->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        frameSizeDisplay->setText(QCoreApplication::translate("MainWindow", "Frame Size = 16", nullptr));
        penSizeDisplay->setText(QCoreApplication::translate("MainWindow", "Pen Size = 1x1", nullptr));
        colorDisplayLabel->setText(QCoreApplication::translate("MainWindow", "Color =", nullptr));
        colorDisplay->setText(QString());
        redoButton->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Play/Pause", nullptr));
        previewImage->setText(QString());
        penSize1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        penSize2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        penSize3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        penSize4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Brush Size", nullptr));
        HorizontalButton->setText(QCoreApplication::translate("MainWindow", "Horizontal", nullptr));
        VerticalButton->setText(QCoreApplication::translate("MainWindow", "Vertical", nullptr));
        LoadButton->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        SaveBu->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        size8Button->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        size16Button->setText(QCoreApplication::translate("MainWindow", "16", nullptr));
        size64Button->setText(QCoreApplication::translate("MainWindow", "64", nullptr));
        size32Button->setText(QCoreApplication::translate("MainWindow", "32", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Frame Size", nullptr));
        shiftLeftButton->setText(QCoreApplication::translate("MainWindow", "Left", nullptr));
        shiftRightButton->setText(QCoreApplication::translate("MainWindow", "Right", nullptr));
        shiftUpButton->setText(QCoreApplication::translate("MainWindow", "Up", nullptr));
        shiftDownButton->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
