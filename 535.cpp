
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

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define pb push_back
#define TC() while(tc--)
#define reset(a,b) memset(a,b,sizeof(a))
#define PI 3.141592653589793
#define EARTH_RAD (6378000) // in meters

double gcDistance(double pLat, double pLong,
                  double qLat, double qLong, double radius) {
  pLat *= PI / 180; pLong *= PI / 180;
  qLat *= PI / 180; qLong *= PI / 180;
  return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
                       cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
                       sin(pLat)*sin(qLat));
}

double EucledianDistance(double pLat, double pLong, // 3D version
                         double qLat, double qLong, double radius) {
  double phi1 = (90 - pLat) * PI / 180;
  double theta1 = (360 - pLong) * PI / 180;
  double x1 = radius * sin(phi1) * cos(theta1);
  double y1 = radius * sin(phi1) * sin(theta1);
  double z1 = radius * cos(phi1);

  double phi2 = (90 - qLat) * PI / 180;
  double theta2 = (360 - qLong) * PI / 180;
  double x2 = radius * sin(phi2) * cos(theta2);
  double y2 = radius * sin(phi2) * sin(theta2);
  double z2 = radius * cos(phi2);

  double dx = x1 - x2, dy = y1 - y2, dz = z1 - z2;
  return sqrt(dx * dx + dy * dy + dz * dz);
}
int main(void){
    //freopen("in.txt","r",stdin);
    int counter = 0;
    string str;
    double x[1000],y[1000];

    while(cin>>str){
    }
    //cin>>str;
    return 0;
}
