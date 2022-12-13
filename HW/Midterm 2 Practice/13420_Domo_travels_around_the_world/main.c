#include <stdio.h>

int N, K;
int connected_components = 0;

typedef struct {
    int visited;
    int neighbor_count;
    int neighbors[100];
} City;

City cities[100];

int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        cities[i].neighbor_count = 0;
        cities[i].visited = 0;
    }

    for (int i = 0; i < K; i++) {
        int city_1, city_2;
        scanf("%d %d", &city_1, &city_2);
        cities[city_1].neighbors[cities[city_1].neighbor_count] = city_2;
        cities[city_1].neighbor_count++;
        cities[city_2].neighbors[cities[city_2].neighbor_count] = city_1;
        cities[city_2].neighbor_count++;
    }

    // DFS
    for (int i = 0; i < N; i++) {
        if (!cities[i].visited) {
            connected_components++;

            int stack[100];
            int size = 1;
            stack[size - 1] = i;

            while (size != 0) {
                int current = stack[size - 1];
                size--;
                cities[current].visited = 1;

                for (int j = 0; j < cities[current].neighbor_count; j++) {
                    int temp = cities[current].neighbors[j];
                    if (!cities[temp].visited) {
                        stack[size] = temp;
                        size++;
                    }
                }
            }
        }
    }

    printf("%d\n", connected_components - 1);

    return 0;
}
