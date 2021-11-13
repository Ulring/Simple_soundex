#include <stdio.h>
#include <stdlib.h>
int        ft_strlen(const char* s)
{
    int    count;

    count = 0;
    while (s[count])
        count++;
    return (count);
}

char    ft_toupper(char str)
{
    if ((str >= 'a') && (str <= 'z'))
        return (str - 32);
    return (str);
}

char* ft_soundex(char* name)
{
    int       string_index;
	int i;
	int length;
    char      c;
	char *string;
	string = (char*)malloc(sizeof (char) * 5);
    //                   ABCDEFGHIJKLMNOPQRSTUVWXYZ
    char equivalent[] = "01230120022455012623010202";
    string[0] = ft_toupper(name[0]);
    string_index = 1; 
	i = 1;
    length = ft_strlen(name);
    while (i < length)
    {
        //Note(Anass): substracting 65 to get the index
        c = ft_toupper(name[i]) - 65;
        if (c >= 0 && c <= 25)
        {
            if (equivalent[c] != 48)
            {
                if (equivalent[c] != string[string_index - 1])
                {
                    string[string_index] = equivalent[c];
                    string_index++;
                }
                if (string_index > 3)
                {
                    break;
                }
            }
        }
        i++;
    }
    if (string_index <= 3)
    {
        while (string_index <= 3)
        {
            string[string_index] = '0';
            string_index++;
        }
    }
    string[string_index] = '\0';
    return string;
}

int main(void) {
    printf("%s", ft_soundex("anass"));
}
