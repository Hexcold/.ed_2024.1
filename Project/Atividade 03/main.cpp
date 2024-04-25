#include "atividade03.cpp"
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