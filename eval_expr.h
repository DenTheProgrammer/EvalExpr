/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 20:35:25 by mdebbi            #+#    #+#             */
/*   Updated: 2019/03/16 21:29:58 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>/////////////del
#include <stdlib.h>
#include <unistd.h>

int calc(int a, int b, char *op);
int eval_rpn(char **rpn);
int get_size(char **arr);
int priority_check(char op1, char op2);
char **exp_to_rpn(char **exp);
int     get_str_len(char *str);
int     get_word_count(char *str);
int     get_word_len(int start_ind, char *str);
void    str_copy(char *src, char *dest, int src_len);
char    **ft_split_whitespaces(char *str);
void ft_putchar(char c);
void    ft_putnbr(int nb);
int eval_expr(char *expr);
