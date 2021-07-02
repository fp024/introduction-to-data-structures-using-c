/**
 * ListBaseSatck.h
 */
#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE    1
#define FALSE   0

typedef int Data;

/**
 * 연결 리스트의 노드를 표현한 구조체
 */
typedef struct _node {
    Data data;
    struct _node* next;
} Node;

/**
 * 연결 리스트 기반 스택을 표현한 구조체  
 */
typedef struct _listStack {
    Node* head;
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


#endif // !__LB_STACK_H__
