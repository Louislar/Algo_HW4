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

double distances(dot p, dot q) //test pass
{
    int lx=p.x-q.x;
    int ly=p.y-q.y;
    lx=lx*lx;
    ly=ly*ly;
    double sum=ly+lx;
    sum=sqrt(sum);
    return sum;
}

double closest(dot points[], int pointsLength)
{
    if(pointsLength==2)
    {
        return distances(points[0], points[1]);
    }
    else if(pointsLength==1) return 10000;
    else{


    int medianIndex=pointsLength/2; //find the median
    int median=points[medianIndex].x;

    dot sL[medianIndex+1];
    dot sR[pointsLength-(medianIndex+1)];

    //separate into sL, sR
    for(int w=0;w<medianIndex+1;w++)
    {
        sL[w]=points[w];
    }
    for(int w=medianIndex+1, e=0;w<pointsLength;w++, e++)
    {
        sR[e]=points[w];
    }


    double dL=closest(sL, medianIndex+1);
    cout<<"dL: "<<dL<<endl;
    double dR=closest(sR, pointsLength-(medianIndex+1));
    cout<<"dR: "<<dR<<endl;
    double d=10000;


    //min(dL, dR)
    if(dL>dR) d=dR;
    else if(dR>dL) d=dL;
    else if(dR==dL) d=dR;

    cout<<d<<endl;

    //the points which's x is between m-d and m
    int point_pLength=0;
    dot point_p[pointsLength];
    for(int w=0;w<pointsLength;w++)
    {
        if(points[w].x<=median&&points[w].x>=median-d)
        {
            point_p[point_pLength]=points[w];
            point_pLength++;
        }
    }

    //the points which's x is between m and m+d
    int point_qLength=0;
    dot point_q[pointsLength];
    for(int w=0;w<pointsLength;w++)
    {
        if(points[w].x<=median+d&&points[w].x>median)
        {
            point_q[point_qLength]=points[w];
            point_qLength++;
        }
    }

    // points which's x is between m and m+d,
    // also its y is between yP-d and yP+d,
    // then calculate those point's distance with p
    for(int w=0;w<point_pLength;w++)
    {
        double yP=point_p[w].y;
        for(int e=0;e<point_qLength;e++)
        {
            if(point_q[e].y<=yP+d&&point_q[e].y>=yP-d)
            {
                double d_=distances(point_p[w], point_q[e]);
                if(d_<d) d=d_;
            }
        }
    }

    return d;


    }//else end
}

//test
int main()
{
    dot p=dot(0, 0);
    dot q=dot(1, 1);

    dot ps[5];
    for(int w=0;w<5;w++){ps[w]=dot(w, w);}
    cout<<closest(ps, 5);
}


int main01()
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
        closest(points, m);

    }
}
