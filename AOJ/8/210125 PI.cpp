#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int C;
int cache[10000];
int MAXNUM = 40000;
string s;

int sameDifficulty(int start, int end) { // [start, end)
    int result = 1;
    for(int i = start + 1; i < end; ++i) {
        if(s[start] != s[i]) result = MAXNUM;
    }
    return result;
}

int differenceByOneDifficulty(int start, int end) {
    int result = 2;
    int difference = (int) s[start + 1] - (int) s[start];
    if(difference != 1 && difference != -1) return result = MAXNUM;
    for(int i = start + 2; i < end; ++i) {
        if(s[i] - s[i - 1] != difference) result = MAXNUM;
    }
    return result;
}

int alternatingDifficulty(int start, int end) {
    int result = 4;
    for(int i = start; i < end - 2; i = i + 2) {
        if(s[i] != s[i + 2]) result = MAXNUM;
    }
    for(int i = start + 1; i < end - 2; i = i + 2) {
        if(s[i] != s[i + 2]) result = MAXNUM;
    }
    return result;
}

int arithmeticSequenceDifficulty(int start, int end) {
    int result = 5;
    int difference = (int) s[start + 1] - (int) s[start];
    for(int i = start + 2; i < end; ++i) {
        if(s[i] - s[i - 1] != difference) result = MAXNUM;
    }
    return result;
}

int minDifficulty(int start) {
    if(start > s.size() - 1) return 0;
    int& ret = cache[start];
    if(ret != -1) return ret;
    if(start > s.size() - 3) return ret = MAXNUM;
    ret = MAXNUM;
    for(int i = 3; i <= 5; ++i) {
        int frontDifficulty = min({sameDifficulty(start, start + i), differenceByOneDifficulty(start, start + i), alternatingDifficulty(start, start + i), arithmeticSequenceDifficulty(start, start + i), 10});
        ret = min(ret, frontDifficulty + minDifficulty(start + i));
    }
    return ret;
}

int main(void){
    cin >> C;
    while(C--) {
        memset(cache, -1, sizeof(cache));
        cin >> s;
        cout << minDifficulty(0) << endl;
    }
    return 0;
}