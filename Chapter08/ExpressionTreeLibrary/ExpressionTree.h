/**
 * ExpressionTree.h
 */
#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree2.h"

/**
 * 수식 트리 구성
 * 
 * @param   exp  후위 표기법의 수식
 * @return  수식 트리
 */
BTreeNode* MakeExpTree(char exp[]);


/**
 * 수식 트리 계산
 * 
 * bt의 노드의 루트 데이터 값은 연산자여야한다.
 * 
 * @param bt 계산할 수식 트리
 * @return 수식 트리를 계산한 값
 */
int EvaluateExpTree(BTreeNode* bt);


/**
 * 전위 표기법 기반 출력
 * 
 * @param bt 출력할 수식트리
 */
void ShowPrefixTypeExp(BTreeNode* bt);


/**
 * 중위 표기법 기반 출력
 *
 * @param bt 출력할 수식트리
 */
void ShowInfixTypeExp(BTreeNode* bt);


/**
 * 후위 표기법 기반 출력
 *
 * @param bt 출력할 수식트리
 */
void ShowPostfixTypeExp(BTreeNode* bt);


#endif // !__EXPRESSION_TREE_H__
