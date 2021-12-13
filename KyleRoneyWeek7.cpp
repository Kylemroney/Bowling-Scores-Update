// KyleRoneyWeek7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//creating the bowling struct
struct Bowling {
	string bowler;
	int games[4];
	int average;
};

//declaring the rows and columns for the bowlers scores
const int column = 5, row = 10;
bool getBowlingData(string file, string bowlers[row], int games[row][column]);
double* GetAverageScore(int games[row][column]);
void PrettyPrintResults(string bowlers[row], int games[row][column], double average[]);

int main() {
	// opening the text file
	string file = "BowlingScores.txt";
	cout << "Bowler Game 1: Game 2: Game 3: Game 4: Game 5: Average:" << endl;

	// variables used in main
	double* average;
	string bowlers[row];
	int games[row][column];
	Bowling scores[300];

	// outputting the functions
	if (getBowlingData(file, bowlers, games)) {
		average = GetAverageScore(games);
		PrettyPrintResults(bowlers, games, average);
	}
	else {
		cout << "Wrong file" << endl;
	}
	return 0;
}

// finishing the getBowlingData function
bool getBowlingData(string file, string bowlers[row], int games[row][column]) {
	// variables used in getBowlingData
	ifstream dataIn;
	// making sure we have the correct file
	dataIn.open(file.c_str());
	if (dataIn.fail()) {
		cout << "Wrong file";
		return false;
	}
	// gathering the bowlers scores from their games
	else {
		for (int i = 0; i < row; i++) {
			dataIn >> bowlers[i];
			for (int n = 0; n < column; n++) {
				dataIn >> games[i][n];
			}
		}
	}
	return true;
}

// finishing the GetAverageScore fuction
double* GetAverageScore(int games[row][column]) {
	// variables used in GetAverageScore
	double total = 0;
	static double average[row];
	// gathering the average
	for (int i = 0; i < row; i++) {
		total = 0;
		for (int n = 0; n < column; n++) {
			total += games[i][n];
		}
		average[i] = total / column;
	}
	return average;
}

// finishing up outputting the PrettyPrintResults
void PrettyPrintResults(string bowlers[row], int games[row][column], double average[]) {
	for (int i = 0; i < row; i++) {
		cout << setw(10) << left << bowlers[i];
		for (int n = 0; n < column; n++) {
			cout << games[i][n] << "\t";
		}
		cout << setw(5) << *(average + i) << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
