/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/rtrmgr_client_xif.cc,v 1.3 2003/01/24 06:31:31 pavlin Exp $"

#include "rtrmgr_client_xif.hh"

bool
XrlRtrmgrClientV0p1Client::send_new_config_user(
	const char*	the_tgt, 
	const uint32_t&	userid, 
	const CB0&	cb
)
{
    Xrl x(the_tgt, "rtrmgr_client/0.1/new_config_user");
    x.args().add("userid", userid);
    return _sender->send(x, callback(this, &XrlRtrmgrClientV0p1Client::unmarshall0, cb));
}


/* Unmarshall new_config_user */
void
XrlRtrmgrClientV0p1Client::unmarshall0(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB0		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRtrmgrClientV0p1Client::send_config_change_done(
	const char*	the_tgt, 
	const bool&	success, 
	const string&	errmsg, 
	const CB1&	cb
)
{
    Xrl x(the_tgt, "rtrmgr_client/0.1/config_change_done");
    x.args().add("success", success);
    x.args().add("errmsg", errmsg);
    return _sender->send(x, callback(this, &XrlRtrmgrClientV0p1Client::unmarshall1, cb));
}


/* Unmarshall config_change_done */
void
XrlRtrmgrClientV0p1Client::unmarshall1(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB1		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRtrmgrClientV0p1Client::send_config_changed(
	const char*	the_tgt, 
	const uint32_t&	userid, 
	const string&	deltas, 
	const string&	deletions, 
	const CB2&	cb
)
{
    Xrl x(the_tgt, "rtrmgr_client/0.1/config_changed");
    x.args().add("userid", userid);
    x.args().add("deltas", deltas);
    x.args().add("deletions", deletions);
    return _sender->send(x, callback(this, &XrlRtrmgrClientV0p1Client::unmarshall2, cb));
}


/* Unmarshall config_changed */
void
XrlRtrmgrClientV0p1Client::unmarshall2(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB2		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
