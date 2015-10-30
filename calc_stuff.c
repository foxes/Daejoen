


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int fibonacci(int);
int square(int);

int
main()
{
    char line[82];
    int  n;
    
    for(;;){
    printf("Enter integer: ");
    fgets(line, sizeof line, stdin);

    n = atoi(line);
    
    if(n < 0)
        break;
        
    printf("F(%i): %i\n", n, fibonacci(n));
    printf("isqrt(%i): %i\n", n, square(n));
    printf("sqrt(%i): %f\n", n, sqrt(n));

    }
    
    puts("quitting");
}

int
fibonacci(int n)  // O(n log n)
{
    if (n == 0) { return 0;}
    else if (n == 1){return 1;}
    else {return(fibonacci(n -1) + fibonacci(n -2 ));}
}

int
square(int n)     //running time proportional to input size, so O(n)
{
    int b =0;
    while (n >= 0) {
        n = n - b;
        b = b + 1;
        n = n - b;
        
    }
    return b -1;
}
