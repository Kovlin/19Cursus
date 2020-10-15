/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:10:53 by rlinkov           #+#    #+#             */
/*   Updated: 2020/10/15 13:39:57 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef struct	s_data_file //en a t'on besoin ?
{
	int			res_x; //screen resolution x
	int			res_y; //screen resolution y
	char		*n_text; //path to north texture
	char		*s_text; //path to south texture
	char		*e_text; //path to east texture
	char		*w_text; //path to west texture
	char		*sprite; //path to sprite texture
	int			f_r; //red for the floor
	int			f_g; //green for the floor
	int			f_b; //blue for the floor
	int			c_r; //red for the ceiling
	int			c_g; //green for the ceiling
	int			c_b; //blue for the ceiling
	
}				t_data;

typedef struct	s_cube3d
{
	//structure globale du projet, contindra tout ce qui est nécéssaire
	char	*file; //fichier .cub /!\ surement pas besoin a voir
	int		**color; //tableau de couleur pour le sol et le plafond
	char 	**textures; //tableau des textures
	int		*e_count; //tableau du nombre d'elements
}				t_cube;

#endif