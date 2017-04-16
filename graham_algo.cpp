#include<bits/stdc++.h>
using namespace std;

#define MP         make_pair
#define PB         push_back
#define LL         long long
#define MAX        1000005
#define mod        1000000007
#define debug(a)   cout<<a<<"\n"
#define mx(a,b,c)  max(a,max(b,c))
#define mn(a,b,c)  min(a,min(b,c))
#define pred(a)    printf("%0.6lf",a);
#define forp(i,x,b) for(int i=x;i<b;i++)
#define fast()     ios_base::sync_with_stdio(0)

const double eps=1e-9;
const double pi =acos(-1);
struct point{
	int x;
	int y;
};
point p0;
point p[100005];
int n;
LL t1,t2,t3,t4,t5;
bool c;
LL lcm(LL x, LL y) { return x*1LL*y/__gcd(x, y);}
LL int modpow(LL a,LL x){
	int r=1;
	while(x>0)
    if (x&1){ r=(r*a)%mod; --x;}
    else {a=(a*a)%mod;x>>=1;}
	return r%mod ;
}
point nextToTop(stack<point> &S)
{
    point p = S.top();
    S.pop();
    point res = S.top();
    S.push(p);
    return res;
}
int dis(point p1, point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

int angle(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
  if(val==0)return val;
    return (val > 0)? 1:2;
}

int compr(const void *p11, const void *p12){
	point *p1=(point *) p11;
	point *p2=(point *) p12;
	int x=angle(p0,*p1,*p2);
	if(x==0)
	{
		 return (dis(p0, *p2) >= dis(p0, *p1))? -1 : 1;
	}
	 return (x== 2)? -1: 1;
}
void Graham_scan()
{
   int y_lowest = p[0].y, min = 0;
   forp(i,1,n)
   {
     int y = p[i].y;
     if ((y < y_lowest) || (y_lowest == y &&
         p[i].x < p[min].x))
        y_lowest = p[i].y, min = i;
   }
   swap(p[0], p[min]);
   p0 = p[0];
   qsort(&p[1], n-1, sizeof(point), compr);
   int m = 1;
  forp(i,1,n)
   {
       while (i<n-1 && angle(p0, p[i], p[i+1])== 0)
          i++;
       p[m] = p[i];
       m++;
   }

   if (m < 3) return;
   stack<point> S;
   S.push(p[0]);
   S.push(p[1]);
   S.push(p[2]);
   for (int i = 3; i < m; i++)
   {
      while (angle(nextToTop(S), S.top(), p[i]) != 2)
         S.pop();
      S.push(p[i]);
   }
   cout<<"The convex hull in counter-clockwise fashion: \n";
   while (!S.empty())
   {
       point p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" <<"\n";
       S.pop();
   }
}

bool checkEqual(point points [],int x,int y,int count){
  bool check = false;
  for(int i=0;i<count;i++){
    if(points[i].x==x && points[i].y==y)
      check = true;
  }
  return check;
}

int main()
{
    t1=1000000007;
  	cout<<"Enter the no. of points:\n";
  	cin>>n;
    int count =0;
  	//cout<<"Enter the points in format of Xi and Yi:\n";
  	forp(i,0,n){
      int x = rand()%n;
      int y = rand()%n;
      while(checkEqual(p,x,y,count)){
        x = rand()%n;
        y = rand()%n;
      }
      p[i].x = x;
      p[i].y = y;
      count++;
    }
  	clock_t tStart = clock();
    Graham_scan();
    cout<<"Time taken: "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
}
