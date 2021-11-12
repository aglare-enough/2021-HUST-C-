#include "queue.h"
extern const char* TestQUEUE(int& s);
int main() {
	int score = 0;
	const char* s = TestQUEUE(score);
	printf("score: %d\nhint: %s\n", score, s);
	return 0;
}