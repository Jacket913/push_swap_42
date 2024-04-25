/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:56:02 by gmoulin           #+#    #+#             */
/*   Updated: 2024/04/25 17:09:48 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* LIBRARIES */
# include <stdarg.h>
# include "libft.h"

/* FUNCTIONS */
int	ft_printf(const char *, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	pnbase(long n, int baselength, char *base);
int	ft_print_ptr(void *ptr);
int	put_ptr(unsigned long n, unsigned long baselength, char *base);

#endif
