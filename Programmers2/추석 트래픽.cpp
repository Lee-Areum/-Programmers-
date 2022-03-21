#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;
int times[3000][2] = { 0 };
int biggest = 1;

void checkTimes(int size) {
    for(int i = 0 ;i<size;i++){
        int count = 0;
        cout << times[i][1] << " ~ " << times[i][1] + 999 << endl;
        for (int k = 0; k < size; k++) {
            int start = times[k][0];
            int end = times[k][1];
            if ((times[i][1] <= start && start<= times[i][1] + 999)
                || times[i][1] <= end && end <=times[i][1] + 999 || start <= times[i][1] && end >= times[i][1]+999) {
                //cout << "count | "<<k<<" " << times[k][0] << " ~ " << times[k][1] << endl;
                count++;
            }
        }
        cout << "i : " << i << " | " << count << endl;
        biggest = biggest < count ? count : biggest;
    }
}

int solution(vector<string> lines) {
    for (int i = 0; i < lines.size(); i++) {
        string tmp;
        int time[4] = { 0 };
        istringstream ss(lines[i]);
        getline(ss, tmp, ' ');
        for (int k = 0; getline(ss, tmp, ':'); k++) {
            time[k] = stof(tmp) * 10000 / 10;
        }
        tmp = tmp.substr(7);
        tmp.erase(tmp.size() - 1, 1);
        time[3] = stof(tmp)*1000;
        cout << "times : " << time[0] << " " << time[1] << " " << time[2] << endl;
        times[i][1] = time[0] * 3600 + time[1] * 60 + time[2];
        times[i][0] = (times[i][1] - time[3]) + 1;
    }
    for (int i = 0; i < lines.size(); i++) {
        cout <<" i : "<<i <<" | "<< times[i][0] << " ~ " << times[i][1]<<endl;
    }

    checkTimes(lines.size());

    return biggest;
}