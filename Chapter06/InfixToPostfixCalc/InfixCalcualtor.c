/**
 * InfixCalculator.c
 */

#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[]) {
    int len = strlen(exp);
    int ret;

    char* expcpy = (char*)malloc(len + 1);  // 문자열 저장공간 마련
    strcpy_s(expcpy, len + 1, exp);

    ConvToRPNExp(expcpy);
    ret = EvalRPNExp(expcpy);

    free(expcpy);

    return ret;
}

