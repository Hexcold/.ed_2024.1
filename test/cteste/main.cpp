#include <cstdio>

int sum(int u[], int n)
{
    if (n == 1)
        return 0;
    else
        return u[0] + sum(u + 1, n - 1);
}

int max (int* u, int n);

int main() {
    int u[] = {2,5,7};
    int x;
    int* p = &x;
    p = &u[0];
    for (int k = 0; k<3; k++){

    }
    p = u + 1;
    int * v = u+1;
    for (int k=0; k<2; k++){
        
    }
    return 0;
}