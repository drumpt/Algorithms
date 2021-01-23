#include <iostream>
#include <vector>
using namespace std;

int C;
vector<vector<int>> switches = {
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};

bool isFinished(vector<int>& s) {
    for (int i = 0; i < 16; ++i) {
        if (s[i] != 12) return false;
    }
    return true;
}

int minSwitches(vector<int>& s, int currentSwitch) {
    if (isFinished(s)) return 0;
    if (currentSwitch > 9) return 99999;
    int result = 99999;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < switches[currentSwitch].size(); ++j) {
            s[switches[currentSwitch][j]] = (s[switches[currentSwitch][j]] + 3 * i) % 12 == 0 ? 12 : (s[switches[currentSwitch][j]] + 3 * i) % 12;
        }
        int numPush = i + minSwitches(s, currentSwitch + 1);
        result = min(result, numPush);
        for (int j = 0; j < switches[currentSwitch].size(); ++j) {
            s[switches[currentSwitch][j]] = (s[switches[currentSwitch][j]] - 3 * i) % 12 == 0 ? 12 : (s[switches[currentSwitch][j]] - 3 * i) % 12;
        }
    }
    return result;
}

int main(void) {
    cin >> C;
    for (int i = 0; i < C; ++i) {
        vector<int> time;
        for (int j = 0; j < 16; ++j) {
            int x;
            cin >> x;
            time.push_back(x);
        }
        cout << (minSwitches(time, 0) >= 9999 ? -1 : minSwitches(time, 0)) << endl;
    }
    return 0;
}