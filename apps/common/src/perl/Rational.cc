/* Copyright (c) 1997-2010
   Ewgenij Gawrilow, Michael Joswig (Technische Universitaet Darmstadt, Germany)
   http://www.polymake.de

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version: http://www.gnu.org/licenses/gpl.txt.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
--------------------------------------------------------------------------------
   $Project: polymake $$Id: Rational.cc 182 2012-02-13 14:12:13Z paffenholz $
*/

///==== this line controls the automatic file splitting: max.instances=40

#include "polymake/client.h"
#include "polymake/Rational.h"
#include "polymake/Integer.h"
#include "polymake/linalg.h"
namespace polymake { namespace common {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   OperatorInstance4perl(convert, Rational, perl::Canned< const Integer >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Rational >, perl::Canned< const pm::SameElementVector<pm::Rational const&> >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} }
