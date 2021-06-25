#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

/**
 * 문제 05-1
 *
 * 직원 구조체
 */

 // 이름의 크기
#define NAME_LEN 30
typedef struct _employee {
    int id;         // 사번
    char name[NAME_LEN];     // 이름, 이름은 최대크기가 어느 한계이니 배열로 하자.
} Employee;

typedef Employee* Data;

/**
 * Employee 구조체 변수의 동적 할당 및 초기화후 주소값 반환
 *
 * @param id  사번 (사번은 0이상 정수만 가능)
 * @param name 이름
 * @return Employee 구조체 주소, 초기화 실패시 NULL반환
 */
Data MakeEmployee(int id, char* name);


/**
 * Employee 구조체 변수의 정보출력
 * @param ptrEmployee   Employee 구조체 주소
 */
void ShowEmployeeInfo(Data ptrEmployee);

#endif