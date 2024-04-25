#include <iostream>

class ArrayD
{
private:
    int *ptr;
    int count;
public:
    ArrayD(){
        int x[5];
        ptr = x;
        count = 0;
    }

    void jobson(int _x){
        if (count >= 5) {
            int y[count + 5];
            for (int i = 0; i < count; ++i) {
                y[i] = *(ptr + i);
            }
            ptr = y;
        }

        *(ptr + count) = _x;

        count++;

    }

};


int main() {
    ArrayD array;
    array.jobson(1);
    array.jobson(1);
    array.jobson(1);
    array.jobson(1);
    array.jobson(1);
    array.jobson(1);

}
