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
 * Abstract: using DFS algorithm to search 
 * Name: Michael Cervantes
 * Date: 1/23/2024
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int vertex, vector<int>& mark) {
    stack<int> dfsStack;
    dfsStack.push(vertex);
    int count = 1;

    while (!dfsStack.empty()) {
        int currentVertex = dfsStack.top();
        dfsStack.pop();

        if (!visited[currentVertex]) {
            visited[currentVertex] = true;
            mark[currentVertex] = count++;

            // Push neighbors in reverse order to prioritize exploration
            for (int i = graph[currentVertex].size() - 1; i >= 0; --i) {
                int neighbor = graph[currentVertex][i];
                if (!visited[neighbor]) {
                    dfsStack.push(neighbor);
                }
            }
        }
    }
}

int main() {
    int numVertices, numEdges;

    cin >> numVertices;
    cin >> numEdges;

    vector<vector<int>> graph(numVertices);
    vector<bool> visited(numVertices, false);
    vector<int> mark(numVertices, 0);

    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph[src].push_back(dest);
        // No need to add the reverse edge for a directed graph
    }

    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            dfs(graph, visited, i, mark);
        }
    }

    // Display the result
    for (int i = 0; i < numVertices; ++i) {
        cout << "Mark[" << i << "]:" << mark[i] << endl;
    }

    return 0;
}
