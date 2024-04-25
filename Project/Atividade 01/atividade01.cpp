#define atividade "1"
#define nome "Henrique Lima Pires"
#define matricula "557176"

// AS FUNÇÕES A SEGUIR DEVEM SER
//  IMPLEMENTADAS USANDO RECURSIVIDADE.
//  FUNÇÕES AUXILIATES PODEM SER
//  USADAS DESDE QUE SEJAM TAMBÉM RECURSIVAS.

// 1
// calcula o mdc de dois inteiros dados.
int mdc(int a, int b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

// 2
// Carregar no vetor M de tamanho
// n os n primeiros primos.começando em 2
// Note que o argumento de entrada M é saída neste problema.
bool isPrime(int num, int divisor)
{
    if (divisor == 1)
    {
        return true;
    }
    if (num % divisor == 0)
    {
        return false;
    }
    return isPrime(num, divisor - 1);
}

int nextPrime(int num)
{
    if (isPrime(num + 1, num))
    {
        return num + 1;
    }
    return nextPrime(num + 1);
}

void loadPrimeVecHelper(int M[], int n, int index, int current)
{
    if (index == n)
    {
        return;
    }
    M[index] = current;
    loadPrimeVecHelper(M, n, index + 1, nextPrime(current));
}

void loadPrimeVec(int M[], int n)
{
    loadPrimeVecHelper(M, n, 0, 2);
}
