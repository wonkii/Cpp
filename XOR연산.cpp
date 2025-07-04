#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Answer;
int main(int argc, char** argv)
{
	int T, test_case;


	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		vector<int> S;
		int N;
		cin >> N;
		vector<int> A;
		for (int i = 0; i < N; i++) {
			int Given;
			cin >> Given;
			A.push_back(Given);
		}
		int C[10]; // 각 요소에는 각 원소가 A 벡터에 몇개 있는 지를 count함
		for (int i = 0; i < 10; i++) {
			C[i] = count(A.begin(), A.end(), i);
		}
		vector<int> Odd; // 홀수 개 있는 원소
		for (int i = 0; i < 10; i++) {
			if (C[i] % 2 == 1) {
				Odd.push_back(i);
			}
		}

		// N개의 정수를 받고, 홀수개인 정수를 따로 저장해놓음.


		// 2로 나눈 나머지가 0이면, 0 1이면 1을 기입
		for (int& i : Odd) {
			vector<int> temp;
			int a = 0;
			while (i != 0) {
				i = i / 2;
				temp[a++] += (i % 2);
			}
			reverse(temp.begin(), temp.end());

		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}


/*
  XOR 연산에는 다음과 같은 중요한 속성이 있습니다.


   1. A ^ A = 0 (같은 두 수를 XOR 하면 0이 됩니다.)
   2. A ^ 0 = A (어떤 수를 0과 XOR 하면 자기 자신이 됩니다.)
   3. XOR 연산은 교환 법칙과 결합 법칙이 성립합니다. (A ^ B ^ C = C ^ A ^ B)

  문제에서 주어진 모든 숫자를 전부 XOR 한다고 생각해봅시다.


   * 만약 어떤 숫자가 짝수 번 나타난다면, 그 숫자들은 계속해서 쌍을 이뤄 XOR 연산이 되고, 그 결과는 0이
	 됩니다. (예: 5 ^ 5 ^ 5 ^ 5 = (5 ^ 5) ^ (5 ^ 5) = 0 ^ 0 = 0)
   * 만약 어떤 숫자가 홀수 번 나타난다면, 짝수 개수만큼은 쌍을 이뤄 0이 되고, 마지막에 하나가 남아 자기 자신이
	  됩니다. (예: 8 ^ 8 ^ 8 = (8 ^ 8) ^ 8 = 0 ^ 8 = 8)


  결과적으로, 주어진 리스트의 모든 숫자를 처음부터 끝까지 전부 XOR 하면, 짝수 번 나타나는 숫자들은 모두 0이
  되어 사라지고, 홀수 번 나타나는 숫자들만 남아 그들끼리 XOR 연산된 결과가 됩니다.

  이는 문제에서 요구하는 "홀수 번만 나타나는 숫자들을 모두 XOR 한 결과"와 정확히 일치합니다.

  따라서 각 테스트 케이스마다 모든 숫자를 단순히 XOR 연산해주면 정답을 찾을 수 있습니다.
	 */