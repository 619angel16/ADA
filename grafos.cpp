#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @brief Constantes globales del grafo
 */
const int MAX = 20;                                  ///< Tamaño máximo de la matriz
const float INF = numeric_limits<float>::infinity(); ///< Valor para representar infinito

/**
 * @brief Clase que representa un grafo mediante matrices de adyacencia
 *
 * Implementa un grafo no dirigido usando matrices de adyacencia y
 * proporciona funcionalidad para el algoritmo de Floyd-Warshall
 */
class Graph
{
public:
    int n;                 ///< Número de vértices
    float edges[MAX][MAX]; ///< Matriz de adyacencia del grafo
    float floyd[MAX][MAX]; ///< Matriz para el algoritmo Floyd-Warshall
    string vtrx[MAX];      ///< Array con los nombres de los vértices

    /**
     * @brief Constructor de la clase Graph
     * @param numVtrx Número de vértices del grafo
     */
    Graph(int numVtrx) : n(numVtrx)
    {
        initMat();
    }

    /**
     * @brief Inicializa las matrices del grafo
     *
     * Establece la diagonal principal a 0 y el resto de elementos a infinito
     */
    void initMat()
    {
        for (int i = 0; i < MAX; ++i)
        {
            for (int j = 0; j < MAX; ++j)
            {
                edges[i][j] = (i == j) ? 0 : INF;
                floyd[i][j] = INF;
            }
        }
    }

    /**
     * @brief Inserta un vértice en el grafo
     * @param avenue Nombre del vértice a insertar
     * @param pos Posición donde insertar el vértice
     * @param graph Referencia al grafo
     * @throws out_of_range Si la posición está fuera de rango
     */
    void insertVtrx(const string &avenue, int pos, Graph &graph)
    {
        if (pos >= 0 && pos < graph.n)
        {
            graph.vtrx[pos] = avenue;
        }
        else
        {
            throw out_of_range("Se ha superado el rango máximo de vértices: " + to_string(pos));
        }
    }

    /**
     * @brief Busca la posición de un vértice en el grafo
     * @param avenue Nombre del vértice a buscar
     * @param graph Referencia constante al grafo
     * @return Posición del vértice o -1 si no se encuentra
     */
    int search(const string &avenue, const Graph &graph)
    {
        for (int i = 0; i < graph.n; ++i)
        {
            if (avenue == graph.vtrx[i])
            {
                return i;
            }
        }
        return -1;
    }

    /**
     * @brief Inserta un arco con coste entre dos vértices
     * @param cost Coste del arco
     * @param fil Índice del vértice origen
     * @param col Índice del vértice destino
     * @param graph Referencia al grafo
     * @throws out_of_range Si los índices están fuera de rango
     */
    void insertArc(float cost, int fil, int col, Graph &graph)
    {
        if (fil >= 0 && fil < graph.n && col >= 0 && col < graph.n)
        {
            graph.edges[fil][col] = cost;
            graph.edges[col][fil] = cost;
        }
        else
        {
            throw out_of_range("El arco se sale de la matriz con fila: " + to_string(fil) + " y columna: " + to_string(col));
        }
    }

    /**
     * @brief Implementa el algoritmo de Floyd-Warshall
     *
     * Calcula las distancias mínimas entre todos los pares de vértices
     */
    void doFloyd()
    {
        // Inicializar matriz de Floyd con los valores de la matriz de adyacencia
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                floyd[i][j] = edges[i][j];
            }
        }

        // Algoritmo de Floyd-Warshall
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (floyd[i][k] != INF && floyd[k][j] != INF && 
                        floyd[i][k] + floyd[k][j] < floyd[i][j])
                    {
                        floyd[i][j] = floyd[i][k] + floyd[k][j];
                    }
                }
            }
        }
    }

    /**
     * @brief Imprime las matrices del grafo
     */
    void printOut()
    {
        cout << "Salida - Matriz Adyacente:\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (edges[i][j] == INF)
                    cout << "INF ";
                else
                    cout << edges[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        cout << "Salida - Matriz de Floyd:\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (floyd[i][j] == INF)
                    cout << "INF ";
                else
                    cout << floyd[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    /**
     * @brief Imprime todos los datos del grafo
     * @param graph Referencia constante al grafo
     *
     * Muestra el número de vértices, array de vértices y ambas matrices
     */
    void printD(const Graph &graph)
    {
        cout << "Número de vértices: " << graph.n << "\n";
        cout << "Array de vértices: ";
        for (int i = 0; i < graph.n; ++i)
        {
            cout << graph.vtrx[i] << " ";
        }
        cout << "\n\n";

        cout << "Matriz Adyacente:\n";
        for (int i = 0; i < graph.n; ++i)
        {
            for (int j = 0; j < graph.n; ++j)
            {
                cout << setw(8) << graph.edges[i][j];
            }
            cout << "\n";
        }
        cout << "\n";

        cout << "Matriz Floyd:\n";
        for (int i = 0; i < graph.n; ++i)
        {
            for (int j = 0; j < graph.n; ++j)
            {
                cout << setw(8) << graph.floyd[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
};