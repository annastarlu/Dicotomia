/*GRUPO 10*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float CalculaValorK(float a, float b, float erro);
float funcaoX(float ponto, int grau, float *p);
void ImprimirCabecalhoTabela();
void ImprimirTabela(int iteracao, float a, float b, float m, float fA, float fB, float fM, char fAfM, char fMfB);
void aloca(float **p,int tamanho);

main()
{
	int grau,K;
//float multi[7]; //Indice 0 a 6
	float *multi = NULL;
    int i, iteracao=0;
    float a, b, m, erro,fa,fb,fm;
    char fafm,fbfm;
    printf("Informe o grau da funcao (2 a 6): ");
    scanf("%i", &grau);

	//Receber os multiplicadores. Dica: Armazenar os valores em um vetor.
	//aX^0 + bX^1 + cX^2 --->Indice do vetor igual ao expoente
	aloca(&multi, grau);
    for(i=grau; i>=0; i--)
    {
        printf("Informe o fator multiplicador de x^%i(%c): ", i, 65+(grau-i));
        scanf("%f", multi+i);
    }


    //Exibindo a funcao recebida
    printf("A funcao recebida foi: ");
    for(i=grau; i>=0; i--)
    {
        if(i==0)
            printf("%.2f = 0\n", multi[i], i);
        else
            printf("%.2fx^%i + ", multi[i], i);
    }
    //Receber os valores de
        //a, b, erro
	printf("Digite o primeiro valor do intervalo: ");
	scanf("%f",&a);
	printf("Digite o segundo valor do intervalo: ");
	scanf("%f",&b);
	printf("Digite o erro: ");
	scanf("%f",&erro);
	//Verificar se no intervalo [A, B] existe zero de funcao
	if(funcaoX(a,grau,multi)*funcaoX(b,grau,multi)>0)
	{
		printf("Intervalo não há zero de funcao");
		exit(1);
	}
	else {
	//Se existir encontar o valor de K
	K = CalculaValorK(a, b, erro);

    //Exibindo o cabecalho
    ImprimirCabecalhoTabela();
    
	while(K!=iteracao)
	{
		iteracao++;
		fa=funcaoX(a,grau,multi);
		fb=funcaoX(b,grau,multi);
		m=((a+b)/2);
		fm=funcaoX(m,grau,multi);
		if(fa*fm<0)
		{
			fafm='-';
		}
		else{
			fafm='+';
		}
		if(fb*fm<0)
		{
			fbfm='-';
		}
		else
		{
			fbfm='+';
		}
		ImprimirTabela(iteracao, a, b, m, fa, fb, fm, fafm, fbfm);
		if (fa * fm < 0)
		{
    		b = m;
		}
		else
		{
    		a = m;
		}
	}

    system("pause");
}
}

float funcaoX(float ponto, int grau, float *multi)
{
    int i;
    float resultado;
    resultado = 0;

    for(i=0; i<=grau; i++)
    {
        resultado = resultado + multi[i]*pow(ponto, i);
    }

    return resultado;
}

float CalculaValorK(float a, float b, float erro)
{
    float fValorK;

    //Realizar o calculo do valor do K
    fValorK = (log10(b-a) - log10(erro))/(log10(2));


    return ceil(fValorK);
}

void ImprimirCabecalhoTabela()
{
	/*
    //Impressao do cabecalho
    printf("I |  a\t|  b\t|  m\t|  f(a)\t|  f(b)\t|  f(m)\t| fa*fm\t| fm*fb\t|\n");
    printf("--+-----+-------+-------+-------+-------+-------+-------+-------+\n");
	*/
	//Impressao do cabecalho
    printf("I |\ta\t|\tb\t|\tm\t|\tf(a)\t|\tf(b)\t|\tf(m)\t|fa*fm\t|fm*fb\t|\n");
    printf("--+-------------+---------------+---------------+---------------+---------------+---------------+-------+-------+\n");

}

void ImprimirTabela(int iteracao, float a, float b, float m, float fA, float fB, float fM, char fAfM, char fMfB)
{
    //printf("%i |%.2f\t|%.2f\t|%.2f\t|%.2f\t|%.2f\t|%.2f\t|%c\t|%c\t|\n", iteracao, a, b, m, fA, fB, fM, fAfM, fMfB);
	printf("%i |%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%c\t|%c\t|\n", iteracao, a, b, m, fA, fB, fM, fAfM, fMfB);
}

void aloca(float **p,int tamanho)
{
	if((*p=(float*)realloc(*p,tamanho*sizeof(float)))==NULL)
	{
		exit(1);
	}
}
