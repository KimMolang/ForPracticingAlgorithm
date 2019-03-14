// you can use includes, for example:

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#pragma region // Basic
/*
#1 : 배열 안에서 없는 숫자 중 제일 작은 값 출력
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

// 처음에 아래와 같이 비효율적인 걸 생각..
//int solution1(vector<int> &A)
//{
//	// write your code in C++14 (g++ 6.2.0)
//
//	sort(A.begin(), A.end(),
//		[](int const& a, int const& b)
//	{
//		return (a < b);
//	}
//	);
//
//	vector<int>::iterator iter = A.begin();
//	vector<int>::iterator iter_end = A.end();
//
//	int smallestNumberOutOfArray = 1;
//
//	for (; iter != iter_end; ++iter)
//	{
//		if (smallestNumberOutOfArray == (*iter))
//			smallestNumberOutOfArray++;
//	}
//
//	cout << smallestNumberOutOfArray << endl;
//
//	return smallestNumberOutOfArray;
//}

#include <unordered_map>

int FindValueInUnorderedMap
(
	const unordered_map<int, int>& _map
	, const int _Value
)
{
	int nextNumber = _Value + 1;

	auto iter_find = _map.find(nextNumber);

	if (iter_find != _map.end())
	{
		return FindValueInUnorderedMap(_map, nextNumber);
	}
	else
	{
		return nextNumber;
	}
}

int solution2(vector<int> &A)
{
	// write your code in C++14 (g++ 6.2.0)

	vector<int>::iterator iter = A.begin();
	vector<int>::iterator iter_end = A.end();

	unordered_map<int, int> saveValue;

	int smallestNumberOutOfArray = 1;

	for (; iter != iter_end; ++iter)
	{
		saveValue.insert(std::make_pair((*iter), (*iter)));

		int targetValue = (*iter);

		//if(smallestNumberOutOfArray < targetValue)
		if (smallestNumberOutOfArray == targetValue)
		{
			smallestNumberOutOfArray
				= FindValueInUnorderedMap(saveValue, targetValue);
		}
	}

	cout << smallestNumberOutOfArray << endl;
	return smallestNumberOutOfArray;
}

int main_SmallestPositiveIntegerThatIsNotInArray()
{
	vector<int> vec;
	for (int i = 0; i < 200; ++i)
	{
		vec.push_back(1);
		vec.push_back(3);
		vec.push_back(6);
		vec.push_back(4);
		vec.push_back(1);
		vec.push_back(2);
		//vec.push_back(5);
		//vec.push_back(8);
	}

	//solution1(vec);
	solution2(vec);
	return 0;
}


/*
#2 https://www.geeksforgeeks.org/leaders-in-an-array/
: 자기 기준, 오른쪽에 있는 모든 원소보다 자기 값이 제일 큰 원소 출력
Leaders in an array
Write a program to print all the LEADERS in the array.
An element is leader if it is greater than all the elements to its right side.
And the rightmost element is always a leader.
For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.

Let the input array be arr[] and size of the array be size.
*/

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

