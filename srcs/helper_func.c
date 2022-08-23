
void ignore_all_spaces(char *str, int *i)
{
    while ((str[*i] == 32) || (str[*i] >= 9 && str[*i] <= 13))
        (*i)++;
}
