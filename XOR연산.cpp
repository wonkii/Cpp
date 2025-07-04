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
		int C[10]; // �� ��ҿ��� �� ���Ұ� A ���Ϳ� � �ִ� ���� count��
		for (int i = 0; i < 10; i++) {
			C[i] = count(A.begin(), A.end(), i);
		}
		vector<int> Odd; // Ȧ�� �� �ִ� ����
		for (int i = 0; i < 10; i++) {
			if (C[i] % 2 == 1) {
				Odd.push_back(i);
			}
		}

		// N���� ������ �ް�, Ȧ������ ������ ���� �����س���.


		// 2�� ���� �������� 0�̸�, 0 1�̸� 1�� ����
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
  XOR ���꿡�� ������ ���� �߿��� �Ӽ��� �ֽ��ϴ�.


   1. A ^ A = 0 (���� �� ���� XOR �ϸ� 0�� �˴ϴ�.)
   2. A ^ 0 = A (� ���� 0�� XOR �ϸ� �ڱ� �ڽ��� �˴ϴ�.)
   3. XOR ������ ��ȯ ��Ģ�� ���� ��Ģ�� �����մϴ�. (A ^ B ^ C = C ^ A ^ B)

  �������� �־��� ��� ���ڸ� ���� XOR �Ѵٰ� �����غ��ô�.


   * ���� � ���ڰ� ¦�� �� ��Ÿ���ٸ�, �� ���ڵ��� ����ؼ� ���� �̷� XOR ������ �ǰ�, �� ����� 0��
	 �˴ϴ�. (��: 5 ^ 5 ^ 5 ^ 5 = (5 ^ 5) ^ (5 ^ 5) = 0 ^ 0 = 0)
   * ���� � ���ڰ� Ȧ�� �� ��Ÿ���ٸ�, ¦�� ������ŭ�� ���� �̷� 0�� �ǰ�, �������� �ϳ��� ���� �ڱ� �ڽ���
	  �˴ϴ�. (��: 8 ^ 8 ^ 8 = (8 ^ 8) ^ 8 = 0 ^ 8 = 8)


  ���������, �־��� ����Ʈ�� ��� ���ڸ� ó������ ������ ���� XOR �ϸ�, ¦�� �� ��Ÿ���� ���ڵ��� ��� 0��
  �Ǿ� �������, Ȧ�� �� ��Ÿ���� ���ڵ鸸 ���� �׵鳢�� XOR ����� ����� �˴ϴ�.

  �̴� �������� �䱸�ϴ� "Ȧ�� ���� ��Ÿ���� ���ڵ��� ��� XOR �� ���"�� ��Ȯ�� ��ġ�մϴ�.

  ���� �� �׽�Ʈ ���̽����� ��� ���ڸ� �ܼ��� XOR �������ָ� ������ ã�� �� �ֽ��ϴ�.
	 */