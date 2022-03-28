#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> strs; //�� �ܾ� ����
vector<pair<bool, bool>> isRulsDone; //����� ��Ģ ����
vector<string> strDone; //�������� �ܾ� ����
unordered_map<char, int> mSpacial; //����� Ư������ ����
int num;

void initialize() { //�ʱ�ȭ
    strs = vector<string>(0);
    isRulsDone = vector<pair<bool, bool>>(0);
    mSpacial = unordered_map<char, int>(0);
    num = 0;
}

bool checkRull() {
    for (int i = 0; i < strs.size(); i++) {
        char rule; string tmp;
        string str = strs[i];
        int index = str.size() - 1;
        if (str == "") continue; //���� �Ϸ�� ����
        cout << str << " : ";
        if (str.size() > 1 && str[1] >= 'a' && str[1] <= 'z') { //��Ģ1
            rule = str[1];
            cout << "#1 " << rule << endl;
            if (mSpacial[rule] > 0 || isRulsDone[i].first) return true;
            mSpacial[rule]++;
            isRulsDone[i].first = true;
            for (int k = 0; k < str.size(); k++) {
                if (k % 2 == 1) {
                    if (str[k] != rule) { //Ư������ Ȯ��
                        if (str[k] == ' ') return true;
                        index = k;
                        break;
                    }
                }
                else {
                    tmp += str[k];
                }
            }
            cout << "index : " << index << " tmp : " << tmp << endl;
            strs[i] = tmp;
        }
        else if (str[0] >= 'a' && str[0] <= 'z') { //��Ģ2
            rule = str[0];
            cout << "#2 " << rule << endl;
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
            cout << "index : " << index << " tmp : " << tmp << endl;
            strs[i] = tmp;
        }
        else {
            for (int k = 0; k < str.size(); k++) {
                if (str[k] >= 'a' && str[k] <= 'z')
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

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(string sentence) {
    string answer = "";
    initialize();
    strDone = vector<string>(sentence.size());
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