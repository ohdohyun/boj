#include <iostream>
#include <cmath>
using namespace std;

class bodySize {
public:
	int weight, height, rank;

	int getRank() {
		return rank;
	}

	bodySize() {
		weight = 0;
		height = 0;
		rank = 1;
	}
};


int main() {
	
	int N;
	cin >> N;

	bodySize *person = new bodySize[N];

	for (int i = 0; i < N; i++) {
		cin >> person[i].weight >> person[i].height;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (person[i].height < person[j].height && person[i].weight < person[j].weight) {
				person[i].rank++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << person[i].rank << ' ';
	}


	delete[] person;


	return 0;
}
