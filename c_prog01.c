/*c_prog01.c
 *
 *      ECE474 introductory C programming assignment Part1
 *
 *     Student Name: Samantha Reksosamudra
 *     Student ID#:  2276717
 *
 */

/*  Objectives:
       Gain experience and proficiency with C programming.


Format of assignment:
1)  Enter your name into the space above
2)  Read through the comments below and edit code into this file to solve the 
    problems.
3)  Check your results against posted solution
4)  Upload this file only (c_prog01.c) to Canvas

Printing:   Use the following functions to print:
  print_int(int x)                prints out an integer
  print_usi(unsigned int x)       prints out an unsigned int
  print_newl()                    prints a "newline" character
  print_str(char *x)              prints a string (pointed to by x)
  print_dble(double)              prints out a double precision floating point number
*/

#include "c_prog1.h"
#include <stdbool.h>

/**********************************************************************
                 All variable declarations
**********************************************************************/

int i,j,k,l;      // these make good loop iterators.
int card, suit;

// Part 1.2
int t1, t2;

// Part 1.4
// HINT: Does this need to be modified?
char* st_buffer[100];

// Part 2.0
shuffle cards[N_DECK][2];

//  Part 2.2
unsigned char testhand[7]={0};

// Part 3.1
char * card_names[]={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen",
                        "King"};
char * suit_names[]={"Hearts","Diamonds","Clubs","Spades"};

// Part 3.2
int dealer_deck_count = 0;  // how many cards have been dealt from a deck

/******************************************************************************
 * 1.1  Write code to print out integers between 1 and N on separate lines
 *      
 *      SAMPLE OUTPUT:
 *       1 
 *       2 
 *       3 
 *       (continued)...
 *****************************************************************************/

void count(int N){
    for (i = 1; i <= N; i++) {
      print_int(i);
      print_newl();
    }
    
}

/******************************************************************************
 * 1.2  Write code to print out integers between 1 and N on separate lines
 *      
 *      SAMPLE OUTPUT:
 *       1 
 *       2 
 *       3 
 *       (continued)...
 *       [sum(1,2,3 ... N)] [sum(1^2,2^2,3^2 ... N^2)]
 *****************************************************************************/

void sums_and_squares1(int N){   
    t1 = 0 ; t2 = 0;

    for (i = 1; i <= N; i++) {
      print_int(i);
      print_newl();
      t1 += i;
      t2 += (i*i);
    }


    print_int(t1) ;  print_int(t2) ;   print_newl();
}

/******************************************************************************
 * 1.3  Write code to print out integers between 1 and N on separate lines
 *      
 *      SAMPLE OUTPUT:
 *      sum: [sum(1,2,3 ... N)] 
 *      sum of squares: [sum(1^2,2^2,3^2 ... N^2)] 
 *****************************************************************************/
void sums_and_squares2(int N){
    char *l1;
    char *l2;

    t1 = 0 ; t2 = 0;

    for (i = 1; i <= N; i++) {
      print_int(i);
      print_newl();
      t1 += i;
      t2 += (i*i);
    }
    
    l1 = "sum: ";
    l2 = "sum of squares: ";

    print_str(l1); print_int(t1); print_newl();
    print_str(l2); print_int(t2); print_newl();

}

/******************************************************************************
 * 1.4  Write a function, char* length_pad(char *st, char* st_buffer, int n), 
 *      which takes a string and adds the right amount of spaces so that it's 
 *      length is n. It should return a pointer the new string.  If the length 
 *      of st is greater than n, truncate the string. 
 *      Note: Check the variable definitions above.
 * 
 *      Modify 1.3 to use length_pad() so that the numbers are all starting in 
 *      col 21 (i.e. all labels have length 20). 
 *     
 *      SAMPLE OUTPUT:
 *      sum:               [sum(1,2,3 ... N)] 
 *      sum of squares:    [sum(1^2,2^2,3^2 ... N^2)]
 *****************************************************************************/

