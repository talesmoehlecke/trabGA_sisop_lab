#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

int contador;

int openFirefox(char *url)
{
	//int status;
	pid_t p = fork();
	if (p < 0)
	{
		fprintf(stderr, "Falha na criação do novo processo! \n");
		exit(13);
	}
	else if (p == 0)
	{
		printf("Filho iniciando %s... \n", url);
		execlp("firefox", "firefox --new-window", url, NULL);
		printf("Filho com parada de execução forçada! \n");
		exit(14);
	}
	else
	{
		return p;
	}
}

int openGedit()
{
	printf("Abre editor de texto");
	fflush(stdout); //força a saida de todas as saidas na fila do buffer
	pid_t p = fork();
	if (p < 0)
	{
		fprintf(stderr, "Falha na criação do novo processo! \n");
		exit(13);
	}
	else if (p == 0)
	{
		printf("Filho iniciando...  pid =  %d", (int)getpid());
		fflush(stdout); //força as saida de todas as saidas no buffer pq o exec limpa o buffer e impede o print
		execlp("gedit", "gedit", NULL);
		//pid2 = getpid();
		//dar um kill no pid impresso encerra o gedit
		printf("Filho com parada de execução forçada! \n");
		exit(14);
	}
	else
	{
		return p; //executa no pai
	}
}

int main(int argc, char *argv[])
{
	char bufferDeLeituras[20];
	char bufferDeURLLeitura[150];
	printf("<<<< Applications Menu >>>\n"
		   "\t1) Web Browsers \t\t(executando, pid=1234)\n"
		   "\t2) Text Editor \t\t(executando, pid=,/*pid2*/)\n"
		   "\t3) Terminal \t\t(falhou)\n"
		   "\t4) Finalizar processo \t(concluído)\n"
		   "\t5) Quit\n"
		   "Opção: ");
	bool whileTaRolando = true;
	int entradaDoUsuario;
	int pidGedit;
	int pidFirefox;
	char *url;
	while (whileTaRolando)
	{
		fgets(bufferDeLeituras, 20, stdin);
		sscanf(bufferDeLeituras, "%d", &entradaDoUsuario);

		printf("%d", entradaDoUsuario);
		printf("\n");

		switch (entradaDoUsuario)
		{
		case (1):
			printf("Insira uma URL:");
			fgets(bufferDeLeituras, 150, stdin);
			sscanf(bufferDeLeituras, "%s", &*url);
			pidFirefox = openFirefox(url);
			printf("PId do firefox: %d", pidFirefox);
			break;
		case (2):
			pidGedit = openGedit();
			printf("pid do filho é %d", pidGedit);
			break;
		case (3):
			printf("Abre terminal");
			break;
		case (4):
			printf("Finalizar processo");
			break;
		default:
			whileTaRolando = false;
			break;
		}
	}

	return 0;
}
