/**
 * HamburgerSim.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define CUS_COME_TERM 15 // 고객의 주문 간격: 초 단위

#define CHE_BUR     0   // 치즈버거 상수
#define BUL_BUR     1   // 불고기버거 상수
#define DUB_BUR     2   // 더블버거 상수

#define CHE_TERM    12  // 치즈버거 제작시간: 초단위
#define BUL_TERM    15  // 불고기버거 제작시간: 초단위
#define DUB_TERM    24  // 더블버거 제작시간: 초단위

int main(void) {
    int makeProc = 0;       // 햄버거 제작 진행 상황
    int cheOrder = 0;
    int bulOrder = 0;
    int dubOrder = 0;

    int sec;

    Queue que;
    QueueInit(&que);
    srand(time(NULL));

    // 아래 for문의 1회 회전은 1초의 시간 흐름을 의미함
    for (sec = 0; sec < 3600; sec++) {
        if (sec % CUS_COME_TERM == 0) { // 15초 마다 진입
            switch (rand() % 3) {  // 0, 1, 2 중 하나 랜덤, 햄버거를 주문하고 대기실에 들어간다.
            case CHE_BUR:
                Enqueue(&que, CHE_TERM);  // 큐에 햄버거별 제작 시간 초 값을 넣는다.
                cheOrder += 1;
                break;
            case BUL_BUR:
                Enqueue(&que, BUL_TERM);
                bulOrder += 1;
                break;
            case DUB_BUR:
                Enqueue(&que, DUB_TERM);
                dubOrder += 1;
                break;
            }
        }

        if (makeProc <= 0 && !QIsEmpty(&que)) {  // 햄버거 제작 시간이 소모된 상태이면서 큐가 비어있지 않을 때 큐의 내용을 빼낸다.
            makeProc = Dequeue(&que);       // 대기실에 나와 대기한다.
        }

        makeProc--; // 제작시간을 소모시킨다.
    }

    printf("Simulation Report! \n");
    printf("- Cheese burger: %d \n", cheOrder); // 각 버거 주문 카운트
    printf("- Bulgogi burger: %d \n", bulOrder);
    printf("- Double burger: %d \n", dubOrder);
    printf("- Waiting room size: %d\n", QUE_LEN); // 대기실 크기 


    // 주문카운트 별 총 처리 시간
    printf("주문 카운트의 총합 시간: %d\n", (cheOrder * CHE_TERM + bulOrder * BUL_TERM + dubOrder * DUB_TERM));

    // 남은 큐 출력    
    int restProc = 0;
    while (!QIsEmpty(&que)) {
        restProc += Dequeue(&que);
    }

    printf("남은 큐 내용 소모시간 합계: %d\n", restProc);

    /**
     주문 카운트를 증가 시키는데 주문 카운트는 3600초를 초과한다.
     초과하는 이유는 아직 1시간 이내에 처리하지 않은 주문 내용이 큐에 남아있기 때문이다.

     대기실 초과 없이 점심시간을 버텼으므로 100% 수용은 한상태라 볼 수 있는 것 같다.
     */
    return 0;
}
