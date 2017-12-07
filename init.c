/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** (initializing part)
*/
#include "include/my.h"

void init_my_window2(my_w_t *window)
{
	sfSprite_setTexture(window->lose, window->lose_tx, sfTrue);
	sfSprite_setTexture(window->win, window->win_tx, sfTrue);
	sfSprite_setTexture(window->mouse, window->mouse_tx, sfTrue);
	sfSprite_setPosition(window->lose, (sfVector2f){550, 300});
	sfSprite_setPosition(window->win, (sfVector2f){500, 275});
	sfSprite_setColor(window->lose, (sfColor){0, 0, 0, 0});
	sfSprite_setColor(window->win, (sfColor){0, 0, 0, 0});
	sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
	sfSprite_scale(window->mouse, (sfVector2f){0.3, 0.3});
}

my_w_t init_my_window(void)
{
	my_w_t window;

	window.window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
		"Seagull.Hunt", sfResize | sfClose, NULL);
	window.wall = sfSprite_create();
	window.waller = sfTexture_createFromFile("woodboard.png", NULL);
	sfSprite_setTexture(window.wall, window.waller, sfTrue);
	window.lose = sfSprite_create();
	window.lose_tx = sfTexture_createFromFile("lose.png", NULL);
	window.loser = sfMusic_createFromFile("loser.ogg");
	window.win = sfSprite_create();
	window.win_tx = sfTexture_createFromFile("win.png", NULL);
	window.mouse = sfSprite_create();
	window.mouse_tx = sfTexture_createFromFile("target.png", NULL);
	window.tada = sfMusic_createFromFile("tada.ogg");
	init_my_window2(&window);
	return (window);
}

bullet_t *init_ammos(void)
{
	bullet_t *ammo = malloc(sizeof(bullet_t) * 8);
	sfColor invisible = sfColor_fromRGBA(0, 0, 0, 0);
	sfColor visible = sfColor_fromRGBA(255, 255, 255, 255);
	sfVector2f rescale = {0.15, 0.15};

	if (ammo == NULL)
		exit (84);
	for (int i = 0 ; i < 8 ; i++) {
		ammo[i].sprite = sfSprite_create();
		ammo[i].texture = sfTexture_createFromFile("bullet.png", NULL);
		ammo[i].color = invisible;
		sfSprite_setTexture(ammo[i].sprite, ammo[i].texture, sfTrue);
		sfSprite_setColor(ammo[i].sprite, visible);
		sfSprite_setPosition(ammo[i].sprite,
			(sfVector2f){330.0 + (float)i * 140, 950.0});
		sfSprite_scale(ammo[i].sprite, rescale);
	}
	return (ammo);
}
