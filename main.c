/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:13:02 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 17:07:45 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				exit_app(void)
{
	exit(0);
}

void			close_app(char *str, int usage)
{
	ft_putendl(str);
	if (usage == 1)
		ft_putendl("usage: scene_1,scene_2,scene_3,scene_4,scene_5");
	exit(0);
}

int				choose_scene(char *str)
{
	if (ft_strcmp("scene_1", str) == 0)
		return (1);
	else if (ft_strcmp("scene_2", str) == 0)
		return (2);
	else if (ft_strcmp("scene_3", str) == 0)
		return (3);
	else if (ft_strcmp("scene_4", str) == 0)
		return (4);
	else if (ft_strcmp("scene_5", str) == 0)
		return (5);
	return (-1);
}

void			init_scene(t_scene *scene)
{
	if (scene->scene_num == 1)
		init_scene_1(scene);
	else if (scene->scene_num == 2)
		init_scene_2(scene);
	else if (scene->scene_num == 3)
		init_scene_3(scene);
	else if (scene->scene_num == 4)
		init_scene_4(scene);
	else if (scene->scene_num == 5)
		init_scene_5(scene);
}

int				main(int argc, char **argv)
{
	t_scene		*scene;
	int			num_scene;

	num_scene = -1;
	if (argc == 2)
		num_scene = choose_scene(argv[1]);
	else
		close_app("Need enter just one parameter", 1);
	scene = NULL;
	if (num_scene != -1)
		scene = init_scene_param(scene, 800, 600, "RTv1");
	else
		close_app("Enter valid name", 1);
	scene->scene_num = num_scene;
	init_scene(scene);
	draw_scene(scene);
	mlx_hook(scene->mlx->win, 17, 1L << 17, exit_app, scene);
	mlx_hook(scene->mlx->win, 2, 5, key_hook, scene);
	mlx_loop(scene->mlx);
	return (0);
}
