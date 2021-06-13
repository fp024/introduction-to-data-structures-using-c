/**
 * 문제 04-4 [정렬의 기준으로 활용되는 함수의 정의]
 *
 *	Point 구조체를 기반으로 리스트를 사용할 수 있게 하고,
 *  x좌표기준으로 오름차순 정렬을 한다.
 *  만약 x좌표가 같을 경우 y좌표 기준으로 오름차순 정렬을 한다.
 *
 */
#include "DLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

int WhoISPrecede(LData d1, LData d2) {
	if (d1->xPos < d2->xPos) {
		return 0;
	}
	else if (d1->xPos == d2->xPos) {
		if (d1->yPos < d2->yPos) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		return 1;
	}
}

int main(void) {
	// 리스트의 생성 및 초기화
	List list;
	Point* ptrPos;
	ListInit(&list);

	SetSortRule(&list, &WhoISPrecede);

	// 5개의 데이터를 저장
	ptrPos = (Point*)malloc(sizeof(Point));
	setPointPos(ptrPos, 11, 111);
	LInsert(&list, ptrPos);

	ptrPos = (Point*)malloc(sizeof(Point));
	setPointPos(ptrPos, 11, 11);
	LInsert(&list, ptrPos);

	ptrPos = (Point*)malloc(sizeof(Point));
	setPointPos(ptrPos, 22, 222);
	LInsert(&list, ptrPos);

	ptrPos = (Point*)malloc(sizeof(Point));
	setPointPos(ptrPos, 22, 22);
	LInsert(&list, ptrPos);

	ptrPos = (Point*)malloc(sizeof(Point));
	setPointPos(ptrPos, 33, 333);
	LInsert(&list, ptrPos);

	ptrPos = (Point*)malloc(sizeof(Point));
	setPointPos(ptrPos, 33, 3333);
	LInsert(&list, ptrPos);


	// 저장된 데이터 전체 출력
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &ptrPos)) {
		ShowPointPos(ptrPos);

		while (LNext(&list, &ptrPos)) {
			ShowPointPos(ptrPos);
		}
	}
	printf("\n\n");

	// x좌표가 22인 요소를 검색하여 모두 삭제
	if (LFirst(&list, &ptrPos)) {
		if (ptrPos->xPos == 22) {
			free(LRemove(&list));

		}

		while (LNext(&list, &ptrPos)) {
			if (ptrPos->xPos == 22) {
				free(LRemove(&list));
			}
		}
	}


	// 삭제 후 남아있는 데이터 전체 출력
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &ptrPos)) {
		ShowPointPos(ptrPos);

		while (LNext(&list, &ptrPos)) {
			ShowPointPos(ptrPos);
		}
	}
	printf("\n\n");
	return 0;
}
