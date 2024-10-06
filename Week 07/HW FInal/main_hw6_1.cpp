/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw6_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw6_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw6_1.cpp
 * Abstract: Collect maximum number of coins on an n x m board. Only move right
 * or down. Using the backtrack method to find path. 
 * Name: Michael Cervantes
 * Date: 2/20/2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

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
      } else if (i > 0) {
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

    // 'board[...] > board[...]' or 'board[...] >= board[...]'. >= gives the
    // correct path
    if (j > 0 && (i == 0 || board[i][j - 1] >= board[i - 1][j]))
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

  for (size_t i = 0; i < path.size(); ++i) {
    const auto &p = path[i];
    cout << "(" << p.first + 1 << "," << p.second + 1 << ")"
         << ((i != path.size() - 1) ? "->" : "");
  }
  cout << endl;

  return 0;
}
