#include <stdio.h>

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue:       a = %d, b = %d\n", a, b);
}

void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Inside swapByReference:   *a = %d, *b = %d\n", *a, *b);
}

int main() {
    
    int num = 100;
    int *ptr = &num; 

    printf("=== Pointer Demonstration ===\n");
    printf("Value of num:                 %d\n", num);
    printf("Address of num (&num):        %p\n", (void*)&num);
    printf("Pointer ptr stores address:   %p\n", (void*)ptr);
    printf("Value accessed via *ptr:      %d\n\n", *ptr);

  
    int x = 10, y = 20;
    printf("=== Call by Value Demonstration ===\n");
    printf("Before swapByValue:          x = %d, y = %d\n", x, y);
    swapByValue(x, y);
    printf("After swapByValue in main:   x = %d, y = %d (Unchanged)\n\n", x, y);

    
    int m = 10, n = 20;
    printf("=== Call by Reference Demonstration ===\n");
    printf("Before swapByReference:        m = %d, n = %d\n", m, n);
    swapByReference(&m, &n); // Passing addresses of variables
    printf("After swapByReference in main: m = %d, n = %d (Swapped)\n", m, n);

    return 0;
}