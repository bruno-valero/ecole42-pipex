/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:16:03 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/19 14:30:32 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char				**get_path(char **envp);
static t_command_array	build_commands(char **commands_str, char **paths);

t_env	create_env(char *infile, char *outfile, char **commands, char **envp)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	env.self_ref = &env;
	env.infile = infile;
	env.outfile = outfile;
	env.paths = get_path(envp);
	env.commands = build_commands(commands, env.paths);
	return (env);
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

static t_command_array	build_commands(char **command_str, char **paths)
{
	int				len;
	t_command_array	commands;

	len = 0;
	while (command_str[len])
		len++;
	commands.length = len;
	commands.commands = malloc(len * sizeof(t_command));
	len = -1;
	while (command_str[++len])
		commands.commands[len] = create_command(command_str[len], paths);
	return (commands);
}

void	*destroy_env(t_env env)
{
	int	command_len;

	ft_destroy_char_matrix(&env.paths);
	command_len = -1;
	while (++command_len < env.commands.length)
		destroy_command(env.commands.commands[command_len]);
	free(env.commands.commands);
	return (NULL);
}
