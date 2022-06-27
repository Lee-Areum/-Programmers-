#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<string> data) {
    string line = "ACFJMNRT";
    int answer = 40320;
    do {
        for (int i = 0; i < n; i++) {
            int n1, n2;
            n1 = find(line.begin(), line.end(), data[i][0]) - line.begin();
            n2 = find(line.begin(), line.end(), data[i][2]) - line.begin();
            int dif = abs(n1 - n2) - 1;
            int num = data[i][4] - '0';
            if (data[i][3] == '=' && dif == num) continue;
            else if (data[i][3] == '>' && dif > num) continue;
            else if (data[i][3] == '<' && dif < num) continue;
            else {
                answer--;
                break;
            }
        }
    } while (next_permutation(line.begin(), line.end()));
    return answer;
}