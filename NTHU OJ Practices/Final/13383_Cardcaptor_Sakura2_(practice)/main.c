#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    int* cards;
} Table;

Table tables[10];

void init(void) {
    for (int i = 0; i < 10; i++) {
        tables[i].cards = (int*)malloc(sizeof(int) * 10005);
    }
}

void print(void) {
    for (int i = 0; i < 10; i++) {
        if (tables[i].size == 0) {
            printf("%d: No card\n", i);
        }
        else {
            printf("%d:", i);
            for (int j = 0; j < tables[i].size; j++) {
                printf(" %d", tables[i].cards[j]);
            }
            printf("\n");
        }
    }
}

void all(int num, int len) {
    for (int i = 0; i < 10; i++) {
        tables[i].size = len;
        for (int j = 0; j < len; j++) {
            tables[i].cards[j] = num;
        }
    }
}

void place(int table_idx, int len) {
    tables[table_idx].size = len;
    for (int i = 0; i < len; i++) {
        int tmp;
        scanf("%d", &tmp);
        tables[table_idx].cards[i] = tmp;
    }
}

void swap(int table_a, int table_b) {
    // swap size
    int tmp_size = tables[table_a].size;
    tables[table_a].size = tables[table_b].size;
    tables[table_b].size = tmp_size;

    // swap cards
    int* tmp_cards = tables[table_a].cards;
    tables[table_a].cards = tables[table_b].cards;
    tables[table_b].cards = tmp_cards;
}

void clear(void) {
    for (int i = 0; i < 10; i++) {
        tables[i].size = 0;
    }
}

void shiftleft(void) {
    for (int i = 0; i < 9; i++) {
        swap(i, i + 1);
    }
}

void shiftright(void) {
    for (int i = 9; i > 0; i--) {
        swap(i, i - 1);
    }
}

void destroy(void) {
    for (int i = 0; i < 10; i++) {
        free(tables[i].cards);
    }
}

int main()
{
    int end = 0;
    char str[20];

    init();

    while (!end) {
        scanf("%s", str);

        if (strcmp(str, "print") == 0) {
            print();
        }
        else if (strcmp(str, "all") == 0) {
            int num, len;
            scanf("%d%d", &num, &len);
            all(num, len);
        }
        else if (strcmp(str, "place") == 0) {
            int table_idx, len;
            scanf("%d%d", &table_idx, &len);
            place(table_idx, len);
        }
        else if (strcmp(str, "swap") == 0) {
            int i, j;
            scanf("%d%d", &i, &j);
            swap(i, j);
        }
        else if (strcmp(str, "shiftleft") == 0) {
            shiftleft();
        }
        else if (strcmp(str, "shiftright") == 0) {
            shiftright();
        }
        else if (strcmp(str, "clear") == 0) {
            clear();
        }
        else if (strcmp(str, "exit") == 0) {
            end = 1;
            destroy();
        }
    }

    return 0;
}
