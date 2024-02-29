#include "libft.h"

static double	handle_decimal(char *str, int count, double result)
{
    double decimal = 0.1;

	count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		result += (str[count++] - '0') * decimal;
		decimal *= 0.1;
	}
	return (result);
}

double	ft_strtod(char *str)
{
	int			count;
	double		result;
	int			minus_sign;

	count = 0;
	result = 0;
	minus_sign = 1;
	if (str[count] == '-')
		minus_sign *= -1;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		result *= 10.0;
		result += (str[count++] - '0') + 0.0;
	}
	if (str[count] == '.')
		result = handle_decimal(str, count, result);
	if (minus_sign < 0 && result > (double)LLONG_MAX)
		return (0.0);
	else if (minus_sign > 0 && result > (double)LLONG_MAX)
		return (-1.0);
	return (result * minus_sign);
}