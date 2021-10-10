/**
 * ex09-1.c - 문제 09-1 [우선순위 큐의 활용]
 */

#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"


 /**
  * Queue에 전달할 사용자 정의 우선순위 비교 함수
  */
int DataPriorityComp(PQData d1, PQData d2) {
    return strlen(d2) - strlen(d1);
}


int main(void) {
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);


    PEnqueue(&pq, "1");
    PEnqueue(&pq, "123");
    PEnqueue(&pq, "12");
    PEnqueue(&pq, "123456");
    PEnqueue(&pq, "12345");
    PEnqueue(&pq, "1234");


    while (!PQIsEmpty(&pq)) {
        printf("%s\n", PDequeue(&pq));
    }

    return 0;
}