#ifndef __NV_PROTO_H__
#define __NV_PROTO_H__

/* in drmmode_display.c */
Bool drmmode_pre_init(ScrnInfoPtr pScrn, int fd, int cpp);
Bool drmmode_is_rotate_pixmap(ScrnInfoPtr pScrn, pointer pPixData,
			      struct nouveau_bo **);
void drmmode_adjust_frame(ScrnInfoPtr pScrn, int x, int y, int flags);

/* in nouveau_calc.c */
void nouveau_calc_arb(ScrnInfoPtr pScrn, int vclk, int bpp, int *burst, int *lwm);
int nouveau_calc_pll_mnp(ScrnInfoPtr pScrn, struct pll_lims *pll_lim, int clk,
			 struct nouveau_pll_vals *pv);

/* in nv_accel_common.c */
Bool NVAccelCommonInit(ScrnInfoPtr pScrn);
Bool NVAccelGetCtxSurf2DFormatFromPixmap(PixmapPtr pPix, int *fmt_ret);
Bool NVAccelGetCtxSurf2DFormatFromPicture(PicturePtr pPix, int *fmt_ret);
PixmapPtr NVGetDrawablePixmap(DrawablePtr pDraw);
void NVAccelFree(ScrnInfoPtr pScrn);

/* in nv_driver.c */
Bool   NVI2CInit(ScrnInfoPtr pScrn);

/* in nv_dri.c */
Bool NVDRIScreenInit(ScrnInfoPtr pScrn);
Bool NVDRIFinishScreenInit(ScrnInfoPtr pScrn);
void NVDRICloseScreen(ScrnInfoPtr pScrn);
Bool NVDRIGetVersion(ScrnInfoPtr pScrn);

/* in nouveau_dri2.c */
Bool nouveau_dri2_init(ScreenPtr pScreen);
void nouveau_dri2_fini(ScreenPtr pScreen);

/* in nv_dac.c */
Bool   NVDACInit(ScrnInfoPtr pScrn, DisplayModePtr mode);
void   NVDACSave(ScrnInfoPtr pScrn, vgaRegPtr vgaReg,
                 NVRegPtr nvReg, Bool saveFonts);
void   NVDACRestore(ScrnInfoPtr pScrn, vgaRegPtr vgaReg,
                    NVRegPtr nvReg, Bool restoreFonts);
void   NVDACLoadPalette(ScrnInfoPtr pScrn, int numColors, int *indices,
                        LOCO *colors, VisualPtr pVisual );
Bool   NVDACi2cInit(ScrnInfoPtr pScrn);

/* in nouveau_xv.c */
void NVInitVideo(ScreenPtr);
void NVTakedownVideo(ScrnInfoPtr);
void NVWaitVSync(ScrnInfoPtr pScrn, int crtc);
void NVSetPortDefaults (ScrnInfoPtr pScrn, NVPortPrivPtr pPriv);
unsigned int nv_window_belongs_to_crtc(ScrnInfoPtr, int, int, int, int);

/* in nv_setup.c */
void   RivaEnterLeave(ScrnInfoPtr pScrn, Bool enter);
void   NVCommonSetup(ScrnInfoPtr pScrn);

/* in nv_cursor.c */
Bool NVCursorInitRandr12(ScreenPtr pScreen);
void nv_crtc_show_cursor(xf86CrtcPtr crtc);
void nv_crtc_hide_cursor(xf86CrtcPtr crtc);
void nv_crtc_set_cursor_position(xf86CrtcPtr crtc, int x, int y);
void nv_crtc_set_cursor_colors(xf86CrtcPtr crtc, int bg, int fg);
void nv_crtc_load_cursor_image(xf86CrtcPtr crtc, CARD8 *image);
void nv_crtc_load_cursor_argb(xf86CrtcPtr crtc, CARD32 *image);

/* in nv_dma.c */
void  NVSync(ScrnInfoPtr pScrn);
Bool  NVInitDma(ScrnInfoPtr pScrn);
void  NVTakedownDma(ScrnInfoPtr pScrn);

/* in nouveau_exa.c */
Bool nouveau_exa_init(ScreenPtr pScreen);
Bool nouveau_exa_pixmap_is_onscreen(PixmapPtr pPixmap);
bool nouveau_exa_pixmap_is_tiled(PixmapPtr ppix);

