#include <string>
#include <map>
#include <stack>

using namespace std;

#define atividade "05"
#define nome "Garibaldi"
#define matricula "***123"


// Atividade 5

// Usando a pilha do STL do C++ implemente um avaliador de expressões numéricas cujas expressões, dadas como 
// strings de entrada, devem ter as seguintes características:

// - Ser formada for letras, operadores, números e parênteses.

// - As letras formam nomes de variáveis e as constantes podem ser números reais ou inteiros. Exemplo,
// "x+beta-1.0" => possui as variáveis x e beta, os operadores + e - e a constante numérica 1.0

// - Os operadores computáveis são em ordem de precedêcia: "(+-*/^" onde "^" é o operador de potência.

// - Espaços em branco devem ser ignoráveis e outros caracteres diferentes dos apresentados devem ser 
// considerados erros. Por exemplo, "alpha+gama0+2!"  => são erros "gama0" pois é uma variável contendo 
// um caractere não letra,  Em "2!" o caractere é inválido.

// - O valor das variáveis é uma entrada representada pela estrutura de dados map da STL do C++. 
// Veja exemplo de uso do map a seguir:

/*
    int main() {
        map<string, float> m;
        m["x"] = 21.5; // carrega 'x'
        m["beta"] = 14.72; // carrega 'beta'
    }
*/  


float xEval(string x, map<string, float> &m)
{
  // x é a ///expressão  de entrada
  // m é o mapa de variáveis/valor
  return 0.0; 
}