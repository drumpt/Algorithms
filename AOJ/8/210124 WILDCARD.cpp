#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int C;
int N;
int cache[101][101];

bool comp(const string& s1, const string& s2) {
    return s1 < s2;
}

bool matchable(string& wildcard, string& file, int w, int f) { // w : wildcard start index, f : file start index
    int& ret = cache[w][f];
    if (ret != -1) return ret;

    if (w >= wildcard.size() && f >= file.size()) return ret = 1;
    if (w == wildcard.size() - 1) {
        if (wildcard[w] == '*') return ret = 1;
        if (wildcard[w] == '?' && f == file.size() - 1) return ret = 1;
        if (f == file.size() - 1) return ret = wildcard[w] == file[f];
        return ret = 0;
    }
    int result = 0;
    if (wildcard[w] == '*') {
        for (int i = f; i < file.size(); ++i) {
            result = result || matchable(wildcard, file, w + 1, i);
        }
    }
    else if (wildcard[w] == '?') {
        if (f < file.size() - 1) result = matchable(wildcard, file, w + 1, f + 1);
        else result = 0;
    }
    else { // normal character
        if (f < file.size() - 1) result = wildcard[w] == file[f] && matchable(wildcard, file, w + 1, f + 1);
        else result = 0;
    }
    return ret = result;
}

int main(void) {
    cin >> C;
    while (C--) {
        string wildcard;
        vector<string> files, resultFiles;
        cin >> wildcard >> N;
        while (N--) {
            string file;
            cin >> file;
            files.push_back(file);
        }
        for (int i = 0; i < files.size(); ++i) {
            memset(cache, -1, sizeof(cache));
            if (matchable(wildcard, files[i], 0, 0)) resultFiles.push_back(files[i]);
        }
        sort(resultFiles.begin(), resultFiles.end(), comp);
        for (int i = 0; i < resultFiles.size(); ++i) {
            cout << resultFiles[i] << endl;
        }
    }
    return 0;
}