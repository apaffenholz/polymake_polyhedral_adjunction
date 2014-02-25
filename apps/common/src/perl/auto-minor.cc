/* Copyright (c) 1997-2010
   Ewgenij Gawrilow, Michael Joswig (Technische Universitaet Darmstadt, Germany)
   http://www.polymake.org

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version: http://www.gnu.org/licenses/gpl.txt.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
--------------------------------------------------------------------------------
   $Project: polymake $$Id: auto-minor.cc 150 2011-10-11 14:10:30Z paffenholz $
*/

///==== this line controls the automatic file splitting: max.instances=40

#include "polymake/client.h"
#include "polymake/Matrix.h"
#include "polymake/Integer.h"
#include "polymake/IncidenceMatrix.h"
#include "polymake/Set.h"
#include "polymake/Rational.h"

namespace polymake { namespace common { namespace {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1, typename T2>
   FunctionInterface4perl( minor_X8_X8_f5, T0,T1,T2 ) {
      perl::Value arg0(stack[0]), arg1(stack[1]), arg2(stack[2]);
      WrapperReturnLvalueAnch( (3)(arg0)(arg1)(arg2), T0, arg0.get<T0>().minor(arg1.get<T1>(), arg2.get<T2>()) );
   };

   FunctionInstance4perl(minor_X8_X8_f5, perl::Canned< Wary< Matrix< Integer > > >, perl::Canned< const pm::Complement<pm::Set<int, pm::operations::cmp>, int, pm::operations::cmp> >, perl::Enum<pm::all_selector>);
   FunctionInstance4perl(minor_X8_X8_f5, perl::Canned< Wary< Matrix< Integer > > >, perl::Canned< const Set< int > >, perl::Enum<pm::all_selector>);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} } }
