/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/rib_client_xif.hh,v 1.8 2003/08/07 04:52:27 hodson Exp $
 */

#ifndef __XRL_INTERFACES_RIB_CLIENT_XIF_HH__
#define __XRL_INTERFACES_RIB_CLIENT_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifRibClient"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlRibClientV0p1Client {
public:
    XrlRibClientV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlRibClientV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr RouteInfoChanged4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Route Info Changed route_info_changed is called by the RIB on the RIB
     *  client (typically a routing protocol) that had registered an interest
     *  in the routing of an address. This can be because the metric and/or
     *  nexthop changed.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param addr base address of the subnet that was registered
     *
     *  @param prefix_len prefix length of the subnet that was registered
     *
     *  @param metric the routing metric toward the address.
     *
     *  @param admin_distance the administratively defined distance toward the
     *  address.
     *
     *  @param protocol_origin the name of the protocol that originated this
     *  entry.
     */
    bool send_route_info_changed4(
	const char*	target_name,
	const IPv4&	addr,
	const uint32_t&	prefix_len,
	const IPv4&	nexthop,
	const uint32_t&	metric,
	const uint32_t&	admin_distance,
	const string&	protocol_origin,
	const RouteInfoChanged4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RouteInfoChanged6CB;

    bool send_route_info_changed6(
	const char*	target_name,
	const IPv6&	addr,
	const uint32_t&	prefix_len,
	const IPv6&	nexthop,
	const uint32_t&	metric,
	const uint32_t&	admin_distance,
	const string&	protocol_origin,
	const RouteInfoChanged6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RouteInfoInvalid4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Route Info Invalid route_info_invalid is called by the RIB on the RIB
     *  client (typically a routing protocol) that had registere d an interest
     *  in the routing of an address. This can be because the information
     *  previously reported as applying no longer applies for any number of
     *  reasons. When the RIB sends this message, it has automatically
     *  de-registered interest in the route, and the client will normally need
     *  to send a register_interest request again.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_route_info_invalid4(
	const char*	target_name,
	const IPv4&	addr,
	const uint32_t&	prefix_len,
	const RouteInfoInvalid4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RouteInfoInvalid6CB;

    bool send_route_info_invalid6(
	const char*	target_name,
	const IPv6&	addr,
	const uint32_t&	prefix_len,
	const RouteInfoInvalid6CB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_route_info_changed4(
	const XrlError&	e,
	XrlArgs*	a,
	RouteInfoChanged4CB		cb
    );

    void unmarshall_route_info_changed6(
	const XrlError&	e,
	XrlArgs*	a,
	RouteInfoChanged6CB		cb
    );

    void unmarshall_route_info_invalid4(
	const XrlError&	e,
	XrlArgs*	a,
	RouteInfoInvalid4CB		cb
    );

    void unmarshall_route_info_invalid6(
	const XrlError&	e,
	XrlArgs*	a,
	RouteInfoInvalid6CB		cb
    );

};

#endif /* __XRL_INTERFACES_RIB_CLIENT_XIF_HH__ */
