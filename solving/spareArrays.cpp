#include <iostream>
#include <vector>
using namespace std;

void sparseArray(vector<string> &strings, vector<string> &queries, vector<int> &ans, int &i, int &count)
{
    if (i >= queries.size())
        return;

    for (int j = 0; j < strings.size(); j++)
    {
        if (strings[j] == queries[i])
            count++;
    }
    ans.push_back(count);
    i++;
    count = 0;
    sparseArray(strings, queries, ans, i, count);
}

int main()
{
    vector<string> strings = {"aba", "baba", "aba", "xzxb"};
    vector<string> queries = {"aba", "xzxb", "ab"};
    vector<int> ans;
    int i = 0;
    int count = 0;
    sparseArray(strings, queries, ans, i, count);

    for (int i : ans)
        cout << i << " ";

    return 0;
}