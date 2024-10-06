/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw4_3.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_3.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw4_3.cpp
 * Abstract: conducts the topological sorting based on the Kahn algorithm
 * Name: Michael Cervantes
 * Date: 02/06/2024
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void topologicalSort(int vertices, const vector<pair<int, int>> &edges) {
  vector<int> inDegree(vertices, 0);
  vector<vector<int>> adjacencyList(vertices);

  for (const auto &edge : edges) {
    int from = edge.first;
    int to = edge.second;

    adjacencyList[from].push_back(to);
    inDegree[to]++;
  }

  queue<int> q;
  int visitedVertices = 0;

  for (int i = 0; i < vertices; ++i) {
    if (inDegree[i] == 0) {
      q.push(i);
    }
  }

  for (int i = 0; i < vertices; ++i) {
    cout << "In-degree[" << i << "]:" << inDegree[i] << endl;
  }

  // std::cout << "Order:";
  string strBuilder = "";

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    // std::cout << u;
    strBuilder += to_string(u);
    visitedVertices++;

    for (int v : adjacencyList[u]) {
      inDegree[v]--;
      if (inDegree[v] == 0) {
        q.push(v);
      }
    }

    if (!q.empty()) {
      strBuilder += "->";
    }
  }

  bool isDag = visitedVertices == vertices;

  if (isDag) {
    cout << "Order:" << strBuilder;
  } else {
    cout << "No Order:";
  }

  cout << endl;
}

int main() {
  int vertices, edgesCount;

  // First Input
  cin >> vertices;
  // Second input
  cin >> edgesCount;

  vector<pair<int, int>> edges;

  // Graph info.
  for (int i = 0; i < edgesCount; ++i) {
    int from, to;
    cin >> from >> to;
    edges.emplace_back(from, to);
  }

  topologicalSort(vertices, edges);

  return 0;
}

