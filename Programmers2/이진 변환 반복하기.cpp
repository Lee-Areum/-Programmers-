#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer = { 0,0 };
    while (s != "1") {
        //0제거
        sort(s.begin(), s.end());
        int index = find(s.begin(), s.end(), '1') - s.begin();
        answer[1] += index;
        s = s.substr(index);
        //2진법
        int n = s.size();
        s = "";
        while (n) {
            s = to_string(n % 2) + s;
            n /= 2;
        }
        answer[0]++;
    }
    return answer;
}