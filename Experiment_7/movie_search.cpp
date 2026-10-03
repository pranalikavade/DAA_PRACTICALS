#include <iostream>
using namespace std;

class Movie
{
public:
    int optimalBST(int keys[], int freq[], int n)
    {
        int cost[20][20];

        for (int i = 0; i < n; i++)
            cost[i][i] = freq[i];

        for (int length = 2; length <= n; length++)
        {
            for (int i = 0; i <= n - length; i++)
            {
                int j = i + length - 1;
                cost[i][j] = 9999;

                int sum = 0;

                for (int k = i; k <= j; k++)
                    sum += freq[k];

                for (int r = i; r <= j; r++)
                {
                    int left = (r > i) ? cost[i][r - 1] : 0;
                    int right = (r < j) ? cost[r + 1][j] : 0;

                    int total = left + right + sum;

                    if (total < cost[i][j])
                        cost[i][j] = total;
                }
            }
        }

        return cost[0][n - 1];
    }
};

int main()
{
    Movie movie;

    int n;

    cout << "Enter number of movies: ";
    cin >> n;

    int *movieID = new int[n];
    int *freq = new int[n];

    cout << "Enter movie IDs in sorted order:" << endl;

    for (int i = 0; i < n; i++)
        cin >> movieID[i];

    cout << "Enter search frequencies:" << endl;

    for (int i = 0; i < n; i++)
        cin >> freq[i];

    int result = movie.optimalBST(movieID, freq, n);

    cout << "\nMinimum Search Cost: " << result << endl;

    delete[] movieID;
    delete[] freq;

    return 0;
}