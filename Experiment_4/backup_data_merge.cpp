#include <iostream>
using namespace std;

class BackupMerge
{
public:
    int findMin(int arr[], int n)
    {
        int minIndex = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[minIndex])
                minIndex = i;
        }

        return minIndex;
    }

    int optimalMerge(int arr[], int n)
    {
        int totalCost = 0;

        while (n > 1)
        {
            int first = findMin(arr, n);
            int firstSize = arr[first];

            arr[first] = arr[n - 1];
            n--;

            int second = findMin(arr, n);
            int secondSize = arr[second];

            arr[second] = arr[n - 1];
            n--;

            int mergeCost = firstSize + secondSize;

            cout << "Merging " << firstSize << " GB + "
                 << secondSize << " GB = "
                 << mergeCost << " GB" << endl;

            totalCost += mergeCost;

            arr[n] = mergeCost;
            n++;
        }

        return totalCost;
    }
};

int main()
{
    BackupMerge backup;

    int n;

    cout << "Enter number of backup files: ";
    cin >> n;

    int *size = new int[n];

    cout << "Enter backup file sizes in GB:" << endl;

    for (int i = 0; i < n; i++)
        cin >> size[i];

    int totalCost = backup.optimalMerge(size, n);

    cout << "\nMinimum Total Merge Cost: "
         << totalCost << " GB" << endl;

    delete[] size;

    return 0;
}