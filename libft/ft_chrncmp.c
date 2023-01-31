/*************************************************************************/
/*                                                                       */
/*                                                                       */
/*     HEADER FUCKING FILE FUCK YEAH MOTHERFUCKER                        */
/*                                                                       */
/*     Created: 69/420 who:fucking:cares by: me                          */
/*     Updated: 69/421 who:fucking:cares by: me                          */
/*                                                             42        */
/*************************************************************************/

#include "libft.h"

int	chrncmp(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
