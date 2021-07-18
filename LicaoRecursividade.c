# include <stdio.h>

//vetor e tamanho do vetor como variavel global porque nao sei como faz para passar e modificar vetor dentro de uma funcao para conversao do binario
int binario[100];
int binSize = 0;

int SequenciaFibonacci(int n)
{
    
    if(n < 2)
    {
        return n;
    }
    if(n >=2)
    {
        return SequenciaFibonacci(n - 1) + SequenciaFibonacci( n - 2);
/*nº = (n-1)º + (n-2)º , explicação da formula:
https://math.libretexts.org/Bookshelves/Applied_Mathematics/Book%3A_College_Mathematics_for_Everyday_Life_(Inigo_et_al)/10%3A_Geometric_Symmetry_and_the_Golden_Ratio/10.04%3A_Fibonacci_Numbers_and_the_Golden_Ratio */ 
    }
    
}

int Multiplicacao(int m1, int m2) 
{
    if (m2 == 0)
    {
        return m2;
    }
    else{
        return m1 + Multiplicacao(m1, m2-1);
    } 
}

int Conversao(int ord) 
{
    if (ord <1)
    {
        return 2;
    }
   
    else{
        if (ord % 2== 0)
        {
            binario[binSize] = 0;
        }
        if (ord % 2 != 0)
        {
            binario[binSize] = 1;
        }
        binSize++;
        return Conversao(ord/2);
    } 
}
  

int main()
{
    int tamFi = 0, i = 0, numOrd = 0, m1 = 0, m2 = 0, menu = 4;
    
    
    // while loop para controlar um menu para ficar mais simples de testar todos os exercicios
    while (menu!= 0)
    {
        printf(" Sequencia de Fibonacci - 1\n");
        printf(" Multiplicacao - 2\n");
        printf(" Conversao binario - 3\n");
        printf(" Sair - 0\n");
        printf("Digite a escolha: ");
        scanf("%d", &menu);
        printf("\n");
        switch (menu)
        {
        case 1:

            printf ("Tamanho da sequencia de Fibonacci: ");
            scanf("%d", &tamFi);
            //começa do 1 porque é o exemplo que o exercicio passou.
            for(i=1; i<tamFi; i++)
            {
                 if(i<tamFi-1)
                 {
                    printf("%d, ", SequenciaFibonacci(i)); 
                }else {
                     if(i<tamFi)
                    {
                        printf("%d ...\n ", SequenciaFibonacci(i));
                    }
                }
            }
            break;
        case 2:

            printf("Digite o multiplicador: ");
            scanf("%d", &m1);
            printf("Digite o muitiplicando: ");
            scanf("%d", &m2);
            printf( "%d x %d = %d\n", m1, m2, Multiplicacao(m1,m2));

            break;
        case 3:

            printf ("Numero ordinario: ");
            scanf("%d", &numOrd);
            Conversao(numOrd);
            printf("Numero binario: ");
            for(i = binSize-1; i>= 0; i-- )
            {
                printf("%d", binario[i]);
            }
            printf("\n");
            break;
        default:
            break;
        }
    }

    return 0;
}