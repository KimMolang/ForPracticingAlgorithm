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
�ߺ��� ���Ұ� �������� �ʴ�, integer�� ������ �迭�� �ֽ��ϴ�.
�迭�� �� ������ ���� Ư���� ���� �Ǵ� ������ index�� ����ϴ� �Լ��� �ϼ����ּ���. ���� ���� �����ϴ� ���ڰ� ������ �����Ѵٸ� �� �� index�� ���� ������ ���� ���� �͸� ����Ͻø� �˴ϴ�.
�ش��ϴ� ���� ������ �� �迭�� ����Ͻø� �˴ϴ�.

�Է� ����

nums	target	result
[2, 7, 11, 15]	9	[0, 1]
[1, 2, 3, 4, 5]	11	[]
[1, 2, 3, 4, 5]	6	[0, 4]

���� ����

1) nums[0] + nums[1] = 2 + 7 = 9 �̹Ƿ�, return ���� [0, 1] �Դϴ�.
2) 11�� ������Ű�� ���ҵ��� ���� �������� �����Ƿ�, return ���� [] �Դϴ�.
3) nums[0] + nums[4] = 1 + 5 = 6, nums[1] + nums[3] = 2 + 4 = 6�̹Ƿ� 2���� index ���� �����մϴ�. �� �� [0, 4]�� [1, 3] ���� ���������� ���� �����Ƿ� return ���� [0, 4] �Դϴ�.

�߰� ����
[a, b], [c, d]���� ���� ��

a < c �� [a, b]�� [c, d]���� ���������� ���� ���ɴϴ�.
a = c ��, b < d�� ��� [a, b]�� [c, d]���� ���������� ���� ���ɴϴ�.
*/


/*
������ �� �ǹ��� ���� ���� ã�� �ֽ��ϴ�.
�ǹ��� ���μ��� ���̴� ũ�Ⱑ 2�� �迭�� �־�����, ������ 0�� 1�� �̷���� 2���� �迭�� �־����ϴ�.
0�� �ǹ��� ���� �� �ִ� ���̶�� �� ��, �ǹ��� ���� �� �ִ� ��� ����� ���� ���ϼ���.

�ǹ��� �ݵ�� ���� �Ǵ� ���η� ����� �ϸ�, �񽺵��� ���� �� �����ϴ�.
�ǹ��� �����ϴ� ��� ���� �ǹ��� ���� �� �ִ� ���̾�� �մϴ�.
�ǹ��� ���� ���� ũ�Ⱑ ������ ��� ���� ���θ� ���� ���� �ʽ��ϴ�.
�Է°��� ������� �ʰ�, �� �迭�� �ִ� ũ��� 100 x 100 �Դϴ�.

�Է� ����

buildingSize	land	result
[1, 2]	[[0, 0], [0, 1]]	2
[2, 2]	[[1, 0, 0], [0, 0, 0], [0, 0, 1]]	2

(�׸�)
1) ���� ��ĭ, ���� ��ĭ�� �ǹ��� ����, ���η� ���� �� �����Ƿ� ����� ���� 2�Դϴ�.
2) ���� ��ĭ, ���� ��ĭ�� �ǹ��� ������ ��, ���� �Ʒ��� ���� �� �����Ƿ� ����� ���� 2�Դϴ�.
*/

/*
������ �־����� �� ������� �ۼ��ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, ���������� ���� ����� �ϴ� ���̺귯���� ����� �� ����. (ex. System.Data.DataTable.Compute ��)

����

�����ڴ� ��+��, ��-��, ��*��, ��/���� �����Ѵ�.
�������� �켱 ������ '*' = '/' > '+' = '-' �̴�.
��/�� �����ڸ� ���ؼ� ���� ���� ������ �ƴ� ��� �Ҽ��� �Ʒ��� ������. (ex. 5/3 = 1, 5/3*3=3)
�־����� ���ڴ� 0�̻� 9������ �����̴�.
�־����� ������ �� ���̴� 100 ���� �۴�.
�־����� ������ �׻� ���ڷ� �����Ѵ�.
�־����� ������ ����, �����ڰ� �����Ƽ� �ϳ��� ���´�. (ex. 3+-5 (X), -3+5 (X), 3-5 (O))
�߰� �������� ������� int ���� (-231 ~ 231)�� ����� �ʴ´�.
���� ��0������ ���������� ��찡 �ִٸ� Impossible�� ��ȯ�Ѵ�.
�־����� ������ ��� ��ȿ�� �����̴�.
�Է�

������ string���� �־�����.
���

������ ������� string���� ��ȯ�Ͽ� ��ȯ�Ѵ�.
*/