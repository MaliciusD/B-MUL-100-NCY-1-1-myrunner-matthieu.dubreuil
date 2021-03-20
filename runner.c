/*
** EPITECH PROJECT, 2020
** runner
** File description:
** main
*/

#include "include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void destroy(struct_t *runner)
{
    sfRenderWindow_destroy(runner->window);
    sfMusic_destroy(runner->music_background);
    sfMusic_destroy(runner->music_hit);
    sfMusic_destroy(runner->music_death);
}

void content2(struct_t *runner, char *buffer, int stock_nbr, int pos_en)
{
    int p = 0;
    for (int i = 0; buffer[i] != '\n'; i++)
        runner->size_line++;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'o')
            runner->stop += 120;
        if (buffer[i] == 'x') {
            runner->nbr_x++;
            buffer[i] = 'p';
            for (; buffer[i] != '\n'; i--)
                pos_en++;
            stock_nbr = pos_en * 120;
            runner->stock[p] = my_getnbrinverse(stock_nbr, 0, 0, 0);
            stock_nbr = 0;
            pos_en = 0;
            p++;
        }
    }
}

void content3(struct_t *runner, char **av, int size_buffer, int pos_en)
{
    int stock_nbr = 0;
    int a = 0;
    int op = open(av[1], O_RDONLY);
    if (op < 0 && av[1][0] != '-') {
        my_putstr("invalid map\n");
        return (84);
    } if (op < 0 && av[1][0] == '-')
        return (84);
    char *buffer = malloc(sizeof(char) * (size_buffer + 1));
    a = read(op, buffer, size_buffer);
    content2(runner, buffer, stock_nbr, pos_en);
    sfVideoMode video_mode = {1920, 1080, 32};
    runner->window = sfRenderWindow_create
        (video_mode, "my_runner", sfFullscreen | sfClose | sfResize, NULL);
    runner->clock = sfClock_create();
    create_sprite(runner);
    create_fromfile(runner);
    set_texture(runner);
    game_loop(runner);
    destroy(runner);
}

void my_helper(void)
{
    my_printf("Pour lancer le jeu: ./my_runner map\n\n");
    my_printf("COMMANDES:\n    ");
    my_printf("Espace | pour sauter\n    Clic gauche | Double saut \
    (lorsque vous êtes au plus haut du saut normal)\n    ");
    my_printf("X | pour mettre le jeu en pause\n    C | pour relancer \
    le jeu dans le menu pause\n    ");
    my_printf("Q | pour quitter le jeu\n    ");
    my_printf("P | pour relancer le jeu quand vous avez perdu\n");
}

int main(int ac, char **av)
{
    if (ac == 1) {
        my_putstr("invalid map\n");
        return (84); }
    struct_t *runner = malloc(sizeof(struct_t));
    if (av[1][0] == '-' && av[1][1] == 'h')
        my_helper();
    runner->s = -1;
    int d = 0;
    runner->stock = malloc(sizeof(char *) * (100));
    for (int i = 0; i < 100; i++)
        runner->stock[i] = malloc(sizeof(char) * (100));
    int pos_en = 0;
    struct stat buf;
    int size_buffer = 0;
    runner->vie = 1;
    stat(av[1], &buf);
    size_buffer = buf.st_size;
    if (size_buffer <= 0)
        return (84);
    content3(runner, av, size_buffer, pos_en);
}