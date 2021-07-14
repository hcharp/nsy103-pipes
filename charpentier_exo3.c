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
    int file_descriptor[2];
    pipe(file_descriptor);

    char phrase[] = "Bonjour monde";

    pid_t pid = fork();

    if (pid==0) { // père
        write(file_descriptor[1], phrase, sizeof(int));
    } else {
        int nb_car = len(phrase);
        close(file_descriptor[1]);
        read(file_descriptor[0], nb_car, sizeof(int));
    }
}