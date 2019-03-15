#include "irc_udp.h"


int serveur()
{
  int s;
  int rc;
  struct sockaddr_in6 server;

  s = socket(AF_INET6, SOCK_DGRAM, 0);
  if(s < 0)
  {
    printf("pas de socket\n");
    return (-1);
  }

  memset(&server, 0, sizeof(server));
  server.sin6_family = AF_INET6;
  server.sin6_port = htons(4242); // port à modifier !!!!!
  rc = bind(s, (struct sockaddr*)&server, sizeof(server));
  if (rc<0)
  {
    printf("bind marche pas\n");
    return (-1);
  }
  while (1)
  {
    unsigned char req[4096], reply[4096];
    struct sockaddr_in6 client;
    socklen_t client_len = sizeof(client);
    rc = recvfrom(s, req, 4096, 0, (struct sockaddr *)&client, &client_len);
    if(rc < 0)
    {
      perror("recvfrom");
      continue;
    }
    printf("%.*s\n", rc, req);
    // faire la reponse ici
    size_t reply_len = 0;
    rc = sendto(s, reply, reply_len, 0, (struct sockaddr *)&client, client_len);
  }
}
