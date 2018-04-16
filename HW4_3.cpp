#include<iostream>

using namespace std;

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
    MergeSort(a, q+1, e);
    Merge(a, s, q, e);
    for(int i=0;i<6;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

int main()
{
    int a[6]={3, 5, 2, 4, 1, 0};
    MergeSort(a, 0, 5);
    for(int i=0;i<6;i++) cout<<a[i]<<" ";
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



}
