//
//  BJYRoomOptions+Internal.h
//  BJYRTCEngine
//
//  Created by lw0717 on 2019/1/21.
//  Copyright © 2019年 BaiJiaYun. All rights reserved.
//

#import <BJYRTCEngine/BJYRoomOptions.h>

@interface BJYRoomOptions ()

#pragma mark - Private BJY
@property (nonatomic, readonly) NSString *token;

@property (nonatomic, readonly) NSString *mainCameraSessionID;
@property (nonatomic, readonly) NSString *mainScreenSharingSessionID;
@property (nonatomic, readonly) NSString *mainFileSessionID;
@property (nonatomic, readonly) NSString *extraCameraSessionID;
@property (nonatomic, readonly) NSString *extraScreenSharingSessionID;
@property (nonatomic, readonly) NSString *extraFileSessionID;

@property (nonatomic, readonly) NSDictionary *toolsWebrtcExt;
@property (nonatomic, readonly) NSDictionary *toolsResolution;
@property (nonatomic, readonly) NSArray *toolsLogUrl;
@property (nonatomic, readonly) NSNumber *toolsFirPeriod;

@property (nonatomic, readonly) NSDictionary *toolsAutoSwitch;

/// 声网小流配置高度，以确定对应在具体哪一分辨率配置项
@property (nonatomic, strong) NSNumber *agora_lowStreamHeight;
/// 声网小流分辨率配置项
@property (nonatomic, strong) NSDictionary *agora_lowStreamTools;

///  摄像头，媒体播放
@property (nonatomic, strong) NSNumber *videoLossRate;
@property (nonatomic, strong) NSNumber *audioLossRate;
@property (nonatomic, strong) NSNumber *pubFps;
@property (nonatomic, strong) NSNumber *subFps;
@property (nonatomic, strong) NSNumber *videoFrameDelay;
@property (nonatomic, strong) NSNumber *win;

///  屏幕分享
@property (nonatomic, strong) NSNumber *screenShareVideoLossRate;
@property (nonatomic, strong) NSNumber *screenShareAudioLossRate;
@property (nonatomic, strong) NSNumber *screenSharePubFps;
@property (nonatomic, strong) NSNumber *screenShareSubFps;
@property (nonatomic, strong) NSNumber *screenShareVideoFrameDelay;
@property (nonatomic, strong) NSNumber *screenShareWin;

/// BRTC APPID
@property (nonatomic, copy) NSString *brtc_appID; // todo: 冗余项，可以与声网 腾讯合并成一个


@property (nonatomic, copy) NSString *extraStr;

/// 默认拉流类型                                                                            
@property (nonatomic, assign) BJYVideoStreamType deafaultStreamType;

/**
 进房间前设置的对应userID的流类型, 只在首次拉到流后有效果
 {
   @"Camera_Main" : {
                  @"123":@(0)  //  0:未知流类型 1:大流  2:小流
                  },
   @"Camera_Extra" : {
                  @"123":@(0)  //  0:未知流类型 1:大流  2:小流
                  }
 }
 */

@property (nonatomic, strong) NSMutableDictionary *streamTypeDic;
@property (nonatomic, copy) NSString *streamTypeDicToken;

/// 是否开启双流模式
@property (nonatomic, assign) BOOL isDualStreamMode;
@property (nonatomic, assign) BJYSmallVideoLevel smallLevel;

@end
