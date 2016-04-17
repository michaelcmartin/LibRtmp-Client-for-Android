//
// Created by faraklit on 08.02.2016.
//

#ifndef _XIECC_RTMP_H_
#define _XIECC_RTMP_H_
#include <stdint.h>
#include <stdbool.h>
#include "rtmp.h"
#ifdef __cplusplus
extern "C"{
#endif

#define RTMP_STREAM_PROPERTY_PUBLIC      0x00000001
#define RTMP_STREAM_PROPERTY_ALARM       0x00000002
#define RTMP_STREAM_PROPERTY_RECORD      0x00000004


int rtmp_open_for_write(const char *url, RTMP** rtmp);

int rtmp_close(RTMP* rtmp);

int rtmp_is_connected(RTMP* rtmp);

// @brief send audio frame
// @param [in] rtmp_sender handler
// @param [in] data       : AACAUDIODATA
// @param [in] size       : AACAUDIODATA size
// @param [in] dts_us     : decode timestamp of frame
int rtmp_sender_write_audio_frame(RTMP* rtmp, uint8_t *data,
                                  int size,
                                  uint64_t dts_us,
                                  uint32_t abs_ts);

// @brief send video frame, now only H264 supported
// @param [in] rtmp_sender handler
// @param [in] data       : video data, (Full frames are required)
// @param [in] size       : video data size
// @param [in] dts_us     : decode timestamp of frame
// @param [in] key        : key frame indicate, [0: non key] [1: key]
int rtmp_sender_write_video_frame(RTMP* rtmp, uint8_t *data,
                                  int size,
                                  uint64_t dts_us,
                                  int key,
                                  uint32_t abs_ts);


void flv_file_open(const char *filename);

void flv_file_close();

void write_flv_header(bool is_have_audio, bool is_have_video);

int rtmp_sender_set_chunk_size(RTMP* rtmp, int chunk_size);

#ifdef __cplusplus
}
#endif
#endif
