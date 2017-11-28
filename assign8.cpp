//*********************************************************************
//// FILE:        assign8.cpp
//// AUTHOR:      Samuel Piecz
//// LOGON ID:    Z1732715
//// DUE DATE:    11/28/17
////
//// PURPOSE:     Make a "poor mans" bash. 
////********************************************************************
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
 
// It's yah boi main
int main() {

    // This is where all our commands get stored - neat
    char buffer[80];

    // Until we say so keep going please
    while (true)
    {
        // Here are our variables, the names should be self explanatory
        // Specifically argument stores up to 5 commands
        // Basically we break down buffer and fill these variables so
        // they may be passed into execvp
        string command, option;
        char *argument[] = {(char*)0, (char*)0, (char*)0, (char*)0, (char*)0}; 

        // prompt user for command to run
        cout << "Enter a command to run: ";

        // take in user input
        cin.getline(buffer, 80);
        
        // If the user says exit listen to them
        // and break down
        if (!strcmp(buffer, "exit"))
        {
            break;
        }

        // Split buffer into pch pointer to char
        char * pch;
        pch = strtok (buffer, " ");

        // Give us a counter variable
        int count = 0;

        // While we have variables in pch keep going
        while (pch != NULL)
        {
            // If it's the first command
            // fill the variable command
            // so we know what to run
            if (count == 0)
            {
                command = pch;
            }
            
            // Pack our array with the variables
            argument[count] = pch;
            // Reset pch
            pch = strtok (NULL, " ");
            // Count iteration
            count++;
        }

        //  This is where the magic starts
        //  What I mean by this, is it's where
        //  the processes and forking actually happens
        //  everything above was just user input this
        //  is the "meat" and the above was the "potatoes"

        // Initialize necessary variables
        int rs, status;

        // fork will make 2 processes
        rs = fork();

        // If fork is unhappy then break down
        if (rs == -1)
        { 
            perror("fork");
            exit(EXIT_FAILURE);
        }

        // If fork is okay run the command
        if (rs == 0)
        {
            rs = execvp(command.c_str(), argument);

            // If the command doesn't work exit and 
            // tell the user the command that execvp
            // didn't like
            if (rs == -1)
            {
              perror(*argument);
              exit(EXIT_FAILURE); 
            }
        }
        else
        { 
            // Parent process: wait for child to end
            wait(&status);
        }

    }
    return 0;
}
