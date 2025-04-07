#include "enemy.h"

Enemy::Enemy(){

    enemyTextureL.loadFromFile("images/enemyL.png");
    enemyTextureR.loadFromFile("images/enemyR.png");

    enemySprite.setTexture(enemyTextureR);
    enemySprite.setPosition(300,735);

    enemySprite.setScale(sf::Vector2f(0.5f, 0.5f)); // размер спрайта

}

void Enemy::update(sf::View view, sf::Sprite heroSprite){

// добавление enemy

    if(enemyVecSprite.size() < 3){ // 3 enemy пока так

        for(int i = 0, random, direct; enemyVecSprite.size() < 3; i++){

            sf::Sprite enemySprite;

            enemySprite.setScale(sf::Vector2f(0.5f, 0.5f));

            do{
                random = rand() % int(view.getSize().x) + view.getCenter().x - view.getSize().x / 2; // rand % (b-a) + a
            }
            while(random > (heroSprite.getPosition().x - 400) && random < heroSprite.getPosition().x + 400);

            if(random < heroSprite.getPosition().x){
                direct = 1;
                enemySprite.setTexture(enemyTextureR);
            }
            else if(random > heroSprite.getPosition().x){
                direct = 0;
                enemySprite.setTexture(enemyTextureL);
            }

            enemySprite.setPosition(random, 735);
            enemyVecSprite.push_back(std::make_pair(enemySprite, direct));
        }
    }

    for(int sort = 0, count = 0; sort == 0;){ // пузырёк (enemyVecSprite)

        for(int i = 0; i < enemyVecSprite.size() - 1; i++){

            if(enemyVecSprite[i].first.getPosition().x > enemyVecSprite[i+1].first.getPosition().x){
                
                count++;

                auto enemyMax = enemyVecSprite[i].first; 
               
                enemyVecSprite[i].first.setPosition(enemyVecSprite[i+1].first.getPosition().x, enemyVecSprite[i+1].first.getPosition().y);
                enemyVecSprite[i+1].first.setPosition(enemyMax.getPosition().x, enemyMax.getPosition().y);
            }
        }

        if(count == 0){
            sort = 1;
        }
        else{
            sort = 0;
            count = 0;
        }
    }

// движение enemy

    for(int i = 0; i < enemyVecSprite.size(); i++){
        if(enemyVecSprite[i].first.getPosition().x < heroSprite.getPosition().x){
            enemyVecSprite[i].first.move(0.05,0);
            enemyVecSprite[i].first.setTexture(enemyTextureR);
        }
        else if(enemyVecSprite[i].first.getPosition().x > heroSprite.getPosition().x){
            enemyVecSprite[i].first.move(-0.05,0);
            enemyVecSprite[i].first.setTexture(enemyTextureL);
        }
    }
}
