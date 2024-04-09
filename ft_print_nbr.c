/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:46:45 by wkabat            #+#    #+#             */
/*   Updated: 2024/04/04 16:51:36 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_nbr(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		len += write(1, "-", 1);
		len += ft_print_nbr(-n);
	}
	else if (n >= 10)
	{
		len += ft_print_nbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}
