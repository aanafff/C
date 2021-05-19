//
//  main.c
//  CHESS_GAME
//
//  Created by Ana Ramirez on 12/05/21.
//

#include <stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<ctype.h>

int pwstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int pbstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
// NAMES OF THE TILES: BISHOP, PAWNS, ROOK, KING, QUEEN AND HORSE AS KNIGHT
char board[8][8] = {
                    { 'R' , 'H' , 'B' , 'K' , 'Q' , 'B' , 'H' , 'R' }, // 8x8 BOARD
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'h' , 'b' , 'k' , 'q' , 'b' , 'h' , 'r' }
                    };

void display(void);
void change( int , int , int , int ) ;
void pawn1(int , int ) ;
void rook(int , int ) ;
void horse(int , int ) ;
void bishop( int , int ) ;
void king( int , int ) ;
void queen( int , int ) ;
void pawn2( int , int ) ;
void player1(void);
void player2(void);
int check(int , int ) ;
int check2(int , int ) ;

// MAIN FUNCTION
int main()
{
int  x = 0 ;
char ch ;

    printf( "\n\tWELCOME TO ANAF'S CHESS GAME\n" ) ; // PRESENTATION
    getch();
    system( "cls" );

 do
 {
 x++;
 system( "cls" ) ;
 display();

// SECOND PLAYER'S TURN
 if( (x%2) == 0 )
 {
     player2();
 }
 // FIRST PLAYER'S TURN
 else
 {
     player1();
 }
 ch = getch();
}while( true ) ;

}

// METHOD THAT PRINTS THE BOARD
void display() //VOID PARAMETER
{
    int i , j , k ;

    printf( "\n" ) ;
    // PRINTS THE TOP ROW (WHERE NUMERBS ARE BEING DISPLAYED)
    for( i=0 ; i<8 ; i++ ) printf( "    %d" , i ) ; printf( "\n" ) ;

    // PRINTS THE -
    for( k=0 ; k<8 ; k++ )
    {
    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ; printf( "%d " , k ) ;

    // PRINTS THE ||
    for( j=0 ; j<8 ; j++ ) { printf( "|| %c " , board[k][j] ) ; }
    printf( "|| \n" ) ;
    }

    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ;

}

// METHOD THAT CHANGES TILE'S POSITION
void change( int r1 , int c1 , int r2 , int c2 )
{
    char temp ;
    temp = board[r1][c1] ;
    board[r1][c1] = board[r2][c2] ;
    board[r2][c2] = temp ;

}

// METHOD THAT HAS THE LOGIC FOR THE PAWN
void pawn( int r1 , int c1 ) // WHITE
{
    pwstatus[c1]++;

    printf( "AVAILABLE: \n" ) ;
   // SHOWS AVAILABLE EMPTY SPACES
   if( pwstatus[c1] == 1 )
    {
        if( board[r1+1][c1] == ' ' )
        printf( "%d%d , " , r1+1 , c1 );

        if( board[r1+2][c1] == ' ' )
        printf( "%d%d , " , r1+2 , c1 ) ;

    }
    else
    {
        // SHOWS TAKEN SPACES BY OTHER TOKENS; THESE TOKENS CAN BE CAPTURED BY YOURS
        if(board[r1+1][c1] == ' ' )
        printf( "%d%d , " , r1+1 , c1 ) ;

        if( check(r1+1 , c1+1) == 1 )
        printf( "%d%d* , " , r1+1 , c1+1 ) ;

        if( check(r1+1 , c1-1) == 1 )
        printf( "%d%d* , " , r1+1 , c1-1 ) ;
    }

}

// MEHTOD THAT HAS THE LOGINC FOR THE ROOK
void rook( int r1 , int c1 )
{
    int i , j , n ;

    printf( "AVAILABLE: \n" ) ;

    n=c1;

    printf( "HORIZONTAL: \n" ) ;

    while( board[r1][n-1] == ' ' )
    {
        if( n == 0 ) { break ; }
        printf( "%d%d , " , r1 , n-1 ) ;
        n-- ;
    }

    n=c1 ;

    while( board[r1][n+1] == ' '  && (n+1) <= 7 )
    {

        printf( "%d%d , " , r1 , n+1 ) ;
        ++n ;
    }

    printf( "\nVERTICAL:\n" ) ;

    n = r1 ;

    while( board[n-1][c1] == ' ' && n > -1 )
    {
        printf( "%d%d , " , n-1 , c1 ) ;
        --n ;
    }

    n = r1 ;

    while( (board[n+1][c1] == ' ') && ( (n) <= 7 ) )
    {
        printf( "%d%d , " , n+1 , c1 ) ;
        ++n ;
    }

}

