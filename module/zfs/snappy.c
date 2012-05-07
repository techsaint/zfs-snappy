/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */

/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#include <sys/debug.h>
#include <sys/types.h>
#include "snappy.h"

#ifdef _KERNEL
#include <sys/systm.h>
#else
#include <strings.h>
#endif

/*
 *s_start - beginning array pointer of data that needs to be compressed
 *d_start - beginning of destination array of compressed data
  size_t s_len - length of data that needs to be compressed
  size_t d_len - length of the destination array (length of data after compression)
 */

size_t
snappy_compress_zfs(void *s_start, void *d_start, size_t s_len, size_t d_len, int n)
{
	size_t dstlen = d_len;

	ASSERT(d_len <= s_len);
                struct snappy_env env;
                snappy_init_env(&env);
                //err = snappy_compress(&env, map, size, out, &outlen);

	if(snappy_compress(&env,s_start, s_len, d_start, &dstlen)){
		if (d_len != s_len)
			return (s_len);

		bcopy(s_start, d_start, s_len);
		return (s_len);
	}
	return dstlen;
}

/*ARGSUSED*/
int
snappy_decompress_zfs(void *s_start, void *d_start, size_t s_len, size_t d_len, int n)
{
	size_t dstlen = d_len;

	ASSERT(d_len >= s_len);
	//err = snappy_uncompress(map, size, out);
 
	if(snappy_uncompress(s_start, s_len, d_start)){
	  return(-1);
	}
	
	return (0);

}
