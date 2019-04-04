/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:51:02 by mdeville          #+#    #+#             */
/*   Updated: 2019/04/03 23:27:01 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_ssl.h"
#include "dlst.h"

int	set_init(t_hash *hash, char *name)
{
	hash->name = name;
	if (ft_strequ(name, "md5"))
		hash->init_f = init_md5;
	else if (ft_strequ(name, "sha256"))
		hash->init_f = init_sha256;
	else
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_flags		flags;
	t_hash		hash;
	t_dlist		*input_list;

	if (ac == 1)
	{
		ft_fprintf(2, "usage: %s md5|sha256 [-sp [-q | -r]]\n", av[0]);
		return (1);
	}
	if (set_init(&hash, av[1]) == 0)
	{
		ft_fprintf(2, "usage: %s md5|sha256 [-sp [-q | -r]]\n", av[0]);
		return (1);
	}
	input_list = parse_cmd(&flags, ac - 1, av + 1);
	if (input_list == NULL)
		return (1);
	return (process_input(input_list, &flags, &hash));
}
