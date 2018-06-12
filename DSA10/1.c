#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<float.h>

typedef struct Point
{
    int x, y;
}Point;

Point P1,P2;

int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

void check(Point p1,Point p2){

	float d1,d2;
	d1=dist(p1,p2);
    d2=dist(P1,P2);

    if(d1<d2){
       P1=p1;
       P2=p2;
    }

}

float bruteForce(Point P[], int n)
{
    Point p1,p2;
    float min = FLT_MAX;
    int i,j;
    for (i = 0; i < n; ++i)
        for (j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min){
                min = dist(P[i], P[j]);
                p1=P[i],p2=P[j];
                check(p1,p2);
            }

    return min;
}

float min(float x, float y)
{
    return (x < y)? x : y;
}

float stripClosest(Point strip[], int size, float d)
{
    Point p1,p2;
    float min = d;
    int i,j;

    for (i = 0; i < size; ++i)
        for (j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min){
                min = dist(strip[i], strip[j]);
                p1=strip[i],p2=strip[j];
                check(p1,p2);
            }

    return min;
}

float closestUtil(Point Px[], Point Py[], int n)
{
    if (n <= 3)
        return bruteForce(Px, n);

    int mid = n/2, i;
    Point midPoint = Px[mid];

    Point Pyl[mid+1];
    Point Pyr[n-mid-1];
    int li = 0, ri = 0;
    for (i = 0; i < n; i++)
    {
      if (Py[i].x <= midPoint.x)
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }

    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n-mid);

    float d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;

    return min(d, stripClosest(strip, j, d) );
}

float closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];
    int i;
    for (i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);

    return closestUtil(Px, Py, n);
}

int main()
{
    P1.x = 0;
    P1.y = 0;
    P2.x = 999;
    P2.y = 999;

    int n,i;
    scanf("%d",&n);

    Point P[n];

    for(i=0; i<n; i++){
        scanf("%d %d",&P[i].x,&P[i].y);
    }

    closest(P, n);

    printf("%d %d\n",P1.x,P1.y);
    printf("%d %d\n",P2.x,P2.y);
    return 0;
}
