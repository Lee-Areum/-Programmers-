//밀러-라빈 소수 탐색 https://man-25-1.tistory.com/99
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

long long modpow(long long a, long long e, long long m) {
	int r = 1, b = a % m;
	while (e > 0) {
		if (e & 1)
			r = r * b % m;
		b = b * b % m;
		e >>= 1;
	}
	return r;
}

bool Miller_Rabin(int n, int b, int s, int t) { //n은 홀수 ,b: base, n -1 = 2^s*t
	int x = modpow(b,s,n); // b0 = b^t mod n
	if (x == 1 || x == n - 1) {//b0가 +-1이면
		return false; //소수 이다.
	}
	for (int i = 1; i < s; i++) {
		x = (int)x*x % n; //x^2 mod n
		if (x == n - 1) {
			return false;
		}
	}
	return true;
}

bool is_prime(int n) {
	if (n < 2) return false;
	int s = 0;
	int t = n - 1;
	while (t & 1 == 0) {//짝수인 경우만
		t >>= 1; //나누기 2
		s = s + 1;
	}
	for (int b : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == b) return true;
		if (Miller_Rabin(n, b, t, s))
			return false;
	}
	return true;
}

int solution(int n) {
	int answer = 0;
	for (int i = 2; i <= n; i++) {
		if (is_prime(i)) {
			answer++;
			cout << i << " ";
		}
	}
	return answer;
}