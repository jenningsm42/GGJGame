#include "Game.h"
#include "Application.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::initialize(Application* app)
{
    app->getView()->setCenter(m_map.getWidth() / 2, m_map.getHeight() / 2);
	m_ritual.initialize(m_map);
	m_enemyPool.initialize(m_map);
    m_workerPool.initialize(m_map, app);
    m_weaponPool.initialize(m_map, app);
    
    m_announcements.setAnnouncement("You have 30 seconds to build your defences. Good luck!");
}

void Game::release()
{
}

void Game::update(float dt, Application* app)
{
    sf::View* view = app->getView();
    sf::Vector2i mpos = sf::Mouse::getPosition();
    
    const float scrollSpeed = 800.f;
    
    if(mpos.x > app->getWidth() - 100)
        view->move(scrollSpeed * float(100 - app->getWidth() + mpos.x) / 100.f * dt, 0);
    if(mpos.x < 100)
        view->move(-scrollSpeed * float(100 - mpos.x) / 100.f * dt, 0);
    if(mpos.y < 100)
        view->move(0, -scrollSpeed * float(100 - mpos.y) / 100.f * dt);
    if(mpos.y > app->getHeight() - 100)
        view->move(0, scrollSpeed * float(100 - app->getHeight() + mpos.y) / 100.f * dt);
    
    if(view->getCenter().x < app->getWidth() / 2)
        view->setCenter(app->getWidth() / 2, view->getCenter().y);
    if(view->getCenter().x > m_map.getWidth() - app->getWidth() / 2)
        view->setCenter(m_map.getWidth() - app->getWidth() / 2, view->getCenter().y);
    if(view->getCenter().y < app->getHeight() / 2)
        view->setCenter(view->getCenter().x, app->getHeight() / 2);
    if(view->getCenter().y > m_map.getHeight() - app->getHeight() / 2)
        view->setCenter(view->getCenter().x, m_map.getHeight() - app->getHeight() / 2);
    
    m_ritual.update(dt);
	m_enemyPool.update(dt, app, m_map, m_currency, m_announcements);
    m_workerPool.update(dt, app, m_map, m_weaponPool, m_enemyPool, m_currency, m_announcements);
    m_weaponPool.update(dt, app, m_map, m_enemyPool, m_projectilePool);
    m_projectilePool.update(dt);
    m_currency.update(app);
    m_announcements.update(app);
    
    
}

void Game::draw(sf::RenderWindow& window)
{
    m_map.draw(window);
    m_weaponPool.draw(window);
    m_workerPool.draw(window);
	m_enemyPool.draw(window);
    m_ritual.draw(window);
    m_projectilePool.draw(window);
    m_currency.draw(window);
    m_announcements.draw(window);
}