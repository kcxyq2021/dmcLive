//
//  BJYPlayerView+Internal.h
//  BJYRTCEngine
//
//  Created by bjy on 2018/11/5.
//  Copyright © 2018 BaiJiaYun. All rights reserved.
//

#import <BJYRTCEngine/BJYRTCEngine.h>
#import "BJYRTCAdapter.h"
#import <BJRTCSDK/BJRTCSDK.h>
#import <TXLiteAVSDK_TRTC/TRTCCloud.h>

@class AgoraRtcVideoCanvas;

@protocol SetRenderModeDelegate <NSObject>

@optional
//- (void)agoraChangeRenderMode:(AgoraRtcVideoCanvas *)canvas isLocal:(BOOL)isLocal; // 声网渲染模式
//- (void)trtcChangeRenderMode:(TRTCVideoFillMode)mode sessionType:(BJYRTCSessionType)sessionType userID:(NSString *)userID; // 腾讯渲染模式
//- (void)brtcChangeRenderMode:(BRTCVideoFillMode)mode sessionType:(BJYRTCSessionType)sessionType userID:(NSString *)userID; // BRTC渲染模式
@end

@interface BJYPlayerView ()


@property (nonatomic, assign) BOOL isVideoMuted; // 是否黑帧，视频是否禁用

@property (nonatomic, strong) UIView * videoView;

//BJRTC
@property (nonatomic, strong) UIImage *previewImage;

////TRTC
//@property (nonatomic, assign) TRTCVideoFillMode fillMode; 
//
////BRTC
//@property (nonatomic, assign) BRTCVideoFillMode brtcFillMode;


//public for use
@property (nonatomic, assign) BOOL isLocalVideo;
@property (nonatomic, assign) BJYEngineType engineType;
@property (nonatomic, assign) BJYRTCSessionType sessionType;
@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, copy) NSString *userID;
@property (nonatomic, weak) BJYRTCAdapter *adapter;

@property (nonatomic, assign) CGSize videoDimensions;

@property (nonatomic, weak) id <SetRenderModeDelegate> internalDelegate;

@property (nonatomic, strong) BJRTCSFUPublisher *publisher;
@property (nonatomic, strong) BJRTCSFUSubscriber *subscriber;

@property (nonatomic, assign) BOOL isDebug;

@property (nonatomic, assign) BJYVideoFlipType flipType; // 仅针对本地推流,翻转类型

- (instancetype)initWithEngineType:(BJYEngineType)engineType
                       sessionType:(BJYRTCSessionType)sessionType
                         sessionID:(NSString *)sessionID
                            userID:(NSString *)userID;

- (void)setDebugText:(NSString *)text;

///
//- (BOOL)isLocal;
/// 流是否含有音频
- (BOOL)hasAudio;
/// 流是否含有视频
- (BOOL)hasVideo;
/// 禁用音频
- (void)disableAudio;
/// 禁用视频
- (void)disableVideo;
/// 打开音频
- (void)enableAudio;
/// 打开视频
- (void)enableVideo;
/// 关闭 publisher/subscriber
- (void)close;

@end
