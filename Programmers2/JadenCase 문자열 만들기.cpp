#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool blank = true;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            if (blank) {
                answer+= toupper(s[i]);
            }
            else answer += tolower(s[i]);
        }
        else {
            answer += s[i];
        }
        if (s[i] == ' ') blank = true;
        else blank = false;
    }
    return answer;
}