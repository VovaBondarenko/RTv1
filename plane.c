/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:14:05 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 00:15:18 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_plane			*create_plane(t_vector center, t_vector normal, t_color color)
{
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
		close_app("Plane is not created", 0);
	plane->center = center;
	plane->normal = normal;
	plane->color = color;
	return (plane);
}

void			check_plane_intersection(t_scene *scene,
		t_plane *plane, t_raytrace ray)
{
	float		light_dist;
	t_vector	tmp;
	int			check;

	plane->normal = normal_vector(plane->normal);
	light_dist = get_dot(ray.dir, plane->normal);
	scene->intersection = (light_dist == 0) ? 0 : 1;
	if (scene->intersection == 0)
		return ;
	scene->intersection = 1;
	tmp = minus_vector(ray.pos, plane->center);
	light_dist = -get_dot(tmp, plane->normal) / get_dot(ray.dir, plane->normal);
	check = (light_dist > 0.001 && light_dist < scene->t) ? 1 : 0;
	scene->t = (check) ? light_dist - 0.1 : scene->t;
	if ((scene->t > scene->light_dist) || !check)
		scene->intersection = 0;
	if (scene->intersection == 1 && scene->need_color == 1)
		scene->closest_obj_color = plane->color;
}

void			calc_plane_normal(t_scene *scene, t_plane *plane)
{
	plane->normal = normal_vector(plane->normal);
	scene->closest_obj->normal = normal_vector(plane->normal);
}
