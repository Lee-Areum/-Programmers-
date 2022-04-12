#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = skill_trees.size();
	for (string str : skill_trees) {
		auto index = find(str.begin(), str.end(), skill[0]);
		for (int i = 1; i < skill.size(); i++) {
			auto index_next = find(str.begin(), str.end(), skill[i]);
			if (index > index_next) {
				answer--;
				break;
			}
			index = index_next;
		}
	}
	return answer;
}