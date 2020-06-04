/*
 * OWL: an open Apple Wireless Direct Link (AWDL) implementation
 * Copyright (C) 2018  The Open Wireless Link Project (https://owlink.org)
 * Copyright (C) 2018  Milan Stute
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef OWL_NETUTILS_H_
#define OWL_NETUTILS_H_

#include <netinet/in.h>
#include <net/ethernet.h>

/**
 * Needs to be run once before netutils can be used (platform-dependent).
 *
 * For example, on Linux, sets up nl80211 socket and state.
 *
 * @return 0 on success, a negative value on failure
 */
int netutils_init();

/**
 * Clean up methods if netutils are no longer needed (platform-dependent)
 */
void netutils_cleanup();

int set_monitor_mode(int ifindex);

int set_channel(int ifindex, int channel);

int link_up(int ifindex);

int link_down(int ifindex);

int link_ether_addr_get(const char *ifname, struct ether_addr *addr);

int get_hostname(char *name, size_t len);

int neighbor_add(int ifindex, const struct ether_addr *, const struct in6_addr *);

int neighbor_remove(int ifindex, const struct in6_addr *);

int neighbor_add_rfc4291(int ifindex, const struct ether_addr *);

int neighbor_remove_rfc4291(int ifindex, const struct ether_addr *);

void rfc4291_addr(const struct ether_addr *eth, struct in6_addr *in6);

#endif /* OWL_NETUTILS_H_ */
