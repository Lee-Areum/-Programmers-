#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

long long solution(int w, int h) {
    long long answer = (long long)w*(long long)h;
    int min_n = gcd(max(w, h), min(w, h));
    answer -= (w + h - min_n);
    return answer;
}