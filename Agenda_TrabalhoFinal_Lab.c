/* 
Trabalho de conclusão de disciplina de Laboratório de informatica
Aluna: Adeline Rodrigues Cruz Wyse Guimarães
Professor: Francisco Pereira Junior (Thesko)
Inicio do projeto: 13/05/2021
Fim do projeto:16/05/2021

*/
#include <stdio.h>
#include <string.h>
//Struct de estrutura de numeros para a data
typedef struct data{
    int dia;
    int mes;
    int ano;
}data;

//Struct de estrutura heterogenea para os dados do contato
typedef struct contato
{
    char nome[50];
    char email[50];
    char telefone[20];
    data dataN;
}contato;

//Função para imprimir o contato passado no parametro
void Imprimir(contato cont)
{
    printf("Nome: %s\n", cont.nome);
    printf("E-mail: %s\n", cont.email);
    printf("Telefone: %s\n", cont.telefone);
    printf("Aniversário: %d / %d / %d\n", cont.dataN.dia, cont.dataN.mes, cont.dataN.ano);
    printf("\n");
}

//Função para validar o email, primeiro valida a parte do @, depois a parte do .COM - imprime o "Email invalido" antes de voltar a função que chamou
int ValidarEmail(char email[])
{
    int j=0, isValid=0, sizeV=0, fimV;
    for(j = 0; j <= strlen(email);j++)
    {
        if(email[j] == '@' && j>2)
        {
            sizeV = 1;
        }
    }
    j = strlen(email);
    
    if(email[j-1] == 'M' && email[j-2] == 'O' && email[j-3] == 'C' && email[j-4] == '.')
    {
        fimV = 1;
    }
    if(sizeV == 1 && fimV == 1)
    {
        isValid = 1;
    }else{
        printf("E-mail inválido.\n");
    }
    return isValid;
}

//Função para validar o telefone, primeira valida se todos os chars são numeros, depois valida o tamaho e depois se o primeiro elemento é 0 - imprime o "Número invalido" antes de voltar a função que chamou
int ValidarTelefone(char telefone[])
{
    int i=0, typeV=0, sizeV=0, comecoV=0, size=0 , isValid=0;
// testa para ver se todos os chars sao numeros, sai do loop se algum deles não for
    for(i = 0; i < strlen(telefone); i++)
    {
        if(telefone[i] >= '0' && telefone[i]<='9')
        {
            typeV = 1;
        }else{
            typeV = 0;
            break;
        }
    }
    // size comparando com 10 e 11 porque estava dando errado. Acho que tem haver com a posição do \0
    size = strlen(telefone)-1;
    if( size == 10 || size == 11)
    {
        sizeV = 1;
    }
    if(telefone[0] == '0')
    {
        comecoV = 1;
    }
    if(typeV==1 && sizeV == 1 && comecoV == 1)
    {
        isValid = 1;
    }else{
        printf("Número inválido.\n");
    }
    return isValid;
}

//Função para validar a data, primeiro o dia, depois o mes, depois o Ano
int ValidarData(data aniv)
{
    int diaV=0, mesV=0, anoV=0, isValid = 0;
    if( aniv.dia >= 1 && aniv.dia <= 30)
    {
        diaV = 1;
    }else {
        printf("Dia inválido.\n");
    }
    if( aniv.mes >=1 && aniv.mes <= 12)
    {
        mesV = 1;
    }else {
        printf("Mês inválido.\n");
    }
    if( aniv.ano >= 1900 && aniv.ano <=2021)
    {
        anoV = 1;
    }else {
        printf("Ano inválido.\n");
    }
    if(diaV == 1 && mesV == 1 && anoV == 1)
    {
        isValid = 1;
    }
    return isValid;
}
//Função para cadastro, chama as funções VALIDAR quando nescessario
contato Cadastro(contato novoC)
{   printf("Novo contado\n");
    printf("Digite o nome: ");
    gets(novoC.nome);
    do
    {
        printf("Digite o email: ");
        gets(novoC.email);
        
    }while(ValidarEmail(novoC.email) == 0);
    do
    {
        printf("Digite o telefone: ");
        gets(novoC.telefone);
    }while(ValidarTelefone(novoC.telefone) == 0);
    do
    {
        printf("Digite a data de nascimento:\n");
        printf("    Dia: ");
        scanf("%d", &novoC.dataN.dia);
        printf("    Mês: ");
        scanf("%d", &novoC.dataN.mes);
        printf("    Ano: ");
        scanf("%d", &novoC.dataN.ano);
    }while(ValidarData(novoC.dataN) == 0);
    getchar();
    printf("Contato Cadastrado\n")
    return novoC;
}
// FUnção que mostrar todos os contatos em ordem alfabática
void OrdemAlfabetica(contato agenda[], int size)
{
    int i=0, j=0, a=0, b=0;
    contato temp;
    for(a = 0;i <size; a++)
    {
        for(i = 0; i <size; i++)
        {   
            if(strcmp(agenda[i].nome , agenda[i+1].nome) > 0)
            {
                temp = agenda[i];
                agenda[i] = agenda[i+1];
                agenda[i+1] = temp;
                break;
            }
            
        }
    }
    for(i = 0; i<=size; i++)
    {
        printf("%s | %s | %s \n \n" , agenda[i].nome, agenda[i].email, agenda[i].telefone);
    }
}

