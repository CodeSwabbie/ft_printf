/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:40:59 by wkabat            #+#    #+#             */
/*   Updated: 2024/04/04 12:49:25 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_hex(unsigned long long int n, char c)
{
	char			*base;
	unsigned int	len;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += ft_hex(n / 16, c);
	len += write(1, &base[n % 16], 1);
	return (len);
}

int	ft_print_ptr(void *str)
{
	unsigned long long int	adress;
	unsigned int			len;

	adress = (unsigned long long int) str;
	len = 0;
	if (str == NULL)
		return (write(1, "0x0", 3));
	len += write(1, "0x", 2);
	len += ft_hex(adress, 'x');
	return (len);
}
