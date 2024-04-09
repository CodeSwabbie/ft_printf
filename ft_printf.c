/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:57:34 by wkabat            #+#    #+#             */
/*   Updated: 2024/04/09 13:59:18 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	// else if (format == 's')
	// 	len += ft_print_str(va_arg(args, char *));
	// else if (format == 'd' || format == 'i')
	// 	len += ft_print_nbr(va_arg(args, int));
	// else if (format == 'p')
	// 	len += ft_print_ptr(va_arg(args, void *));
	// else if (format == 'x' || format == 'X')
	// 	len += ft_print_hex(va_arg(args, unsigned int), format);
	// else if (format == 'u')
	// 	len += ft_print_unsigned(va_arg(args, unsigned int));
	// else if (format == '%')
	// 	len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_format(args, str[i]);
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	main()
{
	ft_printf("%c %c %c\n", 'A','1','B');
	// ft_printf("%s %s\n", "Hello World!", "Yeah!");
	// ft_printf("%d %d\n", 1, 2);
	// ft_printf("Hi! My name is %s, and I am %d old.\n", "Wiktor");
}