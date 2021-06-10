#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DLinkedList.h"

// 정렬 기준 없이 리스트 앞에 노드 추가
// 3, 2, 1 순으로 입력하면 리스트는 1 -> 2 -> 3 이 된다.
void FInsert(List* plist, LData data);

// 정렬 기준을 사용하여 노드 추가
void SInsert(List* plist, LData data);


void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node*)); // 더미 노드 생성
	if (plist->head == NULL) {
		assert(FALSE);
		return;
	}
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}


void LInsert(List* plist, LData data) {
	if (plist->comp == NULL) {	// 정렬기준이 마련되지 않았다면
		FInsert(plist, data);	// 머리에 노드 추가
	}
	else {
		SInsert(plist, data);
	}
}


int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL) {	// 더미 노드가 NULL을 가리킨다면,
		return FALSE;					// 반환할 데이터가 없다.
	}

	plist->before = plist->head;		// before는 더미노드를 가리키게 함
	plist->cur = plist->head->next;		// cur은 첫번째 노드를 가리키게 함

	*pdata = plist->cur->data;			// 첫 번째 노드의 데이터를 전달
	return TRUE; // 데이터 반환 성공
}


int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL) {
		return FALSE;
	}

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}


LData LRemove(List* plist) {
	if (plist->before == plist->cur) {
		fprintf(stderr, "LRemove함수는 연속으로 호출할 수 없습니다. LFirst 또는 LNext 함수 호출이 선행되야합니다.");
		assert(FALSE);
		return -1;
	}

	Node* removalNode = plist->cur;			// 소멸대상의 주소 값을 removalNode에 저장
	LData removalData = plist->cur->data;	// 소멸대상의 데이터를 removalData에 저장

	plist->before->next = plist->cur->next;	// 소멸 대상을 리스트에서 제거
	plist->cur = plist->before;				// cur이 가리키는 위치를 재조정

	free(removalNode);		// 리스트에서 제거된 노드 소멸
	(plist->numOfData)--;	// 저장된 데이터의 수 하나 감소
	return removalData;		// 제거된 노드의 반환
}


int LCount(List* plist) {
	return plist->numOfData;
}


void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}


// ===== 헤더파일로 공개되지 않는 함수 =====
void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));	// 새 노드 생성
	if (newNode == NULL) {
		assert(FALSE);
		return;
	}
	newNode->data = data;							// 새 노드에 데이터 저장

	newNode->next = plist->head->next;		// 새 노드가 다른 노드를 가리키게 함.
	plist->head->next = newNode;			// 더미노드가 새 노드를 가리키게 함.

	(plist->numOfData)++;	// 저장된 노드의 수를 하나 증가 시킴

}

void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));	// 새 노드 생성
	if (newNode == NULL) {
		assert(FALSE);
		return;
	}

	Node* pred = plist->head;						// pred는 더미노드를 가리킴

	newNode->data = data;	// 새 노드에 데이터 저장

	// 새 노드가 들어갈 위치를 찾기 위한 반복문
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
		pred = pred->next; // 다음 노드로 이동
	}

	newNode->next = pred->next;	// 새 노드의 오른쪽을 연결
	pred->next = newNode;		// 새 노드의 왼쪽을 연결

	(plist->numOfData)++; // 저장된 데이터 수 하나 증가

}