/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:09:06 by vbondare          #+#    #+#             */
/*   Updated: 2017/11/17 16:25:54 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <mlx.h>

# define CAM_X 1000
# define CAM_Y 300
# define CAM_Z 2000
# define CAM_ANGLE 75
# define ANGLE_DEF (M_PI / 180.0f)
# define BLACK (t_color){0, 0, 0}
# define CONE 1
# define PLANE 2
# define SPHERE 3
# define CYLINDER 4
# define LIGHT -3
# define PLUS 69
# define MINUS 78
# define ARROW_UP 126
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ESC 53

typedef	struct			s_color
{
	float				r;
	float				g;
	float				b;
}						t_color;

typedef struct			s_vector
{
	float				x;
	float				y;
	float				z;
}						t_vector;

typedef struct			s_cone
{
	t_vector			center;
	t_color				color;
	t_vector			normal;
	float				angle;
}						t_cone;

typedef struct			s_cylinder
{
	t_vector			center;
	t_vector			normal;
	float				radius;
	t_color				color;
}						t_cylinder;

typedef struct			s_sphere
{
	t_vector			center;
	float				radius;
	t_color				color;
}						t_sphere;

typedef struct			s_plane
{
	t_vector			center;
	t_vector			normal;
	t_color				color;
}						t_plane;

typedef struct			s_raytrace
{
	t_vector			pos;
	t_vector			dir;
}						t_raytrace;

typedef struct			s_light
{
	t_vector			center;
	t_color				color;
	float				intensive;
	struct s_light		*next;
}						t_light;

typedef struct			s_list_obj
{
	void				*obj;
	int					type;
	t_vector			normal;
	struct s_list_obj	*next;
}						t_list_obj;

typedef struct			s_image
{
	void				*image;
	char				*str;
	int					size_len;
	int					bpp;
	int					endian;
}						t_image;

typedef struct			s_camera
{
	float				angle;
	t_vector			pos;
}						t_camera;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	int					width;
	int					height;
	t_image				img;
}						t_mlx;

typedef struct			s_scene
{
	t_mlx				*mlx;
	t_camera			*camera;

	t_raytrace			ray;
	t_raytrace			light;
	t_list_obj			*obj;
	t_light				*lights;
	t_list_obj			*closest_obj;
	t_color				closest_obj_color;
	t_color				final_color;
	t_color				fong_shadow;
	float				lambert;
	float				light_dist;
	float				light_d_defoult;
	float				t_defoult;
	float				t;
	float				tmp_dist;
	int					intersection;
	int					clog;
	int					need_color;
	float				shadow_coef;
	int					scene_num;
	int					x;
	int					y;
}						t_scene;

void					close_app(char *str, int usage);
void					draw_scene(t_scene *scene);
void					check_disc_intersection(t_scene *scene,
		float a, float b, float c);
void					find_intersection(t_scene *scene, t_raytrace *ray);
void					check_intersection(t_scene *scene,
		t_list_obj *obj, t_raytrace *ray);
void					check_clog(t_scene *scene);
t_plane					*create_plane(t_vector center,
		t_vector normal, t_color color);
void					check_plane_intersection(t_scene *scene,
		t_plane *plane, t_raytrace ray);
void					calc_plane_normal(t_scene *scene, t_plane *plane);
t_cone					*create_cone(t_vector center,
		t_vector normal, t_color color, float angle);
void					check_cone_intersection(t_scene *scene,
		t_cone *cone, t_raytrace ray);
void					calc_cone_normal(t_scene *scene,
		t_cone *cone, t_vector ray_light);
t_cylinder				*create_cylinder(t_vector center,
		t_vector normal, float radius, t_color color);
void					check_cylinder_intersection(t_scene *scene,
		t_cylinder *cylinder, t_raytrace ray);
void					calc_cylinder_normal(t_scene *scene,
		t_cylinder *cylinder, t_vector ray_light);
t_sphere				*create_sphere(t_vector center,
		t_color color, float radius);
void					check_sphere_intersection(t_scene *scene,
		t_sphere *sphere, t_raytrace ray);
void					calc_sphere_normal(t_scene *scene, t_sphere *sphere);
void					calc_light(t_scene *scene, t_light *light_list);
t_light					*create_light(t_vector center,
		t_color color, float intensive);
void					calc_light_for_obj(t_scene *scene);
void					init_defoult_color(t_scene *scene);
t_scene					*init_scene_param(t_scene *scene,
		int width, int height, char *name);
t_color					get_color(t_scene *scene);
t_vector				get_ray_dir(t_scene *scene);
void					draw_ray(t_scene *scene, t_color color);
void					norm_x(t_vector *vector, float angle);
void					norm_y(t_vector *vector, float angle);
void					norm_z(t_vector *vector, float angle);
void					get_obj_normal(t_scene *scene);
t_list_obj				*create_node_obj(void *obj, int type);
void					add_node_obj(t_list_obj **head, t_list_obj *node);
void					add_node_light(t_light **head, t_light *node);
t_vector				create_vector(float x, float y, float z);
t_vector				add_vector(t_vector vector1, t_vector vector2);
t_vector				normal_vector(t_vector vector);
t_vector				minus_vector(t_vector vector1, t_vector vector2);
float					get_dot(t_vector vector1, t_vector vector2);
t_vector				mult_vector(t_vector vector1, float dot);
void					init_scene_1(t_scene *scene);
void					init_scene_2(t_scene *scene);
void					init_scene_3(t_scene *scene);
void					init_scene_4(t_scene *scene);
void					init_scene_5(t_scene *scene);
void					fong_shadow(t_scene *scene,
		t_light *light_list, t_vector normal);
int						key_hook(int keycode, t_scene *scene);

#endif
