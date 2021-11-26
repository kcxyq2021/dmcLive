/*
 * gsx_rtc_types.h
 *
 * Created by yuqilin on 12/23/2015
 * Copyright (C) 2015 yuqilin <iyuqilin@foxmail.com>
 *
 */

#ifndef GSX_RTC_TYPES_H
#define GSX_RTC_TYPES_H

#include <stdint.h>

#define RTC_INVALID_CHANNEL -1

typedef enum {
    kRTCMediaTypeNone   = 0,
    kRTCMediaTypeAudio  = 0x1,
    kRTCMediaTypeVideo  = 0x2,
} RTCMediaType;

typedef enum {
    kRTCProtocolUnknown = 0,
    kRTCProtocolRTMP    = 1,
    kRTCProtocolRTP     = 2,    
} RTCProtocol;

typedef enum {
    kRTCStreamModeUnknown   = 0,
    kRTCStreamModePull      = 1,
    kRTCStreamModePush      = 2,
} RTCStreamMode;

typedef struct {
    int codec_type;
    int channels;
    int samplerate;
    int samplesize;
    int bitrate;
} RTCAudioDescription;

typedef struct {
    int codec_type;
    int width;
    int height;
    int framerate;
    int bitrate;
    int duration;
} RTCVideoDescription;

// 音频编码格式
enum {
    kAudioCodecAAC = 1,
    kAudioCodecSpeex = 2
};

typedef enum {
    kRTCMsgNone = 0,
    kRTCMsgGetMediaInfo = 1,
    kRTCMsgGetFirstVideoFrame   = 0x11,
    kRTCMsgRenderVideoFrame     = 0xFF11,
    kRTCMsgAVPublishFail        = 0xFF301,
    
    kRTCMsgSpeechInLevel          = 20, // 声音输入级别[0-9]
    
    // 以下消息均在回调函数参数param1中指定stream_id
    kRTCMsgAVConnectSuccess     = 100,  // 连接成功
    kRTCMsgAVConnectFail        = 101,  // 连接失败（前端切换不上报）
    kRTCMsgAVAudioPCMData       = 110,  // 音频原始数据
    kRTCMsgAVPlaySuccess        = 200,  // 播放成功
    kRTCMsgAVPlayFail           = 201,  // 播放失败（前端切换不上报）
    kRTCMsgAVPlayLag            = 202,  // 卡顿（上报）
    kRTCMsgAVPlaySwitch         = 203,  // 切换（前端切换并上报）
    kRTCMsgOpenAudioRecordFailed = 301, // 开启录音失败
    kRTCMsgOpenCameraFailed     = 302,  // 开启摄像头失败
    
    kRTCMsgStreamVideoSizeChanged = 400,    // 流视频宽高变化
    kRTCMsgSwitchVideoRate = 401, //切换视频码率

    kRTCMsgUpserverDisconnect   = 500, // 上行服务器断开
    kRTCMsgDownserverDisconnect = 501, // 下行服务器断开

    kRTCMsgDownTcpRealTimeBuffer = 600, // tcp拉流实时buffer大小
} RTCEngineMsg;

typedef struct {
    int x;
    int y;
    int width;
    int height;
} RTCRect;

typedef enum {
    RTC_VIDEO_DISPLAY_MODE_FIT,
    RTC_VIDEO_DISPLAY_MODE_FILL
} RTCVideoDisplayMode;

typedef void (*gsx_rtc_engine_msg_callback)(void *priv, int msg, int param1, int param2, uint8_t param3[]);

typedef void (*gsx_rtc_engine_ios_log_callback)(void *priv, const char *str);

//卡顿相关阈值
typedef struct {
    //fps block
    int32_t cameraStreamFps;
    int32_t screenStreamFps;
    int32_t mediaFileStreamFps;

    //lost block
    int32_t audioAveLost;
    int32_t videoAveLost;
} BlockThresholdParams;

//采集参数
typedef struct
{
    int32_t width;                  //采集宽
    int32_t height;                 //采集高
    int32_t maxFPS;                 //采集帧率
    int32_t bitrate;                //采集码率
    int32_t keyFrameInterval;       //采集关键帧间隔，单位s
} GsxVideoCaptureCapability;

//采集模式
typedef enum
{
    RTC_HORIZONTAL_CAPTURE  =0,  //横屏采集
    RTC_VERTICAL_CAPTURE    =1,  //竖屏采集
    RTC_ADAPTIVE_CAPTURE    =2   //自适应采集
} GsxCaptureModeType;

//采集帧类型
typedef enum
{
    FrameType_Unknown           = 0,
    FrameType_MetaInfo          = 1, //meta 信息sps和pps
    FrameType_KeyFrame          = 2, //关键帧
    FrameType_UnkeyFrame        = 3  //非关键帧
} GsxCaptureFrameType;


/*连接状态*/
typedef enum tagGsxLiveConnectStatus {
    GSX_CONNECT_STATUS_NON_CONNECTED = 0,               // 未连接
    GSX_CONNECT_STATUS_CONNECTING = 1,                  // 正在连接
    GSX_CONNECT_STATUS_CONNECTED = 2,                   // 已连接
} GsxLiveConnectStatus;

/*统计参数*/
typedef struct tagGsxLivePlayInfo {
    //  char                        watchId;                // 收看的视频源用户ID
    GsxLiveConnectStatus        connectStatus;          // 网络连接状态
    char                        connectIp[128];         // 服务器的ip地址
    int                         totalBytes;             // 服务器转发的总包数
    int                         dropBytes;              // 服务器转发的丢包数
    int                         upKbits;                // 本链接的上行带宽

    int                         audioTotalBytes;      // 服务器转发的音频总包数
    int                         audioDropBytes;       // 服务器转发的音频丢包数
    int                         audioUpKbits;         // 本链接的音频上行带宽

    int                         videoTotalBytes;      // 服务器转发的视频总包数
    int                         videoDropBytes;       // 服务器转发的视频丢包数
    int                         videoUpKbits;         // 本链接的上行视频带宽
    /* stream */
    int                         currentBytesPerSecond;  // 总码流（下载速度）
    int                         droppedFrames;          // 丢包数
    int                         maxBytesPerSecond;      // 最大码流
    int                         bufferTimeMax;          // 设置的最大缓冲时间
    int                         liveDelay;              // 延迟（可选）
    int                         videoBufferLength;      // 视频瞬时缓冲时长
    int                         videoBufferByteLength;  // 视频瞬时缓冲字节（可选）
    int                         videoBytesPerSecond;    // 视频码流
    int                         videoLossRate;          // 视频丢包率（可选）
    int                         videoCodec;             // 视频编码器（编号）
    int                         audioBufferLength;      // 音频瞬时缓冲时长
    int                         audioBufferByteLength;  // 音频瞬时缓冲字节（可选）
    int                         audioBytesPerSecond;    // 音频码流
    int                         audioLossRate;          // 音频丢包率（可选）
    int                         audioCodec;             // 音频编码器（编号）
    int                         pullStreamWidth;        // 拉流帧宽
    int                         pullStreamHeight;       // 拉流帧高
    int                         pushFps;                // 推流帧率
} GsxLivePlayInfo;

#endif /* !GSX_RTC_TYPES_H */
