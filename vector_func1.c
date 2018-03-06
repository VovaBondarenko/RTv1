/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:46:06 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/16 23:46:27 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	mult_vector(t_vector vector1, float dot)
{
	return (create_vector(vector1.x * dot, vector1.y * dot, vector1.z * dot));
}
