#include "push_swap.h"

static int	str_size(char **str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

static void set_instructions(char **cut, int j, int ca, int cb)
{
	if (ca < cb && ca && cb)
	{
		cb -= ca;
		while (ca--)
			cut[j++] = "rr";
		while (cb--)
			cut[j++] = "rb";
	}
	else if (ca > cb && ca && cb)
	{
		ca -= cb;
		while (cb--)
			cut[j++] = "rr";
		while (ca--)
			cut[j++] = "ra";
	}
	else if (ca == cb)
		while (ca--)
			cut[j++] = "rr";
	else if (ca)
		while (ca--)
			cut[j++] = "ra";
	else if (cb)
		while (cb--)
			cut[j++] = "rb";
}

char    **cut_down()
{
	char **cut;
	int i = 0, j = 0, ca = 0, cb = 0;

	cut = ft_memalloc(sizeof(char*) * (str_size(g_in) + 1));
	while (g_in[i])
	{
		if (strequ(g_in[i], "ra") || strequ(g_in[i], "rb"))
		{
			ca = 0;
			cb = 0;
			while (g_in[i] && (strequ(g_in[i], "ra")
						|| strequ(g_in[i], "rb")))
				strequ(g_in[i++], "ra") ? ca++ :  cb++;
			set_instructions(cut, j, ca, cb);
			if (ca < cb && ca && cb)
				j += cb;
			else if (ca > cb && ca && cb)
				j += ca;
			else if (ca == cb)
				j += ca;
			else if (ca)
				j += ca;
			else if (cb)
				j += cb;
		}
		else
			cut[j++] = g_in[i++];
	}
	return (cut);
}
