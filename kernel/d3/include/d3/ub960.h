/**
 * @author Greg Rowe <growe@d3engineering.com>
 *
 * Egregious kludge until a well though out approach to serdes can be
 * implemented.
 *
 * Copyright (c) 2019, D3 Engineering.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _UB960_H
#define _UB960_H

#include <linux/i2c.h>

int ub960_s_stream(struct i2c_client *self,
		   struct i2c_client *src,
		   int enable);

#endif
