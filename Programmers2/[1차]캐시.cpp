#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    vector<int> indexs;
    vector<string> caches;
    int answer = 0;
    if (cacheSize == 0) return 5 * cities.size();
    for (int i = 0; i < cities.size();i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto index = find(caches.begin(), caches.end(), cities[i]);
        if (index == caches.end()) {
            answer += 5;
            if (indexs.size() < cacheSize) {
                indexs.push_back(i);
                caches.push_back(cities[i]);
            }
            else {
                int m = min_element(indexs.begin(), indexs.end()) - indexs.begin();
                indexs[m] = i;
                caches[m] = cities[i];
            }
        }
        else {
            answer += 1;
            indexs[index - caches.begin()] = i;
        }
    }

    return answer;
}