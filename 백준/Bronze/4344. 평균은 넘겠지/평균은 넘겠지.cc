#include<iostream>


using namespace std;



int main() {
	
	int caseNum, numberOfStudent, sum = 0, student[1000] = { 0, };

	double rate, overAverage = 0.000;

	cin >> caseNum;

	for (int i = 0; i < caseNum; i++) {

		cin >> numberOfStudent;
		for (int j = 0; j < numberOfStudent; j++) {
			cin >> student[j];
			sum += student[j];
		}
		for (int j = 0; j < numberOfStudent; j++) {
			if (sum < student[j] * numberOfStudent) {
				overAverage++;
			}
		}

		cout.precision(3);
		cout << fixed << overAverage / (double)numberOfStudent * 100 << '%' << endl;

		/////////
		sum = 0; overAverage = 0;
	}



	return 0;

}
