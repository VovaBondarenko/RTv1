/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:58:38 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 00:01:04 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			init_image(t_scene *scene, t_mlx *mlx)
{
	scene->mlx->img.image = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	scene->mlx->img.str = mlx_get_data_addr(scene->mlx->img.image,
		&(mlx->img.bpp), &(mlx->img.size_len), &(mlx->img.endian));
	if (scene->mlx->img.image == NULL)
		close_app("Image not create", 0);
}

void			init_cam(t_scene *scene)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
		close_app("Cam not create", 0);
	camera->pos = create_vector(CAM_X, CAM_Y, CAM_Z);
	camera->angle = tanf((float)M_PI * 0.5f * CAM_ANGLE / 180.0f);
	scene->camera = camera;
}

void			init_win(t_scene *scene, int width, int height, char *name)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (mlx == NULL)
		close_app("Mlx not create", 0);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, width, height, name);
	mlx->width = width;
	mlx->height = height;
	scene->mlx = mlx;
	init_image(scene, mlx);
}

t_scene			*init_scene_param(t_scene *scene, int width,
		int height, char *name)
{
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (scene == NULL)
		close_app("Scene not create", 0);
	init_win(scene, width, height, name);
	init_cam(scene);
	scene->x = 0;
	scene->y = 0;
	scene->t_defoult = 50000.0f;
	scene->light_d_defoult = scene->t_defoult - 1.0f;
	scene->t = scene->t_defoult;
	scene->light_dist = scene->light_d_defoult;
	scene->closest_obj = NULL;
	scene->intersection = 0;
	scene->ray.pos = scene->camera->pos;
	scene->need_color = 1;
	scene->shadow_coef = 0.2f;
	return (scene);
}
