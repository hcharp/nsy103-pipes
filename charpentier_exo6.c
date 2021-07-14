// Exercice 6

// Ouvrir un terminal et taper la commande shell suivante : $> ls -l | grep . | wc -l
// Que permet de faire cette commande ?
// Écrire un programme en C équivalent à cette commande en utilisant des tubes, dup2 et la fonction
// system() permettant d’appeler les commandes shells.


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    
}