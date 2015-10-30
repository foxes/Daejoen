

#include <stdio.h>


int powers(int n)
{
    return (n < 0) || (powers(n-1) && printf("%8d\t%8d\t%9d\t%9d\t%9d\n", n, n*n, n*n*n, n*n*n*n, n*n*n*n*n));
}

int main(void)
{
    puts("\t\t\t::::: A TABLE OF POWERS ::::::");
    printf("%8s\t%8s\t%9s\t%9s\t%9s\n", "Integer", "Square", "3rd power", "4th power", "5th power");
    printf("%8s\t%8s\t%9s\t%9s\t%9s\n", "-------", "------", "---------", "---------", "---------");
    powers(20);
    
    return 0;

}
