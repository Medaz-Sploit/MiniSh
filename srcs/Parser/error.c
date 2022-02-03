/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:01:44 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/02 22:08:38 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void exit_error(int e)
{
	if (e == 0)
		printf("Error:\n\t Exit Successfuly\n");
	else if (e > 2 && e < 10)
		printf("Error:\n\t Malloc FAILED\n");
	else
		printf("Error\n");
}

void	log_error(char *s)
{
	ft_putstr_fd(s, 1);
	g_parser->exit_status = 258;
	g_parser->syntax_check = 1;
}