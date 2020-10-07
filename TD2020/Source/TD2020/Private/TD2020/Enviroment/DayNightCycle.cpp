// No copyright - copy as you please
#include "TD2020/Enviroment/DayNightCycle.h"


#include "Kismet/KismetMathLibrary.h"
#include "TD2020/Enviroment/Sky/MySkySphere.h"



// Sets default values
ADayNightCycle::ADayNightCycle()
{
    //DEFAULTS

    // INIT COMPONENTS
    Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
    RootComponent = Scene;

    Moon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Moon"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MoonAsset(
        TEXT("StaticMesh'/Game/TD2020/Meshes/Meshes/MaterialSphere.MaterialSphere'"));
    if (MoonAsset.Succeeded())
    {
        Moon->SetStaticMesh(MoonAsset.Object);
        Moon->SetRelativeLocation(FVector(-200000.0f, 0.0f, 0.0f));
        Moon->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
        Moon->SetWorldScale3D(FVector(100.0f));
    }
    Moon->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UMaterial> MatObj(
        TEXT("Material'/Game/TD2020/Materials/Sky/M_Moon.M_Moon'"));
    MoonMaterial = MatObj.Object;
    static ConstructorHelpers::FObjectFinder<UCurveLinearColor> SkyColorCurve_Helper(
        TEXT("CurveLinearColor'/Game/TD2020/Textures/Sky/C_Sky_Zenith_Color.C_Sky_Zenith_Color'"));
    SkyColor = SkyColorCurve_Helper.Object;


    //references - Set them in editor in world outline
    SunLight = nullptr;
    MoonLight = nullptr;
    SkySphere = nullptr;


    // properties
    TimeUnit = 1.0f;
    SunDays = 0;
    SunDrive = 12.0f;
    SunDayDuration = 24.0f;
    Clockwork = 0.0f;
    SunYearDuration = 365.25f;
    MaxDeclination = -23.5f;
    SunDeclination = 0.0f;
    Latitude = 46.0f;
    SunHalfDayLight = 0.0f;
    SunHalfNight = 0.0f;
    Shift = 0.0f;
    Length = 0.0f;
    DayNightFlip = -1.0f;
    SunPitch = 0.0f;
    SunYaw = 0.0f;
    SunDeclinationDrive = 0.0f;
    UseDayNightCycle = true;
    EquatorFlip = 1.0f;
    SunPolar = true;
    Seconds = 0;
    Minutes = 0;
    Hours = 0;
    GameTime = {Seconds, Minutes, Hours};
    DayTick = 0;
    UseSystemTime = false;
    Day = 1;
    Month = 1;
    Year = 1;
    GameDate = {Day, Month, Year};
    UseSystemDate = false;
    EarthLike = true;
    MoonDayDuration = 1.0f;
    MoonDeclination = 1.0f;
    MoonDeclinationDrive = 0.0f;
    MoonYearDuration = 27.0f;
    MoonInclination = 5.0f;
    MoonEquatorFlip = 1.0f;
    MoonDrive = 0.0f;
    MoonHalfDayLight = 0.0f;
    MoonHalfNight = 0.0f;
    MoonDayNightFlip = 0.0f;
    MoonShift = 0.0f;
    MoonLength = 0.0f;
    MoonPitch = 0.0f;
    MoonYaw = 0.0f;
    MoonMaterialInstance = nullptr;
    Valid = false;
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void ADayNightCycle::OnConstruction(const FTransform& Transform)
{
    // Create Material instance
    MoonMaterialInstance = UMaterialInstanceDynamic::Create(MoonMaterial, nullptr);
    Moon->SetMaterial(0, MoonMaterialInstance);


    //check if we use cycle
    if (!UseDayNightCycle)
    {
        PrimaryActorTick.bCanEverTick = false;
        Moon->SetVisibility(false);
        return;
    }

    // Else ROCK ON!

    MoonDayDuration = SunDayDuration / 24.0f * 24.833f;


    // DATE
    if (UseSystemDate)
    {
        FDateTime Now = UKismetMathLibrary::Now();
        Day = Now.GetDay();
        Month = Now.GetMonth();
        Year = Now.GetYear();
    }
    SunDeclinationDrive += Day - 1; // because it counts from 0
    MoonDeclinationDrive += (Day - 1) * SunDayDuration / MoonDayDuration;
    float Remainder = 0;
    UKismetMathLibrary::FMod((Day - 1) * SunDayDuration, MoonDayDuration, Remainder);
    MoonDrive += Remainder;

    if (EarthLike)
    {
        SunYearDuration = 365.25f;
        // SPECIFICS FOR MONTHS - LEAP YEARS ETC
        // from February
        if (Month >= 2)
        {
            for (int i = 1; i < Month - 1; i++)
            {
                // -1 because for current month you do not have to count days
                // to know how many months have past and convert it into days
                SunDeclinationDrive += UKismetMathLibrary::DaysInMonth(Year + 1, i);
            }
        }
    }
    GameDate = {Day, Month, Year};


    // TIME
    if (UseSystemTime)
    {
        FDateTime Now = UKismetMathLibrary::Now();
        //exits also UKismetMathLibrary::GetHour12()
        Clockwork = static_cast<float>(Now.GetHour() + Now.GetMinute() / 60.0f + Now.GetSecond() / 3600.0f);
    }
    else
    {
        Clockwork = static_cast<float>(Hours + Minutes / 60.0f + Seconds / 3600.0f);
    }

    // SunDeclinationDrive and SunDrive
    SunDeclinationDrive = Clockwork / 24.0f;
    SunDrive = SunDeclinationDrive * SunDayDuration;


    // MoonDeclinationDrive and MoonDrive
    MoonDeclinationDrive += SunDrive / MoonDayDuration;
    UKismetMathLibrary::FMod(SunDrive, MoonDayDuration, Remainder);
    MoonDrive += Remainder;


    // We set sun declination on begin play because of southern or northern hemisphere
    // we offset it by 11 days because it staTD2020 on 1. of january but max declination is on 21. December
    SunDeclination = UKismetMathLibrary::Cos(
        UKismetMathLibrary::MultiplyByPi(((SunDeclinationDrive + 11.0f) / SunYearDuration) * 2.0f)) * MaxDeclination;

    // check if its southern hemisphere or not - on begin play
    if (90 - Latitude + SunDeclination > 90) EquatorFlip = -1.0f;
    else EquatorFlip = 1.0f;

    // set polar day or night - on begin play
    SunPolar = (90.0f - (Latitude + SunDeclination) < 0.0f) || (90.0f - (Latitude - SunDeclination) < 0.0f);


    MoonDeclination = UKismetMathLibrary::Cos(
        UKismetMathLibrary::MultiplyByPi((MoonDeclinationDrive / MoonYearDuration) * 2.0f)) * MaxDeclination;
    // It takes 244 circles for inclination to finish its cycle
    // 5.4 is the 5.4 degrees of moon tilt
    MoonInclination = UKismetMathLibrary::Cos(
        UKismetMathLibrary::MultiplyByPi((MoonDeclinationDrive / MoonYearDuration / 244.0f) * 2.0f)) * 5.4;

    if (90.0f - Latitude + (MoonDeclination + MoonInclination) > 90.0f) MoonEquatorFlip = -1.0f;
    else MoonEquatorFlip = 1.0f;


    Valid = Validate();
    // on end of construction script it checks if assets are valid
    if (Valid)
    {
        // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
        PrimaryActorTick.bCanEverTick = true;
        Moon->SetVisibility(true);
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("INVALID INIT DAY NIGHT CYCLE"));
        PrimaryActorTick.bCanEverTick = false;
    }
}


