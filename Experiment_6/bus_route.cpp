#include <iostream>
using namespace std;

class BusRoute
{
public:
    int findMinDistance(int distance[], bool visited[], int n)
    {
        int min = 9999;
        int index = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && distance[i] < min)
            {
                min = distance[i];
                index = i;
            }
        }

        return index;
    }

    void dijkstra(int graph[10][10], int n, int source)
    {
        int distance[10];
        bool visited[10] = {false};

        for (int i = 0; i < n; i++)
            distance[i] = 9999;

        distance[source] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int current = findMinDistance(distance, visited, n);

            if (current == -1)
                break;

            visited[current] = true;

            for (int i = 0; i < n; i++)
            {
                if (!visited[i] &&
                    graph[current][i] > 0 &&
                    distance[current] + graph[current][i] < distance[i])
                {
                    distance[i] =
                        distance[current] + graph[current][i];
                }
            }
        }

        cout << "\nShortest Distance from Bus Station 1:\n";

        for (int i = 0; i < n; i++)
        {
            cout << "Station 1 to Station " << i + 1
                 << " = " << distance[i] << " km" << endl;
        }
    }
};

int main()
{
    BusRoute bus;

    int n;
    int graph[10][10];

    cout << "Enter number of bus stations: ";
    cin >> n;

    cout << "Enter road distance matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    bus.dijkstra(graph, n, 0);

    return 0;
}