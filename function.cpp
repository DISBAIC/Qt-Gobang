
#include "piece.h"
#include <math.h>
#include<qapplication.h>
#include "GOBANG.h"

extern QApplication* QAP;;

#define loops(x,i) for(int i = 0;i<x;i++)

int victory_check(int x, int y, int state) {
    
    int count = 1;
    int xi = x, yi = y;

    //计算直线方向是否有五子连珠
    for (int i = xi - 1; i > 0; i--) {
        if (pieces[i][y].state == state)
            count++;
        else
            break;
    }
    for (int i = xi + 1; i < 19; i++) {
        if (pieces[i][y].state == state)
            count++;
        else
            break;
    }
    if (count > 4) return 1; else count = 1;

    for (int i = yi - 1; i > 0; i--) {
        if (pieces[x][i].state == state)
            count++;
        else
            break;
    }
    for (int i = yi + 1; i < 19; i++) {
        if (pieces[x][i].state == state)
            count++;
        else
            break;
    }
    if (count > 4) return 1; else count = 1;

    //计算斜线方向是否有五子连珠
    for (int i = xi - 1, j = yi - 1; i > 0 && j > 0; i--, j--)
        if (pieces[i][j].state == state)
            count++;
        else
            break;
    for (int i = xi + 1, j = yi + 1; i < 19 && j < 19; i++, j++)
        if (pieces[i][j].state == state)
            count++;
        else
            break;
    if (count > 4) return 1; else count = 1;

    for (int i = xi + 1, j = yi - 1; i < 19 && j > 0; i++, j--)
        if (pieces[i][j].state == state)
            count++;
        else
            break;
    for (int i = xi - 1, j = yi + 1; i > 0 && j < 19; i--, j++)
        if (pieces[i][j].state == state)
            count++;
        else
            break;
    if (count > 4) return 1; else count = 1;

    return 0;
}

void Gobang(int x, int y) {
    //落子至x y处
    int col = x; int row = y;

    //反转operating 更改下一次落子的玩家
    if (pieces[col - 1][row - 1].state == 2) {
        if (operating == 0) {
            operating = 1;
            pieces[col - 1][row - 1].state = 1;
        }
        else {
            operating = 0;
            pieces[col - 1][row - 1].state = 0;
        }
    }
}

void init(int argc,char *argv[]) {
    //将棋盘写满 空值
    loops(19, i) loops(19, j) pieces[i][j].state = 2;
    operating = true;  end = false;
    QAP = new QApplication(argc, argv);
}

int postion(float p) {
    //处理坐标以确定棋盘对应的位置
    float pt = p / 50.0;
    return round(pt);
}



void window_init(int x,int y) {
    
}

int complete() {
    return QAP->exec();
}

void  QTsetFixedSize(GOBANG * Gobang,int x, int y) {
    Gobang->setFixedSize(x,y);
}

void QTShow(GOBANG* Gobang) {
    Gobang->show();
}

void CreateBoarder(GOBANG * Gobang) {
    QPainter painter(Gobang);
    painter.setPen(Qt::black);
    int cellSize = 950 / 19;

    //渲染棋盘网格线
    for (int i = 0; i <= 19; ++i) {

        painter.drawLine(cellSize, i * cellSize, 18 * cellSize, i * cellSize);

        painter.drawLine(i * cellSize, cellSize, i * cellSize, 18 * cellSize);
    }

    //设置背景
    QPalette palette = Gobang->palette();
    palette.setColor(QPalette::Window, Qt::darkYellow);
    Gobang->setPalette(palette);

    //绘制棋子
    int radius = cellSize / 4;
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            QPoint center((i + 1) * cellSize, (j + 1) * cellSize); // 计算棋子中心位置

            if (pieces[i][j].state != 2) {
                painter.setPen(Qt::NoPen); // 不绘制边框

                //根据Pieces数据以绘制棋子
                if (pieces[i][j].state == 0) {
                    painter.setBrush(Qt::black);
                }
                else if (pieces[i][j].state == 1) {
                    painter.setBrush(Qt::white);
                }
                painter.drawEllipse(center, radius, radius);
            }
        }
    }
}