#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <climits>	// INT_MAX
#include <ctime>	// clock

using namespace std;
 
struct Point
{
    int x, y;
};
 
int angle(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
}

void convexHull(Point points[], int n)
{
    if (n < 3) return;
 
    vector<Point> hull;
 
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
 
    int p = l, q;
    do
    {
       
        hull.push_back(points[p]);
 
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           
           if (angle(points[p], points[i], points[q]) == 2)
               q = i;
        }
 
        p = q;
 
    } while (p != l);
 
    for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n";
}

bool checkEqual(Point points [],int x,int y,int count){
	bool check = false;
	for(int i=0;i<count;i++){
		if(points[i].x==x && points[i].y==y)
			check = true;
	}
	return check;
}
 
int main()
{
	int n;
  	cout<<"Enter no. of pnts:\n";
  	cin>>n;
  	int count =0;
    Point points[n];
    for(int i=0;i<n;i++){
    	int x = rand()%n;
    	int y = rand()%n;
    	while(checkEqual(points,x,y,count)){
    		x = rand()%n;
    		y = rand()%n;
    	}
    	points[i].x = x;
    	points[i].y = y;
    	count++;
    }
    clock_t tStart = clock();
    convexHull(points, n);
    cout<<"Time taken: "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
    return 0;
}