#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long double loot = sqrt(n);
    if (loot != (int)loot) return -1;
    answer = (loot + 1) * (loot + 1);
    return answer;
}
//powÇÔ¼ö
//https://programmers.co.kr/learn/courses/30/lessons/12934