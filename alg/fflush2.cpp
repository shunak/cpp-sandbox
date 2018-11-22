#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>


/* プロトタイプ宣言 */
int key_in(const char *s);

/* 主関数 */
int main(void)
{
    int yn_age;
    int yn_sex;

    yn_age = key_in("二十歳以上ですか。0:はい, 1:いいえ ");
    yn_sex = key_in("性別は男ですか。  0:はい, 1:いいえ ");

    printf(
        "\n\n"
        "最初に入力された文字は %c %2X\n"
        "次に入力された文字は   %c %2X\n", /* コンマに注意 */
        yn_age, yn_age,
        yn_sex, yn_sex);

    return (0);
}

/**********************************************************
        int key_in(
        [in ]   const char * s          // 表示文字列
        );
        返し値
                成功 : 入力された最初の文字のコード
                失敗 : EOF
        必須ヘッダーファイル
                stdio.h
        処理詳細
                文字列を表示し、標準入力から一文字入力する
        注意
                入力前にバッファーを空にしている
**********************************************************/
int key_in(const char *s)
{
    int in;

    printf(s);
    fflush(stdin); /* 規格外 */
    in = fgetc(stdin);

    return (in);
}