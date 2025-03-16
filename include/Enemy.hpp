#include "GameObject.hpp"

class Enemy : public GameObject
{
public:
    Enemy(const char* EnemyTextureSheetDir, SDL_Renderer* ren);
    ~Enemy();
    void Update() override;
    void Render();

private:
    
};