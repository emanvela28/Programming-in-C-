// Emmanuel_Velazquez_165_assign1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <string>


int main()
{
	string firstRunner;
	string secondRunner;
	string thirdRunner;
	double firstTime;
	double secondTime;
	double thirdTime;
	string first;
	string second;
	string third;

	cout << "Enter the names of three runners and their finishing times. I will tell you who came in first, second, and third." << endl << endl;

	cout << "Name of runner 1: ";
	getline(cin, firstRunner);

	cout << "Runner 1's finishing time: ";
	cin >> firstTime;
	cout << endl;

	cout << "Name of runner 2: ";
	cin.ignore();
	getline(cin, secondRunner);

	cout << "Runner 2's finishing time: ";
	cin >> secondTime;
	cout << endl;

	cout << "Name of runner 3: ";
	cin.ignore();
	getline(cin, thirdRunner);

	cout << "Runner 3's finishing time: ";
	cin >> thirdTime;
	cout << endl;

	if (firstTime < 0 || secondTime < 0 || thirdTime < 0) {
		cout << "Please enter positive values only for each runner's time." << endl;
		return 1;
	}

	if (firstTime < secondTime && firstTime < thirdTime) {
		first = firstRunner;
		if (secondTime < thirdTime) {
			second = secondRunner;
			third = thirdRunner;
		}
		else {
			second = thirdRunner;
			third = secondRunner;
		}
	}
	else if (secondTime < firstTime && secondTime < thirdTime) {
		first = secondRunner;
		if (firstTime < thirdTime) {
			second = firstRunner;
			third = thirdRunner;
		}
		else {
			second = thirdRunner;
			third = firstRunner;
		}
	}
	else if (thirdTime < firstTime && secondTime > thirdTime) {
		first = thirdRunner;
		if (firstTime < secondTime) {
			second = firstRunner;
			third = secondRunner;
		}
		else {
			second = secondRunner;
			third = firstRunner;
		}
	}
	cout << first << " came in 1st place." << endl;
	cout << second << " came in 2nd place." << endl;
	cout << third << " came in 3rd place." << endl;
}