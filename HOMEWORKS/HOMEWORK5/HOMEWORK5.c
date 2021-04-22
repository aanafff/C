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
   
    printf("\tINSTRUCTIONS:\nENTER A ROW AND COLUMN\n");
    printf("i.e: \"4B\" or \"B4\"\nENTER A LOCATION + \"m\"\n");
    printf("i.e: \"8CM\" \"MC8\" \"8MC\"\nREPEAT TO REMOVE\n\n");
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
            printf("\nYOU LOST\n");
            break;
        }
    } while((c = open()) != EOF && c != WON);
        
    return 0;
}
