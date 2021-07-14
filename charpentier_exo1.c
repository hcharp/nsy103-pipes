// Exercice 1

// Écrire un programme qui permet de faire passer un nombre entier entre deux processus. Le père
// envoie le nombre à son fils


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int sent_integer = 7;
    int file_descriptor[2];
    pipe(file_descriptor); // sur [0] pour la lecture et sur [1] pour l'écriture

    // il faut fermer le descripteur dont on n'a pas besoin avant de créer un fils
    // attention c'est unilatéral
    // pas vraiment un tube mais plutôt un tuyau (pipe)
    // car les communications ne vont que dans un sens
    // on ne peut pas parler en mm temps dans le tuyau

    pid_t pid = fork();

    if (pid==0) { // père
        close(file_descriptor[0]);
        write(file_descriptor[1], sent_integer, sizeof(int));
    } else {
        int number;
        close(file_descriptor[1]);
        read(file_descriptor[0], number, sizeof(int));
    }
}