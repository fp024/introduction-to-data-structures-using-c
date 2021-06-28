/**
 * DBLinkedMain.c
 */
#include <stdio.h>
#include <assert.h>
#include "DBLinkedList.h"

int main(void) {
    // 양방향 연결 리스트의 생성 및 초기화
    List list;
    int data;
    ListInit(&list);

    // 8개의 데이터 저장
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);

    // 저장된 데이터의 조회
    if (LFirst(&list, &data)) {
        printf("%d ", data);

        // 오른쪽 노드로 이동하여 데이터 조회
        while (LNext(&list, &data)) {
            printf("%d ", data);
        }

        // 왼쪽 노드로 이동하여 데이터 조회
        while (LPrevious(&list, &data)) {
            printf("%d ", data);
        }
    }

    printf("\n전체 요소 수: %d \n", LCount(&list));

    assert(8 == LRemove(&list));
    assert(7 == LCount(&list));

    assert(7 == LRemove(&list));
    assert(6 == LCount(&list));

    assert(6 == LRemove(&list));
    assert(5 == LCount(&list));

    assert(5 == LRemove(&list));
    assert(4 == LCount(&list));

    assert(4 == LRemove(&list));
    assert(3 == LCount(&list));

    assert(3 == LRemove(&list));
    assert(2 == LCount(&list));

    assert(2 == LRemove(&list));
    assert(1 == LCount(&list));

    assert(1 == LRemove(&list));
    assert(0 == LCount(&list));

    assert(-1 == LRemove(&list));
    assert(0 == LCount(&list));

    printf("\n\n");

    // 8개의 데이터 저장
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);

    // INSERT시 CUR을 옮기지 않기 때문에 데이터 조회를 해서 리스트가 가리키는 커서를 옮겨줘야함.
    // 저장된 데이터의 조회
    if (LFirst(&list, &data)) {
        printf("%d ", data);

        // 오른쪽 노드로 이동하여 데이터 조회
        while (LNext(&list, &data)) {
            printf("%d ", data);
        }
  
    }

    assert(1 == LRemove(&list));
    assert(7 == LCount(&list));

    assert(2 == LRemove(&list));
    assert(6 == LCount(&list));

    assert(3 == LRemove(&list));
    assert(5 == LCount(&list));

    assert(4 == LRemove(&list));
    assert(4 == LCount(&list));

    assert(5 == LRemove(&list));
    assert(3 == LCount(&list));

    assert(6 == LRemove(&list));
    assert(2 == LCount(&list));

    assert(7 == LRemove(&list));
    assert(1 == LCount(&list));

    assert(8 == LRemove(&list));
    assert(0 == LCount(&list));

    assert(-1 == LRemove(&list));
    assert(0 == LCount(&list));


    return 0;
}