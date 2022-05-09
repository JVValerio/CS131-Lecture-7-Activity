////
// Name: Josh Valerio
// Section: CS 131 - 2830
// Program Name: Lecture 7 - Activity
////
#include <iostream>
#include <vector>
using namespace std;

// Slide 18 - Adding 10
void slide18() {
	int TenByTen[10] = { 0 };
	int holder = 0;
	for (int a = 0; a < 10; a++) {
		TenByTen[a] = holder + 10;
		holder = TenByTen[a];
	}
	for (int a = 0; a < 9; a++) {
		cout << TenByTen[a] << ", ";
	}
	cout << TenByTen[9];
	cout << endl;
}
// Slide 32 - Finding smallest
int slide32(const int array[], int sizeNum) {
	int small = array[0];
	for (int c = 0; c < sizeNum; c++) { 
		if (small > array[c]) {
			small = array[c];
		} 
	}// Variables in loops can be reused outside of it, but will stick to different letters for tracking
	return small;
}
// Slide 37 - Rand array
void slide37() {
	int randChecker[11] = { 0 };
	for (int d = 0; d < 10000; d++) {
		int counter = rand() % 10 + 1; 
		randChecker[counter]++;
	}
	for (int e = 0; e < 11; e++) {
		cout << e << ": " << randChecker[e] << endl;
	}
}
// Slide 50 - Bubble sort array
int slide50(int array[], int sizeNum) {
	for (int f = 0; f < sizeNum - 1; f++) {
		for (int g = 0; g < sizeNum - f - 1; g++) {
			if (array[g] > array[g + 1]) {
				swap(array[g], array[g + 1]);
			}
		}
	}
	cout << "The array sorted from smallest to largest:\n";
	for (int h = 0; h < sizeNum; h++) {
		cout << array[h] << ", ";
	}
	return 0;
}
// Slide 66 - Class average
void slide66() {
	int classes[6][30];
	int total = 0, largestAverage = 0, classTop;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 30; j++) {
			classes[i][j] = rand() % 46 + 55;
			total = classes[i][j] + total;
		}
		cout << "Class " << i+1 << "'s average is: " << total / 30  << endl;
		if (largestAverage < total) {
			largestAverage = total;
			classTop = i + 1;
		}
		total = 0;
	}
	cout << "The class with the highest average is class " << classTop 
		<< " with an average of " << largestAverage/30 << endl;
}
// Slide 84 - Trying for each loop
void slide84() {
	int array[] = { 1,2,3,4,5 };
	cout << "Before: ";
	for (int k : array) {
		cout << k << " ";
	}
	cout << endl;
	cout << "After: ";
	for (int& k : array) {
		k --;
		cout << k << " ";
	}
	cout << endl;
}
// Slide 101 - Bubble sort vector
int slide101(int array[], int sizeNum) {
	vector <int> Arr2Vec;
	for (int l = 0; l < sizeNum; l++) {
		Arr2Vec.push_back(array[l]);
	} // Putting array values into array
	for (int m = 0; m < Arr2Vec.size() - 1; m++) {
		for (int n = 0; n < Arr2Vec.size() - m - 1; n++) {
			if (Arr2Vec.at(n) > Arr2Vec.at(n + 1)) {
				swap(Arr2Vec[n], Arr2Vec[n + 1]);
			}
		}
	}
	cout << "The vector sorted from smallest to largest:\n";
	for (int o = 0; o < Arr2Vec.size(); o++) {
		cout << Arr2Vec[o] << ", ";
	}
	cout << endl;
	return 0;
}
// Slide 128 - Converting slide 66 to vector
void slide128() {
	vector <vector<int>> multiVector(30);
	int total = 0, largestAverage = 0, classTop; //reuse
	for (int p = 0; p < 6; p++) {
		for (int q = 0; q < 30; q++) {
			multiVector[p].push_back(rand() % 46 + 55);
			total = multiVector[p][q] + total;
		}
		cout << "Class " << p + 1 << "'s average is: " << total / 30 << endl;
		if (largestAverage < total) {
			largestAverage = total;
			classTop = p + 1;
		}
		total = 0;
	}
	cout << "The class with the highest average is class " << classTop
		<< " with an average of " << largestAverage / 30 << endl;
}

int main() {
	srand(2);
	int mainChoice, num = 0;
	int mainArray[10] = { 70,800,20,60,56,7,65,156,98,10 };
	num = *(&mainArray + 1) - mainArray; // Set size of array
	cout << "Lecture 7 - Daily Activity\n\n" << "Listed are the avaliable slides:\n"
		<< "Slide 18\n" << "Slide 32\n" << "Slide 37\n" << "Slide 50\n" << "Slide 66\n"
		<< "Slide 84\n" << "Slide 101\n" << "Slide 128" << endl;
	cout << "Input the number of a slide to continue: ";
	cin >> mainChoice;
	switch (mainChoice) { // Could loop, but will have to rearrange
	case 18:
		slide18();
		break;
	case 32:
		cout << "Smallest number from array is: " << slide32(mainArray, num) << endl;
		break;
	case 37:
		slide37();
		break;
	case 50:
		slide50(mainArray, num);
		break;
	case 66:
		slide66();
		break;
	case 84:
		slide84();
		break;
	case 101:
		slide101(mainArray, num);
		break;
	case 128:
		slide128();
		break;
	default:
		cout << "No slide number found!";
		break;
	}


	return 0;
}