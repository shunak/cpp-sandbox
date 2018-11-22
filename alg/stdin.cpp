#include <stdio.h>

int main(void){

    int key;

    key = fgetc(stdin);

    printf(
        "入力キー    :%3c\n"
        "文字コード  :%3d(10)\n"
        "文字コード  :%3X(16)\n",
        key, key, key
    );

    return (0);

}




