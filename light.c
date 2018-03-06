/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:06:34 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 00:08:02 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light			*create_light(t_vector center, t_color color, float intensive)
{
	t_light		*light;

	light = malloc(sizeof(t_light));
	if (light == NULL)
		close_app("Lights not created", 0);
	light->center = center;
	light->color = color;
	light->intensive = intensive;
	light->next = NULL;
	return (light);
}

void			change_pos_ray(t_scene *scene)
{
	scene->light.pos = add_vector(scene->ray.pos,
			mult_vector(scene->ray.dir, scene->t));
	get_obj_normal(scene);
}

void			change_dir_ray(t_scene *scene, t_light *light_obj)
{
	float sqrt;

	scene->light.dir = minus_vector(light_obj->center, scene->light.pos);
	sqrt = sqrtf(scene->light.dir.x * scene->light.dir.x +
			scene->light.dir.y * scene->light.dir.y +
			scene->light.dir.z * scene->light.dir.z);
	scene->light_dist = sqrt;
	scene->t = scene->light_dist + 1;
	scene->light.dir = normal_vector(scene->light.dir);
}

void			init_defoult_color(t_scene *scene)
{
	scene->final_color.r = scene->closest_obj_color.r * scene->shadow_coef;
	scene->final_color.g = scene->closest_obj_color.g * scene->shadow_coef;
	scene->final_color.b = scene->closest_obj_color.b * scene->shadow_coef;
}

void			calc_light_for_obj(t_scene *scene)
{
	t_light		*lights;

	lights = scene->lights;
	change_pos_ray(scene);
	while (lights)
	{
		change_dir_ray(scene, lights);
		scene->clog = 1;
		check_clog(scene);
		if (scene->clog == 1)
			calc_light(scene, lights);
		lights = lights->next;
	}
}
