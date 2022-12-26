#include<stdio.h>
#include <stdlib.h>

#include "function.h"

void PrintArrays(int *A, int *B, int size){
    for(int i = 0; i < size; i++){
        if(i != 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");

    for(int j = 0; j < size; j++){
        if(j != 0) printf(" ");
        printf("%d", B[j]);
    }
    printf("\n");
    return;
}

int main(){
    char str[10];
    int size;
    scanf("%d", &size);

    int *A = (int*)malloc(sizeof(int)*size);
    int *B = (int*)malloc(sizeof(int)*size);

    for(int i = 0; i < size; i++){
        int num;
        scanf("%d", &num);
        A[i] = num;
    }

    for(int j = 0; j < size; j++){
        int num;
        scanf("%d", &num);
        B[j] = num;
    }

    while(1){
        scanf("%s", str);
        if(str[2] == 'A') Swap(A, B);//Swap
        else if(str[2] == 'I') Switch(&A, &B);//Switch
        else if(str[2] == 'P') Replace(A, B);//Replace
        else if(str[2] == 'O') break;//Stop
    }

    PrintArrays(A, B, size);

    return 0;
}
