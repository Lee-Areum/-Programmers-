//https://programmers.co.kr/learn/courses/30/lessons/12915
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int index = 0;

bool index_sort(string str1, string str2) {
    if (str1[index] == str2[index]) {
        return str1 < str2;
    }
    return str1[index] < str2[index];
}

vector<string> solution(vector<string> strings, int n) {
    index = n;
    sort(strings.begin(), strings.end(), index_sort);
    return strings;
}