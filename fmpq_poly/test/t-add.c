
/*=============================================================================

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

=============================================================================*/

/******************************************************************************

   Copyright (C) 2009 William Hart

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <mpir.h>
#include "flint.h"
#include "fmpz.h"
#include "fmpq_poly.h"
#include "ulong_extras.h"

int
main (void)
{
    int result;

    printf ("add....");
    fflush (stdout);

    fmpq_poly_randinit ();

    // Check aliasing of a and c
    for (ulong i = 0; i < 10000UL; i++)
    {
        fmpq_poly_t a, b, c;

        fmpq_poly_init (a);
        fmpq_poly_init (b);
        fmpq_poly_init (c);
        fmpq_poly_randtest (a, n_randint (100), n_randint (200));
        fmpq_poly_randtest (b, n_randint (100), n_randint (200));

        fmpq_poly_add (c, a, b);
        fmpq_poly_add (a, a, b);

        result = (fmpq_poly_equal (a, c));
        if (!result)
        {
            printf ("Error:\n");
            fmpq_poly_print (a);
            printf ("\n\n");
            fmpq_poly_print (b);
            printf ("\n\n");
            fmpq_poly_print (c);
            printf ("\n\n");
            abort ();
        }

        fmpq_poly_clear (a);
        fmpq_poly_clear (b);
        fmpq_poly_clear (c);
    }

    // Check aliasing of b and c
    for (ulong i = 0; i < 10000UL; i++)
    {
        fmpq_poly_t a, b, c;

        fmpq_poly_init (a);
        fmpq_poly_init (b);
        fmpq_poly_init (c);
        fmpq_poly_randtest (a, n_randint (100), n_randint (200));
        fmpq_poly_randtest (b, n_randint (100), n_randint (200));

        fmpq_poly_add (c, a, b);
        fmpq_poly_add (b, a, b);

        result = (fmpq_poly_equal (b, c));
        if (!result)
        {
            printf ("Error:\n");
            fmpq_poly_print (a);
            printf ("\n\n");
            fmpq_poly_print (b);
            printf ("\n\n");
            fmpq_poly_print (c);
            printf ("\n\n");
            abort ();
        }

        fmpq_poly_clear (a);
        fmpq_poly_clear (b);
        fmpq_poly_clear (c);
    }

    fmpq_poly_randclear ();

    _fmpz_cleanup ();
    printf ("PASS\n");
    return 0;
}
