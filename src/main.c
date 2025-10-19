/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:09:36 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/19 15:13:29 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_commands(int argc, char **argv);
static int	error(int error);
static void	verify_files(int *valid_files, char *infile, char *outfile);
static void	verify_commands(t_env env);

int	main(int argc, char **argv, char **envp)
{
	t_env	env;
	int		fd_pipe[2];
	int		fd_files[2];
	int		pid;
	char	**commands;

	if (argc < 5)
		return (error(1));
	commands = get_commands(argc, argv);
	env = create_env(argv[1], argv[argc - 1], commands, envp);
	verify_files(env.valid_files, env.infile, env.outfile);
	verify_commands(env);
	ft_destroy_char_matrix(&commands);
	pipe(fd_pipe);
	if (env.valid_files[0] && env.commands.commands[0].command_path)
	{
		pid = fork();
		if (!pid)
			child_process(env, fd_files, fd_pipe, envp);
	}
	father_process(env, fd_files, fd_pipe, envp);
	destroy_env(env);
}

static char	**get_commands(int argc, char **argv)
{
	int		len;
	int		len_arg;
	char	**commands;

	len = 0;
	while (len + 2 < argc - 1)
		len++;
	commands = ft_calloc((len + 1), sizeof(char *));
	if (!commands)
		return (NULL);
	len = 1;
	while (++len < argc - 1)
	{
		len_arg = ft_strlen(argv[len]);
		commands[len - 2] = ft_calloc((len_arg + 1), sizeof(char));
		if (!commands[len - 2])
			return (ft_destroy_char_matrix(&commands));
		ft_strlcpy(commands[len - 2], argv[len], len_arg + 1);
	}
	return (commands);
}

static int	error(int error)
{
	return (error);
}

static void	verify_files(int *valid_files, char *infile, char *outfile)
{
	int	fd_files[2];

	fd_files[0] = open(infile, O_RDONLY);
	fd_files[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_files[0] > -1)
		valid_files[0] = 1;
	if (fd_files[1] > -1)
		valid_files[1] = 1;
	close(fd_files[0]);
	close(fd_files[1]);
	if (!valid_files[0])
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putstr_fd(infile, 2);
		ft_putstr_fd("\n", 2);
	}
	if (!valid_files[1])
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putstr_fd(outfile, 2);
		ft_putstr_fd("\n", 2);
	}
}

static void	verify_commands(t_env env)
{
	int	i;

	i = -1;
	while (++i < env.commands.length)
	{
		if (!env.commands.commands[i].command_path)
		{
			if (!i && env.valid_files[0])
			{
				ft_putstr_fd("command not found: ", 2);
				ft_putstr_fd(env.commands.commands[i].full_command[0], 2);
				ft_putstr_fd("\n", 2);
			}
		}
	}
}
