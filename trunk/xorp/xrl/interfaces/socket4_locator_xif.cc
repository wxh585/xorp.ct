/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/socket4_locator_xif.cc,v 1.1 2003/11/07 23:07:30 hodson Exp $"

#include "socket4_locator_xif.hh"

bool
XrlSocket4LocatorV0p1Client::send_find_socket_server_for_addr(
	const char*	the_tgt,
	const IPv4&	local_addr,
	const FindSocketServerForAddrCB&	cb
)
{
    Xrl x(the_tgt, "socket4_locator/0.1/find_socket_server_for_addr");
    x.args().add("local_addr", local_addr);
    return _sender->send(x, callback(this, &XrlSocket4LocatorV0p1Client::unmarshall_find_socket_server_for_addr, cb));
}


/* Unmarshall find_socket_server_for_addr */
void
XrlSocket4LocatorV0p1Client::unmarshall_find_socket_server_for_addr(
	const XrlError&	e,
	XrlArgs*	a,
	FindSocketServerForAddrCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string xrl_target;
    try {
	a->get("xrl_target", xrl_target);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &xrl_target);
}
