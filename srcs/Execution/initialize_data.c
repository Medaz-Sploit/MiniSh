/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:15:32 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/05 11:01:30 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_parser	*initialize_data(t_parser *parser)
{
	parser = ft_calloc(1, sizeof(t_parser));
	if (!parser)
		return (0);
}