#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int n;
	struct Node *next;
};


int printNodes(struct Node* p);
void freeNodes(struct Node* p);
void ShowMiddleNodes(struct Node* p,int n);
struct Node *Reversed(struct Node* p);


void main() {
	// �����Լ����� ����� �⺻ ���� ���� 
	int flag = 1;
	int input;

	struct Node *head;
	struct Node *last;
	struct Node *node;

	head = NULL;
	last = NULL;

	printf("������ ������ �Է��Ͻÿ�(����:Ctrl+Z(�������� �Է��ؾ��ϰ� �����Ϸ��� -1) : ");

	while ((scanf("%d", &input)) != EOF){

		printf("������ ������ �Է��Ͻÿ�(����:Ctrl+Z) : ");
		

		
		node = (struct Node*)malloc(sizeof(struct Node));

		
		node->n = input;
		node->next = NULL;

		
		if (head == NULL) {//���Ḯ��Ʈ�� ������� ���(ù��° ����Ʈ)
			head = node;
		}
		else { 
			last->next = node;
		}

		//���� ����Ʈ�� �߰��� node�� �ּҸ� last�� ����
		last = node;

	}//���� �Է¹ް� ������� �Է��� Ctrl+Z�� �ƴϸ� ��带 �Ҵ��Ͽ� ���Ḯ��Ʈ�� �߰�

	
	printf("<�Է¹��� ��� ���>\n");


	int size = printNodes(head); //���Ḯ��Ʈ�� ����ϸ鼭 ������ ���

	printf("\n");

	printf("<�ڷ��� ����:%d��>\n", size); //�ڷ��� ���� ���
	printf("\n");

	printf("<�ڷ��� �߰��� ���>\n");
	ShowMiddleNodes(head,size); //�߰��� ���
	printf("\n");

	printf("<�ڷ��� �������� ���>\n");

	head = Reversed(head);//�������� ����
	printNodes(head);//�������� ����� ���Ḯ��Ʈ�� ���

	head = Reversed(head);//�ٽ� �Է¹��� ������� ����

	printf("\n");

	printf("<Ȧ����° �ڷ� ���� �� ���>\n");


	//Ȧ����° �ڷ� �����ϱ�

		struct Node *temp;
		struct Node *p;
		
		//printf("%d", head); printf("%d", head->n);

		int n = 1;

		p = head;
		temp=p;
		head=p->next;
		p=p->next;
		free(temp); 
		n++;
		//head,p�� �ι�° node�� ��

	

		while(n+1<=size)
		{
			if (n + 1 == size)
			{
				temp = p->next;
				p->next = NULL;
				last = p->next;
				free(temp);
				n++;
			}
			
			else {

				temp = p->next;
				p->next = temp->next;
				free(temp);
				p = p->next;
				n = n + 2;
			}

		}
		

	printNodes(head); //���Ḯ��Ʈ ����ϱ�
	freeNodes(head); //���Ḯ��Ʈ �Ҵ������ϱ�
}




int printNodes(struct Node* p) {
	int n = 0;
	//p�� NULL �ƴ� ��� = ������ ��尡 �ƴ� ���
	while (p != NULL) {
		//��忡 ����� ���� ����ϰ�, ���� ���� �̵�
		printf("%d\n", p->n);
		p = p->next;
		n++;
	}

	return n;
}

void freeNodes(struct Node* p) {
	struct Node *temp;//���� ����� �ּҸ� �ӽ� ������ temp ����
	while (p != NULL) {//���� ����Ʈ�� �� ���� �ݺ�
		temp = p;//���� ��带 �ӽú����� ����
		p = p->next;//���� ���� �̵�
		free(temp);//�ӽú����� ����� ���� ��带 ����
	}
}

void ShowMiddleNodes(struct Node* p, int n) {

	int i = 1;
	while (i < n)
	{
		if (i == n / 2 && n % 2 == 0) printf("%d, ", p->n);
		else if (i == n / 2 + 1) printf("%d\n", p->n);
		i++;
		p = p->next;
	}


}

struct Node *Reversed(struct Node* p)
{
	struct Node *target;
	struct Node *Rhead;
	struct Node *count;

	Rhead = NULL;
	count = p;
	target = NULL;

	
	while (count != NULL)
	{
		target = Rhead;
		Rhead = count;
		count = count->next;
		Rhead->next = target;
	}

	return (Rhead);

}

		

