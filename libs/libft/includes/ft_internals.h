/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internals.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:46:17 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/23 02:50:04 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERNALS_H
# define FT_INTERNALS_H

/* External libraries */
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* Standard file descriptors */
# define STDIN STDIN_FILENO		/* Shortened STDIN file descriptor */
# define STDOUT STDOUT_FILENO	/* Shortened STDOUT file descriptor */
# define STDERR STDERR_FILENO	/* Shortened STDERR file descriptor */

/* get_next_line related */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42	/* Standard buffer size for GNL */
# endif
# define MAX_FD_VALUE 1024	/* Max file descriptor value supported by GNL */

/* Hashtable */
# define HASH_TABLE_SIZE 1031		/* Hashtable total size */
# define HASH_RIGHT_OFFSET 24		/* Right bit-shifting offset */
# define HASH_LEFT_OFFSET 4			/* Left bit-shifting offset */
# define HASH_LIMITER 0xf0000000	/* Hashing limiter */

typedef long long			t_llong;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned long long	t_ullong;

/* Boolean values */
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

/* Linked list node */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* Hashtable node */
typedef struct s_htnode
{
	char			*key;
	char			*value;
	struct s_htnode	*next;
}	t_htnode;

/* Hashtable structure */
typedef struct s_hashtable
{
	t_htnode	*item[HASH_TABLE_SIZE];
}	t_hashtable;

#endif /* FT_INTERNALS_H */
