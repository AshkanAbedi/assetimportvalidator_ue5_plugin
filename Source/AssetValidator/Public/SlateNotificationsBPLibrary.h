// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SlateNotificationsBPLibrary.generated.h"

UCLASS()
class ASSETVALIDATOR_API USlateNotificationsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "Notifications")
	static void NotifySuccess(const FText& NotificationText, const FString& HyperlinkURL = "", const FText& HyperlinkText = FText::GetEmpty());

	UFUNCTION(BlueprintCallable, Category = "Notifications")
	static void NotifyError(const FText& NotificationText, const FString& HyperlinkURL = "", const FText& HyperlinkText = FText::GetEmpty());
};
