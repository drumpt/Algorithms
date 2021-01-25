#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int c, n, m;
int cache[101][101];
vector<int> v1, v2;

int jlis(int index1, int index2) { // joined longest increasing subsequence starting at index1, index2
    int& ret = cache[index1 + 1][index2 + 1];
    if (ret != -1) return ret;
    ret = 0;
    long long a = index1 == -1 ? NEGINF : v1[index1];
    long long b = index2 == -1 ? NEGINF : v2[index2];
    long long maxElement = max(a, b);
    for(int i = index1 + 1; i < v1.size(); ++i) {
        if(maxElement < v1[i]) {
            ret = max(ret, 1 + jlis(i, index2));
        }
    }
    for(int i = index2 + 1; i < v2.size(); ++i) {
        if(maxElement < v2[i]) {
            ret = max(ret, 1 + jlis(index1, i));
        }
    }
    return ret;
}

int main(void) {
    cin >> c;
    while(c--) {
        memset(cache, -1, sizeof(cache));
        v1 = vector<int> {};
        v2 = vector<int> {};
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            int element;
            cin >> element;
            v1.push_back(element);
        }
        for(int i = 0; i < m; ++i) {
            int element;
            cin >> element;
            v2.push_back(element);
        }
        cout << jlis(-1, -1) << endl;
    }
    return 0;
}