//
//  main.c
//  HOMEWORK3
//
//  Created by Ana Ramirez on 10/03/21.
//
#include <stdio.h>
#define TRUE 1
#define FALSE 0
int main() {
    printf ("Write something\n");

  int c, number = FALSE, parenthesis = FALSE, quotes = FALSE;
  while ((c = getchar()) != EOF) {
      switch(c){
              

case '(':
          parenthesis=TRUE;
          putchar(c);
          break;
case ')':
          parenthesis=FALSE;
          putchar(c);
          break;
case '{':
          parenthesis=TRUE;
          putchar(c);
          break;
case '}':
          parenthesis=FALSE;
          putchar(c);
          break;
case '>':
          parenthesis=TRUE;
          putchar(c);
          break;
case '<':
          parenthesis=FALSE;
          putchar(c);
          break;
case '[':
          parenthesis=TRUE;
          putchar(c);
          break;
case ']':
          parenthesis=FALSE;
          putchar(c);
          break;
case ';':
          putchar(c);
          quotes++;
          break;

case ':':
          putchar(c);
          quotes++;
          break;
default:
        if(c!='.'&&c!=':'&&c!='\?'&&c!='!'&&c!='-'&&c!=';'&&c!='_'){
            if (parenthesis==TRUE||quotes==TRUE){
            putchar(c);
            }
            else{
            if (quotes==2){
                    quotes=0;
                }
            if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0'){
                    number++;
            }else{
                  number=0;
                }
            if (number==1){
                    putchar('X');
                }
            if (number==0){
                    putchar(c);
                }
            }
        }




        }
    }


    return 0;
  }

//In collab with Aneth Rodriguez
