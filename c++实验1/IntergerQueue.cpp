#include "queue.h"


//销毁p指向的队列
void destroyQueue(Queue* const p) {
	free(p->elems);
	*(int**)&p->elems = NULL;
	p->head = p->tail = 0;
	*(int*)&p->max = 0;
}

//将e入队列尾部，并返回p
Queue* const enter(Queue* const p, int e) {
	if (p->head == (p->tail+1)%(p->max)) {
		throw "Queue is full!";
	}
	p->elems[p->tail] = e;
	p->tail=(p->tail+1)%(p->max);
	return p;
}

//初始化p指队列：最多申请m个元素
void initQueue(Queue* const p, int m) {
	*(int*)&(p->max) = m;
	*(int **)&(p->elems) = (int*)malloc(m * sizeof(int));
	p->head = 0;
	p->tail = 0;
}

//用s深拷贝初始化p指队列
void initQueue(Queue* const p, const Queue& s) {
	initQueue(p, s.max);
	for (int i = s.head; i%s.max != s.tail; i=(i+1)%s.max) {
		enter(p, s.elems[i]);
	}
}


//返回p指队列的实际元素个数
int  number(const Queue* const p) {
	if (p->tail >= p->head) return (p->tail - p->head);
	else return (p->tail + p->max - p->head);
}


//返回p指队列申请的最大元素个数max
int  size(const Queue* const p) {
	return p->max;
}


 //从队首出元素到e，并返回p
Queue* const leave(Queue* const p, int& e) {
	if (p->elems == NULL) {
		printf("队列未初始化\n");
		return p;
	}
	if (p->head == p->tail) {
		throw "Queue is empty!";
	}
	e = p->elems[p->head];
	p->head = (p->head+1)%p->max;
	return p;
}

//深拷贝赋s给队列并返回p
Queue* const assign(Queue* const p, const Queue& q) {
	if (p == &q) return p;
	if (p->elems != NULL) {
		free(p->elems);
		*(int**)&p->elems = NULL;
	}
	initQueue(p, q);
	return p;
}

 //用s移动初始化p指队列
void initQueue(Queue* const p, Queue&& s) {
	if (s.elems == NULL) {
		printf("队列s为空\n");
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

//打印p指队列至s并返回s
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

//移动赋s给队列并返回p
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

