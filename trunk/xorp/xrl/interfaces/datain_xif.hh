/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/datain_xif.hh,v 1.8 2003/08/07 04:52:24 hodson Exp $
 */

#ifndef __XRL_INTERFACES_DATAIN_XIF_HH__
#define __XRL_INTERFACES_DATAIN_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifDatain"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlDatainV0p1Client {
public:
    XrlDatainV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlDatainV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr ReceiveCB;

    bool send_receive(
	const char*	target_name,
	const string&	peer,
	const uint32_t&	genid,
	const bool&	status,
	const uint32_t&	secs,
	const uint32_t&	micro,
	const vector<uint8_t>&	data,
	const ReceiveCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ErrorCB;

    bool send_error(
	const char*	target_name,
	const string&	peer,
	const uint32_t&	genid,
	const string&	reason,
	const ErrorCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ClosedCB;

    bool send_closed(
	const char*	target_name,
	const string&	peer,
	const uint32_t&	genid,
	const ClosedCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_receive(
	const XrlError&	e,
	XrlArgs*	a,
	ReceiveCB		cb
    );

    void unmarshall_error(
	const XrlError&	e,
	XrlArgs*	a,
	ErrorCB		cb
    );

    void unmarshall_closed(
	const XrlError&	e,
	XrlArgs*	a,
	ClosedCB		cb
    );

};

#endif /* __XRL_INTERFACES_DATAIN_XIF_HH__ */
