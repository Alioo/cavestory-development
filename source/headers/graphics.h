#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();
	/*
	 * Loads an image map into the sprite sheets map if it doesn't already exist
	 * each image is only loaded once in this case.
	 * @returns image loaded into the map
	 */
	SDL_Surface* loadImage(const std::string &filePath);

	/*
	 * Draw a texture to a certain destination of the screen (rectangle refers to the sprite sheet)
	 */
	void blitSurface(SDL_Texture* source, SDL_Rect* rectangle, SDL_Rect* destinationRectangle);

	/*void flip
	 * renders everything to the screen
	 */
	void flip();

	/*
	 * clears everything from the screen
	 */
	void clear();

	/*
	 * return the renderer
	 */
	SDL_Renderer* getRenderer() const;


private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheet;

};

#endif
