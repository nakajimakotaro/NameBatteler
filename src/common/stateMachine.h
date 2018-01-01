//
// Created by harus on 2017/12/29.
//

#ifndef NAMEBATTLER_STATEMACHINE_H
#define NAMEBATTLER_STATEMACHINE_H


#include <map>
#include <unordered_map>
#include <memory>
#include "state.h"

template <typename T> class StateMachine;
template <typename T> using StateGenerator = std::unique_ptr<State<T>>(*)(std::weak_ptr<StateMachine<T>> machine);
template <typename T> using StateMap = std::unordered_map<std::string, StateGenerator<T>>;
template <typename T> using StateMapPair = std::pair<std::string, StateGenerator<T>>;
template <typename T> class StateMachine final: public std::enable_shared_from_this<StateMachine<T>>{
private:
    StateMachine() = default;
    void init(std::weak_ptr<T> body, std::string  initState, StateMap<T> eventMap);
public:
    std::weak_ptr<T> body;
    StateMap<T> stateMap;
    std::unique_ptr<State<T>> state;

public:
    static std::shared_ptr<StateMachine<T>> create(std::weak_ptr<T> body, std::string initState, StateMap<T> eventMap){
        auto ptr = std::shared_ptr<StateMachine<T>>(new StateMachine<T>());
        ptr->init(body, initState, eventMap);
        return ptr;
    }
    void change(std::string name);
    void update();
};

template<typename T>
void StateMachine<T>::init(std::weak_ptr<T> body, std::string initState, StateMap<T> stateMap) {
    this->body = body;
    this->stateMap = stateMap;
    this->state = this->stateMap.at(initState)(this->shared_from_this());
    this->state->start();
}


template<typename T>
void StateMachine<T>::change(std::string name) {
    this->state->end();
    this->state = this->stateMap.at(name)(this->shared_from_this());
    this->state->start();
}

template<typename T>
void StateMachine<T>::update() {
    this->state->update();
}

#endif //NAMEBATTLER_STATEMACHINE_H
