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

        Answer = 0; // 각 사이클 마다 답이 달라진다.
        int N; cin >> N;
        vector<int> latestScore(N); // N명의 직전라운드까지의 점수
        for (int i = 0; i < N; i++) {
            cin >> latestScore[i];
        }// N명의 참가자들의 직전라운드까지의 성적을 받는다.

        sort(latestScore.begin(), latestScore.end(), std::greater<int>()); //내림차순정렬

        for (int& temp : latestScore) {
            if (temp + N < latestScore[0] + 1) break;

            else Answer++;
        } // for문으로 N을 순차대로 해놨으니 우승가능성이 없는 곳에서부터 안돌게 했으나, 시간초과


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
        } // for문으로 N을 순차대로 해놨으니 우승가능성이 없는 곳에서부터 안돌게 했으나, 시간초과
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
        sort(num, num + N); // 배열을 사용하므로, push_back을 사용하는 vector보다 효율적
        int max_num = 0;
        for (int i = 0; i < N; ++i) {
            if (max_num < num[i] + (N - i)) {
                max_num = num[i] + (N - i);
            }
        } // max_num이란, 우승 가능한 점수 중 가장 낮은 숫자
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