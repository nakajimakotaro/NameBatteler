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
        GameObject(scene, startX, startY),
        startX(startX),
        startY(startY),
        goalX(goalX),
        goalY(goalY),
        w(w),
        h(h)
{
}
MoveBlock::MoveBlock(std::weak_ptr<Scene> scene, nlohmann::json json):
        MoveBlock(
                scene,
                json["startX"].get<double>(),
                json["startY"].get<double>(),
                json["goalX"].get<double>(),
                json["goalY"].get<double>(),
                json["w"].get<double>(),
                json["h"].get<double>()
        )
{
}


void MoveBlock::start() {
    this->state = StateMachine<MoveBlock>::create(std::dynamic_pointer_cast<MoveBlock>(shared_from_this()), "wait", {
            MoveState::mapPair(),
            WaitState::mapPair()
    });
}

void MoveBlock::update() {
    this->state->update();
}


void MoveBlock::draw() {
    this->state->draw();
    for(int x = this->x();x < this->x() + this->w;x++){
        Game::get()->screen.writeChar('-', x, this->y());
        Game::get()->screen.writeChar('-', x, this->y() + this->h - 1);
    }
    for(int y = this->y() + 1;y < this->y() + this->h - 1;y++){
        Game::get()->screen.writeChar('|', this->x(), y);
        Game::get()->screen.writeChar('|', this->x() + this->w - 1, y);
    }
}
void MoveBlock::end() {
}

