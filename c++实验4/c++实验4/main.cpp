#include "mat.h"
int main(int argc, char* argv[]) 					//����չmain()������������
{
	MAT<int>   a(1, 2), b(2, 2), c(1, 2);
	char t[2048];
	a[0][0] = 1;			//���Ƶس�ʼ�����������Ԫ��
	a[0][1] = 2; 			//�ȼ��ڡ�*(a.operator[ ](0)+1)=2;�����ȼ��ڡ�*(a[0]+1)=2;��
	a.print(t);			//��ʼ�����������þ���
	b[0][0] = 3; 	b[0][1] = 4;		//����T* const operator[ ](int r)��ʼ������Ԫ��
	b[1][0] = 5; 	b[1][1] = 6;
	b.print(t);   
	c = a * b;						//���Ծ���˷�����
	c.print(t);
	(a + c).print(t);					//���Ծ���ӷ�����
	c = c - a;						//���Ծ����������
	c.print(t);
	c += a;							//���Ծ���+=������
	c.print(t);
	c = ~a;							//���Ծ���ת������
	c.print(t);
	extern const char* TestMAT(int& s);//������Ժ���
	int score = 0;//��¼����
	const char* hint = TestMAT(score);//��¼��ʾ���
	printf("score:%d \nhint:%s\n", score, hint);
	return 0;
}