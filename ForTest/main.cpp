﻿// you can use includes, for example:

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
1.
This is a demo task.

Write a function:

int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

//int main()
//{
//
//	return 0;
//}

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	sort(A.begin(), A.end(),
		[](int const& a, int const& b)
	{
		return (a < b);
	}
	);
	
	vector<int>::iterator iter = A.begin();
	vector<int>::iterator iter_end = A.end();

	int smallestNumberOutOfArray = 1;

	for (; iter != iter_end; ++iter)
	{
		if (smallestNumberOutOfArray == (*iter))
			smallestNumberOutOfArray++;
	}


	return smallestNumberOutOfArray;
}


/*
2. https://www.geeksforgeeks.org/leaders-in-an-array/
Leaders in an array
Write a program to print all the LEADERS in the array.
An element is leader if it is greater than all the elements to its right side.
And the rightmost element is always a leader.
For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.

Let the input array be arr[] and size of the array be size.
*/

//void printLeaders(int arr[], int size);
//int main()
//{
//	int arr[] = { 16, 17, 4, 3, 5, 2 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	printLeaders(arr, n);
//	return 0;
//}

void printLeaders(int arr[], int size) {

	if (size <= 0)
		return;

	/*
	vector<int> leaders;
	leaders.push_back(arr[size - 1]);

	for (int i = size - 1; i >= 0; --i)
	{
		vector<int>::iterator iter = leaders.begin();
		vector<int>::iterator iter_end = leaders.end();

		bool isLeader = true;
		for (; iter != iter_end; ++iter)
		{
			if (arr[i] <= (*iter))
			{
				isLeader = false;
				break;
			}
		}

		// arr[i] > (*all iter)
		if (isLeader)
		{
			leaders.push_back(arr[i]);
		}
	}
	*/

	// You don't need to keep numbers in Vector!!

	int maxFromRight = arr[size - 1];

	/* Rightmost element is always leader */
	cout << maxFromRight << " ";

	for (int i = size - 2; i >= 0; --i)
	{
		if (maxFromRight < arr[i])
		{
			maxFromRight = arr[i];
			cout << maxFromRight << " ";
		}
	}
}


// 3. String Functions
// https://m.blog.naver.com/PostView.nhn?blogId=matre88&logNo=60168749796&proxyReferer=https%3A%2F%2Fwww.google.ca%2F
// http://hiddenviewer.tistory.com/150
int strlen(char* str)
{
	int len = 0;

	while (str[len])
		++len;

	return len;
}

void strcpy(char* destination, char* source)
{
	int i = 0;

	while (source[i])
	{
		destination[i] = source[i];
		++i;
	}

	destination[++i] = '\0';
}

int strcmp(char* str1, char* str2)
{
	int i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
		{
			++i;
		}
		else if (str1[i] < str2[i])
		{
			return -1;
		}
		else if (str1[i] > str2[i])
		{
			return 1;
		}
	}

	return 0;
}

void strrevers(char* str)
{
	int len = strlen(str);
	int halfLen = len / 2;

	for (int i = 0; i < halfLen; ++i)
	{
		int oppositIndex = len - 1 - i;
		char tmp = str[i];
		str[i] = str[oppositIndex];
		str[oppositIndex] = tmp;
	}
}

// 4. Everyday Programming

// #1
// 정수 배열(int array)가 주어지면 가장 큰 이어지는 원소들의 합을 구하시오.
// 단, 시간복잡도는 O(n).
// Input: [-1, 3, -1, 5] / Output : 7 // 3 + (-1) + 5
// Input: [-5, -3, -1] / Output : -1 // -1
//	Input : [2, 4, -2, -3, 8] / Output : 9 // 2 + 4 + (-2) + (-3) + 8
void EP1(int arr[])
{
	
}

// A* and the others path-finding algorithms

// Data struct and basic algorithms (ex. array, vector, list, map, hash ...)

// https://www.geeksforgeeks.org/leaders-in-an-array/