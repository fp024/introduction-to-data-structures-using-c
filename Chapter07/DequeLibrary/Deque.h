/**
 * Deque.h
 */
#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct _node {
    Data data;
    struct _node* prev;
    struct _node* next;
} Node;

typedef struct _dlDeque {
    Node* head;
    Node* tail;
} DLDeque;

typedef DLDeque Deque;

/**
 * 덱을 초기화한다.
 * @param pdeq  초기화할 덱의 주소
 */
void DequeInit(Deque* pdeq);


/**
 * 덱이 비었는지 확인
 * @param pdeq 덱의 주소
 * @return 덱이 빈 경우 TRUE(1), 그렇지 않은 경우 FALSE(0)을 반환 
 */
int DQIsEmpty(Deque* pdeq);


/**
 * 덱의 머리에 데이터를 저장한다.
 * @param pdeq  덱의 주소
 * @param data  저장할 데이터
 */
void DQAddFirst(Deque* pdeq, Data data);


/**
 * 덱의 꼬리에 데이터를 저장한다.
 * @param pdeq  덱의 주소
 * @param data  저장할 데이터
 */
void DQAddLast(Deque* pdeq, Data data);


/**
 * 덱의 머리에 위치한 데이터를 반환 및 삭제한다.
 * @param pdeq  덱의 주소
 * @return 삭제한 데이터
 */
Data DQRemoveFirst(Deque* pdeq);


/**
 * 덱의 꼬리에 위치한 데이터를 반환 및 삭제한다.
 * @param pdeq  덱의 주소
 * @return 삭제한 데이터
 */
Data DQRemoveLast(Deque* pdeq);


/**
 * 덱의 머리에 위치한 데이터를 삭제하지 않고 반환한다.
 * @param pdeq  덱의 주소
 * @return 조회한 데이터
 */
Data DQGetFirst(Deque* pdeq);


/**
 * 덱의 꼬리에 위치한 데이터를 소멸하지 않고 반환한다.
 * @param pdeq  덱의 주소
 * @return 조회한 데이터
 */
Data DQGetLast(Deque* pdeq);


#endif // !__DEQUE_H__

