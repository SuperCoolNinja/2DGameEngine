#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <glm/glm.hpp>
#include <imgui/imgui.h>
#include <sol/sol.hpp>
#include "../Game.h"



int main(int argv, char** args)
 {
    Game game;

    game.Init();

    game.Run();

    game.Destroy();
    return 0;
}
