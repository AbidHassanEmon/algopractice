#include <iostream>
using namespace std;

mystery(int n)
{
    if (n<=1)
    {
        return 1;
    }
    else
    {
       int k=n;
       for(int i=1;i<=n;i++)
            k=k+5;

       return k*mystery(n/2)+8*mystery(n/4);
    }
}
int main()
{
    int n;
    n = 10;
    cout<<"VALUE OF MYSTERY N = "<< mystery(n);

}
