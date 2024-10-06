#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void topologicalSort(int vertices, const std::vector<std::pair<int, int>>& edges) {
    std::vector<int> inDegree(vertices, 0);
    std::vector<std::vector<int>> adjacencyList(vertices);

    for (const auto& edge : edges) {
        int from = edge.first;
        int to = edge.second;

        adjacencyList[from].push_back(to);
        inDegree[to]++;
    }

    std::queue<int> q;
    int visitedVertices = 0;

    for (int i = 0; i < vertices; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 0; i < vertices; ++i) {
        std::cout << "In-degree[" << i << "]:" << inDegree[i] << std::endl;
    }

    //std::cout << "Order:";
    string strBuilder = "";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        //std::cout << u;
        strBuilder += to_string(u);
        visitedVertices++;

        for (int v : adjacencyList[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }

        if (!q.empty()) {
            //std::cout << "->";
            strBuilder += "->";
        }

    }

    bool isDag = visitedVertices == vertices;

    if(isDag){
        cout << "Order:" << strBuilder;
    }else {
        cout << "No Order:";
    }

    std::cout << std::endl;
}

int main() {
    int vertices, edgesCount;
    
    //First Input
    std::cin >> vertices;
    // Second input
    std::cin >> edgesCount;

    std::vector<std::pair<int, int>> edges;

    // Graph info.
    for (int i = 0; i < edgesCount; ++i) {
        int from, to;
        std::cin >> from >> to;
        edges.emplace_back(from, to);
    }

    topologicalSort(vertices, edges);

    return 0;
}
