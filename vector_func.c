/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:46:59 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/16 23:56:59 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector		create_vector(float x, float y, float z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector		add_vector(t_vector vector1, t_vector vector2)
{
	return (create_vector(vector1.x + vector2.x, vector1.y +
				vector2.y, vector1.z + vector2.z));
}

t_vector		normal_vector(t_vector vector)
{
	float		len;

	len = (sqrtf(vector.x * vector.x + vector.y *
				vector.y + vector.z * vector.z));
	if (len != 0)
	{
		len = 1.0f / len;
		vector.x *= len;
		vector.y *= len;
		vector.z *= len;
	}
	return (create_vector(vector.x, vector.y, vector.z));
}

t_vector		minus_vector(t_vector vector1, t_vector vector2)
{
	return (create_vector(vector1.x - vector2.x, vector1.y -
				vector2.y, vector1.z - vector2.z));
}

float			get_dot(t_vector vector1, t_vector vector2)
{
	return (vector1.x * vector2.x + vector1.y *
			vector2.y + vector1.z * vector2.z);
}
