#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	for (long long num : numbers) {
		long long n = num;
		long long one;
		one = -1;
		for (int i = 0; n > 0; i++) {
			if (n % 2 == 1) {
				one = i;
			}
			else {
				break;
			}
			n /= 2;
		}
		long long result = num + (powl(2, one) < 1 ? 1 : powl(2, one));
		answer.push_back(result);
	}
	return answer;
}