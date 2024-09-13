#include <stdio.h> //Biblioteca de comunicação com o usuário 
#include <stdlib.h> //Biblioteca de alocação de espaço em memoria
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Funções 
	{
		
		char arquivo[40]; // colchetes define uma string
		char cpf[40]; 
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); //responsável por copiar os valores das string
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquino "w"
		fprintf(file,cpf); //salvando o valor da variavel 
		fclose(file); // fecha o arquivo
		
		file = fopen(arquivo, "a"); // Definindo o comando acrecentar/append algo dentro do arquivo "a"
		fprintf(file, ","); // acrecentando a instrução dentro do arquivo "," para separar as informações.
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a"); // a partir desta etapa o file ja foi criado, logo só é necessário acrescentar 
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
	
int consulta() // Função
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
			printf("\nUsuário não localizado!\n\n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
	}
	
int deletar() // Função
	{
		char cpf[40]; //O char em números para gerenciamento de string funciona melhor
		
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s",cpf);
		
		
		
		FILE *file;
		file = fopen(cpf, "r");
		fclose(file);
		
		if(file == NULL)
		{
			printf("\nUsuário não localizado! \n");
			
		} 
		else 
		{
			remove(cpf);
			printf("\nUsuário deletado com sucesso! \n");	
		}
		
		system("pause");
		
	}

int main() // Função
	{
		int opcao=0; //definindo variáveis 
		int laco=1;
		char senhadigitada[10]="a";
		int comparacao;
		
		printf("### Cartório da EBAC ###\n\n");
		printf("Login de administrador!\n\nDigite a sua senha: ");
		scanf("%s",senhadigitada);
		
		comparacao = strcmp(senhadigitada, "admin");
		
		if(comparacao == 0)
		{
	 		system ("cls");
			for(laco=1;laco=1;) //comando para fazer o laço/loop
			{
			
				system("cls"); //comando para limpar tudo que estiver acima dele, deixando a tela menos poluida
				
				setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
				
				printf("### Cartório da EBAC ###\n\n"); //inicio do menu
				printf("Escolha a opção desejada do menu:\n\n");
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar os nomes\n");
				printf("\t3 - Deletar nomes\n\n");
				printf("\t4 - Sair do sistema\n\n");
				printf("Opção: "); //Fim do menu
				
				scanf("%d", &opcao); //Armazenando variável na opção do usuário
				
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
					
					case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;	
					
					default:
					printf("Essa opção não esta disponível\n");
					system("pause");
					break;	
						
				}
			}
		}
		else
		printf("Senha incorreta!"); 	
	}

	
	
	
