#include <stdio.h>
#include <stdlib.h>
#include "mistring.h"

/**
 * Devuelve entero con la longitud de la string pasada por parametro
 * 
 * @param string cuya longitud ha de ser analizada
 * @return numero de caracteres que tiene la string
 */
int mi_strlen(char* s1){
    // Version 1 del codigo, podemos ahorrar las variables locales
    //if (s1 == NULL) return -1;
    //char* puntero = s1;
    //int contador = 0;
    //while (*puntero != '\0'){
    //    puntero++;
    //    contador++;
    //}
    //return contador;

    // Version final
    if (s1 == NULL) return -1;
    int longitud = 0;
    while (*s1 != '\0'){
        s1++;
        longitud++;
    }
    return longitud;
}

/**
 * Copia los caracteres de la segunda string en la primera y añade NULL al final, devolviendo la direccion de la primera
 * 
 * @param string s2 cuyos caracteres han de ser copiados en string s1
 * @return direccion s1
 */
char* mi_strcpy(char* s1, char* s2){
    // Version 1 del codigo, podemos ahorrar variables locales
    //if (s1 == NULL || s2 == NULL) return NULL;
    //char* puntero1 = s1;
    //char* puntero2 = s2;
    //while (*puntero2 != '\0'){
    //    *puntero1 = *puntero2;
    //    puntero1++;
    //    puntero2++;
    //}
    //*puntero1 = '\0';
    //return s1;

    // Version final
    if (s1 == NULL || s2 == NULL) return NULL;
    char* dir_inic = s1;
    while (*s2 != '\0'){
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return dir_inic;
}

/**
 * Añade los carcteres de la segunda string al final de la primera y devuelve la direccion de la primera
 * 
 * @param string s2 cuyos caracteres deben ser concatenados a string s1
 * @return direccion s1
 */
char* mi_strcat(char* s1, char* s2){
    // Version 1 del codigo, podemos ahorrar variables locales
    //if (s1 == NULL || s2 == NULL) return NULL;
    //char* puntero1 = s1;
    //char* puntero2 = s2;
    //while(*puntero1 != '\0'){
    //    puntero1++;
    //}
    //puntero1 = mi_strcpy(puntero1, puntero2);
    //return s1;

    // Version final
    if (s1 == NULL || s2 == NULL) return NULL;
    char* dir_inic = s1;
    while (*s1 != '\0'){
        s1++;
    }
    s1 = mi_strcpy(s1, s2);
    return dir_inic;
}

/**
 * Crea un duplicado de la string parada por parametro y devuelve la direccion del duplicado
 * 
 * @param string a duplicar
 * @return direccion duplicado
 */
char* mi_strdup(char* str){
    // Version 1 del codigo, podemos ahorrar variables locales y debemos comprobar que el malloc() no de error
    //if (str == NULL) return NULL;
    //char* duplicado = malloc(sizeof(char)*mi_strlen(str));
    //char* puntero = str;
    //duplicado = mi_strcpy(duplicado, puntero);
    //return duplicado;
    if (str == NULL) return NULL;
    char* duplicado = malloc(sizeof(char)*mi_strlen(str));
    if (duplicado == NULL){
        return NULL;
    }
    duplicado = mi_strcpy(duplicado, str);
    return duplicado;
}

/**
 * Compara las strings s1 y s2. Si son iguales, devuelve un 1, si no, devuelve un 0.
 * 
 * @param string s1 que se compara con string s2
 * @return entero que indica si son iguales ambas strings (SI -> 1, NO -> 0)
 */
int mi_strequals(char* s1, char* s2){
    // Version 1 del codigo, podemos ahorrar variables locales, podemos evitar el doble bucle
    //if (s1 == NULL || s2 == NULL) return -1;
    //if (mi_strlen(s1) != mi_strlen(s2)) return 0;
    //char* puntero1 = s1;
    //char* puntero2 = s2;
    //while (*puntero1 != '\0' && *puntero2 != '\0'){
    //    if (*puntero1 != *puntero2) return 0;
    //    puntero1++;
    //    puntero2++;
    //}
    //return 1;

    // Version final
    if (s1 == NULL || s2 == NULL) return -1;
    while (*s1 == *s2){
        if (*s1 == '\0' || *s2 == '\0') break;
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0') return 1;
    else return 0;
}