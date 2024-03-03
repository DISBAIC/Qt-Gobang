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

        //��ȡ���������
        float x = event->pos().x();
        float y = event->pos().y();

        float colF = x / cellSize;
        float rowF = y / cellSize;
        
        //ת������
        int col = postion(x);
        int row = postion(y);


        // ��������Ƿ������̷�Χ��
        if (row >= 0 && row < 19 && col >= 0 && col < 19) {

            //ִ������
            Gobang(col, row);
            
            //�����Ϸ�Ƿ����
            if (victory_check(col - 1, row - 1, pieces[col - 1][row - 1].state)) {
               end = true;
            };

            //���´�����Ⱦ
            update(); 

            if (end) {
                //��Ϸ���� ���ò�����Ӧ ͬʱ������Ϣ
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
