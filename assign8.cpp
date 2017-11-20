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
        string command;
        char argument[4];
        char options[4];

        // prompt user for command to run
        cout << "Enter a command to run: ";

        cin.getline(buffer, 80);
        
        if (!strcmp(buffer, "exit"))
        {
            break;
        }

        cout << buffer << endl;

        char * pch;
        pch = strtok (buffer, " ");
        while (pch != NULL)
        {
            pch = strtok (NULL, " ");
        }

        //
        //
        //
        //  This is where the magic starts
        //
        //
        //
        /*
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
          rs = execlp("touch", "touch", buffer, (char*) NULL);
          
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

        */
    }
        return 0;
}
