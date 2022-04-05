#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(max(n, m),min(n,m)));
    answer.push_back((n * m) / answer[0]);
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12940