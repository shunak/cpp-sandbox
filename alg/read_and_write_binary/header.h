/* 43_00.h 「 43_00.c 」用ヘッダー・ファイル */
#ifndef __header_h__
#define __header_h__

/* マクロ定義 */
#define MacStreamSuccess 0 /* ストリーム関数 成功 */
#define MacStreamError 1   /*       〃       失敗 */
#define MacStreamEnd 2     /*       〃       終端 */

/* 型定義 */
typedef struct /* 商品型 */
{
    char code[8 + 1];  /* 商品コード */
    char name[15 + 1]; /* 商品名 */
    int price;         /* 通常小売価格 */
} STitem;

/* プロトタイプ宣言 */
void err_msg_out(const char *func_name, const char *msg);
int assist_main(FILE *fp);
int check_stream(FILE *fp);
int write_master_file(FILE *fp);
void set_item(STitem *item, const int i);
int read_stdout_master_file(FILE *fp);
void item_stdout(STitem *item);

#endif /* __header_h__ */

