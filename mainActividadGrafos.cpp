#include "grafos.cpp"
#include <fstream>
#include <stdexcept>

int main() {
    try {
        int n;
        cin >> n;
        Graph graph(n);

        // Leer vértices
        for (int i = 0; i < n; ++i) {
            string vertex;
            cin >> vertex;
            graph.insertVtrx(vertex, i);
        }

        // Leer número de aristas
        int m;
        cin >> m;

        // Leer aristas originales
        for (int i = 0; i < m; ++i) {
            string from, to;
            float weight;
            cin >> from >> to >> weight;
            int fromIdx = graph.search(from);
            int toIdx = graph.search(to);
            if (fromIdx != -1 && toIdx != -1) {
                graph.insertArc(weight, fromIdx, toIdx);
            }
        }

        // Leer número de consultas iniciales
        int q1;
        cin >> q1;

        // Almacenar consultas
        string startQueries[MAX], endQueries[MAX];

        // Consultas iniciales
        graph.doFloyd();
        for (int i = 0; i < q1; ++i) {
            string start, end;
            cin >> start >> end;
            startQueries[i] = start;
            endQueries[i] = end;
            graph.printPath(start, end);
        }

        // Leer prioridades
        string prioridadesStr;
        cin >> prioridadesStr;

        int p;
        cin >> p;
        float totalPriorityTime = 0;
        for (int i = 0; i < p; ++i) {
            string from, to;
            int priority;
            cin >> from >> to >> priority;
            int fromIdx = graph.search(from);
            int toIdx = graph.search(to);
            if (fromIdx != -1 && toIdx != -1) {
                graph.setPriority(fromIdx, toIdx, priority);
                // Usar peso de la arista original para tiempo total
                float edgeWeight = graph.edges[fromIdx][toIdx];
                if (edgeWeight != INF) {
                    totalPriorityTime += edgeWeight;
                }
            }
        }

        // Generar red priorizada
        graph.generatePriorityNetwork();
        graph.doFloyd();

        // Imprimir tiempo total de carreteras priorizadas
        cout << fixed << setprecision(1) << totalPriorityTime << "\n";

        // Consultas en red priorizada
        for (int i = 0; i < q1; ++i) {
            graph.printPath(startQueries[i], endQueries[i]);
        }

        return 0;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}