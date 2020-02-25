#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include <stdio.h>

const int INDEX_NONE = -1;
const int INDEX_ZERO = 0;
const int INDEX_ONE = 1;

using namespace std;

void functionTest()
{
	//vector<vector<int>> point(2, vector<int>(2, 0));
	vector<vector<int> > arr(6, vector<int>(5, 0));


	int serial = -1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = ++serial;
		}
	}


	for (vector<int> vec : arr)
	{
		for (int n : vec)
		{
			cout << n << " ";
		}
		cout << endl;
	}

	cout << arr[1][2] << endl;
}

bool desc(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
	{
		return a.first < b.first;
	}
}

vector<int> solution_01(vector<int> nums, int target) {

	vector<int> answer;
	unordered_map<int, int> saved;
	vector<pair<int, int>> indexList;

	const vector<int>& numList = nums;
	const int SIZE = numList.size();
	for (int i = 0; i < SIZE; ++i)
	{
		int gap = target - numList[i];

		auto iter_find = saved.find(gap);
		if (iter_find == saved.end())
		{
			saved.insert(make_pair(numList[i], i));
		}
		else
		{
			indexList.push_back(pair<int, int>(iter_find->second, i));
		}
	}

	if (indexList.empty() == false)
	{
		std::sort(indexList.begin(), indexList.end(), desc);
		answer.push_back(indexList[INDEX_ZERO].first);
		answer.push_back(indexList[INDEX_ZERO].second);
	}
	

	return answer;
}

#include <queue>
#include <string>

int GetInteger(char character)
{
	if (('0' <= character && character <= '9') == false)
	{
		return INDEX_NONE;
	}

	return character - '0';
}

string solution_03(string input) {

	string answer = "";

	queue<int> q;

	auto iter = input.begin();
	auto iter_end = input.end();

	int prevValueInt = GetInteger(*iter);
	++iter;

	bool multi = false;
	int multiValueInt = 1;

	for (; iter != iter_end; ++iter)
	{
		char curSym = *iter;

		if (curSym == '*')
		{
			if (multi == false)
			{
				multiValueInt = prevValueInt * GetInteger(*(++iter));
			}
			else
			{
				multiValueInt *= GetInteger(*(++iter));
			}

			multi = true;

			if (iter + 1 == iter_end)
			{
				q.push(multiValueInt);
			}
		}
		else if (curSym == '/')
		{
			int value = GetInteger(*(++iter));
			if (value == 0)
			{
				return "Impossible";
			}

			if (multi == false)
			{
				multiValueInt = prevValueInt / value;
			}
			else
			{
				multiValueInt /= value;
			}

			multi = true;

			if (iter + 1 == iter_end)
			{
				q.push(multiValueInt);
			}
		}
		else
		{
			if (multi == true)
			{
				q.push(multiValueInt);
				multi = false;
			}
			else
			{
				q.push(prevValueInt);
			}


			prevValueInt = ((curSym == '+') ? 1 : -1) * GetInteger(*(++iter));

			if (iter + 1 == iter_end)
			{
				q.push(prevValueInt);
			}
		}
	}

	int resultInt = 0;
	while (q.empty() == false)
	{
		int n = q.front();
		q.pop();

		resultInt += n;
	}

	answer = to_string(resultInt);

	return answer;
}

int solution(vector<int> buildingSize, vector<vector<int>> land) {

	int answer = 0;

	const int buildingSizeW = buildingSize[INDEX_ZERO];
	const int buildingSizeH = buildingSize[INDEX_ONE];
	const int NONE_EMPTY = 1;

	const int h = land.size();
	for (int i = 0; i < h; ++i)
	{
		const int w = land[i].size();
		for (int j = 0; j < w; ++j)
		{
			if (land[i][j] == NONE_EMPTY)
			{
				continue;
			}

			if (i + buildingSizeH <= h && j + buildingSizeW <= w)
			{
				bool result = true;
				for (int m = 0; m < buildingSizeH; ++m)
				{
					for (int n = 0; n < buildingSizeW; ++n)
					{
						if (land[i + m][j + n] == NONE_EMPTY)
						{
							result = false;
							break;
						}
					}

					if (result == false)
					{
						break;
					}
				}

				if (result)
				{
					++answer;
				}
			}


			if (buildingSizeW == buildingSizeH)
			{
				continue;
			}

			if (i + buildingSizeW <= h && j + buildingSizeH <= w)
			{
				bool result = true;
				for (int m = 0; m < buildingSizeW; ++m)
				{
					for (int n = 0; n < buildingSizeH; ++n)
					{
						if (land[i + m][j + n] == NONE_EMPTY)
						{
							result = false;
							break;
						}
					}

					if (result == false)
					{
						break;
					}
				}

				if (result)
				{
					++answer;
				}
			}
		}
	}

	return answer;
}

