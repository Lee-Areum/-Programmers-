#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 1;
    stack<char> ctr;
    for (int i = 0; i < s.size(); i++) {
        if (ctr.empty() || ctr.top() != s[i]) {
            ctr.push(s[i]);
        }
        else {
            ctr.pop();
        }
    }
    if (ctr.empty()) return 1;
    else return 0;
}