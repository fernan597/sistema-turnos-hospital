#include <stdio.h>
#include <string.h>

typedef struct{
    int hora_ing;
    int min_ing;
    int hora_ate;
    int min_ate;
}horas;
horas hs;

typedef struct{
    int hora_esp;
    int min_esp;
}tiempo;
tiempo esp;

typedef struct {
    char nom[20];
    char ape[20];
    long int dni;
    int edad;
    horas hs;
    tiempo esp;
    int nvUrg;
    int atendido;
}paciente;
paciente p;

paciente atendidos[5000];

paciente auxi;
paciente auxi2;


typedef struct{
    char nom[20];
    char ape[20];
    long int dni;
    char mutual[30];
    int edad;
    horas hs;
}urgencia;

urgencia u[5000];

char resp[2];

void ingreso(int hors, int minu) {
    p.hs.hora_ing=hors;
    p.hs.min_ing=minu;
    printf("Ingrese el nombre: ");
    scanf("%s", p.nom);
    printf("Ingrese el apellido: ");
    scanf("%s", p.ape);
    printf("D.N.I: ");
    scanf("%d", &p.dni);
    printf("Desea ingresar la edad? Ingrese \"si\" si quiere, sino ingrese cualquier letra: ");
    scanf("%s", resp);
      if (strcmp(resp,"si")==0){
          printf("Ingrese la edad: ");
          scanf("%d", &p.edad);
      }
      else {
        p.edad=0;
      }
    p.atendido=1;
}

int ingreso_urgencia(int n, int cont, int hora, int minu){
    int i, au=-1;
    for(i=0;i<n;i++){
        printf("VAMOS A TOMAR LOS DATOS DEL PACIENTE %d\n",i+1);
        printf("\nIngrese el nombre: ");
        scanf("%s", u[i].nom);
        printf("Ingrese el apellido: ");
        scanf("%s", u[i].ape);
        printf("Ingrese el D.N.I: ");
        scanf("%ld",&u[i].dni);
        printf("Ingrese la mutual: ");
        scanf("%s",u[i].mutual);
        printf("Desea ingresar la edad? Ingrese \"si\" si quiere, sino ingrese cualquier letra: ");
        scanf("%s", resp);
        if (strcmp(resp,"si")==0){
            printf("Ingresar edad: ");
            scanf("%d",&u[i].edad);
        }
        else {
            u[i].edad=0;
        }
    u[i].hs.hora_ing=hora;
    u[i].hs.min_ing=minu;
    }
    for(i=cont;i<cont+n;i++){
        au+=1;
        strcpy(atendidos[i].nom, u[au].nom);
        strcpy(atendidos[i].ape, u[au].ape);
        atendidos[i].dni=u[au].dni;
        strcpy(atendidos[i].ape, u[au].ape);
        atendidos[i].edad=u[au].edad;
        atendidos[i].hs.min_ing=u[au].hs.min_ing;
        atendidos[i].hs.hora_ing=u[au].hs.hora_ing;
        atendidos[i].hs.hora_ate=24;
        atendidos[i].hs.min_ate=0;
    }
return cont;
}

/*void muestra_urgencia(int n, int h, int m){
    int i;
    printf("\nLOS %d PACIENTES INGRESADOS POR URGENCIAS A LAS %d:%dhs. SON: \n", n, h, m);
    printf("\n**************************\n");
    for(i=0;i<n;i++){
        printf("\nPACIENTE: %d\n",i+1);
        printf("\nNombre: %s",u[i].nom);
        printf("\nApellido: %s",u[i].ape);
        printf("\nD.N.I: %ld",u[i].dni);
        printf("\nMutual: %s",u[i].mutual);
        if(u[i].edad!=0){
            printf("\nEdad: %d",u[i].edad);
        }
    printf("\n\n**************************\n");
    }
}
*/

void mostrarAtendido(int cont,int nivel){
    int i;
    printf("******************************\n");
    for(i=0;i<cont+1;i++){
                printf("****\n");
        if(atendidos[i].hs.hora_ate!=24){
            if(atendidos[i].nvUrg==nivel){
                printf("PACIENTE: %d\n", i);
                printf("Nombre y apellido: %s %s\n", atendidos[i].nom, atendidos[i].ape);
                printf("D.N.I: %d\n", atendidos[i].dni);
                printf("Hora y minutos de atencion: %d:%dhs.\n", atendidos[i].hs.hora_ate, atendidos[i].hs.min_ate);
            if (atendidos[i].edad!=0){
                printf("Edad: %d\n", atendidos[i].edad);
            }
            }
        }
    }
}

