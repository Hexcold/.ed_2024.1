#include <fstream>

namespace aluno {

/*
Representa uma fração reduzida, ou seja, numerador e denominador são primos entre si.  
*/

class frac {
   int num;
   int den;
   static int mdc(int a, int b) {
        if(a%b == 0)
            return b;
        return mdc(b, a%b);
   }
public:   
frac(int n=0, int d=1) {  
       num = n;
       den = d;
   }
   // Operadores 
   bool operator>(frac& frac);
   bool operator==(frac& frac);
   frac operator+(frac& frac);   
   int getNum() { return num; }    
   int getDen() { return den; } 
};

frac* loadFracs(char* fileFracs);
frac sumFracs(frac fracs[], int n);
void sortFracs(frac fracs[], int n);
}