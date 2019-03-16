#ifndef UTILS_H
#define	UTILS_H

#define	NOT_A_PATH  "The given path is not a regular Unix path"
#define	MALLOC_FAIL "A malloc has failed"

// path_utils

char * normalize_path(char * curpath);

// str_utils

char * strjoin(const char * s1, const char * s2);
char * strjoin_c(const char * dir, const char * file, char joiner);

char * dupstr(const char * s);
int nb_digit(int i);
char * itoa(int i, char * b);

// format/*.c

int     save_surface_png(const char * file, SDL_Surface * surface);
int     save_surface_jpeg(const char * file, SDL_Surface * surface);
int     save_surface_bmp(const char * file, SDL_Surface * surface);

t_type_img              get_type_img(char * filepath);
t_export_img_func_ptr   get_func_img(t_type_img type);

#endif // ifndef UTILS_H
