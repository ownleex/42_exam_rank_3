#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buf[BUFFER_SIZE + 1];
	int		i;
	int		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	i = 0;
	while ((n = read(fd, &buf[i], 1)) > 0)
	{
		if (buf[i] == '\n' || i == BUFFER_SIZE - 1)
		{
			buf[i + 1] = '\0';
			line = ft_strdup(buf);
			return (line);
		}
		i++;
	}
	if (i != 0)
	{
		buf[i] = '\0';
		line = ft_strdup(buf);
	}
	return (line);
}
