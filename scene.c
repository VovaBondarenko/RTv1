/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:20:13 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 15:52:33 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				init_scene_1(t_scene *scene)
{
	t_list_obj		*obj;
	t_light			*lights;

	obj = NULL;
	lights = NULL;
	add_node_light(&lights, create_light(create_vector(800, 600, 800),
				(t_color){0.8, 0.8, 0.8}, 20));
	add_node_light(&lights, create_light(create_vector(400, 2300, 800),
				(t_color){0.8, 0.8, 0.8}, 20));
	add_node_obj(&obj, create_node_obj(create_sphere(create_vector(0, 0, 0),
					(t_color){1, 0, 0}, 300), SPHERE));
	add_node_obj(&obj, create_node_obj(create_sphere(
			create_vector(600, 100, 400), (t_color){1, 0, 0}, 300), SPHERE));
	add_node_obj(&obj, create_node_obj(create_cylinder(create_vector(300,
	0, 300), create_vector(0, 1, 0), 100, (t_color){0, 0, 1}), CYLINDER));
	add_node_obj(&obj, create_node_obj(create_cylinder(create_vector(600,
	0, 300), create_vector(0.5, 0.5, 0), 100, (t_color){0, 0, 1}), CYLINDER));
	add_node_obj(&obj, create_node_obj(create_plane(create_vector(0, 900, 0),
					create_vector(0, -1, 0), (t_color){0.6, 0.6, 0.7}), PLANE));
	add_node_obj(&obj, create_node_obj(create_cone(create_vector(200, 0, 0),
					create_vector(0, 1, 0), (t_color){1, 1, 0}, 30), CONE));
	add_node_obj(&obj, create_node_obj(create_plane(create_vector(0, -100, 0),
					create_vector(0, 0, 1), (t_color){0, 1, 0}), PLANE));
	scene->obj = obj;
	scene->lights = lights;
}

void				init_scene_2(t_scene *scene)
{
	t_list_obj		*obj;
	t_light			*lights;

	obj = NULL;
	lights = NULL;
	add_node_light(&lights, create_light(create_vector(800, 600, 800),
				(t_color){0.8, 0.8, 0.8}, 20));
	add_node_obj(&obj, create_node_obj(create_plane(create_vector(0, 0, -1000),
					create_vector(0, 0, 1), (t_color){0.7, 0.5, 0.5}), PLANE));
	add_node_obj(&obj, create_node_obj(create_plane(create_vector(0, -1000, 0),
				create_vector(0, 0.5, 0.1), (t_color){0.6, 0.6, 0.7}), PLANE));
	add_node_obj(&obj, create_node_obj(create_plane(create_vector(-1000, 0, 0),
				create_vector(1, -1, 0), (t_color){0.3, 0, 0.7}), PLANE));
	add_node_obj(&obj, create_node_obj(create_plane(create_vector(3000, 0, 0),
				create_vector(1, 1, 0), (t_color){0, 0.3, 0.7}), PLANE));
	add_node_obj(&obj, create_node_obj(create_cylinder(create_vector(300,
	0, 300), create_vector(0, 1, 0), 100, (t_color){0, 0, 1}), CYLINDER));
	add_node_obj(&obj, create_node_obj(create_cylinder(create_vector(1500,
	0, 300), create_vector(0, 1, 0), 100, (t_color){0, 0, 1}), CYLINDER));
	add_node_obj(&obj, create_node_obj(create_cylinder(create_vector(900,
	0, -300), create_vector(0, 1, 0), 100, (t_color){0, 0, 1}), CYLINDER));
	scene->obj = obj;
	scene->lights = lights;
}

void				init_scene_3(t_scene *scene)
{
	t_list_obj		*obj;
	t_light			*lights;

	obj = NULL;
	lights = NULL;
	add_node_light(&lights, create_light(create_vector(1500, 600, -500),
				(t_color){0.8, 0.8, 0.8}, 20));
	add_node_obj(&obj, create_node_obj(create_cone(create_vector(1000,
	0, -1500), create_vector(0.5, 0.5, 0), (t_color){1, 1, 0}, 10), CONE));
	add_node_obj(&obj, create_node_obj(create_cone(create_vector(1000,
	0, -1500), create_vector(0.5, -0.5, 0), (t_color){1, 1, 0}, 10), CONE));
	add_node_obj(&obj, create_node_obj(create_cone(create_vector(1000,
	0, -1500), create_vector(-1, 0, 0), (t_color){1, 1, 0}, 10), CONE));
	add_node_obj(&obj, create_node_obj(create_cone(create_vector(1000,
	0, -1500), create_vector(0, -1, 0), (t_color){1, 1, 0}, 10), CONE));
	add_node_obj(&obj, create_node_obj(create_plane(create_vector(2000,
	0, -3000), create_vector(0, 0, 1), (t_color){0.3, 0.3, 0.3}), PLANE));
	add_node_obj(&obj, create_node_obj(create_sphere(create_vector(1000,
	100, -1500), (t_color){1, 0, 0}, 600), SPHERE));
	scene->obj = obj;
	scene->lights = lights;
}

void				init_scene_4(t_scene *scene)
{
	t_list_obj		*obj;
	t_light			*lights;

	obj = NULL;
	lights = NULL;
	add_node_light(&lights, create_light(create_vector(900,
	0, 500), (t_color){0.8, 0.8, 0.8}, 20));
	add_node_obj(&obj, create_node_obj(create_cylinder(create_vector(300,
	0, 300), create_vector(1, 0, -0.5), 100, (t_color){0, 0, 1}), CYLINDER));
	add_node_obj(&obj, create_node_obj(create_cone(create_vector(300,
	0, 300), create_vector(0, 1, 0), (t_color){1, 1, 0}, 30), CONE));
	add_node_obj(&obj, create_node_obj(create_cylinder(create_vector(300,
	0, 300), create_vector(0.5, 0.5, 0), 100, (t_color){0, 0, 1}), CYLINDER));
	add_node_obj(&obj, create_node_obj(create_sphere(create_vector(300,
	0, 300), (t_color){1, 0, 0}, 300), SPHERE));
	scene->obj = obj;
	scene->lights = lights;
}

void				init_scene_5(t_scene *scene)
{
	t_list_obj		*obj;
	t_light			*lights;

	obj = NULL;
	lights = NULL;
	add_node_light(&lights, create_light(create_vector(900,
	900, 500), (t_color){0.8, 0.8, 0.8}, 30));
	add_node_obj(&obj, create_node_obj(create_sphere(create_vector(300,
	0, 300), (t_color){1, 0, 0}, 300), SPHERE));
	add_node_obj(&obj, create_node_obj(create_sphere(create_vector(900,
	0, 300), (t_color){1, 0, 0}, 300), SPHERE));
	add_node_obj(&obj, create_node_obj(create_cylinder(create_vector(300,
	-500, 300), create_vector(1, 0, 0), 100, (t_color){0, 0, 1}), CYLINDER));
	add_node_obj(&obj, create_node_obj(create_cylinder(create_vector(300,
	-500, 300), create_vector(0.3, 0.3, 0), 100,
					(t_color){0, 0, 1}), CYLINDER));
	scene->obj = obj;
	scene->lights = lights;
}
