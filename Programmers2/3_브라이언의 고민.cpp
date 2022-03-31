#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> strs; //각 단어 저장
vector<pair<bool, bool>> isRulsDone; //사용한 규칙 저장
vector<string> strDone; //정상적인 단어 저장
unordered_map<char, int> mSpacial; //사용한 특수문자 저장
int num;

bool checkRull() {
    for (int i = 0; i < strs.size(); i++) {
        char rule; string tmp;
        string str = strs[i];
        int index = str.size() - 1;
        if (str == "") continue; //적용 완료된 문장
        if (str.size() > 1 && str[1] >= 'a' && str[1] <= 'z') { //규칙1
            rule = str[1];
            if (str.size() < 3) return true;
            if (mSpacial[rule] > 0 || isRulsDone[i].first) return true;
            mSpacial[rule]++;
            isRulsDone[i].first = true;
            for (int k = 0; k < str.size(); k++) {
                if (str[k] == ' ') return true;
                if (k % 2 == 1) {
                    if (str[k] != rule) { //특수문자 확인
                        index = k;
                        break;
                    }
                }
                else {
                    tmp += str[k];
                }
            }
            strs[i] = tmp;
            cout << "1 tmp :" << tmp << endl;
        }
        else if (str[0] >= 'a' && str[0] <= 'z') { //규칙2
            rule = str[0];
            if (str.size() < 3) return true;
            if (mSpacial[rule] > 0 || isRulsDone[i].second) return true;
            mSpacial[rule]++;
            isRulsDone[i].second = true;
            for (int k = 1; k < str.size(); k++) {
                if (str[k] == rule) {
                    index = k + 1;
                    break;
                }
                else {
                    if (str[k] == ' ') return true;
                    tmp += str[k];
                }
            }
            strs[i] = tmp;
            cout << "tmp : " << tmp << endl;
        }
        else {
            for (int k = 0; k < str.size(); k++) {
                if ((str[k] >= 'a' && str[k] <= 'z') || str[k] == ' ')
                    return true;
            }
            strDone[i] = str;
            strs[i].clear();
            num++;
        }
        if (index < str.size() - 1) {
            string input = str.substr(index);
            strs.push_back(input);
            isRulsDone.push_back({ false,false });
        }
    }
    return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    strs = vector<string>(0);
    isRulsDone = vector<pair<bool, bool>>(0);
    strDone = vector<string>(sentence.size());
    mSpacial = unordered_map<char, int>(0);
    num = 0;
    strs.push_back(sentence);
    isRulsDone.push_back({ false,false });
    while (num < strs.size()) {
        if (checkRull()) return "invalid";
    }
    answer += strDone[0];
    for (int i = 1; !strDone[i].empty(); i++) {
        answer += " ";
        answer += strDone[i];
    }
    return answer;
}