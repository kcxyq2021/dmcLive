//
//  BJLRoomViewController.h
//  BJLiveUI-Base-BJLiveUI
//
//  Created by Ney on 7/8/21.
//  Copyright © 2021 BaijiaYun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BJLiveCore/BJLiveCore.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BJLRoomVCType) {
    BJLRoomVCTypeSmallClass = 1, //小班课
    BJLRoomVCTypeBigClass = 2,   //大班课
};

@protocol BJLRoomVCDelegate;


@interface BJLRoomCode : NSObject
/// 参加码
@property (nonatomic, copy) NSString *code;
/// 用户名
@property (nonatomic, copy) NSString *userName;
/// 用户头像
@property (nonatomic, copy, nullable) NSString *userAvatar;
@end

@interface BJLRoomID : NSObject
/// 教室 ID
@property (nonatomic, copy) NSString *roomID;
/// API sign
@property (nonatomic, copy) NSString *apiSign;
/// 用户，初始化时的属性未标记可为空的都需要有值，且字符值长度不能为0
@property (nonatomic, strong) BJLUser *user;
@end


@interface BJLRoomViewController: UIViewController
/**
 通过参加码创建教室，如果sdk没有集成type对应的uisdk，返回nil
 #param type  教室类型
 #param roomCode 参加码对象
 #return 教室
 */
+ (__kindof instancetype)instanceWithRoomType:(BJLRoomVCType)type roomCode:(BJLRoomCode *)roomCode;

/**
 通过roomID创建教室，如果sdk没有集成type对应的uisdk，返回nil
 #param type  教室类型
 #param roomID roomID对象
 #return 教室
 */
+ (__kindof instancetype)instanceWithRoomType:(BJLRoomVCType)type roomID:(BJLRoomID *)roomID;

/** 直播教室
 参考 `BJLiveCore` */
@property (nonatomic, readonly, nullable) BJLRoom *room;

/** 初始化时传入的 roomID 入参
*/
@property (nonatomic, readonly, nullable) BJLRoomID *roomID;

/** 初始化时传入的 roomCode 入参
*/
@property (nonatomic, readonly, nullable) BJLRoomCode *roomCode;

/** 教室的类型，大班课或者小班课
*/
@property (nonatomic, readonly) BJLRoomVCType roomVCType;

/** 跑马灯内容 */
@property (nonatomic, copy, nullable) NSString *customLampContent;

/** 退出教室 */
- (void)exitWithCompletion:(void(^)(void))completion;

/** 事件回调 `delegate` */
@property (nonatomic, weak) id<BJLRoomVCDelegate> delegate;
@end



@protocol BJLRoomVCDelegate <NSObject>
@optional

/** 进入教室 - 成功/失败 */
- (void)roomViewControllerEnterRoomSuccess:(BJLRoomViewController *)roomViewController;
- (void)roomViewController:(BJLRoomViewController *)roomViewController enterRoomFailureWithError:(BJLError *)error;

/**
 退出教室 - 正常/异常
 正常退出 `error` 为 `nil`，否则为异常退出
 参考 `BJLErrorCode` */
- (void)roomViewController:(BJLRoomViewController *)roomViewController willExitWithError:(nullable BJLError *)error;
- (void)roomViewController:(BJLRoomViewController *)roomViewController didExitWithError:(nullable BJLError *)error;

/**
 点击教室右上方分享按钮回调。仅仅大班课才会有回调
 */
- (nullable UIViewController *)roomViewControllerToShare:(BJLRoomViewController *)roomViewController;
@end


NS_ASSUME_NONNULL_END
