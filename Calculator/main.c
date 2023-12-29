#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*  handle order of operations with 2 stacks, work through the expression and only calc if pointers havent found a operation of higher importance. 
    */

#define MAX_SIZE 100

int precedence(char op);
void pushNum(double value);
double popNum();
void pushOp(char op);
char popOp();

double numStack[MAX_SIZE];
int numTop = -1;
char opStack[MAX_SIZE];
int opTop = -1;

int main() {

    char input[MAX_SIZE]; 
    
    printf("enter expression without spaces: "); 
    fgets(input, MAX_SIZE, stdin);

    // Loop over input
    for (int i = 0; input[i]; i++) {
        if (isdigit(input[i])) {
            
            // Read the entire number and push it onto the number stack
            double num = atof(input + i);
            pushNum(num);
            
            // Move the index to the end of the number
            while (isdigit(input[i]) || input[i] == '.') {
                i++;
            }
            i--; // Decrement to stay at the last digit

        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            // Handle operators based on precedence
            while (opTop >= 0 && precedence(opStack[opTop]) >= precedence(input[i])) {
                char op = popOp();
                double num2 = popNum();
                double num1 = popNum();
                if (op == '+') {
                    pushNum(num1 + num2);
                } else if (op == '-') {
                    pushNum(num1 - num2);
                } else if (op == '*') {
                    pushNum(num1 * num2);
                } else if (op == '/') {
                    pushNum(num1 / num2);
                }
            } // if it doesnt have precedence over the current opStack

            // Push the current operator onto the operator stack
            pushOp(input[i]);
        }
    } // End of input loop

    // Evaluate any remaining operators
    while (opTop >= 0) {
        char op = popOp();
        double num2 = popNum();
        double num1 = popNum();
        if (op == '+') {
            pushNum(num1 + num2);
        } else if (op == '-') {
            pushNum(num1 - num2);
        } else if (op == '*') {
            pushNum(num1 * num2);
        } else if (op == '/') {
            pushNum(num1 / num2);
        }
    }

    // The result is on the top of the number stack
    double result = popNum();
    printf("Result: %.2lf\n", result);  // Print rounded to 2 zeroes

    return 0;
}

// Function to get operator precedence value
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // For other characters or invalid operators
}

// Push an element onto the number stack
void pushNum(double value) {
    if (numTop < MAX_SIZE - 1) {
        numStack[++numTop] = value;
    }
}

// Pop an element from the number stack
double popNum() {
    if (numTop >= 0) {
        return numStack[numTop--];
    }
    return 0; // Handle underflow
}

// Push an operator onto the operator stack
void pushOp(char op) {
    if (opTop < MAX_SIZE - 1) {
        opStack[++opTop] = op;
    }
}

// Pop an operator from the operator stack
char popOp() {
    if (opTop >= 0) {
        return opStack[opTop--];
    }
    return '\0'; // Handle underflow
}

