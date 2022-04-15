#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    stack<char> list;
    for (char c : s) {
        if (c == '(') {
            list.push(c);
        }
        else {
            if (list.empty()) return false;
            list.pop();
        }
    }
    if (list.empty())return true;
    else return false;
}