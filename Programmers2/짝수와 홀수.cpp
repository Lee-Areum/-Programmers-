#include <string>
#include <vector>

using namespace std;

string solution(int num) {
	string answer = (num % 2 == 0) ? "Even" : "Odd";
	return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/12937