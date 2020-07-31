#include<stdio.h>

int fib(int k, int x, int y) {
    if(k == 0)
    {
        return x;
    }
    else
    {
        return fib(k-1, y, x+y);
    }
}

int main(int argc, char** argv) {
    int result = fib(10,0,1);
    printf("result: %d \n", result);

}