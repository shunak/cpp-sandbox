/********************************************************************
        c_prac_inkey.h

                キー入力処理のヘッダー
********************************************************************/
#ifndef __c_prac_inkey_h__
#define __c_prac_inkey_h__

#define MacErr_NotNum (-1)      /* 数記号ではない         */
#define MacErr_GetNumStdin (-2) /* GetNumStdin 内でエラー */
int GetNumStdin(int flg_buf_clear);

#endif /* __c_prac_inkey_h__ */