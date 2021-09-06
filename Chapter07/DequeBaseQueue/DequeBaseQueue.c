/**
 * DequeBaseQueue.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "DequeBaseQueue.h"


void QueueInit(Queue* pq) {
    pq->deque = (Deque*)malloc(sizeof(Deque));
    DequeInit(pq->deque);
}

int QIsEmpty(Queue* pq) {
    return DQIsEmpty(pq->deque);
}


void Enqueue(Queue* pq, Data data) {
    DQAddLast(pq->deque, data);
}


Data Dequeue(Queue* pq) {
    return DQRemoveFirst(pq->deque);
}


Data QPeek(Queue* pq) {
    return DQGetFirst(pq->deque);
}