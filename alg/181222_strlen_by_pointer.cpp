// 文字列リテラルの文字列長の取得
#include <stdio.h>

/* マクロ定義 */
#define MacErr_StrLen (-1)

/* プロトタイプ宣言 */
int StrLen(char * s);

int main(void)
{
    char * pc0 = "ABCDEFG";
    char * pc1 = "あいうえお";

    printf("%s : %d文字\n", pc0, StrLen(pc0));
    printf("%s : %d文字\n", pc1, StrLen(pc1));

    return 0;

}
/************************
 * int StrLen(
 *  char * s
 * )
 * 
 * 返し値 
 *  成功: 文字列長。終端’\0’含まず
 *  失敗: MacEr_strLen
 * 
 *詳細処理 
 *  s の文字列長を求める。終端の’\0’は含まない
 *  s がヌルポインタならエラー
 * 
 * 
*****************************************/

int StrLen(char * s)
{
    int len = 0;

    if (s==NULL) {
        return(MacErr_StrLen);
    }

    while(*s != '\0')
    {
        len +=1;
        s+=1;
    }

    return len;




}


















