#include <stdio.h>

int in_set(int set_size, char set[], char ch);
int is_outside(int size, int row, int col);

int main(void)
{
    int set_size = 8;
    const char set1[] = {'a', 'f', 'k', 'p', 'E', 'J', 'O', 'T'};
    const char set2[] = {'b', 'g', 'l', 'q', 'D', 'I', 'N', 'S'};
    const char set3[] = {'c', 'h', 'm', 'r', 'C', 'H', 'M', 'R'};
    const char set4[] = {'d', 'i', 'n', 's', 'B', 'G', 'L', 'Q'};
    const char set5[] = {'e', 'j', 'o', 't', 'A', 'F', 'K', 'P'};

    int map_size, max_steps, row, col;

    scanf("%d%d%d%d", &map_size, &max_steps, &row, &col);
    getchar(); // read and discard '\n'

    char map[map_size][map_size];
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            map[i][j] = getchar();
            getchar(); // read and discard ' '
        }
        getchar(); // read and discard '\n'
    }

    // SOLVE
    // Looping through each step:
    char mode = 's'; // 's' for smallest, 'b' for biggest
    for (int steps = 0; steps <= max_steps && !is_outside(map_size, row, col); steps++) {
        // print current position in map:
        printf("%c", map[row][col]);

        // Find the chosen char:
        char chosen_char = (mode == 's') ? 127 : 0;
        int char_row, char_col;
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {
                if (is_outside(map_size, i, j) || (i == row && j == col)) {
                    continue;
                }

                int satisfy_mode = (mode == 's')
                    ? map[i][j] <= chosen_char
                    : map[i][j] >= chosen_char;

                if (satisfy_mode) {
                    chosen_char = map[i][j];
                    char_row = i;
                    char_col = j;
                }
            }
        }

        // Move:
        if (in_set(set_size, set1, chosen_char)) {
            col--; // move left
        }
        else if (in_set(set_size, set2, chosen_char)) {
            col++; // move right
        }
        else if (in_set(set_size, set3, chosen_char)) {
            row--; // move up
        }
        else if (in_set(set_size, set4, chosen_char)) {
            row++;
        }
        else if (in_set(set_size, set5, chosen_char)) {
            row = char_row;
            col = char_col;
            mode = (mode == 's') ? 'b' : 's';
        }
        else {
            row = char_row;
            col = char_col;
        }
    }

    return 0;
}

int in_set(int set_size, char set[], char ch)
{
    for (int i = 0; i < set_size; i++) {
        if (set[i] == ch) return 1;
    }
    return 0;
}

int is_outside(int size, int row, int col)
{
    return row < 0 || row >= size || col < 0 || col >= size;
}
