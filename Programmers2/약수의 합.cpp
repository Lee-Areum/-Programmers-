//https://programmers.co.kr/learn/courses/30/lessons/12928#
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n) {
    int answer = 0;
    set<int> s;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (s.find(i) != s.end()) {
                break;
            }
            if (i == n / i) {
                s.insert(i);
                answer += i;
            }
            else {
                s.insert({ i, n / i });
                answer += (i + n / i);
            }
        }
    }
    return answer;
}