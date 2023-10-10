#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro () //Função responsável por cadastrar os usuários no sistema
{	
		//início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
		//final da criação de variáveis
	
	printf("\nDigite o CPF a ser cadastrado:\n"); //Coletando informações do usuário
	scanf("%s", cpf); //s porquê se trata de uma string
	
	strcpy(arquivo,cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o w = a write
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //variável a = att
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
		printf ("\nNão foi possível abrir o arquivo, CPF não localizado.\n\n");
		
	}
	
	while (fgets(conteudo, 200,file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n");
		printf("%s", conteudo);
		printf("\n\n");
	
	}
	
	system("pause");
	
}

int deletar ()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja deletar:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; //em caixa alta para entrar no campo biblioteca e em caixa baixa para efetivamente acessar arquuivos
	file = fopen (cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main ()
{
	int opcao=0; //Definindo variáveis 
	int x=1;
	
	for (x=1;x=1;)
	{
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

		printf("### Cartório da EBAC ###\n\n"); //início do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes \n\n"); 
		printf("Opção:");//Final do Menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário, por ser uma varável do tipo inteiro é d
	
		system("cls"); //responsável por limpar a tela 
		
		switch (opcao)
		{
			case 1:
			registro (); //chamada de funções
			break;
			
			case 2:
			consultar ();
			break;
			
			case 3:
			deletar ();
			break;
			
			default:
			printf ("Essa opção não está disponível\n\n");
			system ("pause");
			break;
		} //fim da seleção
	
		
}
	printf("Esse Sofwtare foi feito em aula - por Lara A.\n");
}
