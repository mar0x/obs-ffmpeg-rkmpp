/*
Plugin Name
Copyright (C) <Year> <Developer> <Email Address>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program. If not, see <https://www.gnu.org/licenses/>
*/

#include <obs-module.h>
#include "plugin-support.h"
#include <libavcodec/avcodec.h>

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE(PLUGIN_NAME, "en-US")

extern struct obs_encoder_info ffmpeg_h264_rkmpp_encoder;
extern struct obs_encoder_info ffmpeg_hevc_rkmpp_encoder;
//extern struct obs_encoder_info ffmpeg_mjpeg_rkmpp_encoder;

static void register_encoder_if_available(struct obs_encoder_info *info,
					  const char *id)
{
	const AVCodec *c = avcodec_find_encoder_by_name(id);
	if (c) {
		obs_register_encoder(info);
	}
}

bool obs_module_load(void)
{
	obs_log(LOG_INFO, "plugin loaded successfully (version %s)", PLUGIN_VERSION);

	register_encoder_if_available(&ffmpeg_h264_rkmpp_encoder, "h264_rkmpp");
	register_encoder_if_available(&ffmpeg_hevc_rkmpp_encoder, "hevc_rkmpp");
	//register_encoder_if_available(&ffmpeg_mjpeg_rkmpp_encoder, "mjpeg_rkmpp");
	return true;
}

void obs_module_unload(void)
{
	obs_log(LOG_INFO, "plugin unloaded");
}
