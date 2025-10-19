/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:44:36 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/19 14:40:14 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

static char	*get_command_path(char *command, char **paths);
static char	**build_command(char *command);

t_command	create_command(char	*command_str, char	**paths)
{
	t_command	command;

	command.self_ref = &command;
	command.full_command = build_command(command_str);
	if (!command.full_command[0])
	{
		ft_destroy_char_matrix(&command.full_command);
		command.full_command = NULL;
	}
	if (command.full_command)
		command.command_path = get_command_path(command.full_command[0], paths);
	else
		command.command_path = NULL;
	return (command);
}

static char	*get_command_path(char *command, char **paths)
{
	int		env;
	char	*command_concat_temp;
	char	*command_concat;

	env = -1;
	while (paths[++env])
	{
		command_concat_temp = ft_strjoin(paths[env], "/");
		command_concat = ft_strjoin(command_concat_temp, command);
		if (command_concat_temp)
		{
			free(command_concat_temp);
			command_concat_temp = NULL;
		}
		if (!access(command_concat, F_OK | X_OK))
			return (command_concat);
		if (command_concat)
		{
			free(command_concat);
			command_concat = NULL;
		}
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

void	*destroy_command(t_command command)
{
	ft_destroy_char_matrix(&command.full_command);
	free(command.command_path);
	return (NULL);
}
