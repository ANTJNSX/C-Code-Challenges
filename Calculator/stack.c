/*
* Author: Anton Jonsson
* This is a calculator in C using Polish notation and a stack implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

typedef struct {
    int top;
    int inp_array[SIZE];
} Stack;

int addition(int x1, int x2);
int subt(int x1, int x2);
int multi(int x1, int x2);
float divi(int x1, int x2);

void push(Stack* stack, int element);
int pop(Stack* stack);
void show(Stack* stack);
int isOperator(char c);

int main() {
    return 0;
}

int isOperator(char c) {
    switch(c) {
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 1;
            break;
        case '/':
            return 1;
            break;
        
        default:
            return 0;
            break;
   }

}

    // math operations
int addition(int a, int b) {
    return a + b;
}

int subt(int a, int b) {
    return a - b;
}

int multi(int a, int b) {
    return a * b;
}

float divi(int a, int b) {
    return a / b;
}

    // Start of stack functions
void push(Stack* stack, int element) {
    if (stack->top == SIZE - 1) {
        printf("\nOverflow!!");
    } else {
        stack->top = stack->top + 1;
        stack->inp_array[stack->top] = element;
    }
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("\nUnderflow!!");
        return -1; // or any suitable value to indicate underflow
    } else {
        int poppedValue = stack->inp_array[stack->top];
        // printf("%d", poppedValue);
        stack->top = stack->top - 1;
        return poppedValue;
    }
}

void show(Stack* stack) {
    if (stack->top == -1) {
        printf("\nUnderflow");
    } else {
        printf("\nElements present in the stack: \n");
        for (int i = stack->top; i >= 0; --i)
            printf("%d\n", stack->inp_array[i]);
    }
}


