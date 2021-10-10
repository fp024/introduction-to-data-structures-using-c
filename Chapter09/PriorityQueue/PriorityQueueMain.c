/**
 * PriorityQueueMain.c
 */
#include <stdio.h>
#include "PriorityQueue.h"

 /**
  * Queue에 전달할 사용자 정의 우선순위 비교 함수
  */
int DataPriorityComp(PQData d1, PQData d2) {
    return d2 - d1;
}

int main(void) {
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp); // 큐의 초기화

    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    /*
           A
          / \
         B   C
    */

    printf("%c \n", PDequeue(&pq));
    /*
           B
          /
         C
    */
    printf("------------- \n");

    PEnqueue(&pq, 'A');
    /*
           A
          / \
         C   B
    */

    PEnqueue(&pq, 'B');
    /*
           A
          / \
         B   B
        /
       C
    */

    PEnqueue(&pq, 'C');
    /*
           A
          / \
         B   B
        / \
       C   C
     */
    printf("%c \n", PDequeue(&pq));
    // === A === 
    /*
         B
        / \
       C   B
      /
     C
    */

    while (!PQIsEmpty(&pq)) {
        printf("%c \n", PDequeue(&pq));
    }

    // === B === 
    /*
           B
          /
         C
        /
       C
    */

    // === B === 
    /*
           C
          /
         C
    */

    // === C === 
    /*
          C
    */

    // === C ===
    /*
          비워짐
    */
    return 0;

}