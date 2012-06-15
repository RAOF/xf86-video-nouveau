#include "xwayland_compat.h"

int xorgWayland = 0;

int
xwl_drm_authenticate(struct xwl_screen *xwl_screen, uint32_t magic)
{
	return 0;
}

struct xwl_screen *
xwl_screen_create (void)
{
	return NULL;
}

int
xwl_drm_pre_init(struct xwl_screen *xwl_screen)
{
	return 0;
}

int
xwl_screen_get_drm_fd(struct xwl_screen *xwl_screen)
{
	return -1;
}

void
xwl_screen_destroy(struct xwl_screen *xwl_screen)
{
}

void
xwl_screen_post_damage(struct xwl_screen *xwl_screen)
{
}

int
xwl_screen_init(struct xwl_screen *xwl_screen, ScreenPtr pScreen)
{
	return 0;
}

void
xwl_screen_close(struct xwl_screen *xwl_screen)
{
}

int
xwl_screen_pre_init(ScrnInfoPtr pScrn, struct xwl_screen *xwl_screen, int flags, struct xwl_driver *driver)
{
	return 0;
}

int
xwl_create_window_buffer_drm(struct xwl_window *xwl_window, PixmapPtr pixmap, int name)
{
	return 0;
}

