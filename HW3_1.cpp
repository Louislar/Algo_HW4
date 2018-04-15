#include<iostream>
#include<math.h>

using namespace std;

class dot
{
public:
    dot(){x=0;y=0;}
    dot(int a, int b)
    {
        x=a;
        y=b;
    }
    int x;
    int y;

};

double distances(dot p, dot q)
{
    int lx=p.x-q.x;
    int ly=p.y-q.y;
    lx=lx*lx;
    ly=ly*ly;
    double sum=ly+lx;
    sum=sqrt(sum);
    return sum;
}

int closest(dot points[], int pointsLength)
{
    if(pointsLength==2)
    {
        return distance(points[0], points[1]);
    }

    /*******************start form here*************************/
}

//test
int main01()
{
    dot p=dot(0, 0);
    dot q=dot(1, 1);
    double a=distances(p, q);
    cout<<a;
}


int main()
{
    int n=0;
    cin>>n;
    for(int q=0;q<n;q++)
    {
        int m=0;
        cin>>m;
        dot points[m];
        for(int w=0;w<m;w++){points[w]=dot();}
        for(int w=0;w<m;w++)// input dots
        {
            int temp_x=0;
            int temp_y=0;
            cin>>temp_x;
            cin>>temp_y;
            points[w].x=temp_x;
            points[w].y=temp_y;
        }

        //sorting


        //closest 2 points


    }
}
