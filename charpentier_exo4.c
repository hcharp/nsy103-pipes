// Exercice 4

// Écrire un programme permettant d’avoir n processus créés par un processus père. Le père initialise
// une valeur à 0. Chaque processus fils récupère cette valeur et l’incrémente de son pid. Puis le
// processus fils la retourne à son père qui l’envoie au processus fils suivant. Le programme doit
// permettre d’afficher la somme des pid par le processus père.


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 7;
    int file_descriptor[2];
    pipe(file_descriptor); // sur [0] pour la lecture et sur [1] pour l'écriture
    // il faut fermer le descripteur dont on n'a pas besoin avant de créer un fils
    // attention c'est unilatéral
    // pas vraiment un tube mais plutôt un tuyau (pipe)
    // les communications ne vont que dans un sens
    // on ne peut pas parler en mm temps dans le tuyau
    
    int somme = 0;
    pid_t pid = fork();
    for (int i = 1; i < n-1; i++)
    {
        pid_t pid = fork();
        (int)pid;
        somme += pid;
        // printf(&somme);
        printf("%d\n",&pid);
    }
    

    if (pid==0) { // père
        close(file_descriptor[0]);
        // printf("%d\n",&somme);
    }
    // printf(&somme);
}