char* length_pad(char *st, char* st_buffer, int n) {

    // Calculate the length of the input string
    int len = strlen(st);

    // If the length is greater than or equal to n, truncate the string
    if (len >= n) {
        for (int i = 0; i < n; i++) {
          st_buffer[i] = st[i];
        }
        st_buffer[n] = '\0'; // Null-terminate the string
    } else {
        // If the length is less than n, pad with spaces on the right
        for (int i = 0; i < len; i++) {
          st_buffer[i] = st[i];
        }
        for (int i = len; i < n; i++) {
          st_buffer[i] = ' ';
        }
        st_buffer[n] = '\0'; // Null-terminate the string
    }

    return st_buffer;
}

void sums_and_squares3(int N){
    char *l1;
    char *l2;

    l1 = "sum: ";
    l2 = "sum of squares: ";

    print_str(length_pad(l1,st_buffer, 20)) ; print_int(t1) ; print_newl();
    print_str(length_pad(l2,st_buffer, 20)) ; print_int(t2) ; print_newl();
}



/******************************************************************************
 * 2.1 A 'shuffle' is an array of N_DECK pairs of integers. The first of the 
 *     pair is the card type (0-13 representing ace, 2, 3, .... King) and the 
 *     second representing the suit (hearts, diamonds, clubs, spades).   Thus a 
 *     pair of numbers (1-13)(1-4) describes a unique card in the deck.
 * 
 *     Write a function to fill a shuffle with N_DECK random integer pairs, 
 *     BUT, as with your playing cards, there must be EXACTLY one of each pair 
 *     in the shuffle. Use your function to print out all the "cards" of the 
 *     shuffle, with 7 cards per line.
 * 
 *     To generate a random number use the helper function int randN(int n)
 *     defined at the bottom of this file that returns a random integer between 
 *     1 and N.
 *
 *     SAMPLE OUTPUT:
 [ 11   2 ]  [ 11   4 ]  [ 12   1 ]  [ 5   4 ]  [ 4   3 ]  [ 7   3 ]  [ 5   3 ] 
 [ 13   4 ]  [ 9   3 ]  [ 2   3 ]  [ 1   1 ]  [ 2   4 ]  [ 3   2 ]  [ 2   1 ] 
 [ 13   1 ]  [ 7   4 ]  [ 8   2 ]  [ 4   4 ]  [ 6   4 ]  [ 4   2 ]  [ 1   4 ] 
 [ 7   1 ]  [ 3   3 ]  [ 12   2 ]  [ 6   1 ]  [ 12   4 ]  [ 13   3 ]  [ 9   2 ] 
 [ 9   1 ]  [ 3   4 ]  [ 9   4 ]  [ 10   2 ]  [ 4   1 ]  [ 8   1 ]  [ 1   3 ] 
 [ 3   1 ]  [ 11   3 ]  [ 8   4 ]  [ 10   3 ]  [ 5   1 ]  [ 10   1 ]  [ 13   2 ] 
 [ 11   1 ]  [ 7   2 ]  [ 6   3 ]  [ 8   3 ]  [ 12   3 ]  [ 2   2 ]  [ 5   2 ] 
 [ 1   2 ]  [ 10   4 ]  [ 6   2 ]
 *****************************************************************************/

void fill(shuffle deck[N_DECK][2]) {
    
    // YOUR CODE HERE ...

    // Initialize an array to track used cards
    bool used[N_DECK];
    for (int i = 0; i < N_DECK; i++) {
        used[i] = false;
    }

    // Fill the shuffle array with unique card pairs
    for (int i = 0; i < N_DECK; i++) {
        int cardType, suit;

        do {
            // Generate random card type and suit
            cardType = randN(13);
            suit = randN(4);
        } while (used[(suit - 1) * 13 + (cardType - 1)]); // Check if the card is already used


        // Mark the card as used
        used[(suit - 1) * 13 + (cardType - 1)] = true;
        

        // Assign the card to the shuffle array
        deck[i][0] = cardType;
        deck[i][1] = suit;
    }

}
  

