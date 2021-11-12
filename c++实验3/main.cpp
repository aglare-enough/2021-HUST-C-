#include "stack.h"
extern const char* TestSTACK(int& s); 
int main() {
	/*char result[10240];
	STACK s(10);
	s << 10 << 12 << 32 << 324 << 43 << 23 << 23;
	s.print(result);
	printf("%s", result);*/
	int score = 0;
	const char* hint = TestSTACK(score);
	printf("score : %d\nhint:%s\n", score,hint);
	return 0;
}