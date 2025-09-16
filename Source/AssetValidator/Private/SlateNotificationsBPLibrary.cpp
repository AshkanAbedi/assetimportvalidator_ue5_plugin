// Fill out your copyright notice in the Description page of Project Settings.
#include "SlateNotificationsBPLibrary.h"
#include "SlateBasics.h"
#include "Slate/SlateBrushAsset.h"
#include "EditorStyleSet.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Misc/Paths.h"

void USlateNotificationsBPLibrary::NotifySuccess(const FText& NotificationText, const FString& HyperlinkURL,
                                                 const FText& HyperlinkText)
{
	FNotificationInfo Info(NotificationText);
	Info.bFireAndForget = true;
	Info.bUseThrobber = false;
	Info.bUseLargeFont = true;
	Info.bUseSuccessFailIcons = false;
	Info.FadeInDuration = 0.2f;
	Info.FadeOutDuration = 0.5f;
	Info.ExpireDuration = 5.0f;
	Info.Image = FEditorStyle::GetBrush(TEXT("NotificationList.ItemImage_Success"));  // Green success icon

	if (!HyperlinkURL.IsEmpty())
	{
		Info.Hyperlink = FSimpleDelegate::CreateLambda([HyperlinkURL]()
		{
			FPlatformProcess::LaunchURL(*HyperlinkURL, nullptr, nullptr);
		});
		Info.HyperlinkText = HyperlinkText;
	}

	FSlateNotificationManager::Get().AddNotification(Info);
}

void USlateNotificationsBPLibrary::NotifyError(const FText& NotificationText, const FString& HyperlinkURL,
	const FText& HyperlinkText)
{
	FNotificationInfo Info(NotificationText);
	Info.bFireAndForget = true;
	Info.bUseThrobber = false;
	Info.bUseLargeFont = true;
	Info.bUseSuccessFailIcons = false;
	Info.FadeInDuration = 0.2f;
	Info.FadeOutDuration = 0.5f;
	Info.ExpireDuration = 5.0f;
	Info.Image = FEditorStyle::GetBrush(TEXT("NotificationList.ItemImage_Error"));  // Red error icon

	if (!HyperlinkURL.IsEmpty())
	{
		Info.Hyperlink = FSimpleDelegate::CreateLambda([HyperlinkURL]()
		{
			FPlatformProcess::LaunchURL(*HyperlinkURL, nullptr, nullptr);
		});
		Info.HyperlinkText = HyperlinkText;
	}

	FSlateNotificationManager::Get().AddNotification(Info);
}
