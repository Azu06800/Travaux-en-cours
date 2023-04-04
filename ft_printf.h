/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:56:58 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/04 19:16:57 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putptr(void *ptr);
int		ft_putnbr_base(int nbr, char *base);
int		ft_unsigned_putnbr_base(size_t nbr, char *base);
char	*ft_strchr(const char *s, int c);
#endif
