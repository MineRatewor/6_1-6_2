#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;

template<typename T>
class Vector {
private:
    T* arr;
    int s;
    int c;
public:
    Vector() {
        s = c = 0;
    }

    Vector(int num) {
        s = c = num;
        arr = new T[s];
    }
    //конструктор копирования
    Vector(const Vector& arr2) {
        s = arr2.s;
        c = arr2.c;
        T* tmp = new T[s];
        for (int i = 0; i < s; i++) {
            tmp[i] = arr2.arr[i];
        }
        delete[] arr;
        arr = tmp;
    }

    Vector& operator=(const Vector& arr2) {
        if (this != &arr2) {
            delete[] arr;
            s = arr2.s;
            c = arr2.c;
            T* tmp = new T[s];
            for (int i = 0; i < s; i++) {
                tmp[i] = arr2.arr[i];
            }
            arr = tmp;
        }
        return *this;
    }
    // конструктор перемещений 
    Vector(Vector&& arr2) : arr(arr2.arr),
        s(arr2.s),
        c(arr2.c) {

        arr2.s = 0;
        arr2.c = 0;
    }

    Vector& operator=(Vector&& arr2)
    {
        if (this != &arr2) {
            delete[] arr;
            s = arr2.s;
            c = arr2.c;
            arr = arr2.arr;
            arr2.arr = nullptr;
            arr2.s = 0;
            arr2.c = 0;
        }
        return *this;
    }

    void new_allocation() {
        c = s + 5;
        T* temp = new T[c]();


        for (int i = 0; i < s; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;

    }
    void push_back(T element) {
        if (s == c) {
            new_allocation();
        }
        arr[s] = element;
        s++;
    }


    void pop_back() {
        if (s == 0) {
            cout << "Can't pop, because vector is empty!" << endl;
            return;
        }
        s--;
    }

    int size() {
        return s;
    }

    void insert(int index, T data) {
        if (s == c) {
            new_allocation();
        }
        s++;
        T* tmp = new T[s];
        int k = 0;
        for (int i = 0; i < s; i++) {
            if (i == index) {
                tmp[i] = data;
                continue;
            }
            tmp[i] = arr[k];
            k++;
        }
        delete[] arr;
        arr = tmp;
    }

    void pop(int index) {
        if (s == 0) {
            cout << "Can't pop, because vector is empty!" << endl;
            return;
        }
        s--;
        T* temp1 = new T[s];
        int k = 0;
        for (int i = 0; i < s; i++) {
            if (index == i) {
                k++;
            }
            temp1[i] = arr[k];
            k++;
        }
        delete[] arr;
        arr = temp1;

    }

    void print() {
        for (int i = 0; i < s; i++) {
            cout << setw(3) << arr[i];
        }
        cout << endl;

    }

    void clear() {
        s = c = 0;
        T* tmp = new T[s];
        delete[] arr;
        arr = tmp;
    }

    bool empty() {
        if (s == 0) {
            return true;
        }
        return false;
    }

    T& operator[](int index) {
        return arr[index];
    }
    ~Vector() {
        delete[] arr;
    }
};

int main() {
    Vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(4);
    Vector<int> arr1 = move(arr);
    arr1.print();

    return 0;
}
