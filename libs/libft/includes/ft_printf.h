/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:09:23 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/25 22:34:52 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_internals.h"

# define HEX_BASE "0123456789abcdef"
# define BINARY_BASE "01"

/* ft_*printf format specifiers */
typedef enum e_specifier
{
	PERCENTAGE = '%',
	HEX_UPPER = 'X',
	BINARY = 'b' ,
	CHAR = 'c',
	DECIMAL = 'd',
	INTEGER = 'i',
	POINTER = 'p' ,
	STRING = 's',
	UNSIGNED = 'u',
	HEX_LOWER = 'x'
}	t_specifier;

/* ft_*printf's flag identifier */
typedef struct s_flags
{
	char		*str;
	int			precision;
	int			minus;
	int			zero;
	int			hash;
	int			space;
	int			plus;
	t_bool		has_error;
	t_bool		has_precision;
	size_t		width;
	size_t		str_len;
	size_t		placeholder_len;
	t_specifier	specifier;
}	t_flags;

/* ft_*printf's buffer */
typedef struct s_output
{
	int		size;
	char	*str;
}	t_output;

/* printf's family */

/**
* @brief Produce an output according to a format specified as a parameter,
* then write it to the standard output file descriptor (terminal).
* @param format Desired output formatting.
* @param ... Variadic arguments.
* @return The amount of characters printed, or -1 on error.
*/
int			ft_printf(const char *format, ...);

/**
* @brief Produce an output according to a format specified as a parameter,
* then write it to the given file descriptor.
* @param fd File descriptor to write to.
* @param format Desired output formatting.
* @param ... Variadic arguments.
* @return The amount of characters printed, or -1 on error.
*/
int			ft_dprintf(int fd, const char *format, ...);

/**
* @brief Produce an output according to a format specified as a parameter,
* then write it to the 'buf' character string.
* @param buf Character string to write to.
* @param format Desired output formatting.
* @param ... Variadic arguments.
* @return The amount of characters printed, or -1 on error.
*/
int			ft_sprintf(char *buf, const char *format, ...);

/**
* @brief Produce an output according to a format specified as a parameter,
* then write at most 'n' bytes of it to the 'buf' character string.
* @param buf Character string to write to.
* @param n Amount of bytes to write.
* @param format Desired output formatting.
* @param ... Variadic arguments.
* @return The amount of characters printed, or -1 on error.
*/
int			ft_snprintf(char *buf, size_t n, const char *format, ...);

/**
* @brief Produce an output according to a format specified as a parameter,
* then point 'str' to the generated output.
* Memory for the output
* is obtained with malloc(), and can be freed with free().
* @param str Pointer to where the generated output shall be pointed to.
* @param format Desired output formatting.
* @param ... Variadic arguments.
* @return The amount of characters printed, or -1 on error.
*/
int			ft_asprintf(char **str, const char *format, ...);

/* Handlers */

void		handle_integer(t_specifier specifier, t_flags *flags, va_list ap);
void		handle_binary(t_flags *flags, va_list ap);
void		handle_char(t_flags *flags, va_list ap);
void		handle_string(t_flags *flags, va_list ap);
void		handle_pointer(t_flags *flags, va_list ap);
void		handle_unsigned(t_flags *flags, va_list ap);
void		handle_hex(t_flags *flags, va_list ap);
void		handle_hex_upper(t_flags *flags, va_list ap);
void		handle_percentage(t_flags *flags);

/* Output generation */

int			fill_precision(t_flags *flags);
int			fill_width(t_flags *flags);
int			fill_int_width(t_flags *flags);
int			handle_zero(t_flags *flags);
int			handle_flags_integer(t_flags *flags);
void		prefix_positive(t_flags *flags);
void		get_str(t_specifier converter, t_flags *flags, va_list ap);
t_flags		*get_data(const char *str, va_list ap);
t_output	*generate_output(char *format, va_list ap);

#endif /* FT_PRINTF_H */
