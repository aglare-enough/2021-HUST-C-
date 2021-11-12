#include "queue.h"


//����pָ��Ķ���
void destroyQueue(Queue* const p) {
	free(p->elems);
	*(int**)&p->elems = NULL;
	p->head = p->tail = 0;
	*(int*)&p->max = 0;
}

//��e�����β����������p
Queue* const enter(Queue* const p, int e) {
	if (p->head == (p->tail+1)%(p->max)) {
		throw "Queue is full!";
	}
	p->elems[p->tail] = e;
	p->tail=(p->tail+1)%(p->max);
	return p;
}

//��ʼ��pָ���У��������m��Ԫ��
void initQueue(Queue* const p, int m) {
	*(int*)&(p->max) = m;
	*(int **)&(p->elems) = (int*)malloc(m * sizeof(int));
	p->head = 0;
	p->tail = 0;
}

//��s�����ʼ��pָ����
void initQueue(Queue* const p, const Queue& s) {
	initQueue(p, s.max);
	for (int i = s.head; i%s.max != s.tail; i=(i+1)%s.max) {
		enter(p, s.elems[i]);
	}
}


//����pָ���е�ʵ��Ԫ�ظ���
int  number(const Queue* const p) {
	if (p->tail >= p->head) return (p->tail - p->head);
	else return (p->tail + p->max - p->head);
}


//����pָ������������Ԫ�ظ���max
int  size(const Queue* const p) {
	return p->max;
}


 //�Ӷ��׳�Ԫ�ص�e��������p
Queue* const leave(Queue* const p, int& e) {
	if (p->elems == NULL) {
		printf("����δ��ʼ��\n");
		return p;
	}
	if (p->head == p->tail) {
		throw "Queue is empty!";
	}
	e = p->elems[p->head];
	p->head = (p->head+1)%p->max;
	return p;
}

//�����s�����в�����p
Queue* const assign(Queue* const p, const Queue& q) {
	if (p == &q) return p;
	if (p->elems != NULL) {
		free(p->elems);
		*(int**)&p->elems = NULL;
	}
	initQueue(p, q);
	return p;
}

 //��s�ƶ���ʼ��pָ����
void initQueue(Queue* const p, Queue&& s) {
	if (s.elems == NULL) {
		printf("����sΪ��\n");
		return;
	}
	*(int**)&p->elems = s.elems;
	*(int*)&p->max = s.max;
	p->head = s.head;
	p->tail = s.tail;
	*(int**)&s.elems = NULL;
	*(int*)&s.max = 0; 
	s.head = s.tail = 0;
}

//��ӡpָ������s������s
char* print(const Queue* const p, char* s) {
	char temp[30];
	for (int i = p->head; i != p->tail; i = (i + 1) % p->max) {
		printf("%d ", p->elems[i]);
		_itoa(p->elems[i],temp,10);
		strcat(s, temp);
		strcat(s, ",");
		if ((i + 1) % p->max != p->tail) printf(",");
	}
	printf("\n");
	return s;
}

//�ƶ���s�����в�����p
Queue* const assign(Queue* const p, Queue&& q) {
	if (&q == p) return p;
	if (p->elems != NULL) {
		free(p->elems);
		//free(p);
		*(int**)&p->elems = NULL;
	}
	
	*(int**)&p->elems = q.elems;
	*(int*)&p->max = q.max;
	p->head = q.head;
	p->tail = q.tail;
	*(int**)&q.elems = NULL;
	*(int*)&q.max = 0;
	q.head = q.tail = 0;
	return p;
}

