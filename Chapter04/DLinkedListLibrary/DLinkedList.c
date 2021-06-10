#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DLinkedList.h"

// ���� ���� ���� ����Ʈ �տ� ��� �߰�
// 3, 2, 1 ������ �Է��ϸ� ����Ʈ�� 1 -> 2 -> 3 �� �ȴ�.
void FInsert(List* plist, LData data);

// ���� ������ ����Ͽ� ��� �߰�
void SInsert(List* plist, LData data);


void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node*)); // ���� ��� ����
	if (plist->head == NULL) {
		assert(FALSE);
		return;
	}
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}


void LInsert(List* plist, LData data) {
	if (plist->comp == NULL) {	// ���ı����� ���õ��� �ʾҴٸ�
		FInsert(plist, data);	// �Ӹ��� ��� �߰�
	}
	else {
		SInsert(plist, data);
	}
}


int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL) {	// ���� ��尡 NULL�� ����Ų�ٸ�,
		return FALSE;					// ��ȯ�� �����Ͱ� ����.
	}

	plist->before = plist->head;		// before�� ���̳�带 ����Ű�� ��
	plist->cur = plist->head->next;		// cur�� ù��° ��带 ����Ű�� ��

	*pdata = plist->cur->data;			// ù ��° ����� �����͸� ����
	return TRUE; // ������ ��ȯ ����
}


int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL) {
		return FALSE;
	}

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}


LData LRemove(List* plist) {
	if (plist->before == plist->cur) {
		fprintf(stderr, "LRemove�Լ��� �������� ȣ���� �� �����ϴ�. LFirst �Ǵ� LNext �Լ� ȣ���� ����Ǿ��մϴ�.");
		assert(FALSE);
		return -1;
	}

	Node* removalNode = plist->cur;			// �Ҹ����� �ּ� ���� removalNode�� ����
	LData removalData = plist->cur->data;	// �Ҹ����� �����͸� removalData�� ����

	plist->before->next = plist->cur->next;	// �Ҹ� ����� ����Ʈ���� ����
	plist->cur = plist->before;				// cur�� ����Ű�� ��ġ�� ������

	free(removalNode);		// ����Ʈ���� ���ŵ� ��� �Ҹ�
	(plist->numOfData)--;	// ����� �������� �� �ϳ� ����
	return removalData;		// ���ŵ� ����� ��ȯ
}


int LCount(List* plist) {
	return plist->numOfData;
}


void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}


// ===== ������Ϸ� �������� �ʴ� �Լ� =====
void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));	// �� ��� ����
	if (newNode == NULL) {
		assert(FALSE);
		return;
	}
	newNode->data = data;							// �� ��忡 ������ ����

	newNode->next = plist->head->next;		// �� ��尡 �ٸ� ��带 ����Ű�� ��.
	plist->head->next = newNode;			// ���̳�尡 �� ��带 ����Ű�� ��.

	(plist->numOfData)++;	// ����� ����� ���� �ϳ� ���� ��Ŵ

}

void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));	// �� ��� ����
	if (newNode == NULL) {
		assert(FALSE);
		return;
	}

	Node* pred = plist->head;						// pred�� ���̳�带 ����Ŵ

	newNode->data = data;	// �� ��忡 ������ ����

	// �� ��尡 �� ��ġ�� ã�� ���� �ݺ���
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
		pred = pred->next; // ���� ���� �̵�
	}

	newNode->next = pred->next;	// �� ����� �������� ����
	pred->next = newNode;		// �� ����� ������ ����

	(plist->numOfData)++; // ����� ������ �� �ϳ� ����

}