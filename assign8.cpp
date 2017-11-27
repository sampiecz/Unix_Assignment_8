#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
 
int main() {

    char buffer[80];

    while (true)
    {
        string command, option;
        char *argument[] = {(char*)0, (char*)0, (char*)0, (char*)0, (char*)0}; 

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
        int rs, status;

        // fork will make 2 processes
        rs = fork();
        if (rs == -1)
        { 
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (rs == 0)
        {
            rs = execvp(command.c_str(), argument);

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
