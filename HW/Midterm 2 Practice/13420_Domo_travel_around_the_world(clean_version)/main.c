#include <stdio.h>

int N, K;
int visited[100]; // [city_idx]
int neighbors_of_city[100][5000]; // [city_idx][neighbor_idx]
int num_neighbors[100];

int dfs() {
    int num_of_components = 0;

    // visit all nodes
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            // one component found
            num_of_components++;

            // stack to push
            int stack[5000];
            int size = 0;

            // push current node
            stack[size] = i;
            size++;

            // visit all of current node's children
            // (i.e. nodes in the same component)
            while (size != 0) {
                // get current node
                int current_city = stack[size - 1];
                size--;

                // mark as visited
                visited[current_city] = 1;

                // push all of its children to stack
                for (int j = 0; j < num_neighbors[current_city]; j++) {
                    if (!visited[neighbors_of_city[current_city][j]]) {
                        stack[size] = neighbors_of_city[current_city][j];
                        size++;
                    }
                }
            }
        }
    }
    return num_of_components;
}

int main() {

    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        neighbors_of_city[c1][num_neighbors[c1]] = c2;
        neighbors_of_city[c2][num_neighbors[c2]] = c1;
        num_neighbors[c1]++;
        num_neighbors[c2]++;
    }

    int num_of_components = dfs();
    printf("%d\n", num_of_components - 1);

    return 0;
}

