/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

int Answer;
int main(int argc, char** argv) {
    init_io();

    int T, test_case;
    cin >> T;

    for (test_case = 0; test_case < T; test_case++) {

        Answer = 0; // �� ����Ŭ ���� ���� �޶�����.
        int N; cin >> N;
        vector<int> latestScore(N); // N���� ������������� ����
        for (int i = 0; i < N; i++) {
            cin >> latestScore[i];
        }// N���� �����ڵ��� ������������� ������ �޴´�.

        sort(latestScore.begin(), latestScore.end(), std::greater<int>()); //������������

        for (int& temp : latestScore) {
            if (temp + N < latestScore[0] + 1) break;

            else Answer++;
        } // for������ N�� ������� �س����� ��°��ɼ��� ���� ���������� �ȵ��� ������, �ð��ʰ�


        sort(num, num + N);
        int max_num = 0;
        for (int i = 0; i < N; ++i) {
            if (max_num < num[i] + N - i) {
                max_num = num[i] + N - i;
            }
        }
        for (int i = 0; i < N; ++i) {
            if (max_num <= num[i] + N) {
                ++Answer;
            }
        }

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
*/
/*
for (int& temp : latestScore) {
            if (temp + N < latestScore[0] + 1) break;

            else Winner++;
        } // for������ N�� ������� �س����� ��°��ɼ��� ���� ���������� �ȵ��� ������, �ð��ʰ�
*/

#include <iostream>
#include <algorithm>
using namespace std;

int Answer;
int num[300000];
int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {

        Answer = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////
        int N, max = 0;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> num[i];
        }
        sort(num, num + N); // �迭�� ����ϹǷ�, push_back�� ����ϴ� vector���� ȿ����
        int max_num = 0;
        for (int i = 0; i < N; ++i) {
            if (max_num < num[i] + (N - i)) {
                max_num = num[i] + (N - i);
            }
        } // max_num�̶�, ��� ������ ���� �� ���� ���� ����
        for (int i = 0; i < N; ++i) {
            if (max_num <= num[i] + N) {
                ++Answer;
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}