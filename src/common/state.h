//
// Created by harus on 2017/12/29.
//

#ifndef NAMEBATTLER_STATE_H
#define NAMEBATTLER_STATE_H

#include <memory>

template <typename T> class StateMachine;
template <typename T> class State {
protected:
    explicit State(std::weak_ptr<StateMachine<T>> machine);

public:
    std::weak_ptr<StateMachine<T>> machine;
    virtual void start(){};
    virtual void update(){};
    virtual void draw(){};
    virtual void end(){};
    virtual ~State() = default;
    std::shared_ptr<T> body_ptr();
};

template <typename T> State<T>::State(std::weak_ptr<StateMachine<T>> machine):
        machine(machine)
{
}

template<typename T>
std::shared_ptr<T> State<T>::body_ptr() {
    return this->machine.lock()->body.lock();
}


#endif //NAMEBATTLER_STATE_H
