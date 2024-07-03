#pragma once

#define WIDTH 640
#define HEIGHT 480

//so we can iterate through a specific part of the sprite sheet.
// for example the walking down sprites.
#define UNEXT 15
#define UHEIGHT 23
#define UWIDTH 15

#define LNEXT 32
#define LHEIGHT 23
#define LWIDTH 22

//The sprite is divided into two parts
// the upper part all have the same y "start" coordinates and are right next to each other
// The lower part has wider sprites and needs more room.

#define MOVEX 1
#define JUMPX 81
#define CARRYX 144

#define DOWNY 6
#define RIGHTY 38
#define UPY 69
#define LEFTY 102

#define ATTACKX 7
#define ATTACKDOWNY 134
#define ATTACKUPY 166
#define ATTACKRIGHTY 199
#define ATTACKLEFTY 230

