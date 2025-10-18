#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[], char *envp[]) {

	char *args[] = { "/bin/ls", "-la", NULL };

	execve("/bin/ls", args, envp);

	/* execve only returns on error */
	perror("execve");
	printf("Cheguei aqui\n");

	return EXIT_FAILURE;
}
