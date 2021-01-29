#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
using namespace std;

int C, N, D, P, T;
int adjacentMatrix[50][50];
int connectedTowns[50];
double cache[101][51];

vector<double> getPossibility(int day, vector<double> initial_state) {
    if(day == 0) {
        for(int i = 0; i < N; ++i) {
            cache[0][i] = initial_state[i];
        }
        return initial_state;
    }
    vector<double> result {};
    vector<double> previousPossibility = getPossibility(day - 1, initial_state);
    for(int i = 0; i < N; ++i) {
        double& ret = cache[day][i];
        for(int j = 0; j < N; ++j) {
            ret += (double) adjacentMatrix[i][j] / connectedTowns[j] * previousPossibility[j];
        }
        result.push_back(ret);
    }
    return result;
}

int main(void) {
    cin >> C;
    while(C--) {
        cin >> N >> D >> P;
        memset(adjacentMatrix, 0, sizeof(adjacentMatrix));
        memset(connectedTowns, 0, sizeof(connectedTowns));
        memset(cache, 0, sizeof(cache));
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                int connected;
                cin >> connected;
                adjacentMatrix[i][j] = connected;
                connectedTowns[i] += adjacentMatrix[i][j];
            }
        }
        cin >> T;
        vector<int> townToCalculate {};
        while(T--) {
            int num_town;
            cin >> num_town;
            townToCalculate.push_back(num_town);
        }

        vector<double> initial_state(N, 0);
        initial_state[P] = 1;

        vector<double> result = getPossibility(D, initial_state);
        for(int i = 0; i < townToCalculate.size(); ++i) {
            cout << fixed << setprecision(8) << result[townToCalculate[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}