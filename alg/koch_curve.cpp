#include <stdio.h>
#include <math.h>

struct Point{
    double x, y;
};

int koch(int n, Point a, Point b){

    if(n==0)return 0;

    Point s, t, u;
    double degree = M_PI * 60.0 / 180.0; // 度からラジアン単位へ変換
    static int count=0; // 再帰するたびに初期化されないように、静的変数として定義

    s.x = (2.0 * a.x + 1.0 * b.x)/3.0;
    s.y = (2.0 * a.y + 1.0 * b.y)/3.0;
    t.x = (1.0 * a.x + 2.0 * b.x)/3.0;
    t.y = (1.0 * a.y + 2.0 * b.y)/3.0;

    u.x = (t.x - s.x)*cos(degree)-(t.y-s.y)*sin(degree)+s.x;
    u.y = (t.x - s.x)*sin(degree)+(t.y-s.y)*cos(degree)+s.y;


    koch(n-1,a,s);
    printf("%.8f %.8f\n", s.x, s.y);
    count++;
    koch(n-1,s,u);
    printf("%.8f %.8f\n", u.x, u.y);
    count++;
    koch(n-1,u,t);
    printf("%.8f %.8f\n",t.x, t.y);
    count++;
    koch(n-1,t,b);

    return count;

}

int main(){

    Point a, b;
    int n,ans;
    // static int count;
    // count=0;
    // count=0;

    scanf("%d",&n);

    a.x=0;
    a.y=0;
    b.x=100;
    b.y=0;

    printf("%.8f %.8f\n", a.x, a.y);
    ans = koch(n, a, b);
    printf("%.8f %.8f\n", b.x,b.y);
    printf(" ");
    printf("描画回数%d\n",ans);
    return 0;

}









