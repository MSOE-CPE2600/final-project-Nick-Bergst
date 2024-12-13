/**
* @file voteDB.c
* @brief voting database terminal script.
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

int signal_empty;
int machinesConnected;
int slimThinly;
int thickLargely;

void handle_machine_signal(int sig, siginfo_t *info, void *ucontext) {
    //printf("Incoming Signal!");
    if (sig == SIGUSR1) {
        if (info->si_value.sival_int == 0) {
            slimThinly++;
            printf("One vote for: Slim Thinly\n");
        } else if (info->si_value.sival_int == 1) {
            thickLargely++;
            printf("One vote for: Thick Largely\n");
        } else {
            printf("Error! Unknown Vote\n");
        }
    } else if (sig == SIGUSR2) {
        machinesConnected += info->si_value.sival_int;
        if (info->si_value.sival_int > 0) {
            printf("Machine Connected!\n");
        } else if (info->si_value.sival_int < 0) {
            printf("Machine Disconnected!\n");
        }
        if (machinesConnected == 0) {
            //voting is done
            signal_empty = 0;
            printf("Slim Thinly (small party): %d votes\nThick Largely (Big Party): %d votes\n\n\n", slimThinly, thickLargely);
            if (slimThinly > thickLargely) {
                printf("Slim Thinly\n\tWINNER\n");
            } else if (slimThinly < thickLargely) {
                printf("Thick Largely\n\tWINNER\n");
            } else {
                printf("\tDRAW\n");
            }
        }
    }
}

int main() {
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
    //Print pID
    printf("Connection code: %d\n",getpid());

    //have not recieved a signal yet
    signal_empty = 1;
    //nobody's connected yet
    machinesConnected = 0;
    //nobody has votes
    slimThinly = 0;
    thickLargely = 0;

    // Register for the vote count signal
    struct sigaction cVotes;
    struct sigaction cdVotes;
    cVotes.sa_sigaction = handle_machine_signal;
    cVotes.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &cVotes, &cdVotes);
    // Register for the join/exit signal
    struct sigaction joinEx;
    struct sigaction joinExd;
    joinEx.sa_sigaction = handle_machine_signal;
    joinEx.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &joinEx, &joinExd);

    // Wait until a signal is received
    while(signal_empty) {
        sleep(1);
    }

    return 0;
}