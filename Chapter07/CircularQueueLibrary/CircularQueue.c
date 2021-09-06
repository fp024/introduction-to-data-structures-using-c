/**
 * CircularQueue.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

 /**
  * 다음 위치를 계산한다.
  * @param pos 현재 위치
  * @return 다음 위치
  */
int NextPosIdx(int pos) {
    if (pos == QUE_LEN - 1) {
        return 0;
    }
    else {
        return pos + 1;
    }
}


/**
 * 큐가 꽉 찾는지 여부 검사
 * @param pq 큐의 포인터
 * @return 꽉 찼으면 TRUE, 아니면 FALSE
 */
int QIsFull(Queue* pq) {
    return (NextPosIdx(pq->rear) == pq->front) ? TRUE : FALSE;
}


void QueueInit(Queue* pq) {
    pq->front = 0;
    pq->rear = 0;
}


int QIsEmpty(Queue* pq) {
    return (pq->front == pq->rear) ? TRUE : FALSE;
}


void Enqueue(Queue* pq, Data data) {
    if (QIsFull(pq) == TRUE) {
        printf("큐가 꽉차서 더이상 넣을 수 없습니다.\n");
        exit(-1);
    }

    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;

}


Data Dequeue(Queue* pq) {
    if (QIsEmpty(pq) == TRUE) {
        printf("큐가 비어서 더이상 값을 가져올 수 없습니다.");
        exit(-2);
    }

    pq->front = NextPosIdx(pq->front);
    // 반환뒤 front는 이미 구조적으로 사용할 수 없는 값이니 일부러 0으로 초기화할 필요는 없다.
    return pq->queArr[pq->front];
}


Data QPeek(Queue* pq) {
    if (QIsEmpty(pq) == TRUE) {
        printf("큐가 비어서 더이상 값을 가져올 수 없습니다.");
        exit(-2);
    }

    // Dequeue와 비교해서 front의 위치 이동만 없으면 된다.
    return pq->queArr[NextPosIdx(pq->front)];
}



