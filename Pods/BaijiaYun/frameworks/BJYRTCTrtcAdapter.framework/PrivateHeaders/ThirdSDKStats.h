//
//  ThirdSDKStats.h
//  BJYRTCEngine
//
//  Created by DeskMac on 2020/7/7.
//  Copyright © 2020 BaiJiaYun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BJYRTCEngine/BJYRTCEngineDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class ThirdSDKStats;

@protocol ThirdSDKStatsDelegate <NSObject>
@optional
//- (void)blockSdkStats:(ThirdSDKStats *)stats userId:(NSString *)userId causeByAudio:(BOOL)audio causeByVideo:(BOOL)video containThirdSDKBlock:(BOOL)containThirdSDKBlock;
- (void)blockSdkStats:(ThirdSDKStats *)stats userId:(NSString *)userId isBottomJudeBlock:(BOOL)isBottomJudeBlock containThirdSDKBlock:(BOOL)containThirdSDKBlock;

@end

@interface ThirdSDKStats : NSObject
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, assign) BOOL isLocal;
@property (nonatomic, assign) BJYEngineType engineType;
@property (nonatomic, assign) BJYRTCSessionType sessionType;
@property (nonatomic, weak) id<ThirdSDKStatsDelegate> delegate;

@property (nonatomic, assign) BOOL containVideoByMuteAction;
@property (nonatomic, assign) BOOL containVideoByCallBack;
@property (nonatomic, assign) BOOL containAudioByMuteAction;
@property (nonatomic, assign) BOOL containAudioByCallBack;

@property (nonatomic, assign) NSUInteger txLossRate;
@property (nonatomic, assign) NSUInteger rxLossRate;
@property (nonatomic, assign) NSUInteger sentFrameRate;
@property (nonatomic, assign) NSUInteger renderFrameRate; // 拉流 - 声网
@property (nonatomic, assign) NSUInteger recvFrameRate; // 拉流 - 腾讯
@property (nonatomic, assign) NSUInteger videoLossRate; // 拉流 - 声网
@property (nonatomic, assign) NSUInteger audioLossRate; // 拉流 - 声网
@property (nonatomic, assign) NSUInteger finalLossRate; // 拉流 - 腾讯

@property (nonatomic, assign) NSUInteger blockThreshold; // 卡顿数组阈值
@property (nonatomic, assign) NSUInteger videoLostThreshold; // 视频丢包率判断卡顿阈值
@property (nonatomic, assign) NSUInteger audioLostThreshold; // 音频丢包率判断卡顿阈值
@property (nonatomic, assign) NSUInteger sentFrameRateThreshold; // 发送帧率阈值
@property (nonatomic, assign) NSUInteger renderFrameRateThreshold; // 渲染帧率阈值 (腾讯的接收帧率也是参考这个值)


@property (nonatomic, assign) NSUInteger audioOldTotalFrozenTime; // 上一次音频卡顿总时间 - 声网
@property (nonatomic, assign) NSUInteger audioCurrentTotalFrozenTime; // 当前音频卡顿总时间 - 声网
@property (nonatomic, assign) NSUInteger videoOldTotalFrozenTime; // 上一次视频卡顿总时间 - 声网
@property (nonatomic, assign) NSUInteger videoCurrentTotalFrozenTime; // 当前视频卡顿总时间 - 声网

@property (nonatomic, assign) BOOL didVideoBlock; // 腾讯sdk内部上报视频卡顿

- (instancetype)initWithUserId:(NSString *)userId isLocal:(BOOL)isLocal sessionType:(BJYRTCSessionType)sessionType engineType:(BJYEngineType)engineType;

@end

NS_ASSUME_NONNULL_END
