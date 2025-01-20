/*
 * 11/14/2024
 *
 * Adam Kaufmann: 0AdamKaufmann0
 * Didar Jaff: Didar441
 * Milo Atwood: rossatwood2022
 * Ahmad Al Najjar: MrNajj
 * Nikiel Meeks: Nikiel-M03
 * Quinn Sakelaris: qsakelaris
 *
 * This is the entry point for the project
 *
 * Reviewed by Didar
 */
#include "mainwindow.h"
#include "model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    MainWindow w(model);
    w.show();
    return a.exec();
}
