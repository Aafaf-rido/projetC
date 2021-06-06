#include<gtk/gtk.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


typedef struct Voiture
{
int idVoiture;
char marque[15];
char nomVoiture[15];
char couleur[7];
int nbplaces;
int prixJour;
char EnLocation[4];
} voiture;


typedef struct date
{
 int jour;
 int mois;
 int annee;
}date;


typedef struct contratLocation
{
float numContrat;
int idVoiture;
int idClient;
date debut;
date fin;
int cout;
}contrat;



typedef struct client
{
int idClient;
char nom[20];
char prenom[20];
int cin;
char adresse[15];
int telephone;
}client;


                                                                            ////*********  LA PARTIE DE voiture  ****************//


////////// FONCTION DE RECHERCHE: on cherche une voiture d'apres son ID (passé comme paramétre de la fct)
int rech(int Numrech){
FILE *F;
voiture V;
F=fopen("voitures.txt","r");
do{
fscanf(F,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",V.marque,&V.idVoiture,V.nomVoiture,V.couleur,&V.nbplaces,&V.prixJour,V.EnLocation);//avec cette boucle on fait la lecture de tout le fichier ligne par ligne
fflush(stdin);
	if(V.idVoiture==Numrech){
    fclose(F);
    return 1; //s il trouve le id
 	}
   }while(!feof(F));
fclose(F);
return -1; // s il ne trouve pas
}


//FONCTION QUI AFFICHE LA LISTE DES VOITURES DEJA ENREGISTREES DANS LE FICHIER << VOITURES >>
void  ListeVoitures(){
	char texte[256];
	FILE*liste_voiture=NULL;
	voiture V;
    liste_voiture=fopen("voitures.txt","r");
    if(!liste_voiture){
      printf("ERROR");// Tester l’ouverture du fichier
	}
	else //l'ouverture a réussi ,aprés on lit le fichier puis on l'affiche selon la structure du fichier texte qu'on a déja saisi
	{

    printf("la listes des voitures : \n");

		while ( !feof(liste_voiture)){
	    	fscanf(liste_voiture,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",V.marque,&V.idVoiture,V.nomVoiture,V.couleur,&V.nbplaces,&V.prixJour,V.EnLocation);
			printf("la marque est                  : %s\n",V.marque);
        	printf("le id     est                  : %d\n",V.idVoiture);
        	printf("le nom    est                  : %s\n",V.nomVoiture);
        	printf("la couleur est                 : %s\n",V.couleur);
        	printf("le nb de places est            : %d\n",V.nbplaces);
        	printf("le prix pour un jour est       : %d\n",V.prixJour);
        	printf(" En location                     : %s\n",V.EnLocation);
            printf("\n");
			printf("\n");
		}
	fclose(liste_voiture);
	}

}


//////Fonction qui ajoute une voiture a la fin du fichier <voitures>
int AjouterVoiture(){
	FILE*ajouter_voiture=NULL;
	voiture V;
	int id;
    ajouter_voiture=fopen("voitures.txt","a");
    if(!ajouter_voiture){
      printf("ERROR");
	}
	else
	{ printf("donner l id du voiture \n");
	  scanf("%d",&id);
	  fflush(stdin);
	// il faut verifier d'abord si le ID saisi n'existe pas deja dans le fichier (on ne peut pas avoir deux voitures avec le meme ID )
	   while(rech(id)==1){
	   	printf(" ce id existe deja \n");
	   	printf(" Enter une nouvelle valeur de  idVoiture \n");
	   	scanf("%d",&id);
	   }
	V.idVoiture=id; // pas la peine de redemander de saisir l ID de voiture
	printf("saisir la marque de voiture \n");
	scanf("%s",&V.marque);
	fflush(stdin);
	printf("saisir le nom de la voiture \n");
	scanf("%s",&V.nomVoiture);
	fflush(stdin);
	printf("saisir la couleur de la voiture \n");
	scanf("%s",&V.couleur);
	fflush(stdin);
	printf("saisir le nb de places \n");
	scanf("%d",&V.nbplaces);
	fflush(stdin);
    printf("saisir le prix par jour \n");
	scanf("%d",&V.prixJour);
	fflush(stdin);
	printf("En location  \n");
	scanf("%s",&V.EnLocation);
	fflush(stdin);
	//ajouter les informations saisies dans le fichier a la fin du fichier <voiture >
    fprintf(ajouter_voiture,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",V.marque,V.idVoiture,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);
	fclose(ajouter_voiture);
	}
return 0;
}

///////FONCTION POUR MODIFIER UNE VOITURE
int ModifierVoiture(){
FILE*F,*temp; // on ajoute ce pointeur temp pour cette fct car on aura besoin de deux fichiers, le fichier pincipale <voitures> et un fichier temporaire
int id;
voiture V;
printf("\n saisir le id de voiture a modifier \n");
scanf("%d",&id);
fflush(stdin);
	if(rech(id)==1){ // on verifie si le id de cette voiture existe ,sinon on demande de saisir un autre ID
	F=fopen("voitures.txt","r");
	temp=fopen("tempVoitures.txt","a");
	do{
	fscanf(F,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",&V.marque,&V.idVoiture,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
	    if(id==V.idVoiture){
	    printf("saisir la  marque \n");
		scanf("%s",&V.marque);
		printf("saisir le  id de la voiture \n");
	    scanf("%d",&V.idVoiture);
		printf("saisir le nom de voiture \n");
		scanf("%s",&V.nomVoiture);
		printf("saisir la couleur \n");
		scanf("%s",&V.couleur);
		printf("saisir le nb de places  \n");
		scanf("%d",&V.nbplaces);
		printf("saisir le prix par jour \n");
		scanf("%d",&V.prixJour);
		printf("est ce qu elle est en Location ? \n");
		scanf("%s",&V.EnLocation);
		}
	// apres la lecture du fichier ligne par lingne on copie tout le fichier <voitures> dans le fichier temporaire <tempVoitures> en modifiant la voiture avec l id saisi au debut
	fprintf(temp,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",V.marque,V.idVoiture,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation); // saisie les informations de la voiture dans le fichier en effectuant les modification
	}while(!feof(F));
fclose(F);
fclose(temp);
// maintenant le fichier <tempVoitures> contient les informations qu on veut,donc il faut supprimer le fichier <voitures> et renomer <tempVoitures> ,
remove("voitures.txt");
rename("tempVoitures.txt","voitures.txt");
return 0;
}
	else{
	printf("ce id n'existe pas\n'");
	}
}


//////////// FONCTION POUR SUPPRIMER UNE VOITURE
int SupprimerVoiture()                                                                 //pour la suppression d une voiture on aura besoin de deux fichier, d abord on demande de saisir id de voiture
{
 voiture V;
 int id;
 printf("Entrez le id de voiture a supprimer \n");
 scanf("%d",&id);
 fflush(stdin);
	 if(rech(id)==1)
	 { FILE *temp,*F;
	 F=fopen("voitures.txt","r");
	 temp=fopen("tempVoiture.txt","a");
		 do{                                                                                                                             //cette boucle permet de lire le fichier ligne par ligne tant que le id
	     fscanf(F,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",&V.marque,&V.idVoiture,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);	//de la voiture qu on a lit est defférent de l id de la voiture qu on veut supprimer
			 if(id!=V.idVoiture){                                                                                                            //on ajoute ces information au fichier temporaire
			 fprintf(temp,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",V.marque,V.idVoiture,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);
			 }
		 }while(!feof(F));
	 fclose(temp);
	 fclose(F);
	 // maintenant le fichier <tempVoiture> contient les informations qu on veut,donc il faut supprimer le fichier <voitures> et renomer <tempVoiture> ,
	 remove("voitures.txt");
	 rename("tempVoiture.txt","voitures.txt");
	 printf("LA SUPPRESSION EST FAITE \n");

	 }
	 else{
	 	printf("ce id n existe pas \n");

	 }
}

////////// FONCTION DE RECHERCHE du client d'apres son ID entré en parametre , j'ai definie cette fct ici cr j'aurai besoin de l'utiliser pour la partie location
int rechC(int NumRECH){
FILE *f;
client C;
f=fopen("Clients.txt","r");
do{
fscanf(f,"%s\n%s\n%d\n%d\n%s\n%d\n",C.nom,C.prenom,&C.idClient,&C.cin,C.adresse,&C.telephone);
fflush(stdin);
	if(C.idClient==NumRECH){
    fclose(f);
    return 1;
 	}
   }while(!feof(f));
fclose(f);
return -1; // s il ne trouve pasce ID
}


                                                         ////*********  LA PARTIE DE CONTRAT  ****************//
//FONCTION QUI AFFICHE UN CONTRAT D APRES SON NUMERO
void  VisualiserContrat()
{
contrat cont;
FILE*F;
float  num;
printf("\n saisir le numero de contrat   :\n");
scanf("%f",&num);
fflush(stdin);
F=fopen("contrats.txt","r");
	do{

	 fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jour,&cont.debut.mois,&cont.debut.annee,&cont.fin.jour,&cont.fin.mois,&cont.fin.annee,&cont.cout);
		if(cont.numContrat==num){ // Si on trouve le numero de contrat on l'affiche


			printf("le numero de contrat           : %f\n",cont.numContrat);
        	printf("le ID de voiture               : %d\n",cont.idVoiture);
        	printf("le ID de client                : %d\n",cont.idClient);
        	printf("la date de debut               : %d %d %d \n",cont.debut.jour,cont.debut.mois,cont.debut.annee);
        	printf("la date de fin                 : %d %d %d \n",cont.fin.jour,cont.fin.mois,cont.fin.annee);
        	printf("le cout est                    : %d\n",cont.cout);
            printf("\n");
			printf("\n");
		}

	}while(!feof(F));
fclose(F);
}

//FONCTION DE RECHERCHE D UN CONTRAT D APRES LE Id DE VOITURE LOUEE
int rechCont1(int Num){
FILE *F;
contrat cont;
F=fopen("contrats.txt","r");
do{
fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jour,&cont.debut.mois,&cont.debut.annee,&cont.fin.jour,&cont.fin.mois,&cont.fin.annee,&cont.cout);
fflush(stdin);
	if(cont.idVoiture==Num){
    fclose(F);
    return 1;
 	}
   }while(!feof(F));
fclose(F);
return -1;  // s il ne trouve pas le  id de contrat
}
//FONCTION DE RECHERCHE D UN CONTRAT D APRES LE NUM DE CONTRAT
int rechCont2(int Num){
FILE *F;
contrat cont;
F=fopen("contrats.txt","r");
do{
fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jour,&cont.debut.mois,&cont.debut.annee,&cont.fin.jour,&cont.fin.mois,&cont.fin.annee,&cont.cout);
fflush(stdin);
	if(cont.numContrat==Num){
    fclose(F);
    return 1;
 	}
   }while(!feof(F));
fclose(F);
return -1;  // s il ne trouve pas
}

// LOCATION D UNE VOITURE
void LouerVoiture()
{
contrat cont;
client C;
voiture V;
int dispo=0,aideV=0,aideC=0 ; // j'ai utiliser ces variables juste pour verifier s'ils changeront aprés chaque teste
int IdV,IdC;
FILE*Voiture;
FILE *Client;
FILE*Contrat;
printf("LES INFORMATIONS DU CLIENT :");
printf("Entrez le Id de client \n");
scanf("%d",&IdC);
printf("LES INFORMATIONS SUR LA VOITURE :");
printf("saisir le ID de la voiture \n");
scanf("%d",&IdV);
//VERIFICATION POUR LE CLIENT
if(rechC(IdC)==1){ //verifier si le ID du clients existe
	aideC=1;      // donc la voiture existe dans le fichier <voitures>
}
else{
	printf("Ce client n'est pas enregistre, veuillez saisir vos information  a travers le menu de GESTION CLIENT\n");
}
//VERIFICATION DES INFOS DE VOITURE
Voiture=fopen("voitures.txt","r");

if(rech(IdV)==1){ //verifier si le ID du voiture existe
aideV=1;
printf("la voiture existe \n");
}
else{
	printf("cette voiture n'existe pas !!");
}
// verrifier si la voiture est disponible ou non

if(strcmp(V.EnLocation,"non")|| strcmp(V.EnLocation,"NON")==0)
	    dispo=1;	    // voiture disponible
if(strcmp(V.EnLocation,"oui")|| strcmp(V.EnLocation,"OUI")==0){
		dispo=0;
}
if(dispo==0 && aideV==1){
printf(" la voiture n'est pas desponible \n ");
}
if(dispo==1 && aideV==1){ // voiture existe et disponible donc on vas creer un contrat

printf(" la voiture est  disponible vous pouvez creer un contrat : \n");
FILE *Contrat=fopen("contrats.txt","a");
 	printf("*****entrez les informations concernant le contrat:******\n\n");
  	printf("entrez le numero de contrat:\n");
  	scanf("%f",&cont.numContrat);
	printf("entrez le id de voiture:\n");
  	scanf("%d",&cont.idVoiture);
  	printf("entrez id de client:\n");
    scanf("%d",&cont.idClient);
  	printf("entrez date de debut:\n");
  	scanf("%d %d %d",&cont.debut.jour,&cont.debut.mois,&cont.debut.annee);
  	printf("entrez date de fin :\n");
  	scanf("%d %d %d",&cont.fin.jour,&cont.fin.mois,&cont.fin.annee);
  	printf("entrez cout:\n");
    scanf("%d",&cont.cout);
// apres la creeation on ajoute le contrat au fichier <contrats>
fprintf(Contrat,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",cont.numContrat,cont.idVoiture,cont.idClient,cont.debut.jour,cont.debut.mois,cont.debut.annee,cont.fin.jour,cont.fin.mois,cont.fin.annee,cont.cout);
fclose(Contrat);
 printf("********* le contrat est cree **********\n");
// On doit changer l etat de voiture, de non a oui car la voiture n'est plus dsponible apres la creation du contrat
rewind(Voiture);  // on remet le curseur au début du fichier
fseek(Voiture,-3,SEEK_END); // on place le curseur à la fin du fichier puis on le deplace 3(le nomre de lettre de "non")lettre avant la position courante
fputs("oui",Voiture);     // on ecrase "non" par "oui"
fclose(Voiture);          //fermeture de fichier
}
}

//FOCTION POUR SUPPRIMER UN CONTRAT D APRES LE ID DE VOITURE
void SupprimerCont(int IdVoiture)
{
 contrat cont ;
 int id;
 printf("Entrez le id de la voiture dont vous voulez retourner \n");
 scanf("%d",&id);
 fflush(stdin);
	 if(rechCont1(id)==1)
	 { FILE *temp,*F;
	 F=fopen("contarts.txt","r");
	 temp=fopen("tempContrat.txt","a");
		 do{
	     fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jour,&cont.debut.mois,&cont.debut.annee,&cont.fin.jour,&cont.fin.mois,&cont.fin.annee,&cont.cout);
			 if(IdVoiture!=cont.idVoiture){
			 fprintf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",cont.numContrat,cont.idVoiture,cont.idClient,cont.debut.jour,cont.debut.mois,cont.debut.annee,cont.fin.jour,cont.fin.mois,cont.fin.annee,cont.cout);
			 }
		 }while(!feof(F));
	 fclose(temp);
	 fclose(F);
	 remove("contrats.txt");
	 rename("tempContrat.txt","contrats.txt");
	 }
	 else{
	 	printf("ce id n existe pas \n");
     }
}

//////// FONCTION POUR RETOURNER UNE VOITURE DEJA LOUEE
void RetournerVoiture()
{
int IdR;
FILE*voit;
voiture V;
printf(" Saisir le Id de voiture a retourne \n");
scanf("%d",&IdR);
voit=fopen("voitures.txt","r");
do{
fscanf(voit,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",&V.marque,&V.idVoiture,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
	if(V.idVoiture==IdR){
	strcpy(V.EnLocation,"Non"); // on change l'etat de cette voiture
	// LA VOITURE N'EST PLUS DISPONIBLE DONC ON SUPPRIME LE CONTRAT
	SupprimerCont(IdR);
	}
}while(!feof(voit));
}


// UNE FCT QUI CALCULE la date de retourne en lui donnant le nombre de jour et la date de debut
date DateRetour( date D, int nbJ){
int som;
som=D.jour+nbJ;
	if(som>31){
	D.jour=60-som;
	D.mois=D.mois+1;
		if(D.mois>12){
		D.mois=1;
		D.annee=D.annee+1;
		}

	}
	else{
	D.jour=D.jour+nbJ;
	}
return D;
}


// FONCTION POUR MODIFIER LA DATE DE RETOUR D UNE VOITURE







void ModifierContrat(){
	FILE *F,*temp;
	int Id,nb;
	contrat cont;
	do{
		printf("saisir l Id du contrat a modifier:\n");
 		scanf("%d",&Id);

	}while(rechCont1!=1);

	do{
		printf("saisir le nombre de jour a ajouter(nombre<20 jours)\n");
		scanf("%d",&nb);
	}while(nb>20);
	F=fopen("contarts.txt","r");

    temp=fopen("tempContrats.txt","a");

	do{
	fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jour,&cont.debut.mois,&cont.debut.annee,&cont.fin.jour,&cont.fin.mois,&cont.fin.annee,&cont.cout);
	    if(Id==cont.numContrat){

	    	if(cont.fin.mois==4||cont.fin.mois==6 ||cont.fin.mois==9 ||cont.fin.mois==11){

	    		if(cont.fin.jour+nb>30){

					cont.fin.jour=(cont.fin.jour+nb)-30;

					if(cont.fin.mois==12){
						cont.fin.mois==1;
						cont.fin.annee++;

                }else{ cont.fin.mois++;}
				}else{ cont.fin.mois+=nb; }



			}else{

				if(cont.fin.mois==2){

					if((cont.fin.mois%4==0 && cont.fin.mois%100!=0 || cont.fin.mois%400==0 )){

						if(cont.fin.jour+nb>28){

							cont.fin.jour=(cont.fin.jour+nb)-28;
							if(cont.fin.mois==12){

								(cont.fin.mois==1);
								(cont.fin.annee++);

							}else{ cont.fin.mois++;}
						}else{ cont.fin.mois+=nb; }


					}else{

						if(cont.fin.jour+nb>29){

							cont.fin.jour=(cont.fin.jour+nb)-29;
							if(cont.fin.mois==12){

								cont.fin.mois==1;
								cont.fin.annee++;

							}else{ cont.fin.mois++;}
						}else{ cont.fin.mois+=nb; }

					}


				}else{
	    				if(cont.fin.jour+nb>30){

							cont.fin.jour=(cont.fin.jour+nb)-30;

							if(cont.fin.mois==12){

								cont.fin.mois==1;
								cont.fin.annee++;

							}else{ cont.fin.mois++;}
						}else{ cont.fin.mois+=nb; }

				}

			}
	// apres la lecture du fichier ligne par ligne on copie tout le fichier <contrats> dans le fichier temporaire <tempContrats> en modifiant la voiture avec l id saisi au debut
	fprintf(temp,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",cont.numContrat,cont.idVoiture,cont.idClient,cont.debut.jour,cont.debut.mois,cont.debut.annee,cont.fin.jour,cont.fin.mois,cont.fin.annee,cont.cout); // saisie les informations du contarts dans le fichier en effectuant les modification
	}while(!feof(F));
fclose(F);
fclose(temp);
// maintenant le fichier <tempContrats> contient les informations qu on veut,donc il faut supprimer le fichier <contrats> et renomer <tempContrats> ,
remove("contrats.txt");
rename("tempContrats.txt","contrats.txt");




}}



                                                              ////*********  LA PARTIE DE CLIENT  ****************//


///////////////FONCTION POUR AFFICHER LES CLIENTS
int ListeClients(){
	char texte[256];
	FILE*liste_clients=NULL;
	client C;
    liste_clients=fopen("Clients.txt","r");
    if(!liste_clients){
      printf("ERROR");
	}
	else
	{
    printf("la listes des clients : \n");
		while ( !feof(liste_clients)){ // cette boucle permet de lire tout le fichier et l'afficher comme il est structuré dans le fichier
	    	fscanf(liste_clients,"%s\n%s\n%d\n%d\n%s\n%d\n",C.nom,C.prenom,&C.idClient,&C.cin,C.adresse,&C.telephone);
			printf("le nom est                      : %s\n",C.nom);
        	printf("le prenom    est                : %s\n",C.prenom);
        	printf("le ID du client  est            : %d\n",C.idClient);
        	printf("le cin de client                : %d\n",C.cin);
        	printf("l adresse du clients            : %s\n",C.adresse);
        	printf("le num de telephone             : %d\n",C.telephone);
            printf("\n");
			printf("\n");
		}
	fclose(liste_clients);
	}
return 0;
}

/////// FONCTION D AJOUT D UN CLIENT
int AjouterClient()
{
	FILE*ajouter_client=NULL;
	client C;
	int id;
    ajouter_client=fopen("clients.txt","a");
    if(!ajouter_client){
      printf("ERROR");
	}
	else
	{ printf("donner l id du CLIENT \n");
	  scanf("%d",&id);
	  fflush(stdin);
	   while(rechC(id)==1){
	   	printf(" ce id existe deja \n");
	   	printf(" Enter une nouvelle valeur de  idCLIENT \n");
	   	scanf("%d",&id);
	   }
	C.idClient=id;
	printf("saisir le nom du client \n");
	scanf("%s",&C.nom);
	fflush(stdin);
	printf("saisir le prenom \n");
	scanf("%s",&C.prenom);
	fflush(stdin);
	printf("saisir le cin du client \n");
	scanf("%d",&C.cin);
	fflush(stdin);
    printf("saisir l adresse du client  \n");
	scanf("%s",&C.adresse);
	fflush(stdin);
	printf(" saisir le num du telephone \n");
	scanf("%d",&C.telephone);
	fflush(stdin);
	//ajouter  ce client a la fin du fichier
    fprintf(ajouter_client,"%s\n%s\n%d\n%d\n%s\n%d\n",C.nom,C.prenom,C.idClient,C.cin,C.adresse,C.telephone);
	fclose(ajouter_client);
	}
return 0;
}

/////////////// FONCTION POUR MODIFIER UN CLIENT
int ModifierClient()
{
FILE*F,*temp;
int id;
client C;
printf("\n saisir le id du client a modifier \n");
scanf("%d",&id);
fflush(stdin);
	if(rechC(id)==1){
	F=fopen("clients.txt","r");
	temp=fopen("tempClients.txt","a");
	do{
	fscanf(F,"%s\n%s\n%d\n%d\n%s\n%d\n",C.nom,C.prenom,&C.idClient,&C.cin,C.adresse,&C.telephone);// apres la lecture du fichier ligne par lingne on copie tout le fichier <clients> dans le fichier temporaire <tempClients> en modifiant le client avec l id saisi au debut
	    if(id==C.idClient){
	printf("saisir le nom du client \n");
	scanf("%s",&C.nom);
	fflush(stdin);
	printf("saisir le prenom \n");
	scanf("%s",&C.prenom);
	fflush(stdin);
	printf("saisir le id du client \n");
	scanf("%d",&C.idClient);
	fflush(stdin);
	printf("saisir le cin du client \n");
	scanf("%d",&C.cin);
	fflush(stdin);
    printf("saisir l adresse du client  \n");
	scanf("%s",&C.adresse);
	fflush(stdin);
	printf(" saisir le num du telephone \n");
	scanf("%d",&C.telephone);
	fflush(stdin);
		}
	// saisie les informations du clients dans le fichier en effectuant les modification voulues,
	fprintf(temp,"%s\n%s\n%d\n%d\n%s\n%d\n",C.nom,C.prenom,C.idClient,C.cin,C.adresse,C.telephone);
	}while(!feof(F));
fclose(F);
fclose(temp);
 //maintenant le fichier <tempClients> contient les informations qu on veut,donc il faut supprimer le fichier <clients> et renomer <tempClients> ,
remove("clients.txt");
rename("tempClients.txt","clients.txt");
return 0;
}
	else{
	printf("ce id n'existe pas\n'");
	}
return 0;
}


//////// FCONCTION POUR SUPPRIMER UN CLIENT
int  SupprimerClient()
{
 client C;
 int id;
 printf("Entrez le id du client a supprimer \n");
 scanf("%d",&id);
 fflush(stdin);
	 if(rechC(id)==1)
	 { FILE *temp,*F;
	 F=fopen("clients.txt","r");
	 temp=fopen("tempClient.txt","a");
		 do{                                                                                                         /*cette boucle permet de lire le fichier ligne par ligne tant que le id
																													du client qu on a lit est différent de l id du client qu on veut supprimer
																													on ajoute ces information au fichier temporaire*/
	     fscanf(F,"%s\n%s\n%d\n%d\n%s\n%d\n",C.nom,C.prenom,C.idClient,&C.cin,C.adresse,&C.telephone);
			 if(id!=C.idClient){
			 fprintf(temp,"%s\n%s\n%d\n%d\n%s\n%d\n",C.nom,C.prenom,C.idClient,C.cin,C.adresse,C.telephone);
			 }
		 }while(!feof(F));
	 fclose(temp);
	 fclose(F);
	 remove("clients.txt");
	 rename("tempClient.txt","clients.txt");
	 printf("LA SUPPRESSION EST FAITE \n");

	 }
	 else{
	 	printf("ce id n existe pas \n");

	 }
	return 0;
}























GtkBuilder *builder;


//declation de la fenetre menu principale et ces bouttons
GtkWidget *window1;
GtkWidget *button1;
GtkWidget *button2;
GtkWidget *button3;
GtkWidget *button4;





//declation de la Location d'une voiture et ces bouttons
GtkWidget *window2;
GtkWidget *button5;
GtkWidget *button6;
GtkWidget *button7;
GtkWidget *button8;
GtkWidget *button9;
GtkWidget *button10;


//declation de Gestion des voitures et ces bouttons
GtkWidget *window3;
GtkWidget *button11;
GtkWidget *button12;
GtkWidget *button13;
GtkWidget *button14;
GtkWidget *button15;



//declation de Gestion des clients et ces bouttons
GtkWidget *window4;
GtkWidget *button16;
GtkWidget *button17;
GtkWidget *button18;
GtkWidget *button19;
GtkWidget *button20;



void reteur2(){
new_window();
gtk_widget_destroy(window2);
}

void reteur3(){
new_window();
gtk_widget_destroy(window3);
}
void reteur4(){
new_window();
gtk_widget_destroy(window4);
}

void print(){
printf("bonjour");}

void quitte(){
    g_signal_connect(G_OBJECT(window1), "destroy",G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_destroy(window1);
}

void New_window2(GtkWidget *widget,gpointer data){
//creation de la fenetre 3(Gestion des voitures)

builder=gtk_builder_new_from_file("slt.glade");
window2=gtk_builder_get_object(builder,"window2");
button5=gtk_builder_get_object(builder,"button5");
button6=gtk_builder_get_object(builder,"button6");
button7=gtk_builder_get_object(builder,"button7");
button8=gtk_builder_get_object(builder,"button8");
button9=gtk_builder_get_object(builder,"button9");
button10=gtk_builder_get_object(builder,"button10");


g_signal_connect(button5,"clicked",G_CALLBACK(VisualiserContrat),NULL);
g_signal_connect(button6,"clicked",G_CALLBACK( LouerVoiture),NULL);
g_signal_connect(button7,"clicked",G_CALLBACK(RetournerVoiture),NULL);
g_signal_connect(button8,"clicked",G_CALLBACK(ModifierContrat),NULL);
g_signal_connect(button9,"clicked",G_CALLBACK(SupprimerCont),NULL);


 g_signal_connect (button10, "clicked", G_CALLBACK (reteur2), NULL);

    gtk_widget_destroy(window1);

gtk_widget_show_all(window2);
}





void New_window3(GtkWidget *widget,gpointer data){
//creation de la fenetre 2 (Gestion d'une voitures)

builder=gtk_builder_new_from_file("slt.glade");
window3=gtk_builder_get_object(builder,"window3");
button11=gtk_builder_get_object(builder,"button11");
button12=gtk_builder_get_object(builder,"button12");
button13=gtk_builder_get_object(builder,"button13");
button14=gtk_builder_get_object(builder,"button14");
button15=gtk_builder_get_object(builder,"button15");

g_signal_connect(button11,"clicked",G_CALLBACK(ListeVoitures),NULL);
g_signal_connect(button12,"clicked",G_CALLBACK( AjouterVoiture),NULL);
g_signal_connect(button13,"clicked",G_CALLBACK( ModifierVoiture),NULL);
g_signal_connect(button14,"clicked",G_CALLBACK(SupprimerVoiture),NULL);

 g_signal_connect (button15, "clicked", G_CALLBACK (reteur3), NULL);

    gtk_widget_destroy(window1);

gtk_widget_show_all(window3);

}










void New_window4(GtkWidget *widget,gpointer data){
//creation de la fenetre 4(Gestion des clients)





builder=gtk_builder_new_from_file("slt.glade");
window4=GTK_WIDGET(gtk_builder_get_object(builder,"window4"));
button16=GTK_WIDGET(gtk_builder_get_object(builder,"button16"));
button17=GTK_WIDGET(gtk_builder_get_object(builder,"button17"));
button18=GTK_WIDGET(gtk_builder_get_object(builder,"button18"));
button19=GTK_WIDGET(gtk_builder_get_object(builder,"button19"));
button20=GTK_WIDGET(gtk_builder_get_object(builder,"button20"));

g_signal_connect(button16,"clicked",G_CALLBACK(ListeClients),NULL);
g_signal_connect(button17,"clicked",G_CALLBACK(AjouterClient),NULL);
g_signal_connect(button18,"clicked",G_CALLBACK(ModifierClient),NULL);
g_signal_connect(button19,"clicked",G_CALLBACK(SupprimerClient),NULL);


 g_signal_connect (button20, "clicked", G_CALLBACK (reteur4), NULL);

    gtk_widget_destroy(window1);



gtk_widget_show_all(window4);

}
//creation de la premiere fenetre (Menu principal)

void new_window(){


builder=gtk_builder_new_from_file("slt.glade");
window1=gtk_builder_get_object(builder,"window1");
button1=gtk_builder_get_object(builder,"button1");
button2=gtk_builder_get_object(builder,"button2");
button3=gtk_builder_get_object(builder,"button3");
button4=gtk_builder_get_object(builder,"button4");



g_signal_connect(button1,"clicked",G_CALLBACK(New_window2)  ,NULL);
g_signal_connect(button2,"clicked",G_CALLBACK(New_window3)  ,NULL);
g_signal_connect(button3,"clicked",G_CALLBACK(New_window4)  ,NULL);

 g_signal_connect (button4, "clicked", G_CALLBACK (quitte), NULL);

gtk_widget_show_all(window1);
}








int main(int argc,char **argv){

gtk_init(&argc,&argv);

builder=gtk_builder_new_from_file("slt.glade");

new_window();

gtk_main();

return 0;}
