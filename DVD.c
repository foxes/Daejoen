#define alen(x) ((sizeof x) / (sizeof *x))

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char *movie_title;
    int minutes;
    float price;
} DVD;


void printarray(DVD[]);

char* skip_words(char* s)
{
    while(*s == ' ') s++;
    if(strncmp(s, "The ", 4)==0) s+=4;
    if(strncmp(s, "A ", 2)==0) s+=2;
    if(strncmp(s, "An ", 3)==0) s+=3;
    return s;
}

int tcomp (const void * a, const void * b)
{
    char* s1 = ((DVD*)a)->movie_title;
    char* s2 = ((DVD*)b)->movie_title;
    s1 = skip_irrelvant(s1);
    s2 = skip_irrelvant(s2);
    
    return strcmp(s1, s2);
}

int lcomp (const void * a, const void * b)
{
    const int* s1 = &((DVD*)a)->minutes;
    const int* s2 = &((DVD*)b)->minutes;
    
    return *s2 - *s1; //* swap *s2 and *s1 to sort length in ascending order *//
}

int ccomp (const void * a, const void * b)
{
    const float* s1 = &((DVD*)a)->price;
    const float* s2 = &((DVD*)b)->price;
    
    return *s1 - *s2;
}

int
main()
{
    DVD movies[10] = {
        { "Drive", 153, 14.99},
        { "Only God Forgives", 126, 12.99},
        { "Melancholia", 141, 9.99},
        { "Dogville", 126, 9.99},
        { "Europa", 87, 7.99},
        { "The Prestige", 114, 12.99},
        { "Shame", 104, 12.99},
        { "The Imitation Game", 121, 14.99},
        { "Blue Valentine", 106, 14.99},
        { "Ex Machina", 124, 19.99},
    };
    
    
    
    
    printf("%32s \n","unsorted ");
    printf("%20s %9s %9s\n", "Title", "Minutes", "price");
    printf("%20s %9s %9s\n", "-------", "---------", "---------");
    for (int i = 0; i < alen(movies); i++)
        printf("%20s %9d %9g\n", movies[i].movie_title, movies[i].minutes, movies[i].price);
    
    printf("\n random pieces: %s %d %g \n \n", movies[1].movie_title, movies[2].minutes, movies[3].price);
    
   
    
    
    qsort(movies, alen(movies), sizeof *movies, tcomp);
    
    printf("%32s \n", "title (A-Z)");
    printf("%20s %9s %9s\n", "Title", "Minutes", "price");
    printf("%20s %9s %9s\n", "-------", "---------", "---------");
    for (int i = 0; i < alen(movies); i++)
        printf("%20s %9d %9g\n", movies[i].movie_title, movies[i].minutes, movies[i].price);
    
    qsort(movies, alen(movies), sizeof *movies, lcomp);
    
    printf("%34s \n","length (Descending)");
    printf("%20s %9s %9s\n", "Title", "Minutes", "price");
    printf("%20s %9s %9s\n", "-------", "---------", "---------");
    for (int i = 0; i < alen(movies); i++)
        printf("%20s %9d %9g\n", movies[i].movie_title, movies[i].minutes, movies[i].price);
    
    qsort(movies, alen(movies), sizeof *movies, ccomp);
    
    printf("%34s \n","price (Ascending)");
    printf("%20s %9s %9s\n", "Title", "Minutes", "price");
    printf("%20s %9s %9s\n", "-------", "---------", "---------");
    for (int i = 0; i < alen(movies); i++)
        printf("%20s %9d %9g\n", movies[i].movie_title, movies[i].minutes, movies[i].price);
    
    
}


