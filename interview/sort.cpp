#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;


void quicksort(int a[], int left, int right);
int partition(int a[], int left, int right);
int kthlargest(int a[], int len, int k);

void quicksort(int a[], int left, int right)
{
    if (right > left)
    {
        int pivot = partition(a, left, right);
        quicksort(a, left, pivot-1);
        quicksort(a, pivot+1, right);
    }
}

int partition(int a[], int left, int right)
{
    int pivot = rand() % (right-left+1) + left;
    int pivotValue = a[pivot];
    swap(a[pivot], a[right]);
    int storeIdx = left;
    for (int i = left; i < right; i++)
    {
        if (a[i] <= pivotValue)
        {
            swap(a[i], a[storeIdx]);
            storeIdx++;
        }
    }
    swap(a[right], a[storeIdx]);

    return storeIdx;
}

int kthlargest(int a[], int len, int k)
{
    int left = 0, right = len-1;

    int pivot;
    while (left < right)
    {
        pivot = partition(a, left, right);
        if (pivot == k) return a[k];
        else if (pivot > k) right = pivot-1;
        else left = pivot+1;
    }
}

void mergesort(int a[], int len)
{
}

int* merge(int a[], int m, int b[], int n)
{
    int i = 0, j = 0;
    int *res = new int[m+n];
    int idx = 0;
    while (i < m && j < n)
    {
        if (a[i] < a[j])
        {
            res[idx++] = a[i++];
        }
        else
        {
            res[idx++] = b[j++];
        }
    }

    while (i < m)
    {
        res[idx++] = a[i++];
    }

    while (j < n)
    {
        res[idx++] = b[j++];
    }

    return res;
}

void mergesort_help(int a[], int l, int h)
{
    
    int mid = (h+l) / 2;
    mergesort_help(a, l, mid);
    mergesort_help(a, mid+1, h);

}

void insertsort(int a[], int len)
{
    int *tmp = new int[len];
    for (int i = 0; i < len; i++) tmp[i] = a[i];

    for (int i = 0; i < len-1; i++)
        for (int j = i-1; j >=0; j--)
        {
            if (tmp[i] < a[j])
            {
                a[j+1] = a[j];
            }
            else
            {
                a[j+1] = tmp[i];
                break;
            }
        }

    delete [] tmp;
}

void bubblesort(int a[], int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i; j < len-1; j++)
        {
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
}

void countsort(int a[], int len)
{
    int aux[10];

    for (int i = 0; i < 10; i++) aux[i] = 0;

    for (int i = 0; i < len; i++)
    {
        aux[a[i]]++;
    }

    int idx = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < aux[i]; j++)
            a[idx++] = i;
    }
}

void generate(int a[], int len)
{
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
       a[i] = rand() % 10; 
    }
}

void print(int a[], int len)
{
    if (len == 0) cout << "Empty!" << endl;
    
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[20];

    generate(a, 20);
    print(a, 20);
    cout << "Count sort" << endl;
    countsort(a, 20);
    print(a, 20);

    generate(a, 20);
    print(a, 20);
    cout << "Insert sort" << endl;
    countsort(a, 20);
    print(a, 20);

    generate(a, 20);
    print(a, 20);
    cout << "Bubble sort" << endl;
    countsort(a, 20);
    print(a, 20);

    generate(a, 20);
    cout << "quick sort" << endl;
    quicksort(a, 0, 20);
    print(a, 20);

    //cout << "Merge sort" << endl;
    //countsort(a, 20);
    //print(a, 20);

    generate(a, 20);
    print(a, 20);
    cout << "Kth largest: " << kthlargest(a, 20, 19) << endl;

    return 0;
}
