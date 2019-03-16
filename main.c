/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 21:17:14 by mdebbi            #+#    #+#             */
/*   Updated: 2019/03/16 21:30:21 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(-214748364);
		ft_putchar('8');
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		if (nb < 10)
			ft_putchar('0' + nb);
		else
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + '0');
		}
	}
}

int eval_expr(char *expr)
{
	int i=0;
	char **exp = ft_split_whitespaces(expr);
//	while(exp[i])
//		printf("\n%s\n",exp[i++]);/////////////???!
	char **rpn = exp_to_rpn(exp);
	while(rpn[i])
		printf("%s ", rpn[i++]);
	return (eval_rpn(rpn));	
}


int main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
