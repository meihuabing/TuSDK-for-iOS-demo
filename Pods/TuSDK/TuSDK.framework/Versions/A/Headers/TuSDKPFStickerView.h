//
//  TuSDKPFStickerView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/4.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPFStickerResult.h"

@class TuSDKPFStickerItemView;
/**
 *  贴纸元件视图委托
 */
@protocol TuSDKPFStickerItemViewDelegate <NSObject>
/**
 *  贴纸元件关闭
 *
 *  @param view 贴纸元件视图
 */
- (void)onClosedStickerItemView:(TuSDKPFStickerItemView *)view;

/**
 *  选中贴纸元件
 *
 *  @param view 贴纸元件视图
 */
- (void)onSelectedStickerItemView:(TuSDKPFStickerItemView *)view;
@end

#pragma mark - TuSDKPFStickerItemView
/**
 *  贴纸元件视图
 */
@interface TuSDKPFStickerItemView : UIView
/**
 *  图片视图
 */
@property (nonatomic, readonly) UIImageView *imageView;
/**
 *  取消按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;
/**
 *  旋转缩放按钮
 */
@property (nonatomic, readonly) UIImageView *turnButton;

/**
 *  贴纸元件视图委托
 */
@property (nonatomic, assign) id<TuSDKPFStickerItemViewDelegate> delegate;

/**
 *  最小缩小比例(默认: 0.5f <= mMinScale <= 1)
 */
@property (nonatomic) CGFloat minScale;

/**
 *  边框宽度
 */
@property (nonatomic) CGFloat strokeWidth;

/**
 *  边框颜色
 */
@property (nonatomic, retain) UIColor *strokeColor;

/**
 *  选中状态
 */
@property (nonatomic) BOOL selected;

/**
 *  贴纸数据对象
 */
@property (nonatomic, retain) TuSDKPFSticker *sticker;

/**
 *  重置图片视图边缘距离
 */
- (void)resetImageEdge;

/**
 *  获取贴纸处理结果
 *
 *  @param regionRect 图片选区范围
 *
 *  @return 贴纸处理结果
 */
- (TuSDKPFStickerResult *)resultWithRegionRect:(CGRect)regionRect;
@end

#pragma mark - TuSDKPFStickerView
/**
 *  贴纸视图
 */
@interface TuSDKPFStickerView : UIView<TuSDKPFStickerItemViewDelegate>
/**
 *  添加一个贴纸
 *
 *  @param sticker 贴纸元素
 */
- (void)appenSticker:(TuSDKPFSticker *)sticker;

/**
 *  获取贴纸处理结果
 *
 *  @param regionRect 图片选区范围
 *
 *  @return 贴纸处理结果
 */
- (NSArray *)resultsWithRegionRect:(CGRect)regionRect;
@end
