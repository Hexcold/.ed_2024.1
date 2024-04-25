//ordenar de forma crescente

#include <iostream>

void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

int *max(int u[], int n) {
    if (n == 1)
        return u;

    int *p = max(u + 1, n - 1);
    if (u[0] > *p)
        return u;
    else
        return p;
}

int idMax(int u[], int n) {
    int j = 0;
    for (int k = 0; k < n; k++) // Corrigindo a variável de controle do loop
        if (u[k] > u[j])
            j = k;
    return j;
}

void sort(int u[], int n) {
    if (n == 1)
        return;
    int i = idMax(u, n);
    swap(u[i], u[n - 1]);
    sort(u, n - 1);
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
