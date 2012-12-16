/*
    ChibiOS/GFX - Copyright (C) 2012
                 Joel Bodenmann aka Tectu <joel@unormal.org>

    This file is part of ChibiOS/GFX.

    ChibiOS/GFX is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/GFX is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    drivers/gdisp/VMT/gdisp_lld_driver2.c
 * @brief   GDISP Graphics Driver subsystem low level driver source for VMT.
 *
 * @addtogroup GDISP
 * @{
 */

#include "ch.h"
#include "hal.h"

#if GFX_USE_GDISP /*|| defined(__DOXYGEN__)*/

#define CONFIGFILE()	<../GDISP_VMT_NAME2()/gdisp_lld_config.h>
#define DRIVERFILE()	<../GDISP_VMT_NAME2()/gdisp_lld.c>

/* We don't need these in our VMT referenced driver */
#undef GDISP_NEED_MSGAPI
#define GDISP_NEED_MSGAPI	FALSE

/* Include the specific config file we want */
#include CONFIGFILE()

/* Bring in our API */
#include "gfx.h"

/* Add the low level driver */
#include DRIVERFILE()

#endif /* GFX_USE_GDISP */
/** @} */

