

#include <cmath>
/*
Seja uma classe que representa um ponto no plano dada por,.  
*/

class ponto {
    float x; // abcissa
    float y; // ordenada
public:
    ponto (int _x, int _y)  // constrói ponto
    {  
        x = _x;
        y = _y;
           // cria  ponto dadas coordenadas
    }
    ponto () {
        x = 0;
        y = 0;
         // alternativa de criação de ponto
         // para construir um ponto (0,0) 
     }
     float dist (const ponto& p) {
            // determina a distância do ponto
            // à este passaso como argumeto.
            return sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));
        }       
        float& X() {
               // retorna referência 
               // da abcissa 
               return x;
        }
        float Y() {
             // Retorna referência para
             // a ordenada
             return y;
         }
         

};

/* Implemente as funções a seguir usando a classe anterior */

float reta(ponto& p, ponto& q) {
    // retorna coeficiente angular da reta 
    // que passa por p e 
    return (q.Y() - p.Y()) / (q.X() - p.X());
}

float minDistRecursive(const ponto &p, ponto kust[], int n, int index, float min)
{
    if (index == n) {
        return min;
    }


    float dis = kust[index].dist(p);

 
    if (dis < min) {
        min = dis;
    }


    return minDistRecursive(p, kust, n, index + 1, min);
}

float minDist(const ponto& p, ponto kust[], int n) {
   // retorna a menor distância entre p e os // pontos da lista list dada de 
   // comprimento n.  
   float min = kust[0].dist(p);

   return minDistRecursive(p, kust, n, 1, min);

   return min;
}

#include <iostream>

int main() {
  ponto p(1, 2), q(2, 3);
  ponto kust[] = {{3, 4}, {5, 6}, {7, 8}};

  std::cout << "Distância entre p e q: " << p.dist(q) << std::endl;
  std::cout << "Coeficiente angular da reta pq: " << reta(p, q) << std::endl;
  std::cout << "Menor distânciagcc entre p e os pontos da lista: " << minDist(p, kust, 3) << std::endl;

  return 0;
}