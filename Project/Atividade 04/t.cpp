#define atividade "04"
#define nome "Henrique Lima Pires"
#define matricula "557176"

class Vetor {
    int *u;  // ponteiro para dados
    int size; // tamanho do vetor
public:
    // construtor base
    Vetor(int n) {
        u = new int[n];
        size = 0;
    }
    
    // destrutor
    ~Vetor() { 
        delete [] u; 
    }
    
    // retorna o tamanho do vetor por referência
    int& len() { return size; }

    // operador de acesso []
    int& operator[] (int k) {
        return u[k];
    } 

    // método push_back
    void push_back(int x) {
        u[size] = x;
        size++;
    }

    // método str para exibir o vetor como string
    std::string str() {
        std::string s = "[";
        for (int i = 0; i < size; i++) {
            s += i == 0 ? "" : ",";
            s += std::to_string(u[i]);
        }
        s += "]";
        return s;
    }

    // Método para verificar se dois vetores são iguais
    bool operator==(Vetor& V) {
        if (size != V.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (u[i] != V.u[i]) {
                return false;
            }
        }
        return true;
    }
};

// Função para encontrar o índice do vetor com o menor último elemento
inline int ind_menor_ultimo(Vetor U[], int n) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (U[i].len() == 0) {
            continue;
        }
        if (index == -1 || (U[i][U[i].len() - 1] < U[index][U[index].len() - 1])) {
            index = i;
        }
    }
    return index;
}

// Função para mesclar todos os vetores em um só
inline Vetor mergeAll(Vetor U[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += U[i].len();
    }
    Vetor result(total);
    
    while (true) {
        int index = ind_menor_ultimo(U, n);
        if (index == -1) {
            break;
        }
        result.push_back(U[index][U[index].len() - 1]);
        U[index].push_back(0); // Adicionando um elemento para manter a consistência do vetor
        U[index].len()--; // Removendo o último elemento
    }

    return result; 
}

int main() {
    // Teste dos métodos
    Vetor v1(4);
    std::cout << "Criando vetor com capacidade 4" << '\n';
    std::cout << "size: " << v1.len() << '\n';

    Vetor v2(4);
    std::cout << "Adicionando 1,2,3,0 usando push back" << '\n';
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(0);
    std::cout << "Esperado: [1,2,3,0]" << '\n';
    std::cout << "Recebido: " << v2.str() << '\n';

    std::cout << "Elemento 2: " << v2[2] << '\n';
    std::cout << "Mudando elemento 2 para 5" << '\n';
    v2[2] = 5;
    std::cout << "Esperado: [1,2,5,0]" << '\n';
    std::cout << "Recebido: " << v2.str() << '\n';

    Vetor v3(3);
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(3);
    std::cout << "Criando vetor com lista de inicialização {1,2,3}" << '\n';
    std::cout << "Esperado: [1,2,3]" << '\n';
    std::cout << "Recebido: " << v3.str() << '\n';

    Vetor v4 = v3;
    std::cout << "Criando vetor com cópia do anterior" << '\n';
    std::cout << "Esperado: [1,2,3]" << '\n';
    std::cout << "Recebido: " << v4.str() << '\n';

    Vetor v5(3);
    v5.push_back(4);
    v5.push_back(5);
    v5.push_back(1);
    Vetor v6(4);
    v6.push_back(4);
    v6.push_back(5);
    v6.push_back(1);
    v6.push_back(7);
    std::cout << "Fazendo v5 == v6" << '\n';
    std::cout << "Esperado: 0" << '\n';
    std::cout << "Recebido: " << (v5 == v6) << '\n';
    std::cout << "Fazendo pop_back em v6" << '\n';
    v6.push_back(0); // Adicionando um elemento para manter a consistência do vetor
    v6.len()--;
    std::cout << "Fazendo v5 == v6" << '\n';
    std::cout << "Esperado: 1" << '\n';
    std::cout << "Recebido: " << (v5 == v6) << '\n';

    Vetor va(3);
    va.push_back(6);
    va.push_back(8);
    va.push_back(5);
    Vetor vb(3);
    vb.push_back(3);
    vb.push_back(2);
    vb.push_back(1);
    Vetor vc(3);
    vc.push_back(4);
    vc.push_back(0);
    vc.push_back(9);
    Vetor vall[] = {va, vb, vc};
    Vetor result = mergeAll(vall, 3);
    std::cout << "Fazendo merge" << '\n';
    std::cout << "Esperado: [1,2,3,5,8,6,9,0,4]" << '\n';
    std::cout << "Recebido: " << result.str() << '\n';

    return 0;
}
