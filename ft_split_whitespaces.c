/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:10:47 by mdebbi            #+#    #+#             */
/*   Updated: 2019/03/16 21:26:55 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		get_str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		get_word_count(char *str)
{
	int i;
	int strlen;
	int count;

	strlen = get_str_len(str);
	count = 0;
	i = 0;
	while (i < strlen)
	{
		if(str[i] == '(' || str[i] == ')')
			count++;
		if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') &&
		(str[i + 1] == ' ' || str[i + 1] == '\t' ||
		str[i + 1] == '\0' || str[i + 1] == '\n'))
			count++;
		i++;
	}
	return (count);
}

int		get_word_len(int start_ind, char *str)
{
	int i;

	i = 0;
	if(str[start_ind] == '(' || str[start_ind] == ')')
		return (1);
	while (str[start_ind + i] != ' ' && str[start_ind + i] != '\t' &&
	str[start_ind + i] != '\n' && str[start_ind + i] != '\0')
	{
		if(str[start_ind + i] == '(' || str[start_ind + i] == ')')
			return (i);
		i++;
	}
	return (i);
}

void	str_copy(char *src, char *dest, int src_len)
{
	int i;

	i = 0;
	while (i < src_len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		word_start_index;
	char	**res;
	int		word_len;
	int		curr_word_ind;

	curr_word_ind = 0;
	i = 0;
	res = (char **)malloc(sizeof(char *) * (get_word_count(str) + 1));
	while (i < get_str_len(str))
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			word_len = get_word_len(i, str);
			res[curr_word_ind] = (char *)malloc(sizeof(char) * (word_len + 1));
			str_copy(&str[i], &res[curr_word_ind][0], word_len + 1);
			curr_word_ind++;
			i += word_len - 1;
		}
		i++;
	}
	res[get_word_count(str)] = 0;
	return (res);
}
