/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:08:29 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/19 14:09:44 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "env.h"
# include <fcntl.h>

void	child_process(t_env env, int fd_files[2], int fd_pipe[2], char **envp);
void	father_process(t_env env, int fd_files[2], int fd_pipe[2], char **envp);

#endif
