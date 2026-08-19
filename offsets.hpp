// updated: 8/18/2026
// roblox: 2.734.917
// sober: 1.7.1
#pragma once
#include <cstdint>

namespace offsets {

    namespace Atmosphere {
        constexpr std::uintptr_t Color = 0xB8;
        constexpr std::uintptr_t Decay = 0x8;
        constexpr std::uintptr_t Density = 0x20;
        constexpr std::uintptr_t Glare = 0x10;
        constexpr std::uintptr_t Haze = 0x24;
        constexpr std::uintptr_t Offset = 0x28;
    }

    namespace Attachment {
        constexpr std::uintptr_t Axis = 0xB4;
        constexpr std::uintptr_t Visible = 0x30;
    }

    namespace BasePart {
        constexpr std::uintptr_t Primitive = 0x178;
        constexpr std::uintptr_t Reflectance = 0x20;
        constexpr std::uintptr_t Transparency = 0x24;
        constexpr std::uintptr_t Shape = 0x30;
        constexpr std::uintptr_t Material = 0x34;
        constexpr std::uintptr_t CastShadow = 0xCC;
        constexpr std::uintptr_t Locked = 0xC8;
        constexpr std::uintptr_t Massless = 0xC0;
        constexpr std::uintptr_t Anchored = 0x1B0;
        constexpr std::uintptr_t CanCollide = 0x2C9;
        constexpr std::uintptr_t CanQuery = 0x19E;
        constexpr std::uintptr_t CanTouch = 0x19F;
    }

    namespace BloomEffect {
        constexpr std::uintptr_t Threshold = 0xCC;
    }

    namespace Camera {
        constexpr std::uintptr_t CFrame = 0xD0;
        constexpr std::uintptr_t Position = 0xF4;
        constexpr std::uintptr_t Rotation = 0xD0;
        constexpr std::uintptr_t CameraSubject = 0xC0;
        constexpr std::uintptr_t ViewportSize = 0x2C4;
        constexpr std::uintptr_t CameraType = 0;
    }

    namespace DataModel {
        constexpr std::uintptr_t CreatorId = 0x118;
        constexpr std::uintptr_t GameId = 0x168;
        constexpr std::uintptr_t JobId = 0x128;
        constexpr std::uintptr_t PlaceId = 0x90;
        constexpr std::uintptr_t ServerIp = 0x608;
        constexpr std::uintptr_t Workspace = 0x148;
        constexpr std::uintptr_t UniverseId = 0xD8;
        constexpr std::uintptr_t PrivateServerOwnerId = 0x310;
        constexpr std::uintptr_t SavaVersion = 0x174;
    }

    namespace FakeDataModel {
        constexpr std::uintptr_t RealDataModel = 0x1D8;
        constexpr std::uintptr_t Pointer = 0x7213FE8;
    }

    namespace Humanoid {
        constexpr std::uintptr_t WalkSpeed = 0x1C0;
        constexpr std::uintptr_t WalkSpeedCheck = 0x3AC;
        constexpr std::uintptr_t Health = 0x180;
        constexpr std::uintptr_t MaxHealth = 0x178;
        constexpr std::uintptr_t HipHeight = 0x184;
        constexpr std::uintptr_t JumpHeight = 0x190;
        constexpr std::uintptr_t JumpPower = 0x194;
        constexpr std::uintptr_t MaxSlopeAngle = 0x19C;
        constexpr std::uintptr_t RigType = 0x24;
        constexpr std::uintptr_t AutoRotate = 0x1C4;
        constexpr std::uintptr_t SeatPart = 0x270;
        constexpr std::uintptr_t Sit = 0x1CE
        constexpr std::uintptr_t PlatformStand = 0;
        constexpr std::uintptr_t DisplayDistanceType = 0x30;
        constexpr std::uintptr_t NameOcclusion = 0x4C;
        constexpr std::uintptr_t CameraOffset = 0x40;
        constexpr std::uintptr_t FloorMaterial = 0x279;
    }

    namespace Instance {
        constexpr std::uintptr_t ChildrenStride = 0x10;
        constexpr std::uintptr_t ClassDescriptor = 0x18;
        constexpr std::uintptr_t ClassName = 0x8;
        constexpr std::uintptr_t Name = 0x70;
        constexpr std::uintptr_t NameStringOffset = 0x8;
        constexpr std::uintptr_t Parent = 0x68;
        constexpr std::uintptr_t ChildrenStart = 0x78;
        constexpr std::uintptr_t ChildrenEnd = 0x8;
    }

