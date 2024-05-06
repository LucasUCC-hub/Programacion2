#include "range.h"

Range::Range(int s, int f) : first(s), last(f) {}

bool Range::contains(int value) {
    return first < value && value < last;
}

int Range::size() {
    return last - first;
}

Range::Iterator::Iterator(int first) : current(first) {}

int Range::Iterator::operator*() const {
    return current;
}

Range::Iterator& Range::Iterator::operator++() {
    ++current;
    return *this;
}

bool Range::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

Range::Iterator Range::begin() const {
    return Range::Iterator(first);
}

Range::Iterator Range::end() const {
    return Range::Iterator(last + 1); // Incrementamos el límite para indicar el final del rango
}
