/**
* @file voteVM.c
* @brief voting machine terminal script.
*
* Course: CPE2600
* Section: 111?
* Assignment: Final Project
* Name: Nicholas Bergst
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
    printf("************__________________________________________________\n");
    printf("*****/|*****__________________________________________________\n");
    printf("****/*|*****__________________________________________________\n");
    printf("****|*/*****__________________________________________________\n");
    printf("****|/******__________________________________________________\n");
    printf("************__________________________________________________\n");
    printf("______________________________________________________________\n");
    printf("______________________________________________________________\n");
    printf("______________________________________________________________\n");
    printf("______________________________________________________________\n");
    printf("______________________________________________________________\n");
    printf("______________________________________________________________\n");
    printf("______________________________________________________________\n");
    printf("I couldn't do the cool s. I'm sorry. Glory to the great United\n");
    printf("Union National Unity of the Nation. Copywrong 2024.\n\n\n");
    // if there's a command line arg, convert it to a pid
    if (argc > 1) {
        int vote = 1;
        pid_t myPid;
        sscanf(argv[1], "%d", &myPid);
        union sigval toSend;
        toSend.sival_int = 1;
        // pull up
        sigqueue(myPid, SIGUSR2, toSend);
        while (vote != 0) {
            char buff[100];
            printf("Vote For:\n\t[1] Slim Thinly (small party)\n\t[2] Thick Largely (BIG PARTY)\nOr [Q]uit\n");
            printf("> ");
            fgets(buff, sizeof buff, stdin);
            if (buff[0] == '1') {
                //cast for ST
                toSend.sival_int = 0;
                sigqueue(myPid, SIGUSR1, toSend);
                printf("Vote processed.\n\n\n\n\n\n\n\n\n\n\n");
            } else if (buff[0] == '2') {
                //cast for TL
                toSend.sival_int = 1;
                sigqueue(myPid, SIGUSR1, toSend);
                printf("Vote processed.\n\n\n\n\n\n\n\n\n\n\n\n");
            } else if (buff[0] == 'Q' || buff[0] == 'q') {
                //start leaving
                vote = 0;
            } else {
                //give up
                printf("Input not recognized!\n\n\n\n\n\n\n\n\n\n\n\n");
            }
        }
        toSend.sival_int = -1;
        // leave
        sigqueue(myPid, SIGUSR2, toSend);
        printf("Thank you for voting!\n");
    } else {
        printf("Please provide a Connection ID!\n");
    }
    return 0;
}