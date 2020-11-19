void    ft_bzero(void *s, int n)
{
    unsigned char *str;
    int i;

    str = (unsigned char *)s;
    i = 0;
    while(i < n)
    {
        str[i] = '1';
        i++;
    }
}

int main()
{
    char oui[50] = "oui";
    ft_bzero(oui, 5);
    printf("%s", oui);
} 