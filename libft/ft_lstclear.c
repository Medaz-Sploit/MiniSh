/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:17:48 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/05 12:17:52 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*help;
	t_list	*str;

	str = *lst;
	while (str)
	{
		if (str->next)
			help = str->next;
		else
			help = NULL;
		del(str->content);
		free(str);
		str = help;
	}
	(*lst) = NULL;
}