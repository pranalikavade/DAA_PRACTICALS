#include <iostream>
using namespace std;

class Student
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
    Student student;
    int n, key;

    cout << "Enter number of students: ";
    cin >> n;

    int *rollNo = new int[n];

    cout << "Enter roll numbers in sorted order:" << endl;

    for (int i = 0; i < n; i++)
        cin >> rollNo[i];

    cout << "Enter roll number to search: ";
    cin >> key;

    int result = student.binarySearch(rollNo, 0, n - 1, key);

    if (result != -1)
        cout << "Roll Number " << key << " found at position " << result + 1 << "." << endl;
    else
        cout << "Roll Number " << key << " not found." << endl;

    delete[] rollNo;

    return 0;
}