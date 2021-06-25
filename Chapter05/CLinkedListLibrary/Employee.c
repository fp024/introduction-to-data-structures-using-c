#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Employee.h"

Data MakeEmployee(int id, char* name) {
    if (id < 0 || name == NULL) {
        printf("사원 초기화에 실패하였습니다.");
        return NULL;
    }

    Data newEmployee = (Data)malloc(sizeof(Employee));

    if (newEmployee == NULL) {
        assert(0);
        return NULL;
    }

    newEmployee->id = id;

    strncpy_s(newEmployee->name,  strlen(name) + 1, name, NAME_LEN);
    return newEmployee;
}


void ShowEmployeeInfo(Data ptrEmployee) {
    printf("사번: %d, 이름: %s", ptrEmployee->id, ptrEmployee->name);
}
