/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:36:56 by stalash           #+#    #+#             */
/*   Updated: 2025/01/17 07:43:49 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	setup_map_storage(t_data data)
{
	int	i;

	data.map->map_cub = (char **)ft_calloc(MAP_HEIGHT, sizeof(char *));
	if (!data.map->map_cub)
	{
		printf("allocation failure\n");
		deallocate_map(data);
		return (1);
	}
	i = -1;
	while (data.map->map_cub[++i])
	{
		data.map->map_cub[i] = (char *)ft_calloc(MAP_WIDE, sizeof(char));
			if (!data.map->map_cub[i])
			{
				printf("allocation failure\n");
				deallocate_map(data);
				return (1);
			}
		ft_memset(data.map->map_cub[i], '\0', MAP_WIDE);
	}
	return (0);
}

int valid_map_name(char **argv)
{
	int len;

	len = 0;
	printf("%s\n", argv[1]);
	if (argv == NULL)
		return (1);
	printf("we are here \n");
	len = ft_strlen(argv[1]);
	if (len < 4)
		return (1);
	if (len >= 4)
	{
		if (ft_strchr((argv[1] + (len - 4)), '.') == NULL)
			return (1);
		else if (ft_strchr((argv[1] + (len - 3)), 'c') == NULL)
			return (1);
		else if (ft_strchr((argv[1] + (len - 2)), 'u') == NULL)
			return (1);
		else if (ft_strchr((argv[1] + (len - 1)), 'b') == NULL)
			return (1);
	}
	return (0);
}

void	parsing(char **argv, t_data data)
{
	int		fd;
	char	*map_colors;

	if (valid_map_name(argv) == 1)
		return (printf("Map's name is invalid\n"), exit (1));
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return(printf("can't open the given map\n"), exit (1));
	if (setup_map_storage(data) == 1)
		return (close (fd), exit (1));
	if ((map_colors = retrieve_texture_and_color(fd, data)) == NULL)
		return (deallocate_map(data), close(fd) ,exit(1));
}
