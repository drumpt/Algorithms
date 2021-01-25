#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int C, N, S;
int cache[101][11];
int MAXNUM = 987654321;
vector<int> seq;

int mse(int start, int end, int quantized_num) {
    int result = 0;
    for(int i = start; i < end; ++i) {
        result += (seq[i] - quantized_num) * (seq[i] - quantized_num);
    }
    return result;
}

int mean(int start, int end) {
    int result = 0;
    for(int i = start; i < end; ++i) result += seq[i];
    return round((double) result / (end - start));
}

int quantize(int start, int num_left) {
    if(start == seq.size()) return 0;
    if(num_left == 0) return MAXNUM;
    int& ret = cache[start][num_left];
    if(ret != -1) return ret;
    if(num_left == 1) return ret = mse(start, seq.size(), mean(start, seq.size()));
    ret = MAXNUM;
    for(int i = start + 1; i < seq.size(); ++i) {
        ret = min(ret, mse(start, i, mean(start, i)) + quantize(i, num_left - 1));
    }
    return ret;
}

int main(void) {
    cin >> C;
    while(C--) {
        memset(cache, -1, sizeof(cache));
        seq = vector<int> {};
        cin >> N >> S;
        while(N--) {
            int num;
            cin >> num;
            seq.push_back(num);
        }
        sort(seq.begin(), seq.end());
        cout << quantize(0, S) << endl;
    }
    return 0;
}