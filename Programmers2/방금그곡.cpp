#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//시작시간, 재생시간, 음악제목
bool compare(vector<string>& n1, vector<string>& n2) {
	if (n1[1].compare(n2[1]) != 0) {
		return stoi(n1[1]) > stoi(n2[1]);
	}
	return stoi(n1[0]) < stoi(n2[0]);
}

int getTime(string& str) {
	stringstream ss(str);
	string tmp;
	int time;
	getline(ss, tmp, ':');
	time = stoi(tmp) * 60;
	getline(ss, tmp, ':');
	time += stoi(tmp);
	return time;
}

string solution(string m, vector<string> musicinfos) {
	vector<vector<string>> corrects; //m과 일치하는 음악
	for (string str : musicinfos) {
		vector<string> token;
		stringstream ss(str);
		string tmp;
		while (getline(ss, tmp, ',')) { //분할
			token.push_back(tmp);
		}
		int start, end, mSize;
		start = getTime(token[0]);
		end = getTime(token[1]);
		mSize = end - start;
		string musics = "";
		for (int k = 0, index = 0; index < mSize; k++, index++) {
			int num = k % token[3].size();
			musics.push_back(token[3][num]);
			if (token[3][num + 1] == '#') {
				musics.push_back(token[3][num + 1]);
				k++;
			}
		}
		token[3] = musics;
		int n = (int)(token[3].size() - m.size());
		for (int i = 0; i <= n; i++) {
			string comp = token[3].substr(i, m.size());
			if ((i != n && token[3][i + m.size()] == '#') || comp[0] == '#') {
				continue;
			}
			if (comp.compare(m) == 0) {
				corrects.push_back({ to_string(start) ,to_string(mSize),token[2] });
				break;
			}
		}
	}
	if (corrects.empty()) {
		return "(None)";
	}
	sort(corrects.begin(), corrects.end(), compare);
	return corrects[0][2];
}