// Called when the game staTD2020 or when spawned
void ADayNightCycle::BeginPlay()
{
    Super::BeginPlay();

    // call of OnConstruction function - Has to be called because only editor calls onConstruction on its own - Deployed game doesn't
    OnConstruction(FTransform());
}

// Called every frame
void ADayNightCycle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Check if valid - may have been changed from MySkySphere "UpdateSunDirection" function call
    if (!Valid)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
                                         TEXT("INVALID INIT DAY NIGHT CYCLE OR MY SKY SPHERE INIT"));
        PrimaryActorTick.bCanEverTick = false;
        return;
    }


    SunDrive += DeltaTime / TimeUnit;
    MoonDrive += DeltaTime / TimeUnit;


    SunDeclinationDrive = DeltaTime / TimeUnit / SunDayDuration + SunDeclinationDrive;
    MoonDeclinationDrive = DeltaTime / TimeUnit / MoonDayDuration + MoonDeclinationDrive;

    // Reset manually
    if (SunDeclination >= SunYearDuration) SunDeclination = 0.0f;

    //Set Clockwork -  as output of remainder and Day tick as return value
    DayTick = UKismetMathLibrary::FMod((DeltaTime / TimeUnit / SunDayDuration) * 24.f + Clockwork, 24.0f, Clockwork);

    // call of Sun trajectory function
    SunTrajectory();

    // Rotate sunLight
    SunLight->SetActorRotation(FRotator(SunPitch, SunYaw, 0.0f));

    // call of Sky sphere function
    Valid = SkySphere->UpdateSunDirection();

    MoonTrajectory();
    MoonLight->SetActorRotation(FRotator(MoonPitch, MoonYaw, 0.0f));

    FLatentActionInfo LatentInfo = FLatentActionInfo();
    LatentInfo.CallbackTarget = this;
    UKismetSystemLibrary::MoveComponentTo(Scene, Scene->GetComponentLocation(), FRotator(MoonPitch, MoonYaw, 0.0f),
                                          false, false, 0.0f, true, EMoveComponentAction::Move, LatentInfo);

    // change material
    MoonMaterialInstance->SetVectorParameterValue("MoonColor",
                                                  SkyColor->GetLinearColorValue(
                                                      UKismetMathLibrary::MapRangeUnclamped(
                                                          SunPitch, 0.0f, -18.0f, 0.0f, 1.0f)));


    // call clock
    Clock();

    // call calendar
    Calendar();

    //check for end of the day
    if (SunDrive >= SunDayDuration)
    {
        SunDrive = 0.0f;

        // check if its southern hemisphere or not
        if (90 - Latitude + SunDeclination > 90.0f) EquatorFlip = -1.0f;
        else EquatorFlip = 1.0f;

        // set polar day or night
        SunPolar = (90 - (Latitude + SunDeclination) < 0.0f) || (90 - (Latitude - SunDeclination) < 0.0f);
    }

    // Go to end of the year
    if (SunDeclinationDrive > SunYearDuration) SunDeclinationDrive = 0.0f;

    if (MoonDrive >= MoonDayDuration)
    {
        MoonDrive = 0.0f;
        if (90.0f - Latitude + (MoonDeclination + MoonInclination) > 90.0f) MoonEquatorFlip = -1.0f;
        else MoonEquatorFlip = 1.0f;
    }
    if (MoonDeclinationDrive > MoonYearDuration * 244.0f)
    {
        MoonDeclinationDrive = 0.0f;
    }
}

