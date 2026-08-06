// updated: skibidi
// roblox: 1.0.0
// sober: 1.0.0

#pragma once
#include <cstdint>

namespace offsets {

    namespace Atmosphere {
        constexpr std::uintptr_t Color = 0xB8;
        constexpr std::uintptr_t Decay = 0x20;
        constexpr std::uintptr_t Density = 0x38;
        constexpr std::uintptr_t Glare = 0x24;
        constexpr std::uintptr_t Haze = 0x3C;
        constexpr std::uintptr_t Offset = 0x40;
    }

    namespace Attachment {
        constexpr std::uintptr_t Axis = 0xB0;
        constexpr std::uintptr_t Visible = 0x30;
    }

    namespace BasePart {
        constexpr std::uintptr_t Primitive = 0x118;
        constexpr std::uintptr_t Reflectance = 0x20;
        constexpr std::uintptr_t Transparency = 0x24;
        constexpr std::uintptr_t Shape = 0x30;
        constexpr std::uintptr_t CastShadow = 0xCC;
        constexpr std::uintptr_t Locked = 0xC8;
        constexpr std::uintptr_t Massless = 0xC0;
        constexpr std::uintptr_t Size = 0x14;
        constexpr std::uintptr_t Material = 0x84;
        constexpr std::uintptr_t Anchored = 0x1B0;
        constexpr std::uintptr_t CanQuery = 0x1B1;
        constexpr std::uintptr_t CanTouch = 0x1B2;
    }

    namespace BloomEffect {
        constexpr std::uintptr_t Threshold = 0xCC;
    }

    namespace Camera {
        constexpr std::uintptr_t CFrame = 0xD0;
        constexpr std::uintptr_t Position = 0xF4;
        constexpr std::uintptr_t Rotation = 0xD0;
        constexpr std::uintptr_t CameraSubject = 0xC0;
        constexpr std::uintptr_t ViewportSize = 0x2C0;
        constexpr std::uintptr_t CameraType = 0;
    }

    namespace DataModel {
        constexpr std::uintptr_t CreatorId = 0x198;
        constexpr std::uintptr_t GameId = 0x1A0;
        constexpr std::uintptr_t JobId = 0x130;
        constexpr std::uintptr_t PlaceId = 0x170;
        constexpr std::uintptr_t ServerIp = 0x608;
        constexpr std::uintptr_t Workspace = 0x150;
        constexpr std::uintptr_t UniverseId = 0xD8;
        constexpr std::uintptr_t PrivateServerOwnerId = 0x318;
        constexpr std::uintptr_t SavaVersion = 0x17C;
    }

    namespace FakeDataModel {
        constexpr std::uintptr_t RealDataModel = 0x1D0;
        constexpr std::uintptr_t Pointer = 0x6DD15A0;
    }

    namespace Humanoid {
        constexpr std::uintptr_t WalkSpeed = 0x1C0;
        constexpr std::uintptr_t WalkSpeedCheck = 0x3AC;
        constexpr std::uintptr_t Health = 0x17C;
        constexpr std::uintptr_t MaxHealth = 0x178;
        constexpr std::uintptr_t HipHeight = 0x184;
        constexpr std::uintptr_t JumpHeight = 0x190;
        constexpr std::uintptr_t JumpPower = 0x194;
        constexpr std::uintptr_t MaxSlopeAngle = 0x19C;
        constexpr std::uintptr_t RigType = 0x24;
        constexpr std::uintptr_t AutoRotate = 0x1C4;
        constexpr std::uintptr_t SeatPart = 0x270;
        constexpr std::uintptr_t Sit = 0x2AC;
        constexpr std::uintptr_t PlatformStand = 0x2AD;
        constexpr std::uintptr_t DisplayDistanceType = 0x30;
        constexpr std::uintptr_t NameOcclusion = 0x4C;
        constexpr std::uintptr_t CameraOffset = 0x20;
        constexpr std::uintptr_t FloorMaterial = 0x59;
    }

    namespace Instance {
        constexpr std::uintptr_t ChildrenStride = 0x10;
        constexpr std::uintptr_t ClassDescriptor = 0x18;
        constexpr std::uintptr_t ClassName = 0x8;
        constexpr std::uintptr_t Name = 0x98;
        constexpr std::uintptr_t Parent = 0x68;
        constexpr std::uintptr_t ChildrenStart = 0x70;
        constexpr std::uintptr_t ChildrenEnd = 0x8;
    }

