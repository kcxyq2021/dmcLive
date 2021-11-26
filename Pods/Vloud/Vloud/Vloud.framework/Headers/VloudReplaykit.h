//
//  VloudReplaykit.h
//  products
//
//  Created by DeskMac on 2021/2/4.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import "RTCMacros.h"
RTC_OBJC_EXPORT

@protocol VloudReplaykitDelegate <NSObject>
@optional
/**
 * 当屏幕分享开始时，SDK 会通过此回调通知
 */
- (void)onReplaykitStarted;

/**
 * 当屏幕分享暂停时，SDK 会通过此回调通知
 *
 * @param reason 原因，0：用户主动暂停；
 */
- (void)onReplaykitPaused:(int)reason;

/**
 * 当屏幕分享恢复时，SDK 会通过此回调通知
 *
 * @param reason 恢复原因，0：用户主动恢复；
 */
- (void)onReplaykitResumed:(int)reason;

/**
 * 当屏幕分享停止时，SDK 会通过此回调通知
 *
 * @param reason 停止原因，0：用户主动停止； 1: 异常终止
 */
- (void)onReplaykitStoped:(int)reason;

/**
 * 屏幕录制数据
 */
- (void)onReplaykitSampleBuffer:(CMSampleBufferRef)sampleBuffer rotation:(int)rotation;

@end

@class VloudReplaykitVideoConfig;

RTC_OBJC_EXPORT
@interface VloudReplaykit : NSObject

@property (nonatomic, weak) id<VloudReplaykitDelegate> delegate;

- (void)startScreenCaptureInApp:(VloudReplaykitVideoConfig *)config;
- (void)startScreenCaptureByReplaykit:(VloudReplaykitVideoConfig *)config appGroup:(NSString *)appGroup;
- (int)stopScreenCapture;
- (int)pauseScreenCapture;
- (int)resumeScreenCapture;

@end


