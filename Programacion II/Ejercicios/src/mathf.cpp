#include "../include/mathf.h"

int min_steps(int from, int to, int step) {
    return (to - from) % step;
}