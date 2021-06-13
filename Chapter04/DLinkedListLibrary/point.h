#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point {
    int xPos;
    int yPos;
} Point;

/**
 * Point 변수의 xPos, yPos 값 설정
 */
void setPointPos(Point* ptrPos, int xPos, int yPos);

/**
 * Point 변수의 xPos, yPos 정보 출력
 */
void ShowPointPos(Point* ptrPos);

/**
 * 두 Point 변수의 비교
 */
int PointComp(Point* pos1, Point* pos2);

#endif