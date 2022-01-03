#include "Enemy.h"

void Enemy::initVariables()
{
	this->pointCount = 5;
	this->type = 0;
	this->speed = 1.f;
	this->hpMax = static_cast<int>(this->pointCount);
	this->hp = this->hpMax;
	this->damage = this->pointCount;
	this->points = this->pointCount;
}

void Enemy::initTexture()
{
	if (!this->e_texture.loadFromFile("Textures/enemy.png"))
	{
		std::cout << "ERROR::ENEMY::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Enemy::initSprite()
{
	//Set the texture to the sprite
	this->e_sprite.setTexture(this->e_texture);

	//Resize the sprite
	this->e_sprite.scale(0.2f, 0.2f);
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();

	this->e_sprite.setPosition(pos_x, pos_y);
}


Enemy::~Enemy()
{

}

//Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->e_sprite.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

//Functions
void Enemy::update()
{
	this->e_sprite.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->e_sprite);
}
