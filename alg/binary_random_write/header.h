/* 43_02.h 「 43_02.c 」用ヘッダー・ファイル */
#ifndef __header_h__
#define __header_h__

/* マクロ定義 */
#define MacStreamSuccess 0 /* ストリーム関数 成功 */
#define MacStreamError 1   /*       〃       失敗 */
#define MacStreamEnd 2     /*       〃       終端 */

/* 型定義 */
typedef int TstreamStatus; /* MacStream～用 */

/* プロトタイプ宣言 */
void err_msg_out(const char *func_name, const char *msg);
int assist_main(FILE *fp);
int write_random(FILE *fp);
TstreamStatus check_stream(FILE *fp);
int read_stdout(FILE *fp);

#endif /* __header_h__ */






