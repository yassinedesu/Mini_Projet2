//\\ ------------------------------->> Mini-Projet <<------------------------------- \-\/-/
#include <stdio.h>
#include <string.h>

struct contacts {
    char nom[100];
    char numero[15];
    char email[50];
};

struct contacts contact[100];
int nbr_contact = 0;

void ajouter() {
    if (nbr_contact >= 100) {
        printf("Limite de contacts atteinte.\n");
        return;
    }

    printf("\n1. Ajouter un Contact\n");
    printf("Nom : ");
    scanf(" %[^\n]", contact[nbr_contact].nom);
    printf("Numero de telephone : ");
    scanf("%s", contact[nbr_contact].numero);
    printf("Email : ");
    scanf("%s", contact[nbr_contact].email);
    nbr_contact++;
}

void modifier() {
    char recherchenom[100];
    printf("Veuillez entrer le nom du contact a modifier : ");
    scanf(" %[^\n]", recherchenom);

    for (int i = 0; i < nbr_contact; i++) {
        if (strcmp(contact[i].nom, recherchenom) == 0) {
            printf("Modifier le contact : %s\n", contact[i].nom);
            printf("Nouveau Numero de telephone : ");
            scanf("%s", contact[i].numero);
            printf("Nouvel Email : ");
            scanf("%s", contact[i].email);
            printf("Contact modifie avec succes.\n");
            return;
        }
    }
    printf("Contact non trouve !!\n");
}

void supprimer() {
    char recherchenom[100];
    printf("Veuillez entrer le nom du contact a supprimer : ");
    scanf(" %[^\n]", recherchenom);

    for (int i = 0; i < nbr_contact; i++) {
        if (strcmp(contact[i].nom, recherchenom) == 0) {
            for (int j = i; j < nbr_contact - 1; j++) {
                contact[j] = contact[j + 1];
            }
            nbr_contact--;
            printf("Contact supprime avec succes.\n");
            return;
        }
    }
    printf("Contact non trouve !!\n");
}

void afficher() {
    if (nbr_contact == 0) {
        printf("Aucun Contact !!\nListe des contacts est vide !!\n");
    } else {
        for (int i = 0; i < nbr_contact; i++) {
            printf("\n||---------------------------------||\n");
            printf("Nom: %s\n", contact[i].nom);
            printf("Numero de telephone: %s\n", contact[i].numero);
            printf("Email: %s\n", contact[i].email);
        }
    }
}

void rechercher() {
    char recherchenom[100];
    printf("Veuillez entrer le nom de contact : ");
    scanf(" %[^\n]", recherchenom);

    for (int i = 0; i < nbr_contact; i++) {
        if (strcmp(contact[i].nom, recherchenom) == 0) {
            printf("\n-----------|<Contact trouve>|-----------\n");
            printf("Nom : %s\n", contact[i].nom);
            printf("Numero : %s\n", contact[i].numero);
            printf("Email : %s\n", contact[i].email);
            return;
        }
    }
    printf("\nContact non trouve !!\n");
}

int main() {
    int choix;
    do {
        printf("\n>>-----------------------Contacts-----------------------<<\n");
        printf("1. Ajouter un Contact\n");
        printf("2. Modifier un Contact\n");
        printf("3. Supprimer un Contact\n");
        printf("4. Afficher Tous les Contacts\n");
        printf("5. Rechercher un Contact\n");
        printf("0. Quitter\n");
        printf("Option Menu : ");
        scanf("%d", &choix);
        
        switch (choix) {
            case 1: ajouter(); 
            break;
            case 2: modifier(); 
            break;
            case 3: supprimer(); 
            break;
            case 4: afficher(); 
            break;
            case 5: rechercher(); 
            break;
            case 0: printf("\n/\\_/\\*.*.*.* Au revoir, a la prochaine fois! *.*.*.*/\\_/\\ \n"); 
            break;
            default: printf("\nVeuillez choisir un des choix disponibles !!\n"); 
            break;
        }
    } while (choix != 0);
    
    return 0;
}

//\\ ------------------------------->> Mini-Projet <<------------------------------- \-\/-/
// ----> Yassine El khader <---- //