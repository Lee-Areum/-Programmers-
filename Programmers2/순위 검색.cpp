#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;
vector<vector<string>> check = {
	{"cpp","java","python"},
	{"backend","frontend"},
	{"junior","senior"},
	{"chicken","pizza"}
};

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	unordered_map<string, vector<int>> m;
	for (int k = 0; k < info.size(); k++) {
		vector<string> list = { "" };
		istringstream ss(info[k]);
		string s[4];
		int score;
		for (int i = 0; i < 4; i++) {
			vector<string> input;
			ss >> s[0] >> s[1] >> s[2] >> s[3] >> score;
			for (int t = 0; t < list.size();t++) {
				input.push_back(list[t] + s[i]);
				input.push_back(list[t] + "-");
			}
			list.assign(input.begin(), input.end());
		}
		for (string str : list) {
			m[str].push_back(score);
		}
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		sort(it->second.begin(), it->second.end());
	}
	for (string q : query) {
		stringstream ss(q);
		string s[4];
		int score;
		string str = "";
		ss >> s[0]>> str >> s[1] >> str >> s[2] >> str >> s[3] >> score;
		str = s[0];
		for (int k = 1; k < 4; k++) {
			str += s[k];
		}
		vector<int> v = m[str];
		if (v.size() != 0) {
			auto it = lower_bound(v.begin(), v.end(), score);
			answer.push_back(v.size() - (it - v.begin()));
		}
		else answer.push_back(0);
	}
	return answer;
}