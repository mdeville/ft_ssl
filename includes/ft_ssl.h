/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:33:59 by mdeville          #+#    #+#             */
/*   Updated: 2019/04/04 00:27:18 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdint.h>
# include "dlst.h"

typedef struct	s_hash
{
	char		*name;
	uint32_t	state[8];
	uint64_t	lstate[8];
	size_t		md_len;
	ssize_t		chunk_len;
	char		*out;
	int			(*hash_f)(struct s_hash *, const char *);
	int			(*init_f)(struct s_hash *);
}				t_hash;

typedef struct	s_flags
{
	int			p;
	int			q;
	int			r;
}				t_flags;

typedef enum	e_type
{
	STRING,
	STDIN,
	_FILE
}				t_type;

typedef struct	s_input
{
	t_type		type;
	char		*str;
	int			fd;
}				t_input;

int				init_md5(t_hash *hash);
int				md5(t_hash *hash, const char *buf);
int				init_sha256(t_hash *hash);
int				sha256(t_hash *hash, const char *buf);

t_dlist			*parse_cmd(t_flags *flags, int ac, char *argv[]);
int				process_input(
							t_dlist *lst,
							t_flags *flags,
							t_hash *hash);

#endif
