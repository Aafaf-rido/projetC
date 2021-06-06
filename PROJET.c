#include <stdio.h>
#include <stdlib.h>

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




typedef struct Client
{
 int idClient;
 char nom[20];
 char prenom[20];
 int cin;
 char adresse[15];
 int telephone;
}client;

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
} contrat;





//Fonctions
//Menu Gestion
void AfficherListe(FILE *f){
    FILE *fichier;
    char c;
    fichier=fopen(f,"r");
    c=fgetc(fichier);
    while(c!=EOF)
        printf("%c",c);
    fclose(fichier);


}




                                                                            ////*********  MENU GESTION  voiture  ****************//


//FONCTION QUI AFFICHE LA LISTE DES VOITURES DEJA ENREGISTREES DANS LE FICHIER << VOITURES >>

int ListeVoitures(){ 
//	char texte[256];
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
        	printf(" En location                   : %s\n",V.EnLocation);
            printf("\n");
			printf("\n");     
		}
	fclose(liste_voiture); 
	}
return 0;
}



////////// FONCTION DE RECHERCHE:  cherche une voiture d'apres son ID (passé comme paramétre de la fct) 

int rechV(int num){
FILE *F;
voiture v;
F=open("voitures.txt","r");
do{
fscanf(F,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",&v.marque,&v.idVoiture,&v.nomVoiture,&v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation);
//avec cette boucle on fait la lecture de tout le fichier ligne par ligne
	if(v.idVoiture==num){
        fclose(F);
        return 1; //s il trouve le id
 	}
   }while(!feof(F));
fclose(F);
return -1; // s il ne trouve pas
}


//////////// FONCTION D AJOUT: ajoute une voiture a la fin du fichier <voitures>

void Ajouter(){
    FILE*ajouter_voiture=NULL;
    voiture new;
    voiture v;
    int id;
    ajouter_voiture=fopen("voitures.exe","a");
    if(!ajouter_voiture){
      printf("ERROR");
	}
	else
	{ printf("donner l id du voiture \n");
	  scanf("%d",&id);
	// il faut verifier d'abord si le ID saisi n'existe pas deja dans le fichier (on ne peut pas avoir deux voitures avec le meme ID )
	   while(rechV(id)==1){
	   	printf(" ce id existe deja \n");
	   	printf(" Enter une nouvelle valeur de  idVoiture \n");
	   	scanf("%d",&id);
	   }
    printf("id Voiture:\n");
    scanf("%d",&new.idVoiture);
    printf("Marque:\n");
    scanf("%s",&new.marque);
    printf("Nom voiture:\n");
    scanf("%s",&new.nomVoiture);
    printf("Couleur:\n");
    scanf("%s",&new.couleur);
    printf("Nombre places:\n");
    scanf("%d",&new.nbplaces);
    printf("En location:\n");
    scanf("s",&new.EnLocation);
    printf("Prix jour:\n");
    scanf("%d",&new.prixJour);
    fprintf(ajouter_voiture,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",v.marque,v.idVoiture,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
	fclose(ajouter_voiture);

}}
//////////// FONCTION DE MODIFICATION VOITURE

int ModifierVoiture(){
FILE*F,*temp; // on ajoute ce pointeur temp pour cette fct car on aura besoin de deux fichiers, le fichier pincipale <voitures> et un fichier temporaire 
int id;
voiture V;
  
   do{ 	
	    printf("\n saisir le id de voiture a modifier \n");
        scanf("%d",&id);
   }while(rechV(id)!=1); // on verifie si le id de cette voiture existe ,sinon on demande de saisir un autre ID 
   
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












//////////// FONCTION POUR SUPPRIMER UNE VOITURE		
int SupprimerVoiture()                                                                 //pour la suppression d une voiture on aura besoin de deux fichier, d abord on demande de saisir id de voiture  
{ 
 voiture V;
 int id;
 FILE *temp,*F;
 do{
 	printf("Entrez le id de la voiture a supprimer \n");
    scanf("%d",&id);	
 }while(rechV(id)!=1);
 
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
 
 
 
 
 
 
 
 

 
 
 
 
 
 
	 	
	 	


                                                         ////*********  LA PARTIE DE CONTRAT  ****************//


//FONCTION QUI AFFICHE UN CONTRAT D APRES SON NUMERO  

void  VisualiserContrat()
{ 
contrat cont;
FILE*F;
float  num;
printf("\n saisir le numero de contrat   :\n");
scanf("%f",&num);
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








// LOCATION D UNE VOITURE
void LouerVoiture()
{
contrat cont;
client C;
voiture V;
int dispo=0,aideV=0,aideC=0 ; // j'ai utiliser ces variables juste pour verifier s'ils changeront aprés chaque teste
int IdV,IdC;
FILE*Voiture;
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
	printf("Ce client n'est pas enregistrer, veuillez saisir vos information  a travers le menu de GESTION CLIENT\n");	
}
//VERIFICATION DES INFOS DE VOITURE

		
if(rechV(IdV)==1){ //verifier si le ID du voiture existe
aideV=1;
printf("la voiture existe \n");
}	  
else{
	printf("cette voiture n'existe pas !!");
}
// verrifier si la voiture est disponible ou non 
 
if(strcmp(V.EnLocation,"non")==0|| strcmp(V.EnLocation,"NON")==0)
	    dispo=1;	    // voiture disponible
if(strcmp(V.EnLocation,"oui")==0|| strcmp(V.EnLocation,"OUI")==0){
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
fprintf(Contrat,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n \n \n",cont.numContrat,cont.idVoiture,cont.idClient,cont.debut.jour,cont.debut.mois,cont.debut.annee,cont.fin.jour,cont.fin.mois,cont.fin.annee,cont.cout);
fclose(Contrat);  
 printf("********* le contrat est cree **********\n");
 Voiture=fopen("voitures.txt","a");
// On doit changer l etat de voiture, de non a oui car la voiture n'est plus dsponible apres la creation du contrat
rewind(Voiture);  // on remet le curseur au début du fichier
fseek(Voiture,-3,SEEK_END); // on place le curseur à la fin du fichier puis on le deplace 3(le nomre de lettre de "non")lettre avant la position courante 
fputs("oui",Voiture);     // on ecrase "non" par "oui"
fclose(Voiture);          //fermeture de fichier 
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
voit=fopen("voitures.txt","w");
do{
fscanf(voit,"%s\n%d\n%s\n%s\n%d\n%d\n%s\n",&V.marque,&V.idVoiture,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);		
	if(V.idVoiture==IdR){
	strcpy(V.EnLocation,"Non"); // on change l'etat de cette voiture 		
	// LA VOITURE N'EST PLUS DISPONIBLE DONC ON SUPPRIME LE CONTRAT        
	SupprimerCont(IdR); 
	}		
}while(!feof(voit));
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
























//FOCTION POUR SUPPRIMER UN CONTRAT D APRES LE ID DE VOITURE 
void SupprimerCont(int IdVoiture)
{ 
 contrat cont ;
 int id;
 printf("Entrez le id de la voiture dont vous voulez retourner \n");
 scanf("%d",&id);
 
	 if(rechCont1(id)==1)
	 { FILE *temp,*F;
	 F=fopen("contarts.txt","r");
	 temp=fopen("tempContrat.txt","a");
		 do{
	     fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jour,&cont.debut.mois,&cont.debut.annee,&cont.fin.jour,&cont.fin.mois,&cont.fin.annee,&cont.cout); 		
			 if(IdVoiture!=cont.idVoiture){
			 fprintf(temp,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",cont.numContrat,cont.idVoiture,cont.idClient,cont.debut.jour,cont.debut.mois,cont.debut.annee,cont.fin.jour,cont.fin.mois,cont.fin.annee,cont.cout);		
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






void ModifierContrat(){
	FILE *F,*temp;
	int Id,nb;
	contratLocation cont;
	do{
		printf("saisir l Id du contrat a modifier:\n");
 		scanf("%d",&Id)	
		
	}while(rechCont1)!=1;

	do{
		printf("saisir le nombre de jour a ajouter(nombre<20 jours)\n");
		scanf("%d",&nb);			
	}while(nb>20);
	F=fopen("contarts.txt","r");
	   
    temp=fopen("tempContrats.txt","a");	
	
	do{
	fscanf(F,"%f\n%d\n%d\n%d %d %d \n %d %d %d \n %d \n",&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jour,&cont.debut.mois,&cont.debut.annee,&cont.fin.jour,&cont.fin.mois,&cont.fin.annee,&cont.cout);	
	    if(id==cont.numContrat){
	    	
	    	if(cont.fin.mois==4||cont.fin.mois==6 ||cont.fin.mois==9 ||cont.fin.mois==11){
	    		
	    		if(cont.fin.jour+nb>30){
	    			
					cont.fin.jour=(cont.fin.jour+nb)-30;
	    			
					if(cont.fin.mois==12){
						cont.fin.mois==1;
						cont.fin.annee++;
					}else{ cont.fin.mois++};
				}else{ cont.fin.mois+=nb; };
	    		
	    		
			
			}else{
				
				if(cont.fin.mois==2){
					
					if((cont.fin.mois%4==0 && cont.fin.mois%100!=0 || cont.fin.mois%400==0 )){
						
						if(cont.fin.jour+nb>28){
							
							cont.fin.jour=(cont.fin.jour+nb)-28;
							if(cont.fin.mois==12){
								
								cont.fin.mois==1;
								cont.fin.annee++;
					
							}else{ cont.fin.mois++};
						}else{ cont.fin.mois+=nb; };
							
				
					}else{
						
						if(cont.fin.jour+nb>29){
							
							cont.fin.jour=(cont.fin.jour+nb)-29;
							if(cont.fin.mois==12){
								
								cont.fin.mois==1;
								cont.fin.annee++;
					
							}else{ cont.fin.mois++};
						}else{ cont.fin.mois+=nb; };
								
					}
					
				
				}else{
	    				if(cont.fin.jour+nb>30){

							cont.fin.jour=(cont.fin.jour+nb)-30;
	    			
							if(cont.fin.mois==12){
						
								cont.fin.mois==1;
								cont.fin.annee++;
					
							}else{ cont.fin.mois++};
						}else{ cont.fin.mois+=nb; };
	
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





////////// FONCTION DE RECHERCHE: on cherche un client d'apres son ID (passé comme paramétre de la fct)  


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
	  
	   while(rechC(id)==1){
	   	printf(" ce id existe deja \n");
	   	printf(" Enter une nouvelle valeur de  idCLIENT \n");
	   	scanf("%d",&id);
	   }
	C.idClient=id;
	printf("saisir le nom du client \n");
	scanf("%s",&C.nom);
	
	printf("saisir le prenom \n"); 
	scanf("%s",&C.prenom);
	
	printf("saisir le cin du client \n");
	scanf("%d",&C.cin);
	
    printf("saisir l adresse du client  \n");
	scanf("%s",&C.adresse);
	
	printf(" saisir le num du telephone \n");
	scanf("%d",&C.telephone);
	printf("\n");
	printf("\n");
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

if(rechC(id)==1){
	F=fopen("clients.txt","r");
	temp=fopen("tempClients.txt","a");
	do{
	  fscanf(F,"%s\n%s\n%d\n%d\n%s\n%d\n",C.nom,C.prenom,&C.idClient,&C.cin,C.adresse,&C.telephone);// apres la lecture du fichier ligne par lingne on copie tout le fichier <clients> dans le fichier temporaire <tempClients> en modifiant le client avec l id saisi au debut 		
	    if(id==C.idClient){
	        printf("saisir le nom du client \n");
	        scanf("%s",&C.nom);
       	    
	        printf("saisir le prenom \n"); 
         	scanf("%s",&C.prenom);
	
	        printf("saisir le id du client \n"); 
	        scanf("%d",&C.idClient);

	        printf("saisir le cin du client \n");
         	scanf("%d",&C.cin);
	
            printf("saisir l adresse du client  \n");
        	scanf("%s",&C.adresse);
	
	        printf(" saisir le num du telephone \n");
        	scanf("%d",&C.telephone);
	
		}
    	// saisie des informations du clients dans le fichier en effectuant les modification voulues,  	
    	fprintf(temp,"%s\n%s\n%d\n%d\n%s\n%d\n",C.nom,C.prenom,C.idClient,C.cin,C.adresse,C.telephone);
	}while(!feof(F));
fclose(F);
fclose(temp);
 //maintenant le fichier <tempClients> contient les informations qu on veut,donc il faut supprimer le fichier <clients> et renomer <tempClients> ,
remove("clients.txt");
rename("tempClients.txt","clients.txt");
return 0;    	
}else{
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
 
 if(rechC(id)==1){
 	
     FILE *temp,*F;
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
	 
   }else{ printf("ce id n existe pas \n"); }
	return 0;
}
















 main(){
  

 }







