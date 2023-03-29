/*Nikloa Hristovski INKI 961*/
/*
1. vo red 34 deklarirame niza koja e konstanta od char pointeri  i taja niza gi predstavuva vrednostite na kartite po red od ace do king
2.vo red 37 deklarirame niza koja e konstanta od char pointeri i taja niza gi predstavuva Hearts, Diamonds, Clubs, Spades
3. vo red 40 se koristi funkcijata srand koja e generator na random broj  i time(NULL) e e funkcija koja do dava momentalnoto vreme vo sekundi a null e pointer so vrednost 0
4 vo red 64 definira promenliva koja e ke chuva samo  pozitivni broevi i mozhe da go chuvainteger vre3dnosta najgolemiot broj vo bajti vo zadachata go koristime kako brojach for ciklus
5.vo red 65 iva promenliva e istiot tip kako predhodnata sekoristi vo zadachata kako brojach for ciklus i se dvizhi od 0 do 51

zadachata prvin definira konstanti 52 za karti i 13 zza lica ,potoa definira structura od pojnteri za da ja sostavi kartata go preimenuva struct imeto gi declaria funkcijte
vo main definira niza od tip Card potoa so niza gi initializirvame face and suit i gi povikuva site funkci i potoa kazhuva sekoja funkcija sho ke pravi
fill deck ja popolnuva dech nizata i vo face i suit promenlivite i tuka se sostavuvat site karti vo shuffle se meshaat kartite a vo deal gi deli na 4 dela  cartite
*/

//NP-lab.04
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

// card structure definition
struct card {
   const char *face; // define pointer face
   const char *suit; // define pointer suit
}; // end struct card

typedef struct card Card; // new type name for struct card

// prototypes
void fillDeck( Card * const wDeck, const char * wFace[],
   const char * wSuit[] );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck );

int main( void )
{
   Card deck[ CARDS ]; // define array of Cards


   const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King"};// sto se pravi vo ovoj red ?


   const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};// sto se pravi vo ovoj red ?

   srand( time( NULL ) ); // sto e ovaa naredba ?

   fillDeck( deck, face, suit );
   shuffle( deck );
   deal( deck );
} // end main

// place strings into Card structures
void fillDeck( Card * const wDeck, const char * wFace[],
   const char * wSuit[] )
{
   size_t i;

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) {
      wDeck[ i ].face = wFace[ i % FACES ];
      wDeck[ i ].suit = wSuit[ i / FACES ];
   } // end for
} // end function fillDeck

// shuffle cards
void shuffle( Card * const wDeck )
{
   size_t i; // sto e ovaa promenliva ?
   size_t j; // sto e ovaa promenliva i vo koi vrednosti se dvizi ? vidi kod
   Card temp; // define temporary structure for swapping Cards

   // loop thr
   for ( i = 0; i < CARDS; ++i ) {
      j = rand() % CARDS; //
      temp = wDeck[ i ];
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;
   } // end for
} // end function shuffle

// deal cards
void deal( const Card * const wDeck )
{
   size_t i; // counter

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) {
      printf( "%5s of %-8s%s", wDeck[ i ].face, wDeck[ i ].suit,
         ( i + 1 ) % 4 ? "  " : "\n" );
   } // end for
} // end function deal
