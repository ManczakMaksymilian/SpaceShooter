#ifndef ENEMY_H
#define ENEMY_H

#include<SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
private:
	sf::Texture e_texture;
	sf::Sprite e_sprite;
	
	unsigned pointCount;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initVariables();
	void initTexture();
	void initSprite();

public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif //!ENEMY_H