int main_BiggestValueInRightArray()
{
	int arr[] = { 16, 17, 4, 3, 5, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printLeaders(arr, n);

	return 0;
}

// #3 String Functions
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
#pragma endregion


#pragma region // Everyday Programming
// #1
// 정수 배열(int array)가 주어지면 가장 큰 이어지는 원소들의 합을 구하시오.
// 단, 시간복잡도는 O(n).
// Input: [-1, 3, -1, 5] / Output : 7 // 3 + (-1) + 5
// Input: [-5, -3, -1] / Output : -1 // -1
//	Input : [2, 4, -2, -3, 8] / Output : 9 // 2 + 4 + (-2) + (-3) + 8
int EP1(int arr[])
{
	if (arr[0] == NULL)
		return -99;

	int Present = arr[0];
	int Max = arr[0];
	
	int i = 1;
	while (arr[i])
	{
		int value = arr[i];
		Present += value;

		if (value > Present)
			Present = value;

		if (Present > Max)
			Max = Present;

		++i;
	}

	return Max;
}

// #2 Fibonacci Numbers
// 피보나치 배열은 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 피보나치 수의 합이 된다.
// 정수 N이 주어지면, N보다 작은 모든 짝수 피보나치 수의 합을 구하여라.

int EP2(int n);
//int main()
//{
//	int result = EP2(12);
//	cout << result << endl;
//}
int EP2(int n)
{
	//vector<int> arr;
	//arr.push_back(0);
	//arr.push_back(1);

	//int sum = 0;
	//for ( int i = 0 ; ; ++i )
	//{
	//	int nextFibonacciNumbers = arr[i] + arr[i + 1];

	//	if (nextFibonacciNumbers > n)
	//		break;

	//	arr.push_back(nextFibonacciNumbers);

	//	if (arr[i + 1] % 2 == 0)
	//		sum += arr[i + 1];
	//}

	// 이거 이해하기 어려워서 내 알고리즘 노트에는 다른 식으로 써놨음
	int sum = 0;
	int previouseValue = 1;
	int previouseValueForNextStep = 1;
	for (int i = 1; i < n; i += previouseValue)
	{
		previouseValue = previouseValueForNextStep;
		previouseValueForNextStep = i;

		if (i % 2 == 0)
			sum += i;
	}


	return sum;
}

// #3 PARENTHESIS

void EP3(int n);
void PARENTHESIS(int n); // WOW Crazy
// 해답 http://junprogramer.tistory.com/66
// 해답 https://makefortune2.tistory.com/209
//int main()
//{
//	EP3(3);
//}

void EP3(int n)
{
	PARENTHESIS(n);
}
void PARENTHESIS(int n)
{
	if (n == 0)
		return;
}


// #5
// 정수 배열과 타겟 숫자가 주어지면, 합이 타겟값이 되는 두 원소의 인덱스를 찾으시오.
// 단, 시간복잡도 O(n) 여야 합니다.

#include <unordered_map>

void EP4(int arr[], int target);
//int main()
//{
//	int arr[] = { 2, 5, 6, 1, 10 };
//	EP4(arr, 8);
//}

void EP4(int arr[], int target)
{
	unordered_map<int, int> map;
	for (int i = 0; arr[i] != NULL; ++i)
	{
		auto iter_find = map.find(arr[i]);

		if (iter_find != map.end())
		{
			cout << "[ " << iter_find->second << ", " << i << " ]" << endl;
			return;
		}


		int subtraction = (target - arr[i]);
		map.insert(std::pair<int, int>(subtraction, i));
	}
}
#pragma endregion


#pragma region // Behavior Interactive
int BehaviorInteractive_01(vector<int> &A)
{
	int Present = 0;
	int Max = 0;

	vector<int>::iterator iter = A.begin();
	vector<int>::iterator iter_end = A.end();
	for (; iter != iter_end; ++iter)
	{
		const int value = (*iter);

		if (value < 0)
		{
			Present = 0;
			continue;
		}

		Present += value;

		//if (value > Present)
		//	Present = value;

		if (Present > Max)
			Max = Present;
	}

	return Max;
}

int BehaviorInteractive_02(vector<int> &A)
{
	int Max = 0;

	int ArraySize = A.size();
	for (int i = 0; i < ArraySize; ++i)
	{
		int CurrenValue = A[i] + A[i];

		if (CurrenValue > Max)
		{
			Max = CurrenValue;
		}

		for (int j = i + 1; j < ArraySize; ++j)
		{
			CurrenValue = A[i] + A[j] + (j - i);

			if (CurrenValue > Max)
			{
				Max = CurrenValue;
			}
		}
	}

	return Max;
}


int main_BehaviorInteractive_01_02()
{
	vector<int> arr;
	arr.push_back(-8);
	arr.push_back(4);
	arr.push_back(0);
	arr.push_back(5);
	arr.push_back(-3);
	arr.push_back(6);

	for (auto& iter : arr)
	{
		cout << iter << " ";
	}

	cout << endl;
	cout << BehaviorInteractive_01(arr) << endl;
	cout << BehaviorInteractive_02(arr) << endl;

	return 0;
}

// AT list 3
int GetTotalPeriodNum(int _ParticlesNum)
{
	const int AT_LEAST_PARTICLES_NUM = 3;
	const int MAX_TOTAL_TIMES = 1000000000;


	if (_ParticlesNum < AT_LEAST_PARTICLES_NUM)
		return 0;


	int LastNum = _ParticlesNum - 2;
	int TotalNum = (LastNum * (LastNum + 1)) / 2;

	if (TotalNum > MAX_TOTAL_TIMES)
		return -1;

	//bool isOdd = (LastNum % 2) ? true : false;
	//int HalfSize = LastNum / 2;

	//int PlusValue = LastNum + 1;

	//for (int i = 0; i < HalfSize; ++i)
	//{
	//	TotalNum += PlusValue;
	//}

	//if (isOdd)
	//	TotalNum += HalfSize + 1;

	return TotalNum;
}

int BehaviorInteractive_03(vector<int> &A)
{
	//const int MAX_TOTAL_TIMES = 1000000000;


	vector<int>::iterator iter = A.begin();
	vector<int>::iterator iter_end = A.end();

	int TotalTimes = 0;

	++iter;
	int CurrentVelocity = (*iter) - (*(iter - 1));
	int CurrentParticlesCounter = 1;


	for (; iter != iter_end; ++iter)
	{
		int Velocity = (*iter) - (*(iter - 1));

		if (CurrentVelocity == Velocity)
		{
			++CurrentParticlesCounter;
		}
		else
		{
			int Total = GetTotalPeriodNum(CurrentParticlesCounter);
			// nononononono
			// Check here and MAX_TOTAL_TIMES
			// Total += CurrentParticlesCounter  - 1

			if (Total == -1)
				return -1;


			TotalTimes += Total;

			CurrentVelocity = Velocity;
			CurrentParticlesCounter = 2;
		}
	}

	TotalTimes += GetTotalPeriodNum(CurrentParticlesCounter);


	return TotalTimes;
}

int main_BehaviorInteractive_03()
{
	vector<int> arr;
	//for( int i = 0; i < 10000; ++i)
	//	arr.push_back(2);
	arr.push_back(-1);
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(0);

	cout << BehaviorInteractive_03(arr) << endl;

	return 0;
}


//
//int BehaviorInteractive_03(vector<int> &A)
//{
//
//	const int AT_LEAST_PARTICLES_NUM = 3;
//	const int MAX_TOTAL_TIMES = 1000000000;
//
//	vector<int>::iterator iter = A.begin();
//	vector<int>::iterator iter_end = A.end();
//
//	int TotalTimes = 0;
//
//	++iter;
//	int CurrentVelocity = (*iter) - (*(iter - 1));
//	int CurrentParticlesCounter = 2;
//
//
//	for (; iter != iter_end; ++iter)
//	{
//		int Velocity = (*iter) - (*(iter - 1));
//		bool bNeedInit = false;
//
//		if (CurrentVelocity == Velocity)
//		{
//			++CurrentParticlesCounter;
//
//			if (CurrentParticlesCounter >= AT_LEAST_PARTICLES_NUM)
//			{
//				++TotalTimes;
//
//				if (TotalTimes > MAX_TOTAL_TIMES)
//					return -1;
//
//				bNeedInit = true;
//			}
//		}
//		else
//		{
//			bNeedInit = true;
//		}
//
//		if (bNeedInit)
//		{
//			CurrentVelocity = Velocity;
//			CurrentParticlesCounter = 2;
//		}
//	}
//
//	return TotalTimes;
//}

#pragma endregion




// CPP program to reverse a string 
#include <stdio.h> 

/* function prototype for utility function to
reverse a string from begin to end  */
void reverse(char* begin, char* end);

/*Function to reverse words*/
void reverseWords(char* s)
{
	char* word_begin = s;
	char* temp = s; /* temp is for word boundry */

					/*STEP 1 of the above algorithm */
	while (*temp) {
		temp++;
		if (*temp == '\0') {
			reverse(word_begin, temp - 1);
		}
		else if (*temp == ' ') {
			reverse(word_begin, temp - 1);
			word_begin = temp + 1;
		}
	} /* End of while */

	  /*STEP 2 of the above algorithm */
	reverse(s, temp - 1);
}

/* UTILITY FUNCTIONS */
/*Function to reverse any sequence starting with pointer
begin and ending with pointer end  */
void reverse(char* begin, char* end)
{
	char temp;
	while (begin < end) {
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

int main_reverseWordsInString()
{
	char s[] = "i like this program very much";
	char* temp = s;

	reverseWords(s);
	printf("%s", s);

	return 1;
}

// #19
// 2차 정수 배열(2D int array)가 주어지면, 소용돌이 모양으로 원소들을 프린트하시오.
// Given a 2D integer array, print all elements in a circular spiral shape starting from[0][0].
void EP_19()
{
	const int SIZE_WIDTH = 6;
	const int SIZE_HEIGHT = 3;

	int arr[SIZE_HEIGHT][SIZE_WIDTH]
		= { { 1,  2,  3,  4,  5,  6 }
		, { 7,  8,  9,  10, 11, 12 }
		, { 13, 14, 15, 16, 17, 18 } };
	//const int SIZE_WIDTH = 4;
	//const int SIZE_HEIGHT = 4;

	//int arr[SIZE_HEIGHT][SIZE_WIDTH]
	//	= {{ 1,  2,  3,  4 }
	//	, { 7,  8,  9,  10 }
	//	, { 13, 14, 15, 16 }
	//	, { 17, 18, 19, 20 } };


	//int ToRight = SIZE_WIDTH - 1;
	//int ToDown = SIZE_HEIGHT - 1;
	//int ToLeft = 1;
	//int ToUp = 1;
	
	int widthCnt = SIZE_WIDTH - 1;
	int heightCnt = SIZE_HEIGHT - 1;

	int x = 0, y = 0;


	//while (x == ToLeft - 1 && y == ToUp - 1)
	while (widthCnt > 0 || heightCnt > 0)
	{
		cout << "1 : " << endl;
		//for (; x < ToRight; ++x)
		for (int i = 0; i < widthCnt; ++i, ++x)
		{
			cout << "y : " << y << "\tx : " << x << "\t" << arr[y][x] << endl;
		}

		//--ToRight;
		cout << endl;


		cout << "2 : " << endl;
		//for (; y <= ToDown; ++y)
		for (int i = 0; i < heightCnt; ++i, ++y)
		{
			cout << "y : " << y << "\tx : " << x << "\t" << arr[y][x] << endl;
		}

		//--ToDown;
		cout << endl;


		
		//if (y > ToDown)
		if(y <= heightCnt + (SIZE_HEIGHT - y))
		{
			cout << "3 : " << endl;
			//for (; x >= ToLeft; --x)
			for (int i = 0; i < widthCnt; ++i, --x)
			{
				cout << "y : " << y << "\tx : " << x << "\t" << arr[y][x] << endl;
			}

			//++ToLeft;
			cout << endl;
		}
		

		//if (x <= ToLeft)
		{
			cout << "4 : " << endl;
			//for (; y >= ToUp; --y)
			for (int i = 0; i < heightCnt; ++i, --y)
			{
				cout << "y : " << y << "\tx : " << x << "\t" << arr[y][x] << endl;
			}

			//++ToUp;
			cout << endl;

			++y;
			++x;
		}

		widthCnt -= 2;
		heightCnt -= 2;

		cout << "================" << endl;
		cout << "One-Step-End" << endl;
		cout << "y : " << y << "\tx : " << x <<endl;
		//cout << "ToRight : " << ToRight << "\tToDown : " << ToDown << endl;
		//cout << "ToLeft : " << ToLeft << "\tToUp : " << ToUp << endl;
		cout << "================" << endl;;
	}
}
// 규칙이 아예 안 맞음..


int main_spiralPrint()
{
	const int SIZE_WIDTH = 6;
	const int SIZE_HEIGHT = 3;

	int a[SIZE_HEIGHT][SIZE_WIDTH]
		= { { 1,  2,  3,  4,  5,  6 }
		, { 7,  8,  9,  10, 11, 12 }
		, { 13, 14, 15, 16, 17, 18 } };

	
	int i, k = 0, l = 0;
	int n = SIZE_WIDTH, m = SIZE_HEIGHT;

	/*  k - starting row index
	m - ending row index
	l - starting column index
	n - ending column index
	i - iterator
	*/

	while (k < m && l < n)
	{
		/* Print the first row from the remaining rows */
		for (i = l; i < n; ++i)
		{
			printf("%d ", a[k][i]);
		}
		k++;
		cout << endl;

		/* Print the last column from the remaining columns */
		for (i = k; i < m; ++i)
		{
			printf("%d ", a[i][n - 1]);
		}
		n--;
		cout << endl;

		/* Print the last row from the remaining rows */
		if (k < m)
		{
			for (i = n - 1; i >= l; --i)
			{
				printf("%d ", a[m - 1][i]);
			}
			m--;
			cout << endl;
		}

		/* Print the first column from the remaining columns */
		if (l < n)
		{
			for (i = m - 1; i >= k; --i)
			{
				printf("%d ", a[i][l]);
			}
			l++;
			cout << endl;
		}
	}

	return 0;
}

int main()
{
	main_spiralPrint();
	getchar();
	return 0;
}