#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "",tmp;
    stringstream ss(s);
    vector<int> list;
    while (getline(ss, tmp, ' ')) {
        list.push_back(stoi(tmp));
    }
    sort(list.begin(), list.end());
    answer = to_string(list[0]) + " " + to_string(list[list.size() - 1]);
    return answer;
}