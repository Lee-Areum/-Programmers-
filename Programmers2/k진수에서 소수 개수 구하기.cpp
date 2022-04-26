#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

bool sosu(long long n) {
    if (n == 1) return false;
    if (n != 2 && n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string numbers = "", tmp;
    while (n) {
        numbers = to_string(n % k) + numbers;
        n /= k;
    }
    stringstream ss(numbers);
    while (getline(ss, tmp, '0')) {
        if (tmp.size() > 0 && sosu(stol(tmp))) answer++;
    }
    return answer;
}