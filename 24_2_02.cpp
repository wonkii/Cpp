int main() {

/*
class A {
	int a;
public:
	A(int a = 0) : a(a) {}
	void Print() const {
		std::cout << a << ' ';
	}
};
*/

    std::cout << "### 1 ###" << std::endl;

    // 1. �Ʒ��� ������ �����ϴ� A Ŭ������ �����϶�.

    // 1���� ������ ���(data member, private ���� ������ x)�� ������.

// 1���� ������(constructor, x�� �ʱ�ȭ), 1���� Print ��� �Լ�(member function, x ���)�� ������.

// ������� ���� ����� �߰��� �� ����.

    const A a1, a2{ 5 }, a3{ 10 };

    a1.Print();

    a2.Print();

    a3.Print();

    std::cout << '\n';

    // ���: 0 5 10



    /*
    class B {
        int x;
    public:
        B(int x = 0) :x(x) {}
        int GetX() const {
            return x;
        }
        const class B& operator +(const class B& b) const {
            return B(this->GetX() + b.GetX());
        }
    };

    std::ostream& operator << (std::ostream & os, const class B& b) {
        os << b.GetX();
        return os;
    }
    */
    std::cout << "\n### 2 ###" << std::endl;

    // 2. �Ʒ��� ������ �����ϴ� B Ŭ������ ����(non-member) ������(<<)�� �����϶�.

    // 1���� ������ ���(private ���� ������ x)�� ������.

    // 1���� ������(x�� �ʱ�ȭ), GetX ��� �Լ�(x�� ��ȯ)�� + ��� ������(x�� ���� ��ü�� ��ȯ)�� ������.

    // ���� ������(<<)�� x�� ����ϸ� friend�� ������ �� ����.

    // ������� ���� ����� �߰��� �� ����.

    B b1;

    const B b2(5), b3(10);

    b1 = b2 + b3;

    std::cout << b1 << ' ' << b2 << ' ' << b3 << '\n'; // ���: 15 5 10



    /*
#include <iostream>

class C {
    int n1, n2;
public:
    C(int n1=0, int n2=0): n1(n1), n2(n2){}
    operator int() const { return n1 + n2; }
};
*/

    std::cout << "\n### 3 ###" << std::endl;

    // 3. �Ʒ��� ������ �����ϴ� C Ŭ������ �����϶�.

    // 2���� ������ ���(private ���� ������ n1, n2)�� ������.

    // 1���� ������(n1�� n2�� �ʱ�ȭ)�� 1���� ����ȯ(int) ��� ������(n1+n2�� ��ȯ)�� ������.

    // �Ʒ� ����� ����ȯ �����ڰ� ���ǵǾ� ������ ��ȯ(implicit conversion)���� ��µȴ�.

    // ������� ���� ����� �߰��� �� ����.

    C c1, c2(5), c3(1, 2);

    std::cout << c1 << ' ' << c2 << ' ' << c3 << '\n';    	// ���: 0 5 3




    /*
    #include <iostream>
#include <vector>

class Base {
    int x;
public:
    Base(int x = 0):x(x){}
    virtual int Get() const {
        return x;
    }
};

class Derived :public Base {
    int y;
public:
    Derived(int x = 0, int y = 0): y(x+y){}
    int Get() const {
        return y;
    }
};
*/
    std::cout << "\n### 4 ###" << std::endl;

    // 4. �Ʒ��� ������ �����ϴ� Base�� Derived Ŭ������ �����϶�.

    // Base Ŭ������ 1���� ������ ���(private ���� ������ x)�� ������.

    // Base Ŭ������ 1���� ������(x�� �ʱ�ȭ)�� �� ���� ��� �Լ�(Get)�� ������.

    // Base Ŭ������ Get �Լ��� x�� ��ȯ�Ѵ�.

    // Derived Ŭ������ Base Ŭ������ �Ļ� Ŭ����(derived class)�̴�.

    // Derived Ŭ������ 1���� ������ ���(private ���� ������ y)�� ������.

    // Derived Ŭ������ 1���� ������(x, y�� �ʱ�ȭ)�� 1���� ��� �Լ�(Get)�� ������.

    // Derived Ŭ������ Get �Լ��� x�� y�� ���� ��ȯ�Ѵ�.

    // ������� ���� ����� �߰��� �� ����.

    const std::vector<Base> v1 = { Base(), Base(2) };

    const std::vector<Derived> v2 = { Derived(), Derived(3), Derived(2, 5) };

    for (const Base& b : v1)

        std::cout << b.Get() << ' '; // ���: 0 2

    std::cout << '\n';



    for (const Base& d : v2)

        std::cout << d.Get() << ' ';  // ���: 0 3 7

    std::cout << '\n';

    /*
    #include <iostream>

template<typename T>
class E {
	T x, y, mean;
public:
	E(T x=0, T y=0):x(x), y(y), mean((x+y)/2){}
	void Print() const{
		std::cout << x << ' ' << y << ' ' << mean << std::endl;
	}
};

template<>
void E<char>::Print() const {
	std::cout << static_cast<int>(x) << ' '
		<< static_cast<int>(y) << ' '
		<< static_cast<int>(mean) << std::endl;
}
*/

    std::cout << "\n### 5 ###" << std::endl;

    // 5. �Ʒ��� ������ �����ϴ� E Ŭ���� ���ø��� �����϶�.

    // E Ŭ���� ���ø��� 3���� ������ ���(private ���� ������ x, y, mean)�� ������.

    // E Ŭ������ 1���� �����ڿ� 1���� Print ��� �Լ��� ������.

    // �����ڴ� x, y�� �Ķ���ͷ� �ʱ�ȭ�ϰ�, x�� y�� ����� mean�� �����Ѵ�.

    // Print �Լ��� x, y, mean�� ������� ����Ѵ�.

    // x, y, mean�� char Ÿ���� ��쿡�� ���� ������ ��µǵ��� explicit specialization �Ѵ�.

    // auto �� ǥ�� �Լ��� ����� �� ����.

    // ������� ���� ����� �߰��� �� ����.

    E<int> e1(10, 20), e2;

    E<double> e3(20.2);

    E<char> e4('A', 'C'); // 'A'�� ASCII 65, 'C'�� ASCII 67



    e1.Print(); // ���: 10 20 15

    e2.Print(); // ���: 0 0 0

    e3.Print(); // ���: 20.2 0 10.1

    e4.Print(); // ���: 65 67 66

    std::cout << '\n';



    /* Iterator ����
    template<typename T>
void Fn1(T startIndex, T endIndex) {
    for (T iter = startIndex; iter != endIndex; iter++) {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;
}
*/
    std::cout << "\n### 6 ###" << std::endl;

    // 6. �Ʒ��� ������ �����ϴ� Fn1 �Լ� ���ø��� �����϶�.

    // Fn1 �Լ��� �Ʒ��� ��°� ���� container�� ��� ��Ҹ� ����Ѵ�.

    // auto �� ǥ�� �Լ��� ����� �� ����.

    // �ִ��� �����ϰ�, �ݺ����� iterator�� ����� std::cout�� ����Ѵ�.

    // �߰������� 1���� instance�� ���� �� �ִ�.

    std::vector<int> x1{ 1, 2, 3, 4 };

    std::vector<double> x2{ 1.5, 2.3, 3.2 };

    std::list<int> x3{ 4, 7, 3, 2 };

    Fn1(x1.begin(), x1.end()); // ���: 1 2 3 4

    Fn1(x2.begin(), x2.end()); // ���: 1.5 2.3 3.2

    Fn1(x3.begin(), x3.end()); // ���: 4 7 3 2

    std::cout << '\n';


/*
    #include <iostream>
#include <vector>
#include <list>

void Fn2(std::vector<int>& v) {
    v.erase(std::remove_if(v.begin(), v.end(), [](const int a) {return a < 0; }), v.end());
}
*/
    std::cout << "\n### 7 ###" << std::endl;

    // 7. �Ʒ��� ������ �����ϴ� Fn2 �Լ��� �����϶�.

    // Fn2 �Լ��� std::vector<int>���� 0���� ���� ��Ҹ� �����Ѵ�.

    // Fn2 �Լ��� std::vector<int>.erase, std::remove_if�� 1���� ����� lambda �Լ��� ����Ѵ�.

    // �ִ��� �����ϰ�, �Լ��� body�� 1�ٷ� �ۼ��Ѵ�.

    std::vector<int> z{ 1, 4, -2, 0, 8, -4, 7 };



    for (const auto& e : z)

        std::cout << e << ' '; // ���: 1 4 -2 0 8 -4 7

    std::cout << '\n';

    Fn2(z);

    for (const auto& e : z)

        std::cout << e << ' ';    	// ���: 1 4 0 8 7

    std::cout << '\n';

}