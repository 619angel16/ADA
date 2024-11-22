#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 20;
const float INF = numeric_limits<float>::infinity();

class Graph {
public:
    int n;
    float edges[MAX][MAX];
    float floyd[MAX][MAX];
    string vtrx[MAX];
    int paths[MAX][MAX];
    
    float priorities[MAX][MAX];
    bool isPrioritized[MAX][MAX];

    Graph(int numVtrx = 0) : n(numVtrx) {
        initMat();
    }

    void initMat() {
        for (int i = 0; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                edges[i][j] = (i == j) ? 0 : INF;
                floyd[i][j] = INF;
                paths[i][j] = -1;
                priorities[i][j] = 0;
                isPrioritized[i][j] = false;
            }
        }
    }

    void insertVtrx(const string &name, int pos) {
        if (pos >= 0 && pos < n) {
            vtrx[pos] = name;
        }
    }

    int search(const string &name) const {
        for (int i = 0; i < n; ++i) {
            if (name == vtrx[i]) return i;
        }
        return -1;
    }

    void insertArc(float cost, int from, int to) {
        if (from >= 0 && from < n && to >= 0 && to < n) {
            edges[from][to] = cost;
            edges[to][from] = cost;
        }
    }

    void setPriority(int from, int to, float priority) {
        if (from >= 0 && from < n && to >= 0 && to < n) {
            priorities[from][to] = priority;
            priorities[to][from] = priority;
            isPrioritized[from][to] = true;
            isPrioritized[to][from] = true;
        }
    }

    void generatePriorityNetwork() {
        // Reset edges to INF
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                edges[i][j] = (i == j) ? 0 : INF;
            }
        }

        // Build priority network using Kruskal-like approach
        int group[MAX];
        for (int i = 0; i < n; ++i) group[i] = i;

        auto findGroup = [&](int x) {
            while (group[x] != x) x = group[x];
            return x;
        };

        // Sort and add priority edges
        for (int pass = 0; pass < 2; ++pass) {
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    // First pass: use prioritized edges
                    bool usePrioritized = (pass == 0 && isPrioritized[i][j]);
                    // Second pass: use any remaining edges
                    bool useOtherEdges = (pass == 1 && !isPrioritized[i][j] && edges[i][j] != INF);

                    if ((usePrioritized || useOtherEdges)) {
                        int gi = findGroup(i);
                        int gj = findGroup(j);

                        if (gi != gj) {
                            group[gj] = gi;
                            edges[i][j] = edges[j][i] = (pass == 0) ? 1 : edges[i][j];
                        }
                    }
                }
            }
        }
    }

    void doFloyd() {
        // Initialize floyd matrix with current edges
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                floyd[i][j] = edges[i][j];
                paths[i][j] = (edges[i][j] != INF && i != j) ? j : -1;
            }
        }

        // Floyd-Warshall algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (floyd[i][k] != INF && floyd[k][j] != INF) {
                        float newDist = floyd[i][k] + floyd[k][j];
                        if (newDist < floyd[i][j]) {
                            floyd[i][j] = newDist;
                            paths[i][j] = paths[i][k];
                        }
                    }
                }
            }
        }
    }

    void printPath(const string& start, const string& end) {
        int startIdx = search(start);
        int endIdx = search(end);
        
        if (startIdx == -1 || endIdx == -1 || floyd[startIdx][endIdx] == INF) {
            cout << "No path exists\n";
            return;
        }

        int current = startIdx;
        float totalCost = 0;
        
        while (current != endIdx) {
            cout << vtrx[current] << " ";
            int next = paths[current][endIdx];
            
            if (next == -1) break;
            
            totalCost += (edges[current][next] == INF) ? 1 : edges[current][next];
            current = next;
        }
        
        cout << vtrx[current] << " " << fixed << setprecision(1) << totalCost << "\n";
    }
};