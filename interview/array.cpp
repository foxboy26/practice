#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
using namespace std;

void shuffle(vector<int> &a)
{
    int len = a.size();
    for (int i=0; i < len; i++)
    {
        a[i] = i;
    }

    int idx;
    for (int i = 0; i < len; i++)
    {
        idx = rand() % (len-i) + i;
        swap(a[i], a[idx]);
    }
}

void print(vector<int> a)
{
    int len = a.size();
    if (len == 0) cout << "Empty!" << endl;

    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int> intersection_sorted(vector<int> &a, vector<int> &b)
{
    vector<int> res;

    int i, j;
    int m = a.size(), n = b.size();
    i = j = 0;

    while (i < m && j < n)
    {
        if (a[i] == b[j])
        {
            res.push_back(a[i]);
            i++;j++;
        }
        else if (a[i] < b[j]) i++;
        else j++;
    }

    return res;
}

vector<int> intersection(vector<int> &a, vector<int> &b)
{
    vector<int> res;
    unordered_map<int, int> map;
    int m = a.size(), n = b.size();

    if (m < n)
    {
        for (int i = 0; i < m; i++)
        {
            map[a[i]] = a[i];
        }

        for (int j = 0; j < n; j++)
        {
            if (map.find(b[j]) != map.end())
                res.push_back(b[j]);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            map[b[i]] = b;
        }

        for (int j = 0; j < m; j++)
        {
            if (map.find(a[j]) != map.end())
                res.push_back(a[j]);
        }

    }

    return res;
}

int main()
{
    vector<int> a(10);
    vector<int> b(7);

    //for (int i = 0; i < 10; i++)
    //{
    //    a[i] = i+1;
    //}
    //for (int i = 0; i < 8; i++)
    //{
    //    b[i] = i+6;
    //}

    shuffle(a);
    shuffle(b);

    print(a);
    print(b);

    vector<int> inter_sorted = intersection_sorted(a, b);
    vector<int> inter = intersection(a, b);

    //print(inter_sorted);
    print(inter);

    return 0;
}
