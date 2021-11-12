#include "queue.h"

QUEUE::operator int() const noexcept {
	if (tail >= head) return (tail - head);
	else return (tail + max - head);
}

QUEUE::QUEUE(int m) : elems(new int[m]), max(m), head(0), tail(0) {
	//printf("size = %d\n",m);
}


//用q深拷贝初始化队列
QUEUE::QUEUE(const QUEUE& q) : elems(new int[q.max]), max(q.max), head(0), tail(0) {
	if (q.elems == nullptr) return;
	*this = q;
}


//用q移动初始化队列
QUEUE::QUEUE(QUEUE&& q)noexcept :elems(q.elems), max(q.max), head(q.head), tail(q.tail) {
	if (elems == nullptr) {
		printf("队列s为空\n");
		return;
	}
	*(int**)&q.elems = nullptr;
	*(int*)&q.max = 0;
	q.head = q.tail = 0;
}


//将e入队列尾部，并返回当前队列
QUEUE& QUEUE::operator<<(int e) {
	if (head == (tail + 1) % max) {
		throw "QUEUE is full!";
	}
	//printf("e = %d入队\n",e);
	elems[tail] = e;
	tail = (tail + 1) % max;
	return *this;
}


//深拷贝赋值并返回被赋值队列
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

//移动赋值并返回被赋值队列
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

//打印队列至s并返回s
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


//返回队列申请的最大元素个数max
int QUEUE::size() const noexcept {
	return max;
}


//从队首出元素到e，并返回当前队列
QUEUE& QUEUE::operator>>(int& e) {
	if (elems == nullptr) {
		printf("队列未初始化\n");
		return *this;
	}
	if (head == tail) {
		throw "QUEUE is empty!";
	}
	e = elems[head];
	head = (head + 1) % max;
	//printf("%d 出队\n", e);
	return *this;
}

//销毁当前队列
QUEUE::~QUEUE() {
	delete elems;
	*(int**)&elems = nullptr;
	head = tail = 0;
	*(int*)&max = 0;
}




