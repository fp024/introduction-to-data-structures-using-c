/**
 * 문제 04-3 [연결 리스트에 구조체 변수의 주소값 저장하기]
 *
 *	4장의 연결리스트 기반으로 3장에서 진행했던 Point 구조체를 리스트의 요소 타입으로 사용해보기
 * 
 *  (참고) Point* 타입을 LData 타입으로 사용하기 위해서는 DLinkedListLibrary 프로젝트의 전처리기 설정에 
 *		   _USE_CUSTOM_DATATYPE 를 지정하고 사용하면 됨.
 *		   
 *		    유연하게 타입을 바꾸는 법을 현재로선 잘 모르겠음.ㅠㅠ
 */
#include "DLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// 리스트의 생성 및 초기화
	List list;
	Point* ptrPos;
	ListInit(&list);

	// 5개의 데이터를 저장
	ptrPos = (Point*)malloc(sizeof(Point));
	setPointPos(ptrPos, 11, 111);
	LInsert(&list, ptrPos);

	ptrPos = (Point*)malloc(sizeof(Point));
	setPointPos(ptrPos, 11, 111);
	LInsert(&list, ptrPos);

	ptrPos = (Point*)malloc(sizeof(Point));
	setPointPos(ptrPos, 22, 222);
	LInsert(&list, ptrPos);

	ptrPos = (Point*)malloc(sizeof(Point));
	setPointPos(ptrPos, 22, 222);
	LInsert(&list, ptrPos);

	ptrPos = (Point*)malloc(sizeof(Point));
	setPointPos(ptrPos, 33, 333);
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
