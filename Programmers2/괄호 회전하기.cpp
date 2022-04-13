#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool check_right(string str) { //올바른 괄호인지 확인
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		switch (str[i]) {
		case '(':case'[':case'{':
			s.push(str[i]);
			break;
		case ')':
			if (s.empty() || s.top() != '(')
				return false;
			else s.pop();
			break;
		case ']':
			if (s.empty() || s.top() != '[')
				return false;
			else s.pop();
			break;
		case '}':
			if (s.empty() || s.top() != '{')
				return false;
			else s.pop();
			break;
		default:
			break;
		}
	}
	return true;
}

int solution(string s) {
	int answer = 0;
	int size = s.size();
	s += s;
	if (size % 2 == 1) return 0;
	for (int i = 0; i < size; i++) {
		string tmp = s.substr(i, size);
		if (check_right(tmp)) {
			answer++;
		}
	}
	return answer;
}