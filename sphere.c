/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:11:44 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 15:12:40 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere		*create_sphere(t_vector center,
		t_color color, float radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		close_app("Sphere is not created", 0);
	sphere->center = center;
	sphere->color = color;
	sphere->radius = radius;
	return (sphere);
}

void			check_sphere_intersection(t_scene *scene,
		t_sphere *sphere, t_raytrace ray)
{
	float		a;
	float		b;
	float		c;

	a = get_dot(ray.dir, ray.dir);
	b = 2 * get_dot(ray.dir, minus_vector(ray.pos, sphere->center));
	c = get_dot(
			minus_vector(ray.pos, sphere->center),
			minus_vector(ray.pos, sphere->center)) - pow(sphere->radius, 2);
	check_disc_intersection(scene, a, b, c);
	if (scene->intersection == 1 && scene->need_color == 1)
		scene->closest_obj_color = sphere->color;
}

void			calc_sphere_normal(t_scene *scene, t_sphere *sphere)
{
	scene->closest_obj->normal =
		normal_vector(minus_vector(scene->light.pos, sphere->center));
}
