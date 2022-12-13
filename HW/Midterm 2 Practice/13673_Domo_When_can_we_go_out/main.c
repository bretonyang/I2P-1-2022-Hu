#include <stdio.h>
#include <string.h>

int count = 0;
int N;
char str[21];
int str_idx = 0;

void generate_image(int side_len, int str_len) {

    // Base case
    if (str_idx >= str_len || count == -1 || side_len == 0) {
        count = -1;
        return;
    }
    if (str[str_idx] == '1') {
        count += side_len * side_len;
        str_idx += 1;
        return;
    }
    else if (str[str_idx] == '0') {
        str_idx += 1;
        return;
    }

    // Inductive case

    str_idx += 1;
    for (int i = 0; i < 4; i++) {
        generate_image(side_len / 2, str_len);
    }

}

int main() {
    scanf("%d %s", &N, str);

    int str_len = strlen(str);
    generate_image(1 << N, str_len);

    if (count == -1 || str_idx != str_len) {
        printf("Domo");
    }
    else {
        printf("%d", count);
    }

    return 0;
}
