#include "GOBANG.h"
#include <QtWidgets/QApplication>
///#include "function.h"
#define loops(x,i) for(int i = 0;i<x;i++)
#include "piece.h"

int operating;//将要落子的玩家 true黑方 false白方

int end; //是否有玩家胜利 false无 true有

QApplication* QAP;

void init(int argc, char* argv[]);


piece pieces[19][19]; //棋盘

int complete();

int main(int argc, char *argv[])
{
    //初始化
    init(argc,argv);

    GOBANG w;
    void  QTsetFixedSize(GOBANG * Gobang,int x, int y);
    QTsetFixedSize(&w, 950, 950);
    void QTShow(GOBANG * Gobang);
    QTShow(&w);
    return complete();

}
