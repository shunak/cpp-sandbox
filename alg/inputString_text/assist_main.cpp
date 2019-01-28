/* main 関数の補助 */
int assist_main( AssistPrm * ap, const char * input_end )
{
        const char * msg_err_fseek   = "assist_main : fseek error\n";
        const char * msg_input_start =
                "文字列を入力してください。ファイルに書き込みます。\n"
                "終了するには @end と入力してください。\n"
                "---------------------------------------------------\n\n";
        const char * msg_textout_start =
                "---------------------------------------------------\n\n"
                "書き込んだファイルの内容を出力します。\n\n";

        /* データを標準入力から入力 */
        fputs( msg_input_start, stdout );
        if ( input_stdin( ap ) == MacFalse )
        {
                return ( MacFalse );
        }
        while ( strcmp( ap->buf, input_end ) != 0 )
        {
                /* データをファイルへ記録 */
                if ( text_write( ap ) == MacFalse )
                {
                        return ( MacFalse );
                }
                /* データを標準入力から入力 */
                if ( input_stdin( ap ) == MacFalse )
                {
                        return ( MacFalse );
                }
        }
        /* 読み書き開始位置をファイルの先頭へ移動 */
        if ( fseek( ap->fp, 0, SEEK_SET ) != 0 )
        {
                fputs( msg_err_fseek, stderr );
                return ( MacFalse );
        }
        /* データを標準出力へ出力 */
        fputs( msg_textout_start, stdout );
        return ( text_stdout( ap ) );
}