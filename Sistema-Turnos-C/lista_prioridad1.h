#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct nodo{
 paciente vipd;
 struct nodo *next;
};

typedef struct nodo NodoPrior;

struct listaOrd {
NodoPrior *acc; ///* acceso a la lista */
NodoPrior *cur; ///* cursor de la lista */
NodoPrior *curaux; ///* cursor auxiliar */
};

typedef struct listaOrd listaPriori;

void inicioPriori(listaPriori *l){
   (*l).acc=NULL;
   (*l).cur=NULL;
   (*l).curaux=NULL;
}

void resetPriori(listaPriori *l){
    l->cur=l->acc;
    l->curaux=l->acc;
}

void insertPriori(listaPriori *l, paciente nuevo){
    NodoPrior *aux1=(NodoPrior*)malloc(sizeof(NodoPrior));
    if(aux1!=NULL){
    }
    if((l->cur)==(l->acc))  {
        l->acc=aux1;
        (*aux1).next=l->cur;
        l->cur=l->acc;
        l->curaux=l->acc;
    }
        else{
            (l->curaux)->next=aux1;
            (*aux1).next=l->cur;
            l->cur=aux1;
        }
    (l->cur)->vipd=nuevo;
}

void supresPriori(listaPriori *l){
    if ((l->cur)==(l->acc)) {
        (*l).acc=((*l).cur)->next;
        free((*l).cur);
        (*l).cur=(*l).acc;
        (*l).curaux=(*l).acc;
    }
        else {
            (l->curaux)->next=(l->cur)->next;
            free((*l).cur);
            (*l).cur=(l->curaux)->next;
        }
}

void forwardPriori(listaPriori *l){
     l->curaux=l->cur;
     l->cur=(l->cur)->next;
}


 paciente copyPriori(listaPriori l){
     return (l.cur)->vipd;
 }

 int emptyPriori(listaPriori l){
    if (l.acc==NULL)  {
        return 1;
    }
        else {
            return 0;
        }
 }

 int fullPriori(){
    NodoPrior *aux=(NodoPrior*)malloc(sizeof(NodoPrior));
    if(aux!=NULL){
        free(aux);
        return 0;
    }
        else{
            return 1;
        }
 }

int oosPriori(listaPriori l){
    if (l.cur==NULL) {
        return 1;
    }
        else {
            return 0;
        }
}

void IngresarPrio(listaPriori *pacienPrio, int est, ListaP *pacien) {
    reset(&(*pacien));
    auxi=copy((*pacien));
    auxi.nvUrg=est;
    supres(&(*pacien));

    resetPriori(&(*pacienPrio));
    if(emptyPriori((*pacienPrio))==1) {
        insertPriori(&(*pacienPrio), auxi);
        system("cls");
        printf("\nAcaba de ser atendido %s %s por la enfermera con nivel de urgencia %d.\n", auxi.nom, auxi.ape, est);
    }
        else {
            auxi2=copyPriori((*pacienPrio));
            resetPriori(&(*pacienPrio));
            while(auxi.nvUrg>auxi2.nvUrg ){
                forwardPriori(&(*pacienPrio));
                if(oosPriori((*pacienPrio))==1){
                    insertPriori(&(*pacienPrio), auxi);
                    system("cls");
                    printf("\nAcaba de ser atendido %s %s por la enfermera con nivel de urgencia %d.\n", auxi.nom, auxi.ape, est);
                    resetPriori(&(*pacienPrio));
                    return ;
                }
                auxi2=copyPriori((*pacienPrio));
            }
            if(auxi.nvUrg==auxi2.nvUrg){
                while(auxi.hs.hora_ing>auxi2.hs.hora_ing && auxi.nvUrg==auxi2.nvUrg) {
                    forwardPriori(&(*pacienPrio));
                    if(oosPriori((*pacienPrio))==1){
                    insertPriori(&(*pacienPrio), auxi);
                    system("cls");
                    printf("\nAcaba de ser atendido %s %s por la enfermera con nivel de urgencia %d.\n", auxi.nom, auxi.ape, est);
                    resetPriori(&(*pacienPrio));
                    return ;}
                    auxi2=copyPriori((*pacienPrio));
                }
                while(auxi.hs.min_ing>auxi2.hs.min_ing && auxi.nvUrg==auxi2.nvUrg) {
                    forwardPriori(&(*pacienPrio));
                    if(oosPriori((*pacienPrio))==1){
                        insertPriori(&(*pacienPrio), auxi);
                        printf("\nAcaba de ser atendido %s %s por la enfermera con nivel de urgencia %d.\n", auxi.nom, auxi.ape, est);
                        resetPriori(&(*pacienPrio));
                    return ;
                    }
                    auxi2=copyPriori((*pacienPrio));
                }
            }
            insertPriori(&(*pacienPrio), auxi);
            system("cls");
            printf("\nAcaba de ser atendido %s %s por la enfermera con nivel de urgencia %d.n", auxi.nom, auxi.ape, est);
            resetPriori(&(*pacienPrio));
   }
}

