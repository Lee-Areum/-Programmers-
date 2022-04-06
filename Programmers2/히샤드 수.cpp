#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    int n = x;
    while (n) {
        sum += (n % 10);
        n /= 10;
    }
    return x % sum == 0 ? true : false;
}

//https://programmers.co.kr/learn/courses/30/lessons/12947