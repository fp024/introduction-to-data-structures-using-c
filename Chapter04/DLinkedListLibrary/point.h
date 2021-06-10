#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point {
    int xPos;
    int yPos;
} Point;

/**
 * Point ������ xPos, yPos �� ����
 */
void setPointPos(Point* ptrPos, int xPos, int yPos);

/**
 * Point ������ xPos, yPos ���� ���
 */
void ShowPointPos(Point* ptrPos);

/**
 * �� Point ������ ��
 */
int PointComp(Point* pos1, Point* pos2);

#endif