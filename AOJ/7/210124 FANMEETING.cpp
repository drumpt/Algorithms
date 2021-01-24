#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int C;
string members;
string fans;

void addTo(vector<int>& a, vector<int>& b, int k) { // a + b * 10^k
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); ++i) {
        a[i + k] += b[i];
    }
}

void subFrom(vector<int>& a, vector<int>& b) { // a - b 
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); ++i) {
        a[i] -= b[i];
    }
}

vector<int> multiply(vector<int>&a, vector<int>& b) {
    vector<int> result(a.size() + b.size() - 1, 0);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            result[i + j] += a[i] * b[j];
        }
    }
    return result;
}

vector<int> karatsuba(vector<int>& a, vector<int>& b) { // a.size() >= b.size()
    if (b.size() > a.size()) return karatsuba(b, a);
    if (a.size() == 0 || b.size() == 0) return vector<int> {};
    if (a.size() <= 50) return multiply(a, b);
    else { // a * b = a0 * b0 + a1 * b1 * 
        int middle = a.size() / 2;
        vector<int> result {};

        vector<int> a0 {a.begin(), a.begin() + middle};
        vector<int> a1 {a.begin() + middle, a.end()};
        vector<int> b0 {b.begin(), b.begin() + min((int) b.size(), middle)};
        vector<int> b1 {b.begin() + min((int) b.size(), middle), b.end()};

        vector<int> z0 = karatsuba(a0, b0);
        vector<int> z1 = karatsuba(a1, b1);

        addTo(result, z0, 0);
        addTo(result, z1, 2 * middle);

        addTo(a0, a1, 0); // a0 = a0 + a1
        addTo(b0, b1, 0); // b0 = b0 + b1


        vector<int> z2 = karatsuba(a0, b0); // z2 = (a0 + a1) * (b0 + b1)
        addTo(z1, z0, 0);
        subFrom(z2, z1); // z2 = a0 * b1 + a1 * b0

        addTo(result, z2, middle);
        return result;
    }
}

int getAllHugs(string& members, string& fans) {
    vector<int> numMembers, numFans;
    for (int i = 0; i < members.size(); ++i) {
        numMembers.push_back(members[i] == 'M');
    }
    for (int i = 0; i < fans.size(); ++i) {
        numFans.push_back(fans[i] == 'M');
    }
    reverse(numFans.begin(), numFans.end());
    vector<int> hugsAtSpecificTime = karatsuba(numMembers, numFans);
    int result = 0;
    for (int i = numMembers.size() - 1; i < numFans.size(); ++i) {
        result += hugsAtSpecificTime[i] == 0;
    }
    return result;
}

int main(void) {
    cin >> C;
    while (C--) {
        cin >> members >> fans;
        cout << getAllHugs(members, fans) << endl;
    }
}