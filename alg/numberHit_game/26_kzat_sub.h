/********************************************************************
        26_kzat_sub.h
                数当てゲームの各種関数に関する定義
********************************************************************/
#ifndef __26_kzat_sub_h__
#define __26_kzat_sub_h__

/* プロトタイプ宣言 */
int think_number(int min, int max);
int input_number(int min, int max, int *in_num);
void hit_number(int num);
void miss_number(int com_num, int in_num);
int continue_game(void);
int swapi(int *a, int *b);

/* 当てる回数が早いと判断する値 */
#define Mac_HitSmall 3
/* 外れた時に出すヒントが嘘である確率 */
#define Mac_FalseProbability 10 /* 1/n の意 */
/* 入力バッファのバイト単位の容量 */
#define Mac_InBufSize 16

#endif /* __26_kzat_sub_h__ */




