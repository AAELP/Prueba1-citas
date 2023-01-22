#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int di;
int a;
int m;
struct cita
{
int id;
char nom[50];
int dia;
int hora;
int mes;
int ano;

}e;

FILE *fc;

int main(){

    int ch;

    while(1){
        system("cls");
        printf("<== Sistema de admiciones ==>\n");
        printf("1.Agendar cita\n");
        printf("2.lista de citas\n");
        printf("3.Eliminar cita\n");
        printf("0.salir\n\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
            admitPatient();
            break;

        case 2:
            patientList();
            break;

        case 3:
            dischargePatient();
            break;
        default:
            printf("Invalid Choice...\n\n");

        }
        printf("\n\nPress Any Key To Continue...");
        getch();
    }

    return 0;
}

void admitPatient(){
    fc =fopen("citas.txt","ab");
    printf("Ingrece Id: \n");
   scanf("%d", &e.id);

    printf("Ingrese nombre del paciente: \n");
    fflush(stdin);
    gets(e.nom);

    printf("ingrese dia de la cita: \n");
   scanf("%d", &e.dia);

    printf("ingrese mes de la cita (del 1-12): \n");
   scanf("%d", &e.mes);
    
    printf("ingrese hora de la cita (solo horas enteras, formato 24h): \n");
    scanf("%d", &e.hora);

    printf("ingrese año de la cita: \n");
    scanf("%d", &e.ano);

    fwrite(&e, sizeof(e), 1, fc);
      fclose(fc);

    printf("\nPatient Added Successfully");
}

void patientList(){

    printf("<== Patient List ==>\n\n");
    printf("%-10s %-30s %-30s %-20s %-10s \n", "ID", "Nombre","Dia", "Hora","Año");
    printf("----------------------------------------------------------------------------------------------------------\n");
    fc = fopen("citas.txt", "rb");
    while(fread(&e, sizeof(e), 1, fc) == 1){
        printf("%-10d %-30s %-30d %d:00\t\t\t%d\n",e.id,e.nom,e.dia,e.hora,e.ano);
    }
    fclose(fc); 
}


void dischargePatient(){
    int id, f=0;
    system("cls");
    printf("<== Discharge Patient ==>\n\n");
    printf("Enter Patient id to discharge: ");
    scanf("%d", &id);

    FILE *ft;

    fc = fopen("citas.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&e, sizeof(e), 1, fc) == 1){

        if(id == e.id){
            f=1;
        }else{
            fwrite(&e, sizeof(e), 1, ft);
        }
    }

    if(f==1){
        printf("\n\nPatient Discharged Successfully.");
    }else{
        printf("\n\nRecord Not Found !");
    }

    fclose(fc);
    fclose(ft);

    remove("citas.txt");
    rename("temp.txt", "citas.txt");

}