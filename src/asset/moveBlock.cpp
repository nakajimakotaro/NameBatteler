//
// Created by harus on 2018/01/22.
//

#include "moveBlock.h"
#include "../core/game.h"
#include "../common/state.h"
#include "../common/stateMachine.h"
class MoveState: public State<MoveBlock>{
    const double speed = 0.5;
public:
    explicit MoveState(const std::weak_ptr<StateMachine<MoveBlock>> &machine) : State(machine) {

    }
    void update(){
        double angle = atan2(this->body_ptr()->goalY - this->body_ptr()->startY, this->body_ptr()->goalX - this->body_ptr()->startX);
        this->body_ptr()->localX += cos(angle) * this->speed;
        this->body_ptr()->localY += sin(angle) * this->speed;
        if (abs(this->body_ptr()->goalX - this->body_ptr()->x()) < 2) {
            this->body_ptr()->localX += this->body_ptr()->goalX - this->body_ptr()->x();
        }
        if (abs(this->body_ptr()->goalY - this->body_ptr()->y()) < 2) {
            this->body_ptr()->localY += this->body_ptr()->goalY - this->body_ptr()->y();
        }
        if (
                abs(this->body_ptr()->goalX - this->body_ptr()->x()) < 0.5 &&
                abs(this->body_ptr()->goalY - this->body_ptr()->y()) < 0.5) {
            std::swap(this->body_ptr()->goalX, this->body_ptr()->startX);
            std::swap(this->body_ptr()->goalY, this->body_ptr()->startY);
            this->machine.lock()->changeRequire("wait");
        }
    }
    static StateMapPair<MoveBlock> mapPair() {
        return std::make_pair(
                "move",
                [](auto machine) {
                    return std::unique_ptr<State<MoveBlock>>(new MoveState(machine));
                }
        );
    }
};
class WaitState: public State<MoveBlock>{
public:
    int waitStartFrame = 0;
    const int waitFrame = 30;
    explicit WaitState(const std::weak_ptr<StateMachine<MoveBlock>> &machine) : State(machine) {

    }
    void start() {
        this->waitStartFrame = Game::get()->fps.getCountFrame();
    }
    void update(){
        if(this->waitStartFrame + this->waitFrame < Game::get()->fps.getCountFrame()){
            this->machine.lock()->changeRequire("move");
        }
    }
    static StateMapPair<MoveBlock> mapPair() {
        return std::make_pair(
                "wait",
                [](auto machine) {
                    return std::unique_ptr<State<MoveBlock>>(new WaitState(machine));
                }
        );
    }
};

MoveBlock::MoveBlock(const std::weak_ptr<Scene> &scene, double startX, double startY, double goalX, double goalY, double w, double h):
        Block(scene, startX, startY, w, h),
        startX(startX),
        startY(startY),
        goalX(goalX),
        goalY(goalY)
{
}
MoveBlock::MoveBlock(std::weak_ptr<Scene> scene, std::shared_ptr<MyJson::JsonInterFace> json):
        MoveBlock(
                scene,
                json("startX")->getDouble(),
                json("startY")->getDouble(),
                json("goalX")->getDouble(),
                json("goalY")->getDouble(),
                json("w")->getDouble(),
                json("h")->getDouble()
        )
{
}


void MoveBlock::start() {
    Block::start();
    this->state = StateMachine<MoveBlock>::create(std::dynamic_pointer_cast<MoveBlock>(shared_from_this()), "move", {MoveState::mapPair(), WaitState::mapPair()});
}

void MoveBlock::update() {
    double x = this->localX;
    double y = this->localY;
    this->state->update();
    this->prevMoveX = this->localX - x;
    this->prevMoveY = this->localY - y;
}

void MoveBlock::railDraw(){
    const double w = this->goalX - this->startX;
    const double h = this->goalY - this->startY;
    if(abs(w) > abs(h)){
        const int stepX = w > 0 ? 2 : -2;
        const double slope = h / w;
        for(double x = 0;abs(w - x) > 1;x += stepX){
            double y = x * slope;
            Game::get()->screen.writeChar('*', x + this->startX + this->w / 2, y + this->startY + this->h / 2);
        }
    }else{
        const int stepY = h > 0 ? 1 : -1;
        const double slope = w / h;
        for(double y = 0;abs(h - y) > 1;y += stepY){
            double x = y * slope;
            Game::get()->screen.writeChar('*', x + this->startX + this->w / 2, y + this->startY + this->h / 2);
        }
    }
}

void MoveBlock::draw() {
    this->railDraw();
    Block::draw();
}
void MoveBlock::end() {
    Block::end();
}

