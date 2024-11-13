/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:31:21 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/11/13 13:49:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	handle_format_specifier(char c, va_list args,
		t_function_entry *head)
{
	t_function_entry	*temp;
	int					count;

	temp = head;
	count = 0;
	while (temp)
	{
		if (c == temp->flag)
		{
			count += temp->function(args);
			break ;
		}
		temp = temp->next;
	}
	if (!temp && c == '%')
	{
		put_char('%');
		count++;
	}
	return (count);
}

static int	process_format(const char *format, va_list args,
		t_function_entry *head)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += handle_format_specifier(format[++i], args, head);
		else if (format[i] != '%')
		{
			put_char(format[i]);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list				args;
	t_function_entry	*head;
	int					count;

	if (!format || write(1, NULL, 0) == -1)
		return (-1);
	head = init_functions();
	va_start(args, format);
	count = process_format(format, args, head);
	free_list(head);
	va_end(args);
	return (count);
}
