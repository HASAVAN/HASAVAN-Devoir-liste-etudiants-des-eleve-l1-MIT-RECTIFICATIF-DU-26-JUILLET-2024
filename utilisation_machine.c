#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilisation_machine.h"
#define nbr_of_eleve 76

/*----------------------------------------------------------------------------------------------------------------------------*/
void fil(FILE **file ,  char *argv)
{
    *file=fopen(argv,"r");
    if(*file == NULL)
    {
        perror("Error!!!");
    }
}


/*----------------------------------------------------------------------------------------------------------------------------*/
void get_file(FILE *file , ME *st , char *argv)
{
    int i = 1 , j;
    UM me ;
    char chaine[1000];
    fil(&file , argv);
    for(i=1 ; i < nbr_of_eleve ; i++)
    {
        fgets(chaine, 254, file);
        strcpy(st[i].nom ,chaine);
        st[i].numero = i;
        for(j= 0 ; j < strlen(st[i].nom) - 1 ; j++)
        {
            if(st[i].nom[j] == '\n')
                st[i].nom[j] == '\0';
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------*/
void fill_data(FILE *file , ME *st)
{
    int i,j,k,n,c,a,b,d,e,f,g;
    int opt ,tab[nbr_of_eleve];
    int temp , menu , moyen ;
    int temp2 = 0;
    int temp3[k];
    char search[100] , src[100];
    char util[50];
    file=fopen("temporary.csv" , "w+");
    printf("\n");
    printf("\t\t|1| Afficher la liste des eleves \n");
    printf("\t\t    `````````````````````````````\n");
    printf("\t\t|2| Faire la presence des eleves\n");
    printf("\t\t    ``````````````````````````````\n");
    printf("\t\t|3| Quitter\n");
    printf("\t\t    ````````\n");
    printf("\tChoisissez l'option : ");
    scanf("%d",&menu);
    
    do
        {
        while(menu != 1 &&   menu != 2  && menu != 3)
        {
            do
            {
            printf("Erreur!!! Veuillez bien choisir le chiffre ci_dessous\n");
            printf("Reessayer : \n");
            printf("``````````\n");
            printf("\t\t|1| Afficher la liste des eleves \n");
            printf("\t\t    ````````````````````````````\n");
            printf("\t\t|2| Faire la presence des eleves\n");
            printf("\t\t    ````````````````````````````\n");
            printf("\t\t|3| Quitter\n");
            printf("\t\t    `````````\n");
            printf("\toption : ");
            scanf("%d",&menu);
            while((a=getchar() != '\n') && (a != EOF));
            }while(!menu);
        }

        switch (menu)
        {
            case 1 :
                for(i=1 ; i<nbr_of_eleve ; i++)
                    {
                        printf("-----------------------------------------------------------\n");
                        printf("|%d ,%s|\n",i, st[i].nom);
                    }
                    printf("\t\t|2| Faire la presence des eleves\n");
                    printf("\t\t    ````````````````````````````\n");
                    printf("\t\t|3| Quitter\n");
                    printf("\t\t    `````````\n");
                    printf("\t|option| : ");
                    scanf("%d",&menu);
                    if(menu == 3)
                        exit(EXIT_SUCCESS);

            case 2 :
                for(i=1 ; i < nbr_of_eleve ; i++)
                    {
                        printf("\n\n\t1)Rechercher par numero\n\t `````````````````````\n\t2)Rechercher par nom\n\t ```````````````````\n|Choisissez| : ");
                        scanf("%d",&moyen);
                        while(moyen < 1 || moyen > 2 || ((b=getchar() != '\n') && (b != EOF)))
                        {
                            do
                            {
                            printf("\n\n\t1)Rechercher par numero\n\t `````````````````````\n\t2)Rechercher par nom\n\t ```````````````````\n|Choisissez| : ");
                            scanf("%d",&moyen);
                            if(moyen >= 1 && moyen <= 2)
                            {
                                break;
                            }
                            printf("\n\n\t1)Rechercher par numero\n\t `````````````````````\n\t2)Rechercher par nom\n\t ```````````````````\n|Choisissez| : ");
                            while((b=getchar() != '\n') && (b != EOF));
                            }while(!moyen);
                        }
                        switch(moyen)
                        {
                            case 1 :
                                    printf("Entrer le numero de l'etudiant entre 75 et 1 (reesayer si rien ne se passe) : ");
                                    scanf("%d",&temp);
                                    while((temp > 75   || temp < 1) || ((c=getchar() != '\n') && (c != EOF)))
                                    {
                                        do
                                        {
                                            scanf("%d",&temp);
                                            if (temp < 75   && temp > 0)
                                            {
                                                break;
                                            }
                                        while((c=getchar() != '\n') && (c != EOF));
                                        }while(!temp);
                                    }
                                
                                    
                                    tab[i] = temp ;
                                    temp2++;
                                printf("````````````````````````````````````````\n");   
                                printf("|%s n°%d|\n",st[temp].nom ,st[temp].numero);
                                printf("````````````````````````````````````````\n");   
                                for(j=1 ; j<76 ; j++)
                                {
                                        for(k=1 ; k<temp2 ; k++)
                                        {
                                                if(tab[k] == temp)
                                                {
                                                    while(tab[k] == temp)
                                                    {
                                                        printf("Cette personne est deja verifie \n");
                                                        printf("Entrer le numero de l'etudiant : ");
                                                        scanf("%d",&temp);
                                                    }
                                                }
                                        }
                                }
                                
                                do
                                {
                                    printf("Est ce que vous utilisez la machine de MIT ?\t(OUI/NON)\n(NB: NON <=> vous utilisez votre machine personnel)\n");
                                    scanf("%s", util);
                                    if (strcmp(util,"OUI")==0)
                                        {       
                                            st[temp].um=OUI;
                                            break;
                                        }
                                        else if (strcmp(util,"NON")==0)
                                        {
                                            st[temp].um=NON;
                                            break;
                                        }
                                }while(strcmp(util,"OUI")!=0||strcmp(util,"NON")!=0);
                                printf("==> Option <==\n\n1) Quittez\n2) Continuer\n");
                                printf("opt: ");
                                scanf("%d", &opt);
                                while(opt != 1 && opt != 2)
                                {                          
                                    do
                                    {
                                        printf("\nReessayer : ");
                                        scanf("%d", &opt);
                                        while(e=getchar() != '\n'  &&  e !=EOF);
                                    }while(!(scanf("%d",&opt)));
                                }
                                if(opt == 1)
                                {
                                        fprintf(file ,",%d",st[i].numero);
                                        fprintf(file ,"%d",st[i].um);
                                    break;
                                }
                                break;
                        case 2 :
                    do
                    {
                                printf("Entrer le nom a rechercher : ");
                                scanf("%s", search);
                        do
                        {
                                for(k=1 ; k < nbr_of_eleve ; k++)
                                {
                                    strcpy(src , " ")  ;
                                        for(j=0 ; j < 100 ; j++)
                                        {
                                            if(st[k].nom[j] == search[0] &&  st[k].nom[j+1] == search[1] &&  st[k].nom[j+2] == search[2]  &&  st[k].nom[j+3] == search[3]  &&  st[k].nom[j+4] == search[4] &&  st[k].nom[j+5] == search[5] &&  st[k].nom[j+6] == search[6] &&  st[k].nom[j+7] == search[7])
                                            {
                                                printf("n° : %d  %s\n", st[i].numero ,st[i].nom);
                                                printf("%s ",st[k].nom);
                                                printf("est-ce vous ? : ");
                                                scanf("%s",src);
                                                 if(strcmp(src , "OUI") == 0)
                                                {
                                                temp = st[k].numero ;
                                                }
                                                if((strcmp(src , "NON") == 0) || (strcmp(src , "OUI") == 0))
                                                {
                                                   break;
                                                }
                                            }
                                            if( strstr(st[k].nom , search) != 0 )
                                            {
                                                printf("%s ",st[k].nom);
                                                printf("est-ce vous ? : ");
                                                scanf("%s",src);
                                                if((strcmp(src , "NON") == 0) || (strcmp(src , "OUI") == 0))
                                                {
                                                    break;
                                                }
                                                if(strcmp(src , "OUI") == 0)
                                                {
                                                temp = st[k].numero ;
                                                }
                                            }

                                                if(strcmp(src , "OUI") == 0)
                                                {
                                                temp =st[k].numero ;
                                                tab[i] = temp ;
                                                }                                         
                                        }
                                                if(strcmp(src , "OUI") == 0)
                                                {
                                                    //temp = st[k].numero ;
                                                    tab[i] = temp ;
                                                    break;
                                                } 
                                }
                                if(strcmp(src , "OUI") == 0)
                                {
                                    temp = st[k].numero ;
                                    tab[i] = temp ;
                                    //break;
                                } 
                                printf("%d\n",temp);
                                strcpy(src , "OUI");
                        }while((strcmp(src , "NON") == 0));
                                    temp2++;
                                        for(j=1 ; j<76 ; j++)
                                        {
                                                for(k=1 ; k<temp2 ; k++)
                                                {
                                                        if(tab[k] == temp)
                                                        {
                                                                printf("Cette personne est deja verifie \n");
                                                                break;
                                                        
                                                        }
                                                }

                                                        if(tab[k] == temp)
                                                        {
                                                                break;
                                                        
                                                        }
                                        }

                                                        if(tab[k] == temp)
                                                        {
                                                                break;
                                                        
                                                        }
                            }while(tab[k] ==temp);
                                do
                                {
                                    printf("n°%d : %s ",st[temp].numero ,st[temp].nom);
                                    printf("Est ce que vous utilisez la machine de MIT ?\t(OUI/NON)\n(NB: NON <=> vous utilisez votre machine personnel)\n");
                                    scanf("%s", util);
                                    if (strcmp(util,"OUI")==0)
                                        {       
                                            st[temp].um=OUI;
                                            break;
                                        }
                                        else if (strcmp(util,"NON")==0)
                                        {
                                            st[temp].um=NON;
                                            break;
                                        }
                                }while(strcmp(util,"OUI")!=0 || strcmp(util,"NON")!=0);
                                printf("==> Option <==\n\n1) Quittez\n2) Continuer\n");
                                printf("opt: ");
                                scanf("%d", &opt);
                                if(opt == 1)
                                {
                                    break;
                                }
                                        while(opt != 1 && opt != 2)
                                        {                
                                            do
                                            {
                                                printf("\nReessayer : ");
                                                scanf("%d", &opt);
                                                while(f=getchar() != '\n'  &&  f !=EOF);
                                            }while(!(scanf("%d",&opt)));   


                                                    for(j=0 ; j < strlen(st[i].nom) - 1 ; j++ )
                                                            {
                                                                fprintf(file ,",%c",st[temp].nom[j]);
                                                            }                                    
                                                                fprintf(file ,",%d",st[tab[temp]].numero);
                                                                fprintf(file ,"%d",st[temp].um);
                                                if(opt == 1)
                                                {
                                                   break;
                                                }    
                                        }
                                                    
                        }
                    if(opt == 1)
                        {
                            for(k=0 ; k < temp2 ; k++)
                            {
                                    for(j=0 ; j < strlen(st[i].nom) - 1 ; j++ )
                                    {
                                        fprintf(file ,",%c",st[tab[k]].nom[j]);
                                    }                                    
                                        fprintf(file ,",%d",st[tab[k]].numero);
                                        fprintf(file ,"%d",st[tab[k]].um);
                            }
                            break;
                        }
                    }
                break;
                    case 3 :
                    exit(EXIT_SUCCESS);
            }
    }while(menu == 1);
}


/*----------------------------------------------------------------------------------------------------------------------------*/
void display(FILE *file , ME *st  ,char *argv)
{
    int i ,j ;
    char *car;    
    file=fopen(argv , "w+");
    if(file != NULL)
    {
        fprintf(file,"<HTML>\n<TIILE><CENTER><h3> %s </h3> </CENTER></TIILE>\n",argv);
        fprintf(file,"<BODY background=""ImgBack.png"">\n ");
        fprintf(file , "<FONT size=""10"" color=""maroon"">Mention Informatique et Technologie en premiere annee </FONT><br>");
        fprintf(file,"<TABLE border=5 width=""960"" align=""center"">\n");
        fprintf(file,"<tr>\n");
        fprintf(file ,"<td bgcolor=""white"">Nom et Prenom</td>  <td bgcolor=""white"">Numero</td> <td bgcolor=""white""> Machine</td> <td bgcolor=""white"">Presence</td><br>");
        fprintf(file,"</tr>\n");
        for(i=1 ; i<76 ; i++)
        {
            fprintf(file,"<tr>\n");
            if(st[i].um == OUI)
            {
               st[i].um = 1 ;
               st[i].presence ="<td bgcolor=""aqua"">present</td>";
            }
            else if (st[i].um == NON)
            {
               st[i].um = 2 ;
               st[i].presence ="<td bgcolor=""aqua"">present</td>";
            }
            else
            {
                 st[i].um = 0 ;
                 st[i].presence ="<td bgcolor=""gray"">absent</td>";
            }
            fprintf(file, "<td><B><FONT color=""white"">");
            for(j=0 ; j < strlen(st[i].nom) - 1 ; j++ )
            {
                fprintf(file ,"%c",st[i].nom[j]);
            }
            fprintf(file, "</FONT></B></td>");
            fprintf(file ,"<td><B><FONT COLOR=""yellow"">%d</FONT></B></td> <td><B><FONT COLOR=""orange"">%d</FONT></B></td> %s",st[i].numero ,st[i].um, st[i].presence);
            for(j=0 ; j < strlen(st[i].nom) - 1 ; j++ )
            {
            }
            fprintf(file,"</tr>\n");
        }
        fprintf(file,"</TABLE>\n ");
            fprintf(file ,"\n");
            fprintf(file,"<FONT color=""gray"" size=""5"">Verification machine du %s %s<br></FONT>",__TIME__,__DATE__);
            fprintf(file , "<FONT color=""blue""><B>Indication</B></FONT> : <br> <FONT color=""gray"">1 si OUI (machine MIT) <br> 2 si PERSO<br> 0 si ABS</FONT> ");
            fprintf(file,"</BODY>\n "); 
            fprintf(file,"</HTML>\n ");
    }
}

void error( char *argv )
{

    fprintf(stderr , "utilisation du programme : %s list_L1_copy.csv fichier.html  ",argv);
    exit(EXIT_SUCCESS);
    }