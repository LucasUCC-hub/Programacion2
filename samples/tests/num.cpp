#include <iostream>

template <class T>
T max(T a, T b) {
    return a > b ? a : b;
};

template <class T>
T min(T a, T b) {
    return a < b ? a : b;
};

// Numero multiplicado por 10 elevado a la E expoexpNnte
class expN {
private:
    float n;
    int e;
public:
    expN(float num, int dec_exp);
    expN(float num);
    expN operator+(expN num);
    expN operator-(expN num);
    expN operator*(expN num);
    expN operator/(expN num);

    friend std::ostream& operator<<(std::ostream& os, const expN& obj);
};

expN::expN(float num, int dec_exp) : n(num), e(dec_exp) {}

expN::expN(float num) : n(num), e(1) {}

expN expN::operator*(expN num) {
    this->e += num.e;
    this->n *= num.n;
    return *this;
}

expN expN::operator+(expN num) {
    if (num.e == 1)
    float c = min(this->e, num.e)
    return c*(this->n + );
}

std::ostream& operator<<(std::ostream& os, const expN& obj) {
    os << obj.n << "E" << obj.e;
    return os;
}

int main() {
    std::cout << expN(2, 30) * expN(3, 10);
}