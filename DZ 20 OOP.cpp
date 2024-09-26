#include <iostream>

class Foo {
private:
    static int nextId;
    int id;

public:
    Foo() {
        id = nextId++;
        std::cout << "Foo " << id << " созданный" << std::endl;
    }

    ~Foo() {
        std::cout << "Foo " << id << " уничтожен" << std::endl;
    }
};

int Foo::nextId = 1;

int main() {
    setlocale(LC_ALL, "ru");
    // Глобальные переменные и массив
    Foo globalFoo;
    Foo globalFooArray[3];

    // Локальные и статические переменные и массивы
    {
        Foo localFoo;
        static Foo staticFoo;
        Foo localFooArray[2];
        static Foo staticFooArray[2];
    }

    try {
        std::cout << "Введите размер динамического массива: ";
        int N;
        std::cin >> N;

        if (N <= 0 || N > 1000000) {
            throw std::invalid_argument("Неверный размер массива");
        }

        Foo* dynamicArray = new Foo[N];

        // Освобождение динамической памяти
        delete[] dynamicArray;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}