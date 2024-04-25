#include <string>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

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

vector<string> tokenization(string& x)
{
    string alpha = "";
    string num = "";
    string opr = "";
    vector<string> tokens;

    bool chToken = true;
    bool numToken = true;

    for (char& c : x)
    {
        if (isspace(c)) continue;

        if (isalpha(c) && chToken)
        {
            alpha += c;

            if (!num.empty())
            {
                tokens.push_back(num);
            }

            if (!opr.empty())
            {
                tokens.push_back(opr);
            }

            numToken = false;

            num = "";
            opr = "";
        }

        else if ((isdigit(c) || c == '.') && numToken)
        {
            num += c;

            if (!alpha.empty())
            {
                tokens.push_back(alpha);
            }

            if (!opr.empty())
            {
                tokens.push_back(opr);
            }

            chToken = false;

            alpha = "";
            opr = "";
        }

        else if (c == '+' || c == '-' || c == '/' || c == '^' ||
                 c == '*' || c == '(' || c == ')')
        {
            opr += c;

            if (!num.empty())
            {
                tokens.push_back(num);
            }

            if (!alpha.empty())
            {
                tokens.push_back(alpha);
            }

            tokens.push_back(opr);

            numToken = true;
            chToken = true;

            num = "";
            alpha = "";
            opr = "";
        }
        
        else 
        {
            throw string("erro de sintaxe");
        }
    }

    if (!alpha.empty())
        tokens.push_back(alpha);
    if (!num.empty())
        tokens.push_back(num);
    if (!opr.empty())
        tokens.push_back(opr);

    return tokens;
}

int precedence(string i) 
{
    if (i == "^") return 3;
    else if (i == "/" || i == "*") return 2;
    else if (i == "+" || i == "-") return 1;
    else return 0;
}

vector<string> to_postfix(vector<string>& tokens)
{
    stack<string> stack;
    vector<string> ret;

    for (auto i : tokens)
    {
        if (isalpha(i.at(0)) || isdigit(i.at(0)))
        {
            ret.push_back(i);
        }

        else if (i == "(") stack.push(i);
        else if (i == ")")
        {
            while (stack.top() != "(")
            {
                ret.push_back(stack.top());
                stack.pop();
            }

            stack.pop();
        }
        else  
        {
            while (!stack.empty() 
                   && precedence(stack.top()) >= precedence(i))
            {
                ret.push_back(stack.top());
                stack.pop();
            }

            stack.push(i);
        }
    }

    while (!stack.empty())
    {
        ret.push_back(stack.top());
        stack.pop();
    }

    return ret;
}

float xEval(string x, map<string, float> &m)
{
  // x é a ///expressão  de entrada
  // m é o mapa de variáveis/valor
    vector<string> tokens;
    try
    {
        tokens = tokenization(x);
    }
    catch (const string& e)
    {
        return 0.0;
    }
    vector<string> postfixed = to_postfix(tokens);
    stack<float> stack;

    for (auto i : postfixed)
    {
        try 
        {
            stack.push(stof(i));

            continue;
        }
        catch (const invalid_argument& e) {}

        if (isalpha(i.at(0)) || isdigit(i.at(0)))
        {
            stack.push(m[i]);

            continue;
        }

        float v1 = stack.top();
        stack.pop();
        float v2 = stack.top();
        stack.pop();

        if (i == "+") stack.push(v1 + v2);
        if (i == "-") stack.push(v2 - v1);
        if (i == "*") stack.push(v1 * v2);
        if (i == "/") stack.push(v2 / v1);
        if (i == "^") stack.push(pow(v2, v1));
    }

    return stack.top(); 
}