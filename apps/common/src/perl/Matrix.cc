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
   $Project: polymake $$Id: Matrix.cc 182 2012-02-13 14:12:13Z paffenholz $
*/

///==== this line controls the automatic file splitting: max.instances=40

#include "polymake/client.h"
#include "polymake/Matrix.h"
#include "polymake/Rational.h"
#include "polymake/Vector.h"
#include "polymake/Set.h"
#include "polymake/linalg.h"
#include "polymake/Integer.h"
#include "polymake/IncidenceMatrix.h"
#include "polymake/SparseMatrix.h"

namespace polymake { namespace common { namespace {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( new_X, T0,T1 ) {
      perl::Value arg0(stack[1]);
      WrapperReturnNew(T0, (arg0.get<T1>()) );
   };

   OperatorInstance4perl(BinaryAssign__or, perl::Canned< Wary< Matrix< Rational > > >, perl::Canned< const Vector< Rational > >);
   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::Complement<pm::Set<int, pm::operations::cmp>, int, pm::operations::cmp> const&, pm::all_selector const&> >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< Matrix< Rational > > >, perl::Canned< const pm::SameElementVector<pm::Rational> >);
   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational> const&>, pm::RowChain<pm::Matrix<pm::Rational> const&, pm::SingleRow<pm::SameElementVector<pm::Rational> const&> > const&> >);
   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Integer> const&>, pm::Matrix<pm::Integer> const&> >);
   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::Vector<pm::Integer> const&>, pm::Transposed<pm::Matrix<pm::Integer> > const&> >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< pm::RepeatedRow<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer>&>, pm::Series<int, true>, void> const&> > >, perl::Canned< const Matrix< Integer > >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::MatrixMinor<pm::Matrix<pm::Integer>&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&, pm::all_selector const&> > >, perl::Canned< const Matrix< Integer > >);
   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const pm::RowChain<pm::MatrixMinor<pm::Matrix<pm::Integer>&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&, pm::all_selector const&> const&, pm::Matrix<pm::Integer> const&> >);
   OperatorInstance4perl(Binary_add, perl::Canned< const Wary< pm::RepeatedRow<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer>&>, pm::Series<int, true>, void> const&> > >, perl::Canned< const Matrix< Integer > >);
   OperatorInstance4perl(BinaryAssign__or, perl::Canned< Wary< Matrix<Integer> > >, perl::Canned< const Vector< Integer > >);
   OperatorInstance4perl(BinaryAssign_div, perl::Canned< Wary< Matrix<Integer> > >, perl::Canned< const pm::SameElementSparseVector<pm::SingleElementSet<int>, pm::Integer> >);
   FunctionInstance4perl(new_X, Matrix<Rational>, perl::Canned< const pm::MatrixMinor<pm::Matrix<pm::Integer>&, pm::Complement<pm::Set<int, pm::operations::cmp>, int, pm::operations::cmp> const&, pm::all_selector const&> >);
   FunctionInstance4perl(new_X, Matrix<Rational>, perl::Canned< const pm::MatrixMinor<pm::Matrix<pm::Integer>&, pm::Set<int, pm::operations::cmp> const&, pm::all_selector const&> >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< Matrix<Rational> > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational> const&>, pm::MatrixMinor<pm::Matrix<pm::Rational> const&, pm::Set<int, pm::operations::cmp> const&, pm::all_selector const&> const&> > >, perl::Canned< const pm::SameElementSparseVector<pm::SingleElementSet<int>, pm::Rational> >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::MatrixMinor<pm::Matrix<pm::Rational> const&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> > >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> const&, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::MatrixMinor<pm::Matrix<pm::Rational> const&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> > >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&, void> >);
   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const SparseMatrix< Integer, NonSymmetric > >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< Matrix< Rational > > >, perl::Canned< const pm::SameElementVector<pm::Rational const&> >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} } }
