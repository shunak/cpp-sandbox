/* 42_02.h 「 42_00.c 」用ヘッダー・ファイル */
#ifndef __header_h__
#define __header_h__

/* マクロ定義 */
#define MacStreamSuccess 0 /* ストリーム関数 成功 */
#define MacStreamError 1   /*       〃       失敗 */
#define MacStreamEnd 2     /*       〃       終端 */

/* 型定義 */
typedef struct
{
    FILE *fp;
    char *buf;
    size_t buf_sz;
} AssistPrm;


/* プロトタイプ宣言 */
int check_stream(FILE *fp);
int assist_main(AssistPrm *ap, const char *input_end);
int text_write(AssistPrm *ap);
int text_stdout(AssistPrm *ap);
int input_stdin(const AssistPrm *ap);

#endif /* __header_h__ */