    namespace Lighting {
        constexpr std::uintptr_t Brightness = 0xE0;
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
        constexpr std::uintptr_t AssemblyLinearVelocity  = 0x8C;
        constexpr std::uintptr_t AssemblyAngularVelocity = 0xB4;
        constexpr std::uintptr_t AssemblyRotVelocity     = 0xE4;
        constexpr std::uintptr_t CFrame = 0xC8;
        constexpr std::uintptr_t Material = 0xC0;
        constexpr std::uintptr_t Orientation = 0xC8;
        constexpr std::uintptr_t Position = 0xEC;
        constexpr std::uintptr_t PrimitiveFlags = 0x113;
        constexpr std::uintptr_t Rotation = 0xC8;
        constexpr std::uintptr_t Mass = 0x1C0;
        constexpr std::uintptr_t Size = 0x1B8;
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
        constexpr std::uintptr_t Print = 0x3EB801B;
    }

    namespace RenderView {
        constexpr std::uintptr_t LightingValid = 0x228;
        constexpr std::uintptr_t SkyboxValid = 0x28D;
    }

    namespace RunService {
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
        constexpr std::uintptr_t MouseEnabled = 0x71;
        constexpr std::uintptr_t KeyboardEnabled = 0x93;
        constexpr std::uintptr_t TouchEnabled = 0xB8;
    }

    namespace VisualEngine {
        constexpr std::uintptr_t FakeDataModel = 0xAC0;
        constexpr std::uintptr_t Pointer = 0x79C94F0;
        constexpr std::uintptr_t RenderView = 0xC00;
        constexpr std::uintptr_t ViewMatrix = 0x180;
    }

    namespace Workspace {
        constexpr std::uintptr_t CurrentCamera = 0x450;
        constexpr std::uintptr_t World = 0x3C0;
    }

    namespace World {
        constexpr std::uintptr_t Primitives = 0x400;
    }

} // namespace offsets

//Runtime service pointers ASLR randomized per run
namespace services {
    constexpr std::uintptr_t UserInputService = 0x7F74A0EC1880;
    constexpr std::uintptr_t RunService = 0x7F74A0C3A580;
    constexpr std::uintptr_t ReplicatedStorage = 0x7F749D652700;
    constexpr std::uintptr_t ScriptContext = 0x7F74AA273C80;
    constexpr std::uintptr_t ReplicatedFirst = 0x7F74A9094100;
    constexpr std::uintptr_t HttpService = 0x7F74A0C66980;
    constexpr std::uintptr_t LogService = 0x7F74A076A400;
    constexpr std::uintptr_t InsertService = 0x7F74A9DFC8E0;
    constexpr std::uintptr_t ContentProvider = 0x7F74B8CA0080;
    constexpr std::uintptr_t CollectionService = 0x7F74B56ABD80;
    constexpr std::uintptr_t PhysicsService = 0x7F74A867E180;
    constexpr std::uintptr_t JointsService = 0x7F74A0C4C640;
    constexpr std::uintptr_t TweenService = 0x7F74B16B5A80;
    constexpr std::uintptr_t Selection = 0x7F74B05C1A00;
    constexpr std::uintptr_t GuiService = 0x7F74AF957E80;
    constexpr std::uintptr_t Teams = 0x7F749D650940;
    constexpr std::uintptr_t BadgeService = 0x7F74A0C4C800;
    constexpr std::uintptr_t SocialService = 0x7F74B8AA7880;
    constexpr std::uintptr_t MarketplaceService = 0x7F74B1701C80;
    constexpr std::uintptr_t TeleportService = 0x7F74AF95AF80;
    constexpr std::uintptr_t LocalizationService = 0x7F74A0CBEB80;
    constexpr std::uintptr_t PolicyService = 0x7F74A0C4C2C0;
    constexpr std::uintptr_t FriendService = 0x7F74B56AC080;
    constexpr std::uintptr_t GroupService = 0x7F74C0665300;
    constexpr std::uintptr_t PermissionsService = 0x7F74B1D58900;
    constexpr std::uintptr_t RobloxReplicatedStorage = 0x7F74B1D07240;
    constexpr std::uintptr_t RbxAnalyticsService = 0x7F74A9092700;
    constexpr std::uintptr_t AnalyticsService = 0x7F74A0C4C9C0;
    constexpr std::uintptr_t VRService = 0x7F74A0CBC880;
    constexpr std::uintptr_t TextChatService = 0x7F74A0EC7880;
    constexpr std::uintptr_t GamepadService = 0x7F74AFFB3F80;
    constexpr std::uintptr_t KeyframeSequenceProvider = 0x7F74A0C45640;
    constexpr std::uintptr_t AnimationClipProvider = 0x7F74B56AB780;
    constexpr std::uintptr_t MaterialService = 0x7F74B1702A80;
} // namespace services
