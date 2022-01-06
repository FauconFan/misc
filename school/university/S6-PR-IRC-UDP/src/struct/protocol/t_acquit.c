#include "irc_udp.h"


t_acquit * acquit_alloc(uint64_t dest_id, uint64_t sender_id, uint32_t nonce) {
	t_acquit * acquit = malloc(sizeof(t_acquit));

	if (acquit == NULL)
		return NULL;

	acquit->dest_id     = dest_id;
	acquit->sender_id   = sender_id;
	acquit->nonce       = nonce;
	acquit->no_response = 0;
	timeval_raise(&acquit->next_time, acquit->no_response);

	return acquit;
}

void                    acquit_free(t_acquit * acquit) {
	free(acquit);
}

void                    acquit_print(t_acquit * acquit, int fd) {
	dprintf(fd, "acquit { dest_id : %016lx, sender_id : %016lx, nonce : %x, next_time : ", acquit->dest_id,
	  acquit->sender_id, acquit->nonce);
	timeval_print(acquit->next_time, fd);
	dprintf(fd, ", no_response : %d }", acquit->no_response);
}

void                    acquit_no_response(t_acquit * acquit) {
	acquit->no_response = acquit->no_response + 1;
	timeval_raise(&acquit->next_time, acquit->no_response);
}

t_bool                  is_acquit(t_acquit * acquit, uint64_t dest_id, uint64_t sender_id, uint32_t nonce) {
	return (acquit->dest_id == dest_id && acquit->sender_id == sender_id && acquit->nonce == nonce);
}
