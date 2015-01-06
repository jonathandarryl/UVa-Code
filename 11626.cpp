#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <bitset>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#ifdef DEBUG
    #define cek(x) cout<<x
#else
    #define cek(x) if(false){}
#endif // DEBUG

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))

#define EPS 1e-9
#define PI acos(-1.0)

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); }
   bool operator <(point b) const{
    if(!(fabs(x - b.x)<EPS)) return x < b.x;
    return y < b.y;
   }};
struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
double cross(point p, point q, point r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x); }
// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0; }
  double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
double angle(point a, point o, point b) {  // returns angle aob in rad
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

bool inPolygon(point pt, const vector<point> &P) {
  if ((int)P.size() == 0) return false;
  double sum = 0;    // assume the first vertex is equal to the last vertex
  for (int i = 0; i < (int)P.size()-1; i++) {
    if (ccw(pt, P[i], P[i+1]))
         sum += angle(P[i], pt, P[i+1]);                   // left turn/ccw
    else sum -= angle(P[i], pt, P[i+1]); }                 // right turn/cw
  return fabs(fabs(sum) - 2*PI) < EPS; }
bool PointInPolygon(const vector<point> &p, point q) {
  bool c = 0;
  for (int i = 0; i < p.size()-1; i++){
    int j = (i+1);
    if ((p[i].y <= q.y && q.y < p[j].y ||
      p[j].y <= q.y && q.y < p[i].y) &&
      q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}

bool AM_cmp(point a, point b){
    if(!(fabs(a.x - b.x)<EPS)) return a.x < b.x;
    return a.y < b.y;
}

vector<point> AMH(vector<point> P){
    vector<point> res;
    res.assign(2*(int)P.size(),point(0,0));
    int counter = 0;
    for(int i=0;i<(int)P.size();i++){
        while (counter >= 2 && cross(res[counter-2], res[counter-1], P[i]) < 0) counter--;
                res[counter++] = P[i];
    }

    for(int i=(int)P.size()-2,t=counter+1;i>=0;i--){
        while (counter >= t && cross(res[counter-2], res[counter-1], P[i]) < 0) counter--;
                res[counter++] = P[i];
    }
    res.resize(counter,point(0,0));
    return res;
}point pivot(0,0);
double dist(point p1, point p2) {                // Euclidean distance
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

bool collinear(point p, point q, point r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

bool angleCmp(point a, point b) {                 // angle-sorting function
  if (collinear(pivot, a, b))                               // special case
    return dist(pivot, a) < dist(pivot, b);    // check which one is closer
  double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }   // compare two angles

int main(void){
    //freopen("in.txt","r",stdin);
    vector<point> P;
    int n;
    double x,y;
    int tc;
    scanf("%d",&tc);
    TC(){
        scanf("%d",&n);
        P.clear();
        FOR(i,n){
            char str[10];
            scanf("%lf %lf %s",&x,&y,str);

            if(str[0]=='Y')
                P.pb(point(x,y));
        }
        P.pb(P[0]);
        sort(P.begin(),P.end(),AM_cmp);
        P = AMH(P);
        vector<point> P2;
        //printf("%d\n",P.size());
        //sort(P.begin(),P.end(),angleCmp);
        map<point,int> mapper;
        FOR(i,P.size()){
            if(mapper.find(P[i])==mapper.end()){
                mapper[P[i]] = i;
                //printf("%.0lf %.0lf\n",P[i].x,P[i].y);
                P2.pb(P[i]);
            }
        }
        printf("%d\n",P2.size());
        FOR(i,P2.size()){
            printf("%.0lf %.0lf\n",P2[i].x,P2[i].y);
        }

    }
    return 0;
}