void ADayNightCycle::SunTrajectory()
{
    float MaxSunAngleHorizon = 0.0f;

    // we offset it by 11 days because it staTD2020 on 1. of January but max declination is on 21. December
    SunDeclination = UKismetMathLibrary::Cos(
        UKismetMathLibrary::MultiplyByPi((SunDeclinationDrive + 11.0f) / SunYearDuration) * 2.0f) * MaxDeclination;

    // Polar days and polar nights

    if (SunPolar)
    {
        //if sunrise
        if (SunDrive <= SunDayDuration * 0.25f)
        {
            // Night
            DayNightFlip = -1.0f;
            Shift = 0.0f;
        }
        else
        {
            //if sunrise to sunset
            if ((SunDrive > SunDayDuration * 0.25f) && (SunDrive <= SunDayDuration * 0.75f))
            {
                DayNightFlip = 1.0f;
                Shift = SunDayDuration / 2.0f;
            }
            else
            {
                //if night
                if (SunDrive > SunDayDuration * 0.75f)
                {
                    DayNightFlip = -1;
                    Shift = SunDayDuration;
                }
            }
        }
        // max angle of the sun above or below the horizon
        MaxSunAngleHorizon = 90.0f - Latitude - SunDeclination * DayNightFlip;

        SunPitch = (UKismetMathLibrary::Square(
            ((SunDrive - Shift) / (SunDayDuration * 0.25f)) * UKismetMathLibrary::Sqrt(
                90.0f - UKismetMathLibrary::Abs(Latitude))) * DayNightFlip) - (DayNightFlip * MaxSunAngleHorizon);
    }
    else
    {
        //sun half daylight - from sunrise to noon
        // 6.28319f is 360 in radians - can replace with UKismetMathLibrary::DegreesToRadians(360)
        SunHalfDayLight = UKismetMathLibrary::Acos(
            UKismetMathLibrary::DegTan(Latitude) * UKismetMathLibrary::DegTan(-SunDeclination)) / (6.28319f /
            SunDayDuration);

        //sun half night -from noon to night
        SunHalfNight = UKismetMathLibrary::Acos(
            UKismetMathLibrary::DegTan(Latitude) * UKismetMathLibrary::DegTan(SunDeclination)) / (6.28319f /
            SunDayDuration);

        //if sunrise
        if (SunDrive <= SunHalfNight)
        {
            // Night
            DayNightFlip = -1.0f;
            Shift = 0.0f;
            Length = SunHalfNight;
        }
        else
        {
            //if sunrise to sunset
            if ((SunDrive > SunHalfNight) && (SunDrive <= (SunHalfNight + 2 * SunHalfDayLight)))
            {
                DayNightFlip = 1.0f;
                Shift = SunDayDuration / 2.0f;
                Length = SunHalfDayLight;
            }
            else
            {
                //if night
                if (SunDrive > (SunHalfNight + 2 * SunHalfDayLight))
                {
                    DayNightFlip = -1;
                    Shift = SunDayDuration;
                    Length = SunHalfNight;
                }
            }
        }


        // max angle of the sun above or below the horizon
        MaxSunAngleHorizon = 90.0f - UKismetMathLibrary::Abs(Latitude - SunDeclination * DayNightFlip);

        SunPitch = (UKismetMathLibrary::Square(
            ((SunDrive - Shift) / Length) * UKismetMathLibrary::Sqrt(MaxSunAngleHorizon)) * DayNightFlip) - (
            DayNightFlip * MaxSunAngleHorizon);
    }

    // Equator flip - it flips for minus so it the sun will go from east to north to west to south [-1 or 1]
    SunYaw = (((SunDrive * 360.0f) / SunDayDuration) * EquatorFlip + 180.0f) + 90.0f * (1.0f - EquatorFlip);
}

