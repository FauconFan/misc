#ifndef CNULL_HPP
#define	CNULL_HPP

#include "libsat.hpp"

// This come from here: https://stackoverflow.com/questions/6240950/platform-independent-dev-null-in-c

template <typename Ch, typename Traits = std::char_traits<Ch> >
struct basic_nullbuf: std::basic_streambuf<Ch, Traits> {
	typedef std::basic_streambuf<Ch, Traits> base_type;
	typedef typename base_type::int_type int_type;
	typedef typename base_type::traits_type traits_type;

	virtual int_type overflow(int_type c) {
		return traits_type::not_eof(c);
	}
};

// convenient typedefs
typedef basic_nullbuf<char> nullbuf;
typedef basic_nullbuf<wchar_t> wnullbuf;

// buffers and streams
// in some .h
extern std::ostream cnull;
extern std::wostream wcnull;

#endif // ifndef CNULL_HPP