/* in nouveau_wfb.c */
void nouveau_wfb_setup_wrap(ReadMemoryProcPtr *, WriteMemoryProcPtr *,
			    DrawablePtr);
void nouveau_wfb_finish_wrap(DrawablePtr);
void nouveau_wfb_init();

/* in nv_hw.c */
void NVCalcStateExt(ScrnInfoPtr,NVRegPtr,int,int,int,int,int,int);
void NVLoadStateExt(ScrnInfoPtr pScrn,NVRegPtr);
void NVUnloadStateExt(NVPtr,NVRegPtr);
void NVSetStartAddress(NVPtr,CARD32);

/* in nv_shadow.c */
void NVRefreshArea(ScrnInfoPtr pScrn, int num, BoxPtr pbox);

/* in nv_bios.c */
int NVParseBios(ScrnInfoPtr pScrn);
int call_lvds_script(ScrnInfoPtr pScrn, struct dcb_entry *dcbent, int head, enum LVDS_script script, int pxclk);
bool nouveau_bios_fp_mode(ScrnInfoPtr pScrn, DisplayModeRec *mode);
int nouveau_bios_parse_lvds_table(ScrnInfoPtr pScrn, int pxclk, bool *dl, bool *if_is_24bit);
int run_tmds_table(ScrnInfoPtr pScrn, struct dcb_entry *dcbent, int head, int pxclk);
int get_pll_limits(ScrnInfoPtr pScrn, uint32_t limit_match, struct pll_lims *pll_lim);
uint8_t * nouveau_bios_embedded_edid(ScrnInfoPtr pScrn);
int nouveau_bios_run_display_table(ScrnInfoPtr, struct dcb_entry *, int pxclk);

/* nv_crtc.c */
void nv_crtc_set_digital_vibrance(xf86CrtcPtr crtc, int level);
void nv_crtc_set_image_sharpening(xf86CrtcPtr crtc, int level);
void NVCrtcSetBase(xf86CrtcPtr crtc, int x, int y);
void nv_crtc_init(ScrnInfoPtr pScrn, int crtc_num);

/* nv_output.c */
void nv_encoder_restore(ScrnInfoPtr pScrn, struct nouveau_encoder *nv_encoder);
void nv_encoder_save(ScrnInfoPtr pScrn, struct nouveau_encoder *nv_encoder);
void NvSetupOutputs(ScrnInfoPtr pScrn);

/* nouveau_hw.c */
void NVWriteVgaSeq(NVPtr pNv, int head, uint8_t index, uint8_t value);
uint8_t NVReadVgaSeq(NVPtr pNv, int head, uint8_t index);
void NVWriteVgaGr(NVPtr pNv, int head, uint8_t index, uint8_t value);
uint8_t NVReadVgaGr(NVPtr pNv, int head, uint8_t index);
void NVSetOwner(NVPtr pNv, int owner);
int nouveau_hw_get_current_head(ScrnInfoPtr pScrn);
void NVBlankScreen(NVPtr pNv, int head, bool blank);
void nouveau_hw_setpll(ScrnInfoPtr pScrn, uint32_t reg1,
		       struct nouveau_pll_vals *pv);
int nouveau_hw_get_pllvals(ScrnInfoPtr pScrn, enum pll_types plltype,
			   struct nouveau_pll_vals *pllvals);
int nouveau_hw_pllvals_to_clk(struct nouveau_pll_vals *pllvals);
int nouveau_hw_get_clock(ScrnInfoPtr pScrn, enum pll_types plltype);
void nouveau_hw_save_vga_fonts(ScrnInfoPtr pScrn, bool save);
void nouveau_hw_save_state(ScrnInfoPtr pScrn, int head,
			   struct nouveau_mode_state *state);
void nouveau_hw_load_state(ScrnInfoPtr pScrn, int head,
			   struct nouveau_mode_state *state);
void nouveau_hw_load_state_palette(NVPtr pNv, int head,
				   struct nouveau_mode_state *state);

/* in nv_i2c.c */
int NV_I2CInit(ScrnInfoPtr pScrn, I2CBusPtr *bus_ptr, struct dcb_i2c_entry *dcb_i2c, char *name);

/* in nv04_video_overlay.c */
void NV04PutOverlayImage(ScrnInfoPtr, struct nouveau_bo *, int, int, int,
			 BoxPtr, int, int, int, int, short, short, short,
			 short, short, short, RegionPtr clipBoxes);
