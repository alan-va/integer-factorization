#define nomePrograma "fatora"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <time.h>

#define maiorInteiro LONG_MAX

void usage(int status)
{
  printf("%s%s%s\n\n%s\n%s\n\n%s%s%s\n",
    "Uso: ", nomePrograma, " [NUMERO]",
    "Exibe cada fator primo de NUMERO junto com sua multiplicidade.",
    "Para visualizar o maior inteiro representavel, use NUMERO = -1.",
    "Exemplo: ", nomePrograma, " 29874636");
  exit(status);
} /* fim - usage */

static int fatoraInteiros(long int Num)
{
  bool fatorPrimo = true, numeroPrimo = true;
  long int AuxN = Num; 
  int k; size_t i, j;

  if (Num % 2 == 0 && Num != 2)
  {
    numeroPrimo = false; k = 0;
    while (AuxN % 2 == 0) { k++; AuxN = AuxN / 2; }
    printf(" 2^%d\n", k);
    if (AuxN == 1) { return 0; }
  }
    
  for (i = 3; AuxN != 1 && i <= floor(Num/2); i += 2)
  {
    if (AuxN % i == 0)
    {
      numeroPrimo = false; fatorPrimo = true;

      for (j = 3; j <= floor(sqrt(i)); j += 2)
      {
        if (i % j == 0) { fatorPrimo = false; break; }
      }

      if (fatorPrimo)
      {
        k = 0;
        while (AuxN % i == 0) { k++; AuxN = AuxN / i; }
        printf(" %ld^%d\n", i, k);
      }
    }
  }
  
  if (numeroPrimo)
    printf("--> %ld é um número primo!\n", Num);

  return 0;
} /* fim - fatoraInteiros */

int main(const int argc, char * const argv[])
{
  long int N = 0;
  float tempoExec = 0.0;
  clock_t tic, tac;
  
  if (argc != 2)
    usage(EXIT_SUCCESS);
  else 
    N = atol(argv[1]);

  if (N == -1)
    printf("Maior inteiro representável: %ld\n", maiorInteiro);
  else if (N == 1)
    printf("--> https://primes.utm.edu/notes/faq/one.html\n");
  else if (N <= 0)
    printf("São válidos apenas valores positivos.\n");
  else
  {
    printf("-Fatores primos de %ld:\n\n", N);

    tic = clock();
    fatoraInteiros(N);
    tac = clock();

    tempoExec = (double)(tac - tic) / CLOCKS_PER_SEC;
    printf("\n-Tempo de execução: %.5fs\n", tempoExec);
  }

  return 0;
} /* fim - main */
