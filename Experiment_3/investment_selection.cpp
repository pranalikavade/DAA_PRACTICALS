#include <iostream>
using namespace std;

class Investment
{
public:
    void knapsack(int investment[], int returnValue[], int n, int budget)
    {
        double ratio[100];

        for (int i = 0; i < n; i++)
            ratio[i] = (double)returnValue[i] / investment[i];

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ratio[i] < ratio[j])
                {
                    swap(ratio[i], ratio[j]);
                    swap(investment[i], investment[j]);
                    swap(returnValue[i], returnValue[j]);
                }
            }
        }

        double totalReturn = 0;
        int remaining = budget;

        cout << "\nSelected Investments:\n";

        for (int i = 0; i < n; i++)
        {
            if (investment[i] <= remaining)
            {
                cout << "Investment: " << investment[i]
                     << ", Return: " << returnValue[i] << endl;

                remaining -= investment[i];
                totalReturn += returnValue[i];
            }
            else
            {
                double fraction = (double)remaining / investment[i];

                cout << "Fraction of investment taken: "
                     << fraction << endl;

                totalReturn += returnValue[i] * fraction;
                break;
            }
        }

        cout << "\nMaximum Return: " << totalReturn << endl;
    }
};

int main()
{
    Investment investmentPlan;

    int n, budget;

    cout << "Enter number of investment options: ";
    cin >> n;

    int *investment = new int[n];
    int *returnValue = new int[n];

    cout << "Enter investment amounts:" << endl;
    for (int i = 0; i < n; i++)
        cin >> investment[i];

    cout << "Enter expected returns:" << endl;
    for (int i = 0; i < n; i++)
        cin >> returnValue[i];

    cout << "Enter total budget: ";
    cin >> budget;

    investmentPlan.knapsack(investment, returnValue, n, budget);

    delete[] investment;
    delete[] returnValue;

    return 0;
}