    namespace Lighting {
        constexpr std::uintptr_t Brightness = 0xD8;
    }

    namespace MaterialColors {
        constexpr std::uintptr_t Asphalt = 0x30;
        constexpr std::uintptr_t Basalt = 0x27;
        constexpr std::uintptr_t Brick = 0xF;
        constexpr std::uintptr_t Cobblestone = 0x33;
        constexpr std::uintptr_t Concrete = 0xC;
        constexpr std::uintptr_t CrackedLava = 0x2D;
        constexpr std::uintptr_t Glacier = 0x1B;
        constexpr std::uintptr_t Grass = 0x6;
        constexpr std::uintptr_t Ground = 0x2A;
        constexpr std::uintptr_t Ice = 0x36;
        constexpr std::uintptr_t LeafyGrass = 0x39;
        constexpr std::uintptr_t Limestone = 0x3F;
        constexpr std::uintptr_t Mud = 0x24;
        constexpr std::uintptr_t Pavement = 0x42;
        constexpr std::uintptr_t Rock = 0x18;
        constexpr std::uintptr_t Salt = 0x3C;
        constexpr std::uintptr_t Sand = 0x12;
        constexpr std::uintptr_t Sandstone = 0x21;
        constexpr std::uintptr_t Slate = 0x9;
        constexpr std::uintptr_t Snow = 0x1E;
        constexpr std::uintptr_t WoodPlanks = 0x15;
    }

    namespace MeshPart {
        constexpr std::uintptr_t CollisionFidelity = 0x20;
        constexpr std::uintptr_t MeshId = 0x2E0;
        constexpr std::uintptr_t RenderFidelity = 0x30;
        constexpr std::uintptr_t TextureId = 0x308;
    }

    namespace Model {
        constexpr std::uintptr_t PrimaryPart = 0x218;
    }

    namespace MouseService {
        constexpr std::uintptr_t InputObject = 0xF0;
    }

    namespace Player {
        constexpr std::uintptr_t Character = 0x250;
        constexpr std::uintptr_t DisplayName = 0x138;
        constexpr std::uintptr_t Team = 0x290;
        constexpr std::uintptr_t TeamColor = 0x30;
        constexpr std::uintptr_t UserId = 0xD8;
    }

    namespace Players {
        constexpr std::uintptr_t LocalPlayer = 0x120;
    }

    namespace Primitive {
        constexpr std::uintptr_t AssemblyLinearVelocity  = 0xC0;
        // Manual patch 
        constexpr std::uintptr_t AssemblyAngularVelocity = 0xCC;
        constexpr std::uintptr_t CFrame = 0xC8;
        constexpr std::uintptr_t Material = 0x88;
        constexpr std::uintptr_t Orientation = 0xC8;
        constexpr std::uintptr_t Position = 0xEC;
        constexpr std::uintptr_t PrimitiveFlags = 0x113;
        constexpr std::uintptr_t Rotation = 0xC8;
        constexpr std::uintptr_t AssemblyRotVelocity = 0xD4;
        constexpr std::uintptr_t Mass = 0xD8;
        constexpr std::uintptr_t LinearVelocity  = AssemblyLinearVelocity;
        constexpr std::uintptr_t AngularVelocity = AssemblyAngularVelocity;
    }

    namespace PrimitiveFlags {
        constexpr std::uintptr_t Anchored = 0x80;
        constexpr std::uintptr_t CanCollide = 0x1;
        constexpr std::uintptr_t CanQuery = 0x4;
        constexpr std::uintptr_t CanTouch = 0x2;
    }

    namespace Print {
        constexpr std::uintptr_t Print = 0x3EB8C60;
    }

    namespace RenderView {
        constexpr std::uintptr_t LightingValid = 0x228;
        constexpr std::uintptr_t SkyboxValid = 0x28D;
    }

    namespace RunService {
        // Manual patch
        constexpr std::uintptr_t HeartbeatDelta = 0x1D0;
    }

    namespace ScriptContext {
        constexpr std::uintptr_t ScriptContextRef = 0x8;
        constexpr std::uintptr_t ExtraMemory = 0x100;
    }

    namespace StatsItem {
        constexpr std::uintptr_t AvgValue = 0x3E0;
        constexpr std::uintptr_t AvgValuePrev = 0x3E8;
        constexpr std::uintptr_t DisplayName = 0x480;
        constexpr std::uintptr_t Name = 0x3B0;
        constexpr std::uintptr_t ServicePtr = 0x71C9558;
        constexpr std::uintptr_t Value = 0x1C0;
    }

