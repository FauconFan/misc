" **************************************************************************** "
"                                                                              "
"                                                         :::      ::::::::    "
"    42header.vim                                       :+:      :+:    :+:    "
"                                                     +:+ +:+         +:+      "
"    By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+         "
"                                                 +#+#+#+#+#+   +#+            "
"    Created: 2017/11/25 12:22:04 by tdelmas           #+#    #+#              "
"    Updated: 2017/11/25 20:46:27 by tdelmas          ###   ########.fr        "
"                                                                              "
" **************************************************************************** "

function! s:draw(l)
	let l:data = [  "        :::      ::::::::","      :+:      :+:    :+:","    +:+ +:+         +:+  ","  +#+  +:+       +#+     ","+#+#+#+#+#+   +#+        ","     #+#    #+#          ","    ###   ########.fr    "]
	return l:data[a:l - 3]
endfunction

function! s:put_spaces(len)
	let s:str_spaces = ""
	let l:tmp = a:len
	while (l:tmp > 0)
		let s:str_spaces = s:str_spaces . " "
		let l:tmp = l:tmp - 1
	endwhile
	return s:str_spaces
endfunction

function! s:line_content(line)
	if a:line == 1 || a:line == 11
		return "/* ************************************************************************** */"
	elseif a:line == 2 || a:line == 10
		return "/*                                                                            */"
	elseif a:line == 3 || a:line == 5 || a:line == 7
		return "/*                                                " . s:draw(a:line) . "   */"
	elseif a:line == 4
		return "/*   " . expand("%:t") . s:put_spaces(45 - strlen(expand("%:t"))) . s:draw(a:line) . "   */"
	elseif a:line == 6
		return "/*   By: " . $USER . " <" . $MAIL . ">" . s:put_spaces(24 - (2 * strlen($USER))) . s:draw(a:line) . "   */"
	elseif a:line == 8
		return "/*   Created: " . strftime("%Y/%m/%d %H:%M:%S") . " by " . $USER . s:put_spaces(13 - strlen($USER)) . s:draw(a:line) . "   */"
	elseif a:line == 9
		return "/*   Updated: " . strftime("%Y/%m/%d %H:%M:%S") . " by " . $USER . s:put_spaces(13 - strlen($USER)) . s:draw(a:line) . "   */"
	endif
endfunction

function! s:create()
	let l:line = 11
	call append(0, "")
	while l:line > 0
		call append(0, s:line_content(l:line))
		let l:line = l:line - 1
	endwhile
endfunction

function! s:strcmp_date(str_a, str_b)
	let l:i = strlen(a:str_b)
	if strlen(a:str_a) != l:i
		return 1
	endif
	while l:i >= 0
		if l:i == 14 ||  l:i == 15 ||  l:i == 16 ||  l:i == 17 ||  l:i == 19 ||  l:i == 20 ||  l:i == 22 ||  l:i == 23 ||  l:i == 25 ||  l:i == 26 ||  l:i == 28 ||  l:i == 29 ||  l:i == 31 ||  l:i == 32
		elseif a:str_a[l:i] != a:str_b[l:i]
			return 1
		endif
		let l:i = l:i - 1
	endwhile
	return 0
endfunction

function! s:strcmp(str_a, str_b)
	let l:i = strlen(a:str_b)
	if strlen(a:str_a) != l:i
		return 1
	endif
	while l:i >= 0
		if a:str_a[l:i] != a:str_b[l:i]
			return 1
		endif
		let l:i = l:i - 1
	endwhile
	return 0
endfunction
	
function! s:duplicate()
	let l:line = 11
	while l:line > 0
		if l:line == 8 || l:line == 9
			if s:strcmp_date(getline(l:line), s:line_content(l:line))
				return 1
			endif
		elseif s:strcmp(getline(l:line), s:line_content(l:line))
			return 1
		endif
		let l:line = l:line - 1
	endwhile
	return 0
endfunction

function! s:putheader()
	if &modified && s:duplicate() == 0
		call setline(9, s:line_content(9))
		call setline(4, s:line_content(4))
	elseif s:duplicate()
		call s:create()
	endif
endfunction

command! Header call s:putheader ()
inoremap <C-c> <C-h>:Header<CR>
autocmd BufWritePost * call s:putheader()
