/* 45_00.c 共用体を用いた四角形の面積取得関数 */
#include <stdio.h>
#include "header.h"

/* main 関数 */
int main(void)
{
    const char *fmt_sq = "一辺 %2d の正方形     : %d\n";
    const char *fmt_re = "縦 %2d 横 %2d の長方形 : %d\n";
    const char *fmt_tr = "上底 %2d 下底 %2d 高さ %2d の台形 : %d\n";
    const char *fmt_ck = "種類 : %2d, 関数の戻り値 : %2d\n";
    STquadChara q;
    STsquare sq = {20};           /* 一辺 20 の正方形 */
    STrectangle re = {15, 10};    /* 縦 15 横 10 の長方形 */
    STtrapezium tr = {5, 15, 10}; /* 上底5下底15高さ10の台形 */

    /* 正方形 */
    q.kind = MacQuadSquare;
    q.uniquad.squ = sq;
    printf(fmt_sq, sq.side, quad_area(&q));
    /* 長方形 */
    q.kind = MacQuadRect;
    q.uniquad.rect = re;
    printf(fmt_re, re.verti, re.horizon, quad_area(&q));
    /* 台形 */
    q.kind = MacQuadTrape;
    q.uniquad.trape = tr;
    printf(fmt_tr, tr.top, tr.bottom, tr.height, quad_area(&q));
    /* 四角形の種類を規定範囲外にする */
    q.kind = MacQuadMin - 1;
    printf(fmt_ck, q.kind, quad_area(&q));
    q.kind = MacQuadMax;
    printf(fmt_ck, q.kind, quad_area(&q));

    return (0);
}

/* 四角形の面積を求める関数。エラー時は -1 を返す */
int quad_area(const STquadChara *quad)
{
    const int err = -1;
    const UNIquadrangle *q = &(quad->uniquad);

    int work;

    /* 四角形の種類の検査 */
    if ((quad->kind < MacQuadMin) ||
        (quad->kind >= MacQuadMax))
    {
        return (err);
    }

    switch (quad->kind)
    {
    case MacQuadSquare: /* 正方形 */
        return (q->squ.side * q->squ.side);
    case MacQuadRect: /* 長方形 */
        return (q->rect.verti * q->rect.horizon);
    case MacQuadTrape: /* 台形 */
        work = (q->trape.top + q->trape.bottom) *
               q->trape.height / 2;
        return (work);
    }
    return (0); /* ここには来ない */
}
