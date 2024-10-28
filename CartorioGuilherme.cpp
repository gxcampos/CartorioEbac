#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e "w" refere-se a escrita desse novo arquivo
	fprintf(file,cpf); //salva o arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" refere-se a atualizar o arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	system("pause"); //respons�vel por pausar a tela para leitura do usu�rio
	
}
 
int consulta() //fun��o respons�vel pela consulta de usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //defini��o da linguagem
	
	char cpf[40];
	char conteudo[40];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //cen�rio de erro
	{
		printf("\nN�o foi poss�vel abrir o arquivo, CPF n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}

int deletar() //fun��o respons�vel por deletar os usu�rios do sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //respons�vel por apagar o arquivo referenciado -cpf-
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" refere-se a leitura/consulta do arquivo
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");;
		system("pause");
	}
	
}

int main() //fun��o princ�pal e de menu do usu�rio
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //defini��o da linguagem
	
		printf("### Cart�rio da EBAC ### \n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao) //in�cio da sele��o
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por usar o sistema!");
			return 0;
			break;
			
			default:
			printf("Essa opc�o n�o est� dispon�vel\n!");
			system("pause");
			break; //fim da sele��o
		}
	
	}
}
