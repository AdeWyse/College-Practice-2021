/*https://www.urionlinejudge.com.br/judge/pt/problems/view/1080*/
#include <stdio.h>

int main()
{
    int valor, i, comp, pos;
    for(i=1; i<= 100; i++)
    {
       scanf("%d", &valor);
       if(valor>comp)
       {
           comp = valor;
           pos = i;
       }
    }
    printf("%d\n", comp);
    printf("%d\n", pos);
    return 0;
}
