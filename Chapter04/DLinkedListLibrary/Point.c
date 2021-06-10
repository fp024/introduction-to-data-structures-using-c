#include "point.h"

#include <stdio.h>

void setPointPos(Point* ptrPos, int xPos, int yPos) {
    ptrPos->xPos = xPos;
    ptrPos->yPos = yPos;
}

void ShowPointPos(Point* ptrPos) {
    printf("[%d, %d]\n", ptrPos->xPos, ptrPos->yPos);
}

int PointComp(Point* pos1, Point* pos2) {
    int pos1x = pos1->xPos;
    int pos1y = pos1->yPos;
    int pos2x = pos2->xPos;
    int pos2y = pos2->yPos;

    if (pos1x == pos2x && pos1y == pos2y) {
        return 0;
    }
    else if (pos1x == pos2x && pos1y != pos2y) {
        return 1;
    }
    else if (pos1x != pos2x && pos1y == pos2y) {
        return 2;
    }
    else {
        return -1;
    }
}