// METHOD THAT HAS THE LOGIC FOR THE HORSE
void horse( int r1 , int c1 )
{
    printf( "AVAILABLE: " ) ;

    // HORSE'S AVAILABLE POSITIONS
    if( board[r1+2][c1+1] == ' ' ) printf( "%d%d, " , r1+2 ,c1+1) ;
    if( board[r1+2][c1-1] == ' ' ) { if( (c1-1) > -1 ) printf( "%d%d, " , r1+2, c1-1 ) ; }

    if( board[r1+1][c1+2] == ' ' ) {  if( (c1+2) != 8 ) printf( "%d%d, " , r1+1 , c1+2 ) ; }
    if( board[r1-1][c1+2] == ' ' ) {  printf( "%d%d, " , r1-1 , c1+2 ) ; }

    if( board[r1-2][c1-1] == ' ' )
    {
        if( (c1-1) != -1 )
        printf( "%d%d, " , r1-2 , c1-1 ) ;
    }

    if( board[r1-2][c1+1] == ' ' ) printf( "%d%d, " , r1-2 , c1+1 ) ;

    if( board[r1+1][c1-2] == ' ' ) printf( "%d%d, " , r1+1 , c1-2 ) ;

    if( board[r1-1][c1-2] == ' ' )
    {
        if( (c1-2) != -1 )
            printf( "%d%d, " , r1-1 , c1-2 ) ;
    }
}

// METHOD THAT HAS THE LOGIC FOR THE CAMEL
void camel( int r1 , int c1 )
{
    int a , b , c , d ;
    printf( "AVAILABLE: \n" ) ;


    (void)(a = 1) , b = 1 ;

    while( board[r1-a][c1+b] == ' ' )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1-a , c1+b ) ;
        a++ ;
        b++ ;
    }


    (void)(a = 1) , b = 1 ;

    while( board[r1+a][c1-b] == ' ' )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1+a , c1-b ) ;
        a++ ;
        b++ ;
    }

    (void)(a = 1) , b = 1 ;


    while( board[r1+a][c1+b] == ' ' )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1+a , c1+b ) ;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1-a , c1-b ) ;
        a++ ;
        b++ ;
    }

}

// MEHTOD THAT HAS THE LOGIC FOR THE KING
void king( int r1 , int c1 )
{
    printf( "AVAILABLE: " ) ;
    // king's available positions
    if( board[r1][c1+1] == ' ' ) printf( "%d%d , " , r1 , c1+1 ) ;

    if( board[r1][c1-1] == ' ' ) printf( "%d%d , " , r1 , c1-1 ) ;

    if( board[r1+1][c1] == ' ' ) printf( "%d%d , " , r1+1 , c1 ) ;

    if( board[r1-1][c1] == ' ' ) printf( "%d%d , " , r1-1 , c1 ) ;

    if( board[r1+1][c1+1] == ' ' ) printf( "%d%d , " , r1+1 , c1+1 ) ;

    if( board[r1-1][c1-1] == ' ' ) printf( "%d%d , " , r1-1 , c1-1 ) ;

    if( board[r1-1][c1+1] == ' ' ) printf( "%d%d , " , r1-1 , c1+1 ) ;

    if( board[r1+1][c1-1] == ' ' ) printf( "%d%d , " , r1+1 , c1-1 ) ;
}

// MEHTOD THAT HAS THE LOGIC FOR THE QUEEN
void queen( int r1 , int c1 )
{
    int x=1 , y=1 , a , b ;
    printf( "AVAILABLE: " ) ;

    printf( "HORZONTAL: " ) ;

    while( board[r1][c1-y] == ' ' )
    {
      // QUEEN'S AVAILABLE POSITIONS
        if( (c1-y) == -1 ) break ;
        printf( "%d%d , " , r1 , c1-y ) ;
        y++ ;
    }

    y = 1 ;

    while( board[r1][c1+y] == ' ' )
    {
        if( (c1+y) == 8 ) break ;
        printf( "%d%d , " , r1 , c1+y ) ;
        y++ ;
    }

    printf( "VERTICAL: " ) ;

    x = 1 ;

    while( board[r1-x][c1] == ' ' )
    {
        if( (r1-x) == -1 ) break ;
        printf( "%d%d , " , r1-x , c1 ) ;
        x++ ;
    }

    x = 1 ;

    while( board[r1+x][c1] == ' ' )
    {
        if( (r1+x) == 8 ) break ;
        printf( "%d%d , " , r1+x , c1 ) ;
        x++ ;
    }

    printf( "DIAGONAL: " ) ;

    (void)(a = 1) , b = 1 ;

    while( board[r1-a][c1+b] == ' ' )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1-a , c1+b ) ;
        a++ ;
        b++ ;
    }


    (void)(a = 1) , b = 1 ;

    while( board[r1+a][c1-b] == ' ' )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1+a , c1-b ) ;
        a++ ;
        b++ ;
    }

    (void)(a = 1) , b = 1 ;


    while( board[r1+a][c1+b] == ' ' )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1+a , c1+b ) ;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1-a , c1-b ) ;
        a++ ;
        b++ ;
    }

}

