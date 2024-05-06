#include <iostream>

class Range {
private:
    int first;
    int last;

public:
    Range(int s, int f) : first(s), last(f) {}

    bool contains(int value) {
        return first < value < last;
    }
    
    int size() {
        return last - first;
    }

    class Iterator {
    private:
        int current;

    public:
        Iterator(int first) : current(first) {}

        int operator*() const {
            return current;
        }

        Iterator& operator++() {
            ++current;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() const {
        return Iterator(first);
    }

    Iterator end() const {
        return Iterator(last + 1); // Incrementamos el límite para indicar el final del rango
    }
};

int main() {
    for (int i : Range(1, 10)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
