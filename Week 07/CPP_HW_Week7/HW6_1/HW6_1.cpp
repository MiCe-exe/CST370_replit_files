#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 25;
const int MAX_M = 25;

int main() {
    int n, m;
    cin >> n >> m;

    // Get Input
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    // Perform the dynamic programming step
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) {
                board[i][j] += max(board[i][j - 1], (i > 0) ? board[i - 1][j] : 0);
            }
            else if (i > 0) {
                board[i][j] += board[i - 1][j];
            }
        }
    }

    // Backtrack to find the path
    int maxCoins = board[n - 1][m - 1];
    vector<pair<int, int>> path;
    int i = n - 1, j = m - 1;

    while (i > 0 || j > 0) {
        path.emplace_back(i, j);

        if (j > 0 && (i == 0 || board[i][j - 1] >= board[i - 1][j]))        // board[...] > board[...] or board[...] >= board[...]. >= gives the correct path
            --j;
        else
            --i;
    }

    path.emplace_back(0, 0);

    // Correct order of the path.
    reverse(path.begin(), path.end());

    // Output the result
    cout << "Max coins:" << maxCoins << endl;
    cout << "Path:";
    //for (const auto& p : path)
    //    cout << "(" << p.first + 1 << "," << p.second + 1 << ")" << ((p != path.back()) ? "->" : "");
    //cout << endl;
    for (size_t i = 0; i < path.size(); ++i) {
        const auto& p = path[i];
        cout << "(" << p.first + 1 << "," << p.second + 1 << ")" << ((i != path.size() - 1) ? "->" : "");
    }
    cout << endl;


    return 0;
}
