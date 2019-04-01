#include "push_swap.h"

static int	str_size(char **str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char    **cut_down()
{
    char **cut;
    int i = 0, j = 0, ca = 0, cb = 0;
    
    cut = malloc(sizeof(char*) * str_size(g_in));
    while (g_in[i])
    {
        if (strequ(g_in[i], "ra") || strequ(g_in[i], "rb"))
        {
            ca = 0;
            cb = 0;
            while (g_in[i] && (strequ(g_in[i], "ra")
                    || strequ(g_in[i], "rb")))
                strequ(g_in[i++], "ra") ? ca++ :  cb++;
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
        else
            cut[j++] = g_in[i++];
    }
    cut[j] = NULL;
    return (cut);
}
