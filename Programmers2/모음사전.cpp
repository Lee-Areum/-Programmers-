#include <string>
#include <vector>
#include <map>

using namespace std;
// 781°³
vector<int> can = { 781,156,31,6,1 };
map <char, int> alpha = { {'A',0},{'E',1},{'I',2},{'O',3},{'U',4} };
int solution(string word) {
	int answer = 0;
	for (int i = 0; i < word.size(); i++) {
		int mul = alpha[word[i]];
		answer += can[i] * mul + 1;
	}
	return answer;
}
