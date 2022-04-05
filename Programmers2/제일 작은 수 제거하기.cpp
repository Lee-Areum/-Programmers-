#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() == 1) return { -1 };
    auto index = min_element(arr.begin(), arr.end());
    arr.erase(index);
    return arr;
}

//https://programmers.co.kr/learn/courses/30/lessons/12935