#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GOBANG.h"
#include <qpainter.h>
#include "piece.h"
#include <QMouseEvent>
#include <math.h>
#include <windows.h>
#include <QMessageBox>

void showMessageBox(const char * output);
int victory_check(int x, int y, int state);
void Gobang(int x, int y);

#define loops(x ,i) for(int i = 0;i<x;i++)
extern int operatering;
extern bool end;
extern bool camp;
struct piece;

QBrush Color_spwan(int state);
extern piece pieces[19][19];

class GOBANG : public QMainWindow
{
    Q_OBJECT

public:

    GOBANG(QWidget* parent = nullptr);
    ~GOBANG();
    void GOBANG::paintEvent(QPaintEvent*) {

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);

        painter.setPen(Qt::black);
        int cellSize = width() / 19;
        for (int i = 0; i <= 19; ++i) {

            painter.drawLine(cellSize, i * cellSize, 18 * cellSize, i * cellSize);

            painter.drawLine(i * cellSize, cellSize, i * cellSize, 18 * cellSize);
        }

        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, Qt::darkYellow);
        this->setPalette(palette);

        int radius = cellSize / 4;
        for (int i = 0; i < 19; ++i) {
            for (int j = 0; j < 19; ++j) {
                QPoint center((i + 1) * cellSize, (j + 1) * cellSize); // ������������λ��

                if (pieces[i][j].state != 2) {
                    painter.setPen(Qt::NoPen); // �����Ʊ߿�
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
        float x = event->pos().x();
        float y = event->pos().y();

        // ����������ת��Ϊ�������������
        float colF = x / cellSize;
        float rowF = y / cellSize;

        // ʹ����������ȷ�����յ�����
        int col = round(colF);
        int row = round(rowF);



        // ��������Ƿ������̷�Χ��
        if (row >= 0 && row < 19 && col >= 0 && col < 19) {
            // ��������߼��������¼�

            Gobang(col, row);
            
            if (victory_check(col - 1, row - 1, pieces[col - 1][row - 1].state)) {
                end = true;
            };

            update(); // �����ػ�

            if (end) {
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
