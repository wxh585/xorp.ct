// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2002 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

// $XORP: xorp/libxorp/ref_trie.hh,v 1.2 2003/01/21 03:52:32 mjh Exp $

#ifndef __LIBXORP_MINITRAITS_HH__
#define __LIBXORP_MINITRAITS_HH__

/**
 * @short Class to determine subset of type traits.
 *
 * This class can be use to determine the non-const form of a type.
 * It is a temporary fix for g++ 2.96 (Redhat) which has problems
 * tracking const pointer types in templates.
 */
template <typename T>
class MiniTraits {
    template <class U> 
    struct UnConst {
	typedef U Result;
    };
    template <class U> 
    struct UnConst <const U> {
        typedef U Result;
    };
public:
    typedef typename UnConst<T>::Result NonConst;
};

#endif // __LIBXORP_MINITRAITS_HH__
