#include "libft.h"

static int	ft_needleReset(char **needle)
{
	if (*needle && !**needle)
	{
		*needle = NULL;
		return(1);
	}
	return (0);
}
/*
** ft_newLienOnHaystack is called if '\n' is present on the haystack;
** needle is a pointer to n+1 byte after '\n';
** new line from *needle untill next '\n' is copied to freshly allocated memory
** pointed by **line;
** *needle pointer is shifted on the length of copied new line + 1 byte;
*/
static int	ft_newlineOnHaystack(char **line, char **needle)
{
	int		needleLen;
	char	*needleEnd;

	needleEnd = ft_strchr(*needle, '\n');
	needleLen = needleEnd - *needle;
	if (!(*line = ft_strsub(*needle, 0, needleLen)))
		return(-1);
	*needle += needleLen + 1;
	ft_needleReset(needle);
	return (1);
}
/*
** function readNewLine reads line in a loop till '\n' is reached;
** read results are concatenated to **line;
** if a string is present in haystack, it is copied to the HEAD of **line 
*/
static int	ft_readNewline(int fd, char *haystack, char **needle, char **line)
{	
	int		rd;

	if (*needle)
		if (ft_memncat(line, *needle, ft_strlen(*needle)) == -1)
			return (-1);
	*needle = NULL;
	rd = 1;
	while (!*needle && rd > 0)
	{
		if ((rd = read(fd, haystack, BUFF_SIZE)) == -1)
			return (-1);
		haystack[rd] = '\0';
		if (rd == 0 && !*line)
			return (0);
		if ((*needle = ft_strchr(haystack, '\n')) == 0)
			rd = ft_memncat(line, haystack, ft_strlen(haystack));
		else
		{
			rd = ft_memncat(line, haystack, (*needle - haystack));
			*needle += 1;
		}
	}
	ft_needleReset(needle);
	return (1);
}
/*
** get_next_line_lite is similar to get_next_line, with a main difference in
** memory management; get_next_line_lite is designed for better performances
** on smaller files, with tipical size below several Mb;
** another principal differences: absence of multi-fd;
** function reads from [fd] [BUFF_SIZE] bites and returns
** a new lien in freshly allocated mamory, pointed by **line;
** Return: uppon syccess it returns 1, or 0 if reading is ended;
** -1 is returned in case of an error;
*/
int			get_next_line_lite(int fd, char **line)
{
	static char	haystack[BUFF_SIZE + 1] = { 0 };
	static char	*needle = NULL;
	int			rd;

	if (!line)
		return (-1);
	*line = NULL;
	if (needle && ft_strchr(needle, '\n'))
		rd = ft_newlineOnHaystack(line, &needle);
	else 
		rd = ft_readNewline(fd, haystack, &needle, line);
	return (rd);
}
