#pragma once
#include "raylib.h"

namespace tools
{
struct textureInfo
{
	Texture texture;
	Texture alternativeTexture;
	Rectangle source;
	Rectangle dest;

};
}