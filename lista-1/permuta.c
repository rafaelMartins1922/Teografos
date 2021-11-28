#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(int *numbers, int n){
    printf("{");
    for(int i = 0; i < n; i++){
        printf("%d", numbers[i]);
        if(n > 1 && i != n-1){
            printf(",");
        }
    }
    printf("}\n");
}

void permutate(int *numbers, int start, int end, int n){
    if(start == end){
        print(numbers, n);
    }else{
        for (int i = start; i < end; i++){
            swap(numbers + start, numbers + i);
            permutate(numbers, start + 1, end, n);
            swap(numbers + start, numbers + i);
        }
    }
}

int main(int argc, char *argv[]){
   int n = 10;
    int *numbers = malloc(n*sizeof(int));

    for(int i = 0; i < n; i ++){
        numbers[i] = i+1;
    }

    permutate(numbers, 0, n, n);
    free(numbers);
    return 0;
}