#ifndef CNULL_HPP
#define	CNULL_HPP

#include "libsat.hpp"

// This come from here: https://stackoverflow.com/questions/6240950/platform-independent-dev-null-in-c

template <typename Ch, typename Traits = std::char_traits<Ch> >
struct basic_nullbuf: std::basic_streambuf<Ch, Traits> {
	using base_type   = std::basic_streambuf<Ch, Traits>;
	using int_type    = typename base_type::int_type;
	using traits_type = typename base_type::traits_type;

	int_type overflow(int_type c) override{
		return traits_type::not_eof(c);
	}
};

// convenient typedefs
using nullbuf  = basic_nullbuf<char>;
using wnullbuf = basic_nullbuf<wchar_t>;

// buffers and streams
// in some .h
extern std::ostream cnull;
extern std::wostream wcnull;

#endif // ifndef CNULL_HPP
