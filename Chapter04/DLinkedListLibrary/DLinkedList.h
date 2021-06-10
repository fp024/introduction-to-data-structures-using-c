#pragma once

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
} Node;

typedef struct _linkedList {
	Node* head;
	Node* cur;
	Node* tail;
	int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;


/**
 * �ʱ�ȭ�� ����Ʈ�� �ּ� ���� ���ڷ� �����Ѵ�.
 * ����Ʈ ������ ���� ���� ȣ��Ǿ��ϴ� �Լ�
 *
 * @param plist �ʱ�ȭ�� ����Ʈ�� �ּ� ��
 */
void ListInit(List* plist);


/**
 * ����Ʈ�� �����͸� �����Ѵ�
 *
 * @param plist �����͸� ������ ����Ʈ�� �ּ� ��
 * @param data	������
 */
void LInsert(List* plist, LData data);


/**
 * ù ��° �����Ͱ� pdata�� ����Ű�� �޸𸮿� �����
 * ������ ������ ���� �ʱ�ȭ�� �����
 *
 * @param plist ����Ʈ �ּ�
 * @param pdata	ù ��° �����Ͱ� ����� ������
 *
 * @return ���� ������ TRUE(1), ���н� FALSE(0) ��ȯ
 */
int LFirst(List* plist, LData* pdata);


/**
 * ������ �������� ���� �����Ͱ� pdata�� ����Ű�� �޸𸮿� ����ȴ�.
 * �������� ������ ���ؼ� �ݺ� ȣ���� �����ϴ�.
 * ������ ���� �����Ϸ��� ���� LFirst �Լ��� ȣ���ؾ��Ѵ�.
 *
 * @param plist ����Ʈ �ּ�
 * @param pdata ���� �����͸� ������ ������
 *
 * @return ���� ������ TRUE(1), ���н� FALSE(0) ��ȯ
 */
int LNext(List* plist, LData* pdata);


/**
 * LFirst �Ǵ� LNext �Լ��� ������ ��ȯ �����͸� �����Ѵ�.
 * - ������ �����ʹ� ��ȯ��
 * - ������ ��ȯ�����͸� �����ϹǷ� ������ �ݺ�ȣ���� ������� ����
 * @param plist ����Ʈ �ּ�
 * @return ������ ������
 */
LData LRemove(List* plist);


/**
 * ����Ʈ�� ����Ǿ��ִ� ������ ���� ��ȯ
 * @param plist ����Ʈ �ּ�
 * @return ����� �����ͼ�
 */
int LCount(List* plist);


/**
 * ����Ʈ�� ������ ������ �Ǵ� �Լ��� ����Ѵ�.
 *
 * @param plist	����Ʈ �ּ�
 * @param comp	������ ������ �Ǵ� �Լ� ������
 */
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));

