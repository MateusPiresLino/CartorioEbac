#include <stdio.h> //Biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��es 
	{
		
		char arquivo[40]; // colchetes define uma string
		char cpf[40]; 
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquino "w"
		fprintf(file,cpf); //salvando o valor da variavel 
		fclose(file); // fecha o arquivo
		
		file = fopen(arquivo, "a"); // Definindo o comando acrecentar/append algo dentro do arquivo "a"
		fprintf(file, ","); // acrecentando a instru��o dentro do arquivo "," para separar as informa��es.
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a"); // a partir desta etapa o file ja foi criado, logo s� � necess�rio acrescentar 
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digete o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause"); //comando para manter a mensagem 
		
	}
	
int consulta() // Fun��o
	{
		
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];
		char conteudo[200];
		
		printf("digite o CPF a ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
				
		if(file == NULL)
		{
			printf("\nUsu�rio n�o localizado!\n\n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
	}
	
int deletar() // Fun��o
	{
		char cpf[40]; //O char em n�meros para gerenciamento de string funciona melhor
		
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s",cpf);
		
		
		
		FILE *file;
		file = fopen(cpf, "r");
		fclose(file);
		
		if(file == NULL)
		{
			printf("\nUsu�rio n�o localizado! \n");
			
		} 
		else 
		{
			remove(cpf);
			printf("\nUsu�rio deletado com sucesso! \n");	
		}
		
		system("pause");
		
	}

int main() // Fun��o
	{
	int opcao=0; //definindo vari�veis 
	int laco=1;
	
	for(laco=1;laco=1;) //comando para fazer o la�o/loop
	{
		
		system("cls"); //comando para limpar tudo que estiver acima dele, deixando a tela menos poluida
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando vari�vel na op��o do usu�rio
		
		 system("cls");
		
		switch(opcao)
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
			
			default:
			printf("Essa op��o n�o esta dispon�vel\n");
			system("pause");
			break;	
				
		}
	}
}