/******************************************************************************
 * 2.2 A 'hand' is an array of seven unsigned chars.  Each char represents one 
 *     card.  We use a four bit field in the char for each of the two numbers 
 *     above: the four most significant bits [7...4] represent the card number 
 *     (1-13) and the lower four [3...0] represent the suit.
 * 
 *     Write functions to:  
 *     a) Convert two integers (from  a shuffle for example) into a char as 
 *        above. If the ints are invalid (e.g. convert(294802984,138142) is not 
 *        a card) return CARD_ERROR
 *     b) Test if a char equals a valid integer pair
 *     c) Get the integer suit from a char
 *     d) Get the integer card from a char
 * 
 *     Both functions a and b must return CARD_ERROR if they get invalid input 
 *     (such as suit > 4).
 * 
 *     Write code for the functions convert(), valid_card(), gcard(), and 
 *     gsuit() below.
 *****************************************************************************/
unsigned char  convert(int card, int suit) {
   
    // Check if card and suit value is invalid
    if (card < 0 || card > 14 || suit < 0 || suit > 5) {
      return CARD_ERROR;
    }

    // Shift card value to the left
    unsigned char char_card = card << 4;

    // Do an OR_EQUAL with the suit value
    char_card |= suit;

    // Now, char_card has the card value in bits[7:4] and suit value in bits[3:0]
    return char_card;
}

// Test if a card byte is a valid card
int valid_card(unsigned char card){
    
    // Obtain the card and suit values
    int number = (int) card >> 4;
    int suit = (int) card & 0x0F;

    // Check if card and suit values are invalid
    if (number < 0 || number > 14 || suit < 0 || suit > 5) {
      return CARD_ERROR;
    }

    return 1;
}
// your code for gsuit and gcard here

int gcard(unsigned char card) {
    
    // Check if the card is invalid or not
    if (valid_card(card) == CARD_ERROR) {
      return CARD_ERROR;
    }

    // Obtain the card's value by shifting four bits to the right
    int number = (int) card >> 4;
    
    return number;
}

int gsuit(unsigned char card) {
    
    // Check if the card is invalid or not
    if (valid_card(card) == CARD_ERROR) {
      return CARD_ERROR;
    }

    // Obtain the suit value by AND gate-ing with 00001111(0x0F) to get the four LSB 
    int suit = (int) card & 0x0F;

    return suit;
}

/******************************************************************************
 * 3.1 Write a function names(int card, int suit, char answer[]) which places a 
 *     string of the name and suit of a card in the array answer[]. For 
 *     example: name(11,1) → “Jack of Hearts” name(8,2) → “8 of Diamonds”. Use 
 *     the arrays defined above card_names[] and suit_names[]
 *     
 *     Hint: Use pointers to copy the characters one-by-one into the array 
 *     answer[] to build up the final string.
 *****************************************************************************/

void names(int card, int suit, char *answer) {

    // Check if card and suit values are valid
    if (card < 0 || card > 14 || suit < 0 || suit > 5) {
        return CARD_ERROR;
    }

    // Copy card name into the answer array
    char *card_name = card_names[card-1];
    while (*card_name != '\0') {
        *answer = *card_name;
        answer++;
        card_name++;
    }

    // Add space between card name and suit
    *answer = ' '; answer++;
    *answer = 'o'; answer++;
    *answer = 'f'; answer++;
    *answer = ' '; answer++;

    // Copy suit name into the answer array
    char *suit_name = suit_names[suit - 1];
    while (*suit_name != '\0') {
        *answer = *suit_name;
        answer++;
        suit_name++;
    }

    // Null-terminate the string
    *answer = '\0';

}

