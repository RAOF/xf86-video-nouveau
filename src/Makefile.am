#  Copyright 2005 Adam Jackson.
#
#  Permission is hereby granted, free of charge, to any person obtaining a
#  copy of this software and associated documentation files (the "Software"),
#  to deal in the Software without restriction, including without limitation
#  on the rights to use, copy, modify, merge, publish, distribute, sub
#  license, and/or sell copies of the Software, and to permit persons to whom
#  the Software is furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice (including the next
#  paragraph) shall be included in all copies or substantial portions of the
#  Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  IN NO EVENT SHALL
#  ADAM JACKSON BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
#  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# this is obnoxious:
# -module lets us name the module exactly how we want
# -avoid-version prevents gratuitous .0.0.0 version numbers on the end
# _ladir passes a dummy rpath to libtool so the thing will actually link
# TODO: -nostdlib/-Bstatic/-lgcc platform magic, not installing the .a, etc.
AM_CFLAGS = @XORG_CFLAGS@ @LIBUDEV_CFLAGS@ @LIBDRM_NOUVEAU_CFLAGS@
nouveau_drv_la_LTLIBRARIES = nouveau_drv.la
nouveau_drv_la_LDFLAGS = -module -avoid-version @LIBDRM_NOUVEAU_LIBS@ \
			 @LIBUDEV_LIBS@
nouveau_drv_ladir = @moduledir@/drivers

nouveau_drv_la_SOURCES = \
			 nouveau_exa.c nouveau_xv.c nouveau_dri2.c \
			 nouveau_wfb.c \
			 nv_accel_common.c \
			 nv_dma.c \
			 nv_driver.c \
			 nv_shadow.c \
			 nv04_exa.c \
			 nv04_xv_ovl.c \
			 nv04_xv_blit.c \
			 nv10_exa.c \
			 nv10_xv_ovl.c \
			 nv30_exa.c \
			 nv30_xv_tex.c \
			 nv40_exa.c \
			 nv40_xv_tex.c \
			 nv50_accel.c \
			 nv50_exa.c \
			 nv50_xv.c \
			 nvc0_accel.c \
			 nvc0_exa.c \
			 nvc0_xv.c \
			 drmmode_display.c \
			 vl_hwmc.c

if !XORG_WAYLAND
nouveau_drv_la_SOURCES += xwayland_compat.c
endif

EXTRA_DIST = hwdefs/nv_3ddefs.xml.h \
	     hwdefs/nv_m2mf.xml.h \
	     hwdefs/nv_object.xml.h \
	     hwdefs/nv01_2d.xml.h \
	     hwdefs/nv10_3d.xml.h \
	     hwdefs/nv30-40_3d.xml.h \
	     hwdefs/nv50_2d.xml.h \
	     hwdefs/nv50_3d.xml.h \
	     hwdefs/nv50_defs.xml.h \
	     hwdefs/nv50_texture.h \
	     hwdefs/nvc0_3d.xml.h \
	     hwdefs/nvc0_m2mf.xml.h \
	     nouveau_local.h \
	     nv_const.h \
	     nv_dma.h \
	     nv_include.h \
	     nv_proto.h \
	     nv_rop.h \
	     nv_type.h \
	     nv04_accel.h \
	     nv50_accel.h \
	     nvc0_accel.h \
	     nvc0_shader.h \
	     nve0_shader.h \
	     compat-api.h \
	     vl_hwmc.c \
	     vl_hwmc.h



