//https://programmers.co.kr/learn/courses/30/lessons/12926#
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            bool big = s[i] <= 'Z';
            s[i] += n;
            if ((big && s[i] > 'Z') || s[i] > 'z' || s[i] < 0) {
                s[i] -= 26;
            }
        }
    }
    return s;
}