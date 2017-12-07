/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** (display and calc part my_hunter)
*/
#include "include/my.h"

void gettime(ctime_t *clocker)
{
	clocker->timer = sfClock_getElapsedTime(clocker->clock);
	clocker->seconds = clocker->timer.microseconds / 1000000.0;
}

void destroy_and_free_musics(seagull_t *target, my_w_t *window)
{
	sfMusic_destroy(target->shoot);
	sfMusic_destroy(window->loser);
	sfMusic_destroy(window->tada);
}

void destroy_and_free(my_w_t *window, seagull_t *target,
	ctime_t *clocker, bullet_t *ammo)
{
	for (int i = 0 ; i < 6 ; i++) {
		sfSprite_destroy(target->death[i].sprite);
		sfTexture_destroy(target->death[i].texture);
	}
	for (int i = 0 ; i < 8 ; i++) {
		sfSprite_destroy(ammo[i].sprite);
		sfTexture_destroy(ammo[i].texture);
	}
	sfClock_destroy(clocker->clock);
	sfSprite_destroy(target->sprite);
	sfSprite_destroy(window->wall);
	sfSprite_destroy(window->lose);
	sfSprite_destroy(window->win);
	sfTexture_destroy(target->texture);
	sfTexture_destroy(window->waller);
	sfTexture_destroy(window->lose_tx);
	sfTexture_destroy(window->win_tx);
	sfRenderWindow_destroy(window->window);
	free(target->death);
	free(ammo);
}
