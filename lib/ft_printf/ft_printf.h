/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:04:46 by stalash           #+#    #+#             */
/*   Updated: 2024/03/29 16:04:46 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> //NULL, malloc, free
# include <stdio.h> //testing
# include <stdarg.h> //varidic stuff
# include <unistd.h> //write

//**********prototype****************

extern int	ft_printf(const char *str, ...);
extern int	ft_putchar(char c);
extern int	ft_putstr(char const *s);
extern int	ft_putnbr(long long nb, int base, int uppercase);
extern int	print_pointer(void *ptr);
char		*ft_strchr_p(const char *s, int c);

#endif
