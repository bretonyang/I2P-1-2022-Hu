#include <stdio.h>

int num = 0;
int len = 1;

int reverse(int n, int n_bits) {
    if (!n) return 1;

    int result = 0;
    while (n_bits) {
        result += (1 - (n & 1)) << (n_bits - 1);
        n >>= 1;
        n_bits--;
    }
    return result;
}

void calc_num(int N) {
    while (N--) {
//        printf("(num << 1) + 1): %d\n", (num << 1) + 1);
//        printf("((num << 1) + 1) << num_bits): %d\n", ((num << 1) + 1) << len);
//        printf("num_bits: %d\n", len);
//        printf("reverse(num, num_bits): %d\n", reverse(num, len));

        num = (((num << 1) + 1) << len) + reverse(num, len);
        len = 2 * len + 1;

//        printf("num: %d\n", num);
    }
}

int main()
{
    int N, T;
    scanf("%d %d", &N, &T);

    calc_num(N);

    int idx = 0, size = len;
    int arr[len];
    while (size) {
        arr[len - 1 - idx] = num & 1;
        num >>= 1;
        idx++;
        size--;
    }

    printf("\n-----------------\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n-----------------\n");

    while (T--) {
        int index;
        scanf("%d", &index);
        printf("%d\n", arr[index]);
    }

    return 0;
}
