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

void create_sprite(struct_t *runner)
{
    create_sprite5(runner);
    sfSprite_setScale(runner->sprite_player, (sfVector2f) {2, 2});
    sfSprite_setScale(runner->sprite_jump, (sfVector2f) {2, 2});
    sfSprite_setScale(runner->sprite_vie, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(runner->sprite_bloc1, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(runner->sprite_bloc2, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(runner->sprite_bloc3, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(runner->sprite_bloc4, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(runner->sprite_bloc5, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(runner->sprite_bloc6, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(runner->sprite_b, (sfVector2f) {0.25, 0.25});
    sfSprite_setScale(runner->sprite_pause, (sfVector2f) {0.25, 0.25});
}

void create_fromfile2(struct_t *runner)
{
    runner->texture_bgmenu =
    sfTexture_createFromFile("ressources/menu_image.jpg", NULL);
    runner->texture_end =
    sfTexture_createFromFile("ressources/victory.png", NULL);
    runner->texture_bg1 =
    sfTexture_createFromFile("ressources/prlx.png", NULL);
    runner->texture_bg2 =
    sfTexture_createFromFile("ressources/prlx2.png", NULL);
    runner->texture_bg3 =
    sfTexture_createFromFile("ressources/prlx3.png", NULL);
    runner->texture_player =
    sfTexture_createFromFile("ressources/stevos.png", NULL);
    runner->texture_block1 =
    sfTexture_createFromFile("ressources/magma.png", NULL);
    runner->texture_block2 =
    sfTexture_createFromFile("ressources/magma.png", NULL);
    runner->texture_block3 =
    sfTexture_createFromFile("ressources/magma.png", NULL);
    runner->texture_block4 =
    sfTexture_createFromFile("ressources/magma.png", NULL);
}

void create_fromfile(struct_t *runner)
{
    create_fromfile2(runner);
    runner->texture_block5 =
    sfTexture_createFromFile("ressources/magma.png", NULL);
    runner->texture_block6 =
    sfTexture_createFromFile("ressources/magma.png", NULL);
    runner->texture_jump =
    sfTexture_createFromFile("ressources/stv_jmp.png", NULL);
    runner->texture_vie =
    sfTexture_createFromFile("ressources/health.png", NULL);
    runner->texture_nul =
    sfTexture_createFromFile("ressources/end_image.jpg", NULL);
    runner->texture_b =
    sfTexture_createFromFile("ressources/rectangle.png", NULL);
    runner->texture_pause =
    sfTexture_createFromFile("ressources/pause.png", NULL);
}

void set_texture2(struct_t *runner)
{
    sfSprite_setTexture(runner->sprite_bgmenu,
    runner->texture_bgmenu, sfTrue);
    sfSprite_setTexture(runner->sprite_end,
    runner->texture_end, sfTrue);
    sfSprite_setTexture(runner->sprite_bg1,
    runner->texture_bg1, sfTrue);
    sfSprite_setTexture(runner->sprite_bg2,
    runner->texture_bg2, sfTrue);
    sfSprite_setTexture(runner->sprite_bg3,
    runner->texture_bg3, sfTrue);
    sfSprite_setTexture(runner->sprite_player,
    runner->texture_player, sfTrue);
    sfSprite_setTexture(runner->sprite_bloc1,
    runner->texture_block1, sfTrue);
    sfSprite_setTexture(runner->sprite_bloc2,
    runner->texture_block2, sfTrue);
    sfSprite_setTexture(runner->sprite_bloc3,
    runner->texture_block3, sfTrue);
    sfSprite_setTexture(runner->sprite_bloc4,
    runner->texture_block4, sfTrue);
}

void set_texture(struct_t *runner)
{
    set_texture2(runner);
    sfSprite_setTexture(runner->sprite_bloc5,
    runner->texture_block5, sfTrue);
    sfSprite_setTexture(runner->sprite_bloc6,
    runner->texture_block6, sfTrue);
    sfSprite_setTexture(runner->sprite_jump,
    runner->texture_jump, sfTrue);
    sfSprite_setTexture(runner->sprite_vie,
    runner->texture_vie, sfTrue);
    sfSprite_setTexture(runner->sprite_nul,
    runner->texture_nul, sfTrue);
    sfSprite_setTexture(runner->sprite_b,
    runner->texture_b, sfTrue);
    sfSprite_setTexture(runner->sprite_pause,
    runner->texture_pause, sfTrue);
    runner->player_animation = (sfIntRect) {0, 0, 37, 69};
}