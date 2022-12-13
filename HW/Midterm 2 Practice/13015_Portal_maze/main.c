#include <stdio.h>
#include <ctype.h>

int N, M;
int escaped = 0;
char maze[300][300];
int portal[26][2]; // portal[i][0]: row, portal[i][1]: col
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int is_valid(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < M;
}

void walk(int row, int col) {
    if (maze[row][col] == '&' || escaped) {
        escaped = 1;
        return;
    }
    else if (maze[row][col] == '#') {
        return;
    }
    else if (islower(maze[row][col])) {
        char ch = maze[row][col];
        walk(portal[ch - 'a'][0], portal[ch - 'a'][1]);
        return;
    }

    maze[row][col] = '#'; // block path

    for (int i = 0; i < 4; i++) {
        if (is_valid(row + dr[i], col + dc[i])) {
            walk(row + dr[i], col + dc[i]);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d %d", &N, &M);

        int start_row, start_col;
        escaped = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf(" %c", &maze[i][j]);
                if (maze[i][j] == '$') {
                    start_row = i;
                    start_col = j;
                }
                else if (isupper(maze[i][j])) {
                    portal[maze[i][j] - 'A'][0] = i;
                    portal[maze[i][j] - 'A'][1] = j;
                }
            }
        }

        // SOLVE
        walk(start_row, start_col);

        if (escaped) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}

/*
10
10 10
..#.S.....
..#....#..
##########
..#.....&.
kK#.......
..#.......
..#.......
..#.......
..#...$s..
..#.......
10 10
....I#..i.
.#...#.#..
##########
.#.#.#.#..
...&j#....
.#...#.#..
.....#....
$#.#.#.#..
.....#..J.
.#.#.#.#.#
10 10
.c#..R....
&###.#.#..
..#.......
r##....#.#
.$#.......
##########
..#.......
.###.#.#..
.C#.......
A###a#.#.#
10 10
..#.......
r.#..#.#..
k$#.......
.##....#.#
l&#.......
##########
.R#.......
.###..K#.#
..#.....L.
.##..#.#.#
10 10
.....#....
.....#....
.....#....
.....#...#
.....#....
##########
.&...#....
....j#...#
.....#....
$..#.#J...
10 10
.....#..&.
.....#....
##########
.....#....
..$..#....
.....#....
.....#....
.....#...#
..u..#.U..
.#...#....
10 10
.&.$.#..H.
....h#.#..
##########
...#.#...#
.C...#.c..
.#...#....
.....#....
.#.#.#.#.#
.....#....
.#.#.#.#.#
10 10
..#.......
..#.......
..#.......
..##......
..#.&.....
##########
..#..$.c..
.###...#..
.C#.......
..#..#...#
10 10
U.#i..I...
..#..#..z.
##########
..#.....u#
..#..$....
..#.......
.Z#.......
..#.......
..#&......
..#.......
10 10
..#.......
.###.....#
..#.......
.###y#...#
..#..b....
##########
g.#.G.....
..##.#.#..
.&#....B..
$##....#Y.
*/
