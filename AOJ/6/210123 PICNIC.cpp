#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int C, n, m;
int isFriend[10][10];

int numCases(vector<int> v) { // c : case number
    int firstPeople = -1;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            firstPeople = i;
            break;
        }
    }
    if (firstPeople == -1) return 1;
    int result = 0;
    for (int i = firstPeople + 1; i < v.size(); ++i) {
        if (v[i] == 0 && isFriend[firstPeople][i]) {
            v[firstPeople] = v[i] = 1;
            result += numCases(v);
            v[firstPeople] = v[i] = 0;
        }
    }
    return result;
}

int main(void) {
    cin >> C;
    for (int c = 0; c < C; ++c) {
        memset(isFriend, 0, sizeof(isFriend));
        cin >> n >> m;
        for (int x, y, i = 0; i < m; ++i) {
            cin >> x >> y;
            isFriend[x][y] = isFriend[y][x] = 1;
        }
        vector<int> v(n, 0);
        cout << numCases(v) << endl;
    }
    return 0;
}