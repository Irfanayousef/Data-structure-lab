 #include <stdio.h>
#include <stdlib.h>

#define clrscr() // fixed empty macro with semicolon removed

// fixed struct syntax: spacing and semicolon
struct bit {
    unsigned char x : 1;
};

int uset[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, size = 9;

void readset(struct bit[], int);
void printset(struct bit[]);
void unionset(struct bit[], struct bit[], struct bit[]);
void intersect(struct bit[], struct bit[], struct bit[]);
void difference(struct bit[], struct bit[], struct bit[]);

void main() {
    struct bit a[10] = {0}, b[10] = {0}, c[10] = {0};
    int n;

    printf("number of elements in set A: ");
    scanf("%d", &n);
    readset(a, n);

    printf("number of elements in set B: ");
    scanf("%d", &n);
    readset(b, n);

    clrscr(); // does nothing now

    printf("Set A: ");
    printset(a);

    printf("Set B: ");
    printset(b);

    unionset(a, b, c);
    printf("A U B = "); // fixed 'print' to 'printf'
    printset(c);

    intersect(a, b, c);
    printf("A ∩ B = ");
    printset(c);

    difference(a, b, c);
    printf("A - B = ");
    printset(c);
}

void readset(struct bit a[], int n) {
    int i, x, k;
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        for(k = 0; k < size; k++) {
            if(uset[k] == x) {
                a[k].x = 1;
                break;
            }
        }
    }
    return;
}

void printset(struct bit a[]) {
    int k;
    printf("{"); // fixed typo
    for(k = 0; k < size; ++k) {
        if(a[k].x == 1)
            printf("%d ", uset[k]); // added space for formatting
    }
    printf("}\n");
    return;
}

void unionset(struct bit a[], struct bit b[], struct bit c[]) {
    int k;
    for(k = 0; k < size; ++k)
        c[k].x = a[k].x | b[k].x;
    return;
}

void intersect(struct bit a[], struct bit b[], struct bit c[]) {
    int k;
    for(k = 0; k < size; ++k)
        c[k].x = a[k].x & b[k].x;
    return;
}

// removed extra semicolon in function header
void difference(struct bit a[], struct bit b[], struct bit c[]) {
    int k;
    for(k = 0; k < size; ++k)
        if(a[k].x == 1)
            c[k].x = a[k].x ^ b[k].x;
        else
            c[k].x = 0; // ensure unset values are 0
    return;
}

