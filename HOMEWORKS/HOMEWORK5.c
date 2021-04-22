//
//  main.c
//  HOMEWORK5
//
//  Created by Ana Ramirez on 21/04/21.
//
#include <stdio.h>
#include "PT2.h"

int main()
{
    
    extern char hash[CONTL][CONTL];
    int pos, lett, c;
    int flag = 1, i, a, b;
    
    bombs();
    forloop(i, CONTL*CONTL)
        neighbours(i);
    forloop(i, CONTL*CONTL)
        hash[i/10][i%10] = '#';
   
    printf("\tHow to play:\nEnter the number and row of the coloumn to open it\n");
    printf("Example: \"c3\" or \"3c\"\nTo set a flag enter the location + \"m\"\n");
    printf("Example: \"8dm\" \"md8\" \"8md\"\nAnd to remove it do it again\n\n");
    do { //prints board
        for(lett = 'A', i = 0; i != CONTL; i++, lett++)
        (void)(printf("\t %c", lett)), flag = 1;
        for(pos = 0; pos != 100; pos++) {
            flag ? printf("\n      ") : printf("\n     |");
            for(lett = 0; lett != CONTL; lett++)
                flag ? printf("_______ ") : printf("_______|");
            flag = 0;
            printf("\n     |");
            forloop(i, CONTL)
                printf("       |");
            printf("\n%2i   |", (pos/CONTL)+1);
            do {
                (void)(a = pos/10), b = pos%10;
                hash[a][b] == '-' ? printf("  -1   |") : printf("   %c   |", hash[a][b]); 
                pos++;
            } while((pos%CONTL) != 0);
            pos--;
        }
        printf("\n     |");
        forloop(i, CONTL)
            printf("_______|");
        printf("\n");
        if(c == LOST) {
            printf("\nYou lost!\n");
            break;
        }
    } while((c = open()) != EOF && c != WON);
        
    return 0;
}
