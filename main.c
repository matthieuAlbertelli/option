#include <unistd.h>

size_t ft_strlen(char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

void ft_putstr(char *s)
{
	write (1, s, ft_strlen(s));
}

int ft_isalnum(char c)
{
	return (c >= 'a' && c <= 'z');
}

int ft_ishelp(char *s)
{
	return (*s == '-' && *++s == 'h');
}

#define INVALID "Invalid Option\n"
#define HELP "options: abcdefghijklmnopqrstuvwxyz\n"

int main(int argc, char **argv)
{
	int i;
	int j;
	char opt[33];

	if (argc == 1)
	{
		ft_putstr(HELP);
		return (0);
	}

	i = 0;
	while (i < 32)
	{
		opt[i] = '0';
		++i;
	}
	opt[32] = '\0';

	++argv;

	i = 0;
	while (argv[i])
	{
		if (ft_ishelp(argv[i]))
		{
			ft_putstr(HELP);
			return (0);
		}
		++i;
	}

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			++j;
			while (argv[i][j])
			{
				if (!ft_isalnum(argv[i][j]))
				{
					ft_putstr(INVALID);
					return (0);
				}
				opt['a' - argv[i][j] + 31] = '1';
				++j;
			}
		}
		++i;
	}

	i = 0;
	j = 0;
	while (i < 4)
	{
		write (1, &opt[j], 8);
		if (i != 3)
			ft_putstr(" ");
		++i;
		j += 8;
	}
	ft_putstr("\n");
	return (0);
}
