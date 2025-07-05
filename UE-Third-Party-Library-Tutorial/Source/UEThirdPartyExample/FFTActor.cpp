// Fill out your copyright notice in the Description page of Project Settings.


#include "FFTActor.h"

// Sets default values
AFFTActor::AFFTActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFFTActor::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(0, 30.0f, FColor::Red, DoFFT());
	}
}

// Called every frame
void AFFTActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FString AFFTActor::DoFFT() {
	int is_inverse_fft = 0; // zero = forward transform, one = inverse transform
	// create the fft config
	kiss_fft_cfg config = kiss_fft_alloc(nfft, is_inverse_fft, NULL, NULL);
	// set up in and out data blocks
	kiss_fft_cpx in[nfft], out[nfft];
	// populate the input block with the desired data ( f( x ) = sqrt( x + 1 ) )
	for (int i = 0; i < nfft; i++) {
		in[i].r = FMath::Sqrt((float)(i + 1));
		in[i].i = 0;
	}
	// compute fft
	kiss_fft(config, in, out);
	// free config memory
	kiss_fft_free(config);
	// make result into a string
	FString outString;
	for (int i = 0; i < nfft; i++) {
		outString += FString::Printf(TEXT("  [%d]: real = %f, imag = %f\n"), i, out[i].r, out[i].i);
	}
	return outString;
}