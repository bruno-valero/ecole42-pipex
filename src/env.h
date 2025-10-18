/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:16:03 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/18 19:38:52 by brunofer         ###   ########.fr       */
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
	t_command_array	*commands;
	char			**paths;
};

#endif