void main_test()
{
	vector<int> buildingSize;
	buildingSize.push_back(1);
	buildingSize.push_back(2);

	vector<vector<int>> land;
	vector<int> a;

	a.push_back(0);
	a.push_back(0);
	land.push_back(a);

	a.clear();
	a.push_back(0);
	a.push_back(1);
	land.push_back(a);

	solution(buildingSize, land);
	//solution_03("8/2-4*5");
}

int main()
{
	
	main_test();
	
	return 0;
}

/*
중복된 원소가 존재하지 않는, integer로 구성된 배열이 있습니다.
배열의 두 숫자의 합이 특정한 값이 되는 숫자의 index를 출력하는 함수를 완성해주세요. 만약 합을 만족하는 숫자가 여러개 존재한다면 그 중 index가 사전 순으로 먼저 오는 것만 출력하시면 됩니다.
해당하는 값이 없으면 빈 배열을 출력하시면 됩니다.

입력 예시

nums	target	result
[2, 7, 11, 15]	9	[0, 1]
[1, 2, 3, 4, 5]	11	[]
[1, 2, 3, 4, 5]	6	[0, 4]

예시 설명

1) nums[0] + nums[1] = 2 + 7 = 9 이므로, return 값은 [0, 1] 입니다.
2) 11을 만족시키는 원소들의 합이 존재하지 않으므로, return 값은 [] 입니다.
3) nums[0] + nums[4] = 1 + 5 = 6, nums[1] + nums[3] = 2 + 4 = 6이므로 2개의 index 쌍이 존재합니다. 그 중 [0, 4]이 [1, 3] 보다 사전순으로 먼저 나오므로 return 값은 [0, 4] 입니다.

추가 설명
[a, b], [c, d]쌍이 있을 때

a < c 면 [a, b]가 [c, d]보다 사전순으로 먼저 나옵니다.
a = c 면, b < d인 경우 [a, b]가 [c, d]보다 사전순으로 먼저 나옵니다.
*/


/*
정수는 새 건물을 지을 땅을 찾고 있습니다.
건물의 가로세로 길이는 크기가 2인 배열로 주어지며, 지도는 0과 1로 이루어진 2차원 배열로 주어집니다.
0이 건물을 지을 수 있는 땅이라고 할 때, 건물을 지을 수 있는 모든 경우의 수를 구하세요.

건물은 반드시 가로 또는 세로로 지어야 하며, 비스듬히 지을 수 없습니다.
건물이 차지하는 모든 땅은 건물을 지을 수 있는 땅이어야 합니다.
건물의 가로 세로 크기가 동일한 경우 가로 세로를 따로 세지 않습니다.
입력값은 비어있지 않고, 땅 배열의 최대 크기는 100 x 100 입니다.

입력 예시

buildingSize	land	result
[1, 2]	[[0, 0], [0, 1]]	2
[2, 2]	[[1, 0, 0], [0, 0, 0], [0, 0, 1]]	2

(그림)
1) 가로 한칸, 세로 두칸인 건물을 가로, 세로로 놓을 수 있으므로 경우의 수는 2입니다.
2) 가로 두칸, 세로 두칸인 건물을 오른쪽 위, 왼쪽 아래에 놓을 수 있으므로 경우의 수는 2입니다.
*/

/*
수식이 주어졌을 때 결과값을 작성하는 프로그램을 작성하시오. 단, 직접적으로 수식 계산을 하는 라이브러리는 사용할 수 없다. (ex. System.Data.DataTable.Compute 등)

가정

연산자는 ‘+’, ‘-‘, ‘*’, ‘/‘만 존재한다.
연산자의 우선 순위는 '*' = '/' > '+' = '-' 이다.
‘/‘ 연산자를 통해서 계산된 값이 정수가 아닌 경우 소수점 아래는 버린다. (ex. 5/3 = 1, 5/3*3=3)
주어지는 숫자는 0이상 9이하의 정수이다.
주어지는 수식의 총 길이는 100 보다 작다.
주어지는 수식은 항상 숫자로 시작한다.
주어지는 수식은 숫자, 연산자가 번갈아서 하나씩 나온다. (ex. 3+-5 (X), -3+5 (X), 3-5 (O))
중간 계산과정과 결과값은 int 범위 (-231 ~ 231)를 벗어나지 않는다.
숫자 “0”으로 나누어지는 경우가 있다면 Impossible을 반환한다.
주어지는 수식은 모두 유효한 형태이다.
입력

수식이 string으로 주어진다.
출력

수식의 결과값을 string으로 변환하여 반환한다.
*/