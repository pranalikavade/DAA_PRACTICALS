#include <iostream>
using namespace std;

class DocumentMerge
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

            cout << "Merging " << firstSize << " pages + "
                 << secondSize << " pages = "
                 << mergeCost << " pages" << endl;

            totalCost += mergeCost;

            arr[n] = mergeCost;
            n++;
        }

        return totalCost;
    }
};

int main()
{
    DocumentMerge document;

    int n;

    cout << "Enter number of documents: ";
    cin >> n;

    int *pages = new int[n];

    cout << "Enter number of pages in each document:" << endl;

    for (int i = 0; i < n; i++)
        cin >> pages[i];

    int totalCost = document.optimalMerge(pages, n);

    cout << "\nMinimum Total Merge Cost: "
         << totalCost << " pages" << endl;

    delete[] pages;

    return 0;
}