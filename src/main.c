/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:09:36 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/19 10:00:03 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_commands(int argc, char **argv);
static int	error(int error);

int	main(int argc, char **argv, char **envp)
{
	t_env	env;
	char	**commands;

	if (argc < 5)
		return (error(1));
	commands = get_commands(argc, argv);
	env = create_env(argv[1], argv[argc - 1], commands, envp);
	ft_destroy_char_matrix(&commands);
	printf("command1: %s\ncommand2: %s\n", env.commands.commands[0].command_path, env.commands.commands[1].command_path);
	// command_path = get_command_path(command[0], path);
	// // printf("%s\n", command_path);
	// execve(command_path, command, envp);
	// free(command_path);
	// ft_destroy_char_matrix(&path);
	// ft_destroy_char_matrix(&command);
}

static char	**get_commands(int argc, char **argv)
{
	int		len;
	int		len_arg;
	char	**commands;

	len = 0;
	while (len + 2 < argc -2)
		len++;
	commands = malloc((len + 1) * sizeof(char *));
	if (!commands)
		return (NULL);
	len = 1;
	while (++len < argc -2)
	{
		len_arg = ft_strlen(argv[len]);
		commands[len - 2] = malloc((len_arg + 1) * sizeof(char));
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