void mostrarTiempoEspera(int cont){
    int i, horai,mini;
    printf("******************************\n");
    for(i=0;i<=cont;i++){
        if(atendidos[i].hs.hora_ate!=24){
                printf("PACIENTE: %d\n", i+1);
                printf("Nombre y apellido: %s %s\n", atendidos[i].nom, atendidos[i].ape);
                printf("D.N.I: %d\n", atendidos[i].dni);
                printf("Nivel de urgencia: %d\n",atendidos[i].nvUrg);
                if(atendidos[i].hs.min_ing<atendidos[i].hs.min_ate || atendidos[i].hs.min_ing == atendidos[i].hs.min_ate){
                    atendidos[i].esp.min_esp=  abs(atendidos[i].hs.min_ing-atendidos[i].hs.min_ate);
                    atendidos[i].esp.hora_esp= abs(atendidos[i].hs.hora_ate - atendidos[i].hs.hora_ing);
                }
                else{
                    atendidos[i].esp.min_esp= abs((atendidos[i].hs.min_ing - atendidos[i].hs.min_ate)-60);
                    atendidos[i].esp.hora_esp= abs(atendidos[i].hs.hora_ate - atendidos[i].hs.hora_ing)-1;
                }
                printf("Hora y minutos de espera: %d:%dhs.\n", atendidos[i].esp.hora_esp,atendidos[i].esp.min_esp);
            if (atendidos[i].edad!=0){
            printf("Edad: %d\n", atendidos[i].edad);
            }
            printf("\n******************************\n");
        }
    }
}

/*int recursivaAtendidos(int cont, int i, int acu){
    if(i==cont-1){
        printf("El paciente que mas espero es: %s %s\n",atendidos[acu].nom, atendidos[acu].ape);
        return 0;
    }
    else{
        if(atendidos[i].esp.hora_esp>atendidos[i+1].esp.hora_esp){
            acu=i;
            return recursivaAtendidos(cont,i+1,acu);
        }
            else{
                if(atendidos[i].esp.hora_esp==atendidos[i+1].esp.hora_esp)
                    if(atendidos[i].esp.min_esp> atendidos[i+1].esp.min_esp){
                            acu=i;
                            return recursivaAtendidos(cont,i+1,acu);
                        }
                }
            return recursivaAtendidos(cont,i+1,acu);
    }
}*/

int recursivaAtendidos(int cant, int i, int acum){
    if (cant==0){
        return acum;
    }
        else if(atendidos[i].esp.hora_esp>atendidos[i+1].esp.hora_esp){
            return recursivaAtendidos(cant-1, i+1, acum=i);
        }
            else if(atendidos[i].esp.hora_esp==atendidos[i+1].esp.hora_esp){
                if(atendidos[i].esp.min_esp>atendidos[i+1].esp.min_esp){
                    return recursivaAtendidos(cant-1, i+1, acum=i);
                }
                else{
                    return recursivaAtendidos(cant-1, i+1, acum);
                }
            }
                else {
                    return recursivaAtendidos(cant-1, i+1, acum);
                }
}

void cargaArchivoAten(FILE *f, int cont){
    int i;
    for(i=0;i<=cont;i++){
        if(atendidos[i].hs.hora_ate!=24){
            fprintf(f,"%s %s\n", atendidos[i].nom, atendidos[i].ape);
            fprintf(f,"D.N.I: %ld\n", atendidos[i].dni);
            fprintf(f,"Edad: %d\n", atendidos[i].edad);
            fprintf(f, "Hora de ingreso: %d:%dhs.\n", atendidos[i].hs.hora_ing, atendidos[i].hs.min_ing);
            fprintf(f, "Hora de atencion: %d:%dhs.\n", atendidos[i].hs.hora_ate, atendidos[i].hs.min_ate);
        }
    }
}

void cargaArchivoAtenUrg(FILE *fp1, FILE *fp2, FILE *fp3, int cont){
    int i;
    for (i=0;i<cont+1;i++){
        if (atendidos[i].nvUrg==1){
            fprintf(fp1,"%s %s\n", atendidos[i].nom, atendidos[i].ape);
            fprintf(fp1,"D.N.I: %ld\n", atendidos[i].dni);
            fprintf(fp1,"Edad: %d\n", atendidos[i].edad);
            fprintf(fp1, "Hora de ingreso: %d:%dhs.\n", atendidos[i].hs.hora_ing, atendidos[i].hs.min_ing);
            fprintf(fp1, "Hora de atencion: %d:%dhs.\n", atendidos[i].hs.hora_ate, atendidos[i].hs.min_ate);
        }
    }
    for (i=0;i<cont+1;i++){
        if (atendidos[i].nvUrg==2){
            fprintf(fp2,"Nombre: %s %s\n", atendidos[i].nom, atendidos[i].ape);
            fprintf(fp2,"D.N.I: %ld\n", atendidos[i].dni);
            fprintf(fp2,"Edad: %d\n", atendidos[i].edad);
            fprintf(fp2, "Hora de ingreso: %d:%dhs.\n", atendidos[i].hs.hora_ing, atendidos[i].hs.min_ing);
            fprintf(fp2, "Hora de atencion: %d:%dhs.\n", atendidos[i].hs.hora_ate, atendidos[i].hs.min_ate);
        }
    }
    for (i=0;i<cont+1;i++){
        if (atendidos[i].nvUrg==3){
            fprintf(fp3,"Nombre: %s %s\n", atendidos[i].nom, atendidos[i].ape);
            fprintf(fp3,"D.N.I: %ld\n", atendidos[i].dni);
            fprintf(fp3,"Edad: %d\n", atendidos[i].edad);
            fprintf(fp3,"Hora de ingreso: %d:%dhs.\n", atendidos[i].hs.hora_ing, atendidos[i].hs.min_ing);
            fprintf(fp3,"Hora de atencion: %d:%dhs.\n", atendidos[i].hs.hora_ate, atendidos[i].hs.min_ate);
        }
    }
}
