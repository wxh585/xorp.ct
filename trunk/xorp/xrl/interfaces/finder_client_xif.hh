/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/finder_client_xif.hh,v 1.3 2003/01/10 00:30:27 hodson Exp $
 */

#ifndef __XRL_INTERFACES_FINDER_CLIENT_XIF_HH__
#define __XRL_INTERFACES_FINDER_CLIENT_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFinderClient"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlFinderClientV0p1Client {
public:
    XrlFinderClientV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlFinderClientV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB0;
    /**
     *  Send Xrl intended to:
     *  
     *  No op method used by finder to poll for liveness.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_hello(
	const char*	target_name, 
	const CB0&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB1;
    /**
     *  Send Xrl intended to:
     *  
     *  Remove Xrl from cache. The client should remove currently cached value
     *  for Xrl from it's cached. On the next invocation of Xrl, the client
     *  will need to consult the Finder for updated information, though
     *  implementations may consult the Finder for updated information before.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_remove_xrl_from_cache(
	const char*	target_name, 
	const string&	xrl, 
	const CB1&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CB2;
    /**
     *  Send Xrl intended to:
     *  
     *  Remove all Xrls relating to target from cache
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_remove_xrls_for_target_from_cache(
	const char*	target_name, 
	const string&	target_name, 
	const CB2&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall0(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB0		cb
    );

    void unmarshall1(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB1		cb
    );

    void unmarshall2(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB2		cb
    );

};

#endif /* __XRL_INTERFACES_FINDER_CLIENT_XIF_HH__ */
