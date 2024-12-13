# Overview
    This package has a program for a vote counting database and seperate voting machines.
# How to Use
    To run successfully, that is, after building with the included Makefile, open a number
of terminals such that you have one to run the voteDB program with no command line arguments,
and one per voting machine you wish to run. On each voting machine terminal, run voteVM with
a command line argument that matches your database's connection code, which is this number:
                    |
                    V
Connection code: [Number]

    You will know if the voting machine has connected when the voting database prints this:

Machine Connected!

    The use of the voting machines is designedly intuitive, and describing it in this manual would
be good practice, which is why voting is described here as simply typing the character in the
brackets to vote for a candidate, or disconnect the machine, as shown here.

Vote For:
        [1] Slim Thinly
        [2] Thick Largely
Or [Q]uit
        > 2
Vote processed.
Vote For:
        [1] Slim Thinly
        [2] Thick Largely
Or [Q]uit
        > 1
Vote processed.
Vote For:
        [1] Slim Thinly
        [2] Thick Largely
Or [Q]uit
        > q
Thank you for voting!

    When all connected machines are disconnected, the database will display the tallied votes and
declare either a winner or a draw.