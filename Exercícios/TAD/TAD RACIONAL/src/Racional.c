#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/Racional.h"

struct rac {
    int a;
    int b;
};

Racional* rac_cria(int x, int y) {
    Racional* r = (Racional*) malloc(sizeof(Racional));
    r->a = x;
    r->b = y;
    return r;
}
