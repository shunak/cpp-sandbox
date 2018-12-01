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

    int count;
    count=0;

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d %d",&t,&x,&y);

        // tの回数だけ+1か-1ができる
        int x_;
        int y_;

        // 一度目のループのときだけ変数宣言する
        // if (i==0) {

            // 原点の座標の定義宣言
            int pos_x;
            pos_x=0;
            int pos_y;
            pos_y=0;
            int pos[2]={pos_x,pos_y};

        // }

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
                                // pos[0]=x;

                                puts("Yes");
                                return 0;
                            }
                            

                    //     }

                    // }

                }

            }


    



    }

    puts("No");


    return 0;
}


