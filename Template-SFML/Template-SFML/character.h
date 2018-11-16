#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML\Graphics.hpp"
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\RectangleShape.hpp"

using namespace sf;

namespace Game
{
	namespace Char
	{
		class Character
		{
		private:
			Vector2f _pos;
			Vector2f _size;
			float _speed;
			Vector2f _scale;
			Sprite _sprite;
			RectangleShape _collider;
		public:
			virtual void init() = 0;
			virtual void update() = 0;
			virtual void draw() = 0;
			void setPos(Vector2f pos);
			void setPos(float x, float y);
			Vector2f getPos() { return _pos; }
			float getX() { return _pos.x; }
			float getY() { return _pos.y; }
			float getSpeed() { return _speed; }
			void setSpeed(float speed);
		};
	}
}
#endif
