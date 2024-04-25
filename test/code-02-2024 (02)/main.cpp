    #include <iostream> //biblioteca 

    void swap(int & x, int & y) { //função para inverter as variaveis
        int t = x;
        x = y;
        y = t;
    }

    int main () {
        int x = 10;
        int &r = x; // o & é uma referencia
        std::cout << x << std::endl; // print
        std::cout << r << std::endl;

        int a = 2;
        int b = 3;
        swap(a,b); // chamada da função
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }