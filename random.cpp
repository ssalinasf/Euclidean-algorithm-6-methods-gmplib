
#include <stdlib.h>             /* Standard Lib    ISOC  */
#include <stdio.h>              /* I/O lib         ISOC  */
#include <stdarg.h>             /* Variable args   ISOC  */
#include <gmp.h>                /* GNU GMP Library       */
#include <math.h>
#include <time.h>
#include "a4.cpp"



int main(int argc, char const *argv[]) {
  mpz_t a; // Random number a
  mpz_t b; // random number b
  mpz_t piso;
  int nBit; // 2^(nbit) cantidad de bits
  gmp_randstate_t state;
  gmp_randstate_t stateb;


  // a y b van a contener números random
  mpz_init(a);
  mpz_init(b);
  mpz_init(piso);
  float MAX = 0;
  nBit = 1200;
  mpz_ui_pow_ui(piso,2,nBit); // piso= 2^(nBit)

  gmp_randinit_default(state);
  gmp_randseed_ui(state, 10);

  bool flag=0;
	clock_t tStart;
  float t;


  for(int i = 0; i<=10; i++){

    tStart = clock();

    mpz_urandomb(a, state, nBit);
    mpz_add(a,a,piso); // le suma a un número de 2^(nBit) para asegurarse que sea el minimo número a mostrar
    mpz_urandomb(b, state, nBit);

    t += (double)(clock() - tStart)/CLOCKS_PER_SEC;


    if(MAX < (double)(clock() - tStart)/CLOCKS_PER_SEC){
      MAX=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    }
    printf("\n i= %d t =  %.7f", i, (double)(clock() - tStart)/CLOCKS_PER_SEC);
  }
  printf("\nMAX =  %.7f \n", MAX);
  printf("\nt =  %.7f \n", t/10);
  gmp_randclear(state);
  mpz_clear(a);
  mpz_clear(b);
  mpz_clear(piso);
  return 0;

}
