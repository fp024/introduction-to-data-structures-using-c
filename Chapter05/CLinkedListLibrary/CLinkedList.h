#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

#ifdef _USE_EMPLOYEE_DATATYPE
#include "Employee.h"
#else
typedef int Data;
#endif


typedef struct _node {
    Data data;
    struct _node* next;
} Node;

typedef struct _CLL {
    Node* tail;     // 꼬리 가리키는 멤버
    Node* cur;      // 참조 및 삭제를 돕는 멤버
    Node* before;   // 삭제를 돕는 멤버
    int numOfData;  // 저장된 데이터의 수를 기록하기 위한 멤버
} CList;


typedef CList List;


/**
 * 초기화할 리스트의 주소 값을 인자로 전달한다.
 * 리스트 생성후 제일 먼저 호출되야하는 함수
 *
 * @param plist 초기화할 리스트의 주소 값
 */
void ListInit(List* plist);


/**
 * 꼬리에 노드를 추가
 *
 * @param plist 데이터를 저장할 리스트의 주소 값
 * @param data	데이터
 */
void LInsert(List* plist, Data data);


/**
 * 머리에 노드를 추가
 *
 * @param plist 데이터를 저장할 리스트의 주소 값
 * @param data	데이터
 */
void LInsertFront(List* plist, Data data);


/**
 * 첫 번째 데이터가 pdata가 가리키는 메모리에 저장됨
 * 데이터 참조를 위한 초기화가 진행됨
 *
 * @param plist 리스트 주소
 * @param pdata	첫 번째 데이터가 저장될 포인터
 *
 * @return 참조 성공시 TRUE(1), 실패시 FALSE(0) 반환
 */
int LFirst(List* plist, Data* pdata);


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
int LNext(List* plist, Data* pdata);


/**
 * LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다.
 * - 삭제된 데이터는 반환됨
 * - 마지막 반환데이터를 삭제하므로 연이은 반복호출을 허용하지 않음
 *
 * @param plist 리스트 주소
 * @return 삭제된 데이터
 */
Data LRemove(List* plist);


/**
 * 리스트에 저장되어있는 데이터 수를 반환
 *
 * @param plist 리스트 주소
 * @return 저장된 데이터수
 */
int LCount(List* plist);

#endif