#include <check.h>
#include "cimp.h"

START_TEST(test_quit){
  treat_line("QUIT");
  ck_assert_int_eq(g_cimp->running,0);
} END_TEST

START_TEST(test_rotate){
  short truth = 1;
  SDL_Surface *surf=SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
  uint32_t * new = (uint32_t *) surf->pixels;
  uint32_t to_test =(uint32_t)32;
  new[0]=to_test;
  g_cimp->screen=malloc(sizeof(t_cimp_screen));
  g_cimp->screen->buff_screen=surf;
  treat_line("rotate 90");
  if(g_cimp->screen->buff_screen->w==2 && g_cimp->screen->buff_screen->h==3){
    uint32_t * pixels     = (uint32_t *) g_cimp->screen->buff_screen->pixels;
    for(int i=0 && truth; i<6;i++){
      if(i==1){truth=truth && pixels[1]==to_test;}
      else{truth=truth && pixels[i]==0;}
    }
  }else
    ck_assert(0==1);
  treat_line("rotate 180");
  if(truth && g_cimp->screen->buff_screen->w==2 && g_cimp->screen->buff_screen->h==3){
    uint32_t * pixels     = (uint32_t *) g_cimp->screen->buff_screen->pixels;
    for(int i=0 && truth; i<6;i++){
      if(i==4){truth=truth && pixels[4]==to_test;}
      else{truth=truth && pixels[i]==0;}
    }
  }else
    ck_assert(0==1);
  treat_line("rotate -90");
  if(truth && g_cimp->screen->buff_screen->w==3 && g_cimp->screen->buff_screen->h==2){
    uint32_t * pixels     = (uint32_t *) g_cimp->screen->buff_screen->pixels;
    for(int i=0 && truth; i<6;i++){
      if(i==5){truth=truth && pixels[5]==to_test;}
      else{truth=truth && pixels[i]==0;}
    }
  }else
    ck_assert(0==1);
  ck_assert(truth);
} END_TEST

START_TEST(test_sym_verti){
  short truth = 1;
  SDL_Surface *surf=SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
  uint32_t * new = (uint32_t *) surf->pixels;
  uint32_t to_test =(uint32_t)32;
  new[0]=to_test;
  g_cimp->screen=malloc(sizeof(t_cimp_screen));
  g_cimp->screen->buff_screen=surf;
  treat_line("sym_verti");
  if(g_cimp->screen->buff_screen->w==3 && g_cimp->screen->buff_screen->h==2){
    uint32_t * pixels     = (uint32_t *) g_cimp->screen->buff_screen->pixels;
    for(int i=0 && truth; i<6;i++){
      if(i==2){truth=truth && pixels[2]==to_test;}
      else{truth=truth && pixels[i]==0;}
    }
    ck_assert(truth);
  }else
    ck_assert(0==1);
}END_TEST

START_TEST(test_sym_hori){
  short truth=1;
  SDL_Surface *surf=SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
  uint32_t * new = (uint32_t *) surf->pixels;
  uint32_t to_test =(uint32_t)32;
  new[0]=to_test;
  g_cimp->screen=malloc(sizeof(t_cimp_screen));
  g_cimp->screen->buff_screen=surf;
  treat_line("sym_hori");
  if(g_cimp->screen->buff_screen->w==3 && g_cimp->screen->buff_screen->h==2){
    uint32_t * pixels     = (uint32_t *) g_cimp->screen->buff_screen->pixels;
    for(int i=0 && truth; i<6;i++){
      if(i==3){truth=truth && pixels[3]==to_test;}
      else{truth=truth && pixels[i]==0;}
    }
    ck_assert(truth);
  }else
    ck_assert(0==1);
}END_TEST

START_TEST(empty_line){
  treat_line("");
  ck_assert(g_cimp->running);
}END_TEST

START_TEST(test_close){
  short truth=1;
  treat_line("close");
  truth = truth && g_cimp->screen == NULL;
  SDL_Surface *surf=SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
  g_cimp->screen=malloc(sizeof(t_cimp_screen));
  g_cimp->screen->buff_screen=surf;
  /*treat_line("close");
  truth = truth && g_cimp->screen == NULL;*/
  ck_assert(truth);


}END_TEST

START_TEST(test_open){
  treat_line("open images/untitled17.bmp");
  ck_assert(1);
}END_TEST

Suite *sample_suite(void) {
  Suite *s;
  TCase *tc_sample;

  s = suite_create("cimp commandes");
  tc_sample = tcase_create("Sample");
  tcase_add_test(tc_sample, test_rotate);
  tcase_add_test(tc_sample,test_sym_verti);
  tcase_add_test(tc_sample,test_sym_hori);
  tcase_add_test(tc_sample,empty_line);
  tcase_add_test(tc_sample,test_close);
  tcase_add_test(tc_sample,test_open);
  tcase_add_test(tc_sample, test_quit);
  suite_add_tcase(s, tc_sample);

  return s;
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;
  libtest_viewing_enabled=0;
  cimp_init();
  s = sample_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
