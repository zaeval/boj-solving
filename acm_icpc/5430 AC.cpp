#include<iostream>
#include<deque>
#include<string.h>
using namespace std;

bool D(deque<int> * deq, bool reverse) {
	if (deq->begin() == deq->end()) {
		printf("error\n");
		return true;
	}
	else if (reverse) {
		deq->pop_back();
	}
	else {
		deq->pop_front();
	}
	return false;
}
void R(bool * reverse) {
	*reverse = !*reverse;
}
void printDeq(deque<int> * deq, bool reverse) {
	printf("[");
	while (deq->begin() != deq->end()) {
		if (reverse) {
			printf("%d", deq->back());
			deq->pop_back();
		}
		else {
			printf("%d", deq->front());
			deq->pop_front();
		}
		if (deq->begin() + 1 <= deq->end()) {
			printf(",");
		}
	}
	printf("]\n");
}
int main() {
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		deque<int> deq;
		int N;
		char p[100001] = { 0 }, gar;
		bool reverse = false;
		bool check = false;
		scanf("%s\n", p);
		scanf("%d\n", &N);

		// [ ¾Ã±â
		scanf("%c",&gar);

		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			deq.push_back(temp);
			// , ¾Ã±â
			scanf("%c",&gar);
		}

		// \n ¾Ã±â
		scanf("%c", &gar);

		for (int j = 0;; j++) {
			if (p[j] == '\0')
				break;
			else if (p[j] == 'D') {
				if (check = D(&deq, reverse))
					break;
			}
			else if (p[j] == 'R') {
				R(&reverse);
			}
		}
		if(!check)
			printDeq(&deq, reverse);
	}
	return 0;
}