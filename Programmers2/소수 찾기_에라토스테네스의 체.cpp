//https://programmers.co.kr/learn/courses/30/lessons/12921
//에라토스테네스의 체(효율성 - 시간초과),  
#include <string>
#include <vector>
#include <cmath>

using namespace std;
bool checked[1000001] = { false }; //0부터 시작 

void check_sosu(int n) {
    for (int i = 2; i < sqrt(n); i++) {
        for (int k = i + 1; k < n; k++) {
            if (k % i == 0) checked[k] = true;
        }
    }
}

int solution(int n) {
    int answer = 0;
    check_sosu(n);
    for(int i = 2;i<=n;i++){
        if (!checked[i]) answer++;
    }
    return answer;
}