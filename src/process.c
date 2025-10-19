/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:08:15 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/19 15:21:02 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	child_process(t_env env, int fd_files[2], int fd_pipe[2], char **envp)
{
	fd_files[0] = open(env.infile, O_RDONLY);
	dup2(fd_files[0], 0);
	close(fd_files[0]);
	dup2(fd_pipe[1], 1);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	execve(
		env.commands.commands[0].command_path,
		env.commands.commands[0].full_command,
		envp);
}

void	father_process(t_env env, int fd_files[2], int fd_pipe[2], char **envp)
{
	fd_files[1] = open(env.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd_files[1], 1);
	close(fd_files[1]);
	dup2(fd_pipe[0], 0);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	if (env.commands.commands[1].command_path)
		execve(
			env.commands.commands[1].command_path,
			env.commands.commands[1].full_command,
			envp);
	else
		write(1, "\0", 1);
}
