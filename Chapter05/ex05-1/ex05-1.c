#include "CLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * 1. 직원이 입력 순서대로, 순서대로 돌아가며 당직을 선다.
 *
 *      A -> B -> C -> A -> B ...
 *
 * 이부분은 원형 연결리스트의 구현 상으로 바로 사용할 수 있는 부분이여서 추가 구현이 없다.
 */


 /**
   * 2. 직원의 이름과 하나의 숫자를 이용해서 당직자를 확인한 후,
   *
   * @param plist 데이터를 저장할 리스트의 주소 값
   * @param plist 검색된 다음 당직자의 정보를 저장할 구조체
   * @param name 이름
   * @param days 일수
   *
   * @return 일(dyas) 뒤에 누가 당직을 서는지에 검색이 된경우 TRUE,
   *         찾을 수 없을 경우 FALSE 반환
   */
int FoundNextNightShift(List* plist, Data* nextShift, char* name, int days);


/**
 * 이름으로 첫번째 직원을 검색
 *
 * @param plist 데이터를 저장할 리스트의 주소 값
 * @return 검색된 직원의 사번, 발견하지 못할 경우 -1반환
 */
int FindEmployeeIdByName(List* plist, char* name);


/**
 * 리스트 메모리 해제
 * 
 * @param plist 데이터를 삭제할 리스트의 주소 값
 * @return 성공/실패 여부
 */
int FreeList(List* plist);




int main(void) {
    List list;
    ListInit(&list);

    // 리스트에 5개의 데이터를 저장
    LInsert(&list, MakeEmployee(1, "AAA"));
    LInsert(&list, MakeEmployee(2, "BBB"));
    LInsert(&list, MakeEmployee(3, "CCC"));
    LInsert(&list, MakeEmployee(4, "DDD"));
    LInsert(&list, MakeEmployee(5, "EEE"));
    LInsert(&list, MakeEmployee(6, "FFF"));
    LInsert(&list, MakeEmployee(7, "GGG"));

    // FindEmployeeIdByName() 동작 검증
    assert(1 == FindEmployeeIdByName(&list, "AAA"));
    assert(7 == FindEmployeeIdByName(&list, "GGG"));
    assert(2 == FindEmployeeIdByName(&list, "BBB"));
    assert(6 == FindEmployeeIdByName(&list, "FFF"));
    assert(3 == FindEmployeeIdByName(&list, "CCC"));
    assert(5 == FindEmployeeIdByName(&list, "EEE"));
    assert(4 == FindEmployeeIdByName(&list, "DDD"));

    // GetIdOfNextNightShift() 동작 검증
    //   
    // 사번:     1      2      3      4      5      6      7
    // 이름:    AAA -> BBB -> CCC -> DDD -> EEE -> FFF -> GGG 
    // 

    Data nextShift = NULL;
    int found = FoundNextNightShift(&list, &nextShift, "AAA", 3);
    ShowEmployeeInfo(nextShift);
    assert(4 == nextShift->id);

    printf("\n");

    nextShift = NULL;
    found = FoundNextNightShift(&list, &nextShift, "AAA", 7);
    ShowEmployeeInfo(nextShift);
    assert(1 == nextShift->id);

    printf("\n");

    nextShift = NULL;
    found = FoundNextNightShift(&list, &nextShift, "BBB", 8);
    ShowEmployeeInfo(nextShift);
    assert(3 == nextShift->id);


    assert(TRUE == FreeList(&list));

    assert(0 == list.numOfData);


    return 0;
}


int FoundNextNightShift(List* plist, Data* nextShift, char* name, int days) {
    int id = FindEmployeeIdByName(plist, name);

    if (id == -1) {
        return FALSE;
    }

    // id가 -1이 아닐 때, 검색을 완료한 상태가 되고,
    // list의 cur이 현재 검색된 데이터를 가지고 있다.
    // 이 시점에서 days만 큼 next를 호출해주면 된다.
    // 해깔리는 부분이... 리스트에 있는 내용을 복사해서 반환해야하나?

    for (int i = 0; i < days; i++) {
        LNext(plist, nextShift);
    }

    return TRUE;
}


int FindEmployeeIdByName(List* plist, char* name) {
    Data data;

    if (LFirst(plist, &data)) {
        if (strcmp(data->name, name) == 0) {
            return data->id;
        }

        for (int i = 0; i < LCount(plist) - 1; i++) {
            if (LNext(plist, &data) == TRUE
                && strcmp(data->name, name) == 0) {
                return data->id;
            }
        }
    }
    return -1;
}



int FreeList(List* plist) {
    int success = TRUE;
    int count = LCount(plist);
    Data data;


    if (LFirst(plist, &data)) {
        if (LRemove(plist) == FALSE) {
            success = FALSE;
        }

        for (int i = 0; i < count - 1; i++) {
            if (LNext(plist, &data)) {
                if (LRemove(plist) == FALSE) {
                    success = FALSE;
                }
            }
        }
    }
    return success;
}


