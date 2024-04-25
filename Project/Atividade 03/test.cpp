#include <fstream>

#define atividade "3"  
#define nome "Henrique Lima Pires" 
#define matricula "557176"


namespace aluno {

    /*
    Representa uma fração reduzida, ou seja, numerador e denominador são primos entre si.  
    */
    class frac {
        int num;
        int den;

        static int mdc(int num1, int num2) {
            if (num1 % num2 == 0)
                return num2;
            return mdc(num2, num1 % num2);
        }

    public:
        frac(int n = 0, int d = 1) {
            num = n;
            den = d;
        }

        // Operadores 
        bool operator>(frac& f) {
            return (static_cast<float>(num) / den) > (static_cast<float>(f.num) / f.den);
        }

        bool operator==(frac& f) {
            return (static_cast<float>(num) / den) == (static_cast<float>(f.num) / f.den);
        }

        frac operator+(frac& f) {
            int x = f.num * den + f.den * num;
            int y = f.den * den;
            int gcd = mdc(x, y);
            x /= gcd;
            y /= gcd;
            return frac(x, y);
        }

        int getNum() {
            return num;
        }

        int getDen() {
            return den;
        }
    };

    frac* loadFracs(char* fileFracs) {
        /*
        Retorna frações num arquivo e as coloca em um vetor alocaso dinamicamente. 
        */
        std::ofstream file;
        frac* fracs = new frac[16];
        int x, y;
        int fracs_count = 0;

        file.open("fracoes.txt");

        for (int i = 0, count = 0; fileFracs[i] != '\0'; i++) {
            if (fileFracs[i] >= '0' && fileFracs[i] <= '9') {
                if (count == 0) {
                    file << fileFracs[i] << std::endl;
                    count++;
                } else {
                    if (count % 2 != 0) {
                        file << fileFracs[i];
                        if (fileFracs[i + 1] >= '0' && fileFracs[i + 1] <= '9') {
                            file << fileFracs[i + 1];
                            x = 10 * (fileFracs[i] - '0') + (fileFracs[i + 1] - '0');
                            i++;
                        } else {
                            x = fileFracs[i] - '0';
                        }
                        file << '\t';
                    } else {
                        file << fileFracs[i];
                        if (fileFracs[i + 1] >= '0' && fileFracs[i + 1] <= '9') {
                            file << fileFracs[i + 1];
                            y = 10 * (fileFracs[i] - '0') + (fileFracs[i + 1] - '0');
                            i++;
                        } else {
                            y = fileFracs[i] - '0';
                        }
                        file << std::endl;
                        fracs[fracs_count] = frac(x, y);
                        fracs_count++;
                    }
                    count++;
                }
            }
        }

        file.close();

        return fracs;
    }

    frac sumFracs(frac fracs[], int n) {
        /*
        Retorna soma de frações do vetor de entrada. 
        */
        frac sum;
        for (int i = 0; i < n; i++) {
            sum = sum + fracs[i];
        }
        return sum;
    }

    void sortFracs(frac fracs[], int n) {
    /*
    Ordena vetor de frações de entrada. 
    */
    int z = 0;

loop:
    for (int i = z; i < n; i++) {
        if (fracs[0 + z] > fracs[i] && i != 0) {
            frac temp = fracs[0 + z];       
            fracs[0 + z] = fracs[i];
            fracs[i] = temp;
        }        
    }

    z++;

    if (z != n)
        goto loop;
}

}


#include <iostream>

using std::cout, std::endl;

int main()
{
    aluno::frac * fracs = aluno::loadFracs("9 : 4/8 1/2 3/1 4/1 5/1 6/16 7/1 81/1 9/12");
    aluno::sortFracs(fracs, 9);

    for (int i = 0; i < 9; i++)
    {
        cout << fracs[i].getNum() << " / " << fracs[i].getDen() << endl;
    }

    aluno::frac sum = aluno::sumFracs(fracs, 9);

    cout << "sum: " << sum.getNum() << "/" << sum.getDen() << endl;

    return 0;
}
