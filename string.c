#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **split(char *str, char delimiter)
{
	char *tempWords		= NULL;
	char **tempStoreWord = NULL;

	int i, length = strlen(str);
	int a, b, flag = 0;

	a = b = 1;
	for(i = 0; i < length; i++)
	{
		if(str[i] == delimiter)
		{
			if(flag)
			{
				tempWords[a - 1] = '\0';

				tempStoreWord = (char **) realloc(tempStoreWord, b * sizeof(char *));
				tempStoreWord[b++ - 1] = tempWords;

				a = 1; flag = 0;
			}
		}
		else
		{
			if(flag)
			{
				tempWords = (char *) realloc(tempWords, (a + 1) * sizeof(char));
				tempWords[a++ - 1] = str[i];
			}
			else
			{
				tempWords = (char *) calloc(1, sizeof(char));
				tempWords[a++ -1] = str[i];

				flag = 1;
			}
		}
	}

	if(flag)
	{
		tempWords[a++] = '\0';

		tempStoreWord = (char **) realloc(tempStoreWord, b * sizeof(char *));
		tempStoreWord[b - 1] = tempWords;

		flag = 0;
	}

	return tempStoreWord;
}

int equals(char *str1, char *str2)
{
	int i, length = strlen(str1);

	if(length == strlen(str2))
	{
		for(i = 0; i < length; i++)
		{
			if(str1[i] != str2[i])
				return 0;
		}

		return 1;
	}

	return 0;
}

char *toLowerCase(char *str)
{
	int i, length = strlen(str);

	for(i = 0; i < length; i++)
	{
		if(isalpha(str[i]))
		{
			if(64 < str[i] && str[i] < 91)
				str[i] += 32;
		}
	}

	return str;
}

char *toUpperCase(char *str)
{
	int i, length = strlen(str);

	for(i = 0; i < length; i++)
	{
		if(isalpha(str[i]))
		{
			if(96 < str[i] && str[i] < 123)
				str[i] -= 32;
		}
	}

	return str;
}

char *reverse(char *str)
{
	int a = 0, b = strlen(str);
	char *temp = (char *) malloc(b * sizeof(char));

	for(; a < strlen(str); a++, b--)
	{
		temp[a] = str[b - 1];
	}
	temp[a] = '\0';

	return temp;
}

int indexOf(char *str, char *target)
{
	int max_s = strlen(str);
	int max_t = strlen(target);

	int a, b, flag;

	for(a = 0; a < ( ( max_s - max_t ) + 1 ); a++)
	{
		b  = 0;
		flag = 1;

		if(str[a] == target[b])
		{
			for( ; b < max_t; b++)
			{
				if(str[a + b] != target[b])
				{
					flag = 0;
				}
			}

			if(flag)
			{
				return a;
			}
		}
	}

	return -1;
}

char *getString()
{
    int i = 0;    // counter
    char temp, *str = NULL;

    while((temp = getchar()) != '\n')
    {
        str = (char *) realloc(str, ++i * sizeof(char));
        str[i - 1] = temp;
    }

    str = (char *) realloc(str, ++i * sizeof(char));
    str[i - 1] = '\0';

    return str;
}

int endsWith(char *str, char *pattern)
{
    int x = strlen(str) - 1;
    int y = strlen(pattern) - 1;

    if(x == -1 || y == -1)
        return 0;

    if(y < x)
    {
        for(; y >= 0; x--, y--)
        {
            if(str[x] != pattern[y])
                return 0;
        }

        return 1;
    }

    return 0;
}

int startsWith(char *str, char *pattern)
{
    int i = 0;    // counter

    int x = strlen(str);
    int y = strlen(pattern);

    if(x == -1 || y == -1)
        return 0;

    if(y < x)
    {
        for(; i < y; i++)
        {
            if(pattern[i] != str[i])
                return 0;
        }

        return 1;
    }

    return 0;
}