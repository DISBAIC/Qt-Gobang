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

        //���ù���
        painter.setPen(Qt::black);

        //����ÿ����Ĵ�С
        int cellSize = width() / 19;

        //��Ⱦ����������
        for (int i = 0; i <= 19; ++i) {

            painter.drawLine(cellSize, i * cellSize, 18 * cellSize, i * cellSize);

            painter.drawLine(i * cellSize, cellSize, i * cellSize, 18 * cellSize);
        }

        //���ñ���
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, Qt::darkYellow);
        this->setPalette(palette);

        //��������
        int radius = cellSize / 4;
        for (int i = 0; i < 19; ++i) {
            for (int j = 0; j < 19; ++j) {
                QPoint center((i + 1) * cellSize, (j + 1) * cellSize); // ������������λ��

                if (pieces[i][j].state != 2) {
                    painter.setPen(Qt::NoPen); // �����Ʊ߿�

                    //����Pieces�����Ի�������
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
