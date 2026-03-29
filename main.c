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

// CODIGO ARMADO POR JAVIER
/* #include <stdio.h>
#include <stdlib.h>

// Definicion del nodo

    typedef struct nodo {
        int info;
        struct nodo *sig;

    }tnodo;

// tipo lista
    typedef tnodo *Lista;

    // Funcion creaNodo
    Lista creaNodo(int dato)
    {
        Lista p = malloc(sizeof(tnodo));
        if (p == NULL) {
            printf("No hay espacio suficiente. Este programa de cerra.\n");
            exit(1);
        }
        p->info = dato;
        p->sig = NULL;

        return p;
    }



// Funcion para leer el archivo y construir la lista
    Lista leeArchivo(char nombreArchivo[30]) {
        FILE *archivo;
        Lista inicio = NULL;
        Lista nuevo, aux;
        int dato;

        archivo = fopen(nombreArchivo, "r");
        if (archivo == NULL) {
            printf("Error: no se pudo abrir el archivo %s\n", nombreArchivo);
            return NULL;
        }

        // Lee enteros hasta llegar al final del archivo

        while (fscanf(archivo, "%d", &dato) == 1) {
            nuevo = creaNodo(dato);
            if (inicio == NULL) {
                inicio = nuevo;
            }
            else {
                aux = inicio;
                while (aux -> sig != NULL) {
                    aux = aux -> sig;
                }
                aux -> sig = nuevo;
            }
        }
        fclose(archivo);
        return inicio;
    }

    // Funcion para imprimir la lista
    void imprimeLista(Lista lista) {
        Lista aux = lista;
        if (aux == NULL) {
            printf("La lista esta vacia. \n");
            return;
        }
        printf("Contenido de la lista: \n");
        while (aux != NULL) {
            printf("%d ", aux -> info);
            aux = aux -> sig;
        }
        printf("\n ");

    }

// Programa principal
int main() {
        Lista listaNumeros;
        char nombreArchivo[30] = "datos.txt";
        listaNumeros = leeArchivo(nombreArchivo);
        imprimeLista(listaNumeros);
        return 0;
    }
   */