void Muestra_Prioridad(listaPriori pacien) {
    int i=1;
    resetPriori(&pacien);
    printf("******************************\n");
    while(!oosPriori(pacien)) {
        auxi=copyPriori(pacien);
        printf("PACIENTE: %d\n", i);
        printf("Nombre y apellido: %s %s\n", auxi.nom, auxi.ape);
        printf("D.N.I: %ld\n", auxi.dni);
        printf("Hora y minutos de atencion: %d:%dhs.\n", auxi.hs.hora_ing, auxi.hs.min_ing);
        printf("Nivel de urgencia: %d\n", auxi.nvUrg);
        if (auxi.edad!=0){
            printf("Edad: %d\n", auxi.edad);
        }
            if (auxi.atendido==1) {
                printf("No fue atendido\n");
            }
                else {
                    printf("Ya fue atendido por la enfermera\n");
                }
        printf("\n******************************\n");
        i++;
        forwardPriori(&pacien);
    }
}

void atencionMedico (listaPriori *P, int cont, int h, int m) {
    resetPriori(&(*P));
    atendidos[cont]=copyPriori((*P));
    atendidos[cont].hs.hora_ate=h;
    atendidos[cont].hs.min_ate=m;
    supresPriori(&(*P));
    printf("******************************\n");
    printf("\nAcaba de ser atendido %s %s por el medico.\n", atendidos[cont].nom, atendidos[cont].ape);
    printf("\n******************************\n");
}

void mostrarPrimero(listaPriori P){
    resetPriori(&P);
    auxi=copyPriori(P);
    printf("Nombre y apellido: %s %s\n", auxi.nom, auxi.ape);
    printf("D.N.I: %ld\n", auxi.dni);
    printf("Edad: %d\n", auxi.edad);
    printf("Ingreso a las %d:%dhs.\n", auxi.hs.hora_ing, auxi.hs.min_ing);
}

void AsignarHoraRetiro(listaPriori *P, int cont){
    atendidos[cont].nvUrg=1;
    atendidos[cont]=copyPriori((*P));
    atendidos[cont].hs.hora_ate=24;
    atendidos[cont].hs.min_ate=0;
}

int retiro_voluntario_prioridad(long int dni, listaPriori *P, int cont) {
    resetPriori(&(*P));
    while (!oosPriori(*P)) {
        auxi=copyPriori(*P);
            if (dni==auxi.dni) {
                AsignarHoraRetiro(&(*P), cont);
                supresPriori(&(*P));
                return 1;
            }
                else {
                    forwardPriori(&(*P));
                }
    }
return 0;
}



int modificarEdadPrioridad(listaPriori *P,long int dni){
   resetPriori(&(*P));
    int cont=0, ed, i=0;
    while (!oosPriori(*P)) {
        auxi=copyPriori((*P));
            if (dni==auxi.dni) {
                printf("\nIngrese la edad a cambiar: ");
                scanf("%d", &ed);
                auxi.edad=ed;
                supresPriori(&(*P));
                insertPriori(&(*P), auxi);
                return 1;
            }
                else {
                    cont+=1;
                    forwardPriori(&(*P));
                }
    }
return 0;
}

void cargaArchivo(listaPriori *P, FILE *f){
    resetPriori(&(*P));
    while(oosPriori((*P))!=1){
        auxi=copyPriori((*P));
        fprintf(f,"%s %s\n", auxi.nom, auxi.ape);
        fprintf(f,"D.N.I: %ld\n", auxi.dni);
        fprintf(f,"Edad: %d\n", auxi.edad);
        forwardPriori(&(*P));
    }
}

int buscaDniLisPrio(listaPriori P, long int dni){
    int i=0,cont=0;
    resetPriori(&P);
    while(i!=1 && !oosPriori(P)){
        auxi=copyPriori(P);
        if (auxi.dni==dni){
          i=1;
          forwardPriori(&P);}
        else{
            i=0;
            forwardPriori(&P);
        }
    }
    if(i=1){
        while(!oosPriori(P)){
            cont++;
            forwardPriori(&P);
        }
    return cont;
    }
return -1;
}

void MostrarEnListPrioridad(listaPriori P, int cont){
    resetPriori(&P);
    int i, Nv1=0, Nv2=0, Nv3=0;
    for(i=0;i<cont;i++){
        auxi=copyPriori(P);
        if (auxi.nvUrg==1){
            Nv1++;
        }
            else if (auxi.nvUrg==2){
                Nv2++;
            }
                else{
                    Nv3++;
                }
    }
    printf("******************************\n\n");
    printf("Nivel de urgencia rojo: %d\n", Nv1);
    printf("Nivel de urgencia amarillo: %d\n", Nv2);
    printf("Nivel de urgencia Verde: %d\n", Nv3);
    printf("\n******************************\n");
}
