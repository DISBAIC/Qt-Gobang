#include "GOBANG.h"
#include <QMessageBox>

//������
GOBANG::GOBANG(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

GOBANG::~GOBANG()
{}

//չʾ����
void showMessageBox(const char * output) {
    QMessageBox::information(nullptr, "Game Over", output);
}


