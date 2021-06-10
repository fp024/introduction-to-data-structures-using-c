#include <stdio.h>
#include "DLinkedList.h"

int WhoISPrecede(LData d1, LData d2) {
    if (d1 < d2) {
        return 0; // d1이 정렬 순서상 앞선다.
    }
    else {
        return 1; // d2가 정렬 순서상 앞서거나 같다.
    }

}



int main(void) {
    int r = LFirst(NULL, NULL);
    printf("%d", r);
  

    return 0;
}