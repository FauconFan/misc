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

typedef struct      s_metasearch{
	uint64_t dest_id;
	uint64_t sender_id;
	uint32_t nonce;
}                   t_metasearch;

t_bool                  is_acquit_wstruct(t_acquit * acquit, t_metasearch * mts) {
	return (is_acquit(acquit, mts->dest_id, mts->sender_id, mts->nonce));
}

t_bool                  list_has_acquit(t_list * lst, uint64_t dest_id, uint64_t sender_id, uint32_t nonce) {
	t_metasearch mts;

	mts.dest_id   = dest_id;
	mts.sender_id = sender_id;
	mts.nonce     = nonce;
	return (lst_findp(lst, (t_bool(*)(void *, void *))is_acquit_wstruct, &mts) != NULL);
}

static void             parcours_acq(t_acquit * acq, struct timeval * tv) {
	struct timeval * tmp;

	tmp = timeval_min(tv, &acq->next_time);
	timeval_assign(tv, *tmp);
}

t_bool                  acquit_get_min_time(t_list * li_acquit, struct timeval * tv) {
	if (lst_isempty(li_acquit))
		return (FALSE);

	timeval_assign(tv, (((t_acquit *) lst_top(li_acquit))->next_time));
	lst_iterp(li_acquit, (void(*)(void *, void *))parcours_acq, tv);
	return (TRUE);
}
