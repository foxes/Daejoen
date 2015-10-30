#include <stdio.h>
#include <string.h>

int main()
{
  
    char str[250], temp;
    int i, j = 0;
    
    
    while( fgets (str, 250, stdin)!=NULL )
    {
        
        i = 0;
        j = strlen(str) - 1;

        while (i < j) {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
            
        }
        
        printf("%s",str);
        
    }

    puts("\n");

}
