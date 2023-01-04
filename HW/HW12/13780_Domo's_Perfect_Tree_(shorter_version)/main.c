#include <stdio.h>
#include <stdlib.h>

int valueOfNode[1005];
int sizeOfNode[1005];
int *neighboursOfNode[1005];
int numOfNeighboursOfNode[1005];
int visited[1005];
int numOfPrint = 0;

int N, X, D;

void dfs(int idx) {
    // mark node as visited
    visited[idx] = 1;
	sizeOfNode[idx] += valueOfNode[idx];

    // if the node is not a leaf (whose only neighbour is its parent)
    if (numOfNeighboursOfNode[idx] != 1) {
        for (int i = 0; i < numOfNeighboursOfNode[idx]; i++) {
            // The current node's parent node is already visited
            if (!visited[neighboursOfNode[idx][i]]) {
                dfs(neighboursOfNode[idx][i]);
                sizeOfNode[idx] += sizeOfNode[neighboursOfNode[idx][i]];
            }
        }
    }

    // for later usage on printf
    if ((sizeOfNode[idx] - X > -D) && (sizeOfNode[idx] - X < D)) {
        numOfPrint++;
    }
}

int main(void)
{
    scanf("%d%d%d", &N, &X, &D);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &valueOfNode[i]);
    }

    int i, j;
    for (int cnt = 1; cnt <= N - 1; cnt++) {
        scanf("%d%d", &i, &j);

        // register neighbour
        numOfNeighboursOfNode[i] += 1;
        numOfNeighboursOfNode[j] += 1;
        neighboursOfNode[i] = (int*)realloc(neighboursOfNode[i], numOfNeighboursOfNode[i] * sizeof(int));
        neighboursOfNode[j] = (int*)realloc(neighboursOfNode[j], numOfNeighboursOfNode[j] * sizeof(int));

        neighboursOfNode[i][numOfNeighboursOfNode[i] - 1] = j;
        neighboursOfNode[j][numOfNeighboursOfNode[j] - 1] = i;
    }

    // Calculate and store the size of each node.
    dfs(1);

    // print result
    for (int i = 1, cnt = 0; i <= N; i++) {
        // |Size - X| < D
        // Size - X < D && Size - x > -D
        if ((sizeOfNode[i] - X > -D) && (sizeOfNode[i] - X < D)) {
            printf("%d%c", i, (cnt < numOfPrint - 1 ? ' ' : '\n'));
            cnt++;
        }
    }

    // Free the resources
    for (int i = 1; i <= N; i++) {
        // It's ok to free malloc'd pointers or NULL
        // However, free an uninitialized pointer is undefined behavior
        free(neighboursOfNode[i]);
    }

    return 0;
}

/*

1. Tree with N nodes
2. node 1 is the root
3. size of node i == sum(all of its children's values)
4.

*/

