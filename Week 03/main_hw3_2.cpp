/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw3_3.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_3.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw3_3.cpp
 * Abstract: Depth First solving Travel salesman Problem. 
 * Name: Michael Cervantes 
 * Date: 01/23/2024
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>   // dont need this?
#include <numeric>
#include <vector>
#include <climits>

using namespace std;

const int MAX_VERTICES = 15;

int minimumCost = INT_MAX;
vector<int> minPath;

void generatePaths(vector<vector<int>> &graph, vector<int> &vertices,
                   vector<int> &path, int currentCost, int currentVertex) {
  if (path.size() == graph.size()) {
    // Check if a complete path exists back to the starting vertex
    if (graph[currentVertex][path[0]] != INT_MAX) {
      int totalCost = currentCost + graph[currentVertex][path[0]];
      if (totalCost < minimumCost) {
        minimumCost = totalCost;
        minPath = path;
        minPath.push_back(path[0]); // Add starting vertex to complete the cycle
      }
    }
    return;
  }

  for (int i = 0; i < vertices.size(); ++i) {
    int nextVertex = vertices[i];
    if (graph[currentVertex][nextVertex] != INT_MAX &&
        find(path.begin(), path.end(), nextVertex) == path.end()) {
      path.push_back(nextVertex);
      generatePaths(graph, vertices, path,
                    currentCost + graph[currentVertex][nextVertex], nextVertex);
      path.pop_back();
    }
  }
}

int main() {
  int numVertices, numEdges, startVertex;

  cin >> numVertices;
  cin >> numEdges;

  vector<vector<int>> graph(numVertices, vector<int>(numVertices, INT_MAX));

  for (int i = 0; i < numEdges; ++i) {
    int src, dest, weight;
    cin >> src >> dest >> weight;
    graph[src][dest] = weight;
  }

  cin >> startVertex;

  vector<int> vertices(numVertices);
  iota(vertices.begin(), vertices.end(), 0);
  vertices.erase(remove(vertices.begin(), vertices.end(), startVertex),
                 vertices.end()); // Remove starting vertex

  vector<int> path = {startVertex};

  generatePaths(graph, vertices, path, 0, startVertex);

  if (minPath.empty()) {
    cout << "Path:" << endl;
    cout << "Cost:-1" << endl;
  } else {
    cout << "Path:";
    for (int i = 0; i < minPath.size(); ++i) {
      cout << minPath[i];
      if (i < minPath.size() - 1) {
        cout << "->";
      }
    }
    cout << endl;
    cout << "Cost:" << minimumCost << endl;
  }

  return 0;
}