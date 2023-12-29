#include <stdio.h>

/*  handle order of operations with 2 stacks, work through the expression and only calc if pointers havent found a operation of higher importance. 
    */

#define MAX_SIZE 100

int main() {
    double numStack[MAX_SIZE];
    int numTop = -1;
    
    char opStack[MAX_SIZE];
    int opTop = -1;

    char* inp[10];
    
    printf("enter expression without spaces"); 
    scanf(inp);

    return 0;

}

