//
//  main.c
//  HOMEWORK1
//
//  Created by Ana Ramirez on 24/02/21.
//
#include <stdio.h>
int main() {
    int c, i=0;
    char stro [13]={"strong/strong"};
    char scrip [13]={"script/script"};
    while((c = getchar()) != EOF)
    {
        if(c == '<')
        {
            while((c = getchar()) == stro[i]) {
        i++;
    }
          if(c == scrip[1]){
        c = getchar();
        if(c == scrip[2]){
            c = getchar();
            if(c == scrip [3]){
                while((c = getchar()) != '>'){
                    ;
                }
                while((c = getchar()) != '>'){
                ;
                }
            }
        }
    }
          if(i == 13){
        i=0;
    }
          while(c != EOF && c != '>'){
        c = getchar();
    }
          else if(i == 6 && i < 13){
        if(c == ' '){
            printf("_");
        }
        putchar(c);
    }
          if((i != 6 && c != '<' && c != '>')c == '\n'){
        putchar(c);
        i=0;
    }
        }
    }
}
