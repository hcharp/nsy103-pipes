#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int retour0, retour1, old;

    char buff[5];
    int fds[2]; // fds = avec 2 portes (0 et 1)

    pipe(fds); // création du tube

    old = dup(1); //stdout - entrée standard devient old
    
    /*
    0 -> stdin
    1 -> stdout
    2 -> stderr
    3 -> FDS[0] (porte de lecture du tube)
    4 -> FDS[1] (porte d'écriture du tube)
    */

    close(1); // old
    retour1 = dup(fds[1]); // écriture du tube devient retour1
    close(fds[1]); // retour1 fermé

    close(0); // stdin fermé
    retour0 = dup(fds[0]); // stdin devient retour0
    close(fds[0]); // retour0 fermé

    write(1, "Test\n", 5); // on écrit sur retour1, sur 5 octets
    read(0, buff, 5); // on lit sur retour0, sur 5 octets

    dup2(old, 1); // retour1 devient old

    printf("%s", buff); // on fait un printf de... je suis perdue
    return 0;
}