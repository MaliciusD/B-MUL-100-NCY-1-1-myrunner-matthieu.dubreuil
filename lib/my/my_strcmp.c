/*
** EPITECH PROJECT, 2020
** str
** File description:
** cmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i++);
    return (s1[i] - s2[i]);
}