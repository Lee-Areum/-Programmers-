#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(int r_diff, int w_diff, char type) {
    if (type == '=') {
        return r_diff == w_diff;
    }
    else if (type == '<') {
        return r_diff < w_diff;
    }
    else {
        return r_diff > w_diff;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string names = "ACFJMNRT";
    do {
        bool flag = true;
        for (string str : data) {
            int man1 = names.find(str[0]);
            int man2 = names.find(str[2]);
            char type = str[3];
            int diff = str[4] - '0';
            int r_diff = man1 - man2;
            if (check(abs(r_diff) - 1, diff, type)) {
                continue;
            }
            flag = false;
            break;
        }
        if (flag) {
            answer++;
        }
    } while (next_permutation(names.begin(), names.end()));
    return answer;
}