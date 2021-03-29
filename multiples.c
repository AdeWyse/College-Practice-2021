/*https://www.urionlinejudge.com.br/judge/pt/problems/view/2060
Find the multiples of 2, 3, 4 and 5 in a list.*/
#include <stdio.h>

int main()
{
   int size, i, m2=0, m3=0, m4=0, m5=0;
  
   scanf("%d", &size);
   int bino[size];
    for(i = 0; i < size; ++i) {
     scanf("%d", &bino[i]);
  }
  for(i = 0; i < size; ++i) {
      if(bino[i]%2==0){
         m2++;
        
     }
     if(bino[i]%3==0){
         m3++;
     }
     if(bino[i]%4==0){
         m4++;
     }
     if(bino[i]%5==0){
         m5++;
     }
     
  }
    printf("%d Multiplo(s) de 2\n", m2);
    printf("%d Multiplo(s) de 3\n", m3);
    printf("%d Multiplo(s) de 4\n", m4);
    printf("%d Multiplo(s) de 5\n", m5);
    return 0;
}

