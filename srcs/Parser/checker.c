/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 23:15:19 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/02 23:20:26 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_spaceskip(char *line, int *i)
{
	if (line == NULL)
		return (0);
	while (line && ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
			|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f')))
		(*i)++;
	return (1);
}