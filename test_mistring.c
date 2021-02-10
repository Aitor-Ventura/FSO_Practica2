// test_mistring.c
// ===============
// Batería de pruebas de la biblioteca "mistring"
//
// Podrás empezar a usarla cuando hayas hecho un fichero "mistring.h"
// al menos con los cuerpos vacíos de las funciones mi_strlen, mi_strcat 
// y mi_strequals

#ifndef TEST
#include "mistring.h"
#endif

#include <assert.h>
#include <stdio.h>

// Este bloque es para probar que "test_mistring.c" está correctamente
// escrito, sin necesidad de que aún esté implementado "mi_string.c"
// En ese caso, compilar con la opción -DTEST
#ifdef TEST
#include <string.h>
#define mi_strlen strlen
#define mi_strcat strcat
#define mi_strequals(a,b) (strcmp(a,b)==0)
#endif

#define DebeSerCierto(x)	assert(x)
#define DebeSerFalso(x)		assert(!(x))

void INICIO_TEST (const char* titulo_test)
{
  printf("- bateria de pruebas para %s: ", titulo_test); 
 	// fflush fuerza que se imprima el mensaje anterior
	// sin necesidad de utilizar un salto de línea
	fflush(stdout);
}

void FIN_TEST (const char* titulo_test)
{
  printf ("hecho\n");
}

void test_mi_strlen()
{
  char cadena_1000 [1000];
  int i;
  #define LONGITUD_TEST 500
  for (i=0; i<LONGITUD_TEST; i++) 
  {
    cadena_1000[i] = 32+(rand()%96);
  }
  cadena_1000[LONGITUD_TEST] = '\0'; 
  
  INICIO_TEST("mi_strlen");
	DebeSerCierto(mi_strlen("hola mundo") == 10);
	DebeSerCierto(mi_strlen("") == 0);
	DebeSerCierto(mi_strlen(cadena_1000) == LONGITUD_TEST);

	// Anadido por alumno
	char* s1 = NULL;
	DebeSerCierto(mi_strlen(s1) == -1);
	FIN_TEST("mi_strlen");
}

void test_mi_strcat()
{
	char cadena1[15] = { 'h','o','l','a', '\0' };
	char* resultado = mi_strcat(cadena1," mundo");
	INICIO_TEST("mi_strcat");
	DebeSerCierto(cadena1 == resultado);
	DebeSerCierto(mi_strlen(cadena1)==10);
	DebeSerCierto(mi_strequals(cadena1,"hola mundo"));
	DebeSerFalso(mi_strequals(cadena1,"hola"));

	// Anadido por alumno
	char anadido[100] = {'\0'};
	char* s1 = mi_strcat(anadido, "un cinco");
	DebeSerCierto(mi_strequals(s1, "un cinco"));

	s1 = mi_strcat(anadido, " son seis creditos");
	DebeSerCierto(mi_strequals(s1, "un cinco son seis creditos"));

	char* s2 = NULL;
	DebeSerCierto(mi_strcat(s1,s2) == NULL);

	FIN_TEST("mi_strcat");
}

// Anadido por alumno
void test_mi_strcpy(){
	INICIO_TEST("mi_strcpy");

	char anadido[40];
	char* s1 = mi_strcpy(anadido, "un cinco son seis creditos");
	DebeSerCierto(mi_strequals(s1, "un cinco son seis creditos"));

	s1 = mi_strcpy(anadido, "");
	DebeSerCierto(mi_strequals(s1, ""));
	
	s1 = mi_strcpy(anadido, "alexis tengo tu whatsapp");
	DebeSerCierto(mi_strequals(s1, "alexis tengo tu whatsapp"));

	char* s2 = NULL;
	DebeSerCierto(mi_strcpy(s1,s2) == NULL);

	FIN_TEST("mi_strcpy");
}

// Anadido por alumno
void test_mi_strdup(){
	INICIO_TEST("mi_strdup");

	char* s1 = mi_strdup("hola mundo");
	DebeSerCierto(mi_strequals(s1, "hola mundo"));

	s1 = mi_strdup("");
	DebeSerCierto(mi_strequals(s1,""));

	s1 = mi_strdup("josemi me da teoria");
	DebeSerCierto(mi_strequals(s1, "josemi me da teoria"));

	char* s2 = NULL;
	DebeSerCierto(mi_strdup(s2) == NULL);

	FIN_TEST("mi_strdup");
}

// Anadido por alumno
void test_mi_strequals(){
	INICIO_TEST("mi_strequals");

	char anadido[20];
	char* s1 = mi_strcpy(anadido, "");
	DebeSerCierto(mi_strequals(s1, ""));

	s1 = mi_strdup("hola mundo");
	DebeSerCierto(mi_strequals(s1, "hola mundo"));

	char* s2 = mi_strcpy(anadido, "bochin bochan bochudo");
	DebeSerFalso(mi_strequals(s1, s2));

	char* s3 = NULL;
	DebeSerCierto(mi_strequals(s1, s3) == -1);

	FIN_TEST("mi_strequals");
}

void ejecuta_tests ()
{
	test_mi_strlen();
	test_mi_strcat();
	test_mi_strcpy();
	test_mi_strdup();
	test_mi_strequals();
}

main()
{
	puts("Iniciando tests...");
	
	ejecuta_tests();
	
	puts("Bateria de test completa.");
}
