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

bool victory_check(int x, int y, state state) {
    int count = 1;
    int xi = x, yi = y;

    for (int i = xi - 1; i > 0; i--) {
        if (pieces[i][y].state == state)
            count++;
        else
            break;
    }
    for (int i = xi + 1; i < 18; i++) {
        if (pieces[i][y].state == state)
            count++;
        else
            break;
    }
    if (count > 4) return true; else count = 1;

    for (int i = yi - 1; i > 0; i--) {
        if (pieces[x][i].state == state)
            count++;
        else
            break;
    }
    for (int i = yi + 1; i < 18; i++) {
        if (pieces[x][i].state == state)
            count++;
        else
            break;
    }
    if (count > 4) return true; else count = 1;


    for (int i = xi - 1, j = yi - 1; i > 0 && j > 0; i--, j--)
        if (pieces[i][j].state == state)
            count++;
        else
            break;
    for (int i = xi + 1, j = yi + 1; i < 18 && j < 18; i++, j++)
        if (pieces[i][j].state == state)
            count++;
        else
            break;
    if (count > 4) return true; else count = 1;

    for (int i = xi + 1, j = yi - 1; i < 18 && j > 0; i++, j--)
        if (pieces[i][j].state == state)
            count++;
        else
            break;
    for (int i = xi - 1, j = yi + 1; i > 0 && j < 18; i--, j++)
        if (pieces[i][j].state == state)
            count++;
        else
            break;
    if (count > 4) return true; else count = 1;

    return false;
}

QBrush Color_spwan(state state) {
    switch (state) {
    case none:
        return QColor(0, 0, 0, 0); break;
    case white:
        return  Qt::white; break;
    case black:
        return Qt::black; break;
    }
}


