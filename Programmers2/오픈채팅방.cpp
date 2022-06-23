#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer; //����
    vector<pair<bool, string>> result; //����� ���� ����
    unordered_map<string, string> users; //id�� �г����� �ִ� map
    for (string r : record) { //������ �г����� �˾Ƴ��� ����
        string command, uid, unick;
        istringstream ss(r);
        ss >> command >> uid >> unick;
        if (!command.compare("Enter")) { //����
            users[uid] = unick;
            result.push_back({ true,uid });
        }
        else if (!command.compare("Leave")) { //����
            result.push_back({ false,uid });
        }
        else { //����
            users[uid] = unick;
        }
    }
    for (auto tmp : result) { //����� �����ϴ� �ܰ�
        string nickname = users[tmp.second];
        if (tmp.first) { //����
            answer.push_back(nickname + "���� ���Խ��ϴ�.");
        }
        else { //����
            answer.push_back(nickname + "���� �������ϴ�.");
        }
    }
    return answer;
}