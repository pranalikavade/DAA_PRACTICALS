#include <iostream>
using namespace std;

class Bank
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
    Bank bank;
    int n, key;

    cout << "Enter number of account numbers: ";
    cin >> n;

    int *accountNo = new int[n];

    cout << "Enter account numbers in sorted order:" << endl;

    for (int i = 0; i < n; i++)
        cin >> accountNo[i];

    cout << "Enter account number to search: ";
    cin >> key;

    int result = bank.binarySearch(accountNo, 0, n - 1, key);

    if (result != -1)
        cout << "Account Number " << key << " found at position " << result + 1 << "." << endl;
    else
        cout << "Account Number " << key << " not found." << endl;

    delete[] accountNo;

    return 0;
}