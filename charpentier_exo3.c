// Exercice 3

// Écrire un programme permettant d’échanger une phrase entre deux processus. Par exemple, le père
// envoie un texte que le fils va afficher. Le fils doit aussi afficher le nombre de caractères du texte
// (dans cet exercice il est possible d’utiliser la librairie <string.h>)


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int file_descriptor[2];
    pipe(file_descriptor); // sur [0] pour la lecture et sur [1] pour l'écriture
    // il faut fermer le descripteur dont on n'a pas besoin avant de créer un fils
    // attention c'est unilatéral
    // pas vraiment un tube mais plutôt un tuyau (pipe)
    // les communications ne vont que dans un sens
    // on ne peut pas parler en mm temps dans le tuyau

    pid_t pid = fork();

    if (pid==0) { // père
        close(file_descriptor[0]); 
    } 
}