#include <stdio.h>

void function(int num) {
    printf("%d\n", num);
}

struct Test {
    Test* next = NULL;
    void (*fun_ptr)(int);
};

int main() {
    Test test;
    test.fun_ptr = function;

    test.fun_ptr(10);

}
