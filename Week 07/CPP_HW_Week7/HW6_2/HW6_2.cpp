#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Floyd algorithm
vector<vector<int>> floyd(const vector<vector<int>>& W) {
    int inputVertices = W.size();
    vector<vector<int>> D = W;

    for (int k = 0; k < inputVertices; ++k) {
        for (int i = 0; i < inputVertices; ++i) {
            for (int j = 0; j < inputVertices; ++j) {
                if (D[i][k] != INF && D[k][j] != INF && D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    return D;
}

int main() {
    int inputVertices;
    cin >> inputVertices;

    // Input graph 
    vector<vector<int>> W(inputVertices, vector<int>(inputVertices));
    for (int i = 0; i < inputVertices; ++i) {
        for (int j = 0; j < inputVertices; ++j) {
            cin >> W[i][j];
            if (W[i][j] == -1) {
                W[i][j] = INF;
            }
        }
    }

    vector<vector<int>> result = floyd(W);

    // Display the result
    for (int i = 0; i < inputVertices; ++i) {
        for (int j = 0; j < inputVertices; ++j) {
            if (result[i][j] == INF && j != inputVertices -1) {
                cout << "-1 ";
            }
            else if(j == inputVertices - 1){
                //cout << result[i][j];
                if (result[i][j] == INF) {
                    cout << "-1";
                }
                else {
                    cout << result[i][j];
                }
            }
            else {
                cout << result[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
