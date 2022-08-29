#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void manipulateArray(vector<vector<int>> &queries, vector<int> &sum, int &n, int &i)
{
    if (i >= queries.size())
    {
        return;
    }

    int a = queries[i][0];
    int b = queries[i][1];
    int k = queries[i][2];

    sum[a] += k;
    if ((b + 1) <= n)
        sum[b + 1] -= k;
    i++;
    manipulateArray(queries, sum, n, i);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> queries(m, vector<int>(3, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> queries[i][j];
        }
    }

    vector<int> sum(n + 1, 0);

    long maxVal = 0, sumVal = 0;
    int i = 0;
    manipulateArray(queries, sum, n, i);

    for (int i : sum)
    {
        sumVal += i;
        maxVal = max(maxVal, sumVal);
    }
    cout << maxVal;

    return 0;
}