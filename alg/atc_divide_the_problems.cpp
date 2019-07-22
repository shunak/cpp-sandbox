
#include <cstdio>
#include <algorithm>
#define NUM 100000
#define LL long long
using namespace std;

int main()
{

    LL i, pos, j, m, buf, n, first_max, second_min, K, N, d[NUM];

    scanf("%lld", &N);

    for (i = 0; i < N; i++)
    {

            scanf("%lld", &d[i]);
        }

    sort(d, d + N);

    // //昇順整列アルゴリズム(バブルソート)
    //      // これだとTLEになってしまう
    //          // for (m = 0; m < N; m++)
    //              // {
    //
    //                  //     for (i = 0; i < N; i++)
    //                      //     {
    //
    //                          //         pos = d[i];
    //
    //                              //         if (i != N - 1)
    //                                  //         {
    //                                      //             j = i + 1;
    //                                          //         }
    //                                              //         else
    //                                                  //         {
    //                                                      //             j = i;
    //                                                          //         }
    //
    //                                                              //         if (pos >= d[j])
    //                                                                  //         {
    //
    //                                                                      //             buf = d[i];
    //                                                                          //             d[i] = d[j];
    //                                                                              //             d[j] = buf;
    //                                                                                  //         }
    //                                                                                      //     }
    //                                                                                          // }
    //
    //                                                                                              //条件を満たすKの値を求める
    //                                                                                                  first_max = N / 2 - 1;
    //                                                                                                      second_min = N / 2;
    //                                                                                                          // printf("%d\n",d[first_max]);
    //                                                                                                              // printf("%d\n",d[second_min]);
    //
    //                                                                                                                  //Kの初期化
    //                                                                                                                      K = 0;
    //
    //                                                                                                                          for (n = d[first_max] + 1; n <= d[second_min]; n++)
    //                                                                                                                              {
    //                                                                                                                                      K++;
    //                                                                                                                                          }
    //
    //                                                                                                                                              // puts("");
    //                                                                                                                                                  //結果の表示
    //                                                                                                                                                      printf("%lld\n", K);
    //
    //                                                                                                                                                          return 0;
    //                                                                                                                                                          }}









































































