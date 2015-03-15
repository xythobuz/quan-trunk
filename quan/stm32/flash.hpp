#ifndef QUAN_STM32_FLASH_HPP_INCLUDED
#define QUAN_STM32_FLASH_HPP_INCLUDED
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

#include <cstdint>
#include <quan/dynarray.hpp>

namespace quan {namespace stm32 {namespace flash {

   struct symbol_table{
      symbol_table(){}
      
      virtual uint16_t get_symbol_storage_size(uint16_t symidx)const =0;
      virtual uint16_t get_symtable_size()const =0;

      bool read_symbol (uint16_t symidx, quan::dynarray<uint8_t> & buffer)const;
      bool write_symbol(uint16_t symidx, quan::dynarray<uint8_t> const & buffer)const;
      bool have_symbol(uint16_t symidx)const;
      // get the index of the symbol name in the dynarray
      int32_t get_index( quan::dynarray<char> const & symbol_name) const;
      virtual int32_t get_index( const char* const symbol_name) const;
      private:
         symbol_table(symbol_table const &) = delete;
         symbol_table& operator = (symbol_table const &) = delete;
   };

   // return -1 if corrupt
   // n.b. only returns num since last firmware update
   int32_t get_write_count();
  
  
   
  
}}}
 
#endif // QUAN_STM32_FLASH_HPP_INCLUDED
 
