#include <iostream>
#include <vector>
using namespace std;

int C, N;

int getMaxRectangle(vector<int>& v) {
    if (v.size() == 1) return v[0];
    int middle = v.size() / 2;
    vector<int> left {v.begin(), v.begin() + middle};
    vector<int> right {v.begin() + middle, v.end()};

    int result = 0;
    int leftMax = getMaxRectangle(left);
    int rightMax = getMaxRectangle(right);

    result = max(leftMax, rightMax);

    int low = middle -1;
    int high = middle;
    int height = min(v[low], v[high]);
    int centerMax = height * (high - low + 1);

    while (low > 0 || high < v.size() - 1) {
        if (high < v.size() - 1 && (low == 0 || v[high + 1] >= v[low - 1])) {
            high++;
            height = min(height, v[high]);
        }
        else {
            low--;
            height = min(height, v[low]);
        }
        centerMax = max(centerMax, height * (high - low + 1));
    }
    result = max(result, centerMax);
    return result;
}

int main(void) {
    cin >> C;
    while (C--) {
        cin >> N;
        vector<int> fenceHeights;
        for (int i = 0; i < N; ++i) {
            int h;
            cin >> h;
            fenceHeights.push_back(h);
        }
        cout << getMaxRectangle(fenceHeights) << endl;
    }
    return 0;
}