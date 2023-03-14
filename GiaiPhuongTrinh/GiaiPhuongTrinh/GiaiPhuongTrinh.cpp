// GiaiPhuongTrinh.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdlib.h>
#include <stdio.h>
#include "PhuongTrinh.h"


int main()
{
	double a, b, x;
	int songhiem;
	printf("Please enter a=");
	scanf("%lf", &a);
	printf("Please enter b=");
	scanf("%lf", &b);
	songhiem = GiaiPTBac1(a, b, &x);
	switch (songhiem) {
	case -1:
		printf("No result"); break;
	case 0:
		printf("infinite"); break;
	case 1:
		printf("one result, %lf", x); break;
	default:
		printf("Invalid returned value"); break;
	}
	exit(0);
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
