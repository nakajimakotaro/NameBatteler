//
// Created by harus on 2018/01/12.
//

#include "arrowBullet.h"
#include "../core/game.h"
#include "camera.h"

ArrowBullet::ArrowBullet(std::weak_ptr<Scene> scene, double x, double y, GameObject::Type ownerType, double angle) :
        Bullet(scene, x, y, ownerType),
        angle(angle)
{

}

void ArrowBullet::start() {
    auto rideCollider = std::shared_ptr<Collider>(new Collider(this->scene, 0, 0, 1, 1, [this](std::weak_ptr<Collider> obj, Rect overarea){

        if(obj.lock()->getParent().use_count() == 0){
            return;
        }
        if(
                obj.lock()->getParent().lock()->getType() == GameObject::Type::BLOCK ||
                obj.lock()->getParent().lock()->getType() == GameObject::Type::MOVEBLOCK
                ){
            this->scene.lock()->removeObject(shared_from_this());
        }
    }));
    this->collider = rideCollider;
    this->addChild(rideCollider);
    this->scene.lock()->collision.addObjectRequire(rideCollider);
}

void ArrowBullet::update() {
    double speed = 3;
    this->localX += cos(this->angle) * speed;
    this->localY += sin(this->angle) * speed;
    auto camera = this->scene.lock()->getObject<Camera>(Type::CAMERA);
    if(
            camera->localX - 30 > this->localX ||
            camera->localY - 30 > this->localY||
            camera->localX + Game::get()->screen.WIDTH + 30 < this->localX ||
            camera->localY + Game::get()->screen.HEIGHT + 30 < this->localY){
        this->scene.lock()->removeObject(shared_from_this());
    }
}

void ArrowBullet::draw() {
    int count = Game::get()->fps.getCountFrame();
    //Game::get()->screen.writeChar(count % 10 > 4 ? '/' : '\\', this->x() - 1, this->y() - 1);
    //Game::get()->screen.writeChar(count % 10 < 4 ? '/' : '\\', this->x() + 1, this->y() - 1);
    //Game::get()->screen.writeChar(count % 10 > 4 ? '/' : '\\', this->x() + 1, this->y() + 1);
    //Game::get()->screen.writeChar(count % 10 < 4 ? '/' : '\\', this->x() - 1, this->y() + 1);
    Game::get()->screen.writeChar('+', this->x() - 0, this->y() + 0, Screen::ForColor::MAGENTA, Screen::BackColor::MAGENTA);
}

void ArrowBullet::end() {
    this->removeChild(this->collider);
    this->scene.lock()->collision.removeObjectRequire(this->collider);
}

