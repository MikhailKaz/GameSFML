#include "level_1.h"
#include "SFML/Graphics/RenderWindow.hpp"

Level_1::Level_1(){

    posX[0] = hero.heroSprite.getPosition().x - 300; // для движения окна
    posX[1] = hero.heroSprite.getPosition().x + 300;
    
    platformTexture_1.loadFromFile("images/pngwing.png");
    platformTexture_2.loadFromFile("images/pngwingCut.png");

    platformSprite_1.setTexture(platformTexture_1);
    platformSprite_2.setTexture(platformTexture_2);

    platformSprite_1.setScale(sf::Vector2f(0.4f, 0.4f)); 
    platformSprite_2.setScale(sf::Vector2f(0.4f, 0.4f)); 

    for(int i = 0; i < 20; i++){
        platformSprite_1.setPosition(i*150,800);
        platforms.push_back(platformSprite_1);

        platformSprite_2.setPosition(i*150,950);
        platforms.push_back(platformSprite_2);

    }
}

std::vector <sf::Sprite> Level_1::getVecSprite(){

    return platforms;

}

void Level_1::update(sf::View& view, std::vector<sf::Event::KeyEvent> pressedKeys){

// update

    hero.update(pressedKeys);

    enemy.update(view, hero.heroSprite);

    bullet.update(view, pressedKeys, hero.getDirect(), hero.heroSprite);

// движеие окна

    if(hero.heroSprite.getPosition().x < posX[0]){
        view.move(-0.05,0);
        posX[0] -= 0.05;
        posX[1] -= 0.05;
    }
    else if(hero.heroSprite.getPosition().x > posX[1]){
        view.move(0.05,0);
        posX[1] += 0.05;
        posX[0] += 0.05;
    }

// проверка полёта bullet, удаление объектов (enemy,bullet)

    for (int j = 0; j < bullet.bulletVecSprite.size(); j++) {
        
        int step, start, end;
            
        if (bullet.bulletVecSprite[j].second == 1) {
            start = 0;
            end = enemy.enemyVecSprite.size();
            step = 1;
        } 
        else if (bullet.bulletVecSprite[j].second == 0) {
            start = enemy.enemyVecSprite.size() - 1;
            end = -1;
            step = -1;
        }

        for (int i = start; i != end; i += step) {

            if (enemy.enemyVecSprite[i].first.getPosition().x + 60 >= bullet.bulletVecSprite[j].first.getPosition().x 
                && enemy.enemyVecSprite[i].first.getPosition().x <= bullet.bulletVecSprite[j].first.getPosition().x) {

                if (enemy.enemyVecSprite[i].first.getPosition().y + 60 >= bullet.bulletVecSprite[j].first.getPosition().y &&
                        enemy.enemyVecSprite[i].first.getPosition().y <= bullet.bulletVecSprite[j].first.getPosition().y) {

                    enemy.enemyVecSprite.erase(enemy.enemyVecSprite.begin() + i);
                    bullet.bulletVecSprite.erase(bullet.bulletVecSprite.begin() + j);
                }
            }
        }
    }

// проверка на game over

    for (auto enemySprite : enemy.enemyVecSprite){ // 70/60/50 хитбоксы
        
        if(enemySprite.first.getPosition().x + 70 >= hero.heroSprite.getPosition().x && 
                enemySprite.first.getPosition().x <= hero.heroSprite.getPosition().x){

            if(enemySprite.first.getPosition().y <= hero.heroSprite.getPosition().y &&
                    enemySprite.first.getPosition().y + 60 >= hero.heroSprite.getPosition().y){
                exit(0);
            }

            else if(enemySprite.first.getPosition().y <= hero.heroSprite.getPosition().y + 60 &&
                    enemySprite.first.getPosition().y + 60 >= hero.heroSprite.getPosition().y + 60){
                exit(0);
            }
        }
        
        else if(enemySprite.first.getPosition().x + 70 >= hero.heroSprite.getPosition().x + 50 && 
                enemySprite.first.getPosition().x <= hero.heroSprite.getPosition().x + 50){
            
            if(enemySprite.first.getPosition().y <= hero.heroSprite.getPosition().y &&
                    enemySprite.first.getPosition().y + 60 >= hero.heroSprite.getPosition().y){
                exit(0);
            }

            else if(enemySprite.first.getPosition().y <= hero.heroSprite.getPosition().y + 60 &&
                    enemySprite.first.getPosition().y + 60 >= hero.heroSprite.getPosition().y + 60){
                exit(0);
            }
       }
    }
}

void Level_1::draw(sf::RenderWindow& window){

    for(auto bullet : bullet.bulletVecSprite){
        window.draw(bullet.first);
    }

    for(auto platform : getVecSprite()){
        window.draw(platform);
    }

    for(auto var : enemy.enemyVecSprite){
        window.draw(var.first);
    }

    window.draw(hero.heroSprite);

}
