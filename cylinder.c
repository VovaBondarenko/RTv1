/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:06:36 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 15:08:47 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cylinder		*create_cylinder(t_vector center,
		t_vector normal, float radius, t_color color)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		close_app("Cylinder is not created", 0);
	cylinder->center = center;
	cylinder->normal = normal;
	cylinder->radius = radius;
	cylinder->color = color;
	return (cylinder);
}

void			check_cylinder_intersection(t_scene *scene,
		t_cylinder *cylinder, t_raytrace ray)
{
	float		a;
	float		b;
	float		c;
	t_vector	len;

	cylinder->normal = normal_vector(cylinder->normal);
	len = minus_vector(ray.pos, cylinder->center);
	a = get_dot(ray.dir, ray.dir)
		- get_dot(ray.dir, cylinder->normal) *
		get_dot(ray.dir, cylinder->normal);
	b = 2 * (get_dot(ray.dir, len) -
		get_dot(ray.dir, cylinder->normal) *
		get_dot(len, cylinder->normal));
	c = get_dot(len, len) -
		get_dot(len, cylinder->normal) *
		get_dot(len, cylinder->normal) -
		pow(cylinder->radius, 2);
	check_disc_intersection(scene, a, b, c);
	if (scene->intersection == 1 && scene->need_color == 1)
		scene->closest_obj_color = cylinder->color;
}

void			calc_cylinder_normal(t_scene *scene,
		t_cylinder *cylinder, t_vector ray_light)
{
	t_vector	normal;
	t_vector	v;
	float		m;

	cylinder->normal = normal_vector(cylinder->normal);
	m = get_dot(cylinder->normal, scene->ray.dir) * scene->t +
		get_dot(cylinder->normal,
				minus_vector(scene->ray.pos, cylinder->center));
	v = minus_vector(ray_light, cylinder->center);
	normal = normal_vector(minus_vector(v, mult_vector(cylinder->normal, m)));
	scene->closest_obj->normal = normal;
}
