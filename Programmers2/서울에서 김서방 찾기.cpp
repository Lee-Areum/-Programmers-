//https://programmers.co.kr/learn/courses/30/lessons/12919
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "�輭���� ";
    int index = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    answer += to_string(index) + "�� �ִ�";
    return answer;
}