#include <stdio.h>

int main(void)
{
    int yn_age;
    int yn_sex;

    printf("二十歳以上ですか。0:はい, 1:いいえ ");
    fflush(stdin); /* 規格外 */
    yn_age = fgetc(stdin);
    printf("性別は男ですか。  0:はい, 1:いいえ ");
    fflush(stdin); /* 規格外 */
    yn_sex = fgetc(stdin);

    printf(
        "\n\n"
        "最初に入力された文字は %c %2X\n"
        "次に入力された文字は   %c %2X\n", /* コンマに注意 */
        yn_age, yn_age,
        yn_sex, yn_sex);

    return (0);
}