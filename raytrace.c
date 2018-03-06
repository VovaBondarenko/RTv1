/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:23:24 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 00:30:30 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			draw_scene(t_scene *scene)
{
	scene->y = 0;
	while (scene->y < scene->mlx->height)
	{
		scene->x = 0;
		while (scene->x < scene->mlx->width)
		{
			scene->ray.dir = get_ray_dir(scene);
			scene->closest_obj = NULL;
			find_intersection(scene, &scene->ray);
			if (scene->closest_obj)
			{
				init_defoult_color(scene);
				calc_light_for_obj(scene);
				draw_ray(scene, scene->final_color);
			}
			else
				draw_ray(scene, BLACK);
			scene->t = scene->t_defoult;
			scene->light_dist = scene->light_d_defoult;
			scene->x++;
		}
		scene->y++;
	}
	mlx_put_image_to_window(scene->mlx->mlx,
			scene->mlx->win, scene->mlx->img.image, 0, 0);
}

void			draw_ray(t_scene *scene, t_color color)
{
	int		index;

	index = scene->x * 4 + scene->y * scene->mlx->img.size_len;
	scene->mlx->img.str[index] = (color.b * 255 <
			(unsigned char)255) ? color.b * 255 : (unsigned char)255;
	scene->mlx->img.str[index + 1] = (color.g * 255 <
			(unsigned char)255) ? color.g * 255 : (unsigned char)255;
	scene->mlx->img.str[index + 2] = (color.r * 255 <
			(unsigned char)255) ? color.r * 255 : (unsigned char)255;
}

t_vector		get_ray_dir(t_scene *scene)
{
	t_vector	ray_dir;

	ray_dir = create_vector(
		(2 * ((scene->x + 0.5f) / (float)scene->mlx->width) - 1) *
		scene->camera->angle * ((float)scene->mlx->width /
			(float)scene->mlx->height),
		(1 - 2 * (scene->y + 0.5f) / (float)scene->mlx->height) *
		scene->camera->angle,
		-1.0f);
	norm_x(&ray_dir, 0);
	norm_y(&ray_dir, 0);
	norm_z(&ray_dir, 0);
	ray_dir = normal_vector(ray_dir);
	return (ray_dir);
}
