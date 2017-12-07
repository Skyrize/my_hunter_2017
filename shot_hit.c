/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** (shot_hit yeah !)
*/
#include "include/my.h"

void replace_sprite(float speed, seagull_t *target)
{
	if (speed < 0)
		target->position.x += 133;
	if (speed > 0)
		target->position.x -= 133;
}

void click_event_sprite_move(seagull_t *target, float x, float y)
{
	target->speed.x *= x;
	target->speed.y *= y;
	sfSprite_scale(target->sprite, target->invert);
	sfSprite_setPosition(target->sprite, target->position);
}

void check_clicked_time3(seagull_t *target, bullet_t *ammo)
{
	sfColor color = sfColor_fromRGBA(150, 150, 255, 125);

	switch (target->hits % 6) {
		case 5:
			replace_cross(target->death,
				5, (sfVector2f){1735.0, 875.0});
			target->speed.x = 0;
			target->speed.y = -0.3;
			target->position.y += 133;
			sfSprite_setPosition(target->sprite,
			target->position);
			sfSprite_setRotation(target->sprite, 180);
			sfSprite_setColor(target->sprite, color);
			break;
	}
}

void check_clicked_time2(seagull_t *target, bullet_t *ammo)
{
	switch (target->hits % 6) {
		case 3:
			click_event_sprite_move(target, -1.2, -1.2);
			replace_cross(target->death,
				3, (sfVector2f){1735.0, 570.0});
			break;
		case 4:
			target->speed.x *= 1.0;
			target->speed.y *= -1.2;
			replace_cross(target->death,
				4, (sfVector2f){1735.0, 735.0});
			break;
	}
	check_clicked_time3(target, ammo);
}

void check_clicked_time1(seagull_t *target, bullet_t *ammo)
{
	switch (target->hits % 6) {
		case 0:
			click_event_sprite_move(target, -2.0, 3.1);
			replace_cross(target->death,
				0, (sfVector2f){1735.0, 85.0});
			break;
		case 1:
			target->speed.x *= 1.4;
			target->speed.y *= -1.5;
			replace_cross(target->death,
				1, (sfVector2f){1735.0, 235.0});
			break;
		case 2:
			click_event_sprite_move(target, -1.4, -1.0);
			replace_cross(target->death,
				2, (sfVector2f){1735.0, 415.0});
			break;
	}
	check_clicked_time2(target, ammo);
}
