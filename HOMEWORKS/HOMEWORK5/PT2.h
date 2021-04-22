//
//  PT2.h
//  HOMEWORK5
//
//  Created by Ana Ramirez on 21/04/21.
//

#ifndef PT2_h
#define PT2_h


#endif /* PT2_h */
#define forloop(i, x) for(i = 0; i != x; i++)
#define BOMB -1
#define AMBOMBS 15
#define CONTL 10 

#define LOST 'l'
#define WON 'O'
#define OK '?'

void bombs(void);
void neighbours(int);
int open(void);
void kaboom(void);
void empty(int, int);
