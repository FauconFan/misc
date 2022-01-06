/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 11:07:25 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 10:45:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_DEFINES_H
# define SSL_DEFINES_H

/*
**	Global helpers
*/

# define HELP_PROG			"Program tool to crypt, hash or decrypt contents"
# define HELP_DGT			"Digest messages with %s algorithm."
# define HELP_BASE64		"Base64 encode or decode."
# define HELP_DES			"Encrypt (DES) using %s cipher mode algorithm"

# define PAD_PRINT_ASCII	64
# define ASK_PWD			"enter encryption password:"
# define ASK_VERIFYING_PWD	"Verifying - enter encryption password:"
# define ASK_PWD_FAILURE	"Verification failure"

# define MSG_VALID_KEY		"You should provide a valid key."
# define MSG_VALID_IV		"You should provide a valid init vector (iv)."
# define MSG_VALID_SALT		"You should provide a valid salt, or just miss it."

/*
**	Commands defines
*/

# define CMD_MD5			"md5"
# define CMD_MD4			"md4"
# define CMD_SHA1			"sha1"
# define CMD_SHA224			"sha224"
# define CMD_SHA256			"sha256"
# define CMD_SHA384			"sha384"
# define CMD_SHA512			"sha512"
# define CMD_SHA512_256		"sha512_256"
# define CMD_SHA512_224		"sha512_224"
# define CMD_BASE64			"base64"
# define CMD_BASE64_URL		"base64_url"
# define CMD_DES			"des"
# define CMD_DES_ECB		"des-ecb"
# define CMD_DES_CBC		"des-cbc"
# define CMD_DES_OFB		"des-ofb"
# define CMD_DES_CFB		"des-cfb"

/*
**	Specifig commands helpers
*/

# define HELP_OPT_DEC		"decode mode"
# define HELP_OPT_ENC		"encode mode (default)"
# define HELP_OPT_IN		"input file (default:stdin)"
# define HELP_OPT_OUT		"output file (default:stdout)"
# define HELP_OPT_P			"STDIN to STDOUT and append the checksum to STDOUT"
# define HELP_OPT_Q			"quiet mode"
# define HELP_OPT_R			"reverse the format of the output"
# define HELP_OPT_S			"print the sum of the given string"
# define HELP_ASC_OUTPUT	"process (input/output) with base64 algorithm"
# define HELP_KEY			"key in hexadecimal form"
# define HELP_PWD			"password is given in the next argument"
# define HELP_APWD			"password is asked, and key and iv are generated"
# define HELP_SALT			"salt in hexadecimal form"
# define HELP_VEC			"initialization vector in hexadecimal form"
# define HELP_NOPAD			"disable standard block padding"

/*
**	Tags
*/

# define HELP_ENC_TAG		"encode_tag"
# define HELP_DEC_TAG		"decode_tag"
# define HELP_IN_TAG		"input_file_tag"
# define HELP_OUT_TAG		"output_file_tag"
# define HELP_STDIN_TAG		"stdin_tag"
# define HELP_QUIET_TAG		"quiet_tag"
# define HELP_REV_TAG		"reverse_tag"
# define HELP_SAM_TAG		"samples_tag"
# define HELP_ASC_TAG		"ascii_tag"
# define HELP_KEY_TAG		"key_tag"
# define HELP_PWD_TAG		"password_tag"
# define HELP_APWD_TAG		"ask_password_tag"
# define HELP_SALT_TAG		"salt_tag"
# define HELP_VEC_TAG		"vector_tag"
# define HELP_NOPAD_TAG		"nopad_tag"

#endif
