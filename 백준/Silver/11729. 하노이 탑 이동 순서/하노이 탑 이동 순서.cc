//#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>


//using namespace std;


void hanoi(int n, int from, int by, int to);

int main() {

	
	int n;
	unsigned long int sum = 1;
	scanf("%d", &n);
	

	for (int i = 0; i < n; i++) {
		sum *= 2;
	}
	printf("%d\n", sum - 1);


	hanoi(n, 1, 2, 3);



	return 0;

}

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		printf("%d %d\n", from, to);
	}
	else {


		hanoi(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(n - 1, by, from, to);
	}


}
