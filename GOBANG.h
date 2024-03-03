#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GOBANG.h"
#include <qpainter.h>
#include "piece.h"
#include <QMouseEvent>
#include <QMessageBox>
#include "function.h"

extern struct piece pieces[19][19];
#define loops(x ,i) for(int i = 0;i<x;i++)
QBrush Color_spwan(int state);


class GOBANG : public QMainWindow
{
    Q_OBJECT

public:

    GOBANG(QWidget* parent = nullptr);
    ~GOBANG();
    void GOBANG::paintEvent(QPaintEvent*) {
        void CreateBoarder(GOBANG * Gobang);
        CreateBoarder(this);
    }

    void GOBANG::mousePressEvent(QMouseEvent* event) {
        int cellSize = 50; 

        //获取鼠标点击坐标
        float x = event->pos().x();
        float y = event->pos().y();

        float colF = x / cellSize;
        float rowF = y / cellSize;
        
        //转换坐标
        int col = postion(x);
        int row = postion(y);


        // 检查行列是否在棋盘范围内
        if (row >= 0 && row < 19 && col >= 0 && col < 19) {

            //执行落子
            Gobang(col, row);
            
            //检测游戏是否结束
            if (victory_check(col - 1, row - 1, pieces[col - 1][row - 1].state)) {
               end = true;
            };

            //更新窗口渲染
            update(); 

            if (end) {
                //游戏结束 禁用操作响应 同时弹出消息
                setEnabled(false);
                if (pieces[col - 1][row - 1].state == 0) {
                    showMessageBox("Black Win");
                }
                else {
                    showMessageBox("White Win");
                }
            }
        }
        

    }

private:
    Ui::GOBANGClass ui;
};
