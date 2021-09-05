/**
 * CircularQueue.h
 */
#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE    1
#define FALSE   0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue {
    // Queue의 Front
    int front;

    // Queue의 Rear
    int rear;

    Data queArr[QUE_LEN];

} CQueue;

typedef CQueue Queue;

/**
 * 큐를 초기화한다.
 * @param pq    큐의 포인터
 */
void QueueInit(Queue* pq);

/**
 * 큐가 비었는지 확인한다.
 * @param pq    큐의 포인터
 * @return 비었으면 TRUE, 아니면 FALSE
 */
int QIsEmpty(Queue* pq);


/**
 * 큐에 데이터를 넣는다.
 * @param pq    큐의 포인터
 * @param data  데이터
 */
void Enqueue(Queue* pq, Data data);


/**
 * 큐에서 데이터를 꺼낸다.
 * 꺼낸 데이터는 큐에서 제거됨.
 *
 * @param   pq    큐의 포인터
 * @return  data  데이터
 */
Data Dequeue(Queue* pq);


/**
 * 큐의 마지막 데이터를 조회한다.
 * 조회만 함, 데이터를 제거하지 않음.
 *
 * @param   pq    큐의 포인터
 * @return  data  데이터
 */
Data QPeek(Queue* pq);


#endif