#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
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
	
	system("pause"); //responsável por pausar a tela para leitura do usuário
	
}
 
int consulta() //função responsável pela consulta de usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definição da linguagem
	
	char cpf[40];
	char conteudo[40];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //cenário de erro
	{
		printf("\nNão foi possível abrir o arquivo, CPF não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}

int deletar() //função responsável por deletar os usuários do sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //responsável por apagar o arquivo referenciado -cpf-
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" refere-se a leitura/consulta do arquivo
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");;
		system("pause");
	}
	
}

int main() //função princípal e de menu do usuário
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definição da linguagem
	
		printf("### Cartório da EBAC ### \n\n"); //início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao) //início da seleção
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
			printf("Essa opcão não está disponível\n!");
			system("pause");
			break; //fim da seleção
		}
	
	}
}
