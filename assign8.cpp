#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
 
int main() {
	
   while (true)
   {
       string command;
       string argumentOne;
       string argumentTwo;
       string argumentThree; 

       // prompt user for command to run
       cout << "Enter command to run: ";
       cin >> command >> argumentOne >> argumentTwo >> argumentThree;
       
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
          // Child process: exec to command with argument
          // cout << "before exec to: " << command << " " << argumentOne << " " << argumentTwo << " " << argumentThree << " " << endl;
          rs = execlp(command.c_str(), command.c_str(), argumentOne.c_str(), argumentTwo.c_str(), argumentThree.c_str(), (char*) NULL);
          
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
