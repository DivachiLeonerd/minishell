
#include"libft.h"

long int	ft_atol(const char *str)
{
	long int	number;
	long int	i;
	int	neg;

	neg = 1;
	number = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (str[i] - 48) + number * 10;
		i++;
	}
	return (number * (long int)neg);
}
