/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/finder_client_base.hh,v 1.13 2003/06/19 00:44:46 hodson Exp $
 */


#ifndef __XRL_INTERFACES_FINDER_CLIENT_BASE_HH__
#define __XRL_INTERFACES_FINDER_CLIENT_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlFinderClientTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlFinderclientTargetBase {
protected:
    XrlCmdMap* _cmds;

public:
    /**
     * Constructor.
     *
     * @param cmds an XrlCmdMap that the commands associated with the target
     *		   should be added to.  This is typically the XrlRouter
     *		   associated with the target.
     */
    XrlFinderclientTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlFinderclientTargetBase();

    /**
     * Set command map.
     *
     * @param cmds pointer to command map to associate commands with.  This
     * argument is typically a pointer to the XrlRouter associated with the
     * target.
     *
     * @return true on success, false if cmds is null or a command map has
     * already been supplied.
     */
    bool set_command_map(XrlCmdMap* cmds);

    /**
     * Get Xrl instance name associated with command map.
     */
    inline const string& name() const { return _cmds->name(); }

    /**
     * Get version string of instance.
     */
    inline const char* version() const { return "finderclient/0.0"; }

protected:

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get name of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_target_name(
	// Output values,
	string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get version string from Xrl Target
     */
    virtual XrlCmdError common_0_1_get_version(
	// Output values,
	string&	version) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get status of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_status(
	// Output values,
	uint32_t&	status,
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Request clean shutdown of Xrl Target
     */
    virtual XrlCmdError common_0_1_shutdown() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  No op method used by finder to poll for liveness.
     */
    virtual XrlCmdError finder_client_0_2_hello() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Remove Xrl from cache. The client should remove currently cached value
     *  for Xrl from it's cached. On the next invocation of Xrl, the client
     *  will need to consult the Finder for updated information, though
     *  implementations may consult the Finder for updated information before.
     */
    virtual XrlCmdError finder_client_0_2_remove_xrl_from_cache(
	// Input values,
	const string&	xrl) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Remove all Xrls relating to target from cache.
     */
    virtual XrlCmdError finder_client_0_2_remove_xrls_for_target_from_cache(
	// Input values,
	const string&	target_name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Execute tunneled Xrl. Permits finder to call methods on clients through
     *  FinderClient.
     */
    virtual XrlCmdError finder_client_0_2_dispatch_tunneled_xrl(
	// Input values,
	const string&	xrl,
	// Output values,
	uint32_t&	xrl_error,
	string&	xrl_error_note) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_client_0_2_hello(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_client_0_2_remove_xrl_from_cache(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_client_0_2_remove_xrls_for_target_from_cache(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_client_0_2_dispatch_tunneled_xrl(const XrlArgs& in, XrlArgs* out);

    void add_handlers()
    {
	if (_cmds->add_handler("common/0.1/get_target_name",
	    callback(this, &XrlFinderclientTargetBase::handle_common_0_1_get_target_name)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://finderclient/common/0.1/get_target_name");
	}
	if (_cmds->add_handler("common/0.1/get_version",
	    callback(this, &XrlFinderclientTargetBase::handle_common_0_1_get_version)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://finderclient/common/0.1/get_version");
	}
	if (_cmds->add_handler("common/0.1/get_status",
	    callback(this, &XrlFinderclientTargetBase::handle_common_0_1_get_status)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://finderclient/common/0.1/get_status");
	}
	if (_cmds->add_handler("common/0.1/shutdown",
	    callback(this, &XrlFinderclientTargetBase::handle_common_0_1_shutdown)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://finderclient/common/0.1/shutdown");
	}
	if (_cmds->add_handler("finder_client/0.2/hello",
	    callback(this, &XrlFinderclientTargetBase::handle_finder_client_0_2_hello)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://finderclient/finder_client/0.2/hello");
	}
	if (_cmds->add_handler("finder_client/0.2/remove_xrl_from_cache",
	    callback(this, &XrlFinderclientTargetBase::handle_finder_client_0_2_remove_xrl_from_cache)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://finderclient/finder_client/0.2/remove_xrl_from_cache");
	}
	if (_cmds->add_handler("finder_client/0.2/remove_xrls_for_target_from_cache",
	    callback(this, &XrlFinderclientTargetBase::handle_finder_client_0_2_remove_xrls_for_target_from_cache)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://finderclient/finder_client/0.2/remove_xrls_for_target_from_cache");
	}
	if (_cmds->add_handler("finder_client/0.2/dispatch_tunneled_xrl",
	    callback(this, &XrlFinderclientTargetBase::handle_finder_client_0_2_dispatch_tunneled_xrl)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://finderclient/finder_client/0.2/dispatch_tunneled_xrl");
	}
	_cmds->finalize();
    }

    void remove_handlers()
    {
	_cmds->remove_handler("common/0.1/get_target_name");
	_cmds->remove_handler("common/0.1/get_version");
	_cmds->remove_handler("common/0.1/get_status");
	_cmds->remove_handler("common/0.1/shutdown");
	_cmds->remove_handler("finder_client/0.2/hello");
	_cmds->remove_handler("finder_client/0.2/remove_xrl_from_cache");
	_cmds->remove_handler("finder_client/0.2/remove_xrls_for_target_from_cache");
	_cmds->remove_handler("finder_client/0.2/dispatch_tunneled_xrl");
    }
};

#endif /* __XRL_INTERFACES_FINDER_CLIENT_BASE_HH__ */
