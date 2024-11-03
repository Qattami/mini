
#include <stdio.h>
#include <unistd.h>  
#include <string.h>  
#include <stdlib.h>

////Wa Imaaan labassss elliiiiik 

//Sojod:
//🤡 Note : 
    //(link the strcmp with libft) for strcmp
    //Now args[0] == ./a.out Soon---> cd
    //Now args[1] == cd --> PATH
    //Now args[2] == PATH --> NULL (maybee if you want to add more PATH with pipes)
    //Go to bash and test (cd /path /path) --> you will see more loke at the output by pwd

void cd_(char **args) {
    char *home;

    home = NULL;
    if (!args[2]) {
            home = getenv("HOME"); 
        if (home)
        {
            if (chdir(home) != 0)
                perror("cd");
            // : Sojod: you need to check the else if it is cd or a random word 
                if (!strcmp(args[1], "cd") && args[2] == NULL) //to make more sure for there's cd onlyy !!   arg[1] will be arg[0] in the future
                {
                    printf("u are at home 🏠\n");
                    getenv("HOME"); // to go into the home
                }
         }
         else
            fprintf(stderr, "cd: HOME not set\n");
        return;
    }
        if (chdir(args[2]) != 0) 
                printf("L PAth makyenx 👺");
        else
            printf("L path kayen 🏠") ;
        //  if chdir() fails => return -1 else return 0

}


int main(int ac, char **av)
{
    if(ac >= 2)
    {
       cd_(av);
    }
    else
        printf("nothing is sets \n");
}

/// Khanbriiik <3
