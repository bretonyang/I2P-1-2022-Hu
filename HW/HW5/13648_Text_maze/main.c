#include <stdio.h>

#define SIZE 100

void print_path(int map_size, char map[SIZE][SIZE], int steps,
                int max_steps, int x, int y, char mode);
char find_smallest_char_around(int map_size, char map[SIZE][SIZE],
                               int x, int y, int *ch_x, int *ch_y);
char find_largest_char_around(int map_size, char map[SIZE][SIZE],
                               int x, int y, int *ch_x, int *ch_y);
void move(char chosen_ch, int ch_x, int ch_y, int *x, int *y, char *mode);
int is_outside(int size, int x, int y);


int main(void)
{
    int map_size, max_steps, x_pos, y_pos;
    char map[SIZE][SIZE] = {0};

    // Reading input
    scanf("%d %d %d %d", &map_size, &max_steps, &x_pos, &y_pos);
    getchar(); // clear '\n'
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            scanf("%c", &map[i][j]);
            getchar(); // clear ' '
        }
        getchar(); // clear '\n'
    }

    // print the path
    print_path(map_size, map, 0, max_steps, x_pos, y_pos, 's');

    return 0;
}

/**
 * Prints the texts visited with the given map and x, y position recursively.
 * Note that x, y are in the range [0, map_size - 1].
 */
void print_path(int map_size, char map[SIZE][SIZE], int steps,
                int max_steps, int x, int y, char mode)
{
    if (is_outside(map_size, x, y) || steps > max_steps) {
        return;
    }

    char chosen_ch;
    int ch_x, ch_y;

    printf("%c", map[x][y]);

    if (mode == 's') {
        chosen_ch = find_smallest_char_around(map_size, map, x, y, &ch_x, &ch_y);
    }
    else {
        chosen_ch = find_largest_char_around(map_size, map, x, y, &ch_x, &ch_y);
    }

    move(chosen_ch, ch_x, ch_y, &x, &y, &mode);

    print_path(map_size, map, steps + 1, max_steps, x, y, mode);
}

/**
 * Returns the index of the smallest char around the point (x, y) in the map.
 * If there are duplicated chars, return the largest index.
 * And store the index in ch_x and ch_y.
 */
char find_smallest_char_around(int map_size, char map[SIZE][SIZE],
                               int x, int y, int *ch_x, int *ch_y)
{
    char ch = 127;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (is_outside(map_size, i, j) || (i == x && j == y)) continue;

            if (map[i][j] <= ch) {
                ch = map[i][j];
                *ch_x = i;
                *ch_y = j;
            }
        }
    }

    return ch;
}

/**
 * Returns the index of the largest char around the point (x, y) in the map.
 * If there are duplicated chars, return the largest index.
 * Also, store the index in ch_x and ch_y.
 */
char find_largest_char_around(int map_size, char map[SIZE][SIZE],
                               int x, int y, int *ch_x, int *ch_y)
{
    char ch = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (is_outside(map_size, i, j) || (i == x && j == y)) continue;

            if (map[i][j] >= ch) {
                ch = map[i][j];
                *ch_x = i;
                *ch_y = j;
            }
        }
    }

    return ch;
}

void move(char chosen_ch, int ch_x, int ch_y, int *x, int *y, char *mode)
{
    switch (chosen_ch) {
        case 'a':
        case 'f':
        case 'k':
        case 'p':
        case 'E':
        case 'J':
        case 'O':
        case 'T':
            (*y)--;
            break;
        case 'b':
        case 'g':
        case 'l':
        case 'q':
        case 'D':
        case 'I':
        case 'N':
        case 'S':
            (*y)++;
            break;
        case 'c':
        case 'h':
        case 'm':
        case 'r':
        case 'C':
        case 'H':
        case 'M':
        case 'R':
            (*x)--;
            break;
        case 'd':
        case 'i':
        case 'n':
        case 's':
        case 'B':
        case 'G':
        case 'L':
        case 'Q':
            (*x)++;
            break;
        case 'e':
        case 'j':
        case 'o':
        case 't':
        case 'A':
        case 'F':
        case 'K':
        case 'P':
            *x = ch_x;
            *y = ch_y;
            *mode = (*mode == 's') ? 'b' : 's';
            break;
        default:
            *x = ch_x;
            *y = ch_y;
    }
}

/** Returns true if (x, y) is outside of the map, false otherwise. */
int is_outside(int map_size, int x, int y)
{
    return x < 0 || x == map_size || y < 0 || y == map_size;
}
