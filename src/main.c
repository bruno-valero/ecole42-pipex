/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:09:36 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/18 18:23:01 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path(char **envp);
static int	error(int error);
static char	**build_command(char *command);
static char	*get_command_path(char *command, char **path);

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	char	**command;
	char	*command_path;
	t_env	env;

	(void)argc;
	if (!argv[1])
		return (error(1));
	env.full_command = build_command(argv[1]);

	if (!env.full_command[0])
		return (error(1));
	path = get_path(envp);
	if (!path)
	{
		ft_destroy_char_matrix(&env.full_command);
		return (error(1));
	}
	command_path = get_command_path(command[0], path);
	// printf("%s\n", command_path);
	execve(command_path, command, envp);
	free(command_path);
	ft_destroy_char_matrix(&path);
	ft_destroy_char_matrix(&command);
}

static char	**get_path(char **envp)
{
	int		env;
	char	*path;
	char	**path_splitted;

	env = -1;
	path = NULL;
	while (envp[++env])
	{
		if (!ft_strncmp("PATH=", envp[env], 5))
		{
			path = envp[env] + 5;
			break ;
		}
	}
	if (!path)
		return (NULL);
	path_splitted = ft_split(path, ':');
	if (!path_splitted[0])
		return (ft_destroy_char_matrix(&path_splitted));
	return (path_splitted);
}

static char	*get_command_path(char *command, char **path)
{
	int		env;
	char	*command_concat_temp;
	char	*command_concat;

	env = -1;
	while (path[++env])
	{
		command_concat_temp = ft_strjoin(path[env], "/");
		command_concat = ft_strjoin(command_concat_temp, command);
		free(command_concat_temp);
		if (!access(command_concat, F_OK | X_OK))
			return (command_concat);
		free(command_concat);
	}
	free(command_concat);
	return (NULL);
}

static char	**build_command(char *command)
{
	char	**splitted_command;

	splitted_command = ft_split(command, ' ');
	return (splitted_command);
}

static int	error(int error)
{
	return (error);
}
