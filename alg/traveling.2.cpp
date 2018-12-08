#include <string>
#include <iostream>

using namespace std;

int main(void){

    // 変数宣言。変数の領域をメモリ上に確保
    int N;

    // 標準入力から先ほど宣言したNのメモリ領域に値を読み込む。
    // このとき、Nはint型なので、＆演算子でさきほどの宣言で確保した変数Nのメモリ領域のアドレスを渡す。
    scanf("%d",&N);

    // t、ｘ、ｙをNの数だけ、読み込む
    // 変数宣言
    int t;
    int x;
    int y;

    // int count;
    // count=0;

    // 座標位置の宣言と初期化
    int pos[2]={0,0};

    // t>=1という条件があるので、座標はすくなくとも
    // 以下のいずれか。
    int pos_right[2]={1,0};
    int pos_up[2]={0,1};
    int pos_left[2]={-1,0};
    int pos_down[2]={0,-1};

    // 3 1 2
    // 6 1 1
    // というのは、
    //  ｛0,0｝に３回1か-1を足して、1,2にできて、
    // かつ、1,2に6-3回=3回1か-1足して1,1にできるか
    // という問題になる

    // 2^3の8通り×２の16通りある

    for(int i = 0; i < N; i++)
    {
        // 標準入力から値の読み込み
        scanf("%d %d %d",&t,&x,&y);

        




    }


    if (pos[0]==x&&pos[1]==y) {
        puts("Yes");
    }else{
        puts("No");
    }


    return 0;
}


