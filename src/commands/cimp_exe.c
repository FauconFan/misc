#include "cimp.h"

/* /!\ /!\ POSITION PROVISOIRE /!\/!\ */

void cimp_exe(t_parser_out * cmd){
  if(strstr(cmd->cmd,"help")){
    cimp_help();
  }else if(strstr(cmd->cmd,"list")){
    cimp_list();
  }else if(strstr(cmd->cmd,"QUIT")){
    exit(0);
  }
}
