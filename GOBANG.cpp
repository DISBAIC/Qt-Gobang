#include "GOBANG.h"
#include <QMessageBox>

GOBANG::GOBANG(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

GOBANG::~GOBANG()
{}



void showMessageBox(const char * output) {
    QMessageBox::information(nullptr, "Game Over", output);
}

QBrush Color_spwan(int state) {
    switch (state) {
    case 2:
        return QColor(0, 0, 0, 0); break;
    case 1:
        return  Qt::white; break;
    case 0:
        return Qt::black; break;
    }
}


