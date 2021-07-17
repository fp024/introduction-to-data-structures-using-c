/**
 * InfixToPostfix.c
 */
#include "ListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

 /**
  * 연산자의 연산 우선순위 정보 반환
  * @param 연산자
  *
  * @return 연산자의 우선순위
  */
int GetOpPrec(char op) {
    switch (op) {
    case '*':
    case '/':
        return 5;   // 가장 높은 연산의 우선순위
    case '+':
    case '-':
        return 3;
    case '(':
        return 1;
    }

    return -1;  // 등록되지 않은 연산자임을 알림!
}


/**
 * 두 연산자의 우선 순위를 반환
 *
 * @param op1   연산자1
 * @param op2   연산자2
 *
 * @return  1이면 op1의 연산자가 우선순위가 높음 -1이면 op2의 우선순위가 높음, 0이면 우선순위가 같음
 */
int WhoPrecOp(char op1, char op2) {
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if (op1Prec > op2Prec) {
        return 1;
    }
    else if (op1Prec < op2Prec) {
        return -1;
    }
    else {
        return 0;
    }
}


void ConvToRPNExp(char exp[]) {
    Stack stack;
    int expLen = strlen(exp);
    char* convExp = (char*)malloc(expLen + 1); // 변환된 수식을 담을 공간 마련

    int i, idx = 0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char) * expLen + 1); // 할당된 배열을 0으로 초기화
    StackInit(&stack);

    for (i = 0; i < expLen; i++) {
        tok = exp[i]; // exp로 전달된 수식을 한 문자씩 tok에 저장

        if (isdigit(tok)) {
            convExp[idx++] = tok;   // 숫자이면 배열 convExp에 그냥 저장
        }
        else {
            switch (tok) {
            case '(':
                SPush(&stack, tok); // 여는 소괄호면 스텍에 쌓음
                break;
            case ')':
                while (1) {
                    popOp = SPop(&stack);   // 스택에서 연산자를 꺼내어,
                    if (popOp == '(') {     // 연산자 (를 만날때까지,
                        break;
                    }
                    convExp[idx++] = popOp; // 배열 convExp에 저장한다.
                }

                break;
            case '+': case '-':
            case '*': case '/':
                while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) { 
                    // 스택쪽에 있는 연산자가 연산자 우선순위가 높거나 같으면 빼서 결과 배열에 추가
                    convExp[idx++] = SPop(&stack);
                }
                SPush(&stack, tok);  // 스택이 비었거나, 스택쪽의 연산자가 연산자 우선순위가 작다면 신규 연산자를 스택에 추가
                break;
            }
        }
    }

    // 스택에 남아있는 모든 연산자를 배열 convExp로 이동
    while (!SIsEmpty(&stack)) {
        convExp[idx++] = SPop(&stack);
    }

    strcpy_s(exp, expLen + 1, convExp); //변환된 수식을 exp에 복사
    free(convExp);

}


void testConvToRPNExp() {
    char exp1[] = "1+2*3";
    int exp1Length = strlen(exp1);

    char exp2[] = "(1+2)*3";
    int exp2Length = strlen(exp2);

    char exp3[] = "((1-2)+3)*(5-2)";
    int exp3Length = strlen(exp3);

    ConvToRPNExp(exp1);
    ConvToRPNExp(exp2);
    ConvToRPNExp(exp3);

    printf("test1: %s \n", exp1);
    printf("test2: %s \n", exp2);
    printf("test3: %s \n", exp3);

    assert(strncmp("123*+", exp1, exp1Length) == 0);
    assert(strncmp("12+3*", exp2, exp2Length) == 0);
    assert(strncmp("12-3+52-*", exp3, exp3Length) == 0);
}
