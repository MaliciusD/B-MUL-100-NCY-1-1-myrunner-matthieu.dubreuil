/*
** EPITECH PROJECT, 2020
** runner
** File description:
** runner
*/

#include "include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void display_gm2(struct_t *runner)
{
    if (runner->menu == 0)
        display_menu(runner);
    if (runner->menu == 1) {
        runner->count_reset = 0;
        display_game(runner);
    }
    if (runner->menu == 2) {
        sfRenderWindow_display(runner->window);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_end, NULL);
    }
    if (runner->vie < 0)
        runner->menu = 3;
}

void display_gm3(struct_t *runner)
{
    sfMusic_stop(runner->music_death);
    runner->pos_player.x = 50;
    runner->pos_player.y = 815;
    runner->pos_bloc1.x = 5000;
    runner->pos_bloc2.x = 5000;
    runner->pos_bloc3.x = 5000;
    runner->pos_bloc4.x = 5000;
    runner->pos_bloc5.x = 5000;
    runner->pos_bloc6.x = 5000;
    if (runner->nbr_x == 1)
        runner->pos_bloc1.x = my_getnbr(runner->stock[0]);
    if (runner->nbr_x == 2) {
        runner->pos_bloc1.x = my_getnbr(runner->stock[0]);
        runner->pos_bloc2.x = my_getnbr(runner->stock[1]);
    }
    if (runner->nbr_x == 3) {
        runner->pos_bloc1.x = my_getnbr(runner->stock[0]);
        runner->pos_bloc2.x = my_getnbr(runner->stock[1]);
        runner->pos_bloc3.x = my_getnbr(runner->stock[2]);
    }
}

void display_gm4(struct_t *runner)
{
    if (runner->nbr_x == 4) {
        runner->pos_bloc1.x = my_getnbr(runner->stock[0]);
        runner->pos_bloc2.x = my_getnbr(runner->stock[1]);
        runner->pos_bloc3.x = my_getnbr(runner->stock[2]);
        runner->pos_bloc4.x = my_getnbr(runner->stock[3]);
    } if (runner->nbr_x == 5) {
        runner->pos_bloc1.x = my_getnbr(runner->stock[0]);
        runner->pos_bloc2.x = my_getnbr(runner->stock[1]);
        runner->pos_bloc3.x = my_getnbr(runner->stock[2]);
        runner->pos_bloc4.x = my_getnbr(runner->stock[3]);
        runner->pos_bloc5.x = my_getnbr(runner->stock[4]);
    }
    if (runner->nbr_x >= 6) {
        runner->pos_bloc1.x = my_getnbr(runner->stock[0]);
        runner->pos_bloc2.x = my_getnbr(runner->stock[1]);
        runner->pos_bloc3.x = my_getnbr(runner->stock[2]);
        runner->pos_bloc4.x = my_getnbr(runner->stock[3]);
        runner->pos_bloc5.x = my_getnbr(runner->stock[4]);
        runner->pos_bloc6.x = my_getnbr(runner->stock[5]);
    }
}

void display_gm5(struct_t *runner)
{
    if (runner->menu == 3) {
        sfRenderWindow_display(runner->window);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_nul, NULL);
        sfMusic_play(runner->music_death);
        if (sfKeyboard_isKeyPressed(sfKeyP) && runner->count_reset == 0) {
            display_gm3(runner);
            display_gm4(runner);
            runner->vie = 1;
            runner->speed = 0;
            runner->to_end = 0;
            runner->count_block = 0;
            runner->menu = 1;
            runner->count_reset = 1;
            runner->s = 0;
        }
    } if (sfKeyboard_isKeyPressed(sfKeyX) && runner->menu == 1)
        runner->menu = 4;
    if (sfKeyboard_isKeyPressed(sfKeyC) && runner->menu == 4) {
            runner->menu = 1;
    }
}

void display_gm6(struct_t *runner)
{
    sfRenderWindow_display(runner->window);
    sfRenderWindow_drawSprite(runner->window, runner->sprite_bg1, NULL);
    sfRenderWindow_drawSprite(runner->window, runner->sprite_bg3, NULL);
    sfRenderWindow_drawSprite(runner->window, runner->sprite_bg2, NULL);
    sfRenderWindow_drawSprite(runner->window, runner->sprite_b, NULL);
    sfRenderWindow_drawText(runner->window, runner->scoros, NULL);
    if (runner->vie == 1)
        sfRenderWindow_drawSprite(runner->window, runner->sprite_vie, NULL);
    if (runner->nbr_x == 1)
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc1, NULL);
    if (runner->nbr_x == 2) {
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc1, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc2, NULL);
    }
    if (runner->nbr_x == 3) {
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc1, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc2, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc3, NULL);
    }
}