#include <iostream>
using namespace std;

class Railway
{
public:
    int binarySearch(int arr[], int low, int high, int key)
    {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (key < arr[mid])
            return binarySearch(arr, low, mid - 1, key);

        return binarySearch(arr, mid + 1, high, key);
    }
};

int main()
{
    Railway railway;
    int n, key;

    cout << "Enter number of ticket IDs: ";
    cin >> n;

    int *ticketID = new int[n];

    cout << "Enter ticket IDs in sorted order:" << endl;

    for (int i = 0; i < n; i++)
        cin >> ticketID[i];

    cout << "Enter ticket ID to search: ";
    cin >> key;

    int result = railway.binarySearch(ticketID, 0, n - 1, key);

    if (result != -1)
        cout << "Ticket ID " << key << " found at position " << result + 1 << "." << endl;
    else
        cout << "Ticket ID " << key << " not found." << endl;

    delete[] ticketID;

    return 0;
}