#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int randomGenerator(int l, int r)
{
    random_device dev;
    mt19937 range(dev());
    uniform_int_distribution<mt19937::result_type> gen(l, r);
    return gen(range);
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

int partition_random(vector<int> &arr, int low, int high)
{
    int random = randomGenerator(low, high);
    swap(arr[random], arr[low]);
    return partition(arr, low, high);
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition_random(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    quickSort(arr, 0, n - 1);
    cout << "Sorted Array : ";
    printArray(arr, n);
    return 0;
}
