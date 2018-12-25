/* 24_00.c 演算子の優先順位 */
#include <stdio.h>
#include <stdlib.h>

/* マクロ定義 */
#define Mac_Size 5
#define Mac_AllocErr (-1)

int main(void)
{
    int i;
    char *p = (char *)malloc(sizeof(char) * Mac_Size);
    char *pb = p; /* p のバックアップ */

    if (p == NULL)
    {
        exit(Mac_AllocErr);
    }

    /* 確保した領域を直値 0 で初期化*/
    for (i = 0; i < Mac_Size; i++)
    {
        *(p + i) = (char)0;
    }

    /* 問題の表記 */
    *p++ = (char)20;
    *(p++) = (char)30;
    /* (*p)++ = (char)40; */ /* 有効にするとどなるでしょう */
    *++p = (char)50;         /* この様な記述は推奨しません */

    /* ポインターの値とメモリーの内容を表示 */
    printf("pb = %p\np  = %p\n", pb, p);
    for (i = 0; i < Mac_Size; i++)
    {
        printf("アドレス %p : データ %d\n", pb + i, *(pb + i));
    }

    free(pb);
    return (0);
}




// 　*p++ = (char)20; の式で最も優先順位の低い演算子は = です。従って右辺の代入はこの式の演算の最後となります。int 型の 20 から char 型への変換は代入に先立って行われます。
// 　*p++ では単項演算子が二つあります。間接参照演算子 * と 後置インクリメント演算子 ++ の演算優先順位は同じです。演算の優先順位が同じ場合には結合規則が働きます。
// 　結合規則は二種類あり、左から右、及び右から左です。左から右とは左側の演算子を先に処理し、その後右の演算子を処理します。右から左はその逆となります。左から右は →、右から左は ← と表記される事もあります。
// 　* と ++ は右から左、← なので p++ が評価されますが ++ は後置インクリメントなので後で加算処理されます。その後 *p が演算処理されます。従って *p++ = (char)20; は次の表記を一行にまとめたものです。

// *p = (char)20;
// p++;
// この結果確保した領域の最初のデータが 20 になったのです。
// 　優先順位や結合規則は C にとって重要な概念です。これらは表として C コンパイラーの説明書に付属していますから困った時は参照すると良いでしょう。本書にも付録として収録してあります。ですが出来るだけ括弧を用いる様にしましょう。括弧を付ければ優先順位を気にする事も無く安全ですし他の方にも分かり易いです。

// 　*(p++) = (char)30; は括弧が付いているのでその意味は分かり易いと思います。先の *p++ に括弧を付けた記述です。ですから現在の p が指し示すアドレスの内容に char 型の 30 が格納され、その後 p が一加算されます。

// 　注釈化してある (*p)++ = (char)40; ですが、もしこれを有効にすればコンパイル時にエラーとなります。 (*p)++ = (char)40; は (*p) = (char)40; (*p)++; を一行にまとめた記述と考えても問題無い様に思えますが、後置インクリメント演算子がある為にそうはなりません。
// 　*p や (*p) だけならば p の指し示す内容であり、これが左辺なのですからそこへの代入は可能です。 ところが (*p)++ と記述すると、この時点ではまだインクリメントは行われないもののその意味は「 ( p の指し示す内容 ) に後で 1 加算する char 型の整数値」となってしまいます。即ち 1 = 2; と記述したのと意味は同じになりエラーとなります。
// 　++(*p) の様に後置を前置に変更したとしても考え方は同じなのでやはりエラーとなります。
// 　この説明が理解出来れば c を char 型変数だとすると c = (*p)++; が有効なのはお分かりでしょう。 c にはまず *p の値が代入され、その後 *p の値が 1 加算されます。

// 　最後の *++p = (char)50; は一目で判断出来ないでしょう。こんな記述も C 言語では許されます。この記述は演算子の結合規則により *(++p) = (char)50; と認識されるので、先に p のアドレスを一加算しその後加算結果のアドレスの内容に char 型の 50 が格納されます。その為に 30 が格納されたアドレスから 50 が格納されたアドレスとは一つ間が開いています。
// 　演算子が連続する場合はなるべく括弧を使用するのが望ましいです。