int NV04SetOverlayPortAttribute(ScrnInfoPtr, Atom, INT32, pointer);
int NV04GetOverlayPortAttribute(ScrnInfoPtr, Atom, INT32 *, pointer);
void NV04StopOverlay(ScrnInfoPtr);

/* in nv04_video_blitter.c */
void NVPutBlitImage(ScrnInfoPtr, struct nouveau_bo *, int, int, int, BoxPtr,
		    int, int, int, int, short, short, short, short, short,
		    short, RegionPtr, PixmapPtr);
int NVSetBlitPortAttribute(ScrnInfoPtr, Atom, INT32, pointer);
int NVGetBlitPortAttribute(ScrnInfoPtr, Atom, INT32 *, pointer);
void NVStopBlitVideo(ScrnInfoPtr, pointer, Bool);

/* in nv04_exa.c */
Bool NV04EXAPrepareSolid(PixmapPtr, int, Pixel, Pixel);
void NV04EXASolid(PixmapPtr, int, int, int, int);
void NV04EXADoneSolid(PixmapPtr);
Bool NV04EXAPrepareCopy(PixmapPtr, PixmapPtr, int, int, int, Pixel);
void NV04EXACopy(PixmapPtr, int, int, int, int, int, int);
void NV04EXADoneCopy(PixmapPtr);
Bool NV04EXAUploadIFC(ScrnInfoPtr, const char *src, int src_pitch,
		      PixmapPtr pdPix, int x, int y, int w, int h, int cpp);

/* in nv10_exa.c */
Bool NVAccelInitNV10TCL(ScrnInfoPtr pScrn);
Bool NV10EXACheckComposite(int, PicturePtr, PicturePtr, PicturePtr);
Bool NV10EXAPrepareComposite(int, PicturePtr, PicturePtr, PicturePtr,
			     PixmapPtr, PixmapPtr, PixmapPtr);
void NV10EXAComposite(PixmapPtr, int, int, int, int, int, int, int, int);
void NV10EXADoneComposite(PixmapPtr);

/* in nv10_video_overlay.c */
void NV10PutOverlayImage(ScrnInfoPtr, struct nouveau_bo *, int, int, int, int,
			 BoxPtr, int, int, int, int, short, short, short,
			 short, short, short, RegionPtr clipBoxes);
int NV10SetOverlayPortAttribute(ScrnInfoPtr, Atom, INT32, pointer);
int NV10GetOverlayPortAttribute(ScrnInfoPtr, Atom, INT32 *, pointer);
void NV10StopOverlay(ScrnInfoPtr);
void NV10WriteOverlayParameters(ScrnInfoPtr);

/* in nv30_exa.c */
Bool NVAccelInitNV30TCL(ScrnInfoPtr pScrn);
Bool NV30EXACheckComposite(int, PicturePtr, PicturePtr, PicturePtr);
Bool NV30EXAPrepareComposite(int, PicturePtr, PicturePtr, PicturePtr,
				  PixmapPtr, PixmapPtr, PixmapPtr);
void NV30EXAComposite(PixmapPtr, int, int, int, int, int, int, int, int);
void NV30EXADoneComposite(PixmapPtr);

/* in nv30_video_texture.c */
int NV30PutTextureImage(ScrnInfoPtr, struct nouveau_bo *, int, int, int, int,
			BoxPtr, int, int, int, int, uint16_t, uint16_t,
			uint16_t, uint16_t, uint16_t, uint16_t,
			RegionPtr, PixmapPtr, NVPortPrivPtr);
void NV30StopTexturedVideo(ScrnInfoPtr, pointer, Bool);
int NV30GetTexturePortAttribute(ScrnInfoPtr, Atom, INT32 *, pointer);
int NV30SetTexturePortAttribute(ScrnInfoPtr, Atom, INT32, pointer);

/* in nv40_exa.c */
Bool NVAccelInitNV40TCL(ScrnInfoPtr pScrn);
Bool NV40EXACheckComposite(int, PicturePtr, PicturePtr, PicturePtr);
Bool NV40EXAPrepareComposite(int, PicturePtr, PicturePtr, PicturePtr,
				  PixmapPtr, PixmapPtr, PixmapPtr);
void NV40EXAComposite(PixmapPtr, int, int, int, int, int, int, int, int);
void NV40EXADoneComposite(PixmapPtr);

