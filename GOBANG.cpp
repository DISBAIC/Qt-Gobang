#include "GOBANG.h"
#include <QMessageBox>

//窗口类
GOBANG::GOBANG(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

GOBANG::~GOBANG()
{}

//展示弹窗
void showMessageBox(const char * output) {
    QMessageBox::information(nullptr, "Game Over", output);
}


