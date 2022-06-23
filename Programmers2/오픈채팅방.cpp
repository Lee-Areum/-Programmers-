#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer; //정답
    vector<pair<bool, string>> result; //결과로 찍을 순서
    unordered_map<string, string> users; //id와 닉네임을 넣는 map
    for (string r : record) { //마지막 닉네임을 알아내기 위해
        string command, uid, unick;
        istringstream ss(r);
        ss >> command >> uid >> unick;
        if (!command.compare("Enter")) { //입장
            users[uid] = unick;
            result.push_back({ true,uid });
        }
        else if (!command.compare("Leave")) { //퇴장
            result.push_back({ false,uid });
        }
        else { //변경
            users[uid] = unick;
        }
    }
    for (auto tmp : result) { //결과를 저장하는 단계
        string nickname = users[tmp.second];
        if (tmp.first) { //입장
            answer.push_back(nickname + "님이 들어왔습니다.");
        }
        else { //퇴장
            answer.push_back(nickname + "님이 나갔습니다.");
        }
    }
    return answer;
}