
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>



char c;
int lines;
int words;
int characters;
bool notblank = false;

char prev = '\n';

int
main()
{
    
        while ((c = getchar()) != EOF) {
         if (c == '\n') {
             lines++;
             
        }
         if (!isspace(c) && !notblank) {
             
             notblank = true;
             words++;
                
        }
          if (isspace(c) && notblank) {
                
              notblank = false;
              prev = c;
                
        }
    
        characters++;
        
    }
    
    printf("words:%d \n",words);
    printf("Lines:%d \n",lines);
    printf("Characters:%d \n",characters);
    
}
