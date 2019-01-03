#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int dobro(int num){
	return (2 * num);
}

int quadrado(int num){
	return (num * num);
}

void main(){
	int i;
	printf("Essa regiao será executada por ambos os processos\n\n");
	printf("I = ");
	scanf("%d", &i);
	pid_t pid;
	if((pid = fork()) < 0){
		perror("Erro no fork()!\a\n");
		exit(1);
	}
	if(pid == 0){
		printf("\nExecutando o processo filho\n");
		printf("Pid do Filho: %d\n", getpid());
		i = dobro(i);
		printf("Dobro(i) = %d\n", i);
	}else{
		printf("\nExecutando o processo pai\n");
		printf("Pid do Pai: %d\n", getpid());
		i = quadrado(i);
		printf("Quadrado(i) = %d\n", i);
	}
	exit(0);
}
