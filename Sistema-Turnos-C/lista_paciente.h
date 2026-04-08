#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct {
 paciente lugar;
 struct nodo *next;
}Nodo;



struct  Lista_Pac{
Nodo *acc; ///* acceso a la lista */
Nodo *cur; ///* cursor de la lista */
Nodo *aux; ///* cursor auxiliar */
};

typedef struct Lista_Pac ListaP;

void init(ListaP *L){
    (*L).acc=NULL;
    (*L).cur=NULL;
    (*L).aux=NULL;
}

void reset(ListaP *L){
    (*L).cur=L->acc;
    (*L).aux=L->acc;
}

void insert(ListaP *L, paciente d){
    Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
        if(nuevo!=NULL){
            if((L->cur)==(L->acc))  {
                L->acc=nuevo;
                (*nuevo).next=L->cur;
                L->cur=L->acc;
                L->aux=L->acc;
            }
            else{
                (L->aux)->next=nuevo;
                (*nuevo).next=L->cur;
                L->cur=nuevo;
            }
            (L->cur)->lugar=d;
        }
}

void supres(ListaP *L) {
    if ((L->cur)==(L->acc)) {
        (*L).acc=((*L).cur)->next;
        free((*L).cur);
        (*L).cur=(*L).acc;
        (*L).aux=(*L).acc;
    }
        else {
            (L->aux)->next=(L->cur)->next;
            free((*L).cur);
            (*L).cur=(L->aux)->next;
        }
}

void forward(ListaP *L){
     L->aux=L->cur;
     L->cur=(L->cur)->next;
 }

 paciente copy (ListaP L){
     return (L.cur)->lugar;
 }

 int empty(ListaP L){
     if (L.acc==NULL) {
        return 1;
     }
         else {
            return 0;
         }
 }

 int full(){
    Nodo *aux=(Nodo*)malloc(sizeof(Nodo));
    if(aux!=NULL){
        free(aux);
        return 0;
    }
        else {
            return 1;
        }
 }

 int oos(ListaP L){
    if (L.cur==NULL) {
        return 1;
    }
        else {
            return 0;
        }
}

void muestra_Pacientes(ListaP pacien) {
    int i=1;
    reset(&pacien);
    printf("******************************\n");
    while (!oos(pacien)) {
        auxi=copy(pacien);
        printf("PACIENTE: %d\n", i);
        printf("Nombre y apellido: %s %s\n", auxi.nom, auxi.ape);
        printf("D.N.I: %d\n", auxi.dni);
        printf("Hora y minutos de atencion: %d:%dhs.\n", auxi.hs.hora_ing, auxi.hs.min_ing);
        if (auxi.edad!=0){
            printf("Edad: %d\n", auxi.edad);
        }
        printf("\n******************************\n");
        i++;
        forward(&pacien);
    }
}

void muestra_siguiente(ListaP pacien){
    reset(&pacien);
    auxi=copy(pacien);
    printf("Nombre y apellido: %s %s\n", auxi.nom, auxi.ape);
    printf("D.N.I: %ld\n", auxi.dni);
    printf("Edad: %d\n", auxi.edad);
    printf("Ingreso a las %d:%dhs.\n", auxi.hs.hora_ing, auxi.hs.min_ing);
}

int retiro_voluntario(long int dni, ListaP *pacien, int NroAte) {
    reset(&(*pacien));
    while (!oos(*pacien)) {
        auxi=copy((*pacien));
            if (dni==auxi.dni) {
                atendidos[NroAte]=copy(*pacien);
                atendidos[NroAte].nvUrg=1;
                atendidos[NroAte].hs.hora_ate=24;
                atendidos[NroAte].hs.min_ate=0;
                supres(&(*pacien));
                return 1;
            }
                else {
                    forward(&(*pacien));
                }
    }
return 0;
}

int modificarEdad(int dni, ListaP *pacien){
    reset(&(*pacien));
    int cont=0, ed, i=0;
    while (!oos(*pacien)) {
        auxi=copy((*pacien));
            if (dni==auxi.dni) {
                printf("\nIngrese la edad a cambiar: ");
                scanf("%d", &ed);
                auxi.edad=ed;
                supres(&(*pacien));
                insert(&(*pacien), auxi);
                return 1;
            }
                else {
                    cont+=1;
                    forward(&(*pacien));
                }
    }
return 0;
}

int lecturaArchivo(ListaP *P, FILE *f){
    int cont;
    reset(&(*P));
    while(!oos(*P)){
        forward(&(*P));
    }
    while(!feof(f)){
        fscanf(f,"%d %d",&auxi.hs.hora_ing, &auxi.hs.min_ing);
        fscanf(f,"%s", auxi.nom);
        fscanf(f,"%s", auxi.ape);
        fscanf(f,"%d", &auxi.dni);
        fscanf(f,"%d", &auxi.edad);
        insert(&(*P), auxi);
        cont++;
        forward(&(*P));
    }
return cont;
}

int buscaDniLisPac(ListaP P, long int dni){
    int i=0, cont=0;
    reset(&P);
    while(i!=1){
        auxi=copy(P);
        if (auxi.dni==dni){
          i=1;
          forward(&P);}
        else{
            i=0;
            forward(&P);
        }
    }
    if(i=1){
        while(!oos(P)){
            cont++;
            forward(&P);
        }
    return cont;
    }
return -1;
}
