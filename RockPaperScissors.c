// Por favor, ejecutar en sistemas Unix para poder hacer uso de clear y sleep .
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char messages() {
     printf("BIENVENIDO AL PIEDRA PAPEL O TIJERA\n");
     printf("Preciona [intro] para continuar:");
     getchar();
     system("clear");
     printf("Hoy vas a pelear contra la maquina\n");
}

char menu() {
     printf("Estos son los movimientos\n");
     system("sleep 2");
     system("clear");
     printf("Piedra[r], Papel[p] y Tijera[s]\n");
     system("sleep 1");
     printf("Elige: ");
}

int movement_mach() {
     int mvnt = rand() % 3 + 1;
     if(mvnt == 1){
          printf("La maquina elige Piedra\n");
          return 1;
     }
     else if (mvnt == 2){
          printf("La máquina elige Papel\n");
          return 2;
     }
     else {
          printf("La máquina elige Tijeras\n");
          return 3;
     }
}

int game() {
     srand(time(NULL));

     printf("¿Estás preparado? [y/n]: ");
     int q = getchar();
     getchar();

     if (q == 'y') {
          menu();
          int slct = getchar();
          getchar();

          if (slct == 'r' || slct == 'p' || slct == 's'){
               int m = movement_mach();
               if (slct == 'r'){
                    if(m != 2 || m == 1) {
                         if(m == 1){
                              printf("Has empatado\n");
                              printf("Volviendo...");
                              system("sleep 2");
                              game();
                         }else {
                              printf("Piedra aplasta tijera\n");
                              printf("¡Has ganado!\n");
                         }

                    }else {
                         printf("Papel cubre piedra.\n");
                         printf("Oh, has perdido, ¿desea volver a intantarlo [y/n]?: ");
                         int rtry =  getchar();
                         getchar();
                         if(rtry == 'y'){
                              game();
                         }
                    }
               }
               else if(slct == 'p'){

                    if(m != 3 || m == 2) {
                         if(m == 2){
                              printf("¡Has empatado!\n");
                              printf("Volviendo...");
                              system("sleep 2");
                              game();
                         }else {
                              printf("Papel cubre piedra\n");
                              printf("¡Has ganado!\n");
                         }

                    }else {
                         printf("Tijera corta papel.\n");
                         printf("Oh, has perdido, ¿desea volver a intentarlo [y/n]?: ");
                         int rtry =  getchar();
                         getchar();
                         if(rtry == 'y'){
                              game();
                         }
                    }
               }
               else if(slct == 's') {
                    if(m != 1 || m == 3) {
                         if(m == 3){
                              printf("¡Has empatado!\n");
                              printf("Volviendo...");
                              system("sleep 2");
                              game();
                         }else{
                              printf("Tijera corta papel\n");
                              printf("¡Has ganado!\n");
                         }

                    }else {
                         printf("Piedra aplasta tijeras.\n");
                         printf("Oh, has perdido, ¿desea volver a intentarlo [y/n]?: ");
                         int rtry =  getchar();
                         getchar();
                         if(rtry == 'y'){
                              game();
                         }
                    }
               }

          }else {
               printf("Por movimiento erroneo, por favor, repita su elección.\n");
               game();   
          }
     }
     else if (q == 'n') {
          printf("Oh, vaya, entonces nos veremos a la próxima.\n");

     }else {
          printf("\nPor favor ingrese la opción correcta.\n");
          game();
     }
}

int main() {
     messages();
     game();    
}