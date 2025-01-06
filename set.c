#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

struct bit {
    unsigned char x : 1;  // 1 bit
};

int uset[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void readset(struct bit[], int n);
void printset(struct bit[]);
void unionset(struct bit[], struct bit[], struct bit[]);
void interset(struct bit[], struct bit[], struct bit[]);
void difference(struct bit[], struct bit[], struct bit[]);

void main() {
    struct bit a[SIZE] = {0}, b[SIZE] = {0}, c[SIZE] = {0};
    int n;

    printf("Number of elements in set A:\n ");
    scanf("%d", &n);
    readset(a, n);

    printf("Number of elements in set B: \n");
    scanf("%d", &n);
    readset(b, n);

    printf("Set A = ");
    printset(a);
    printf("\nSet B = ");
    printset(b);

    unionset(a, b, c);
    printf("\nA U B = ");
    printset(c);

    interset(a, b, c);
    printf("\nA intersection B = ");
    printset(c);

    difference(a, b, c);
    printf("\nA - B = ");
    printset(c);
}

void printset(struct bit a[]) {
    int k;
    printf("{");
    for (k = 0; k < SIZE; ++k) {
        if (a[k].x == 1) {
            printf("%d,", uset[k]);
        }
    }
    printf("}\n");
}

void interset(struct bit a[], struct bit b[], struct bit c[]) {
    int k;
    for (k = 0; k < SIZE; ++k) {
        c[k].x = a[k].x & b[k].x;  // Bitwise AND for intersection
    }
}

void difference(struct bit a[], struct bit b[], struct bit c[]) {
    int k;
    for (k = 0; k < SIZE; ++k) {
        if (a[k].x == 1) {
            c[k].x = a[k].x & (~b[k].x);  // Bitwise AND with NOT for difference
        }
    }
}

void unionset(struct bit a[], struct bit b[], struct bit c[]) {
    int k;
    for (k = 0; k < SIZE; ++k) {
        c[k].x = a[k].x | b[k].x;  // Bitwise OR for union
    }
}

void readset(struct bit a[], int n) {
    int i, x, k;
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        for (k = 0; k < SIZE; ++k) {
            if (uset[k] == x) {
                a[k].x = 1;  // Mark the bit corresponding to the element as 1
                break;
            }
        }
    }
}

