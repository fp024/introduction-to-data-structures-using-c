/**
 * InfixCalculator.h
 */
#ifndef __INFIX_CALCULATOR_H__
#define __INFIX_CALCULATOR_H__

/**
 * 중위식 연산 수식을 계산(내부적으로 후위식으로 변환)하여 결과 반환
 * 
 * @param exp 중위식 연산 수식
 * 
 * @return 연산결과
 */
int EvalInfixExp(char exp[]);

#endif