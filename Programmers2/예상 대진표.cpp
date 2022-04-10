#include <iostream>
#include <cmath>

using namespace std;
int solution(int n, int a, int b)
{
    int answer = 0;
    while (a != b) {
        a = a % 2 == 0 ? a : a + 1;
        b = b % 2 == 0 ? b : b + 1;

        a = a / 2 == 0 ? 1 : a / 2;
        b = b / 2 == 0 ? 1 : b / 2;
        answer++;
    }
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/12985#