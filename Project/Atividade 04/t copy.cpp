

class Vetor {
    int *u; 
    int size {0};
public:

    Vetor(int n) {
        u = new int[n];
        size = 0;
    }
    ~Vetor() { 
        delete [] u; 
    }

    int& operator[] (int k) {
        return u[k];
    } 

    int len() { return size; }

    Vetor(std::initializer_list<int> v) {
        u = new int[v.size()];
        size = 0;
        for (int x : v) {
            this->push_back(x);
        }
    }

    Vetor(const Vetor& V) {
        u = new int[V.size];
        size = V.size;
        for (int i = 0; i < size; i++) {
            u[i] = V.u[i];
        }
    }

    bool empty() {
        return size == 0;
    } 

    int back() {
        return u[size - 1];
    }

    void pop_back() {
        size--;
    }

    void push_back(int x) {
        u[size] = x;
        size++;
    }

    std::string str() {
        std::string s = "[";
        for (int i = 0; i < size; i++) {
            s += i == 0 ? "" : ",";
            s += std::to_string(u[i]);
        }
        s += "]";
        return s;
    }

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

inline int ind_menor_primeiro(Vetor U[], int n, Vetor ind) {
    int menor = -1;
    for (int i = 0; i < n; i++) {
        if (ind[i] < U[i].len()) {
            if (menor == -1 || U[i][ind[i]] < U[menor][ind[menor]]) {
                menor = i;
            }
        }
    }
    return menor;
}

inline Vetor mergeAll(Vetor U[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += U[i].len();
    }
    Vetor result(total);
    Vetor ind(n);
    for (int i = 0; i < n; i++) {
        ind.push_back(0);
    }
    while (true) {
        int index = ind_menor_primeiro(U, n, ind);
        if (index == -1) {
            break;
        }
        result.push_back(U[index][ind[index]]);
        ind[index]++;
    }
    return result; 
}



