/**
 * CircularQueueMain.c
 */

#include <stdio.h>
#include "CircularQueue.h"

void testDefault() {
    // Queue의 생성 및 초기화
    Queue q;
    QueueInit(&q);

    // 데이터 넣기
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);

    // 데이터 꺼내기
    while (!QIsEmpty(&q)) {
        printf("%d ", Dequeue(&q));
    }
}

void testQIsFull() {
    // Queue의 생성 및 초기화
    Queue q;
    QueueInit(&q);

    // 큐 배열의 내용중 한개 요소는 사용하지 않는다.
    for (int i = 1; i < QUE_LEN; i++) {
        Enqueue(&q, i);
    }

    // 데이터 꺼내기
    while (!QIsEmpty(&q)) {
        printf("%d\n", Dequeue(&q));
    }
}



int main(void) {
    testDefault();

    printf("\n=============\n");

    testQIsFull();
    return 0;
}