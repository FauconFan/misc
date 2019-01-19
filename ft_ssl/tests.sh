#!/bin/bash

_RED=$(tput setaf 1 2> /dev/null || echo "")
_GREEN=$(tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(tput setaf 3 2> /dev/null || echo "")
_BLUE=$(tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(tput setaf 5 2> /dev/null || echo "")
_CYAN=$(tput setaf 6 2> /dev/null || echo "")
_WHITE=$(tput setaf 7 2> /dev/null || echo "")
_END=$(tput sgr0 2> /dev/null || echo "")

RANDOM_EIGHT_HEX_NUM="dd if=/dev/random bs=8 count=1 2>/dev/null | od -An -tx1 | tr -d ' \n\t'"

TMP_SCORE=$(mktemp)
TMP_FILE=$(mktemp)
DUMP_LEAKS_FILE="dump_leaks.txt"

MD5_META="openssl md5,./ft_ssl md5"
MD4_META="openssl md4,./ft_ssl md4"
SHA256_META="openssl sha -sha256,./ft_ssl sha256"
SHA1_META="openssl sha -sha1,./ft_ssl sha1"
SHA224_META="openssl sha -sha224,./ft_ssl sha224"
SHA384_META="openssl sha -sha384,./ft_ssl sha384"
SHA512_META="openssl sha -sha512,./ft_ssl sha512"
SHA512224_META="shasum -a 512224,./ft_ssl sha512_224"
SHA512256_META="shasum -a 512256,./ft_ssl sha512_256"

HASH_META="${MD5_META};${MD4_META};${SHA256_META};${SHA1_META};${SHA224_META};${SHA384_META};${SHA512_META};${SHA512224_META};${SHA512256_META};"

NB_KEYS="3"
NB_IVS="1"

KEYS=""
IVS=""

for (( i = 0; i < NB_KEYS; i++ )); do
	KEY=$(eval ${RANDOM_EIGHT_HEX_NUM})
	KEYS="${KEYS}${KEY};"
done

for (( i = 0; i < NB_IVS; i++ )); do
	IV=$(eval ${RANDOM_EIGHT_HEX_NUM})
	IVS="${IVS}${IV};"
done

MODES="des-ecb;des-cbc;des-cfb;des-ofb;"

BASE64="base64,base64 -D,./ft_ssl base64,./ft_ssl base64 -d,1"
BASE64_URL="base64 | tr '+/' '-_', tr -- '-_' '+/' | base64 -D,./ft_ssl base64_url,./ft_ssl base64_url -d,1"

build_commands()
{
	rm -f tmp.txt
	echo "${BASE64};" > tmp.txt
	echo "${BASE64_URL};" >> tmp.txt
	echo "${MODES}" | while read -d';' MODE; do
		echo "${KEYS}" | while read -d';' KEY; do
			if [ ${MODE} = "des-ecb" ]; then
				echo "openssl ${MODE} -K ${KEY},openssl ${MODE} -d -K ${KEY},./ft_ssl ${MODE} -k ${KEY},./ft_ssl ${MODE} -d -k ${KEY},0;" >> tmp.txt
			else
				echo "${IVS}" | while read -d';' IV; do
					echo "openssl ${MODE} -K ${KEY} -iv ${IV},openssl ${MODE} -d -K ${KEY} -iv ${IV},./ft_ssl ${MODE} -k ${KEY} -v ${IV},./ft_ssl ${MODE} -d -k ${KEY} -v ${IV},0;" >> tmp.txt
				done
			fi
		done
	done
	cat tmp.txt | tr -d '\n'
	rm -f tmp.txt
}

ENCRYPT_META="$(build_commands)"

DATA=$(cat << EOL
.Je suis un poulet sur patte.Et accesoirement une patate.pickle rick.Do not pity with the dead, Harry..Pity the living.And above all,.pity those that aren't following baerista on spotify..be sure to handle edge cases carefully.some of this will not make sense at first.GL HF let's go.one more thing.just to be extra clear.just an extra test...Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin arcu magna, tincidunt quis risus nec, pretium egestas mi. Praesent id sagittis nisl. Mauris pretium lectus orci, sit amet pulvinar dolor maximus sit amet. Duis nulla lorem, vulputate vitae tempus id, eleifend nec nulla. Proin quis urna sed nibh porttitor convallis sed vitae tortor. Ut tincidunt, dui non finibus mattis, ipsum nunc lobortis augue, vel placerat ligula justo id nunc. Aliquam porta felis vel velit accumsan, et laoreet magna fermentum. Nam lectus nisl, pretium imperdiet orci vitae, laoreet vulputate arcu. Proin efficitur consectetur enim, nec sollicitudin nunc. Proin finibus mollis velit ac scelerisque. Integer varius tempor lacus, ut varius urna rutrum quis. Aenean consectetur lacinia ante. Integer eu tempor sapien. Ut magna nulla, commodo et lacus non, tempor commodo dui...Etiam consequat viverra nisi nec varius. Ut elementum nibh facilisis diam consequat scelerisque. Morbi sit amet dui tempor nisi maximus eleifend. Proin eget mattis enim. Suspendisse potenti. Sed sem mi, vehicula nec aliquet et, tristique vel est. Integer ullamcorper eleifend luctus. Suspendisse sagittis nunc eget consequat volutpat. Nam dapibus vestibulum lectus nec scelerisque. Nulla id ligula luctus, rhoncus metus in, laoreet ex. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas...Mauris vel diam malesuada, posuere odio at, pretium augue. Duis in lorem turpis. Suspendisse dapibus eu leo eu lacinia. Proin egestas ipsum et quam hendrerit sodales. Sed eu tortor eu nulla efficitur sodales. Pellentesque hendrerit felis eget magna aliquet, in cursus ipsum gravida. Donec in vulputate nisi, sed convallis magna. Cras vel orci lacinia, elementum nunc vitae, rutrum ex...Fusce feugiat, quam vitae placerat viverra, libero odio tempor neque, in iaculis dui ante vel sapien. Aenean in est a est volutpat convallis. Ut in metus et nisl dapibus cursus. Ut eu molestie ligula. Quisque diam nulla, condimentum ut pretium eget, varius eu nisl. Proin pellentesque facilisis ex id rutrum. Donec quis diam tincidunt, fermentum ligula ut, aliquet elit. Suspendisse felis ligula, viverra vitae semper vitae, malesuada eu ligula. Fusce faucibus ante enim, id aliquet nulla faucibus a...In eu velit id lectus interdum consequat. Vivamus a enim mollis, imperdiet orci nec, porttitor velit. Sed imperdiet diam eget mauris varius vehicula. Pellentesque rhoncus ex feugiat libero egestas, ut congue risus varius. Interdum et malesuada fames ac ante ipsum primis in faucibus. Nam quam leo, aliquam vel porttitor sed, sollicitudin quis elit. Aenean aliquet eget libero quis vehicula. Suspendisse ut lobortis libero, vel bibendum justo. Pellentesque lacinia condimentum purus et sagittis. Ut ultrices, enim sed aliquet ornare, leo libero auctor nulla, quis sollicitudin sem urna et mi. Vestibulum quis tincidunt purus, at ultrices elit. Cras diam metus, sollicitudin sed mauris vitae, tempor ornare erat. Phasellus sed urna tellus._________________.__________________________________.___________________________________________________.____________________________________________________________________._____________________________________________________________________________________.______________________________________________________________________________________________________._______________________________________________________________________________________________________________________.________________________________________________________________________________________________________________________________________._________________________________________________________________________________________________________________________________________________________.__________________________________________________________________________________________________________________________________________________________________________.___________________________________________________________________________________________________________________________________________________________________________________________.____________________________________________________________________________________________________________________________________________________________________________________________________________._____________________________________________________________________________________________________________________________________________________________________________________________________________________________.______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.込作金連携南政育平挙活世激即逆転。東断化情教野画摂景戒保在端身。手回実化燃話政橋売録史国年由力長准必転申。摘提況索属応局際伺断任写行普波踏。氏史跡戦再条平本企前革板様熊。過去女参主戸平実無年洗正旅真周強極。出戦覧手車足連内応縄都図保住。強権定夜高尿陽参高合宝提駐高選単北正。新手問思後力暮挑録博酒帯止物。.
EOL
)

if [ ! -f ./ft_ssl ]; then
	printf "Run make all before...\\n"
	exit 1
fi

compt_OK()
{
	N=$(cat ${TMP_SCORE})
	if [ -z ${N} ]; then
		printf "OK %s1%s" "${_GREEN}" "${_END}"
		echo "1" > ${TMP_SCORE}
	else
		N=$((N + 1))
		printf "\\rOK %s%d%s" "${_GREEN}" "${N}" "${_END}"
		echo ${N} > ${TMP_SCORE}
	fi
}

compt_reset()
{
	echo "" > ${TMP_SCORE}
	printf "\\n"
}

checks_hash()
{
	echo "${HASH_META}" | while IFS=',' read -d';' REAL_CMD MINE_CMD; do
		printf "============ %s ===========\\n" "${MINE_CMD}"
		echo "${DATA}" | while read -d'.' STR; do
			OR=$(eval "echo \"${STR}\" | ${REAL_CMD} | sed 's/(stdin)//' | tr -d '= -'")
			OM=$(eval "echo \"${STR}\" | ${MINE_CMD}")
			if ! [ ${OR} = ${OM} ]; then
				RET=1
				compt_reset
				printf "Failed on :\\n"
				printf "\"%s\"\\n" "${STR}"
				printf "%d\\n" "${#STR}"
				echo "${OR}"
				echo "${OM}"
			else
				compt_OK
			fi
		done
		compt_reset
	done
}

_check_des()
{
	INPUT="$1"
	REAL_ENC="$2"
	REAL_DEC="$3"
	MINE_ENC="$4"
	MINE_DEC="$5"
	DELETE_SP="$6"
	ENC_OUT_REAL="enc_real.out"
	ENC_OUT_MINE="enc_mine.out"
	DEC_OUT_REAL="dec_real.out"
	DEC_OUT_MINE="dec_mine.out"

	eval "cat ${INPUT} | ${REAL_ENC}" > ${ENC_OUT_REAL}
	eval "cat ${INPUT} | ${MINE_ENC}" > ${ENC_OUT_MINE}
	if [ ${DELETE_SP} = "1" ]; then
		tmp=$(mktemp)
		cat ${ENC_OUT_REAL} | tr -d '\n ' > ${tmp}
		mv ${tmp} ${ENC_OUT_REAL}
		cat ${ENC_OUT_MINE} | tr -d '\n ' > ${tmp}
		mv ${tmp} ${ENC_OUT_MINE}
		rm -f ${tmp}
	fi
	eval "cat ${ENC_OUT_REAL} | ${REAL_DEC}" > ${DEC_OUT_REAL}
	eval "cat ${ENC_OUT_MINE} | ${MINE_DEC}" > ${DEC_OUT_MINE}
	if diff ${ENC_OUT_REAL} ${ENC_OUT_MINE} > /dev/null 2>&1 && diff ${DEC_OUT_REAL} ${DEC_OUT_MINE} > /dev/null 2>&1; then
		compt_OK
	else
		diff ${ENC_OUT_REAL} ${ENC_OUT_MINE}
		diff ${DEC_OUT_REAL} ${DEC_OUT_MINE}
		compt_reset
		printf "Failed on : %s\\n" "${INPUT}"
		exit 1
	fi
	rm -f ${ENC_OUT_REAL} ${ENC_OUT_MINE} ${DEC_OUT_REAL} ${DEC_OUT_MINE}
}

checks_des()
{
	echo "${ENCRYPT_META}" | while IFS=',' read -d';' A B C D E; do
		printf "============ %s ===========\\n" "${D}"
		echo "${DATA}" | while read -d'.' STR; do
			echo ${TMP} > ${TMP_FILE}
			_check_des ${TMP_FILE} "${A}" "${B}" "${C}" "${D}" "${E}"
		done
		compt_reset
	done
}

checks_random_des()
{
	echo "${ENCRYPT_META}" | while IFS=',' read -d';' A B C D E; do
		printf "============ %s ===========\\n" "${D}"
		for (( i = 0; i < 50; i++ )); do
			cat /dev/urandom | head -c ${RANDOM} > ${TMP_FILE}
			_check_des ${TMP_FILE} "${A}" "${B}" "${C}" "${D}" "${E}"
		done
		compt_reset
	done
}

_check_leak()
{
	BEG_CMD="if !"
	END_CMD="2>&1 | tee -a ${DUMP_LEAKS_FILE} | grep 'definitely lost' | grep -v ' 0 bytes' ; then printf '${_GREEN}OK${_END}'; else printf '${_RED}KO${_END}'; fi"

	eval "${BEG_CMD} $* ${END_CMD}"
	printf " : \"%s\"\\n" "$*"
}

checks_leaks()
{
	VG="valgrind --leak-check=full"
	RD="cat /dev/urandom | head -c 512"
	CMD="${VG} ./ft_ssl"

	rm -f ${DUMP_LEAKS_FILE}
	_check_leak "${CMD}"
	echo "${HASH_META}" | while IFS=',' read -d';' REAL_CMD MINE_CMD; do
		_check_leak "${RD} | ${VG} ${MINE_CMD}"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -h"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -r"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -rq"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -p"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -pq"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -pq -s 'oui'"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -pqr -s 'oui'"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -pq -s 'oui' -s 'non'"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -pqr -s 'oui' -s 'non'"
	done
	for ba in base64 base64_url; do
		_check_leak "${RD} | ${CMD} ${ba}"
		_check_leak "${RD} | ${CMD} ${ba} -e"
		_check_leak "${RD} | ${CMD} ${ba} -e -o tmp"
		_check_leak "${CMD} ${ba} -i ./ft_ssl -o tmp"
		_check_leak "${CMD} ${ba} -i ./ft_ssl -e -e -e -o tmp"
		_check_leak "${CMD} ${ba} -i ./ft_ssl -eee -o tmp"
		_check_leak "${CMD} ${ba} -i tmp -d"
		_check_leak "${CMD} ${ba} -i ./ft_ssl -d"
	done
	eval "${RD} > tmp2"
	echo "${MODES}" | while read -d';' MODE; do
		echo "${KEYS}" | while read -d';' KEY; do
			IV=$(echo -n ${KEY} | tr '0123456789ABCDEF' '49F378BD6A10C25E')
			_check_leak "${RD} | ${CMD} ${MODE} -k ${KEY} -v ${IV}"
			_check_leak "${RD} | ${CMD} ${MODE} -k ${KEY} -v ${IV} -e"
			_check_leak "${RD} | ${CMD} ${MODE} -k ${KEY} -v ${IV} -e -o tmp"
			_check_leak "${CMD} ${MODE} -k ${KEY} -v ${IV} -i tmp2 -o tmp"
			_check_leak "${CMD} ${MODE} -k ${KEY} -v ${IV} -i tmp2 -e -e -e -o tmp"
			_check_leak "${CMD} ${MODE} -k ${KEY} -v ${IV} -i tmp2 -eee -o tmp"
			_check_leak "${CMD} ${MODE} -k ${KEY} -v ${IV} -i tmp -d"
			_check_leak "${CMD} ${MODE} -k ${KEY} -v ${IV} -i tmp2 -d"
		done
	done
	rm tmp tmp2
}

RET=0
LOOP=0

if [ $# = 2 ]; then
	if [ $1 = "loop" ]; then
		LOOP=1
		printf "the program is in loop mode, kill it if you want to stop it\\n"
	else
		printf "first argument is ignored, must be loop\\n"
	fi
	shift
fi

if ! [ $# = 1 ]; then
	RET=1
else
	case $1 in
		hash )
			checks_hash
			;;
		des )
			checks_des
			;;
		random_des )
			checks_random_des
			;;
		leaks )
			checks_leaks
			;;
		all )
			checks_hash
			checks_des
			checks_leaks
			;;
		* )
			RET=1
			;;
	esac
fi

if ! [ $RET = "0" ]; then
	rm -rf ${TMP_SCORE}
	rm -rf ${TMP_FILE}
fi

if [ $LOOP = "1" ] && [ $RET = "0" ]; then
	printf "%sLOOPING%s\\n" "${_CYAN}" "${_END}"
	bash $0 "loop" "$1"
fi

exit ${RET}
