#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

int fat(int x)
{
    if(x==0||x==1)
    {
        return 1;
    }
	else if(x>=0)
	{
		return x*fat(x-1);;
	}
	else
	{
        return 0;
	}
}

int comb(int n, int k)
{
	if(n>=k&&n>=0&& n>=0)
	{
		return fat(n)/(fat(n-k)*fat(k));
	}
	else
	{
		return 0;
	}
}

int arrj(int n, int k)
{
	if(n>=k && n>=0 && k>=0)
	{
		return fat(n)/fat(n-k);
	}
	else
	{
		return 0;
	}
}


    int per(int n)
    {
        if(n>0)
        {
            return fat(n);
        }
        else
        {
            return 1;
        }
    }


int main()
{
    int n, k;
    char op;
    setlocale(LC_ALL,"Portuguese");
    printf("qual operação vc gostaria?\n");
    printf("[P]Permutação simples \n[C]Combinação \n[A]Arranjo \n[T] Triangulo de Pascal\n");
        scanf(" %c",&op);

op = toupper(op);
switch(op)
{
//--------- P --------------
    case 'P':
        printf("Digite o valor de n para a permutar: \n");
            scanf("%d",&n);
        printf("Calculando...\n");
        printf("P(%d) =",n,n);
        for(int i=0;i<n;i++)
        {
            printf("*%d",n-i);
        }
        printf("\n");
        printf("\n------ Resultado --------\n");
        printf(" P(%d) = %d\n", n, per(n));
        break;
//------------ C --------------

    case 'C':
        printf("Digite o valor de n: ");
            scanf("%d", &n);
        printf("Digite o valor de k: ");
            scanf("%d", &k);

        if (n>=k && k>=0)
        {
            printf(" C(%d, %d) = %d\n", n, k, comb(n, k));
        }
        else
        {
            printf(" Valores inválidos para Combinação (n >= k >= 0).\n");
        }
        break;

//------------ A --------------

    case 'A':
        printf("Digite o valor de n: ");
            scanf("%d", &n);
        printf("Digite o valor de k: ");
            scanf("%d", &k);

        if (n>=k && k>=0)
        {
            printf(" A(%d, %d) = %d\n", n, k, arrj(n, k));
        }
        else
        {
            printf(" Valores inválidos para Arranjo (n >= k >= 0).\n");
        }

        break;

// ----------- T --------------
    case 'T':
        printf("Quantas linhas terá o nosso triangulo de Pascal?\n");
        scanf("%d",&n);

        printf("Digite um valor para o numero de colunas\n");
        scanf("%d",&k);

        printf("\n============ Relatório ============\n");
        if(n >=0 && n >=k && k>=0)
        {
            printf("\n---------------Conta -----------------\n");
            printf("    (%d, %d) = %d!/ %d * (%d-%d)!\n",n,k,n,k,n,k);
            printf("        (%d, %d) = %d\n",n,k,comb(n,k));

            printf("\n--- Resultado da soma na forma de potencia ----\n");
            printf("2^ %d = %d\n", n,(1 << n));
        }
        else
        {
            printf("Erro: sem solucao para os valores informados \n");
            printf("\n--- Resultado da soma na forma de potencia ----\n");
            printf("2^ %d = %d\n", n,(1 << n));
        }


        printf("\n------TRIANGULO FORMADO--------\n");
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                printf("%d",comb(i,j));
            }
            printf("\n");
        }
        break;

}
return 0;
}
