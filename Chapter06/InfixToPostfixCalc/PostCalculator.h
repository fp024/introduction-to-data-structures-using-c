/**
 * PostCalculator.h
 */
#ifndef __POST_CALCULATOR_H__
#define __POST_CALCULATOR_H__

/**
 * 후위 표기법 수식을 계산해서 반환한다.
 * 
 * @param exp 후위 표기법 수식 
 * 
 * @ return 계산 결과
 */
int EvalRPNExp(char exp[]);

/**
 * EvalRPNExp() 함수의 실행 테스트 함수
 */
void testEvalRPNExp();

#endif