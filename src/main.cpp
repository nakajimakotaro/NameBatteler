#include <windows.h>
#include "screen.h"
#include "game.h"

int main() {
    return Game::get()->loop();
}
