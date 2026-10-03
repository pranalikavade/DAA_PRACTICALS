#include <iostream>
using namespace std;

class Emergency
{
public:
    void knapsack(int weight[], int value[], int n, int capacity)
    {
        double ratio[100];

        for (int i = 0; i < n; i++)
            ratio[i] = (double)value[i] / weight[i];

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ratio[i] < ratio[j])
                {
                    swap(ratio[i], ratio[j]);
                    swap(weight[i], weight[j]);
                    swap(value[i], value[j]);
                }
            }
        }

        double totalValue = 0;
        int remaining = capacity;

        cout << "\nSelected Emergency Supplies:\n";

        for (int i = 0; i < n; i++)
        {
            if (weight[i] <= remaining)
            {
                cout << "Weight: " << weight[i]
                     << ", Value: " << value[i] << endl;

                remaining -= weight[i];
                totalValue += value[i];
            }
            else
            {
                double fraction = (double)remaining / weight[i];

                cout << "Fraction of item taken: "
                     << fraction << endl;

                totalValue += value[i] * fraction;
                break;
            }
        }

        cout << "\nMaximum Value: " << totalValue << endl;
    }
};

int main()
{
    Emergency emergency;

    int n, capacity;

    cout << "Enter number of emergency supplies: ";
    cin >> n;

    int *weight = new int[n];
    int *value = new int[n];

    cout << "Enter weight of supplies:" << endl;
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter value of supplies:" << endl;
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter emergency bag capacity: ";
    cin >> capacity;

    emergency.knapsack(weight, value, n, capacity);

    delete[] weight;
    delete[] value;

    return 0;
}