#include "queue.h"

QUEUE::operator int() const noexcept {
	if (tail >= head) return (tail - head);
	else return (tail + max - head);
}

QUEUE::QUEUE(int m) : elems(new int[m]), max(m), head(0), tail(0) {
	//printf("size = %d\n",m);
}


//��q�����ʼ������
QUEUE::QUEUE(const QUEUE& q) : elems(new int[q.max]), max(q.max), head(0), tail(0) {
	if (q.elems == nullptr) return;
	*this = q;
}


//��q�ƶ���ʼ������
QUEUE::QUEUE(QUEUE&& q)noexcept :elems(q.elems), max(q.max), head(q.head), tail(q.tail) {
	if (elems == nullptr) {
		printf("����sΪ��\n");
		return;
	}
	*(int**)&q.elems = nullptr;
	*(int*)&q.max = 0;
	q.head = q.tail = 0;
}


//��e�����β���������ص�ǰ����
QUEUE& QUEUE::operator<<(int e) {
	if (head == (tail + 1) % max) {
		throw "QUEUE is full!";
	}
	//printf("e = %d���\n",e);
	elems[tail] = e;
	tail = (tail + 1) % max;
	return *this;
}


//�����ֵ�����ر���ֵ����
QUEUE& QUEUE::operator=(const QUEUE& q) {
	if (q.elems == nullptr) return *this;
	for (int i = 0; i < q.max; i++) {
		elems[i] = q.elems[i];
	}
	*(int*)&max = q.max;
	head = q.head;
	tail = q.tail;
	return *this;
}

//�ƶ���ֵ�����ر���ֵ����
QUEUE& QUEUE::operator=(QUEUE&& q)noexcept {
	if (&q == this) return *this;
	if (elems != nullptr) {
		free(elems);
		//free(p);
		*(int**)&elems = nullptr;
	}

	*(int**)&elems = q.elems;
	*(int*)&max = q.max;
	head = q.head;
	tail = q.tail;
	*(int**)&q.elems = nullptr;
	*(int*)&q.max = 0;
	q.head = q.tail = 0;
	return *this;
}

//��ӡ������s������s
char* QUEUE::print(char* s) const noexcept {
	s[0] = '\0';
	char temp[30];
	for (int i = head; i != tail; i = (i + 1) % max) {
		//printf("max:%d , i : %d\n", max, i);
		//printf(" %d ", *(this->elems+i));
		_itoa(elems[i], temp, 10);
		strcat(s, temp);
		//strcat(s, ",");
		if ((i + 1) % max != tail) /*printf(",")*/ strcat(s, ",");
	}
	//printf("\n");
	return s;
}


//���ض�����������Ԫ�ظ���max
int QUEUE::size() const noexcept {
	return max;
}


//�Ӷ��׳�Ԫ�ص�e�������ص�ǰ����
QUEUE& QUEUE::operator>>(int& e) {
	if (elems == nullptr) {
		printf("����δ��ʼ��\n");
		return *this;
	}
	if (head == tail) {
		throw "QUEUE is empty!";
	}
	e = elems[head];
	head = (head + 1) % max;
	//printf("%d ����\n", e);
	return *this;
}

//���ٵ�ǰ����
QUEUE::~QUEUE() {
	delete elems;
	*(int**)&elems = nullptr;
	head = tail = 0;
	*(int*)&max = 0;
}




