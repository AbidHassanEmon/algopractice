#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int s[],int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            {
               swap(arr[j], arr[j+1]);
               swap(s[j], s[j+1]);
            }
}


void ActivitySelection(int start[], int finish[], int n)
{
  cout<<"The following activities are selected:"<<endl;
  int j = 0;
  cout<<j+1<<" ";
  for (int i = 1; i < n; i++)
  {
    if (start[i] >= finish[j])
    {
        cout<<i+1<<" ";
        j = i;
    }
  }
}


void printArray(int arr[], int size)
  {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
  }


int main()
{
    int start [] ={ 12,0,3,5 , 6, 2, 8,3,8,5,1 };
    int finish[] = {16,6,5,9,10,14,12,9,11,7,4};
    int n = sizeof(finish)/sizeof(finish[0]);
    bubbleSort(finish ,start,n);

    cout<<"AFTER SORT\n"<<"STARTING ARRAY :";
    printArray(start,n);

    cout<<"FINISHING ARRAY:";
    printArray(finish , n);

    ActivitySelection(start, finish, n);

    return 0;
}

