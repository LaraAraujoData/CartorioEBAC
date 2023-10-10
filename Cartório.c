#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro () //Fun��o respons�vel por cadastrar os usu�rios no sistema
{	
		//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
		//final da cria��o de vari�veis
	
	printf("\nDigite o CPF a ser cadastrado:\n"); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //s porqu� se trata de uma string
	
	strcpy(arquivo,cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o w = a write
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //vari�vel a = att
	fprintf(file, ",");
	fclose(file);
	
	printf("\nDigite o nome a ser cadastrado:\n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("\nDigite o sobrenome a ser cadastrado:\n");
	scanf("%s",sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("\nDigite o cargo a ser cadastrado:\n");
	scanf("%s",cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}


int consultar ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado:\n\n");
	scanf("%s",cpf); //s por ser uma string
	
	FILE *file;
	file = fopen(cpf,"r"); //r = read
	
	if(file == NULL)
	{
		printf ("\nN�o foi poss�vel abrir o arquivo, CPF n�o localizado.\n\n");
		
	}
	
	while (fgets(conteudo, 200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");
		printf("%s", conteudo);
		printf("\n\n");
	
	}
	
	system("pause");
	
}

int deletar ()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; //em caixa alta para entrar no campo biblioteca e em caixa baixa para efetivamente acessar arquuivos
	file = fopen (cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main ()
{
	int opcao=0; //Definindo vari�veis 
	int x=1;
	
	for (x=1;x=1;)
	{
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do Menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes \n\n"); 
		printf("Op��o:");//Final do Menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio, por ser uma var�vel do tipo inteiro � d
	
		system("cls"); //respons�vel por limpar a tela 
		
		switch (opcao)
		{
			case 1:
			registro (); //chamada de fun��es
			break;
			
			case 2:
			consultar ();
			break;
			
			case 3:
			deletar ();
			break;
			
			default:
			printf ("Essa op��o n�o est� dispon�vel\n\n");
			system ("pause");
			break;
		} //fim da sele��o
	
		
}
	printf("Esse Sofwtare foi feito em aula - por Lara A.\n");
}
