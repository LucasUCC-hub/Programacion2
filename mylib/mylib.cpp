#include "mylib.h"

float RNG::random(float seed) {
    return sin(floor(seed / 42314) * 6542);
}