/* in nv40_video_texture.c */
int NV40PutTextureImage(ScrnInfoPtr, struct nouveau_bo *, int, int, int, int,
			BoxPtr, int, int, int, int, uint16_t, uint16_t,
			uint16_t, uint16_t, uint16_t, uint16_t,
			RegionPtr, PixmapPtr, NVPortPrivPtr);
void NV40StopTexturedVideo(ScrnInfoPtr, pointer, Bool);
int NV40GetTexturePortAttribute(ScrnInfoPtr, Atom, INT32 *, pointer);
int NV40SetTexturePortAttribute(ScrnInfoPtr, Atom, INT32, pointer);

/* in nv50_accel.c */
Bool NVAccelInitNV50TCL(ScrnInfoPtr pScrn);

/* in nv50_exa.c */
Bool NV50EXAPrepareSolid(PixmapPtr, int, Pixel, Pixel);
void NV50EXASolid(PixmapPtr, int, int, int, int);
void NV50EXADoneSolid(PixmapPtr);
Bool NV50EXAPrepareCopy(PixmapPtr, PixmapPtr, int, int, int, Pixel);
void NV50EXACopy(PixmapPtr, int, int, int, int, int, int);
void NV50EXADoneCopy(PixmapPtr);
Bool NV50EXACheckComposite(int, PicturePtr, PicturePtr, PicturePtr);
Bool NV50EXAPrepareComposite(int, PicturePtr, PicturePtr, PicturePtr,
				  PixmapPtr, PixmapPtr, PixmapPtr);
void NV50EXAComposite(PixmapPtr, int, int, int, int, int, int, int, int);
void NV50EXADoneComposite(PixmapPtr);
Bool NV50EXAUploadSIFC(const char *src, int src_pitch,
		       PixmapPtr pdPix, int x, int y, int w, int h, int cpp);

/* in nv50_display.c */
Bool NV50DispPreInit(ScrnInfoPtr);
Bool NV50DispInit(ScrnInfoPtr);
void NV50DispShutdown(ScrnInfoPtr);

/* in nv50_cursor.c */
Bool NV50CursorInit(ScreenPtr);
Bool NV50CursorAcquire(ScrnInfoPtr);
void NV50CursorRelease(ScrnInfoPtr);

/* in nv50_crtc.c */
void NV50DisplayCommand(ScrnInfoPtr pScrn, uint32_t addr, uint32_t value);
void NV50CrtcCommand(nouveauCrtcPtr crtc, uint32_t addr, uint32_t value);
void NV50CrtcInit(ScrnInfoPtr pScrn);
void NV50CrtcDestroy(ScrnInfoPtr pScrn);

/* in nv50_output.c */
int NV50OrOffset(nouveauOutputPtr output);
void NV50OutputSetup(ScrnInfoPtr pScrn);
void NV50OutputDestroy(ScrnInfoPtr pScrn);

/* nv50_dac.c */
void NV50DacSetFunctionPointers(nouveauOutputPtr output);

/* nv50_sor.c */
void NV50SorSetFunctionPointers(nouveauOutputPtr output);

/* nv50_connector.c */
void NV50ConnectorInit(ScrnInfoPtr pScrn);
void NV50ConnectorDestroy(ScrnInfoPtr pScrn);

/* nv50_randr.c */
void nv50_crtc_init(ScrnInfoPtr pScrn, int crtc_num);
void nv50_output_create(ScrnInfoPtr pScrn);
int nv_scaling_mode_lookup(char *name, int size);

/* nv50_xv.c */
int nv50_xv_image_put(ScrnInfoPtr, struct nouveau_bo *, int, int, int, int,
		      BoxPtr, int, int, int, int, uint16_t, uint16_t,
		      uint16_t, uint16_t, uint16_t, uint16_t,
		      RegionPtr, PixmapPtr, NVPortPrivPtr);
void nv50_xv_video_stop(ScrnInfoPtr, pointer, Bool);
int nv50_xv_port_attribute_set(ScrnInfoPtr, Atom, INT32, pointer);
int nv50_xv_port_attribute_get(ScrnInfoPtr, Atom, INT32 *, pointer);

/* To support EXA 2.0, 2.1 has this in the header */
#ifndef exaMoveInPixmap
extern void exaMoveInPixmap(PixmapPtr pPixmap);
#endif

extern Bool wfbPictureInit(ScreenPtr, PictFormatPtr, int);

#endif /* __NV_PROTO_H__ */

