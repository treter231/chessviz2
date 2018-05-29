#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "board.h"

void help_print();
void info_print();
int board_main();

int main() {
    system("clear");
        board_main();

    return 0;
}

char places[6];
int exitt = 0;

int board_main() {
    system("clear");
    print_new_board();
    while (exitt == 0) {
        help_print();
        printf("Write coordinates of the figure and \n   where to put it."
        " Example a2-c8\n""\t\tCommand:\n\t\t ");
        scanf("%s", places);
        printf("%s", RESET);
        if (places[0] == 'r') {
            system("clear");
            exitt = 1;
            board_main();
        } else if (places[0] == 'q') {
            system("clear");
            printf("%sGoodbye!%s\n",RED, RESET);
            return 0;
        }
        system("clear");
        exitt = board_func(places, 0);
        if (exitt == -1) {
            print_board();
            if (places[0] == 'r') {
                //printf("%s\t\tRestart!\n%s", GREEN, RESET);
            } else {
                printf("%s\tWrong coordinates or way!\n%s", RED, RESET);
            }
            exitt = 0;
        }
    }
    return 0;
}

void help_print() {
    printf("\t%s      (q) Quit\n\n%s", GRAY, RESET);
}

void info_print() {
    printf("%s\n"
    "\t  ████──█──█──███──███──███\n"
    "\t  █──█──█──█──█────█────█\n"
    "\t  █─────████──███──███──███\n"
    "\t  █──█──█──█──█──────█────█\n"
    "\t  ████──█──█──███──███──███\n\n"
    "\t████───████──████──████──████\n"
    "\t█──██──█──█──█──█──█──█──█──██\n"
    "\t████───█──█──████──████──█──██\n"
    "\t█──██──█──█──█──█──█─█───█──██\n"
    "\t████───████──█──█──█─█───████\n\n%s", RED, RESET);
    printf("%s\t        Beta version\n\n%s", GRAY, RESET);
    printf("\t    %s(s) Start or (q) Quit\n", GREEN);
    printf("\t\t  Command \n\t\t    %s", RESET);
}
