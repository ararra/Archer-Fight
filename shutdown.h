#pragma once

#include "main.h"

void shutdown()
{
    tmx_map_free(game.map);
}