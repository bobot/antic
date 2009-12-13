/*============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

===============================================================================*/
/******************************************************************************

 Copyright (C) 2006, 2007, 2008, 2009 William Hart
 Copyright (C) 2009, Andy Novocin
 
******************************************************************************/

#ifndef FMPZ_POLY_H
#define FMPZ_POLY_H

#include <mpir.h>
#include "fmpz.h"

typedef struct
{
   fmpz * coeffs;
   ulong alloc;
   ulong length;
} fmpz_poly_struct;

typedef fmpz_poly_struct fmpz_poly_t[1];

void fmpz_poly_init(fmpz_poly_t poly);

void fmpz_poly_init2(fmpz_poly_t poly, const ulong alloc);

void fmpz_poly_realloc(fmpz_poly_t poly, const ulong alloc);

void fmpz_poly_fit_length(fmpz_poly_t poly, const ulong length);

void fmpz_poly_clear(fmpz_poly_t poly);

void _fmpz_poly_normalise(fmpz_poly_t poly);

static inline
void fmpz_poly_truncate(fmpz_poly_t poly, const ulong length)
{
	if (poly->length > length) // only truncate if necessary
   {
      ulong i;
      for (i = length; i < poly->length; i++)
			_fmpz_demote(poly->coeffs + i);
		poly->length = length;
      _fmpz_poly_normalise(poly);
   }  
}

#endif





