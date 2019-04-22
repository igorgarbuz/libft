#include "libft.h"
/*
** function ft_memncat concatenates two locations of memory nito one;
** it is useful to safely concatenate strings that contain '\0'  
** concatenation is done in freshly allocated memory, pointed by **mainStr;
** previously allocated memory pointed by **mainStr is freed;
*/
int		ft_memncat(char **mainStr, char *adder, int lenAdder)
{
	char	*newStr;
	int		lenStr;

	if (lenAdder && mainStr && adder)
	{
		newStr = NULL;
		lenStr = ft_strlen(*mainStr);
		if (!(newStr = (char *)malloc(sizeof(char) * (lenStr + lenAdder + 1))))
			return (-1);
		ft_memcpy(newStr, *mainStr, lenStr);
		ft_memcpy(newStr + lenStr, adder, lenAdder);
		newStr[lenStr + lenAdder] = '\0';
		if (*mainStr)
			free(*mainStr);
		*mainStr = newStr;
		return (1);
	}
	return (0);
}