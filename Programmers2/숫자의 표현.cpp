#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 1; //nÀÏ °æ¿ì
	int num = 0, k = 1;
	for (int i = 1; i < n; i++) {
		num += i;
		while (num > n) {
			num -= k++;
		}
		if (num == n) {
			answer++;
			num -= k++;
		}
	}
	return answer;
}