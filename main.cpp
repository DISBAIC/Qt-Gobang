#include "GOBANG.h"
#include <QtWidgets/QApplication>
#include "base.h"
#define loops(x,i) for(int i = 0;i<x;i++)

bool operatering;
bool end;

piece pieces[19][19];

void init() {
    loops(19, i) loops(19, j) pieces[i][j].state = none;
}


int main(int argc, char *argv[])
{

    init();
    QApplication a(argc, argv);
    operatering = true;  end = false;
    GOBANG w;
    w.setFixedSize(950, 950);
    w.show();
    return a.exec();
}
