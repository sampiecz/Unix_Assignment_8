#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
 
int main() {
    // At this point in time I just need to make
    // argument a vector so I stop getting garbage
    // I'm going to commit then try again.

    char buffer[80];

    while (true)
    {
        string command, option;
        char* argument[5]; 

        // prompt user for command to run
        cout << "Enter a command to run: ";

        cin.getline(buffer, 80);
        
        if (!strcmp(buffer, "exit"))
        {
            break;
        }

        char * pch;
        pch = strtok (buffer, " ");

        int count = 0;

        while (pch != NULL)
        {
            if (count == 0)
            {
                command = pch;
            }
            /* else if ()
            {
                option = pch;
            } 
            */
            argument[count] = pch;
            pch = strtok (NULL, " ");
            count++;
        }

        //
        //
        //
        //  This is where the magic starts
        //
        //
        //
        int pid, rs, status;

        // fork will make 2 processes
        pid = fork();
        if (pid == -1)
        { 
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            // rs = execlp(command.c_str(), argument, (char*) NULL);
            rs = execvp(command.c_str(), argument);

            if (rs == -1)
            {
              perror("execlp"); exit(EXIT_FAILURE); 
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
