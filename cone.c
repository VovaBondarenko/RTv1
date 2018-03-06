/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:09:13 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 15:11:05 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cone			*create_cone(t_vector center,
		t_vector normal, t_color color, float angle)
{
	t_cone		*cone;

	cone = malloc(sizeof(t_cone));
	if (cone == NULL)
		close_app("Cone is not created", 0);
	cone->center = center;
	cone->normal = normal;
	cone->color = color;
	cone->angle = angle * ANGLE_DEF;
	return (cone);
}

void			check_cone_intersection(t_scene *scene,
		t_cone *cone, t_raytrace ray)
{
	float		a;
	float		b;
	float		c;
	float		tan;
	t_vector	tmp;

	cone->normal = normal_vector(cone->normal);
	tan = tanf(cone->angle);
	tmp = minus_vector(ray.pos, cone->center);
	a = get_dot(ray.dir, ray.dir) - (pow(tan, 2) + 1) *
		pow(get_dot(ray.dir, cone->normal), 2);
	b = 2 * (get_dot(ray.dir, tmp) - (pow(tan, 2) + 1)
		* get_dot(ray.dir, cone->normal)
		* get_dot(tmp, cone->normal));
	c = get_dot(tmp, tmp) - (pow(tan, 2) + 1) *
		pow(get_dot(tmp, cone->normal), 2);
	check_disc_intersection(scene, a, b, c);
	if (scene->intersection == 1 && scene->need_color == 1)
		scene->closest_obj_color = cone->color;
}

void			calc_cone_normal(t_scene *scene,
		t_cone *cone, t_vector ray_light)
{
	float		len;
	float		tan;
	t_vector	tmp;

	cone->normal = normal_vector(cone->normal);
	tan = tanf(cone->angle);
	len = get_dot(cone->normal, scene->ray.dir) * scene->t +
		get_dot(cone->normal, minus_vector(scene->ray.pos, cone->center));
	tmp = minus_vector(ray_light, cone->center);
	scene->closest_obj->normal = normal_vector(minus_vector(tmp,
				mult_vector(cone->normal, len * (pow(tan, 2) + 1))));
}
