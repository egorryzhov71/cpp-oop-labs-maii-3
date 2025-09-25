#include "nod.h"
#include <cmath>
int calculateNOD(int a, int b) {
   
    if (a == 0 && b == 0) return 0;
    if (a == 0) return std::abs(b);
    if (b == 0) return std::abs(a);
    
    a = std::abs(a);
    b = std::abs(b);
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}