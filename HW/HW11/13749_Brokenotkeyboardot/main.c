#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char p[10];
char s[500];
char **split_(char* str, char* pattern, int* split_num);
void free_(char **result, int split_num);
int main(void){
    int i, split_num;
    char **result;
    scanf("%s",s);
    scanf("%s",p);
    result = split_(s, p, &split_num);
    for(i=0; i<split_num; ++i) printf("%s\n",result[i]);
    free_(result, split_num);
    return 0;
}
