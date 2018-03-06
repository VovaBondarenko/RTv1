/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:01:50 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 00:04:01 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			get_lambert(t_scene *scene,
		t_light *light_list, t_vector normal)
{
	t_vector	tmp;
	t_vector	dir;
	float		cos;

	tmp = minus_vector(light_list->center, scene->light.pos);
	dir = normal_vector(tmp);
	cos = get_dot(dir, normal);
	scene->lambert = (cos > 0) ? cos : 0;
}

void			calc_light(t_scene *scene, t_light *light_list)
{
	t_vector	normal;
	float		cos;

	normal = scene->closest_obj->normal;
	if (scene->closest_obj->type == PLANE)
	{
		cos = get_dot(normal, scene->light.dir);
		if (!(cos >= 0))
			normal = mult_vector(normal, -1);
	}
	get_lambert(scene, light_list, normal);
	fong_shadow(scene, light_list, normal);
	scene->final_color.r += scene->closest_obj_color.r *
		(scene->lambert) + scene->fong_shadow.r;
	scene->final_color.g += scene->closest_obj_color.g *
		(scene->lambert) + scene->fong_shadow.g;
	scene->final_color.b += scene->closest_obj_color.b *
		(scene->lambert) + scene->fong_shadow.b;
}
