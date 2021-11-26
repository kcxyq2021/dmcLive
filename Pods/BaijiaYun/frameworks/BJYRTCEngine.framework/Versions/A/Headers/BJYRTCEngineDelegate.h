//
//  BJYRTCEngineDelegate.h
//  BJYRTCEngine
//
//  Created by bjy on 2018/11/5.
//  Copyright © 2018 BaiJiaYun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BJYRTCEngine/BJYRTCEngineDefines.h>
#import <BJYRTCEngine/BJYRTCMessage.h>

#ifndef BJYRTCEngineDelegate_h
#define BJYRTCEngineDelegate_h

@class BJYRTCEngine;

@protocol BJYRTCEngineDelegate <NSObject>

@optional
#pragma mark - 信令和流程
/// 加入房间回调
- (void)joinRoomSuccessWithEngine:(BJYRTCEngine *)engine;

/// 获得媒体服务器列表回调、声网不支持
- (void)engine:(BJYRTCEngine *)engine serverDic:(NSDictionary *)dic;

/// 信令、流程方面错误
- (void)engine:(BJYRTCEngine *)engine roomMessage:(BJYRTCMessage *)roomMessage;

#pragma mark - publisher
/// 推流回调 pc ice 3 // publish + mute(不推流)
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType publishSuccessWithUserId:(NSString *)userId;

/// 取消推流回调
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType unPublishSuccessWithUserId:(NSString *)userId;

/// 推流 不成功 错误
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType publisherMessage:(BJYRTCMessage *)publisherMessage;

#pragma mark - subscuber
/// 远端停止推流
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType remoteUnPublishWithUserId:(NSString *)userId;
/// 远端开始推流 开始loading // mute(不拉流)
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType remotePublishWithUserId:(NSString *)userId;
/// 订阅回调
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType subscribeSuccessWithUserId:(NSString *)userId;

/// 取消订阅回调、声网不支持
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType unsubscribeSuccessWithUserId:(NSString *)userId;

/// 远端流到达 getplayerview
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType receivedStreamWithUserId:(NSString *)userId;

/// 远端流首帧渲染 取消loading
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType firstFrameRenderedWithUserID:(NSString *)userID;

/// mute音频回调 subscriber
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType muteAudioSuccessWithUserId:(NSString *)userId;

/// mute视频回调 subscirber
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType muteVideoSuccessWithUserId:(NSString *)userId;

/// subscriber error
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType subscriberMessage:(BJYRTCMessage *)subscriberMessage withUserID:(NSString *)userID;

#pragma mark - 音视频质量
/// 音量改变通知 范围[0,255]
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType onVolumeChangeWithUserIdDictionary :(NSDictionary *)userIdDictionary;

/// 网络状况回调
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType onNetworkQuality:(BJYRTCEngineNetworkQuality)result userId:(NSString *)userId;

/// 音频丢包率回调
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType onAudioLostPercent:(float)lost userId:(NSString *)userId;

/// 视频丢包率回调
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType onVideoLostPercent:(float)lost userId:(NSString *)userId;

/// Candidate回调、声网不支持
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType allCandidateDic:(NSDictionary *)AllUserersIpDic;

/// 音视频参数回调、声网不支持
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType qosDic:(NSDictionary *)dic;

/// 卡顿回调 type: BJYBlockType_Up为上行 BJYBlockType_Down为下行
//- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType userID:(NSString *)userID videoResolution:(BJYVideoResolution)videoResolution blockType:(BJYBlockType)type containThirdSDKBlock:(BOOL)containThirdSDKBlock;
- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType userID:(NSString *)userID videoResolution:(BJYVideoResolution)videoResolution blockType:(BJYBlockType)type isBottomJudeBlock:(BOOL)isBottomJudeBlock isThirdSDKBlock:(BOOL)isThirdSDKBlock;

/// 媒体服务器断开回调、声网不支持 type: BJYBlockType_Up为推流 BJYBlockType_Down为拉流
//- (void)engine:(BJYRTCEngine *)engine sessionType:(BJYRTCSessionType)sessionType userID:(NSString *)userID videoResolution:(BJYVideoResolution)videoResolution disconnectType:(NSUInteger)type;


@end

#endif /* BJYRTCEngineDelegate_h */
