#ifndef BOOST_DETAIL_INTERLOCKED_HPP_INCLUDED
#define BOOST_DETAIL_INTERLOCKED_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  boost/detail/interlocked.hpp
//
//  Copyright 2005 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/config.hpp>

#if defined( BOOST_USE_WINDOWS_H )

# include <windows.h>

# define BOOST_INTERLOCKED_INCREMENT ::InterlockedIncrement
# define BOOST_INTERLOCKED_DECREMENT ::InterlockedDecrement
# define BOOST_INTERLOCKED_COMPARE_EXCHANGE ::InterlockedCompareExchange
# define BOOST_INTERLOCKED_EXCHANGE ::InterlockedExchange
# define BOOST_INTERLOCKED_COMPARE_EXCHANGE_POINTER ::InterlockedCompareExchangePointer

#elif defined( BOOST_MSVC ) || defined( BOOST_INTEL_WIN )

extern "C" long __cdecl _InterlockedIncrement( long volatile * );
extern "C" long __cdecl _InterlockedDecrement( long volatile * );
extern "C" long __cdecl _InterlockedCompareExchange( long volatile *, long, long );
extern "C" long __cdecl _InterlockedExchange( long volatile *, long);
extern "C" void* __cdecl _InterlockedCompareExchangePointer( void* volatile *, void*, void* );

# pragma intrinsic( _InterlockedIncrement )
# pragma intrinsic( _InterlockedDecrement )
# pragma intrinsic( _InterlockedCompareExchange )
# pragma intrinsic( _InterlockedExchange )
# pragma intrinsic( _InterlockedCompareExchangePointer )

# define BOOST_INTERLOCKED_INCREMENT ::_InterlockedIncrement
# define BOOST_INTERLOCKED_DECREMENT ::_InterlockedDecrement
# define BOOST_INTERLOCKED_COMPARE_EXCHANGE ::_InterlockedCompareExchange
# define BOOST_INTERLOCKED_EXCHANGE ::_InterlockedExchange
# define BOOST_INTERLOCKED_COMPARE_EXCHANGE_POINTER ::_InterlockedCompareExchangePointer

#elif defined( WIN32 ) || defined( _WIN32 ) || defined( __WIN32__ )

namespace boost
{

namespace detail
{

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement( long volatile * );
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement( long volatile * );
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange( long volatile *, long, long );
extern "C" __declspec(dllimport) long __stdcall InterlockedExchange( long volatile *, long );
extern "C" __declspec(dllimport) void* __stdcall InterlockedCompareExchangePointer( void* volatile *, void*, void* );

} // namespace detail

} // namespace boost

# define BOOST_INTERLOCKED_INCREMENT ::boost::detail::InterlockedIncrement
# define BOOST_INTERLOCKED_DECREMENT ::boost::detail::InterlockedDecrement
# define BOOST_INTERLOCKED_COMPARE_EXCHANGE ::boost::detail::InterlockedCompareExchange
# define BOOST_INTERLOCKED_EXCHANGE ::boost::detail::InterlockedExchange
# define BOOST_INTERLOCKED_COMPARE_EXCHANGE_POINTER ::boost::detail::InterlockedCompareExchangePointer

#else

# error "Interlocked intrinsics not available"

#endif

#define BOOST_INTERLOCKED_READ(x) BOOST_INTERLOCKED_COMPARE_EXCHANGE(x,0,0)
#define BOOST_INTERLOCKED_READ_POINTER(x) BOOST_INTERLOCKED_COMPARE_EXCHANGE_POINTER(x,0,0)


#endif // #ifndef BOOST_DETAIL_INTERLOCKED_HPP_INCLUDED
