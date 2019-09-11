#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
/*
int contador;

void load_firefox(char *url[]){
	//int status;
        pid_t p = fork();                                       
        if (p < 0) {                                            
                fprintf(stderr, "Falha na criação do novo processo! \n");
                exit(13);                                       
        } else if (p == 0) {                                    
                printf("Filho iniciando %s... \n", url[contador]); 
                execlp("firefox","firefox --new-window", url[contador], NULL);                  
                printf("Filho com parada de execução forçada! \n"); 
                exit(14);
        } else {       
                printf("Pai esperando... \n"); 
		//wait(&status);
		sleep(5);
		if(--contador>0) load_firefox(url);
                printf("Pai finalizando... \n"); 
                exit(0);
        }
}

void start_browser(char *url[]){
        load_firefox(url);
}
 */




int main(int argc, char *argv[]){
		printf("<<<< Applications Menu >>>\n"
		       "\t1) Web Browser \t\t(executando, pid=1234)\n"
		       "\t2) Text Editor \t\t(executando, pid=3456)\n"
		       "\t3) Terminal \t(falhou)\n"
		       "\t4) Finalizar processo \t(concluído)\n"
		       "\t5) Quit\n"
		"Opção: ");
		bool whileTaRolando = true;
		int entradaDoUsuario;
		//pid_t p = fork();
		while (whileTaRolando){
			scanf("%d", &entradaDoUsuario);
			//sleep(1);	
			printf("%d", entradaDoUsuario);
			printf("\n");
			
			switch(entradaDoUsuario){
			case(1) :
				printf("Abre Firefox");
				break;
			case(2) :
				printf("Abre texto");

				pid_t p = fork();                                       
        			if (p < 0) {                                            
                			fprintf(stderr, "Falha na criação do novo processo! \n");
                			exit(13);                                       
        			} 
				else if (p == 0) {                                    
                			printf("Filho iniciando... \n"); 
					execlp("gedit", "gedit", NULL);	                
					printf("Filho com parada de execução forçada! \n"); 
					exit(14);
				}





		
				break;
			case(3) :
				printf("Abre terminal");
				break; 	
			case(4) :
				printf("Finalizar processo");
				break; 	
			default :
				whileTaRolando = false;
				break; 	
			}
		}
	
return 0;
}

