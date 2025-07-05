// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Use this for Unreal Engine versions 5.2 and below on Windows
 #if defined(_WIN64) || defined(_WIN32)
 #include <Windows/WindowsPlatformCompilerPreSetup.h>
 #endif

// Use this for all Unreal Engine versions on Apple systems for PRAGMA_DEFAULT_VISIBILITY_START.
// If for whatever reason you do not need that macro, you will still need this for Unreal Engine 
// versions 5.2 and below for THIRD_PARTY_INCLUDES
 #if defined(__APPLE__)
 // Other macros you may want to test here include: __OSX__, __APPLE_CC__, __MACH__, TARGET_OS_MAC,
 // TARGET_OS_IPHONE, and so on
 #include <Apple/ApplePlatformCompilerPreSetup.h>
 // <Mac/MacPlatformCompilerPreSetup.h> and <IOS/IOSPlatformCompilerPreSetup.h> also work
 // but only include the above header
 #endif

// Use this for all Unreal Engine versions on unix systems (linux specifically) for
// THIRD_PARTY_INCLUDES. Could work with apple but it has its own compiler 
// presetup header so you should probably just use that.
 #if defined(__linux__)
 // __unix__ can also work but may catch apple systems too
 #include <Unix/UnixPlatformCompilerPreSetup.h>
 // <Linux/LinuxPlatformCompilerPreSetup.h> also works but only includes the above header
 #endif

PRAGMA_DEFAULT_VISIBILITY_START
THIRD_PARTY_INCLUDES_START

#include <kiss_fft.h> //third party (private static dependency "Kiss_FFT")

THIRD_PARTY_INCLUDES_END
PRAGMA_DEFAULT_VISIBILITY_END

//GENERATED
#include "FFTActor.generated.h"

#define nfft 16 // number of samples in time and frequency domain

// Uncomment below if you want to redefine the kiss_fft_scalar [May generate compiler and build warnings]
// #define kiss_fft_scalar double

UCLASS()
// Logs FFT info to the screen when placed in an Unreal Engine Level
class UETHIRDPARTYEXAMPLE_API AFFTActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFFTActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Return a string of data about the FFT
	FString DoFFT();

};
