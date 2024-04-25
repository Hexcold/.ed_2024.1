#include <iostream>
#include <cstdio>

void swap(int* p, int* q) {
    int x = *p;
    *p = *q;
    *q = x;
}

void inverse(int *u, int n) {
    if (n<2)
    return;

    swap(u, u + n - 1);

    inverse(u+1, n-2);
}

int* get() {
    return nullptr;
}
/*
int main() { //definindo o size (tamanho de vetor é padrão)
    int u[] = {1,2,3,4,5};
    inverse(u, 5);
    for (int k=0; k < 5; k++){
    printf("%d", u[k]);
    }
}
*/

int main () {
    int u[] = {1,2,3,4,5};
    int size = sizeof(u) / sizeof(u[0]); //ver o tamanho do array

    for(int k = 0; k < size; k++) {
        printf("%d ", u[k]);
    }

    printf("\n");

    inverse(u, size);

    for (int k = 0; k < size; k++) {
        printf("%d ", u[k]);
    }
    return 0;

}