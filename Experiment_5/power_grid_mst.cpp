#include <iostream>
using namespace std;

class PowerGrid
{
public:
    int findParent(int parent[], int vertex)
    {
        if (parent[vertex] == vertex)
            return vertex;

        return findParent(parent, parent[vertex]);
    }

    void prims(int graph[10][10], int n)
    {
        int selected[10] = {0};
        int edges = 0;
        int totalCost = 0;

        selected[0] = 1;

        cout << "\nPrim's MST:\n";

        while (edges < n - 1)
        {
            int min = 9999;
            int x = 0;
            int y = 0;

            for (int i = 0; i < n; i++)
            {
                if (selected[i])
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (!selected[j] && graph[i][j] &&
                            graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }

            cout << "Station " << x + 1
                 << " - Station " << y + 1
                 << " : " << min << endl;

            totalCost += min;
            selected[y] = 1;
            edges++;
        }

        cout << "Total MST Cost using Prim's: "
             << totalCost << endl;
    }

    void kruskals(int graph[10][10], int n)
    {
        int parent[10];

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int edges = 0;
        int totalCost = 0;

        cout << "\nKruskal's MST:\n";

        while (edges < n - 1)
        {
            int min = 9999;
            int x = -1;
            int y = -1;

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (graph[i][j] && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }

            int rootX = findParent(parent, x);
            int rootY = findParent(parent, y);

            if (rootX != rootY)
            {
                cout << "Station " << x + 1
                     << " - Station " << y + 1
                     << " : " << min << endl;

                totalCost += min;
                parent[rootX] = rootY;
                edges++;
            }

            graph[x][y] = 0;
            graph[y][x] = 0;
        }

        cout << "Total MST Cost using Kruskal's: "
             << totalCost << endl;
    }
};

int main()
{
    PowerGrid grid;

    int n;
    int graph[10][10];

    cout << "Enter number of power stations: ";
    cin >> n;

    cout << "Enter connection cost matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    grid.prims(graph, n);

    grid.kruskals(graph, n);

    return 0;
}