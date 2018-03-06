/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fong_shadow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:09:54 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 00:11:06 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			fong_shadow(t_scene *scene,
		t_light *light_list, t_vector normal)
{
	t_vector	len;
	float		cos;
	float		tmp;

	scene->fong_shadow = (t_color){0, 0, 0};
	len = add_vector(minus_vector(light_list->center,
				scene->light.pos),
			minus_vector(scene->camera->pos, scene->light.pos));
	cos = get_dot(normal_vector(len), normal);
	if (cos > 0)
	{
		tmp = pow(cos, light_list->intensive);
		scene->fong_shadow.r = tmp * light_list->color.r;
		scene->fong_shadow.g = tmp * light_list->color.g;
		scene->fong_shadow.b = tmp * light_list->color.b;
	}
}