/*Função para checar quantos numeros tem o mesmo DDD, primeiro checa o DDD, quando encontra um DDD igual coloca ele no vetor dddIgual.
Quando tudo foi checado  mostrar a quantidade de numeros encontrados e imprime os contatos*/
void DDDCheck(char ddd[], contato agenda[], int size)
{
    int i=0, count=0;
    contato dddIgual[101];
    for(i = 0; i <= size; i++)
    {
        if(agenda[i].telefone[0] == ddd[0] && agenda[i].telefone[1] == ddd[1] && agenda[i].telefone[2] == ddd[2])
        {
            
            dddIgual[count] = agenda[i];
            count++;
        }
    }
    printf("Existem %d contados com esse DDD\n", count);
    for(i = 0; i < count; i++)
    {
        Imprimir(dddIgual[i]);
    }
}

// Função para encher o array de contatos com outros arrays já predeterminados
contato  Fill(contato novoC, int i)
{
    char nomes[20][20] = {"Ana Prestes" , "Marcelo da Silva", "Catia Honda", "Julia Amorin",
    "Andre Carvalho", "Marcos Martins", "Helena Seixas" ,  "Matheus Cont", "Maria Lopes", "Leticia da Silva", "Luciana de Abreu",
    "Edivane Marvelo", "Cleiton Carmim", "Cecilia Guimarães" , "Eleanor Teixeira" , "Barbara Amim" , "Jean Ragvandir", 
    "Gilnei Ferreira", "Reinaldo Davlin" , "Silvana Roxa" };
    char emails[20][20] = {"ana@prestes.COM" , "marcelo@silva.COM" , "catia@honda.COM", "julia@amorin.COM" , "andre@carvalho.COM" ,
    "marcos@Martins.COM" , "helena@seixas.COM" , "matheus@cont.COM" ,  "maria@lopes.COM", "leticia@silva.COM" , "luciana@abreu.COM",
    "edivane@marvelo.COM" , "cleiton@carmim.COM" , "cecilia@guimaraes.COM" , "eleanor@teixeira.COM" , "barbara@amim.COM" ,
    "jean@ragvandir.COM" , "gilnei@ferreira.COM" , "reinaldo@davlin.COM" , "silvana@roxa.COM"};
    char telefones[20][20] = {"0123456789098" , "012345642476" , "0237413562471" , "098765432123" , "0742389075246" , "098752356421",
    "023456789098" , "012521468942" , "0654212441232" , "075412864325" ,"098765432165" , "064215675327" , "01376543213" , "014765432112",
    "015876543212" , "016234568234" , "017976432134" , "01864214325" , "019325797543" ,"020864321675"};
    int dias[20] = { 01, 02, 02, 03, 04, 05, 06, 20, 15, 28, 30, 12, 22, 17, 14 , 05, 21, 04, 05, 30};
    int meses[20] = { 01, 02, 02, 03, 04, 05, 06, 10, 12, 02, 10, 12, 12, 11, 10 , 05, 11, 04, 05, 01};
    int anos[20] = {2001, 1902, 2002, 1923, 2004, 1985, 1946, 2020, 2015, 1928, 1930, 2012, 1962, 2017, 1994 , 2005, 1949, 2004, 2005, 1930};
    
    strcpy(novoC.nome , nomes[i]);
    strcpy(novoC.email , emails[i]);
    strcpy(novoC.telefone , telefones[i]);
    novoC.dataN.dia = dias[i];
    novoC.dataN.mes = meses[i];
    novoC.dataN.ano = anos[i];
    
    return novoC;
    
}

//Função para buscar contatos baseado no telefone
void Busca (char busca[] , contato novo[], int size)
{  
    
    int isEqual =1,  count = 0,  i=0;
    contato temp[100];
    
    for(i = 0; i <= size; i++)
    {   isEqual = strcmp (busca , novo[i].telefone);
       if( isEqual == 0)
       {
           
           temp[count] = novo[i];
           count++;
       }
    }
    printf("Existem %d contatos com esse número: \n", count);
    for(i = 0; i<count; i++)
    {
        Imprimir(temp[i]);
    }
}

int main()
{
    contato novo[100];
    char ddd[4] , busca[13];
    int menu=0, control=0, count=0, i=0 , size=0;;
    //loop que enche o array inicial
    for(size = 0; size < 20; size++)
    {
        novo[size] = Fill(novo[size] , size);
         
    
    }
    
    //Menu que controla a interface inicial
    do
    {   printf("\n");
        printf("MENU\n");
        printf("1 - Cadastrar \n2 - Ordem Alfabética \n3 - DDD Check \n4 - Imprimir \n5 - Busca por telefone \n0 - SAIR\n");
        scanf("%d", &menu);
        getchar();
        switch (menu)
        {
            case 1 :
                printf("Quantos contados você quer cadastrar? \n");
                scanf("%d", &count);
                getchar();
                count = size + count;
                for(i = size; i <count; i++)
                {
                  novo[i] = Cadastro(novo[i]);
                   size++;
                }
                break;
                
            case 2 :
                OrdemAlfabetica(novo , size);
                break;
                
            case 3 :
                printf("Digite o DDD: ");
                gets(ddd);
                DDDCheck(ddd, novo, size);
                break;
                
            case 4 :
                for(i = 0; i <size; i++)
               {
                 Imprimir(novo[i]);
               }
               break;
               
            case 5 :
                do
                {   
                    printf("Digite o telefone que quer buscar: ");
                    gets(busca);
                }while(ValidarTelefone(busca) == 0);
                Busca(busca , novo , size);
                break;
                
            default :
                control = 1;
                break;
        }
    }while(control != 1);
  
    return 0;
}





