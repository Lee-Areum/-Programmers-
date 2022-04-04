//https://programmers.co.kr/learn/courses/30/lessons/12918
#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.size() != 4 && s.size() != 6) return false;
        for (char c : s) {
            if (!isdigit(c)) return false;
        }
    return answer;
}