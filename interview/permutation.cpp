#include <iostream>
#include <vector>
using namespace std;

void permute_help(vector<vector<int> > &res, vector<int> &a, int low, int high)
{
    if (low == high-1) res.push_back(a);

    for (int i = low; i < high; i++)
    {
        swap(a[low], a[i]);
        permute_help(res, a, low+1, high);
        swap(a[low], a[i]);
    }
}

vector<vector<int> > subset(vector<int> &a)
{
    int size = 1 << a.size();

    vector<vector<int> > res;
    for (int i = 0; i < size; i++)
    {   
        vector<int> sub;
        int j = i, idx = 0;
        while (j > 0)
        {
            if (j & 1 > 0) 
                sub.push_back(a[idx]);
            idx++;
            j >>= 1;
        }
        res.push_back(sub);
    }

    return res;
}

void print(vector<int> &a)
{
    for (int j = 0; j < a.size(); j++)
        cout << a[j] << " ";
    cout << endl;
}

int main()
{
    vector<int> a;
    for (int i = 0; i < 4; i++)
        a.push_back(i);

    vector<vector<int> > res;
    permute_help(res, a, 0, a.size());

    for (int i = 0; i < res.size(); i++)
    {
        print(res[i]);
    }

    vector<vector<int> > res2 = subset(a);
    for (int i = 0; i < res2.size(); i++)
    {
        print(res2[i]);
    }

    return 0;
}
