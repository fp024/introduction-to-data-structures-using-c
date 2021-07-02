/**
 * CListBaseStack.h
 */

#include "CLinkedList.h"

#define TRUE        1
#define FALSE       0

typedef int Data; // CLinkedList.h 에 Data타입이 선언되어있는데, 재선언해도 상관없나?


typedef struct _listStack {
    List* plist;
} ListStack;

typedef ListStack Stack;


/**
 * 스택의 초기화
 *
 * 스택 생성 후 제일 먼저 호출되어야하는 함수
 *
 * @param pstack 스택 자료구조의 포인터
 */
void StackInit(Stack* pstack);


/**
 * 스택이 비었는지 확인
 *
 * @param pstack 스택 자료구조의 포인터
 *
 * @return 스택이 빈 경우 TRUE(1), 그렇지 않은 경우 FALSE(0)을 반환한다.
 */
int SIsEmpty(Stack* pstack);


/**
 * 스택의 push 연산
 *
 * @param pstack 스택 자료구조의 포인터
 * @param data 저장할 데이터
 */
void SPush(Stack* pstack, Data data);


/**
 * 스택의 pop 연산
 * top의 데이터를 꺼낸다.
 *
 * @param pstack 스택 자료구조의 포인터
 *
 * @return 스택 top의 데이터
 */
Data SPop(Stack* pstack);


/**
 * 스택의 peek 연산
 * 스텍 top의 데이터 삭제 없이 조회한다.
 *
 * @param pstack 스택 자료구조의 포인터
 *
 * @return 스택 top의 데이터
 */
Data SPeek(Stack* pstack);
