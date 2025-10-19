/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:16:03 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/19 13:57:06 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "command.h"
# include "libft.h"

typedef struct s_command_array		t_command_array;
struct s_command_array
{
	int			length;
	t_command	*commands;
};

typedef struct s_env				t_env;
struct s_env
{
	t_env			*self_ref;
	char			*infile;
	char			*outfile;
	int				valid_files[2];
	t_command_array	commands;
	char			**paths;
};

t_env	create_env(char *infile, char *outfile, char **commands, char **envp);
void	*destroy_env(t_env env);

#endif
