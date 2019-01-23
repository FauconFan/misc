//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

#define MIN(x, y)	(((x) < (y)) ? (x) : (y))

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int SCREEN_WIDTH2 = 960;
const int SCREEN_HEIGHT2 = 720;

SDL_Surface		*buff_screen = NULL;
int				wbuff_screen = 0;
int				hbuff_screen = 0;

void			init_buff_screen(int width, int height);
void			resize_buff_screen(int new_width, int new_height);
void			free_buff_screen();

int main(void) {
	//The window we'll be rendering to
	SDL_Window		*window = NULL;
	//Pointers to the list of pixels
	uint32_t		*pixels = NULL;
	//two sdl_rect util
	SDL_Rect		origin_rect1 = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
	SDL_Rect		origin_rect2 = {0, 0, SCREEN_WIDTH2, SCREEN_HEIGHT2};

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			init_buff_screen(SCREEN_WIDTH, SCREEN_HEIGHT);

			SDL_FillRect(buff_screen, NULL, SDL_MapRGB(buff_screen->format, 0, 0xFF, 0xFF));

			if (SDL_MUSTLOCK(buff_screen))
				SDL_LockSurface(buff_screen);

			pixels = (uint32_t *)buff_screen->pixels;
			//Put a red square
			for (size_t x = 100; x < 200; x++) {
				for (size_t y = 100; y < 200; y++) {
					pixels[x + (y * buff_screen->w)] = SDL_MapRGB(buff_screen->format, 0xFF, 0, 0);
				}
			}

			for (size_t x = 300; x < 400; x++) {
				for (size_t y = 100; y < 200; y++) {
					int dx = abs(x - 350);
					int dy = abs(y - 150);
					if (dx * dx + dy * dy < 50 * 50)
						pixels[x + (y * buff_screen->w)] = SDL_MapRGB(buff_screen->format, 0, 0xFF, 0);
				}
			}

			if (SDL_MUSTLOCK(buff_screen))
				SDL_UnlockSurface(buff_screen);

			//Update the surface
			SDL_BlitSurface(buff_screen, &origin_rect1, SDL_GetWindowSurface(window), NULL);
			SDL_UpdateWindowSurface(window);

			//Wait one second
			SDL_Delay(1000);

			resize_buff_screen(SCREEN_WIDTH2, SCREEN_HEIGHT2);

			//Resize the window
			SDL_SetWindowSize(window, SCREEN_WIDTH2, SCREEN_HEIGHT2);

			if (SDL_MUSTLOCK(buff_screen))
				SDL_LockSurface(buff_screen);

			pixels = (uint32_t *)buff_screen->pixels;

			for (int x = SCREEN_WIDTH; x < SCREEN_WIDTH2; x++) {
				for (int y = SCREEN_HEIGHT; y < SCREEN_HEIGHT2; y++) {
					pixels[x + (y * buff_screen->w)] = SDL_MapRGB(buff_screen->format, 0, 0, 0xFF);
				}
			}

			if (SDL_MUSTLOCK(buff_screen))
				SDL_UnlockSurface(buff_screen);

			//Update the surface
			SDL_BlitSurface(buff_screen, &origin_rect2, SDL_GetWindowSurface(window), NULL);
			SDL_UpdateWindowSurface(window);

			//Wait one second
			SDL_Delay(1000);

			//free buffer
			free_buff_screen();
		}
	}
	//Destroy window
	if (window)
		SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return (0);
}

void		init_buff_screen(int width, int height)
{
	free_buff_screen();
	buff_screen = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	wbuff_screen = width;
	hbuff_screen = height;
}

void		resize_buff_screen(int new_width, int new_height)
{
	SDL_Surface		*tmp;
	SDL_Rect		orig;

	tmp = SDL_CreateRGBSurface(0, new_width, new_height, 32, 0, 0, 0, 0);
	orig.x = 0;
	orig.y = 0;
	orig.w = MIN(wbuff_screen, new_width);
	orig.h = MIN(hbuff_screen, new_height);
	SDL_BlitSurface(buff_screen, &orig, tmp, NULL);
	free_buff_screen();
	buff_screen = tmp;
	wbuff_screen = new_width;
	hbuff_screen = new_height;
}

void		free_buff_screen()
{
	if (buff_screen != NULL)
	{
		SDL_FreeSurface(buff_screen);
		buff_screen = NULL;
		wbuff_screen = 0;
		hbuff_screen = 0;
	}
}

// #include <stdio.h>
// #include <SDL2/SDL.h>
//
// void	pause();
//
// int		main(void)
// {
// 	SDL_Surface *ecran = NULL;
//
// 	if (SDL_Init(SDL_INIT_VIDEO) != 0)
// 	{
// 		printf("SDL_Init Error : %s\n", SDL_GetError());
// 		return (1);
// 	}
// 	ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
//     if (ecran == NULL)
//     {
//         fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
//         return (1);
//     }
//     SDL_WM_SetCaption("Ma super fenêtre SDL !", NULL);
//     pause();
// 	SDL_Quit();
// 	return (0);
// }
//
// void	pause()
// {
//     int			continuer = 1;
//     SDL_Event	event;
//
//     while (continuer)
//     {
//         SDL_WaitEvent(&event);
//         switch(event.type)
//         {
//             case SDL_QUIT:
//                 continuer = 0;
//         }
//     }
// }
