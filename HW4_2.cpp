#include<iostream>

using namespace std;

int f(int n)
{
    int cycleCount=0;
    while(1)
    {
        cycleCount++;
        if(n==1) break;
        if(n%2!=0) n=n*3+1;
        else {n=n/2;}
    }
    return cycleCount;
}

int main()
{
    int a=0;
    while(cin>>a)
    {
        int b=0;
        cin>>b;
        cout<<a<<" "<<b<<" ";
        if(a>b)
        {
            int temp=a;
            a=b;
            b=temp;
        }

        int cycleCount=0;
        for(int i=a;i<b+1;i++)
        {
            if(f(i)>cycleCount)
                cycleCount=f(i);
        }
        cout<<cycleCount<<endl;
    }
}
