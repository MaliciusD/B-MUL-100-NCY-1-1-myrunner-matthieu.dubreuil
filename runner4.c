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

void event(struct_t *runner)
{
    while (sfRenderWindow_pollEvent(runner->window, &runner->event)) {
        if (runner->event.type == sfEvtClosed)
            sfRenderWindow_close(runner->window);
        runner->posx_mouse = runner->event.mouseButton.x;
        runner->posy_mouse = runner->event.mouseButton.y;
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            sfRenderWindow_close(runner->window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (runner->posx_mouse >= 180 && runner->posx_mouse <= 597 &&
            runner->posy_mouse >= 225 && runner->posy_mouse <= 325)
                runner->menu = 1;
            if (runner->menu == 0)
                if (runner->posx_mouse >= 1182 && runner->posx_mouse <= 1814 &&
                runner->posy_mouse >= 96 && runner->posy_mouse <= 462)
                    sfRenderWindow_close(runner->window);
        }
    }
}

void display_game2(struct_t *runner)
{
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

void display_game3(struct_t *runner)
{
    display_game2(runner);
    if (runner->nbr_x == 4) {
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc1, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc2, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc3, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc4, NULL);
    } if (runner->nbr_x == 5) {
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc1, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc2, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc3, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc4, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc5, NULL);
    } if (runner->nbr_x >= 6) {
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc1, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc2, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc3, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc4, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc5, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc6, NULL);
    }
}

void display_game(struct_t *runner)
{
    sfRenderWindow_display(runner->window);
    display_game3(runner);
    if (runner->db_jmp == 0)
        sfRenderWindow_drawSprite(runner->window, runner->sprite_player, NULL);
    if (runner->db_jmp > 0)
        sfRenderWindow_drawSprite(runner->window, runner->sprite_jump, NULL);
    sfSprite_setPosition(runner->sprite_bg1, runner->pos_prlx1);
    sfSprite_setPosition(runner->sprite_bg3, runner->pos_prlx3);
    sfSprite_setPosition(runner->sprite_bg2, runner->pos_prlx2);
    sfSprite_setPosition(runner->sprite_player, runner->pos_player);
    sfSprite_setPosition(runner->sprite_bloc1, runner->pos_bloc1);
    sfSprite_setPosition(runner->sprite_bloc2, runner->pos_bloc2);
    sfSprite_setPosition(runner->sprite_bloc3, runner->pos_bloc3);
    sfSprite_setPosition(runner->sprite_bloc4, runner->pos_bloc4);
    sfSprite_setPosition(runner->sprite_bloc5, runner->pos_bloc5);
    sfSprite_setPosition(runner->sprite_bloc6, runner->pos_bloc6);
    sfSprite_setPosition(runner->sprite_jump, runner->pos_player);
    sfSprite_setPosition(runner->sprite_vie, runner->pos_vie);
    sfSprite_setPosition(runner->sprite_b, runner->pos_b);
    sfSprite_setPosition(runner->sprite_pause, runner->pos_pause);
}

void display_menu(struct_t *runner)
{
    sfRenderWindow_display(runner->window);
    sfRenderWindow_drawSprite(runner->window, runner->sprite_bgmenu, NULL);
}