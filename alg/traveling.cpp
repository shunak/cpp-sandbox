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

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d %d",&t,&x,&y);


        // 一度目のループのときだけ変数宣言する
        // 原点の座標の定義宣言
        // int pos_x;
        // int pos_y;

        // if (i==0) {
        //     pos_y=0;
        //     pos_x=0;
        // }

        // 原点の座標の定義宣言
        // int pos[2]={pos_x,pos_y};


            // 上下左右全検索
            for(int right = 0; right <= t; right++)
            {
                pos[0]++;
                printf("%d\n",pos[0]);
                for(int up = 0; up <= t-right; up++)
                {
                    pos[1]++;
                    printf("%d\n",pos[1]);
                    // for(int left = 0; left <= t-right-up; left++)
                    // {
                    //     pos_x--;
                    //     for(int down = 0; down <= t-right-up-left; down++)
                    //     {
                    //         pos_y--;

                            
                            if (pos[0]==x&&pos[1]==y) {
                                pos[0]=x;
                                pos[1]=y;
                                // continue;
                                break;
                                // puts("Yes");
                                // return 0;
                            // }else{

                                // puts("Yes");
                                // return 0;

                            }
                            

                    //     }

                    // }

                }


                // break;
            }


    



    }

    
    if (pos[0]==x&&pos[1]==y) {
        puts("Yes");
    }else{
        puts("No");
    }


    return 0;
}


