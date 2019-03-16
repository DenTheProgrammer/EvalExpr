int ft_atoi(char *str)
{
	int res = 0;
	int sign = 1;
	while(*str == ' ' || *str == '\t')
		str++;
	if(*str == '+' || *str == '-')
		if(*str++ == '-')
			sign *= -1;
	while(*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * sign);
}
