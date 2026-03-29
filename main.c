#include <stdio.h>
#include <stdlib.h>

struct datos {
    int info;
    struct datos *sig;
};
typedef struct datos *Lista;

Lista crearNodo(int datos) {
    Lista p;

    p = malloc(sizeof(struct datos));
    if (p == NULL) {
        printf("Memoria insuficiente, el programa se cerrar%c", 160);
        exit(0);
    }
    p->info = datos;
    p->sig = NULL;
    return p;
}

Lista leerArchivo(const char* nombreArchivo) {
    FILE *fp = fopen(nombreArchivo, "r");
    if (fp == NULL) {
        perror("Error al abrir el archivo");
        return NULL;
    }

    Lista inicio = NULL;  // primer nodo de la lista
    Lista final = NULL;    // último nodo insertado
    int numero;

/*retorno fscanf
 * 1: leyó un entero (numero es entero) correctamente
 * 0: Encontró un valor que no es el especificado (un entero)
 * EOF -1: Llegó al final del archivo o hubo un error
 */
    while (fscanf(fp, "%d", &numero) == 1) {
        Lista nuevo = crearNodo(numero);

        if (inicio == NULL) {
            inicio = nuevo;   // primer nodo
            final = nuevo;
        } else {
            final->sig = nuevo;  // encadena al final
            final = nuevo;
        }
    }

    fclose(fp);
    return inicio;
}

void imprimeLista(Lista l) {
    Lista actual = l;
    while (actual != NULL) {
        printf("%d", actual->info);
        if (actual->sig != NULL) printf(" -> ");
        actual = actual->sig;
    }
    printf("\n");
}

int main() {
    Lista lista = leerArchivo("./documentos/datos.txt");
    imprimeLista(lista);
    return 0;
}
