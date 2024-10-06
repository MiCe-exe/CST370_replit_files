#include <iostream>
#include <string>

using namespace std;

void printArr(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	cout << endl;
}

void posI(int i) {
	cout << "pos i: " << i << endl;
}

void posJ(int j) {
	cout << "pos j: " << j << endl;
}

void printStatus(string s) {
	cout << s << endl;
}


int main()
{
	//int arr[] = {5,-3,1,-9,-8,2,-4,7};
	////int arr[] = { 5,3,1,9,8,2,4,7 };
	//int MAX_SIZE = 8;
	//int midIndex = 0;
	//bool limitI = false;

	////if (MAX_SIZE % 2 == 0) {
	////	midIndex = (MAX_SIZE / 2);
	////}
	////else {
	////	midIndex = (MAX_SIZE / 2) +1;
	////}

	//midIndex = (MAX_SIZE / 2);

	//for (int i = 1; i < MAX_SIZE; i++) {
	//	posI(i);


	//	if (arr[i] > arr[0]) {

	//		for (int j = MAX_SIZE - 1; j > 0; j--) {
	//			posJ(j);

	//			if (i > j && arr[j] < arr[0] && arr[i] > 5) {
	//				cout << endl << " +++++++ Piv Swap +++++++++\n";

	//			}

	//			if (arr[j] < arr[0])
	//			{
	//				int tmp = arr[i];
	//				arr[i] = arr[j];
	//				arr[j] = tmp;
	//				break;
	//			}




	//		}
	//	}
	//}

	//int arr[] = { -4, 3, 9, -6, 2, -5, 8, 7};
	//int arr[] = { 10, 20, 30, 40, 50, 60, 70 };
	int arr[] = { -10, -30, 25, -15, 40 };
	//int MAX_SIZE = 8;
	int MAX_SIZE = sizeof(arr) / sizeof(arr[0]);
	int i = 1, j = MAX_SIZE - 1;

	bool exitLoop = false;


	while(!exitLoop) {

		if (arr[i] > arr[j])
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}

		if (arr[i] > arr[0] && arr[j] > arr[0]) {

			j--;
		}

		if (i > j) {
			exitLoop = true;

			if (!(arr[0] < arr[i] && arr[j] < arr[i])) {
				int temp = arr[0];
				arr[0] = arr[j];
				arr[j] = temp;
			}
		}


	}

	for (int i = 0; i < MAX_SIZE; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}