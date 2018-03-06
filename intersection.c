/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:08 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 15:19:07 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			check_disc_intersection(t_scene *scene,
		float a, float b, float c)
{
	float		disc;
	float		dist_x;
	float		dist_y;

	scene->intersection = 0;
	disc = b * b - 4.0f * a * c;
	if (!((disc = b * b - 4.0f * a * c) < 0))
	{
		scene->intersection = 1;
		dist_x = (-b + sqrt(disc)) / (2 * a);
		dist_y = (-b - sqrt(disc)) / (2 * a);
		scene->t = (dist_x > 0.001 && dist_x < scene->t) ? dist_x : scene->t;
		if (dist_y > 0.001 && dist_y < scene->t)
			scene->t = dist_y - 0.1;
		else
			scene->intersection = 0;
		scene->intersection = (scene->t > scene->light_dist)
			? 0 : scene->intersection;
	}
}

void			find_intersection(t_scene *scene, t_raytrace *ray)
{
	t_list_obj	*tmp_obj;

	tmp_obj = scene->obj;
	while (tmp_obj != NULL)
	{
		check_intersection(scene, tmp_obj, ray);
		if (scene->intersection)
			scene->closest_obj = tmp_obj;
		tmp_obj = tmp_obj->next;
	}
}

void			check_intersection(t_scene *scene,
		t_list_obj *obj, t_raytrace *ray)
{
	if (obj->type == CONE)
		check_cone_intersection(scene, (t_cone *)obj->obj, *ray);
	else if (obj->type == PLANE)
		check_plane_intersection(scene, (t_plane *)obj->obj, *ray);
	else if (obj->type == SPHERE)
		check_sphere_intersection(scene, (t_sphere *)obj->obj, *ray);
	else if (obj->type == CYLINDER)
		check_cylinder_intersection(scene, (t_cylinder *)obj->obj, *ray);
}

void			check_clog(t_scene *scene)
{
	t_list_obj	*obj;

	obj = scene->obj;
	scene->need_color = 0;
	while (obj && scene->clog)
	{
		check_intersection(scene, obj, &scene->light);
		if (scene->intersection == 1)
			scene->clog = 0;
		else
			scene->clog = 1;
		obj = obj->next;
	}
	scene->need_color = 1;
}
