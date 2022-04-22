#include <iostream>
using namespace std;

void countSort(int a[], int n) {

  int b[30];
  int op=0;
  int k = a[0];
  op=op+1;

  for (int i = 0; i < n; i++) {
      op=op+2;
    if (a[i] > k)
      k = a[i];
     op=op+4;
  }
  op=op+2;
    int c[k];


  for (int i = 0; i <= k; i++) {
        c[i] = 0;
        op=op+4;
  }
  op=op+1;

  for (int j = 0; j < n; j++) {
       c[a[j]] =c[a[j]]+1;
      op=op+10;
  }
   op=op+2;

  for (int i = 1; i <= k; i++) {
    c[i] = c[i] + c[i - 1];
    op=op+5;
  }
   op=op+1;

  for (int j = n - 1; j >= 0; j--) {
    b[c [a[j]] - 1] = a[j];
    c[a[j]]= c[a[j]]-1 ;
    op=op+20;
  }
  op=op+2;

  for (int i = 0; i < n; i++) {
    a[i] = b[i];
  }
  cout<<"NUMBER OF OPERATION = "<<op<<endl;
}



void printArray(int a[], int n) {
    cout <<"SORTED : ";
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

int main()
{
  int a[] = {2, 20, 8, 5, 3, 10};
  int n = sizeof(a) / sizeof(a[0]);
  countSort(a, n);
  printArray(a, n);
}
