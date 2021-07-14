// Exercice 2

// Écrire un programme permettant à deux processus (père et fils) d’afficher ”je suis le père” et ”je
// suis le fils”. Le message ”je suis le fils” doit toujours apparaitre après celui du père. Utiliser les
// primitives read et write pour synchroniser les processus.


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

    char txt_pere[] = "Père\n";
    char txt_fils[] = "Fils\n";
    pid_t pid = fork();

    if (pid==0) { // père
        close(file_descriptor[0]);
        write(file_descriptor[1], &txt_pere, sizeof(int));
        close(file_descriptor[1]);
        read(file_descriptor[0], &txt_pere, sizeof(int));
    } else {
        close(file_descriptor[0]);
        write(file_descriptor[1], &txt_fils, sizeof(int));
        close(file_descriptor[1]);
        read(file_descriptor[0], &txt_fils, sizeof(int));
    }

}