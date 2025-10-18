/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:42:56 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/18 19:44:43 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <unistd.h>
# include "libft.h"

typedef struct s_command	t_command;
struct s_command
{
	t_command	*self_ref;
	char		**full_command;
	char		*command_path;
};

t_command	create_command(char	*command_str, char	**paths);
void		*destroy_command(t_command command);

#endif