void ADayNightCycle::MoonTrajectory()
{
    MoonDeclination = UKismetMathLibrary::Cos(
        UKismetMathLibrary::MultiplyByPi((MoonDeclinationDrive / MoonYearDuration) * 2.0f)) * MaxDeclination;
    // It takes 244 circles for inclination to finish its cycle
    // 5.4 is the 5.4 degrees of moon tilt
    MoonInclination = UKismetMathLibrary::Cos(
        UKismetMathLibrary::MultiplyByPi((MoonDeclinationDrive / MoonYearDuration / 244.0f) * 2.0f)) * 5.4;


    MoonHalfDayLight = UKismetMathLibrary::Acos(
        UKismetMathLibrary::DegTan(Latitude) * UKismetMathLibrary::DegTan(-(MoonDeclination + MoonInclination))) / (
        6.28319f / MoonDayDuration);

    //Moon half night -from noon to night
    MoonHalfNight = UKismetMathLibrary::Acos(
        UKismetMathLibrary::DegTan(Latitude) * UKismetMathLibrary::DegTan(MoonDeclination + MoonInclination)) / (
        6.28319f / MoonDayDuration);
    // Day- the object is above the horizon


    //if sunrise
    if (MoonDrive <= MoonHalfNight)
    {
        // Night
        MoonDayNightFlip = -1.0f;
        MoonShift = 0.0f;
        MoonLength = MoonHalfNight;
    }
    else
    {
        //if sunrise to sunset
        if (MoonDrive > MoonHalfNight && MoonDrive <= MoonHalfNight + 2 * MoonHalfDayLight)
        {
            MoonDayNightFlip = 1.0f;
            MoonShift = MoonDayDuration / 2.0f;
            MoonLength = MoonHalfDayLight;
        }
        else
        {
            //if night
            if (MoonDrive > (MoonHalfNight + 2 * MoonHalfDayLight))
            {
                MoonDayNightFlip = -1;
                MoonShift = MoonDayDuration;
                MoonLength = MoonHalfNight;
            }
        }
    }

    float MaxMoonAngleHorizon = 90.0f - UKismetMathLibrary::Abs(
        Latitude - (MoonDeclination * MoonDayNightFlip + MoonInclination * MoonDayNightFlip));

    MoonPitch = (UKismetMathLibrary::Square(
        ((MoonDrive - MoonShift) / MoonLength) * UKismetMathLibrary::Sqrt(MaxMoonAngleHorizon)) * MoonDayNightFlip) - (
        MoonDayNightFlip * MaxMoonAngleHorizon);
    MoonYaw = (((MoonDrive * 360.0f) / MoonDayDuration) * MoonEquatorFlip + 180.0f) + 90.0f * (1.0f - MoonEquatorFlip);
}

