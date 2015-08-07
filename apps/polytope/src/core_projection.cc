/*
  Copyright (c) 2010-13 Andreas Paffenholz
 
  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation; either version 2, or (at your option) any
  later version: http://www.gnu.org/licenses/gpl.txt.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
-------------------------------------------------------------------------------
  $Project: polyhedral_adjunction $$Id: core_projection.cc 179 2012-02-09 15:16:42Z paffenholz $
*/


#include "polymake/client.h"
#include "polymake/Set.h"
#include <polymake/PowerSet.h>
#include "polymake/Matrix.h"
#include "polymake/SparseMatrix.h"
#include "polymake/Integer.h"
#include "polymake/Rational.h"
#include "polymake/Smith_normal_form.h"
#include "polymake/common/lattice_tools.h"


namespace polymake { namespace polytope {

    perl::Object mountain ( perl::Object p ) {

      if (!p.give("FULL_DIM") )     // only for full dimensional polytopes
	throw std::runtime_error("not a full dimensional polytope");

      perl::Object q("Polytope<Rational>");

      Matrix<Rational> FR = p.give("FACETS");
      Matrix<Integer> F = common::primitive(FR);
      F |= -ones_vector<Integer>(F.rows());
      F /= unit_vector<Integer>(F.cols(),F.cols()-1);
      q.take("INEQUALITIES") << F;

      return q;
    }

    perl::Object core_face ( perl::Object p ) {
      
      perl::Object q("Polytope<Rational>");
      
      int adim = p.give("CONE_AMBIENT_DIM");
      adim -= 1;

      perl::Object m = mountain(p);

      perl::Object lp("LinearProgram<Rational>");
      Vector<Rational> v = unit_vector<Rational>(adim+2,adim+1);

      lp.take("LINEAR_OBJECTIVE") << v;

      m.take("LP") << lp;

      // FIXME request next three properties to work around scheduler bug
      m.give("VERTICES");
      m.give("GRAPH.ADJACENCY");
      m.give("FAR_FACE");

      Set<int> core_face = m.give("LP.MAXIMAL_FACE");

      Matrix<Rational> V = m.give("VERTICES");

      q.take("POINTS") << V.minor(core_face,range(0,adim));

      return q;
    }

    perl::Object core_projection ( perl::Object p ) {

      perl::Object q("Polytope<Rational>");
      perl::Object c = core_face(p);
      
      int core_dim = c.give("CONE_DIM");
      core_dim--;
      if (  core_dim == 0 ) 
	throw std::runtime_error("core is a point");
      

      Matrix<Rational> VR = c.give("VERTICES");

      VR -= repeat_row(VR.row(0),VR.rows());
      VR = VR.minor(~scalar2set(0),~scalar2set(0));
      Matrix<Integer> M = common::primitive(VR);
      SmithNormalForm<Integer> SNF = smith_normal_form(M);

      Matrix<Integer> R = SNF.right_companion;
      if (det(R) < 0)              // det(R) > 0
	R.col  (SNF.rank-1) *= -1;

      Matrix<Rational> V = p.give("VERTICES");

      V -= repeat_row(V.row(0),V.rows());
      V = V.minor(All,~scalar2set(0));
      V = V*inv(R);

      V = ones_vector<Rational>(V.rows())|V.minor(All,~range(0,SNF.rank-1));
      q.take("POINTS") << V;
      
      return q;
    }

    UserFunction4perl("# @category Polyhedral Adjunction"
		      "# Produces the mountain over P"
		      "# "
		      "# Let P be given by primitive non-redundant inequalities  0<= b+Ax"
		      "# Then the mountain over $P$ is the polytope defined by"
		      "# 0 <= b-lambda*1+Ax and lambda>=0"
		      "# @param Polytope P"
		      "# @return Polytope mountain over P",
		      &mountain, "mountain($)");

    UserFunction4perl("# @category Polyhedral Adjunction" 
		      "# Produces the core face of the polytope P"
		      "# "
		      "# the core face is the face of the mountain of P defined by 1/lambda=[[Q_CODEGREE]]"
		      "# @param Polytope P"
		      "# @return Polytope core face of P",
		      &core_face, "core_face($)");

    UserFunction4perl("# @category Polyhedral Adjunction"
		      "# Projects a polytope along its core face"
		      "# the core face must have dimension >= 1"
		      "# "
		      "# @param Polytope P"
		      "# @return Polytope the projection along the core face",
		      &core_projection, "core_projection($)");


  }}
