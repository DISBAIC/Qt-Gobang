
#include "piece.h"
#include <math.h>

int victory_check(int x, int y, int state) {
    
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
    if (count > 4) return 1; else count = 1;

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
    if (count > 4) return 1; else count = 1;


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
    if (count > 4) return 1; else count = 1;

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
    if (count > 4) return 1; else count = 1;

    return 0;
}

void Gobang(int x, int y) {
    int col = x; int row = y;
    if (pieces[col - 1][row - 1].state == 2) {
        if (operatering == 0) {
            operatering = 1;
            pieces[col - 1][row - 1].state = 1;
        }
        else {
            operatering = 0;
            pieces[col - 1][row - 1].state = 0;
        }
    }
}

int postion(float p) {
    float pt = p / 50.0;
    return round(pt);
}
