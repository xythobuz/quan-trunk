
#ifndef QUAN_META_DETAIL_RATIONAL_IMPL_HPP_INCLUDED
#define QUAN_META_DETAIL_RATIONAL_IMPL_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

#include <quan/config.hpp>
#include <quan/meta/gcd.hpp>

namespace quan{namespace meta{namespace detail{

   template<
      int64_t N,
      int64_t D 
   >
   struct rational_impl {

      static const int64_t pos_nume_in = (N >= 0) ? N : -N;
      static const int64_t pos_denom_in = (D >= 0) ? D : -D;

      typedef quan::meta::gcd<int64_t,pos_nume_in,pos_denom_in> gcd_type;

      static const int64_t gcd_ = (gcd_type::value);
      static const int64_t n_sign = (N >= 0)? 1 :-1;
      static const int64_t d_sign = (D >= 0)? 1 :-1;
      static const int64_t nume_in 
         = ((n_sign * d_sign) > 0)? pos_nume_in : -pos_nume_in;

      static const int64_t numerator = static_cast<int64_t>(nume_in) / gcd_;
      static const int64_t denominator = static_cast<int64_t>(pos_denom_in) / gcd_;

      typedef rational_impl<numerator,denominator> type;
   };

}}}//quan::meta::detail

#endif
