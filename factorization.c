#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <time.h>

#define maiorInteiro LONG_MAX /* long_max veio da biblioteca <limits.h> */

// variáveis globais
long int AuxN;
bool numeroPrimo;

static int fatoraInteiros(long int Num)
{
  long int i, j; int k;
  bool fatorPrimo = true;

  if (Num % 2 == 0 && Num != 2)
  {
    numeroPrimo = false; k = 0;
    while (AuxN % 2 == 0) 
    { 
      k++; AuxN = AuxN / 2; 
    }
    printf(" 2^%d\n", k);
    if (AuxN == 1) { return 0; }
  }

  for (i = 3; i <= floor(Num/2); i += 2)
  {
    if (AuxN % i == 0)
    {
      numeroPrimo = false; fatorPrimo = true;

      for (j = 3; j <= floor(sqrt(i)); j += 2)
      {
        if (i % j == 0)
        {
          fatorPrimo = false; break;
        }
      }

      if (fatorPrimo)
      {
        k = 0;
        while (AuxN % i == 0)
        {
          k++; AuxN = AuxN / i;
        }
        printf(" %ld^%d\n", i, k);
        if (AuxN == 1) { break; }
      }
    }
  }

  return 0; /* sem erros */
} /* fim - fatoraInteiros */

int main(void)
{
  long int N;
  float tempoExec;

  printf("Decomposição de inteiros em fatores primos --- Versão C\nDado N, este programa determina:\n\n");
  printf("Cada fator pi (i=1, ... , n) de N e ki, a maior potência de pi que divide N; ou seja\n");
  printf("p1^k1, p2^k2, ... , pn^kn tais que N = (p1^k1) * (p2^k2) * ... * (pn^kn).\n\n");
  printf("[-1] Maior inteiro representável | [-2] Sair do programa\n\n");
  
  while (true)
  {
    printf("<Insira N> "); scanf("%ld", &N); AuxN = N; numeroPrimo = true;

    if (N == -1) { printf("Maior inteiro representável: %ld\n\n", maiorInteiro); }
    else if (N == -2) { printf("\nEncerrando...\n"); exit(0); }
    else if (N == 1)
      printf("\nVery funny.\n\n");
    else if (N <= 0)
      printf("\nSão válidos apenas valores positivos.\n\n");
    else
    {
      printf("\n-Fatores primos de N:\n\n");

      clock_t begin = clock(); // tic...
      fatoraInteiros(N);       // cool stuff
      clock_t end = clock();   // ...toc

      if (numeroPrimo) { printf("--> %ld é um número primo!\n", N); }

      tempoExec = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\n-Tempo de execução: %.2f\n\n", tempoExec);
    }
  }

  return 0;
} /* fim - main */
