#include <iostream>

// Função auxiliar para verificar se um número é primo
bool isPrime(int num, int divisor) {
    if (divisor == 1) {
        return true;
    }
    if (num % divisor == 0) {
        return false;
    }
    return isPrime(num, divisor - 1);
}

// Função auxiliar para encontrar o próximo número primo
int nextPrime(int num) {
    if (isPrime(num + 1, num)) {
        return num + 1;
    }
    return nextPrime(num + 1);
}

// Função recursiva para carregar os n primeiros primos no vetor M
void loadPrimeVecHelper(int M[], int n, int index, int current) {
    if (index == n) {
        return;
    }
    M[index] = current;
    loadPrimeVecHelper(M, n, index + 1, nextPrime(current));
}

// Função principal para carregar os n primeiros primos no vetor M
void loadPrimeVec(int M[], int n) {
    loadPrimeVecHelper(M, n, 0, 2); // Começa com o primeiro primo, que é 2
}

int main() {
    const int n = 10; // Número de primos a serem carregados
    int primes[n];
    loadPrimeVec(primes, n);
    std::cout << "Os " << n << " primeiros primos são: ";
    for (int i = 0; i < n; ++i) {
        std::cout << primes[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
