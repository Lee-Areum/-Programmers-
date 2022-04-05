//https://programmers.co.kr/learn/courses/30/lessons/12930
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    for (char c : s) {
        if (isalpha(c)) {
            char tmp = c;
            if (c >= 'A' && c <= 'Z') {
                tmp += 'a' - 'A';
            }
            if (index % 2 == 0) { //Â¦¼öÀÌ¸é
                tmp += 'A' - 'a';
            }
            answer += tmp;
            index++;
        }
        else {
            index = 0;
            answer += c;
        }
    }
    return answer;
}