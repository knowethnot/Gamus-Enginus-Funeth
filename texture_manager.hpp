#ifndef __TEXTURE_MANAGER_HPP__
#define __TEXTURE_MANAGER_HPP__

#include <string>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <map>

class TextureManager
{
	public:
		~TextureManager();

		void Load(const std::string& filepath, const std::string& id);
		void Sketch(const std::string& id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void CaptureFrame(const std::string& id, int x, int y, int width, int height, int cur_row, int cur_frame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void ClearTexture(const std::string& id);

	protected:
		std::map<std::string, SDL_Texture*> n_textureMap;
	
	private:
		SDL_Renderer* renderer;
		SDL_Rect src_rect, dst_rect;
};

#endif // __TEXTURE_MANAGER_HPP__
