#include <stdio.h>

int hit_wall(int y, int x, int H, int W);

int main(void)
{
    // Read inputs
    int H, W, r, l, k;
    scanf("%d %d", &H, &W);
    scanf("%d %d", &r, &l);
    scanf("%d", &k);

    /*
     * Starting at (r, 1)
     * we'll still use the same xy-axis system
     * However, instead of (x,y), we'll use (y,x) to express the coordinate of a point
     * (due to the weird coordinate system of this question)
     */

    // Solve
    int y_pos = r; // starting position
    int x_pos = l; // starting position

    int dy = -1; // change in y direction
    int dx = 1; // change in x direction

    // when k == 1, it's the starting (r, 1) position
    for (; k > 1; k--) {
        do {
            y_pos += dy;
            x_pos += dx;
        } while (!hit_wall(y_pos, x_pos, H, W));

        if ((y_pos == 1 && (x_pos == 1 || x_pos == W)) || (y_pos == H && (x_pos == 1 || x_pos == W))) {
            // hit by corners
            break;
        }
        else if (x_pos == 1 || x_pos == W) {
            // hit by left/right wall
            dx = -dx;
        }
        else if (y_pos == 1 || y_pos == H) {
            // hit by upper wall
            dy = -dy;
        }
    }

    // print out result
    printf("(%d,%d)", y_pos, x_pos);

    return 0;
}

int hit_wall(int y, int x, int H, int W)
{
    if (x == 1 || x == W || y == 1 || y == H) {
        return 1;
    }

    return 0;
}
