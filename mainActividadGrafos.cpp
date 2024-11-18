#include "grafos.cpp"
#include <fstream>
#include <stdexcept>

using namespace std;

/**
 * @brief Lee datos de un grafo desde un archivo y construye la matriz de adyacencia
 *
 * @param filename Nombre del archivo que contiene los datos del grafo
 * @param graph Referencia al grafo que se va a construir
 * @throws runtime_error Si hay problemas al abrir o leer el archivo
 * @throws invalid_argument Si los datos del archivo son inválidos
 *
 * Formato esperado del archivo:
 * - Primera línea: número de vértices (N)
 * - Siguientes N líneas: nombres de los vértices
 * - Siguiente línea: número de aristas (M)
 * - Siguientes M líneas: origen destino peso
 */
void loadFile(const string &filename, Graph &graph)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        throw runtime_error("No se pudo abrir el archivo: " + filename);
    }

    try
    {
        // Lectura del número de vértices
        int vertexCount;
        if (!(inputFile >> vertexCount) || vertexCount <= 0 || vertexCount > MAX)
        {
            throw invalid_argument("Número de vértices inválido o excede el máximo permitido (" +
                                   to_string(MAX) + "): " + to_string(vertexCount));
        }

        // Crear nuevo grafo con el número de vértices especificado
        graph = Graph(vertexCount);

        // Lectura de vértices
        string vertex;
        for (int i = 0; i < vertexCount; ++i)
        {
            if (!(inputFile >> vertex))
            {
                throw invalid_argument("Error al leer vértice " + to_string(i + 1));
            }
            graph.insertVtrx(vertex, i, graph);
        }

        // Lectura del número de aristas
        int edgeCount;
        if (!(inputFile >> edgeCount) || edgeCount < 0)
        {
            throw invalid_argument("Número de aristas inválido");
        }

        // Lectura y procesamiento de aristas
        string source, dest;
        float weight;
        for (int i = 0; i < edgeCount; ++i)
        {
            if (!(inputFile >> source >> dest >> weight))
            {
                throw invalid_argument("Error al leer arista " + to_string(i + 1));
            }

            if (weight < 0)
            {
                throw invalid_argument("Peso negativo no permitido en arista " +
                                       to_string(i + 1) + ": " + to_string(weight));
            }

            const int sourceIdx = graph.search(source, graph);
            const int destIdx = graph.search(dest, graph);

            if (sourceIdx == -1 || destIdx == -1)
            {
                throw invalid_argument("Vértice no encontrado en arista " + to_string(i + 1) +
                                       ": " + (sourceIdx == -1 ? source : dest));
            }

            graph.insertArc(weight, sourceIdx, destIdx, graph);
        }
    }
    catch (const exception &e)
    {
        inputFile.close();
        throw runtime_error("Error al procesar el archivo: "s + e.what());
    }

    inputFile.close();
}

/**
 * @brief Lee datos del grafo desde la entrada estándar (cin)
 *
 * @param graph Referencia al grafo que se va a construir
 * @throws invalid_argument Si los datos de entrada son inválidos
 * @throws runtime_error Si hay problemas con el formato de entrada
 */
void readInput(Graph &graph)
{
    try
    {
        // Lectura y validación del número de vértices
        int vertexCount;
        if (!(cin >> vertexCount))
        {
            throw invalid_argument("Error al leer el número de vértices");
        }
        if (vertexCount <= 0 || vertexCount > MAX)
        {
            throw invalid_argument("El número de vértices debe ser positivo y no exceder " +
                                   to_string(MAX) + ": " + to_string(vertexCount));
        }

        // Crear nuevo grafo con el número de vértices especificado
        graph = Graph(vertexCount);

        // Lectura de vértices
        string vertex;
        for (int i = 0; i < vertexCount; ++i)
        {
            if (!(cin >> vertex))
            {
                throw invalid_argument("Error al leer el vértice " + to_string(i + 1));
            }
            graph.insertVtrx(vertex, i, graph);
        }

        // Lectura y validación del número de aristas
        int edgeCount;
        if (!(cin >> edgeCount))
        {
            throw invalid_argument("Error al leer el número de aristas");
        }
        if (edgeCount < 0)
        {
            throw invalid_argument("El número de aristas debe ser no negativo: " + to_string(edgeCount));
        }

        // Lectura y procesamiento de aristas
        for (int i = 0; i < edgeCount; ++i)
        {
            string source, dest;
            float weight;

            if (!(cin >> source >> dest >> weight))
            {
                throw invalid_argument("Error al leer la arista " + to_string(i + 1));
            }

            if (weight < 0)
            {
                throw invalid_argument("Peso negativo no permitido en arista " +
                                       to_string(i + 1) + ": " + to_string(weight));
            }

            const int sourceIdx = graph.search(source, graph);
            const int destIdx = graph.search(dest, graph);

            if (sourceIdx == -1 || destIdx == -1)
            {
                throw invalid_argument("Vértice no encontrado en arista " + to_string(i + 1) +
                                       ": " + (sourceIdx == -1 ? source : dest));
            }

            graph.insertArc(weight, sourceIdx, destIdx, graph);
        }
    }
    catch (const exception &e)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Error en la entrada de datos: "s + e.what());
    }
}

/**
 * @brief Función principal del programa
 * @return 0 si la ejecución es exitosa, otro valor en caso de error
 */
int main()
{

    try
    {
        // Crear grafo inicial con un vértice (se redimensionará según la entrada)
        Graph graph(1);

        // Descomentar para usar lectura desde archivo
        /*
        string filename;
        cout << "Introduce el nombre del fichero de entrada: ";
        cin >> filename;
        loadFile(filename, graph);
        */

        // Lectura desde entrada estándar
        readInput(graph);

        // Aplicar algoritmo de Floyd y mostrar resultados
        graph.doFloyd(); // El método ya tiene acceso a los datos del grafo
        graph.printOut();

        return 0;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
};