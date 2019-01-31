/* 43_01.h 「 43_01.c 」用ヘッダー・ファイル */
#ifndef __header_h__
#define __header_h__

/* マクロ定義 */
#define MacStreamSuccess 0 /* ストリーム関数 成功 */
#define MacStreamError 1   /*       〃       失敗 */
#define MacStreamEnd 2     /*       〃       終端 */

#define MacStdinBuffer 16 /* 標準入力のバッファ容量 */

/* ファイルへのアクセス法 */
#define MacModeArray 0   /* 配列の様に */
#define MacModePointer 1 /* ポインターの様に */

#define MacStrInputEnd "@end\n" /* 入力終了の合図の文字列 */

/* 型定義 */
typedef struct /* 商品型 */
{
    char code[8 + 1];  /* 商品コード */
    char name[15 + 1]; /* 商品名 */
    int price;         /* 通常小売価格 */
} STitem;

typedef int TstreamStatus; /* MacStream～用 */

/* プロトタイプ宣言 */
void err_msg_out(const char *func_name, const char *msg);
int assist_main(FILE *fp);
int input_read(FILE *fp, char *buf, const int buf_size,
               const int mode);
TstreamStatus input_stdin(char *buf, const int buf_size,
                          const int now_pos, int *result);
int get_nowpos(FILE *fp, const size_t size, long *pos);
int move_pos(FILE *fp, const size_t size, const long pos,
             const int mode);
TstreamStatus check_stream(FILE *fp);
void data_stdout(const STitem *item);

#endif /* __header_h__ */