/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:12:53 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 00:13:34 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		change_shadow_coef(t_scene *scene, int keycode)
{
	float	coef;
	float	tmp_shadow_coef;

	coef = (keycode == PLUS) ? 0.1f : -0.1f;
	tmp_shadow_coef = scene->shadow_coef;
	if (keycode == MINUS)
		scene->shadow_coef += (scene->shadow_coef >= 0.1f) ? coef : 0.0f;
	else
		scene->shadow_coef += (scene->shadow_coef <= 0.9f) ? coef : 0.0f;
	if (tmp_shadow_coef != scene->shadow_coef)
	{
		mlx_clear_window(scene->mlx->mlx, scene->mlx->win);
		draw_scene(scene);
	}
}

void		change_light_dist(t_scene *scene, int keycode)
{
	float	coef;
	float	tmp_defoult;

	tmp_defoult = scene->t_defoult;
	coef = (keycode == ARROW_UP) ? 100.0f : -100.0f;
	if (keycode == ARROW_UP)
		scene->t_defoult += (scene->t_defoult >= 0) ? coef : 0;
	else
		scene->t_defoult += (scene->t_defoult > 101.0f) ? coef : 0;
	scene->light_d_defoult = scene->t_defoult - 1.0f;
	if (tmp_defoult != scene->t_defoult)
	{
		mlx_clear_window(scene->mlx->mlx, scene->mlx->win);
		draw_scene(scene);
	}
}

int			key_hook(int keycode, t_scene *scene)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == PLUS || keycode == MINUS)
		change_shadow_coef(scene, keycode);
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN)
		change_light_dist(scene, keycode);
	return (1);
}
