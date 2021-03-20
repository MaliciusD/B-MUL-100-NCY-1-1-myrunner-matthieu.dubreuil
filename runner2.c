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

char *my_getnbrinverse(int tmp, int k, int trans, int is_neg)
{
    char *int_chared = malloc(sizeof(char *));
    char *intneg_chared = malloc(sizeof(char *) * (11));
    if (tmp == 0)
        return ("0");
    else { if (tmp < 0) {
            tmp = tmp * -1;
            is_neg = 1;
        }
        for (; tmp > 0; k++) { trans = tmp % 10;
            tmp = tmp / 10;
            int_chared[k] = trans + 48;
        } int_chared = my_revstr(int_chared);
        if (is_neg != 0) {
            for (int i = 0; int_chared[i] != '\0'; i++) {
                intneg_chared[0] = '-';
                intneg_chared[i + 1] = int_chared[i];
            } return (intneg_chared);
        } else
            return (int_chared); }
}

void create_sprite2(struct_t *runner)
{
    runner->sprite_bgmenu = sfSprite_create();
    runner->sprite_end = sfSprite_create();
    runner->sprite_bg1 = sfSprite_create();
    runner->sprite_bg2 = sfSprite_create();
    runner->sprite_bg3 = sfSprite_create();
    runner->sprite_player = sfSprite_create();
    runner->sprite_bloc1 = sfSprite_create();
    runner->sprite_bloc2 = sfSprite_create();
    runner->sprite_bloc3 = sfSprite_create();
    runner->sprite_bloc4 = sfSprite_create();
    runner->sprite_bloc5 = sfSprite_create();
    runner->sprite_bloc6 = sfSprite_create();
    runner->sprite_jump = sfSprite_create();
    runner->sprite_pause = sfSprite_create();
    runner->sprite_vie = sfSprite_create();
    runner->sprite_nul = sfSprite_create();
    runner->music_background =
    sfMusic_createFromFile("ressources/music_bg.ogg");
    runner->music_hit =
    sfMusic_createFromFile("ressources/music_hit.ogg");
}

void create_sprite3(struct_t *runner)
{
    create_sprite2(runner);
    runner->music_death =
    sfMusic_createFromFile("ressources/music_death.ogg");
    runner->scoros = sfText_create();
    runner->sprite_b = sfSprite_create();
    runner->font = sfFont_createFromFile("ressources/bunny.ttf");
    sfText_setFont(runner->scoros, runner->font);
    runner->pos_bloc1.x = 5000;
    runner->pos_bloc2.x = 5000;
    runner->pos_bloc3.x = 5000;
    runner->pos_bloc4.x = 5000;
    runner->pos_bloc5.x = 5000;
    runner->pos_bloc6.x = 5000;
    runner->pos_player.x = 50;
    runner->pos_player.y = 815;
    runner->pos_bloc1.y = 875;
    runner->pos_bloc2.y = 875;
    runner->pos_bloc3.y = 875;
    runner->pos_bloc4.y = 875;
    runner->pos_bloc5.y = 875;
}

void create_sprite4(struct_t *runner)
{
    create_sprite3(runner);
    runner->pos_vie.x = 1500;
    runner->pos_bloc6.y = 875;
    runner->pos_pause.x = 800;
    runner->pos_pause.y = 440;
    runner->pos_b.y = -25;
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

void create_sprite5(struct_t *runner)
{
    create_sprite4(runner);
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
    } if (runner->nbr_x >= 6) {
        runner->pos_bloc1.x = my_getnbr(runner->stock[0]);
        runner->pos_bloc2.x = my_getnbr(runner->stock[1]);
        runner->pos_bloc3.x = my_getnbr(runner->stock[2]);
        runner->pos_bloc4.x = my_getnbr(runner->stock[3]);
        runner->pos_bloc5.x = my_getnbr(runner->stock[4]);
        runner->pos_bloc6.x = my_getnbr(runner->stock[5]);
    }
}
