/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:11:37 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 00:12:35 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void		norm_x(t_vector *vector, float angle)
{
	t_vector	tmp;

	tmp = *vector;
	vector->y = tmp.y * cos(angle * ANGLE_DEF) - tmp.z * sin(angle * ANGLE_DEF);
	vector->z = tmp.y * sin(angle * ANGLE_DEF) + tmp.z * cos(angle * ANGLE_DEF);
}

inline void		norm_y(t_vector *vector, float angle)
{
	t_vector tmp;

	tmp = *vector;
	vector->x = tmp.x * cos(angle * ANGLE_DEF) + tmp.z * sin(angle * ANGLE_DEF);
	vector->z = tmp.x * sin(angle * ANGLE_DEF) + tmp.z * cos(angle * ANGLE_DEF);
}

inline void		norm_z(t_vector *vector, float angle)
{
	t_vector tmp;

	tmp = *vector;
	vector->x = tmp.x * cos(angle * ANGLE_DEF) - tmp.y * sin(angle * ANGLE_DEF);
	vector->y = tmp.x * sin(angle * ANGLE_DEF) + tmp.y * cos(angle * ANGLE_DEF);
}

void			get_obj_normal(t_scene *scene)
{
	if (scene->closest_obj->type == CONE)
		calc_cone_normal(scene,
				(t_cone *)(scene->closest_obj->obj), scene->light.pos);
	else if (scene->closest_obj->type == PLANE)
		calc_plane_normal(scene, (t_plane *)(scene->closest_obj->obj));
	else if (scene->closest_obj->type == SPHERE)
		calc_sphere_normal(scene, (t_sphere *)(scene->closest_obj->obj));
	else if (scene->closest_obj->type == CYLINDER)
		calc_cylinder_normal(scene,
				(t_cylinder *)(scene->closest_obj->obj), scene->light.pos);
}
