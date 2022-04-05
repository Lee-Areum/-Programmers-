#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while (n / 10 > 0) {
        answer.push_back(n % 10);
        n /= 10;
    }
    answer.push_back(n % 10);
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/12932