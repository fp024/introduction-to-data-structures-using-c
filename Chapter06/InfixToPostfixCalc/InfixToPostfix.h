#ifndef __INFIX_TO_POSTFIX_H__
#define __INFIX_TO_POSTFIX_H__

/**
 * 후위 표기법의 수식으로 변환
 * 
 * @param 후위 표기법으로 변환할 중위 표기법 연산식
 */
void ConvToRPNExp(char exp[]);


/**
 * ConvToRPNExp() 함수의 실행 검증 테스트
 */
void testConvToRPNExp();

#endif
