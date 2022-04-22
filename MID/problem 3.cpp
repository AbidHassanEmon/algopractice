#include <iostream>
using namespace std;

long power(long x,long n)
{
    if(n==0)
    {
        return 1;
    }
    if ((n%2)==0)
    {
        return power(x,n/2)*power(x,n/2);
    }
    else
    {
       return x*power(x,n/2)*power(x,n/2);
    }
}
int main()
{
    long n,y;
    n = 3;
    y = 5;
    cout<<"VALUE OF POWER() = "<< power(n,y);

}