void ADayNightCycle::Clock()
{
    float Remainder = 0.0f;

    // set seconds
    int ReturnValue = UKismetMathLibrary::FMod(Clockwork * 3600.0f, 60.0f, Remainder);
    Seconds = UKismetMathLibrary::FFloor(Remainder);

    // set minutes
    ReturnValue = UKismetMathLibrary::FMod(static_cast<float>(ReturnValue), 60.0f, Remainder);
    Minutes = UKismetMathLibrary::FFloor(Remainder);

    // set hours
    UKismetMathLibrary::FMod(static_cast<float>(ReturnValue), 24.0f, Remainder);
    Hours = UKismetMathLibrary::FFloor(Remainder);

    GameTime = {Seconds, Minutes, Hours};
    FString GameTimeString = FString::FromInt(GameTime[0]) + " " + FString::FromInt(GameTime[1]) + " " +
        FString::FromInt(GameTime[2]);


    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(GameTime[0]));
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(GameTime[1]));
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(GameTime[2]));
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "");
}

void ADayNightCycle::Calendar()
{
    Day += DayTick;

    //game date[1] is month
    //game date[2] is year
    if (Day > UKismetMathLibrary::DaysInMonth(GameDate[2], GameDate[1]))
    {
        Day = 1;
        Month++;
    }
    if (Month > 12)
    {
        Month = 1;
        Year++;
    }

    // GameDay on 0 is 1
    GameDate = {Day, Month, Year};

    FString GameDateString = FString::FromInt(GameDate[0]) + " " + FString::FromInt(GameDate[1]) + " " +
        FString::FromInt(GameDate[2]);


    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, GameDateString);
}

bool ADayNightCycle::Validate()
{
    // returns true if everything is setup else false
    return (
        Scene->IsValidLowLevel() &&
        Moon->IsValidLowLevel() &&
        MoonMaterial->IsValidLowLevel() &&
        MoonMaterialInstance->IsValidLowLevel() &&
        SkyColor->IsValidLowLevel() &&
        SunLight->IsValidLowLevel() &&
        MoonLight->IsValidLowLevel() &&
        SkySphere->IsValidLowLevel()
    );
}
