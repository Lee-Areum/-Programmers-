#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    while (n > 3) {
        if (n % 3 == 0) {
            answer = "4" + answer;
            n -= 1;
        }
        else {
            answer = to_string(n % 3) + answer;
        }
        n /= 3;
    }
    if (n == 3) {
        answer = "4" + answer;
    }
    else {
        answer = to_string(n) + answer;
    }
    return answer;
}