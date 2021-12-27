/* Purpose: take a number as input as a command line argument and print it in
 * the style of a seven segment digital display
 * 
 * Author: Matthew Cummings
 * 
 * Date: 3 December 2021
*/

// Purpose: support printing to STDOUT with printf()
#include <stdio.h>

// Purpose: find length of inputted argument string with strlen()
#include <string.h>

// Purpose: determine if a given char is a number with isdigit()
#include <ctype.h>

/*
 * Purpose: prints the correct segments for 1 digit in the top zone
 * thisDigit: current digit being partially printed
*/
void top_zone_num(char thisDigit) {
    // print current digit being displayecd
    // printf("%c", thisDigit);

    // match a given ASCII digit with the correct segments and print it
    if (thisDigit == '1' || thisDigit == '4') {
        printf("   ");
    } else {
        printf(" _ ");
    }
}

/*
 * Purpose: prints the correct segments for 1 digit in the middle zone
 * thisDigit: current digit being partially printed
*/
void mid_zone_num(char thisDigit) {
    // print current digit being displayecd
    // printf("%c", thisDigit);

    // match a given ASCII digit with the correct segments and print it
    if (thisDigit == '0') {
        printf("| |");
    } else if (thisDigit == '1' || thisDigit == '7') {
        printf("  |");
    } else if (thisDigit == '2' || thisDigit == '3') {
        printf(" _|");
    } else if (thisDigit == '4' || thisDigit == '8' || thisDigit == '9') {
        printf("|_|");
    } else {
        printf("|_ ");
    }
}

/*
 * Purpose: prints the correct segments for 1 digit in the bottom zone
 * thisDigit: current digit being partially printed
*/
void bot_zone_num(char thisDigit) {
    // print current digit being displayecd
    // printf("%c", thisDigit);

    if (thisDigit == '0' || thisDigit == '6' || thisDigit == '8') {
        printf("|_|");
    } else if (thisDigit == '1' || thisDigit == '4' || thisDigit == '7') {
        printf("  |");
    } else if (thisDigit == '2') {
        printf("|_ ");
    } else {
        printf(" _|");
    }
}

/*
 * Purpose: prints all segments for the top zone by calling top_zone_num for
 *          each digit
 * userInt: full number user entered as a command line argument
*/
void top_zone(char* userInt, int intLen) {
    // prints full userInt
    // printf("top: %s\n", userInt);

    // iterate over top zone and print every digit's segments one at a time
    for (int i = 0; i < intLen; i++) {
        top_zone_num(userInt[i]);
    } printf("\n");
}

/*
 * Purpose: prints all segments for the middle zone by calling mid_zone_num for
 *          each digit
 * userInt: full number user entered as a command line argument
*/
void mid_zone(char* userInt, int intLen) {
    // prints full userInt
    // printf("mid: %s\n", userInt);

    // iterate over top zone and print every digit's segments one at a time
    for (int i = 0; i < intLen; i++) {
        mid_zone_num(userInt[i]);
    } printf("\n");
}

/*
 * Purpose: prints all segments for the bottom zone by calling bot_zone_num for
 *          each digit
 * userInt: full number user entered as a command line argument
*/
void bot_zone(char* userInt, int intLen) {
    // prints full userInt
    // printf("bot: %s\n", userInt);

    // iterate over top zone and print every digit's segments one at a time
    for (int i = 0; i < intLen; i++) {
        bot_zone_num(userInt[i]);
    } printf("\n");
}

/* 
 * argc: num of arguments
 * argv: array of arguments
 * argv[1]: number to print in 7 segment style
*/
int main(int argc, char *argv[]) {

    // check user entered number to display
    if (argc != 2) {
        printf("Error. Check arguments.\nUsage: ./display7.c 123456789\n");
        return 0;
    }

    // find length of inputted number
    int intLen = strlen(argv[1]);

    // iterate over argv[1] and check it contains a number in every char.
    // if argv[1] contains an int, then intChars will equal intLen. otherwise,
    // the user has not correctly inputted an int in argv[1] and this
    // program must terminate
    int intChars = 0;
    for (int i = 0; i < intLen; i++) {
        if (isdigit(argv[1][i])) {
            intChars++;
        }
    } if (intChars != intLen) {
        printf("Please enter a positive number instead of \"%s\".\n", argv[1]);
        return 0;
    }

    // print userInt
    // printf("%s\n", argv[1]);

    // call functions to handle the printing of each zone
    top_zone(argv[1], intLen);
    mid_zone(argv[1], intLen);
    bot_zone(argv[1], intLen);
}