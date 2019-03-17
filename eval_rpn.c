/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_rpn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 20:16:01 by mdebbi            #+#    #+#             */
/*   Updated: 2019/03/17 15:42:00 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int calc(int a, int b, char *op)
{
	if(op[0] == '+')
		return (a + b);
	else if(op[0] == '-')
		return (a - b);
	else if(op[0] == '*')
		return (a * b);
	else if(op[0] == '/')
		return (a / b);
	else if(op[0] == '%')
		return (a % b);
	else
		return (0);
}

int eval_rpn(char **rpn)
{
	int *stack = (int *)malloc(sizeof(int) * get_size(rpn));
	int sp = 0;
	while (*rpn)
	{
		if ((*rpn[0] >= '0' && *rpn[0] <= '9') || (*rpn[0] == '-' && *(*rpn + 1) != '\0'))
			stack[sp++] = ft_atoi(*rpn);
		else
		{
			stack[sp - 2] = calc(stack[sp-2], stack[sp-1], *rpn);
			sp--;
		}
		rpn++;
	}
	return (stack[0]);
}
