#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0,0 };
    unordered_set<string> sets;
    sets.insert(words[0]);
    for (int i = 1; i < words.size(); i++) {
        if (sets.find(words[i]) != sets.end()) {
            answer[0] = ((i % n) + 1);
            answer[1] = (i / n + 1);
            return answer;
        }
        else if (words[i - 1][words[i - 1].size() - 1] != words[i][0]) {
            answer[0] = ((i % n) + 1);
            answer[1] = (i / n + 1);
            return answer;
        }
        sets.insert(words[i]);
    }
    return answer;
}


//https://programmers.co.kr/learn/courses/30/lessons/12981