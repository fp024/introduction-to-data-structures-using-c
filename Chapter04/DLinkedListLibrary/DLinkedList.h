#pragma once

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
} Node;

typedef struct _linkedList {
	Node* head;
	Node* cur;
	Node* tail;
	int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;


/**
 * 초기화할 리스트의 주소 값을 인자로 전달한다.
 * 리스트 생성후 제일 먼저 호출되야하는 함수
 *
 * @param plist 초기화할 리스트의 주소 값
 */
void ListInit(List* plist);


/**
 * 리스트에 데이터를 저장한다
 *
 * @param plist 데이터를 저장할 리스트의 주소 값
 * @param data	데이터
 */
void LInsert(List* plist, LData data);


/**
 * 첫 번째 데이터가 pdata가 가리키는 메모리에 저장됨
 * 데이터 참조를 위한 초기화가 진행됨
 *
 * @param plist 리스트 주소
 * @param pdata	첫 번째 데이터가 저장될 포인터
 *
 * @return 참조 성공시 TRUE(1), 실패시 FALSE(0) 반환
 */
int LFirst(List* plist, LData* pdata);


/**
 * 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
 * 순차적인 참조를 위해서 반복 호출이 가능하다.
 * 참조를 새로 시작하려면 먼저 LFirst 함수를 호출해야한다.
 *
 * @param plist 리스트 주소
 * @param pdata 다음 데이터를 저장할 포인터
 *
 * @return 참조 성공시 TRUE(1), 실패시 FALSE(0) 반환
 */
int LNext(List* plist, LData* pdata);


/**
 * LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다.
 * - 삭제된 데이터는 반환됨
 * - 마지막 반환데이터를 삭제하므로 연이은 반복호출을 허용하지 않음
 * @param plist 리스트 주소
 * @return 삭제된 데이터
 */
LData LRemove(List* plist);


/**
 * 리스트에 저장되어있는 데이터 수를 반환
 * @param plist 리스트 주소
 * @return 저장된 데이터수
 */
int LCount(List* plist);


/**
 * 리스트의 정렬의 기준이 되는 함수를 등록한다.
 *
 * @param plist	리스트 주소
 * @param comp	정렬의 기준이 되는 함수 포인터
 */
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));