    namespace Team {
        constexpr std::uintptr_t TeamColor = 0x4;
    }

    namespace Terrain {
        constexpr std::uintptr_t GrassLength = 0x1E0;
        constexpr std::uintptr_t MaterialColors = 0x490;
        constexpr std::uintptr_t WaterColor = 0x1D0;
        constexpr std::uintptr_t WaterReflectance = 0x1E8;
        constexpr std::uintptr_t WaterTransparency = 0x1EC;
        constexpr std::uintptr_t WaterWaveSize = 0x1F0;
        constexpr std::uintptr_t WaterWaveSpeed = 0x1F4;
    }

    namespace UserInputService {
        constexpr std::uintptr_t MouseEnabled = 0x8B;
        constexpr std::uintptr_t KeyboardEnabled = 0xB8;
        constexpr std::uintptr_t TouchEnabled = 0xEF;
    }

    namespace VisualEngine {
        constexpr std::uintptr_t FakeDataModel = 0xA80;
        constexpr std::uintptr_t Pointer = 0x72C7AF8;
        constexpr std::uintptr_t RenderView = 0xBA8;
        constexpr std::uintptr_t ViewMatrix = 0x140;
    }

    namespace Workspace {
        constexpr std::uintptr_t CurrentCamera = 0x438;
        constexpr std::uintptr_t World = 0x3C0;
    }

    namespace World {
        constexpr std::uintptr_t Gravity = 0x208;
        constexpr std::uintptr_t Primitives = 0x400;
    }

} // namespace offsets

// runtime pointers aslr randomized 
namespace services {
    constexpr std::uintptr_t UserInputService = 0x7FE0A7DD2480;
    constexpr std::uintptr_t RunService = 0x7FE09C038A80;
    constexpr std::uintptr_t ReplicatedStorage = 0x7FE0ACA72CC0;
    constexpr std::uintptr_t ScriptContext = 0x7FE0AF597880;
    constexpr std::uintptr_t ReplicatedFirst = 0x7FE0A8E1B200;
    constexpr std::uintptr_t HttpService = 0x7FE09C046D00;
    constexpr std::uintptr_t LogService = 0x7FE0A8705800;
    constexpr std::uintptr_t InsertService = 0x7FE0A78CAC00;
    constexpr std::uintptr_t ContentProvider = 0x7FE0AC3B0080;
    constexpr std::uintptr_t CollectionService = 0x7FE0A7E4B180;
    constexpr std::uintptr_t PhysicsService = 0x7FE0B0667880;
    constexpr std::uintptr_t JointsService = 0x7FE0AC3921C0;
    constexpr std::uintptr_t TweenService = 0x7FE0B0640C80;
    constexpr std::uintptr_t Selection = 0x7FE09BC6F600;
    constexpr std::uintptr_t GuiService = 0x7FE0A61C3F80;
    constexpr std::uintptr_t Teams = 0x7FE0B54F53A0;
    constexpr std::uintptr_t BadgeService = 0x7FE0AC392380;
    constexpr std::uintptr_t SocialService = 0x7FE0B638F580;
    constexpr std::uintptr_t MarketplaceService = 0x7FE09C256280;
    constexpr std::uintptr_t TeleportService = 0x7FE0A61C1C80;
    constexpr std::uintptr_t LocalizationService = 0x7FE09C05E180;
    constexpr std::uintptr_t PolicyService = 0x7FE0AC391E40;
    constexpr std::uintptr_t FriendService = 0x7FE0A7E4B480;
    constexpr std::uintptr_t GroupService = 0x7FE0A7AE2540;
    constexpr std::uintptr_t PermissionsService = 0x7FE0ACA7E480;
    constexpr std::uintptr_t RobloxReplicatedStorage = 0x7FE0A7273500;
    constexpr std::uintptr_t RbxAnalyticsService = 0x7FE0A8E1D700;
    constexpr std::uintptr_t AnalyticsService = 0x7FE0AC392540;
    constexpr std::uintptr_t VRService = 0x7FE09C05EB80;
    constexpr std::uintptr_t TextChatService = 0x7FE09C0CA280;
    constexpr std::uintptr_t GamepadService = 0x7FE0B964DB80;
    constexpr std::uintptr_t KeyframeSequenceProvider = 0x7FE09BB6E780;
    constexpr std::uintptr_t AnimationClipProvider = 0x7FE0A7E49F80;
    constexpr std::uintptr_t MaterialService = 0x7FE09C24D280;
} // namespace services
