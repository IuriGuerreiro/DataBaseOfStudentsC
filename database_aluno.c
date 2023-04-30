#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct aluno{
	int ano_escolar,num_cart;
	char genero,nome_c[40],data_nas[10];
}dados;

dados aluno[9999];

FILE *Fp;
int quant=0;

int menu(){
	int opc;
	system("cls");
	printf ("\n\t\t***DADOS DE ALUNOS***");
	printf ("\n\n\t1-Add Student");
	printf ("\n\t2-Show students\n");
	scanf ("%d",&opc);

	return opc;
}



int loading(){
	char line[1024],buf[7];
	int i=0;
	printf ("CARREGANDO...");
	sleep(2);
	Fp = fopen("Students.txt", "a+");
		
	if(Fp==NULL){
		printf ("\nFile not found");
		getch();
		exit(1);	
	}
	while(fgets(line,1024,Fp)!=NULL){
		for(i=0;i<sizeof(line);i++){
			strncpy(buf ,line + i, 6);
			buf[6] = '\0';
			if (strcmp(buf,"ALUNO-")==0)
				quant++;
		}
	}
	return 0;
}



int Intr_dados(){
	
	int i=-1,ff;
	char SouN,parame[15];
	Fp = fopen("Students.txt", "a");
		
	if(Fp==NULL){
		printf ("\nFile not found");
		getch();
		exit(1);	
	}
	do{
		i++;
		system ("cls");//scanf de informações
		printf ("\n\t\t\t\tStudent- %d",quant+1);
		printf("\nName: ");
		fflush(stdin);
		gets(aluno[i].nome_c);
		printf ("\nDate of birth(ex:22/01/2023): ");
		gets(aluno[i].data_nas);
		printf ("\nGender F/M : ");
		do{
			if(aluno[i].genero!='f'&& aluno[i].genero!='m')
				printf ("\nThat wasn't asked\nGender F/M : ");
			scanf (" %c",&aluno[i].genero);
			tolower(aluno[i].genero);
			
		}while(aluno[i].genero!='f'&& aluno[i].genero!='m');
		
		printf ("\nYear of Shocolarship(ex:1,2,3): ");
		scanf ("%d",&aluno[i].ano_escolar);
		aluno[i].num_cart=quant+1;
		
		
		
		system ("cls");//verificar se as informações estam corretas 
		printf ("\n\t\t\t\tStudent- %d",aluno[i].num_cart);
		printf ("\nNName: %s",aluno[i].nome_c);
		printf ("\nDate of Birth: %s",aluno[i].data_nas);
		printf ("\nYear of escolarship: %d",aluno[i].ano_escolar);
		printf ("\nGender: %c",aluno[i].genero);
		printf ("\nEstá tudo correto S/N : ");
		scanf (" %c",&SouN);
		tolower(SouN);
		while (SouN!='s'&&SouN!='n'){
			printf ("\nThat wasn't asked");
			printf ("\nIt's all good S/N: ");
			scanf (" %c",&SouN);
			tolower(SouN);
		}
		ff=1;
		do{
			if (SouN=='n'){
				ff=0;
				printf ("\nWitch is the incorrect information : ");
				fflush(stdin);
				gets(parame);
				strlwr(parame);
				if (strcmp(parame,"name")==0){
					printf ("\nName of the Student:");
					gets (aluno[i].nome_c);
					ff=1;
				}
				else if (strcmp(parame,"gender")==0){
					printf ("\nGender of the Student:");
					gets (aluno[i].nome_c);
					ff=1;
				}
				else if (strcmp(parame,"date of birth")==0){
					printf ("\nDate of birth:");
					gets (aluno[i].nome_c);
					ff=1;
				}
				else if (strcmp(parame,"year of scolarship")==0){
					printf ("\nYear of scolarship:");
					gets (aluno[i].nome_c);
					ff=1;
				}
				else 
					printf ("\nThe parameter was bad written write it again!!");
			}
		}while(ff!=1);
		
		fprintf (Fp,"\n\t\t\t\tStudent- %d",aluno[i].num_cart);
		fprintf (Fp,"\nName: %s",aluno[i].nome_c);
		fprintf (Fp,"\nDate of Birth: %s",aluno[i].data_nas);
		fprintf (Fp,"\nYear of Scoralship: %d",aluno[i].ano_escolar);
		fprintf (Fp,"\nGender: %c",aluno[i].genero);
	
		
		printf ("\nAdd another Student Y/N: ");//para se quiser fazer scanf de mais um aluno
		scanf (" %c",&SouN);
		tolower(SouN);
		while (SouN!='y'&&SouN!='n'){
			printf ("\nThat wasn't asked': ");
			printf ("\nAdd another Student Y/N: ");
			scanf (" %c",&SouN);
			tolower(SouN);
		}
		quant++;
	}while (SouN=='s');
	fclose(Fp);
	return 0;
}	


mostrar(){
	char line[1024];
	system("cls");
	Fp = fopen("Students.txt", "r");
		
	if(Fp==NULL){
		printf ("\nFile not found");
		getch();
		exit(1);	
	}
	while(fgets(line,100,Fp))
		printf ("%s",line);
		
	getch();
	return 0;
}

int main (){
	int opc;
	setlocale(LC_ALL,"portuguese");
	
		loading();//ver o ultimo numero do aluno que está no ficheiro
	do{
		opc =menu();
		if (opc==1)
			Intr_dados();
			
		if (opc==2)
			mostrar();
			
	}while(opc!=0);

}
