#include<iostream>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	switch (num/10) {
	case 10:
		printf("A\n");
		break;
	case 9:
		printf("A\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 6:
		printf("D\n");
		break;
	default:
		printf("F\n");
		break;
	}
	return 0;
}