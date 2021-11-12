#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iomanip> 
#include <exception>
#include <typeinfo>
#include <string.h>
#include <stdlib.h>
using namespace std;


int calAddress(int i, int j, int c) {
	return i * c + j;
}

template <typename T>
class MAT{
	T* const e;							//指向所有整型矩阵元素的指针
	const int r, c;							//矩阵的行r和列c大小
public:
	MAT(int r, int c);						//矩阵定义
	MAT(const MAT& a);				//深拷贝构造
	MAT(MAT&& a)noexcept;			//移动构造
	virtual ~MAT()noexcept;
	virtual T* const operator[](int r);//取矩阵r行的第一个元素地址，r越界抛异常
	virtual MAT operator+(const MAT& a)const;	//矩阵加法，不能加抛异常
	virtual MAT operator-(const MAT& a)const;	//矩阵减法，不能减抛异常
	virtual MAT operator*(const MAT& a)const;	//矩阵乘法，不能乘抛异常
	virtual MAT operator~()const;					//矩阵转置
	virtual MAT& operator=(const MAT& a);		//深拷贝赋值运算
	virtual MAT& operator=(MAT&& a)noexcept;	//移动赋值运算
	virtual MAT& operator+=(const MAT& a);		//“+=”运算
	virtual MAT& operator-=(const MAT& a);		//“-=”运算
	virtual MAT& operator*=(const MAT& a);		//“*=”运算
//print输出至s并返回s：列用空格隔开，行用回车结束
	virtual char* print(char* s)const noexcept;
};

template MAT<int>;
template MAT<long long>;

//矩阵定义
template <typename T>
MAT<T>::MAT(int r, int c) :r(r),c(c), e(new T[r*c]) {}


	//深拷贝构造
template <typename T>
MAT<T>::MAT(const MAT& a) : r(a.r), c(a.c),e(new T[a.r*a.c]) {
	if (a.e == nullptr) throw "MAT is empty";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) e[calAddress(i,j,c)] = a.e[calAddress(i, j, a.c)];
	}
}


//移动构造	
template <typename T>
MAT<T>::MAT(MAT&& a)noexcept : r(a.r),c(a.c),e(a.e){
	//if (a.e == nullptr) throw "MAT is empty";
	*(T*)&(a.c) = 0;
	*(T*)&(a.r) = 0;
	*(T**)&(a.e) = nullptr;
}

template <typename T>
MAT<T>::~MAT()noexcept {
	if (e != nullptr) delete e;
	*(T**)&e = nullptr;
	*(int*)&r = 0;
	*(int*)&c = 0;
}


//取矩阵r行的第一个元素地址，r越界抛异常
template <typename T>
T* const MAT<T>::operator[](int r) {
	if (r >= this->r || r<0) throw "越界";
	return &e[calAddress(r, 0, c)];
}



//矩阵加法，不能加抛异常
template <typename T>
MAT<T> MAT<T>::operator+(const MAT& a)const {

	if (a.e == nullptr || a.r != r || a.c != c) throw "can not add";
	MAT<T> res(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			res[i][j] = e[calAddress(i, j, c)] + a.e[calAddress(i, j, c)];
		}
	}
	return res;
}




template <typename T>
MAT<T> MAT<T>::operator-(const MAT& a)const {
	if (a.e == nullptr || a.r != r || a.c != c) throw "can not reduce";
	MAT<T> res(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			res[i][j] = e[calAddress(i, j, c)] - a.e[calAddress(i, j, c)];
		}
	}
	return res;
}



template <typename T>
MAT<T> MAT<T>::operator*(const MAT& a)const {
	if (a.e == nullptr || a.r != c) throw "can not mutiply";
	MAT<T> res(r, a.c);
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < a.c; k++) {
			sum = 0;
			for (int j = 0; j < c; j++) {
				sum += e[calAddress(i, j, c)]*a.e[calAddress(j, k, a.c)];
			}
			res[i][k] = sum;
		}
	}
	/*char s[100];
	res.print(s);*/
	return res;
}



template <typename T>
MAT<T> MAT<T>::operator~()const {
	MAT res(c, r);
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			res[i][j] = e[calAddress(j,i,c)];
		}
	}
	return res;
}





template <typename T>
MAT<T>& MAT<T>::operator=(const MAT& a) {
	if (a.e == nullptr) throw "MAT is empty";
	if (this == &a) return *this;
	if (e != nullptr) delete e;
	*(T**)&e = new T[a.r * a.c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) e[calAddress(i, j, c)] = a.e[calAddress(i, j, a.c)];
	}
	*(int*)&r = a.r;
	*(int*)&c = a.c;
	return *this;
}



template <typename T>
MAT<T>& MAT<T>::operator=(MAT&& a)noexcept {
	//if (a.e == nullptr) throw "MAT is empty";
	//e(a.e);
	if (this == &a) return *this;
	if (e != nullptr) delete e;
	*(T**)&e = a.e;
	*(int*)&r = a.r;
	*(int*)&c = a.c;

	*(T**)&a.e = nullptr;
	*(int*)&a.r = 0;
	*(int*)&a.c = 0;
	return *this;
}




template <typename T>
MAT<T>& MAT<T>::operator+=(const MAT& a){
	if (a.e == nullptr || a.r != r || a.c != c) throw "can not add";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			e[calAddress(i, j, c)] += a.e[calAddress(i, j, a.c)];
		}
	}
	return *this;
}

template <typename T>
MAT<T>& MAT<T>::operator-=(const MAT& a) {
	if (a.e == nullptr || a.r != r || a.c != c) throw "can not reduce";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			e[calAddress(i, j, c)] -= a.e[calAddress(i, j, a.c)];
		}
	}
	return *this;
}




template <typename T>
MAT<T>& MAT<T>::operator*=(const MAT& a) {
	if (a.e == nullptr ||a.r != c) throw "can not mutiply";
	*this = *this * a;
	return *this;
}




template <typename T>
char* MAT<T>::print(char* s)const noexcept {
	char temp[20];
	s[0] = '\0';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			_itoa(e[calAddress(i, j, c)], temp,10);
			strcat(s, temp);
			if(j!=c-1)
			strcat(s, "      ");
		}
		strcat(s, "\n");
	}
	//printf("%s\n", s);
	return s;
}

/*
			

virtual T* const operator[](int r);//取矩阵r行的第一个元素地址，r越界抛异常
virtual MAT operator+(const MAT& a)const;	
virtual MAT operator-(const MAT& a)const;	//矩阵减法，不能减抛异常
virtual MAT operator*(const MAT& a)const;	//矩阵乘法，不能乘抛异常
virtual MAT operator~()const;					//矩阵转置
virtual MAT& operator=(const MAT& a);		//深拷贝赋值运算
virtual MAT& operator=(MAT&& a)noexcept;	//移动赋值运算
virtual MAT& operator+=(const MAT& a);		//“+=”运算
virtual MAT& operator-=(const MAT& a);		//“-=”运算
virtual MAT& operator*=(const MAT& a);		//“*=”运算
//print输出至s并返回s：列用空格隔开，行用回车结束
virtual char* print(char* s)const noexcept;

*/


