#ifndef XWAYLAND_COMPAT_H
#define XWAYLAND_COMPAT_H

#ifndef XORG_WAYLAND

#include "xorg-server.h"
#include "nv_include.h"

extern int xorgWayland;


struct xwl_screen;
struct xwl_window;

struct xwl_driver {
	int version;
	int use_drm;
	int (*create_window_buffer) (struct xwl_window *window, PixmapPtr pix);
};

int
xwl_drm_authenticate(struct xwl_screen *xwl_screen, uint32_t magic);

struct xwl_screen *
xwl_screen_create (void);

int
xwl_drm_pre_init(struct xwl_screen *xwl_screen);

int
xwl_screen_get_drm_fd(struct xwl_screen *xwl_screen);

void
xwl_screen_destroy(struct xwl_screen *xwl_screen);

void
xwl_screen_post_damage(struct xwl_screen *xwl_screen);

int
xwl_screen_init(struct xwl_screen *xwl_screen, ScreenPtr pScreen);

void
xwl_screen_close(struct xwl_screen *xwl_screen);

int
xwl_screen_pre_init(ScrnInfoPtr pScrn, struct xwl_screen *xwl_screen, int flags, struct xwl_driver *driver);

int
xwl_create_window_buffer_drm(struct xwl_window *xwl_window, PixmapPtr pixmap, int name);

#endif /* !XORG_WAYLAND */
#endif /* XWAYLAND_COMPAT_H */
