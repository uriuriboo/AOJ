#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,k,n) for(int i = k;i < (n);i++)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
using ll = long long;
using P = pair<ll,ll>;
#define repl(i,n) for(ll i = 0;i < (n);i++)
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll lINF = 1e18;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template <class T> inline bool chmin(T &a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return true;} return false;}

static const double EPS = (1e-10);

bool equals(double a,double b){
    return fabs(a-b) < EPS;
}

class Point{
    public:
    double x,y;
    Point(double x = 0,double y = 0):x(x),y(y){}

    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double a) { return Point(a * x, a * y); }
    Point operator/(double a) { return Point(x / a, y / a); }

    double abs() { return sqrt(norm()); }
    double norm() { return x * x + y * y; }

    bool operator < (const Point &p) const{
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const {
        return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};

class Segment{
    public:
    Point p1,p2;
    Segment(Point p1,Point p2):p1(p1),p2(p2){}
};

class Circle{
    public:
    Point c;
    double r;
    Circle(Point c = Point(),double r = 0.0):c(c),r(r){}
};

using Vector = Point;
using Line = Segment;
using Polygon = vector<Point>;

double norm(Vector a){
    return a.x * a.x + a.y * a.y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

double dot(Vector a,Vector b){
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a,Vector b){
    return a.x * b.y - a.y * b.x;
}

bool isOrthogonal(Vector a,Vector b){
    return equals(dot(a, b), 0.0);
}

bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){
    return isOrthogonal(a1 - a2, b1 - b2);
}

bool isOrthogonal(Segment s1,Segment s2){
    return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

bool isParallel(Vector a,Vector b){
    return equals(cross(a, b), 0.0);
}

bool isParallel(Point a1,Point a2,Point b1,Point b2){
    return isParallel(a1 - a2, b1 - b2);
}

bool isParallel(Segment s1,Segment s2){
    return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

Point project(Segment s,Point p){
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}

Point reflect(Segment s,Point p){
    return p + (project(s, p) - p) * 2.0;
}
/*p0,p1,p2の順に
1: 反時計回り
-1: 時計回り

2: p2,p0,p1の順に同一直線上
-2: p0,p1,p2の順に同一直線上
0: p2が線分p0p1上にある*/
int ccw(Point p0,Point p1,Point p2){
    const int COUNTER_CLOCKWISE = 1,CLOCK_WISE = -1,ONLINE_BACK = 2,ONLINE_FRONT = -2,ON_SEGMENT = 0;
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCK_WISE;
    if (dot(a, b) < -EPS) return ONLINE_BACK;
    if (a.norm() < b.norm()) return ONLINE_FRONT;

    return ON_SEGMENT;
}

bool intersect(Point p1,Point p2,Point p3,Point p4){
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1,Segment s2){
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double getDistance(Point a,Point b){
    return abs(a - b);
}

double getDistanceLP(Line l,Point p){
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double getDistanceSP(Segment s,Point p){
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
    return getDistanceLP(s, p);
}

double getDistance(Segment s1,Segment s2){
    if(intersect(s1,s2)) return 0.0;
    return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
    min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

Point getCrossPoint(Segment s1,Segment s2){
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

int main(void){
    int n,ans = 0;
    double x0,y0,x1,y1,x2,y2,x3,y3;
    cin >> n;

    rep(i,n){
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        Point p0(x0,y0),p1(x1,y1),p2(x2,y2),p3(x3,y3);
        Segment s1(p0,p1),s2(p2,p3);
        if(isParallel(p0,p1,p2,p3)) cout << 2 << endl;
        else if(isOrthogonal(p0,p1,p2,p3)) cout << 1 << endl;
        else cout << 0 << endl;
    }


    return 0;
}