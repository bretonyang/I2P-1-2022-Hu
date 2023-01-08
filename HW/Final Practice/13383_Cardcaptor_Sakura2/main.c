#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdint.h> // for int8_t types

typedef struct {
    int size;
    int* cards;
} Table;

// global variables are initialized to 0 bits.
Table tables[10];


void init(void) {
    for (int i = 0; i < 10; i++) {
        tables[i].cards = (int*)malloc(sizeof(int) * 10005);
    }
    // 10 * ~40100 = 401000 bytes
}

/**
 * print the status of each table with the format:
 * "table_idx: cards_on_the tables\n", e.g. "0: 1 3 3 4 5\n".
 */
void print(void) {
    for (int i = 0; i < 10; i++) {
        printf("%d:", i);
        if (!tables[i].size) {
            printf(" No card\n");
        }
        else {
            for (int j = 0; j < tables[i].size; j++) {
                printf(" %d", tables[i].cards[j]);
            }
            printf("\n");
        }
    }
}

/**
 * Place len cards on each table, and the value on each card is num .
 *
 * (Note that if there are cards already on the target table,
 * the status will be overridden.)
 */
void all(int num, int len) {
    for (int i = 0; i < 10; i++) {
        tables[i].size = len;
        for (int j = 0; j < len; j++) {
            tables[i].cards[j] = num;
        }
    }
}

/**
 * Place a stack of cards on table `table_idx`.
 * `len` means the number of cards in the stack.
 * An integer sequence `integer_sequence` of length `len` is given,
 * in which each integer means the value on the placed card.
 *
 * (Note that if there are cards already on the target table,
 * the status will be overridden.)
 */
void place(int table_idx, int len) {
    int num;
    tables[table_idx].size = len;
    for (int i = 0; i < len; i++) {
        scanf("%d", &num);
        tables[table_idx].cards[i] = num;
    }
}

/**
 * Swap the cards on table_idx_1 and table_idx_2.
 */
void swap(int table_idx_1, int table_idx_2) {
    // swap the sizes
    int size_tmp = tables[table_idx_1].size;
    tables[table_idx_1].size = tables[table_idx_2].size;
    tables[table_idx_2].size = size_tmp;

    // swap the cards
    int* tmp = tables[table_idx_1].cards;
    tables[table_idx_1].cards = tables[table_idx_2].cards;
    tables[table_idx_2].cards = tmp;
}

void clear(void) {
    for (int i = 0; i < 10; i++) {
        tables[i].size = 0;
    }
}

void free_all_sources(void) {
    for (int i = 0; i < 10; i++) {
        free(tables[i].cards);
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

int main()
{
//    freopen("testcases/28683.in", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int end = 0;
    char command[12];

    init();

    while (!end) {
        scanf(" %s", &command);

        if (!strcmp(command, "print")) {
            print();
        }
        else if (!strcmp(command, "all")) {
            int num, len;
            scanf("%d%d", &num, &len);
            all(num, len);
        }
        else if (!strcmp(command, "place")) {
            int table_idx, len;
            scanf("%d%d", &table_idx, &len);
            place(table_idx, len);
        }
        else if (!strcmp(command, "swap")) {
            int idx1, idx2;
            scanf("%d%d", &idx1, &idx2);
            swap(idx1, idx2);
        }
        else if (!strcmp(command, "clear")) {
            clear();
        }
        else if (!strcmp(command, "exit")) {
            free_all_sources();
            end = 1;
        }
        else if (!strcmp(command, "shiftleft")) {
            shiftleft();
        }
        else if (!strcmp(command, "shiftright")) {
            shiftright();
        }
    }

    return 0;
}
