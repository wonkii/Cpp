#include <iostream>
#include <algorithm>
using namespace std;

int Answer;
int Score[200000]; // N의 최대값만큼의 공간을 할당
int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N, K; cin >> N >> K; // 과목의 수, 공부할 과목의 수

		for (int i = 0; i < N; i++) {
			cin >> Score[i];
		}
		sort(Score, Score + N);
		reverse(Score, Score + N);

		for (int i = 0; i < K; i++) {
			Answer += Score[i];
		}
		/////////////////////////////////////////////////////////////////////////////////////////////


		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}