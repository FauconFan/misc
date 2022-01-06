#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include "libfts.h"

#define NB_ROUNDS	32

static void		print_data(uint8_t *data, size_t len)
{
	size_t		i;

	i = 0;
	while (i != len)
	{
		if (i != 0)
		{
			if (i % 16 == 0)
				printf("\n");
			else
				printf(" ");
		}
		printf("%02x", data[i] & 0xFF);
		++i;
	}
	printf("\n");
}

int				main(void)
{
	uint8_t		*data;
	uint8_t		*copy_original;
	uint8_t		key[16];
	uint8_t		data_size;

	ft_getrandom(&data_size, 1);
	if (data_size < 8)
		data_size += 8;
	data = malloc(data_size);
	copy_original = malloc(data_size);
	if (data == NULL || copy_original == NULL)
		return (1);
	ft_getrandom(data, data_size);
	ft_getrandom(key, 16);
	ft_memcpy(copy_original, data, data_size);
	printf("Key:\n");
	print_data(key, 16);
	printf("\n");

	printf("Init: (zise = %d)\n", data_size);
	print_data(data, data_size);
	printf("\n");

	ft_encrypt(data, data_size, key, NB_ROUNDS);
	printf("After encryption:\n");
	print_data(data, data_size);
	printf("\n");

	ft_decrypt(data, data_size, key, NB_ROUNDS);
	printf("After decryption:\n");
	print_data(data, data_size);
	printf("\n");

	int		ret = ft_memcmp(data, copy_original, data_size);
	if (ret == 0)
		printf("Encrypt OK all good\n");
	else
		printf("================= SOMETHING WENT WRONG =================\n");
	free(data);
	free(copy_original);
	return (ret);
}
