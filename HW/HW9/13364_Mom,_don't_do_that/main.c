#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    getchar();

    while (T-- > 0) {
        char origin[55][5005]; // 250000 bytes
        char decoded[55][5005]; // 250000 bytes
        int origin_len = -1;
        int decoded_len = -1;
        int index;
        char ch;
        while ((ch = getchar()) != '\n') {
            if (ch == '/') {
                if (origin_len >= 0) {
                    origin[origin_len][index] = '\0';
                }
                origin_len++;
                index = 0;
                continue;
            }
            origin[origin_len][index++] = ch;
        }
        origin[origin_len++][index] = '\0';

        while ((ch = getchar()) != '\n') {
            if (ch == '/') {
                if (decoded_len >= 0) {
                    decoded[decoded_len][index] = '\0';
                }
                decoded_len++;
                index = 0;
                continue;
            }
            decoded[decoded_len][index++] = ch;
        }
        decoded[decoded_len++][index] = '\0';

        // solve
        int is_valid = 1;

//        for (int i = 0; i < decoded_len && i < origin_len; i++) {
//            int found = 0;
//            for (int j = 0; j < decoded_len; j++) {
//                if (strcmp(origin[i], decoded[j]) == 0) {
//                    found = 1;
//                    break;
//                }
//            }
//            if (!found) {
//                is_valid = 0;
//                break;
//            }
//        }
//        if (decoded_len > origin_len) {
//            is_valid = 0;
//        }

        for (int i = 0; i < decoded_len; i++) {
            int found = 0;
            for (int j = 0; j < origin_len; j++) {
                if (strcmp(origin[j], decoded[i]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                is_valid = 0;
                break;
            }
        }

        if (is_valid) {
            printf("valid\n");
        } else {
            printf("not valid\n");
        }
    }

    return 0;
}
