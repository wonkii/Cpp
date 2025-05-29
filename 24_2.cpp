#include <iostream>
#include <vector>
#include <string>
/*
class A {
    double x;
public:
    A(double x = 0) : x(x) {
    }
    double GetX() const {
        return x;
    };
*/
/*
class B {
     double x;
public:
     B(double x = 0) : x(x) {}
     double GetX() const {
         return x;
     }
     void SetX(double x) {
         this ->x = x;
     }
};

std::ostream& operator<<(std::ostream& os, const B& object) {
    os << object.GetX();
    return os;
}
*/

/*
class C {
    std::string name;
    std::vector<double> score;
    double mean;

public:
    C(std::string name = "Anonymous", double s1 = 0, double s2 = 0) : name(name), score{ s1, s2 }, mean((s1+s2)/2) {}
   
    friend std::ostream& operator<<(std::ostream& os, const C& object);
};
std::ostream& operator<<(std::ostream& os, const C& object) {
    os << object.name<< ' ' << object.score[0] << ' ' << object.score[1] << ' ' << object.mean;
    return os;
}*/

/*
class Base {
    int x;
public:
    Base(int x=0): x(x){}
    virtual int Get()const {
        return x;
    }
};

class Derived:public Base {
    int y;
public:
    Derived(int x=0, int y=0): Base(x), y(y) {}
    int Get() const {
        int sum = Base::Get() + y;
        return sum;
    }
};

std::ostream& operator<<(std::ostream& os, const class Base& b) {
    os << b.Get();
    return os;
}
*/
/*
template <typename T, int C>
class Data {
    std::vector<T> v;
public:
    Data() :v(C) {}

    void Print() const {
        for (const T& e : v) {
            std::cout << e << ' ';
        }
    }
    T Size() const {
        return C;
    }
    void Set(int index, T givenValue) {
        v[index] = givenValue;
    }
};
*/
int main() {
    
    std::cout << "### 1 ###" << std::endl;
    const A a1, a2{ 10. }, a3{ 12.5 };
    std::cout << a1.GetX() << ' ' << a2.GetX() << ' ' << a3.GetX() << '\n';
    // ���: 0 10 12.5

    std::cout << "\n### 2 ###" << std::endl;

    // 2. �Ʒ��� ������ �����ϴ� B Ŭ������ ����(non-member) ������(<<)�� �����϶�.
    const B b1, b2(10);
    B b3;
    b3.SetX(5);

    std::cout << b1 << ' ' << b2 << ' ' << b3 << '\n';

    // ���: 0 10 5

    
    
    std::cout << "\n### 3 ###" << std::endl;

    // 3. �Ʒ��� ������ �����ϴ� C Ŭ������ ���� ������(<<)�� �����϶�.

    // 1���� ������(name, score, mean�� �ʱ�ȭ)�� ������.

    // ���� ������(<<)�� �Ʒ��� ���� ���� ����� ����ϸ� friend�� ����Ѵ�.

    // ������� ���� ����� �߰��� �� ����.

    C c1, c2("Thomas", 84), c3("Sophia", 90.5, 75.4);

    std::cout << c1 << ' ' << c2 << ' ' << c3 << '\n';

    // ���: Anonymous 0 0 0 Thomas 84 0 42 Sophia 90.5 75.4 82.95

    /*

    std::cout << "\n### 4 ###" << std::endl;

    // 4. �Ʒ��� ������ �����ϴ� Base/Derived Ŭ������ ���� ������(<<)�� �����϶�.

    // Base Ŭ������ 1���� ������ ���(private ���� ������ x)�� ������.

    // Base Ŭ������ 1���� ������(x�� �ʱ�ȭ)�� 1���� ��� �Լ�(Get)�� ������.

    // Base Ŭ������ Get �Լ��� x�� ��ȯ�Ѵ�.

    // Derived Ŭ������ Base Ŭ������ �Ļ� Ŭ����(derived class)�̴�.

    // Derived Ŭ������ 1���� ������ ���(private ���� ������ y)�� ������.

    // Derived Ŭ������ 1���� ������(x, y�� �ʱ�ȭ)�� 1���� ��� �Լ�(Get)�� ������.

    // Derived Ŭ������ Get �Լ��� x�� y�� ���� ��ȯ

    // ���� ������(<<)�� 1���� ���ǵǸ� �Ʒ��� ���� ���� ��µȴ�.

    // ������� ���� ����� �߰��� �� ����.

    const std::vector<Base> v1 = { Base(), Base(2) };

    const std::vector<Derived> v2 = { Derived(), Derived(3), Derived(2, 5) };

    for (const Base& b : v1)

        std::cout << b << ' '; // ���: 0 2

    std::cout << '\n';

    for (const Base& b : v2)

        std::cout << b << ' '; // ���: 0 3 7

    std::cout << '\n';



    std::cout << "\n### 5 ###" << std::endl;

    // 5. �Ʒ��� ������ �����ϴ� Data Ŭ���� ���ø��� �����϶�.

    // Data Ŭ���� ���ø��� 1���� std::vector Ÿ���� ������ ���(private ���� ������ v)�� ������.

    // Data Ŭ������ 1���� �����ڿ� 3���� ��� �Լ�(Print, Size, Set)�� ������.

    // Data Ÿ���� �ν��Ͻ� �������� 2���� �μ�(argument)�� �ʿ��ϴ�.

    // - ù���� argument�� v�� element type�̰� �ι�° argument�� v�� size�̴�.

    // Print �Լ��� v�� �� ��Ҹ� ����Ѵ�.

    // Size �Լ��� v�� size�� ��ȯ�Ѵ�.

    // Set �Լ��� v�� index�� ����� ���� �����Ѵ�.

    // ������� ���� ����� �߰��� �� ����.

    Data<int, 3> d1;

    Data<double, 5> d2;



    for (int i = 0; i < d1.Size(); ++i)

        d1.Set(i, i);

    for (int i = 0; i < d2.Size(); ++i)

        d2.Set(i, i / 2.);



    d1.Print();	// ���: 0 1 2

    std::cout << '\n';

    d2.Print();	// ���: 0 0.5 1 1.5 2

    std::cout << '\n';



    std::cout << "\n### 6 ###" << std::endl;

    // 6. �Ʒ��� ������ �����ϴ� Fn1 �Լ��� �����϶�.

    // Fn1 �Լ��� 2���� parameter(f�� t)�� ������.

    // ��ȯ�Ǵ� �Լ��� f�� ����� t���� ũ�ų� ������ f�̸�, t���� ������ -f�� �Լ��̴�.

    // �ִ��� �����ϰ�, �Լ��� body�� 1���� return���� �ۼ��Ѵ�.

    auto f1 = [](double x) { return 2 * x; };

    auto f2 = [](double x) { return 3 * x * x + 3 * x - 15; };

    auto F1 = Fn1(f1, 0);

    auto F2 = Fn1(f2, 0);



    for (int x = -3; x <= 3; ++x)

        std::cout << F1(x) << ':' << f1(x) << ' ';

    // ���: 6:-6 4:-4 2:-2 0:0 2:2 4:4 6:6

    std::cout << '\n';

    for (int x = -3; x <= 3; ++x)

        std::cout << F2(x) << ':' << f2(x) << ' ';

    // ���: 3:3 9:-9 15:-15 15:-15 9:-9 3:3 21:21

    std::cout << '\n';



    std::cout << "\n### 7 ###" << std::endl;

    // 7. �Ʒ��� ������ �����ϴ� Fn2 �Լ��� �����϶�.

    // Fn2 �Լ��� 2���� parameter(v�� t)�� ������.

    // v�� second�� t���� ũ�ų� ���� ��Ҹ� �����Ѵ�.

    // Fn2 �Լ��� std::vector<...>.erase, std::remove_if�� 1���� lambda �Լ��� ����Ѵ�.

    // �ִ��� �����ϰ�, �Լ��� body�� 1�ٷ� �ۼ��Ѵ�.

    std::vector<std::pair<char, int>> v(10);

    srand((unsigned)time(nullptr));

    for (auto& e : v) {

        e.first = rand() % ('Z' - 'A' + 1) + 'A';

        e.second = rand() % 10;

    }

    for (const auto& e : v)

        std::cout << e.first << ':' << e.second << ' ';

    // ������ ��� // L:5 O:3 D:4 V:3 U:0 I:0 Q:8 J:4 R:0 Z:5

    std::cout << '\n';

    Fn2(v, 4);

    for (const auto& e : v)

        std::cout << e.first << ':' << e.second << ' ';

    // ���� ������ ��¿� ���� ���	// O:3 V:3 U:0 I:0 R:0
    */
}