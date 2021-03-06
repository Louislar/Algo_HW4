#include<iostream>
#include<math.h>

using namespace std;

int tIndex=0;

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
    if(e==tIndex){
        for(int i=0;i<=tIndex;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}

//test
int main01()
{
    int a[8]={3, 5, 2, 4, 1, 0, 7, 6};
    tIndex=7;
    MergeSort(a, 0, 7);
    for(int i=0;i<8;i++) cout<<a[i]<<" ";
    cout<<"\nB: \n";;

    int b[8]={3, 5, 2, 4, 1, 0, 7, 6};
    int k=3;
    int l=8;
    for(int e=1;e<=k;e++)
    {
        int temp1=pow(2, e);
        for(int i=0;i<l;i=i+temp1)
        {
            Merge(b, i, (2*i+temp1-1)/2, i+temp1-1);
        }

        //print B
        for(int i=0;i<l;i++) cout<<b[i]<<" ";
        cout<<endl;
    }

}

int main()
{
    int k=0;
    cin>>k;
    int l=pow(2, k);

    // 2^k=l

    int nums[l]={0};
    for(int i=0;i<l;i++) cin>>nums[i];

    tIndex=l-1;

    for(int e=1;e<=k;e++)
    {
        int temp1=pow(2, e);
        for(int i=0;i<l;i=i+temp1)
        {
            Merge(nums, i, (2*i+temp1-1)/2, i+temp1-1);
        }

        //print B
        for(int i=0;i<l;i++)
        {
            cout<<nums[i];
            if(i!=l-1)
                cout<<" ";
        }
        if(e!=k)
            cout<<endl;
    }



}
