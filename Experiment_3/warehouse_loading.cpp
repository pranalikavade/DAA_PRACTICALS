#include <iostream>
using namespace std;

class Warehouse
{
public:
    void knapsack(int weight[], int profit[], int n, int capacity)
    {
        double ratio[100];

        for (int i = 0; i < n; i++)
            ratio[i] = (double)profit[i] / weight[i];

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ratio[i] < ratio[j])
                {
                    swap(ratio[i], ratio[j]);
                    swap(weight[i], weight[j]);
                    swap(profit[i], profit[j]);
                }
            }
        }

        double totalProfit = 0;
        int remaining = capacity;

        cout << "\nSelected Items:\n";

        for (int i = 0; i < n; i++)
        {
            if (weight[i] <= remaining)
            {
                cout << "Weight: " << weight[i]
                     << ", Profit: " << profit[i] << endl;

                remaining -= weight[i];
                totalProfit += profit[i];
            }
            else
            {
                double fraction = (double)remaining / weight[i];

                cout << "Fraction of item taken: "
                     << fraction << endl;

                totalProfit += profit[i] * fraction;
                break;
            }
        }

        cout << "\nMaximum Profit: " << totalProfit << endl;
    }
};

int main()
{
    Warehouse warehouse;

    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int *weight = new int[n];
    int *profit = new int[n];

    cout << "Enter weight of items:" << endl;
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter profit of items:" << endl;
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << "Enter truck capacity: ";
    cin >> capacity;

    warehouse.knapsack(weight, profit, n, capacity);

    delete[] weight;
    delete[] profit;

    return 0;
}