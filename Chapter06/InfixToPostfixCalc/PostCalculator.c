/**
 * PostCalculator.c
 */

#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]) {
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;


    StackInit(&stack);

    for (i = 0; i < expLen; i++) {
        tok = exp[i];

        if (isdigit(tok)) {
            SPush(&stack, tok - '0');
        }
        else {
            op2 = SPop(&stack); // 두번째 피연산자
            op1 = SPop(&stack); // 첫번째 피연산자

            switch (tok) {
            case '+':
                SPush(&stack, op1 + op2);
                break;
            case '-':
                SPush(&stack, op1 - op2);
                break;
            case '*':
                SPush(&stack, op1 * op2);
                break;
            case '/':
                SPush(&stack, op1 / op2);
                break;
            }
        }
    }
    return SPop(&stack);
}


void testEvalRPNExp() {
    char postExp1[] = "42*8+";
    char postExp2[] = "123+*4/";

    assert(16 == EvalRPNExp(postExp1));
    assert(1 == EvalRPNExp(postExp2));
}