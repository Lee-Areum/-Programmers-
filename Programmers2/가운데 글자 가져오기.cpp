#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer;
    answer.push_back(s[s.size() / 2]);
    if (s.size() % 2 == 0) {
        answer = s[s.size() / 2 - 1] + answer;
    }
    return answer;
}