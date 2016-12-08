#include "texture_manager.hpp"

// Garbage collection Is A no no for scale
// But not a good programmer or program yet
// Come Back With Efficiency on Loads & Opengl

TextureManager::~TextureManager()
{
	SDL_DestroyRenderer(renderer);
}

void TextureManager::Load(const std::string& filepath, const std::string& id)
{
	SDL_Surface *surface = IMG_Load(filepath.c_str());

	if (surface == 0) return;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	if (texture <= 0) 
	{
		IMG_GetError();
		exit(-1);
	}
	else { n_textureMap[id] = texture; }
}

void TextureManager::Sketch(const std::string& id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.w = width;
	src_rect.h = height;

	dst_rect.x = x;
	dst_rect.y = y;
	dst_rect.w = width;
	dst_rect.h = height;

	SDL_RenderCopyEx(renderer, n_textureMap[id], &src_rect, &dst_rect, 0, 0, flip);
}

void TextureManager::CaptureFrame(const std::string& id, int x, int y, int width, int height, int cur_row, int cur_frame, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	src_rect.x = width * cur_frame;
	src_rect.y = height * (cur_row - 1);
	src_rect.w = width;
	src_rect.h = height;

	dst_rect.x = x;
	dst_rect.y = y;
	dst_rect.w = width;
	dst_rect.h = height;

	SDL_RenderCopyEx(renderer, n_textureMap[id], &src_rect, &dst_rect, 0, 0, flip);
}

void TextureManager::ClearTexture(const std::string& id)
{
	n_textureMap.erase(id);
}
