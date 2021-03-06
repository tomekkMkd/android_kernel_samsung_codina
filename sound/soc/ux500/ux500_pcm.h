/*
 * Copyright (C) ST-Ericsson SA 2010
 *
 * Author: Ola Lilja <ola.o.lilja@stericsson.com>,
 *         Roger Nilsson <roger.xr.nilsson@stericsson.com>
 *         for ST-Ericsson.
 *
 * License terms:
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 */
#ifndef UX500_PCM_H
#define UX500_PCM_H

#include <asm/page.h>
#include <linux/workqueue.h>

#define UX500_PLATFORM_MIN_RATE_PLAYBACK 8000
#define UX500_PLATFORM_MAX_RATE_PLAYBACK 48000
#define UX500_PLATFORM_MIN_RATE_CAPTURE	8000
#define UX500_PLATFORM_MAX_RATE_CAPTURE	48000

#define UX500_PLATFORM_MIN_CHANNELS 1
#define UX500_PLATFORM_MAX_CHANNELS 8

#define UX500_PLATFORM_PERIODS_BYTES_MIN	128

/* Our DMA supports maximum of 131070 bytes segment size
 * So, we can support period_size of max 32767 frames
 */
#define UX500_PLATFORM_PERIODS_BYTES_MAX	131070

#define UX500_PLATFORM_PERIODS_MIN		2
#define UX500_PLATFORM_PERIODS_MAX		48
#define UX500_PLATFORM_BUFFER_BYTES_MAX		(2048 * PAGE_SIZE)

extern struct snd_soc_platform ux500_soc_platform;

struct ux500_pcm_private {
	struct dma_chan *pipeid;
	struct workqueue_struct *wq;
	struct work_struct ws_stop;
	int msp_id;
	int stream_id;
	unsigned int offset;
};

struct ux500_pcm_dma_params {
	unsigned int data_size;
	struct stedma40_chan_cfg *dma_cfg;
};

#endif
