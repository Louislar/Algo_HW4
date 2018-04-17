#include<iostream>
#include<queue>

using namespace std;

int tIndex=0;
queue<int> myqueue;

void Merge(int a[], int s, int q, int e)
{
    int temp1Length=q-s+1;
    int temp2Length=e-q;
    int temp1[temp1Length];
    int temp2[temp2Length];
    for(int i=0;i<temp1Length;i++)
        temp1[i]=a[s+i];
    for(int i=0;i<temp1Length;i++)
        temp2[i]=a[q+i+1];

    {//Merge to the original array

    int temp1Index=0;
    int temp2Index=0;
    int aIndex=s;
    while(1)
    {
        if(temp1Index>=temp1Length||temp2Index>=temp2Length)
        {
            break;
        }
        if(temp1[temp1Index]<temp2[temp2Index])
        {
            a[aIndex]=temp1[temp1Index];
            aIndex++;
            temp1Index++;
        }

        else if(temp1[temp1Index]>temp2[temp2Index])
        {
            a[aIndex]=temp2[temp2Index];
            aIndex++;
            temp2Index++;
        }

    }
    for(int i=temp1Index;i<temp1Length;i++)
    {
        a[aIndex]=temp1[i];
        aIndex++;
    }
    for(int i=temp2Index;i<temp1Length;i++)
    {
        a[aIndex]=temp2[i];
        aIndex++;
    }



    }//merge to original array end
}

int MergeSort(int a[], int s, int e)
{
    if(e==s) return 0;
    int q=(s+e)/2;

    MergeSort(a, s, q);
    for(int i=s;i<=q;i++) myqueue.push(a[i]);

    MergeSort(a, q+1, e);
    for(int i=q+1;i<=e;i++) myqueue.push(a[i]);

    Merge(a, s, q, e);
    if(e==tIndex){
        int temp1=e-s+1;
        int temp2=tIndex+1;
        int count1=0;
        while(temp2!=temp1) {temp2=temp2/2; count1++;}
        for(int i=0;i<=tIndex;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}

int main()
{
    int a[8]={3, 5, 2, 4, 1, 0, 7, 6};
    tIndex=7;
    MergeSort(a, 0, 7);
    for(int i=0;i<8;i++) cout<<a[i]<<" ";
}

int main01()
{
    int k=0;
    cin>>k;
    int l=1;
    while(k!=0)
    {
        l=l*2;
        k--;
    }
    k=l;

    int nums[k]={0};
    for(int i=0;i<k;i++) cin>>nums[i];

    tIndex=k-1;
    MergeSort(nums, 0, k-1);



}
