#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {


	int fd_in = open("arquivo1", O_RDONLY);
	int fd_out = open("arquivo2", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	// printf("Escrevendo\n");

	// int	old_fd_term = dup(1);

	dup2(fd_in, 0);
	dup2(fd_out, 1);

	printf("Escrevendo\n");
	fflush(stdout);

	write(1, "Batata\n", 8);

	// dup2(old_fd_term, 1);

	write(1, "Batata\n", 8);
}
