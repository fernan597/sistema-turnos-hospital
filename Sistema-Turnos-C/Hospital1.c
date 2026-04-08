#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "lista_paciente.h"
#include "lista_prioridad1.h"



int main () {
    char borrado;
    int x, h, m, est, NroPacient=0, NroPrioridad=0, NroAtendidos=-1, hUrg=0, mUrg=0, hAte=0, mAte=0, hIng=0, mIng=0, Nro;
    long int dnii;

    ListaP pacien;
    init(&pacien);
    listaPriori paciP;
    inicioPriori(&paciP);

    printf("*******************************************************\n");
    printf("\n*** BIENVENIDOS AL SISTEMA DE ATENCION HOSPITALARIO ***\n");
    printf("\n*******************************************************\n");
    printf("presione ENTER para comenzar...");
    scanf("%c", &borrado);
    system("cls");
    do {
      printf("\t\t\tBIENVENIDO AL MENU PRINCIPAL!\n");
      printf("\n1>Ingreso de un nuevo paciente al hospital\n2>Atencion de la enfermera\n3>Muestra de todos los pacientes\n4>Atencion del medico\n");
      printf("5>Retiro de un paciente\n6>Ingresar pacientes por urgencia\n7>Mostrar siguiente paciente por ser atendido\n8>Modificar edad\n");
      printf("9>Muestra pacientes atendidos y que se retiraron\n10>Escritura y carga de archivos\n11>Cantidad de pacientes detras(segun DNI dado)\n");
      printf("12>Muestra la cantidad de pacientes en espera\n13>Muestra cuantos pacientes hay por nivel de urgencia\n14>Archiva los datos de los pacientes atendidos\n0>Salir.");
      printf("\nINGRESE LA OPCION QUE DESEA REALIZAR: ");
      scanf("%d", &x);
      switch (x) {
       case 1: system("cls"); /// INGRESO DE UN NUEVO PACIENTE AL HOSPITAL ///
               printf("PREPARANDO EL INGRESO PARA UN NUEVO PACIENTE...\n\n");
               printf("Ingrese solo la hora actual: ");
               scanf("%d", &h);
                while (h>23 || h<0 || h<hIng || h<hUrg) {
                    printf("\nLa hora ingresada no puede ser posible. Intentelo de nuevamente.\n");
                    printf("Ingrese solo la hora actual: ");
                    scanf("%d", &h);
                }
               printf("\nIngrese solo los minutos actuales: ");
               scanf("%d", &m);
               if (h==hIng || h==hUrg){
                    while (m>59 || m<0 || m<mIng || m==mIng || m<mUrg || m==mUrg) {
                        printf("\nLos minutos ingresados no pueden ser posibles. Intentelo de nuevamente.\n");
                        printf("\nIngrese solo los minutos actuales: ");
                        scanf("%d", &m);
                    }
               }
               else{
                    while (m>59 || m<0) {
                        printf("\nLos minutos ingresados no pueden ser posibles. Intentelo de nuevamente.\n");
                        printf("\nIngrese solo los minutos actuales: ");
                        scanf("%d", &m);
                    }
               }
                NroPacient+=1;
                hIng=h;
                mIng=m;
                printf("\nVAMOS A TOMAR LOS DATOS DEL PACIENTE...\n");
                ingreso(h, m);
                ///************************************///
                insert(&pacien, p);
                forward(&pacien);
                ///************************************///
                system("cls");
                printf("Los datos fueron tomados con exito. Volviendo al Menu principal...\n\n");
       break;

       case 2: if (NroPacient>=1) { /// ATENCION DE LA ENFERMERA ///
                    system("cls");
                    printf("(ESTE CAMPO LO DEBE LLENAR LA ENFERMERA PARA DETERMINAR SU GRADO DE URGENCIA)\n");
                    printf("\nEl paciente atendido por la enfermera es: \n\n");
                    muestra_siguiente(pacien);
                    printf("\n1> Rojo: Muy urgente\t2> Amarillo: Urgencia media\n\n3>Verde: No urgente\n\nIngrese el estado del paciente: ");
                    scanf("%d", &est);
                 while (est<1 || est>3) {
                    printf("\nEl valor ingresado es incorrecto. Intentelo nuevamente: ");
                    scanf("%d", &est);
                 }
                /////////////////////////////////////////////////////////////
                IngresarPrio(&paciP, est, &pacien);
                printf("\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                ////////////////////////////////////////////////////////////
                NroPrioridad+=1;
                NroPacient-=1;
               }
               else{
                    system("cls");
                    printf("No hay pacientes para ser atendidos por la enfermera\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
               }
       break;

       case 3:  if (NroPacient>=1 || NroPrioridad>=1) { /// MUESTRA DE LOS PACIENTES ///
                    do{
                        system("cls");
                        printf("1>Por orden de llegada\t2>Por orden de prioridad\n");
                        printf("\nIngrese la opcion a realizar: ");
                        scanf("%d", &x);
                            if (x<1 || x>2) {
                                printf("\nHa ingresado el numero %d.\n", x);
                                printf("\nLa opcion ingresada es incorrecta. Por favor intetelo nuevamente...\n");
                            }
                    }while(x!=1 && x!=2);
                }
                    switch (x) {
                        case 1: system("cls");
                                muestra_Pacientes(pacien);
                        break;

                        case 2: if (NroPrioridad>=1) {
                                    system("cls");
                                    Muestra_Prioridad(paciP);

                                }
                                    else {
                                        system("cls");
                                        printf("La enfermera no ha atendido a ningun paciente todavia\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                    }
                        break;
                    }
                        if (NroPacient<1&&NroPrioridad<1) {
                            system("cls");
                            printf("No hay pacientes para mostrar\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                        }
        break;

        case 4: if (NroPrioridad>=1) { /// ATENCION DEL MEDICO ///
                    system("cls");
                    printf("Ingrese solo la hora actual: ");
                    scanf("%d", &h);
                    while (h>23 || h<0 || h<hAte  ) {
                    printf("\nLa hora ingresada no puede ser posible. Intentelo de nuevamente.\n");
                    printf("Ingrese solo la hora actual: ");
                    scanf("%d", &h);
                }
               printf("\nIngrese solo los minutos actuales: ");
               scanf("%d", &m);
               if (h==hAte ){
                    while (m>59 || m<0 || m<mAte || m==mAte ) {
                        printf("\nLos minutos ingresados no pueden ser posibles. Intentelo de nuevamente.\n");
                        printf("\nIngrese solo los minutos actuales: ");
                        scanf("%d", &m);
                    }
               }
               else{
                    while (m>59 || m<0) {
                        printf("\nLos minutos ingresados no pueden ser posibles. Intentelo de nuevamente.\n");
                        printf("\nIngrese solo los minutos actuales: ");
                        scanf("%d", &m);
                    }
               }
                    hAte=h;
                    mAte=m;
                    NroAtendidos+=1;
                    system("cls");
                    atencionMedico(&paciP, NroAtendidos, hAte, mAte);
                    printf("\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                    NroPrioridad-=1;
                }
                    else {
                        system("cls");
                        printf("No hay pacientes para ser atendidos por el medico.\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                    }

        break;

        case 5: if (NroPacient>=1 || NroPrioridad>=1) { /// RETIRO DE UN PACIENTE POR D.N.I///
                    int encontrado;
                    system("cls");
                    printf("Ingrese el D.N.I del paciente que se retiro sin ser atendido: ");
                    scanf("%ld", &dnii);
                    encontrado=retiro_voluntario(dnii, &pacien, NroPacient);
                    if(encontrado==1){
                        NroPacient-=1;
                        NroAtendidos+=1;
                        printf("El paciente se ha retirado del sistema con exito!\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                    }
                        else if(encontrado==0){
                            printf("\nNO SE ENCONTRO EL PACIENTE EN LA LISTA DE ESPERA.\nBUSCANDO EN LISTA DE PRIORIDAD...\n\n");
                            encontrado=retiro_voluntario_prioridad(dnii, &paciP, NroAtendidos);
                        }
                            if (encontrado==0) {
                                printf("No se ha encontrado al paciente deseado\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                            }
                                else{
                                    NroPrioridad-=1;
                                    NroAtendidos+=1;
                                    printf("El paciente se ha retirado del sistema con exito!\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                }

                }
                    else{
                        system("cls");
                        printf("No hay pacientes para retirar.\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                    }
        break;

        case 6: system("cls"); /// INGRESAR PACIENTES POR URGENCIA ///
                printf("PREPARANDO EL INGRESO DE EL/LOS PACIENTES POR URGENCIA...\n\n");
                printf("Ingrese solo la hora actual: ");
                scanf("%d", &h);
                while (h>23 || h<0 || h<hUrg || h<hIng ) {
                    printf("\nLa hora ingresada no puede ser posible. Intentelo de nuevamente.\n");
                    printf("Ingrese solo la hora actual: ");
                    scanf("%d", &h);
                }
               printf("\nIngrese solo los minutos actuales: ");
               scanf("%d", &m);
               if (h==hUrg || h==hIng){
                    while (m>59 || m<0 || m<mUrg || m==mUrg) {
                        printf("\nLos minutos ingresados no pueden ser posibles. Intentelo de nuevamente.\n");
                        printf("\nIngrese solo los minutos actuales: ");
                        scanf("%d", &m);
                    }
               }
               else{
                    while (m>59 || m<0) {
                        printf("\nLos minutos ingresados no pueden ser posibles. Intentelo de nuevamente.\n");
                        printf("\nIngrese solo los minutos actuales: ");
                        scanf("%d", &m);
                    }
               }
                hUrg=h;
                mUrg=m;
                printf("\nIngresar la cantidad de pacientes que pasan por urgencia: ");
                scanf("%d",&Nro);
                while (Nro<0) {
                    printf("\nSe ingreso un numero negativo de ingreso de pacientes. Intentelo de nuevamente.\n");
                    printf("\nIngresar la cantidad de pacientes que pasan por urgencia: ");
                    scanf("%d", &Nro);
                }
                if (Nro>0) {
                    system("cls");
                    NroAtendidos+=ingreso_urgencia(Nro, NroAtendidos, hUrg, mUrg);
                    system("cls");
                    /*muestra_urgencia(Nro, hUrg, mUrg);*/
                    printf("Se han ingresado los %d pacientes por urgencia con exito!\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n", Nro);
                }
                else{
                    system("cls");
                    printf("No se ha ingresado ningun paciente por urgencia\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                }
        break;

        case 7: if (NroPacient>=1) { /// MOSTRAR SIGUIENTE PACIENTE POR SER ATENDIDO ///
                system("cls");
                do{
                printf("1>Por la enfermera\t2>Por el medico\n");
                printf("\nIngrese la opcion a realizar: ");
                scanf("%d", &x);
                    if (x<1 || x>2) {
                        printf("\nHa ingresado el numero %d.\n", x);
                        printf("\nLa opcion ingresada es incorrecta. Por favor intetelo nuevamente...\n");
                    }
                    }while(x!=1 && x!=2);
                }
                    switch (x) {
                        case 1: system("cls");
                                printf("******************************\n");
                                printf("\nEL PROXIMO PACIENTE PARA SER ATENTIDO POR LA ENFERMERA ES:\n\n");
                                muestra_siguiente(pacien);
                                printf("\n******************************\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");


                        break;

                        case 2: if(NroPrioridad>=1){
                                   system("cls");
                                    printf("\n******************************\n");
                                    printf("\nEL PROXIMO PACIENTE POR SER ATENDIDO POR EL MEDICO ES:\n");
                                    mostrarPrimero(paciP);
                                    printf("\n******************************\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                }
                                    else{
                                        system("cls");
                                        printf("No hay pacientes para mostrar\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                    }
                        break;
                    }
                        if (NroPacient<1) {
                            system("cls");
                            printf("No hay pacientes para mostrar\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                        }
        break;
        case 8: if (NroPacient>=1 || NroPrioridad>=1 ) { /// MODIFICAR EDAD ///
                system("cls");
                do{
                printf("\n1>De un paciente sin ser atendido por la enfermera\t2>Paciente atendido por la enfermera\n");
                printf("\nIngrese la opcion a realizar: ");
                scanf("%d", &x);
                    if (x<1 || x>2) {
                        printf("\nHa ingresado el numero %d.\n", x);
                        printf("\nLa opcion ingresada es incorrecta. Por favor intetelo nuevamente...\n");
                    }
                    }while(x!=1 && x!=2);
                }
                    switch (x) {
                        case 1: system("cls");
                                if(NroPacient>=1){
                                    printf("Ingrese el D.N.I del paciente que desea cambiar la edad: ");
                                    scanf("%ld", &dnii);
                                    if(modificarEdad(dnii, &pacien)==1){
                                     printf("\nSe modifico la edad del paciente con exito!\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                    }
                                    else{
                                       printf("\nNo se encontro el paciente solicitado.\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                    }
                                }
                                else{
                                    printf("No hay pacientes en esta lista...\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                }

                        break;

                        case 2: if(NroPrioridad>=1){
                                    system("cls");
                                    printf("Ingrese el D.N.I del paciente que desea cambiar la edad: ");
                                    scanf("%ld", &dnii);
                                    if (modificarEdadPrioridad(&paciP,dnii)==1) {
                                    printf("\nSe modifico la edad del paciente con exito!\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                    }
                                        else{
                                            printf("\nNo se encontro el paciente solicitado.\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                        }
                                }
                                else{
                                    printf("No hay pacientes en esta lista...\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                }

                        break;
                    }
                        if (NroPacient<1) {
                            system("cls");
                            printf("No hay pacientes para modificar la edad\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                        }
        break;
        case 9: if(NroAtendidos>=0 || NroPrioridad>=1) { /// MUESTRA PACIENTE ATENDIDOS Y NO ATENDIDOS ///
                system("cls");
                    do{
                        printf("\n1>Listado por nivel de urgencia dado\n2>Mostrar todos(Tiempo de espera)\n3>Mostrar paciente que espero mas tiempo\n4>Mostrar cuantos fueron atendidos o se retiraron\n");
                        printf("\nIngrese la opcion a realizar: ");
                        scanf("%d", &x);
                            if (x<1 || x>4) {
                                printf("\nHa ingresado el numero %d.\n", x);
                                printf("\nLa opcion ingresada es incorrecta. Por favor intetelo nuevamente...\n");
                            }
                    }while(x!=1 && x!=2 && x!=3 && x!=4);
                }
                    switch (x) {
                        case 1: system("cls");
                                printf("Ingrese el nivel de urgencia de los pacientes que desea ver: ");
                                scanf("%d", &Nro);
                                mostrarAtendido(NroAtendidos, Nro);
                        break;

                        case 2: system("cls");
                                mostrarTiempoEspera(NroAtendidos);
                        break;

                        case 3: system("cls");
                                Nro=recursivaAtendidos(NroAtendidos, 0, 0);
                                printf("El paciente que mas espero es: %s %s\n",atendidos[Nro].nom, atendidos[Nro].ape);
                        break;

                        case 4: system("cls");
                                printf("Por el momento fueron atendidos o se retiraron por su cuenta: %d\n", NroAtendidos+1);
                        break;

                if (NroAtendidos<0){
                        system("cls");
                        printf("No hay pacientes atendidos para mostrar\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                }
                    break;
                    }
                break;
        case 10:    system("cls"); /// ESCRITURA Y CARGA DE ARCHIVOS ///
                    printf("\n1>Escribir en un .txt los pacientes que no fueron atendidos\n2>Cargar de un .txt a la lista de ingreso un listado de pacientes\n");
                    do{
                        printf("\nIngrese la opcion a realizar: ");
                        scanf("%d", &x);
                        if (x<1 || x>2) {
                            printf("\nHa ingresado el numero %d.", x);
                            printf("\nLa opcion ingresada es incorrecta. Por favor intetelo nuevamente...\n");
                        }
                    }while(x!=1 && x!=2);
                    switch (x) {
                    case 1: system("cls");
                            if (NroAtendidos >=0){
                            FILE *fp=fopen("noatendidos.txt","w+");
                            if(fp==NULL){
                                printf("ERROR AL ABRIR EL ARCHIVO!!...\n");
                                exit(1);
                            }
                            cargaArchivo(&paciP, fp);
                            fclose(fp);
                    }
                    else{
                                printf("No hay pacientes atendidos\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                            }
                    break;

                    case 2: system("cls");
                            FILE *fp2=fopen("precarga.txt","r+");
                            if(fp2==NULL){
                                printf("ERROR AL ABRIR EL ARCHIVO!!...\n");
                                exit(1);
                            }
                            NroPacient+=lecturaArchivo(&pacien, fp2); /// CHEQUEAR MUTUAL ///
                            fclose(fp2);
                    break;
                    }
        break;
        case 11:if (NroPacient>=1 || NroPrioridad>=1) { /// CANTIDAD DE PACIENTES DETRAS (SEGUN D.N.I) ///
                    system("cls");
                    do{
                        printf("1>Por espera de la enfermera\t2>Por espera del doctor\n");
                        printf("\nIngrese la opcion a realizar: ");
                        scanf("%d", &x);
                        if (x<1 || x>2) {
                            printf("\nHa ingresado el numero %d.\n", x);
                            printf("\nLa opcion ingresada es incorrecta. Por favor intetelo nuevamente...\n");
                        }
                    }while(x!=1 && x!=2);
                }
                    switch (x) {
                        case 1: if(NroPacient>=1) {
                                    system("cls");
                                    printf("Ingrese el D.N.I del paciente: ");
                                    scanf("%ld", &dnii);
                                    if (buscaDniLisPac(pacien, dnii)==-1){
                                    printf("No se encontro el D.N.I solicitado\n");
                                    }
                                    else{
                                        printf("\nCantidad de pacientes detras esperando: %d\n", buscaDniLisPac(pacien, dnii));
                                    }
                                }
                                else{
                                    system("cls");
                                    printf("No hay pacientes para mostrar\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                }

                        break;

                        case 2: if(NroPrioridad>=1){
                                    system("cls");
                                    printf("Ingrese el D.N.I del paciente: ");
                                    scanf("%ld", &dnii);
                                    if(buscaDniLisPrio(paciP, dnii)==-1){
                                        printf("No se encontro el D.N.I solicitado\n");
                                    }
                                    else{
                                        printf("\nCantidad de pacientes detras esperando: %d\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n", buscaDniLisPrio(paciP, dnii));
                                    }
                                }
                                else{
                                    system("cls");
                                    printf("No hay pacientes para mostrar\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                                }

                        break;
                    }
                    if (NroPacient<=0 || NroPrioridad<=0){
                        system("cls");
                        printf("No hay pacientes para mostrar\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                    }
        break;

        case 12:if (NroPacient>0 || NroPrioridad>0){ /// MUESTRA DE PACIENTES EN LISTA DE INGRESO Y PRIORIDAD ///
                    system("cls");
                    printf("Pacientes en espera en ingreso: %d\n", NroPacient);
                    printf("Pacientes en espera del medico: %d\n", NroPrioridad);
                    printf("\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                }
                else{
                    system("cls");
                    printf("No hay ningun paciente en ninguna lista de espera\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                }

        break;

        case 13: system("slc");
                if (NroPrioridad>=1) { /// MUESTRA CUANTOS PACIENTES HAY POR NIVEL DE URGENCIA ///
                    system("cls");
                    MostrarEnListPrioridad(paciP, NroPrioridad);
                }
                else{
                    printf("No hay ningun paciente en lista prioridad\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                }

        break;

        case 14: system("slc");
                if (NroAtendidos>=1){ /// ALMACENA LOS DATOS DE LOS PACIENTES ATENDIDOS ///
                    FILE *fp;
                    fp=fopen("PacientesAtendidos.dat", "w+");
                    if(fp==NULL){
                        printf("ERROR AL ABRIR EL ARCHIVO!!...\n");
                        exit(1);
                    }
                    cargaArchivoAten(fp, NroAtendidos);
                    fclose(fp);
                    FILE *fp1, *fp2, *fp3;
                    fp1=fopen("PacientesAtendidosNv1.dat", "w+");
                    if(fp1==NULL){
                        printf("ERROR AL ABRIR EL ARCHIVO!!...\n");
                        exit(1);
                    }
                    fp2=fopen("PacientesAtendidosNv2.dat", "w+");
                    if(fp2==NULL){
                        printf("ERROR AL ABRIR EL ARCHIVO!!...\n");
                        exit(1);
                    }
                    fp3=fopen("PacientesAtendidosNv3.dat", "w+");
                    if(fp3==NULL){
                        printf("ERROR AL ABRIR EL ARCHIVO!!...\n");
                        exit(1);
                    }
                    cargaArchivoAtenUrg(fp1, fp2, fp3, NroAtendidos);
                    fclose(fp1);
                    fclose(fp2);
                    fclose(fp3);

                }
                else{
                    printf("No hay ningun paciente atendido\n\nVOLVIENDO AL MENU PRINCIPAL...\n\n");
                }

        break;

    default: if (x<0 || x>14) {
                system("cls");
                printf("Ha ingresado el numero %d.\n", x);
                printf("\nLa opcion ingresada es incorrecta. Por favor intetelo nuevamente...\n\n");
             }
        }
    }while (x!=0);
    system("cls");
    printf("CERRANDO...\n\nGracias por usar el sistema de organizacion hospitalario de Funes y Garcia!\n");
}
