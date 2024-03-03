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

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);

        //设置管线
        painter.setPen(Qt::black);

        //计算每个格的大小
        int cellSize = width() / 19;

        //渲染棋盘网格线
        for (int i = 0; i <= 19; ++i) {

            painter.drawLine(cellSize, i * cellSize, 18 * cellSize, i * cellSize);

            painter.drawLine(i * cellSize, cellSize, i * cellSize, 18 * cellSize);
        }

        //设置背景
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, Qt::darkYellow);
        this->setPalette(palette);

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
