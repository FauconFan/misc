#ifndef MACROS_HPP
#define	MACROS_HPP

#define	CONCATENATE(arg1, arg2)                        CONCATENATE1(arg1, arg2)
#define	CONCATENATE1(arg1, arg2)                       CONCATENATE2(arg1, arg2)
#define	CONCATENATE2(arg1, arg2)                       arg1 ## arg2

#define	RSEQ()                                         8, 7, 6, 5, 4, 3, 2, 1, 0
#define	NARG_N(_1, _2, _3, _4, _5, _6, _7, _8, N, ...) N
#define	NARG_(...)                                     NARG_N(__VA_ARGS__)
#define	NARG(...)                                      NARG_(__VA_ARGS__, RSEQ())

#define	FOR_EACH_1(what, x)                            what(x)
#define	FOR_EACH_2(what, x, ...)                       what(x) FOR_EACH_1(what, __VA_ARGS__)
#define	FOR_EACH_3(what, x, ...)                       what(x) FOR_EACH_2(what, __VA_ARGS__)
#define	FOR_EACH_4(what, x, ...)                       what(x) FOR_EACH_3(what, __VA_ARGS__)
#define	FOR_EACH_5(what, x, ...)                       what(x) FOR_EACH_4(what, __VA_ARGS__)
#define	FOR_EACH_6(what, x, ...)                       what(x) FOR_EACH_5(what, __VA_ARGS__)
#define	FOR_EACH_7(what, x, ...)                       what(x) FOR_EACH_6(what, __VA_ARGS__)
#define	FOR_EACH_8(what, x, ...)                       what(x) FOR_EACH_7(what, __VA_ARGS__)

#define	FOR_EACH_(N, what, x, ...)                     CONCATENATE(FOR_EACH_, N)(what, x, __VA_ARGS__)
#define	FOR_EACH(what, x, ...)                         FOR_EACH_(NARG(x, __VA_ARGS__), what, x, __VA_ARGS__)

#endif // ifndef MACROS_HPP