// MEHTOD THAT HAS THE LOGIC FOR THE BLACK PAWN
void pawnb( int r1 , int c1 ) //BLACK
{
    pbstatus[c1]++;

    printf( "AVAILABLE: \n" ) ;


    if( pbstatus[c1] == 1 )
    {
        if( board[r1-1][c1] == ' ' )
        printf( "%d%d , " , r1-1 , c1 ) ;

        if( board[r1-2][c1] == ' ' )
        printf( "%d%d , " , r1-2 , c1 ) ;
    }
    else
    {
        if(board[r1-1][c1] == ' ' )
        printf( "%d%d , " , r1-1 , c1 ) ;

        if( check2(r1-1 , c1-1) == 1 )
        printf( "%d%d* , " , r1-1 , c1-1 ) ;

        if( check2(r1-1 , c1+1) == 1 )
        printf( "%d%d* , " , r1-1 , c1+1 ) ;
    }

}

// PLAYER 1 GAME FLOW
void player1()
{
    printf( "\nPLAYER 1 - UPPER CASES \n" ) ;
    int p1, p2 , c1 , r1 , c2 , r2;
    bool valido = true;
    while(valido == true){
      printf( "\nENTER THE POSITION TO CHANGE: " ) ;
      scanf( "%d" , &p1 );
      c1 = p1 % 10 ;
      r1 = p1 / 10 ;

      //SWITHC THAT CHECKS WHICH TOKEN THE PLAYER IS MOVING
      switch(board[r1][c1] )
      {
          case 'P': pawn( r1 , c1 );
                    valido = false;
                    break;
          case 'R': rook( r1 , c1 ) ;
                    valido = false;
                    break ;
          case 'H': horse( r1 , c1 );
                    valido = false;
                    break ;
          case 'C': camel( r1 , c1 );
                    valido = false;
                    break ;
          case 'K': king( r1 , c1 ) ;
                    valido = false;
                    break ;
          case 'Q': queen( r1 , c1 ) ;
                    valido = false;
                    break ;
          default: printf("INVALID POSITION!");
                   break;
      }
    }


    printf( "\nENTER POSITION TO SEND: " ) ;
    scanf( "%d" , &p2 ) ;

    c2 = p2 % 10 ;
    r2 = p2 / 10  ;
    change(r1,c1,r2,c2) ;
}

// PLAYER 2 GAME FLOW
void player2()
{
    int p1 , p2 , c1 , r1 , c2 , r2;

    printf( "\nPLAYER 2 - LOWER CASES \n") ;
    again2:
    printf( "\nENTER POSITION TO CHANGE: " ) ;
    scanf( "%d" , &p1 ) ;

    c1 = p1 % 10 ;
    r1 = p1 / 10 ;

    //SWITCH TAHT CHECKS WHICH TOKEN THE PLAYER IS MOVING
    switch( board[r1][c1] )
    {
        case 'p': pawnb( r1 , c1 ) ;
                  break ;
        case 'r': rook( r1 , c1 ) ;
                  break ;
        case 'h': horse( r1 , c1 ) ;
                  break ;
        case 'c': camel( r1 , c1 ) ;
                  break ;
        case 'k': king( r1 , c1 ) ;
                  break ;
        case 'q': queen( r1 , c1 ) ;
                  break ;
        default: printf( "INVALID POSITION! " ) ; goto again2 ;
    }


    printf( "\nENTER POSITION TO SEND: " ) ;
    scanf( "%d" , &p2 ) ;

    c2 = p2 % 10 ;
    r2 = p2 / 10  ;


    change(r1,c1,r2,c2) ;
}

// METHOD THAT CHECKSM ""TO BE DEFINED""
int check(int x , int y )
{
    switch( board[x][y] )
    {
    case 'p':
    case 'r':
    case 'h':
    case 'c':
    case 'k':
    case 'q': return 1 ; break ;
    default: return 0 ;
    }
}

// MEHTOD THAT CHECKS ""TO BE DEFINED""
int check2(int x , int y )
{
    switch( board[x][y] )
    {
    case 'P':
    case 'R':
    case 'H':
    case 'C':
    case 'K':
    case 'Q': return 1 ; break ;
    default: return 0 ;
    }
}
