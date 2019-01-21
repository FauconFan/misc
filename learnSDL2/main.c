//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int SCREEN_WIDTH2 = 960;
const int SCREEN_HEIGHT2 = 720;

int main(void) {
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

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
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0xFF, 0xFF));

			//Put a red square
			uint32_t	*pixels = (uint32_t *)screenSurface->pixels;

			for (size_t x = 100; x < 200; x++) {
				for (size_t y = 100; y < 200; y++) {
					pixels[x + (y * screenSurface->w)] = SDL_MapRGB(screenSurface->format, 0xFF, 0, 0);
				}
			}

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait one second
			SDL_Delay(1000);

			//Resize the window
			SDL_SetWindowSize(window, SCREEN_WIDTH2, SCREEN_HEIGHT2);

			//Wait one second
			SDL_Delay(1000);
		}
	}
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return (0);
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
