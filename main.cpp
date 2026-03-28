#include <stdio.h>

int main () {
    FILE * fp = fopen("./documentos/datos.txt","r");
    if (fp == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
}