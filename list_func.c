/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:04:55 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 00:06:14 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_list_obj		*create_node_obj(void *obj, int type)
{
	t_list_obj	*node;

	node = (t_list_obj *)malloc(sizeof(t_list_obj));
	node->obj = obj;
	node->type = type;
	node->next = NULL;
	return (node);
}

void			add_node_obj(t_list_obj **head, t_list_obj *node)
{
	t_list_obj	*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		*head = node;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

void			add_node_light(t_light **head, t_light *node)
{
	t_light		*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		*head = node;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}
