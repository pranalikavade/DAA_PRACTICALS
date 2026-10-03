#include <iostream>
using namespace std;

class VideoMerge
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

            cout << "Merging " << firstSize << " MB + "
                 << secondSize << " MB = "
                 << mergeCost << " MB" << endl;

            totalCost += mergeCost;

            arr[n] = mergeCost;
            n++;
        }

        return totalCost;
    }
};

int main()
{
    VideoMerge video;

    int n;

    cout << "Enter number of video files: ";
    cin >> n;

    int *size = new int[n];

    cout << "Enter video file sizes in MB:" << endl;

    for (int i = 0; i < n; i++)
        cin >> size[i];

    int totalCost = video.optimalMerge(size, n);

    cout << "\nMinimum Total Merge Cost: "
         << totalCost << " MB" << endl;

    delete[] size;

    return 0;
}