#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <zconf.h>

int main() {
    srand(time(NULL));
    int nbquestions=0;
    int resultat=0;
    int total=0;
    int rep=0;
    printf("A combien de questions voulez-vous répondre\n");
    scanf("%d",&nbquestions);
    for(int i=0;i<nbquestions;i++)
    {
        int nombre1=(rand() % (100)) + 1; //nombre entre 1 et 100
        int nombre2=(rand() % (100 )) + 1; //nombre entre 1 et 100
        /***********************propose une question aléatoire************************************/
        int op=(rand() % (3)) + 1; //nombre entre 1 et 3
        switch (op)
        {
            case 1:
                printf("%d+%d=?\n",nombre1,nombre2);
                resultat=nombre1+nombre2;
                break;
            case 2:
                printf("%d-%d=?\n",nombre1,nombre2);
                resultat=nombre1-nombre2;
                break;
            case 3:
                printf("%d*%d=?\n",nombre1,nombre2);
                resultat=nombre1*nombre2;
                break;

        }
        /*********************Génération des réponses possibles***********************************/
        int j=0;
        for(int i=0;i<3;i++)
        {

            if(i==0)
                j=rand()%2; //definit sur quel numéro de question sera positionnée
            if(i==j)
            {
                rep=resultat; //on positionne le résultat

            }
            else { // cas resultat aléatoire
                if(op==3) //si multiplication on ajuste le résultat
                rep = (rand() % 10000) + 1;
                else
                    rep=(rand()%200)+1; //autrement calcul standard
            }
            printf("%d\n",rep);
        }
        /********************saisie de la réponse************************************************/
        int reputil=0;

        printf("Veuillez choisir une réponse\n");
        scanf("%d",&reputil);
        /********************Vérification du résultat et calcul du total*************************/
        if(reputil== resultat)
        {
            printf("Bonne réponse\n");
            total++;
        }
        else
        {
            printf("La Réponse est fausse la bonne réponse est %d\n",resultat);
        }
    }
    printf("Votre total de bonne réponse est de %d sur %d\nMerci d'avoir jouer",total,nbquestions);


}