/******************************************************************************
 * 3.2 Write a function to deal a hand of M (0<M<8) cards from a shuffle. Use a 
 *     global variable int dealer deck count to keep track of how many cards 
 *     have been dealt from the deck.
 * 
 *     To test this write a function printhand() that prints out a hand of 
 *     cards
 *     
 *     SAMPLE OUTPUT:
 * 
 *     ----testing deal: hand:  0 
 *     Deck count:  0 
 *     --------dealt hand: 
 *     the hand: 
 *         Jack of Diamonds
 *         Jack of Spades
 *         Queen of Hearts
 *         5 of Spades
 *         4 of Clubs
 *         7 of Clubs
 *         5 of Clubs
 * 
 *****************************************************************************/

void deal(int M, unsigned char hand[7], int deck[N_DECK][2]) {
    
    // YOUR CODE HERE ...
    if (M < 0 && M > 8 ) {
      print_str("Invalid number for hands. Please give a range between 0 to 7.");
      print_newl();
    } 
    else {
      for (int i = 0; i < M; i++) {
      
        // Initialize a variable to store a card, number, and suit values
        unsigned char card;
        int number, suit;

        // Get the number and suit values of a card in deck
        number = deck[i + dealer_deck_count][0];
        suit = deck[i + dealer_deck_count][1]; 
        
        // Convert it into a card
        card = convert(number, suit);

        // Assign card into our hand
        hand[i] = card; 
      }
      dealer_deck_count += M;
    }
  
}

void printhand(int M, unsigned char* hand, char* buff1) {
    
    for (int i = 0; i < M; i++) {
      // Obtain the card's number and suit values
      int number = gcard(hand[i]);
      int suit = gsuit(hand[i]);

      // Get the name of the card
      names(number, suit, buff1);
      // Print the name
      print_str(buff1);
      print_newl();  
    }

}

/******************************************************************************
 * 3.3 Write functions to identify pairs of cards in a hand (two cards with the
 *     same number), three-of-a-kind (three cards with the same number), and 
 *     four-of-a-kind (four cards with the same number).
 *****************************************************************************/
int pairs(int M, unsigned char hand[]) {
    
    int pair = 0;

    // Initilaize an array to store the card values
    int card[13][2];

    // Fill in the array with card values and their quantity
    for (int i = 0; i < 13; i++) {
      card[i][0] = i + 1;           //numbers
      card[i][1] = 0;               //quantity
    }

    // Count the number of cards 
    for(int i = 0; i < M ; i++) {
      int number = gcard(hand[i]);
      card[number - 1][1]++;
    }

    // Check for pairs
    for (int i = 0; i < 13; i++) {
      if (card[i][1] == 2) {
        pair++;
      }
    }

    return pair;
}

int trip_s(int M, unsigned char hand[]) {
    
    int triple = 0;

    // Initilaize an array to store the card values
    int card[13][2];

    // Fill in the array with card values and their quantity
    for (int i = 0; i < 13; i++) {
      card[i][0] = i + 1;           //numbers
      card[i][1] = 0;               //quantity
    }

    // Count the number of cards 
    for(int i = 0; i < M ; i++) {
      int number = gcard(hand[i]);
      card[number - 1][1]++;
    }

    // Check for triples
    for (int i = 0; i < 13; i++) {
      if (card[i][1] == 3) {
        triple++;
      }
    }

    return triple;
}

int four_kind(int M, unsigned char hand[]) {
  
    int quartet = 0;

    // Initilaize an array to store the card values
    int card[13][2];

    // Fill in the array with card values and their quantity
    for (int i = 0; i < 13; i++) {
      card[i][0] = i + 1;           //numbers
      card[i][1] = 0;               //quantity
    }

    // Count the number of cards 
    for(int i = 0; i < M ; i++) {
      int number = gcard(hand[i]);
      card[number - 1][1]++;
    }

    // Check for four-kinds
    for (int i = 0; i < 13; i++) {
      if (card[i][1] == 4) {
        quartet++;
      }
    }

    return quartet;
}

//  Predefined helper function to return a random integer between 1 and n
int randN(int n) { 
    double x;
    x = 1.0 + (double) n * rand() / RAND_MAX;
    return((int)x);
}