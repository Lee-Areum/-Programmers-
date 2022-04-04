//https://programmers.co.kr/learn/courses/30/lessons/12921
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sosu = { 2 };

bool find_sosu(int num) {
    for (int i = 0; i < sosu.size() && sosu[i] <= sqrt(num); i++) {
        if (num % sosu[i] == 0) return false;
    }
    sosu.push_back(num);
    return true;
}

int solution(int n) {
    int answer = 1;
    for (int i = 3; i <= n; i++) {
        if (i % 2 == 0) continue;
        if (find_sosu(i)) answer++;
    }
    return answer;
}