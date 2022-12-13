#include <stdio.h>
#include <ctype.h>

#define SIZE 5
#define A_TO_Z 26

void encrypt(char res[], char src[], int r_shifts[]);
char shift_right(char ch, int shift);
void get_shifts(int shifts[], char s[], char enc_s[]);
char toggle_case(char ch);

int main(void)
{
    int r_shifts[SIZE];
    char A[SIZE + 1], enc_A[SIZE + 1], B[SIZE + 1], enc_B[SIZE + 1];
    scanf("%s", A);
    scanf("%s", enc_A);
    scanf("%s", B);

    get_shifts(r_shifts, A, enc_A);
    encrypt(enc_B, B, r_shifts);

    printf("%s\n", enc_B);

    return 0;
}

void encrypt(char res[], char src[], int r_shifts[])
{
    for (int i = 0; i < SIZE; i++) {
        res[i] = shift_right(src[i], r_shifts[i]);
        res[i] = toggle_case(res[i]);
    }

    res[SIZE] = '\0';
}

char shift_right(char ch, int shift)
{
    if (islower(ch)) {
        return (ch + shift > 'z') ? (ch + shift - A_TO_Z) : (ch + shift);
    }

    return (ch + shift > 'Z') ? (ch + shift - A_TO_Z) : (ch + shift);
}

void get_shifts(int shifts[], char s[], char enc_s[])
{
    for (int i = 0; i < SIZE; i++) {
        char ch = toggle_case(enc_s[i]);
        shifts[i] = (ch > s[i]) ? (ch - s[i]) : (A_TO_Z - s[i] + ch);
    }
}

char toggle_case(char ch)
{
    if (islower(ch)) {
        return toupper(ch);
    }
    else {
        return tolower(ch);
    }
}
