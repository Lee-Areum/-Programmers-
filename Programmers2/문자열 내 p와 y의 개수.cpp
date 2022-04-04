//https://programmers.co.kr/learn/courses/30/lessons/12916
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int count = 0; // y : +1 , p : -1
    for (char c : s) {
        if (c == 'y'|| c=='Y') count++;
        else if (c == 'p'||c=='P') count--;
    }
    return !count;
}