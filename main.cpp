#include "GOBANG.h"
#include <QtWidgets/QApplication>
///#include "function.h"
#define loops(x,i) for(int i = 0;i<x;i++)
#include "piece.h"

int operating;//��Ҫ���ӵ���� true�ڷ� false�׷�

int end; //�Ƿ������ʤ�� false�� true��

QApplication* QAP;

void init(int argc, char* argv[]);


piece pieces[19][19]; //����

int complete();

int main(int argc, char *argv[])
{
    //��ʼ��
    init(argc,argv);

    GOBANG w;
    void  QTsetFixedSize(GOBANG * Gobang,int x, int y);
    QTsetFixedSize(&w, 950, 950);
    void QTShow(GOBANG * Gobang);
    QTShow(&w);
    return complete();

}
