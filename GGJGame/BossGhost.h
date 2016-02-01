#ifndef BossGhost_H
#define BossGhost_H
#include "Map.h"
#include "Enemy.h"

class BossGhost : public Enemy
{
public:
	BossGhost();
	BossGhost(const BossGhost&);
	~BossGhost();

	void initialize(Map& map, sf::Texture &m_texture) override;
	void release() override;

	void update(float dt, Map &map);
	void draw(sf::RenderWindow&) override;

	BossGhost& operator=(const BossGhost&);

};
#endif