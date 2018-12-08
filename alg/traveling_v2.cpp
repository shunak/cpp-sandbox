#include <string>
#include <iostream>

using namespace std;

int main(void){

    int N;
    int t[110000], x[110000], y[110000];

    scanf("%d", &N);

    // 初期状態の定義
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;

    for (int i=0;i<N;i++) scanf("%d %d %d", &t[i+1], &x[i+1], &y[i+1]);

    bool canPlan = true;
    for (int i = 0; i < N; ++i) {
        int dt = t[i+1] - t[i];
        int dist = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
        if (dt < dist) canPlan = false;
        if (dist % 2 != dt % 2) canPlan = false;  // dist と dt の偶奇は一致する必要あり！
    }

    if (canPlan) puts("Yes");
    else puts("No");

    return 0;
}


