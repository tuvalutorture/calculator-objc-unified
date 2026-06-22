#include <TargetConditionals.h>
#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
	#import <UIKit/UIKit.h>
	#define	theType UITextField
# else
	#import <AppKit/AppKit.h>
	#define theType NSTextField
#endif

@interface CalculatorController : NSObject {
	IBOutlet theType* display;
	NSDictionary *operators;
	double memory;
	NSString* currentOperator;
	double currentBuffer, priorBuffer;
	BOOL clearable;
	BOOL wasLastButtonCalculation;
}

+ (id)addNumber:		(NSNumber*)num1 with:(NSNumber*)num2;
+ (id)subtractNumber:	(NSNumber*)num1 with:(NSNumber*)num2;
+ (id)divideNumber:		(NSNumber*)num1 with:(NSNumber*)num2;
+ (id)multiplyNumber:	(NSNumber*)num1 with:(NSNumber*)num2;

+ (NSString*)getButtonString:(id)button;
- (NSString*)displayText;
- (void)setDisplayText:(NSString*)string;
- (void)updateDisplay:(double)number;

- (IBAction)invokeNumberButton:		(id)sender;
- (IBAction)invokeOperatorButton:	(id)sender;

- (IBAction)clearCalculation:		(id)sender;

- (IBAction)performCalculation:		(id)sender;

- (IBAction)flipSign:				(id)sender;

- (IBAction)memoryClear:			(id)sender;
- (IBAction)memoryAdd:				(id)sender;
- (IBAction)memorySubtract:			(id)sender;
- (IBAction)memoryRecall:			(id)sender;
@end
