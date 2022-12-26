#include <stdio.h>
#include "function.h"

int main() {
	int n; scanf("%d\n", &n);
	Student* arr = Create_(n);
	for(int i = 0; i < n; i++) {
		int num;
		char c[51];
		scanf("%d %s", &num, c);
		SetVal_(arr, i, num, c);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(Compare_(arr, i, j) > 0) {
				Swap_(arr, i, j);
			} 
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%d %s\n", arr[i].grade, arr[i].name);
	}
	Free_(arr, n);
}
