/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** (initializer 2)
*/
#include "include/my.h"

redcross_t *init_cross(void)
{
	redcross_t *cross = malloc(sizeof(redcross_t) * 6);
	sfVector2f start = {1800, 1000};
	sfColor invisible = sfColor_fromRGBA(0, 0, 0, 0);
	sfColor visible = sfColor_fromRGBA(255, 255, 255, 255);
	sfVector2f rescale = {0.15, 0.15};

	if (cross == NULL)
		exit (84);
	for (int i = 0 ; i < 6 ; i++) {
		cross[i].sprite = sfSprite_create();
		cross[i].texture = sfTexture_createFromFile("cross.png", NULL);
		cross[i].color = visible;
		sfSprite_setTexture(cross[i].sprite, cross[i].texture, sfTrue);
		sfSprite_setColor(cross[i].sprite, invisible);
		sfSprite_setPosition(cross[i].sprite, start);
		sfSprite_scale(cross[i].sprite, rescale);
	}
	return (cross);
}

seagull_t init_seagull(float x, float y)
{
	seagull_t seagull;
	sfIntRect rect = {0, 0, 133, 133};
	sfVector2f speed = {x, y};

	seagull.death = init_cross();
	seagull.sprite = sfSprite_create();
	seagull.texture = sfTexture_createFromFile("seagull.png", NULL);
	seagull.shoot = sfMusic_createFromFile("shoot_reload.ogg");
	seagull.rect = rect;
	seagull.speed = speed;
	seagull.invert = (sfVector2f){-1, 1};
	seagull.position = (sfVector2f){0, 0};
	seagull.shots = 0;
	seagull.hits = 0;
	seagull.able = 1;
	sfSprite_setTexture(seagull.sprite, seagull.texture, sfTrue);
	sfSprite_setPosition(seagull.sprite, (sfVector2f){200, 300});
	sfSprite_scale(seagull.sprite, seagull.invert);
	sfSprite_setTextureRect(seagull.sprite, seagull.rect);
	return (seagull);
}

ctime_t init_timer(void)
{
	ctime_t clock;

	clock.clock = sfClock_create();
	clock.seconds = 0;
	return (clock);
}
