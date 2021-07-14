// Exercice 3

// Écrire un programme permettant d’échanger une phrase entre deux processus. Par exemple, le père
// envoie un texte que le fils va afficher. Le fils doit aussi afficher le nombre de caractères du texte
// (dans cet exercice il est possible d’utiliser la librairie <string.h>)


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fds[2];
    pipe(fds);

    char phrase[100];

    pid_t pid = fork();

    if (pid==0) { // père
        close(fds[0]);
        char phrase_envoyee[] = "Bonjour le monde";
        write(fds[1], phrase_envoyee, strlen(phrase_envoyee)); // je le mets dans le tube
    } else {
        close(fds[1]); // je ferme la porte d'écriture
        // read(fds[0], phrase, 100); // je le lis dans le tube
        // int nb_car = strlen(phrase);

        //comme read renvoie le nombre de caractères, on fera plutôt :
        int nb_car = read(fds[0], phrase, 100); 
        printf("La phrase \"%s\" contient %d caractères.\n", phrase, nb_car);
    }
}