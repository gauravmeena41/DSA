#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    deque<int> dmax(k);
    deque<int> dmin(k);

    for (int i = 0; i < k; i++)
    {
        while (!dmax.empty() && v[dmax.front()] <= v[i])
            dmax.pop_front();
        while (!dmin.empty() && v[dmin.front()] >= v[i])
            dmin.pop_front();

        dmax.push_back(i);
        dmin.push_back(i);
    }

    int sum = 0;

    sum += v[dmax.front()] + v[dmin.front()];

    for (int i = k; i < n; i++)
    {

        while (!dmax.empty() && i - dmax.front() >= k)
            dmax.pop_front();

        while (!dmin.empty() && i - dmin.front() >= k)
            dmin.pop_front();

        while (!dmax.empty() && v[dmax.front()] <= v[i])
            dmax.pop_front();

        while (!dmin.empty() && v[dmin.front()] >= v[i])
            dmin.pop_front();

        dmax.push_back(i);
        dmin.push_back(i);
        sum += v[dmax.front()] + v[dmin.front()];
    }

    cout << sum << endl;

    return sum;
}