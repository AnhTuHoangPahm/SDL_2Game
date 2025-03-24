#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "GameObject.hpp"

class Enemy : public GameObject
{
public:
    Enemy(const char* EnemyTextureSheetDir, SDL_Renderer* ren);
    ~Enemy();
    void Update() override;
    void Render() override;
    void RandomMovement();
    void Attack();

private:
    
};

#endif