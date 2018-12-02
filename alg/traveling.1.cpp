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

        // 標準入力から値の読み込み
        scanf("%d %d %d",&t,&x,&y);

            // 上下左右全検索
            // 右方向検索
            for(int right = 0; right <= t; right++)
            {
                pos[0]++;
                printf("+x方向 %d\n",pos[0]);
                if (pos[0]==x&&pos[1]==y) {
                    pos[0]=x;
                    pos[1]=y;
                    // break;
                    goto _exit;
                }

                // 上方向検索
                for(int up = 0; up <= t-right; up++)
                {
                    pos[1]++;
                    printf("+y方向 %d\n",pos[1]);
                    if (pos[0]==x&&pos[1]==y) {
                        pos[0]=x;
                        pos[1]=y;
                        // break;
                        goto _exit;
                    }

                    // 左方向検索
                    for(int left = 0; left <= t-right-up; left++)
                    {
                        pos[0]--;
                        printf("-x方向 %d\n",pos[0]);
                        if (pos[0]==x&&pos[1]==y) {
                            pos[0]=x;
                            pos[1]=y;
                            goto _exit;
                            // break;

                        }

                        // // 下方向検索
                        // for(int down = 0; down <= t-right-up-left; down++)
                        // {
                        //     pos[1]--;
                        //     printf("-y方向 %d\n",pos[1]);
                        //     if (pos[0]==x&&pos[1]==y) {
                        //         pos[0]=x;
                        //         pos[1]=y;
                        //         goto _exit;
                        //         // break;
                        //     }


                        // }

                    // break;
                    }

                // break;
                }

            // break;
            }
            // break;


    _exit:;

    }

    
    if (pos[0]==x&&pos[1]==y) {
        puts("Yes");
    }else{
        puts("No");
    }


    return 0;
}


