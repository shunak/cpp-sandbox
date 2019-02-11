/* 45_00.h 「45_00.c」用ヘッダー・ファイル */
#ifndef __header_h__
#define __header_h__

/* 型定義 */
typedef struct  /* 正方形 */
{
        int side;       /* 一辺の長さ */
} STsquare;

typedef struct  /* 長方形 */
{
        int verti;      /* 縦の辺の長さ */
        int horizon;    /* 横の   〃    */
} STrectangle;

typedef struct  /* 台形 */
{
        int top;        /* 上底 */
        int bottom;     /* 下底 */
        int height;     /* 高さ */
} STtrapezium;  /* 英吉利 */

typedef union   /* 四角形の形状 */
{
        STsquare    squ;
        STrectangle rect;
        STtrapezium trape;
} UNIquadrangle;

typedef int TkindQuad;
typedef struct  /* 四角形の特徴 */
{
        TkindQuad     kind;
        UNIquadrangle uniquad;
} STquadChara;

/* マクロ定義 */
        /* TkindQuad 用 MacQuadMin ≦ 有効値 ＜ MacQuadMax */
#define MacQuadMin      0
#define MacQuadSquare   ( MacQuadMin    + 0 )
#define MacQuadRect     ( MacQuadSquare + 1 )
#define MacQuadTrape    ( MacQuadRect   + 1 )
#define MacQuadMax      ( MacQuadTrape  + 1 )

/* プロトタイプ宣言 */
int quad_area( const STquadChara * quad );

#endif  /* __header_h__ */