/*
This is an ad-hoc solution to make the C-compiled libcerf callable from C++ code.

TODO:
- Either, distribute this along with liberf.
- Or, make sure the Debian, Homebrew etc packages distribute a libcerfcpp along with libcerf.

*/

#include <cerf.h>
#include <complex>

std::complex<double> cerfcx(const std::complex<double>& z)
{
    const _cerf_cmplx ret = cerfcx(*((_cerf_cmplx*)(&z)));
    return {reinterpret_cast<const double(&)[2]>(ret)[0],
            reinterpret_cast<const double(&)[2]>(ret)[1]};
}
