// BSD 3-Clause License
//
// Copyright (c) 2019, "WebGPU native" developers
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#ifdef __EMSCRIPTEN__
#error "Do not include this header. Emscripten already provides headers needed for WebGPU."
#endif
#ifndef WEBGPU_H_
#define WEBGPU_H_

#if defined(WGPU_SHARED_LIBRARY)
#    if defined(_WIN32)
#        if defined(WGPU_IMPLEMENTATION)
#            define WGPU_EXPORT __declspec(dllexport)
#        else
#            define WGPU_EXPORT __declspec(dllimport)
#        endif
#    else  // defined(_WIN32)
#        if defined(WGPU_IMPLEMENTATION)
#            define WGPU_EXPORT __attribute__((visibility("default")))
#        else
#            define WGPU_EXPORT
#        endif
#    endif  // defined(_WIN32)
#else       // defined(WGPU_SHARED_LIBRARY)
#    define WGPU_EXPORT
#endif  // defined(WGPU_SHARED_LIBRARY)

#if !defined(WGPU_OBJECT_ATTRIBUTE)
#define WGPU_OBJECT_ATTRIBUTE
#endif
#if !defined(WGPU_ENUM_ATTRIBUTE)
#define WGPU_ENUM_ATTRIBUTE
#endif
#if !defined(WGPU_STRUCTURE_ATTRIBUTE)
#define WGPU_STRUCTURE_ATTRIBUTE
#endif
#if !defined(WGPU_FUNCTION_ATTRIBUTE)
#define WGPU_FUNCTION_ATTRIBUTE
#endif
#if !defined(WGPU_NULLABLE)
#define WGPU_NULLABLE
#endif

#include <stdint.h>
#include <stddef.h>

#if defined(__cplusplus)
#  if __cplusplus >= 201103L
#    define WGPU_MAKE_INIT_STRUCT(type, value) (type value)
#  else
#    define WGPU_MAKE_INIT_STRUCT(type, value) value
#  endif
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#  define WGPU_MAKE_INIT_STRUCT(type, value) ((type) value)
#else
#  define WGPU_MAKE_INIT_STRUCT(type, value) value
#endif

#define WGPU_ARRAY_LAYER_COUNT_UNDEFINED UINT32_MAX
#define WGPU_COPY_STRIDE_UNDEFINED UINT32_MAX
#define WGPU_DEPTH_SLICE_UNDEFINED UINT32_MAX
#define WGPU_LIMIT_U32_UNDEFINED UINT32_MAX
#define WGPU_LIMIT_U64_UNDEFINED UINT64_MAX
#define WGPU_MIP_LEVEL_COUNT_UNDEFINED UINT32_MAX
#define WGPU_QUERY_SET_INDEX_UNDEFINED UINT32_MAX
#define WGPU_WHOLE_MAP_SIZE SIZE_MAX
#define WGPU_WHOLE_SIZE UINT64_MAX

typedef uint32_t WGPUFlags;
typedef uint32_t WGPUBool;

typedef struct WGPUAdapterImpl* WGPUAdapter WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUBindGroupImpl* WGPUBindGroup WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUBindGroupLayoutImpl* WGPUBindGroupLayout WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUBufferImpl* WGPUBuffer WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUCommandBufferImpl* WGPUCommandBuffer WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUCommandEncoderImpl* WGPUCommandEncoder WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUComputePassEncoderImpl* WGPUComputePassEncoder WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUComputePipelineImpl* WGPUComputePipeline WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUDeviceImpl* WGPUDevice WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUExternalTextureImpl* WGPUExternalTexture WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUInstanceImpl* WGPUInstance WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUPipelineLayoutImpl* WGPUPipelineLayout WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUQuerySetImpl* WGPUQuerySet WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUQueueImpl* WGPUQueue WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPURenderBundleImpl* WGPURenderBundle WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPURenderBundleEncoderImpl* WGPURenderBundleEncoder WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPURenderPassEncoderImpl* WGPURenderPassEncoder WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPURenderPipelineImpl* WGPURenderPipeline WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUSamplerImpl* WGPUSampler WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUShaderModuleImpl* WGPUShaderModule WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUSharedBufferMemoryImpl* WGPUSharedBufferMemory WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUSharedFenceImpl* WGPUSharedFence WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUSharedTextureMemoryImpl* WGPUSharedTextureMemory WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUSurfaceImpl* WGPUSurface WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUSwapChainImpl* WGPUSwapChain WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUTextureImpl* WGPUTexture WGPU_OBJECT_ATTRIBUTE;
typedef struct WGPUTextureViewImpl* WGPUTextureView WGPU_OBJECT_ATTRIBUTE;

// Structure forward declarations
struct WGPUAdapterInfo;
struct WGPUAdapterProperties;
struct WGPUAdapterPropertiesD3D;
struct WGPUAdapterPropertiesVk;
struct WGPUBindGroupEntry;
struct WGPUBlendComponent;
struct WGPUBufferBindingLayout;
struct WGPUBufferDescriptor;
struct WGPUBufferHostMappedPointer;
struct WGPUBufferMapCallbackInfo;
struct WGPUColor;
struct WGPUColorTargetStateExpandResolveTextureDawn;
struct WGPUCommandBufferDescriptor;
struct WGPUCommandEncoderDescriptor;
struct WGPUCompilationInfoCallbackInfo;
struct WGPUCompilationMessage;
struct WGPUComputePassTimestampWrites;
struct WGPUConstantEntry;
struct WGPUCopyTextureForBrowserOptions;
struct WGPUCreateComputePipelineAsyncCallbackInfo;
struct WGPUCreateRenderPipelineAsyncCallbackInfo;
struct WGPUDawnWGSLBlocklist;
struct WGPUDawnAdapterPropertiesPowerPreference;
struct WGPUDawnBufferDescriptorErrorInfoFromWireClient;
struct WGPUDawnCacheDeviceDescriptor;
struct WGPUDawnComputePipelineFullSubgroups;
struct WGPUDawnEncoderInternalUsageDescriptor;
struct WGPUDawnExperimentalSubgroupLimits;
struct WGPUDawnRenderPassColorAttachmentRenderToSingleSampled;
struct WGPUDawnShaderModuleSPIRVOptionsDescriptor;
struct WGPUDawnTextureInternalUsageDescriptor;
struct WGPUDawnTogglesDescriptor;
struct WGPUDawnWireWGSLControl;
struct WGPUDepthStencilStateDepthWriteDefinedDawn;
struct WGPUDeviceLostCallbackInfo;
struct WGPUDrmFormatProperties;
struct WGPUExtent2D;
struct WGPUExtent3D;
struct WGPUExternalTextureBindingEntry;
struct WGPUExternalTextureBindingLayout;
struct WGPUFormatCapabilities;
struct WGPUFuture;
struct WGPUInstanceFeatures;
struct WGPULimits;
struct WGPUMemoryHeapInfo;
struct WGPUMultisampleState;
struct WGPUOrigin2D;
struct WGPUOrigin3D;
struct WGPUPipelineLayoutDescriptor;
struct WGPUPipelineLayoutStorageAttachment;
struct WGPUPopErrorScopeCallbackInfo;
struct WGPUPrimitiveDepthClipControl;
struct WGPUPrimitiveState;
struct WGPUQuerySetDescriptor;
struct WGPUQueueDescriptor;
struct WGPUQueueWorkDoneCallbackInfo;
struct WGPURenderBundleDescriptor;
struct WGPURenderBundleEncoderDescriptor;
struct WGPURenderPassDepthStencilAttachment;
struct WGPURenderPassDescriptorMaxDrawCount;
struct WGPURenderPassTimestampWrites;
struct WGPURequestAdapterCallbackInfo;
struct WGPURequestAdapterOptions;
struct WGPURequestDeviceCallbackInfo;
struct WGPUSamplerBindingLayout;
struct WGPUSamplerDescriptor;
struct WGPUShaderModuleSPIRVDescriptor;
struct WGPUShaderModuleWGSLDescriptor;
struct WGPUShaderModuleCompilationOptions;
struct WGPUShaderModuleDescriptor;
struct WGPUSharedBufferMemoryBeginAccessDescriptor;
struct WGPUSharedBufferMemoryDescriptor;
struct WGPUSharedBufferMemoryEndAccessState;
struct WGPUSharedBufferMemoryProperties;
struct WGPUSharedFenceDXGISharedHandleDescriptor;
struct WGPUSharedFenceDXGISharedHandleExportInfo;
struct WGPUSharedFenceMTLSharedEventDescriptor;
struct WGPUSharedFenceMTLSharedEventExportInfo;
struct WGPUSharedFenceDescriptor;
struct WGPUSharedFenceExportInfo;
struct WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor;
struct WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo;
struct WGPUSharedFenceVkSemaphoreSyncFDDescriptor;
struct WGPUSharedFenceVkSemaphoreSyncFDExportInfo;
struct WGPUSharedFenceVkSemaphoreZirconHandleDescriptor;
struct WGPUSharedFenceVkSemaphoreZirconHandleExportInfo;
struct WGPUSharedTextureMemoryD3DSwapchainBeginState;
struct WGPUSharedTextureMemoryDXGISharedHandleDescriptor;
struct WGPUSharedTextureMemoryEGLImageDescriptor;
struct WGPUSharedTextureMemoryIOSurfaceDescriptor;
struct WGPUSharedTextureMemoryAHardwareBufferDescriptor;
struct WGPUSharedTextureMemoryBeginAccessDescriptor;
struct WGPUSharedTextureMemoryDescriptor;
struct WGPUSharedTextureMemoryDmaBufPlane;
struct WGPUSharedTextureMemoryEndAccessState;
struct WGPUSharedTextureMemoryOpaqueFDDescriptor;
struct WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor;
struct WGPUSharedTextureMemoryVkImageLayoutBeginState;
struct WGPUSharedTextureMemoryVkImageLayoutEndState;
struct WGPUSharedTextureMemoryZirconHandleDescriptor;
struct WGPUStaticSamplerBindingLayout;
struct WGPUStencilFaceState;
struct WGPUStorageTextureBindingLayout;
struct WGPUSurfaceCapabilities;
struct WGPUSurfaceConfiguration;
struct WGPUSurfaceDescriptor;
struct WGPUSurfaceDescriptorFromAndroidNativeWindow;
struct WGPUSurfaceDescriptorFromCanvasHTMLSelector;
struct WGPUSurfaceDescriptorFromMetalLayer;
struct WGPUSurfaceDescriptorFromWaylandSurface;
struct WGPUSurfaceDescriptorFromWindowsHWND;
struct WGPUSurfaceDescriptorFromWindowsCoreWindow;
struct WGPUSurfaceDescriptorFromWindowsSwapChainPanel;
struct WGPUSurfaceDescriptorFromXlibWindow;
struct WGPUSurfaceTexture;
struct WGPUSwapChainDescriptor;
struct WGPUTextureBindingLayout;
struct WGPUTextureBindingViewDimensionDescriptor;
struct WGPUTextureDataLayout;
struct WGPUTextureViewDescriptor;
struct WGPUUncapturedErrorCallbackInfo;
struct WGPUVertexAttribute;
struct WGPUYCbCrVkDescriptor;
struct WGPUAHardwareBufferProperties;
struct WGPUAdapterPropertiesMemoryHeaps;
struct WGPUBindGroupDescriptor;
struct WGPUBindGroupLayoutEntry;
struct WGPUBlendState;
struct WGPUCompilationInfo;
struct WGPUComputePassDescriptor;
struct WGPUDepthStencilState;
struct WGPUDrmFormatCapabilities;
struct WGPUExternalTextureDescriptor;
struct WGPUFutureWaitInfo;
struct WGPUImageCopyBuffer;
struct WGPUImageCopyExternalTexture;
struct WGPUImageCopyTexture;
struct WGPUInstanceDescriptor;
struct WGPUPipelineLayoutPixelLocalStorage;
struct WGPUProgrammableStageDescriptor;
struct WGPURenderPassColorAttachment;
struct WGPURenderPassStorageAttachment;
struct WGPURequiredLimits;
struct WGPUSharedTextureMemoryAHardwareBufferProperties;
struct WGPUSharedTextureMemoryDmaBufDescriptor;
struct WGPUSharedTextureMemoryProperties;
struct WGPUSupportedLimits;
struct WGPUTextureDescriptor;
struct WGPUVertexBufferLayout;
struct WGPUBindGroupLayoutDescriptor;
struct WGPUColorTargetState;
struct WGPUComputePipelineDescriptor;
struct WGPUDeviceDescriptor;
struct WGPURenderPassDescriptor;
struct WGPURenderPassPixelLocalStorage;
struct WGPUVertexState;
struct WGPUFragmentState;
struct WGPURenderPipelineDescriptor;

typedef enum WGPUWGSLFeatureName {
    WGPUWGSLFeatureName_ReadonlyAndReadwriteStorageTextures = 0x00000001,
    WGPUWGSLFeatureName_Packed4x8IntegerDotProduct = 0x00000002,
    WGPUWGSLFeatureName_UnrestrictedPointerParameters = 0x00000003,
    WGPUWGSLFeatureName_PointerCompositeAccess = 0x00000004,
    WGPUWGSLFeatureName_ChromiumTestingUnimplemented = 0x000003E8,
    WGPUWGSLFeatureName_ChromiumTestingUnsafeExperimental = 0x000003E9,
    WGPUWGSLFeatureName_ChromiumTestingExperimental = 0x000003EA,
    WGPUWGSLFeatureName_ChromiumTestingShippedWithKillswitch = 0x000003EB,
    WGPUWGSLFeatureName_ChromiumTestingShipped = 0x000003EC,
    WGPUWGSLFeatureName_Force32 = 0x7FFFFFFF
} WGPUWGSLFeatureName WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUAdapterType {
    WGPUAdapterType_DiscreteGPU = 0x00000001,
    WGPUAdapterType_IntegratedGPU = 0x00000002,
    WGPUAdapterType_CPU = 0x00000003,
    WGPUAdapterType_Unknown = 0x00000004,
    WGPUAdapterType_Force32 = 0x7FFFFFFF
} WGPUAdapterType WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUAddressMode {
    WGPUAddressMode_Undefined = 0x00000000,
    WGPUAddressMode_ClampToEdge = 0x00000001,
    WGPUAddressMode_Repeat = 0x00000002,
    WGPUAddressMode_MirrorRepeat = 0x00000003,
    WGPUAddressMode_Force32 = 0x7FFFFFFF
} WGPUAddressMode WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUAlphaMode {
    WGPUAlphaMode_Opaque = 0x00000001,
    WGPUAlphaMode_Premultiplied = 0x00000002,
    WGPUAlphaMode_Unpremultiplied = 0x00000003,
    WGPUAlphaMode_Force32 = 0x7FFFFFFF
} WGPUAlphaMode WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUBackendType {
    WGPUBackendType_Undefined = 0x00000000,
    WGPUBackendType_Null = 0x00000001,
    WGPUBackendType_WebGPU = 0x00000002,
    WGPUBackendType_D3D11 = 0x00000003,
    WGPUBackendType_D3D12 = 0x00000004,
    WGPUBackendType_Metal = 0x00000005,
    WGPUBackendType_Vulkan = 0x00000006,
    WGPUBackendType_OpenGL = 0x00000007,
    WGPUBackendType_OpenGLES = 0x00000008,
    WGPUBackendType_Force32 = 0x7FFFFFFF
} WGPUBackendType WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUBlendFactor {
    WGPUBlendFactor_Undefined = 0x00000000,
    WGPUBlendFactor_Zero = 0x00000001,
    WGPUBlendFactor_One = 0x00000002,
    WGPUBlendFactor_Src = 0x00000003,
    WGPUBlendFactor_OneMinusSrc = 0x00000004,
    WGPUBlendFactor_SrcAlpha = 0x00000005,
    WGPUBlendFactor_OneMinusSrcAlpha = 0x00000006,
    WGPUBlendFactor_Dst = 0x00000007,
    WGPUBlendFactor_OneMinusDst = 0x00000008,
    WGPUBlendFactor_DstAlpha = 0x00000009,
    WGPUBlendFactor_OneMinusDstAlpha = 0x0000000A,
    WGPUBlendFactor_SrcAlphaSaturated = 0x0000000B,
    WGPUBlendFactor_Constant = 0x0000000C,
    WGPUBlendFactor_OneMinusConstant = 0x0000000D,
    WGPUBlendFactor_Src1 = 0x0000000E,
    WGPUBlendFactor_OneMinusSrc1 = 0x0000000F,
    WGPUBlendFactor_Src1Alpha = 0x00000010,
    WGPUBlendFactor_OneMinusSrc1Alpha = 0x00000011,
    WGPUBlendFactor_Force32 = 0x7FFFFFFF
} WGPUBlendFactor WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUBlendOperation {
    WGPUBlendOperation_Undefined = 0x00000000,
    WGPUBlendOperation_Add = 0x00000001,
    WGPUBlendOperation_Subtract = 0x00000002,
    WGPUBlendOperation_ReverseSubtract = 0x00000003,
    WGPUBlendOperation_Min = 0x00000004,
    WGPUBlendOperation_Max = 0x00000005,
    WGPUBlendOperation_Force32 = 0x7FFFFFFF
} WGPUBlendOperation WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUBufferBindingType {
    WGPUBufferBindingType_Undefined = 0x00000000,
    WGPUBufferBindingType_Uniform = 0x00000001,
    WGPUBufferBindingType_Storage = 0x00000002,
    WGPUBufferBindingType_ReadOnlyStorage = 0x00000003,
    WGPUBufferBindingType_Force32 = 0x7FFFFFFF
} WGPUBufferBindingType WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUBufferMapAsyncStatus {
    WGPUBufferMapAsyncStatus_Success = 0x00000001,
    WGPUBufferMapAsyncStatus_InstanceDropped = 0x00000002,
    WGPUBufferMapAsyncStatus_ValidationError = 0x00000003,
    WGPUBufferMapAsyncStatus_Unknown = 0x00000004,
    WGPUBufferMapAsyncStatus_DeviceLost = 0x00000005,
    WGPUBufferMapAsyncStatus_DestroyedBeforeCallback = 0x00000006,
    WGPUBufferMapAsyncStatus_UnmappedBeforeCallback = 0x00000007,
    WGPUBufferMapAsyncStatus_MappingAlreadyPending = 0x00000008,
    WGPUBufferMapAsyncStatus_OffsetOutOfRange = 0x00000009,
    WGPUBufferMapAsyncStatus_SizeOutOfRange = 0x0000000A,
    WGPUBufferMapAsyncStatus_Force32 = 0x7FFFFFFF
} WGPUBufferMapAsyncStatus WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUBufferMapState {
    WGPUBufferMapState_Unmapped = 0x00000001,
    WGPUBufferMapState_Pending = 0x00000002,
    WGPUBufferMapState_Mapped = 0x00000003,
    WGPUBufferMapState_Force32 = 0x7FFFFFFF
} WGPUBufferMapState WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUCallbackMode {
    WGPUCallbackMode_WaitAnyOnly = 0x00000001,
    WGPUCallbackMode_AllowProcessEvents = 0x00000002,
    WGPUCallbackMode_AllowSpontaneous = 0x00000003,
    WGPUCallbackMode_Force32 = 0x7FFFFFFF
} WGPUCallbackMode WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUCompareFunction {
    WGPUCompareFunction_Undefined = 0x00000000,
    WGPUCompareFunction_Never = 0x00000001,
    WGPUCompareFunction_Less = 0x00000002,
    WGPUCompareFunction_Equal = 0x00000003,
    WGPUCompareFunction_LessEqual = 0x00000004,
    WGPUCompareFunction_Greater = 0x00000005,
    WGPUCompareFunction_NotEqual = 0x00000006,
    WGPUCompareFunction_GreaterEqual = 0x00000007,
    WGPUCompareFunction_Always = 0x00000008,
    WGPUCompareFunction_Force32 = 0x7FFFFFFF
} WGPUCompareFunction WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUCompilationInfoRequestStatus {
    WGPUCompilationInfoRequestStatus_Success = 0x00000001,
    WGPUCompilationInfoRequestStatus_InstanceDropped = 0x00000002,
    WGPUCompilationInfoRequestStatus_Error = 0x00000003,
    WGPUCompilationInfoRequestStatus_DeviceLost = 0x00000004,
    WGPUCompilationInfoRequestStatus_Unknown = 0x00000005,
    WGPUCompilationInfoRequestStatus_Force32 = 0x7FFFFFFF
} WGPUCompilationInfoRequestStatus WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUCompilationMessageType {
    WGPUCompilationMessageType_Error = 0x00000001,
    WGPUCompilationMessageType_Warning = 0x00000002,
    WGPUCompilationMessageType_Info = 0x00000003,
    WGPUCompilationMessageType_Force32 = 0x7FFFFFFF
} WGPUCompilationMessageType WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUCompositeAlphaMode {
    WGPUCompositeAlphaMode_Auto = 0x00000001,
    WGPUCompositeAlphaMode_Opaque = 0x00000002,
    WGPUCompositeAlphaMode_Premultiplied = 0x00000003,
    WGPUCompositeAlphaMode_Unpremultiplied = 0x00000004,
    WGPUCompositeAlphaMode_Inherit = 0x00000005,
    WGPUCompositeAlphaMode_Force32 = 0x7FFFFFFF
} WGPUCompositeAlphaMode WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUCreatePipelineAsyncStatus {
    WGPUCreatePipelineAsyncStatus_Success = 0x00000001,
    WGPUCreatePipelineAsyncStatus_InstanceDropped = 0x00000002,
    WGPUCreatePipelineAsyncStatus_ValidationError = 0x00000003,
    WGPUCreatePipelineAsyncStatus_InternalError = 0x00000004,
    WGPUCreatePipelineAsyncStatus_DeviceLost = 0x00000005,
    WGPUCreatePipelineAsyncStatus_DeviceDestroyed = 0x00000006,
    WGPUCreatePipelineAsyncStatus_Unknown = 0x00000007,
    WGPUCreatePipelineAsyncStatus_Force32 = 0x7FFFFFFF
} WGPUCreatePipelineAsyncStatus WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUCullMode {
    WGPUCullMode_Undefined = 0x00000000,
    WGPUCullMode_None = 0x00000001,
    WGPUCullMode_Front = 0x00000002,
    WGPUCullMode_Back = 0x00000003,
    WGPUCullMode_Force32 = 0x7FFFFFFF
} WGPUCullMode WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUDeviceLostReason {
    WGPUDeviceLostReason_Unknown = 0x00000001,
    WGPUDeviceLostReason_Destroyed = 0x00000002,
    WGPUDeviceLostReason_InstanceDropped = 0x00000003,
    WGPUDeviceLostReason_FailedCreation = 0x00000004,
    WGPUDeviceLostReason_Force32 = 0x7FFFFFFF
} WGPUDeviceLostReason WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUErrorFilter {
    WGPUErrorFilter_Validation = 0x00000001,
    WGPUErrorFilter_OutOfMemory = 0x00000002,
    WGPUErrorFilter_Internal = 0x00000003,
    WGPUErrorFilter_Force32 = 0x7FFFFFFF
} WGPUErrorFilter WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUErrorType {
    WGPUErrorType_NoError = 0x00000001,
    WGPUErrorType_Validation = 0x00000002,
    WGPUErrorType_OutOfMemory = 0x00000003,
    WGPUErrorType_Internal = 0x00000004,
    WGPUErrorType_Unknown = 0x00000005,
    WGPUErrorType_DeviceLost = 0x00000006,
    WGPUErrorType_Force32 = 0x7FFFFFFF
} WGPUErrorType WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUExternalTextureRotation {
    WGPUExternalTextureRotation_Rotate0Degrees = 0x00000001,
    WGPUExternalTextureRotation_Rotate90Degrees = 0x00000002,
    WGPUExternalTextureRotation_Rotate180Degrees = 0x00000003,
    WGPUExternalTextureRotation_Rotate270Degrees = 0x00000004,
    WGPUExternalTextureRotation_Force32 = 0x7FFFFFFF
} WGPUExternalTextureRotation WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUFeatureName {
    WGPUFeatureName_DepthClipControl = 0x00000001,
    WGPUFeatureName_Depth32FloatStencil8 = 0x00000002,
    WGPUFeatureName_TimestampQuery = 0x00000003,
    WGPUFeatureName_TextureCompressionBC = 0x00000004,
    WGPUFeatureName_TextureCompressionETC2 = 0x00000005,
    WGPUFeatureName_TextureCompressionASTC = 0x00000006,
    WGPUFeatureName_IndirectFirstInstance = 0x00000007,
    WGPUFeatureName_ShaderF16 = 0x00000008,
    WGPUFeatureName_RG11B10UfloatRenderable = 0x00000009,
    WGPUFeatureName_BGRA8UnormStorage = 0x0000000A,
    WGPUFeatureName_Float32Filterable = 0x0000000B,
    WGPUFeatureName_DawnInternalUsages = 0x000003EA,
    WGPUFeatureName_DawnMultiPlanarFormats = 0x000003EB,
    WGPUFeatureName_DawnNative = 0x000003EC,
    WGPUFeatureName_ChromiumExperimentalTimestampQueryInsidePasses = 0x000003EE,
    WGPUFeatureName_ImplicitDeviceSynchronization = 0x000003EF,
    WGPUFeatureName_SurfaceCapabilities = 0x000003F0,
    WGPUFeatureName_TransientAttachments = 0x000003F1,
    WGPUFeatureName_MSAARenderToSingleSampled = 0x000003F2,
    WGPUFeatureName_DualSourceBlending = 0x000003F3,
    WGPUFeatureName_D3D11MultithreadProtected = 0x000003F4,
    WGPUFeatureName_ANGLETextureSharing = 0x000003F5,
    WGPUFeatureName_ChromiumExperimentalSubgroups = 0x000003F6,
    WGPUFeatureName_ChromiumExperimentalSubgroupUniformControlFlow = 0x000003F7,
    WGPUFeatureName_PixelLocalStorageCoherent = 0x000003F9,
    WGPUFeatureName_PixelLocalStorageNonCoherent = 0x000003FA,
    WGPUFeatureName_Unorm16TextureFormats = 0x000003FB,
    WGPUFeatureName_Snorm16TextureFormats = 0x000003FC,
    WGPUFeatureName_MultiPlanarFormatExtendedUsages = 0x000003FD,
    WGPUFeatureName_MultiPlanarFormatP010 = 0x000003FE,
    WGPUFeatureName_HostMappedPointer = 0x000003FF,
    WGPUFeatureName_MultiPlanarRenderTargets = 0x00000400,
    WGPUFeatureName_MultiPlanarFormatNv12a = 0x00000401,
    WGPUFeatureName_FramebufferFetch = 0x00000402,
    WGPUFeatureName_BufferMapExtendedUsages = 0x00000403,
    WGPUFeatureName_AdapterPropertiesMemoryHeaps = 0x00000404,
    WGPUFeatureName_AdapterPropertiesD3D = 0x00000405,
    WGPUFeatureName_AdapterPropertiesVk = 0x00000406,
    WGPUFeatureName_R8UnormStorage = 0x00000407,
    WGPUFeatureName_FormatCapabilities = 0x00000408,
    WGPUFeatureName_DrmFormatCapabilities = 0x00000409,
    WGPUFeatureName_Norm16TextureFormats = 0x0000040A,
    WGPUFeatureName_MultiPlanarFormatNv16 = 0x0000040B,
    WGPUFeatureName_MultiPlanarFormatNv24 = 0x0000040C,
    WGPUFeatureName_MultiPlanarFormatP210 = 0x0000040D,
    WGPUFeatureName_MultiPlanarFormatP410 = 0x0000040E,
    WGPUFeatureName_SharedTextureMemoryVkDedicatedAllocation = 0x0000044C,
    WGPUFeatureName_SharedTextureMemoryAHardwareBuffer = 0x0000044D,
    WGPUFeatureName_SharedTextureMemoryDmaBuf = 0x0000044E,
    WGPUFeatureName_SharedTextureMemoryOpaqueFD = 0x0000044F,
    WGPUFeatureName_SharedTextureMemoryZirconHandle = 0x00000450,
    WGPUFeatureName_SharedTextureMemoryDXGISharedHandle = 0x00000451,
    WGPUFeatureName_SharedTextureMemoryD3D11Texture2D = 0x00000452,
    WGPUFeatureName_SharedTextureMemoryIOSurface = 0x00000453,
    WGPUFeatureName_SharedTextureMemoryEGLImage = 0x00000454,
    WGPUFeatureName_SharedFenceVkSemaphoreOpaqueFD = 0x000004B0,
    WGPUFeatureName_SharedFenceVkSemaphoreSyncFD = 0x000004B1,
    WGPUFeatureName_SharedFenceVkSemaphoreZirconHandle = 0x000004B2,
    WGPUFeatureName_SharedFenceDXGISharedHandle = 0x000004B3,
    WGPUFeatureName_SharedFenceMTLSharedEvent = 0x000004B4,
    WGPUFeatureName_SharedBufferMemoryD3D12Resource = 0x000004B5,
    WGPUFeatureName_StaticSamplers = 0x000004B6,
    WGPUFeatureName_YCbCrVulkanSamplers = 0x000004B7,
    WGPUFeatureName_ShaderModuleCompilationOptions = 0x000004B8,
    WGPUFeatureName_DawnLoadResolveTexture = 0x000004B9,
    WGPUFeatureName_Force32 = 0x7FFFFFFF
} WGPUFeatureName WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUFilterMode {
    WGPUFilterMode_Undefined = 0x00000000,
    WGPUFilterMode_Nearest = 0x00000001,
    WGPUFilterMode_Linear = 0x00000002,
    WGPUFilterMode_Force32 = 0x7FFFFFFF
} WGPUFilterMode WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUFrontFace {
    WGPUFrontFace_Undefined = 0x00000000,
    WGPUFrontFace_CCW = 0x00000001,
    WGPUFrontFace_CW = 0x00000002,
    WGPUFrontFace_Force32 = 0x7FFFFFFF
} WGPUFrontFace WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUIndexFormat {
    WGPUIndexFormat_Undefined = 0x00000000,
    WGPUIndexFormat_Uint16 = 0x00000001,
    WGPUIndexFormat_Uint32 = 0x00000002,
    WGPUIndexFormat_Force32 = 0x7FFFFFFF
} WGPUIndexFormat WGPU_ENUM_ATTRIBUTE;

typedef enum WGPULoadOp {
    WGPULoadOp_Undefined = 0x00000000,
    WGPULoadOp_Clear = 0x00000001,
    WGPULoadOp_Load = 0x00000002,
    WGPULoadOp_ExpandResolveTexture = 0x00000003,
    WGPULoadOp_Force32 = 0x7FFFFFFF
} WGPULoadOp WGPU_ENUM_ATTRIBUTE;

typedef enum WGPULoggingType {
    WGPULoggingType_Verbose = 0x00000001,
    WGPULoggingType_Info = 0x00000002,
    WGPULoggingType_Warning = 0x00000003,
    WGPULoggingType_Error = 0x00000004,
    WGPULoggingType_Force32 = 0x7FFFFFFF
} WGPULoggingType WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUMapAsyncStatus {
    WGPUMapAsyncStatus_Success = 0x00000001,
    WGPUMapAsyncStatus_InstanceDropped = 0x00000002,
    WGPUMapAsyncStatus_Error = 0x00000003,
    WGPUMapAsyncStatus_Aborted = 0x00000004,
    WGPUMapAsyncStatus_Unknown = 0x00000005,
    WGPUMapAsyncStatus_Force32 = 0x7FFFFFFF
} WGPUMapAsyncStatus WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUMipmapFilterMode {
    WGPUMipmapFilterMode_Undefined = 0x00000000,
    WGPUMipmapFilterMode_Nearest = 0x00000001,
    WGPUMipmapFilterMode_Linear = 0x00000002,
    WGPUMipmapFilterMode_Force32 = 0x7FFFFFFF
} WGPUMipmapFilterMode WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUPopErrorScopeStatus {
    WGPUPopErrorScopeStatus_Success = 0x00000001,
    WGPUPopErrorScopeStatus_InstanceDropped = 0x00000002,
    WGPUPopErrorScopeStatus_Force32 = 0x7FFFFFFF
} WGPUPopErrorScopeStatus WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUPowerPreference {
    WGPUPowerPreference_Undefined = 0x00000000,
    WGPUPowerPreference_LowPower = 0x00000001,
    WGPUPowerPreference_HighPerformance = 0x00000002,
    WGPUPowerPreference_Force32 = 0x7FFFFFFF
} WGPUPowerPreference WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUPresentMode {
    WGPUPresentMode_Fifo = 0x00000001,
    WGPUPresentMode_FifoRelaxed = 0x00000002,
    WGPUPresentMode_Immediate = 0x00000003,
    WGPUPresentMode_Mailbox = 0x00000004,
    WGPUPresentMode_Force32 = 0x7FFFFFFF
} WGPUPresentMode WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUPrimitiveTopology {
    WGPUPrimitiveTopology_Undefined = 0x00000000,
    WGPUPrimitiveTopology_PointList = 0x00000001,
    WGPUPrimitiveTopology_LineList = 0x00000002,
    WGPUPrimitiveTopology_LineStrip = 0x00000003,
    WGPUPrimitiveTopology_TriangleList = 0x00000004,
    WGPUPrimitiveTopology_TriangleStrip = 0x00000005,
    WGPUPrimitiveTopology_Force32 = 0x7FFFFFFF
} WGPUPrimitiveTopology WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUQueryType {
    WGPUQueryType_Occlusion = 0x00000001,
    WGPUQueryType_Timestamp = 0x00000002,
    WGPUQueryType_Force32 = 0x7FFFFFFF
} WGPUQueryType WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUQueueWorkDoneStatus {
    WGPUQueueWorkDoneStatus_Success = 0x00000001,
    WGPUQueueWorkDoneStatus_InstanceDropped = 0x00000002,
    WGPUQueueWorkDoneStatus_Error = 0x00000003,
    WGPUQueueWorkDoneStatus_Unknown = 0x00000004,
    WGPUQueueWorkDoneStatus_DeviceLost = 0x00000005,
    WGPUQueueWorkDoneStatus_Force32 = 0x7FFFFFFF
} WGPUQueueWorkDoneStatus WGPU_ENUM_ATTRIBUTE;

typedef enum WGPURequestAdapterStatus {
    WGPURequestAdapterStatus_Success = 0x00000001,
    WGPURequestAdapterStatus_InstanceDropped = 0x00000002,
    WGPURequestAdapterStatus_Unavailable = 0x00000003,
    WGPURequestAdapterStatus_Error = 0x00000004,
    WGPURequestAdapterStatus_Unknown = 0x00000005,
    WGPURequestAdapterStatus_Force32 = 0x7FFFFFFF
} WGPURequestAdapterStatus WGPU_ENUM_ATTRIBUTE;

typedef enum WGPURequestDeviceStatus {
    WGPURequestDeviceStatus_Success = 0x00000001,
    WGPURequestDeviceStatus_InstanceDropped = 0x00000002,
    WGPURequestDeviceStatus_Error = 0x00000003,
    WGPURequestDeviceStatus_Unknown = 0x00000004,
    WGPURequestDeviceStatus_Force32 = 0x7FFFFFFF
} WGPURequestDeviceStatus WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUSType {
    WGPUSType_SurfaceDescriptorFromMetalLayer = 0x00000001,
    WGPUSType_SurfaceDescriptorFromWindowsHWND = 0x00000002,
    WGPUSType_SurfaceDescriptorFromXlibWindow = 0x00000003,
    WGPUSType_SurfaceDescriptorFromCanvasHTMLSelector = 0x00000004,
    WGPUSType_ShaderModuleSPIRVDescriptor = 0x00000005,
    WGPUSType_ShaderModuleWGSLDescriptor = 0x00000006,
    WGPUSType_PrimitiveDepthClipControl = 0x00000007,
    WGPUSType_SurfaceDescriptorFromWaylandSurface = 0x00000008,
    WGPUSType_SurfaceDescriptorFromAndroidNativeWindow = 0x00000009,
    WGPUSType_SurfaceDescriptorFromWindowsCoreWindow = 0x0000000B,
    WGPUSType_ExternalTextureBindingEntry = 0x0000000C,
    WGPUSType_ExternalTextureBindingLayout = 0x0000000D,
    WGPUSType_SurfaceDescriptorFromWindowsSwapChainPanel = 0x0000000E,
    WGPUSType_RenderPassDescriptorMaxDrawCount = 0x0000000F,
    WGPUSType_DepthStencilStateDepthWriteDefinedDawn = 0x00000010,
    WGPUSType_TextureBindingViewDimensionDescriptor = 0x00000011,
    WGPUSType_DawnTextureInternalUsageDescriptor = 0x000003E8,
    WGPUSType_DawnEncoderInternalUsageDescriptor = 0x000003EB,
    WGPUSType_DawnInstanceDescriptor = 0x000003EC,
    WGPUSType_DawnCacheDeviceDescriptor = 0x000003ED,
    WGPUSType_DawnAdapterPropertiesPowerPreference = 0x000003EE,
    WGPUSType_DawnBufferDescriptorErrorInfoFromWireClient = 0x000003EF,
    WGPUSType_DawnTogglesDescriptor = 0x000003F0,
    WGPUSType_DawnShaderModuleSPIRVOptionsDescriptor = 0x000003F1,
    WGPUSType_RequestAdapterOptionsLUID = 0x000003F2,
    WGPUSType_RequestAdapterOptionsGetGLProc = 0x000003F3,
    WGPUSType_RequestAdapterOptionsD3D11Device = 0x000003F4,
    WGPUSType_DawnRenderPassColorAttachmentRenderToSingleSampled = 0x000003F6,
    WGPUSType_RenderPassPixelLocalStorage = 0x000003F7,
    WGPUSType_PipelineLayoutPixelLocalStorage = 0x000003F8,
    WGPUSType_BufferHostMappedPointer = 0x000003F9,
    WGPUSType_DawnExperimentalSubgroupLimits = 0x000003FA,
    WGPUSType_AdapterPropertiesMemoryHeaps = 0x000003FB,
    WGPUSType_AdapterPropertiesD3D = 0x000003FC,
    WGPUSType_AdapterPropertiesVk = 0x000003FD,
    WGPUSType_DawnComputePipelineFullSubgroups = 0x000003FE,
    WGPUSType_DawnWireWGSLControl = 0x000003FF,
    WGPUSType_DawnWGSLBlocklist = 0x00000400,
    WGPUSType_DrmFormatCapabilities = 0x00000401,
    WGPUSType_ShaderModuleCompilationOptions = 0x00000402,
    WGPUSType_ColorTargetStateExpandResolveTextureDawn = 0x00000403,
    WGPUSType_SharedTextureMemoryVkDedicatedAllocationDescriptor = 0x0000044D,
    WGPUSType_SharedTextureMemoryAHardwareBufferDescriptor = 0x0000044E,
    WGPUSType_SharedTextureMemoryDmaBufDescriptor = 0x0000044F,
    WGPUSType_SharedTextureMemoryOpaqueFDDescriptor = 0x00000450,
    WGPUSType_SharedTextureMemoryZirconHandleDescriptor = 0x00000451,
    WGPUSType_SharedTextureMemoryDXGISharedHandleDescriptor = 0x00000452,
    WGPUSType_SharedTextureMemoryD3D11Texture2DDescriptor = 0x00000453,
    WGPUSType_SharedTextureMemoryIOSurfaceDescriptor = 0x00000454,
    WGPUSType_SharedTextureMemoryEGLImageDescriptor = 0x00000455,
    WGPUSType_SharedTextureMemoryInitializedBeginState = 0x000004B0,
    WGPUSType_SharedTextureMemoryInitializedEndState = 0x000004B1,
    WGPUSType_SharedTextureMemoryVkImageLayoutBeginState = 0x000004B2,
    WGPUSType_SharedTextureMemoryVkImageLayoutEndState = 0x000004B3,
    WGPUSType_SharedTextureMemoryD3DSwapchainBeginState = 0x000004B4,
    WGPUSType_SharedFenceVkSemaphoreOpaqueFDDescriptor = 0x000004B5,
    WGPUSType_SharedFenceVkSemaphoreOpaqueFDExportInfo = 0x000004B6,
    WGPUSType_SharedFenceVkSemaphoreSyncFDDescriptor = 0x000004B7,
    WGPUSType_SharedFenceVkSemaphoreSyncFDExportInfo = 0x000004B8,
    WGPUSType_SharedFenceVkSemaphoreZirconHandleDescriptor = 0x000004B9,
    WGPUSType_SharedFenceVkSemaphoreZirconHandleExportInfo = 0x000004BA,
    WGPUSType_SharedFenceDXGISharedHandleDescriptor = 0x000004BB,
    WGPUSType_SharedFenceDXGISharedHandleExportInfo = 0x000004BC,
    WGPUSType_SharedFenceMTLSharedEventDescriptor = 0x000004BD,
    WGPUSType_SharedFenceMTLSharedEventExportInfo = 0x000004BE,
    WGPUSType_SharedBufferMemoryD3D12ResourceDescriptor = 0x000004BF,
    WGPUSType_StaticSamplerBindingLayout = 0x000004C0,
    WGPUSType_YCbCrVkDescriptor = 0x000004C1,
    WGPUSType_SharedTextureMemoryAHardwareBufferProperties = 0x000004C2,
    WGPUSType_AHardwareBufferProperties = 0x000004C3,
    WGPUSType_Force32 = 0x7FFFFFFF
} WGPUSType WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUSamplerBindingType {
    WGPUSamplerBindingType_Undefined = 0x00000000,
    WGPUSamplerBindingType_Filtering = 0x00000001,
    WGPUSamplerBindingType_NonFiltering = 0x00000002,
    WGPUSamplerBindingType_Comparison = 0x00000003,
    WGPUSamplerBindingType_Force32 = 0x7FFFFFFF
} WGPUSamplerBindingType WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUSharedFenceType {
    WGPUSharedFenceType_VkSemaphoreOpaqueFD = 0x00000001,
    WGPUSharedFenceType_VkSemaphoreSyncFD = 0x00000002,
    WGPUSharedFenceType_VkSemaphoreZirconHandle = 0x00000003,
    WGPUSharedFenceType_DXGISharedHandle = 0x00000004,
    WGPUSharedFenceType_MTLSharedEvent = 0x00000005,
    WGPUSharedFenceType_Force32 = 0x7FFFFFFF
} WGPUSharedFenceType WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUStatus {
    WGPUStatus_Success = 0x00000001,
    WGPUStatus_Error = 0x00000002,
    WGPUStatus_Force32 = 0x7FFFFFFF
} WGPUStatus WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUStencilOperation {
    WGPUStencilOperation_Undefined = 0x00000000,
    WGPUStencilOperation_Keep = 0x00000001,
    WGPUStencilOperation_Zero = 0x00000002,
    WGPUStencilOperation_Replace = 0x00000003,
    WGPUStencilOperation_Invert = 0x00000004,
    WGPUStencilOperation_IncrementClamp = 0x00000005,
    WGPUStencilOperation_DecrementClamp = 0x00000006,
    WGPUStencilOperation_IncrementWrap = 0x00000007,
    WGPUStencilOperation_DecrementWrap = 0x00000008,
    WGPUStencilOperation_Force32 = 0x7FFFFFFF
} WGPUStencilOperation WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUStorageTextureAccess {
    WGPUStorageTextureAccess_Undefined = 0x00000000,
    WGPUStorageTextureAccess_WriteOnly = 0x00000001,
    WGPUStorageTextureAccess_ReadOnly = 0x00000002,
    WGPUStorageTextureAccess_ReadWrite = 0x00000003,
    WGPUStorageTextureAccess_Force32 = 0x7FFFFFFF
} WGPUStorageTextureAccess WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUStoreOp {
    WGPUStoreOp_Undefined = 0x00000000,
    WGPUStoreOp_Store = 0x00000001,
    WGPUStoreOp_Discard = 0x00000002,
    WGPUStoreOp_Force32 = 0x7FFFFFFF
} WGPUStoreOp WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUSurfaceGetCurrentTextureStatus {
    WGPUSurfaceGetCurrentTextureStatus_Success = 0x00000001,
    WGPUSurfaceGetCurrentTextureStatus_Timeout = 0x00000002,
    WGPUSurfaceGetCurrentTextureStatus_Outdated = 0x00000003,
    WGPUSurfaceGetCurrentTextureStatus_Lost = 0x00000004,
    WGPUSurfaceGetCurrentTextureStatus_OutOfMemory = 0x00000005,
    WGPUSurfaceGetCurrentTextureStatus_DeviceLost = 0x00000006,
    WGPUSurfaceGetCurrentTextureStatus_Error = 0x00000007,
    WGPUSurfaceGetCurrentTextureStatus_Force32 = 0x7FFFFFFF
} WGPUSurfaceGetCurrentTextureStatus WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUTextureAspect {
    WGPUTextureAspect_Undefined = 0x00000000,
    WGPUTextureAspect_All = 0x00000001,
    WGPUTextureAspect_StencilOnly = 0x00000002,
    WGPUTextureAspect_DepthOnly = 0x00000003,
    WGPUTextureAspect_Plane0Only = 0x00000004,
    WGPUTextureAspect_Plane1Only = 0x00000005,
    WGPUTextureAspect_Plane2Only = 0x00000006,
    WGPUTextureAspect_Force32 = 0x7FFFFFFF
} WGPUTextureAspect WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUTextureDimension {
    WGPUTextureDimension_Undefined = 0x00000000,
    WGPUTextureDimension_1D = 0x00000001,
    WGPUTextureDimension_2D = 0x00000002,
    WGPUTextureDimension_3D = 0x00000003,
    WGPUTextureDimension_Force32 = 0x7FFFFFFF
} WGPUTextureDimension WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUTextureFormat {
    WGPUTextureFormat_Undefined = 0x00000000,
    WGPUTextureFormat_R8Unorm = 0x00000001,
    WGPUTextureFormat_R8Snorm = 0x00000002,
    WGPUTextureFormat_R8Uint = 0x00000003,
    WGPUTextureFormat_R8Sint = 0x00000004,
    WGPUTextureFormat_R16Uint = 0x00000005,
    WGPUTextureFormat_R16Sint = 0x00000006,
    WGPUTextureFormat_R16Float = 0x00000007,
    WGPUTextureFormat_RG8Unorm = 0x00000008,
    WGPUTextureFormat_RG8Snorm = 0x00000009,
    WGPUTextureFormat_RG8Uint = 0x0000000A,
    WGPUTextureFormat_RG8Sint = 0x0000000B,
    WGPUTextureFormat_R32Float = 0x0000000C,
    WGPUTextureFormat_R32Uint = 0x0000000D,
    WGPUTextureFormat_R32Sint = 0x0000000E,
    WGPUTextureFormat_RG16Uint = 0x0000000F,
    WGPUTextureFormat_RG16Sint = 0x00000010,
    WGPUTextureFormat_RG16Float = 0x00000011,
    WGPUTextureFormat_RGBA8Unorm = 0x00000012,
    WGPUTextureFormat_RGBA8UnormSrgb = 0x00000013,
    WGPUTextureFormat_RGBA8Snorm = 0x00000014,
    WGPUTextureFormat_RGBA8Uint = 0x00000015,
    WGPUTextureFormat_RGBA8Sint = 0x00000016,
    WGPUTextureFormat_BGRA8Unorm = 0x00000017,
    WGPUTextureFormat_BGRA8UnormSrgb = 0x00000018,
    WGPUTextureFormat_RGB10A2Uint = 0x00000019,
    WGPUTextureFormat_RGB10A2Unorm = 0x0000001A,
    WGPUTextureFormat_RG11B10Ufloat = 0x0000001B,
    WGPUTextureFormat_RGB9E5Ufloat = 0x0000001C,
    WGPUTextureFormat_RG32Float = 0x0000001D,
    WGPUTextureFormat_RG32Uint = 0x0000001E,
    WGPUTextureFormat_RG32Sint = 0x0000001F,
    WGPUTextureFormat_RGBA16Uint = 0x00000020,
    WGPUTextureFormat_RGBA16Sint = 0x00000021,
    WGPUTextureFormat_RGBA16Float = 0x00000022,
    WGPUTextureFormat_RGBA32Float = 0x00000023,
    WGPUTextureFormat_RGBA32Uint = 0x00000024,
    WGPUTextureFormat_RGBA32Sint = 0x00000025,
    WGPUTextureFormat_Stencil8 = 0x00000026,
    WGPUTextureFormat_Depth16Unorm = 0x00000027,
    WGPUTextureFormat_Depth24Plus = 0x00000028,
    WGPUTextureFormat_Depth24PlusStencil8 = 0x00000029,
    WGPUTextureFormat_Depth32Float = 0x0000002A,
    WGPUTextureFormat_Depth32FloatStencil8 = 0x0000002B,
    WGPUTextureFormat_BC1RGBAUnorm = 0x0000002C,
    WGPUTextureFormat_BC1RGBAUnormSrgb = 0x0000002D,
    WGPUTextureFormat_BC2RGBAUnorm = 0x0000002E,
    WGPUTextureFormat_BC2RGBAUnormSrgb = 0x0000002F,
    WGPUTextureFormat_BC3RGBAUnorm = 0x00000030,
    WGPUTextureFormat_BC3RGBAUnormSrgb = 0x00000031,
    WGPUTextureFormat_BC4RUnorm = 0x00000032,
    WGPUTextureFormat_BC4RSnorm = 0x00000033,
    WGPUTextureFormat_BC5RGUnorm = 0x00000034,
    WGPUTextureFormat_BC5RGSnorm = 0x00000035,
    WGPUTextureFormat_BC6HRGBUfloat = 0x00000036,
    WGPUTextureFormat_BC6HRGBFloat = 0x00000037,
    WGPUTextureFormat_BC7RGBAUnorm = 0x00000038,
    WGPUTextureFormat_BC7RGBAUnormSrgb = 0x00000039,
    WGPUTextureFormat_ETC2RGB8Unorm = 0x0000003A,
    WGPUTextureFormat_ETC2RGB8UnormSrgb = 0x0000003B,
    WGPUTextureFormat_ETC2RGB8A1Unorm = 0x0000003C,
    WGPUTextureFormat_ETC2RGB8A1UnormSrgb = 0x0000003D,
    WGPUTextureFormat_ETC2RGBA8Unorm = 0x0000003E,
    WGPUTextureFormat_ETC2RGBA8UnormSrgb = 0x0000003F,
    WGPUTextureFormat_EACR11Unorm = 0x00000040,
    WGPUTextureFormat_EACR11Snorm = 0x00000041,
    WGPUTextureFormat_EACRG11Unorm = 0x00000042,
    WGPUTextureFormat_EACRG11Snorm = 0x00000043,
    WGPUTextureFormat_ASTC4x4Unorm = 0x00000044,
    WGPUTextureFormat_ASTC4x4UnormSrgb = 0x00000045,
    WGPUTextureFormat_ASTC5x4Unorm = 0x00000046,
    WGPUTextureFormat_ASTC5x4UnormSrgb = 0x00000047,
    WGPUTextureFormat_ASTC5x5Unorm = 0x00000048,
    WGPUTextureFormat_ASTC5x5UnormSrgb = 0x00000049,
    WGPUTextureFormat_ASTC6x5Unorm = 0x0000004A,
    WGPUTextureFormat_ASTC6x5UnormSrgb = 0x0000004B,
    WGPUTextureFormat_ASTC6x6Unorm = 0x0000004C,
    WGPUTextureFormat_ASTC6x6UnormSrgb = 0x0000004D,
    WGPUTextureFormat_ASTC8x5Unorm = 0x0000004E,
    WGPUTextureFormat_ASTC8x5UnormSrgb = 0x0000004F,
    WGPUTextureFormat_ASTC8x6Unorm = 0x00000050,
    WGPUTextureFormat_ASTC8x6UnormSrgb = 0x00000051,
    WGPUTextureFormat_ASTC8x8Unorm = 0x00000052,
    WGPUTextureFormat_ASTC8x8UnormSrgb = 0x00000053,
    WGPUTextureFormat_ASTC10x5Unorm = 0x00000054,
    WGPUTextureFormat_ASTC10x5UnormSrgb = 0x00000055,
    WGPUTextureFormat_ASTC10x6Unorm = 0x00000056,
    WGPUTextureFormat_ASTC10x6UnormSrgb = 0x00000057,
    WGPUTextureFormat_ASTC10x8Unorm = 0x00000058,
    WGPUTextureFormat_ASTC10x8UnormSrgb = 0x00000059,
    WGPUTextureFormat_ASTC10x10Unorm = 0x0000005A,
    WGPUTextureFormat_ASTC10x10UnormSrgb = 0x0000005B,
    WGPUTextureFormat_ASTC12x10Unorm = 0x0000005C,
    WGPUTextureFormat_ASTC12x10UnormSrgb = 0x0000005D,
    WGPUTextureFormat_ASTC12x12Unorm = 0x0000005E,
    WGPUTextureFormat_ASTC12x12UnormSrgb = 0x0000005F,
    WGPUTextureFormat_R16Unorm = 0x00000060,
    WGPUTextureFormat_RG16Unorm = 0x00000061,
    WGPUTextureFormat_RGBA16Unorm = 0x00000062,
    WGPUTextureFormat_R16Snorm = 0x00000063,
    WGPUTextureFormat_RG16Snorm = 0x00000064,
    WGPUTextureFormat_RGBA16Snorm = 0x00000065,
    WGPUTextureFormat_R8BG8Biplanar420Unorm = 0x00000066,
    WGPUTextureFormat_R10X6BG10X6Biplanar420Unorm = 0x00000067,
    WGPUTextureFormat_R8BG8A8Triplanar420Unorm = 0x00000068,
    WGPUTextureFormat_R8BG8Biplanar422Unorm = 0x00000069,
    WGPUTextureFormat_R8BG8Biplanar444Unorm = 0x0000006A,
    WGPUTextureFormat_R10X6BG10X6Biplanar422Unorm = 0x0000006B,
    WGPUTextureFormat_R10X6BG10X6Biplanar444Unorm = 0x0000006C,
    WGPUTextureFormat_External = 0x0000006D,
    WGPUTextureFormat_Force32 = 0x7FFFFFFF
} WGPUTextureFormat WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUTextureSampleType {
    WGPUTextureSampleType_Undefined = 0x00000000,
    WGPUTextureSampleType_Float = 0x00000001,
    WGPUTextureSampleType_UnfilterableFloat = 0x00000002,
    WGPUTextureSampleType_Depth = 0x00000003,
    WGPUTextureSampleType_Sint = 0x00000004,
    WGPUTextureSampleType_Uint = 0x00000005,
    WGPUTextureSampleType_Force32 = 0x7FFFFFFF
} WGPUTextureSampleType WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUTextureViewDimension {
    WGPUTextureViewDimension_Undefined = 0x00000000,
    WGPUTextureViewDimension_1D = 0x00000001,
    WGPUTextureViewDimension_2D = 0x00000002,
    WGPUTextureViewDimension_2DArray = 0x00000003,
    WGPUTextureViewDimension_Cube = 0x00000004,
    WGPUTextureViewDimension_CubeArray = 0x00000005,
    WGPUTextureViewDimension_3D = 0x00000006,
    WGPUTextureViewDimension_Force32 = 0x7FFFFFFF
} WGPUTextureViewDimension WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUVertexFormat {
    WGPUVertexFormat_Uint8x2 = 0x00000001,
    WGPUVertexFormat_Uint8x4 = 0x00000002,
    WGPUVertexFormat_Sint8x2 = 0x00000003,
    WGPUVertexFormat_Sint8x4 = 0x00000004,
    WGPUVertexFormat_Unorm8x2 = 0x00000005,
    WGPUVertexFormat_Unorm8x4 = 0x00000006,
    WGPUVertexFormat_Snorm8x2 = 0x00000007,
    WGPUVertexFormat_Snorm8x4 = 0x00000008,
    WGPUVertexFormat_Uint16x2 = 0x00000009,
    WGPUVertexFormat_Uint16x4 = 0x0000000A,
    WGPUVertexFormat_Sint16x2 = 0x0000000B,
    WGPUVertexFormat_Sint16x4 = 0x0000000C,
    WGPUVertexFormat_Unorm16x2 = 0x0000000D,
    WGPUVertexFormat_Unorm16x4 = 0x0000000E,
    WGPUVertexFormat_Snorm16x2 = 0x0000000F,
    WGPUVertexFormat_Snorm16x4 = 0x00000010,
    WGPUVertexFormat_Float16x2 = 0x00000011,
    WGPUVertexFormat_Float16x4 = 0x00000012,
    WGPUVertexFormat_Float32 = 0x00000013,
    WGPUVertexFormat_Float32x2 = 0x00000014,
    WGPUVertexFormat_Float32x3 = 0x00000015,
    WGPUVertexFormat_Float32x4 = 0x00000016,
    WGPUVertexFormat_Uint32 = 0x00000017,
    WGPUVertexFormat_Uint32x2 = 0x00000018,
    WGPUVertexFormat_Uint32x3 = 0x00000019,
    WGPUVertexFormat_Uint32x4 = 0x0000001A,
    WGPUVertexFormat_Sint32 = 0x0000001B,
    WGPUVertexFormat_Sint32x2 = 0x0000001C,
    WGPUVertexFormat_Sint32x3 = 0x0000001D,
    WGPUVertexFormat_Sint32x4 = 0x0000001E,
    WGPUVertexFormat_Unorm10_10_10_2 = 0x0000001F,
    WGPUVertexFormat_Force32 = 0x7FFFFFFF
} WGPUVertexFormat WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUVertexStepMode {
    WGPUVertexStepMode_Undefined = 0x00000000,
    WGPUVertexStepMode_VertexBufferNotUsed = 0x00000001,
    WGPUVertexStepMode_Vertex = 0x00000002,
    WGPUVertexStepMode_Instance = 0x00000003,
    WGPUVertexStepMode_Force32 = 0x7FFFFFFF
} WGPUVertexStepMode WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUWaitStatus {
    WGPUWaitStatus_Success = 0x00000001,
    WGPUWaitStatus_TimedOut = 0x00000002,
    WGPUWaitStatus_UnsupportedTimeout = 0x00000003,
    WGPUWaitStatus_UnsupportedCount = 0x00000004,
    WGPUWaitStatus_UnsupportedMixedSources = 0x00000005,
    WGPUWaitStatus_Unknown = 0x00000006,
    WGPUWaitStatus_Force32 = 0x7FFFFFFF
} WGPUWaitStatus WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUBufferUsage {
    WGPUBufferUsage_None = 0x00000000,
    WGPUBufferUsage_MapRead = 0x00000001,
    WGPUBufferUsage_MapWrite = 0x00000002,
    WGPUBufferUsage_CopySrc = 0x00000004,
    WGPUBufferUsage_CopyDst = 0x00000008,
    WGPUBufferUsage_Index = 0x00000010,
    WGPUBufferUsage_Vertex = 0x00000020,
    WGPUBufferUsage_Uniform = 0x00000040,
    WGPUBufferUsage_Storage = 0x00000080,
    WGPUBufferUsage_Indirect = 0x00000100,
    WGPUBufferUsage_QueryResolve = 0x00000200,
    WGPUBufferUsage_Force32 = 0x7FFFFFFF
} WGPUBufferUsage WGPU_ENUM_ATTRIBUTE;
typedef WGPUFlags WGPUBufferUsageFlags WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUColorWriteMask {
    WGPUColorWriteMask_None = 0x00000000,
    WGPUColorWriteMask_Red = 0x00000001,
    WGPUColorWriteMask_Green = 0x00000002,
    WGPUColorWriteMask_Blue = 0x00000004,
    WGPUColorWriteMask_Alpha = 0x00000008,
    WGPUColorWriteMask_All = 0x0000000F,
    WGPUColorWriteMask_Force32 = 0x7FFFFFFF
} WGPUColorWriteMask WGPU_ENUM_ATTRIBUTE;
typedef WGPUFlags WGPUColorWriteMaskFlags WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUHeapProperty {
    WGPUHeapProperty_DeviceLocal = 0x00000001,
    WGPUHeapProperty_HostVisible = 0x00000002,
    WGPUHeapProperty_HostCoherent = 0x00000004,
    WGPUHeapProperty_HostUncached = 0x00000008,
    WGPUHeapProperty_HostCached = 0x00000010,
    WGPUHeapProperty_Force32 = 0x7FFFFFFF
} WGPUHeapProperty WGPU_ENUM_ATTRIBUTE;
typedef WGPUFlags WGPUHeapPropertyFlags WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUMapMode {
    WGPUMapMode_None = 0x00000000,
    WGPUMapMode_Read = 0x00000001,
    WGPUMapMode_Write = 0x00000002,
    WGPUMapMode_Force32 = 0x7FFFFFFF
} WGPUMapMode WGPU_ENUM_ATTRIBUTE;
typedef WGPUFlags WGPUMapModeFlags WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUShaderStage {
    WGPUShaderStage_None = 0x00000000,
    WGPUShaderStage_Vertex = 0x00000001,
    WGPUShaderStage_Fragment = 0x00000002,
    WGPUShaderStage_Compute = 0x00000004,
    WGPUShaderStage_Force32 = 0x7FFFFFFF
} WGPUShaderStage WGPU_ENUM_ATTRIBUTE;
typedef WGPUFlags WGPUShaderStageFlags WGPU_ENUM_ATTRIBUTE;

typedef enum WGPUTextureUsage {
    WGPUTextureUsage_None = 0x00000000,
    WGPUTextureUsage_CopySrc = 0x00000001,
    WGPUTextureUsage_CopyDst = 0x00000002,
    WGPUTextureUsage_TextureBinding = 0x00000004,
    WGPUTextureUsage_StorageBinding = 0x00000008,
    WGPUTextureUsage_RenderAttachment = 0x00000010,
    WGPUTextureUsage_TransientAttachment = 0x00000020,
    WGPUTextureUsage_StorageAttachment = 0x00000040,
    WGPUTextureUsage_Force32 = 0x7FFFFFFF
} WGPUTextureUsage WGPU_ENUM_ATTRIBUTE;
typedef WGPUFlags WGPUTextureUsageFlags WGPU_ENUM_ATTRIBUTE;

typedef void (*WGPUBufferMapCallback)(WGPUBufferMapAsyncStatus status, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUCallback)(void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUCompilationInfoCallback)(WGPUCompilationInfoRequestStatus status, struct WGPUCompilationInfo const * compilationInfo, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUCreateComputePipelineAsyncCallback)(WGPUCreatePipelineAsyncStatus status, WGPUComputePipeline pipeline, char const * message, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUCreateRenderPipelineAsyncCallback)(WGPUCreatePipelineAsyncStatus status, WGPURenderPipeline pipeline, char const * message, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef size_t (*WGPUDawnLoadCacheDataFunction)(void const * key, size_t keySize, void * value, size_t valueSize, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUDawnStoreCacheDataFunction)(void const * key, size_t keySize, void const * value, size_t valueSize, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUDeviceLostCallback)(WGPUDeviceLostReason reason, char const * message, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUDeviceLostCallbackNew)(WGPUDevice const * device, WGPUDeviceLostReason reason, char const * message, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUErrorCallback)(WGPUErrorType type, char const * message, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPULoggingCallback)(WGPULoggingType type, char const * message, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUPopErrorScopeCallback)(WGPUPopErrorScopeStatus status, WGPUErrorType type, char const * message, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProc)(void) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUQueueWorkDoneCallback)(WGPUQueueWorkDoneStatus status, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPURequestAdapterCallback)(WGPURequestAdapterStatus status, WGPUAdapter adapter, char const * message, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPURequestDeviceCallback)(WGPURequestDeviceStatus status, WGPUDevice device, char const * message, void * userdata) WGPU_FUNCTION_ATTRIBUTE;

// Callback function pointers
typedef void (*WGPUBufferMapCallback2)(WGPUMapAsyncStatus status, char const * message, void* userdata1, void* userdata2) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUCompilationInfoCallback2)(WGPUCompilationInfoRequestStatus status, struct WGPUCompilationInfo const * compilationInfo, void* userdata1, void* userdata2) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUCreateComputePipelineAsyncCallback2)(WGPUCreatePipelineAsyncStatus status, WGPUComputePipeline pipeline, char const * message, void* userdata1, void* userdata2) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUCreateRenderPipelineAsyncCallback2)(WGPUCreatePipelineAsyncStatus status, WGPURenderPipeline pipeline, char const * message, void* userdata1, void* userdata2) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUPopErrorScopeCallback2)(WGPUPopErrorScopeStatus status, WGPUErrorType type, char const * message, void* userdata1, void* userdata2) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUQueueWorkDoneCallback2)(WGPUQueueWorkDoneStatus status, void* userdata1, void* userdata2) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPURequestAdapterCallback2)(WGPURequestAdapterStatus status, WGPUAdapter adapter, char const * message, void* userdata1, void* userdata2) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPURequestDeviceCallback2)(WGPURequestDeviceStatus status, WGPUDevice device, char const * message, void* userdata1, void* userdata2) WGPU_FUNCTION_ATTRIBUTE;

typedef struct WGPUChainedStruct {
    struct WGPUChainedStruct const * next;
    WGPUSType sType;
} WGPUChainedStruct WGPU_STRUCTURE_ATTRIBUTE;

typedef struct WGPUChainedStructOut {
    struct WGPUChainedStructOut * next;
    WGPUSType sType;
} WGPUChainedStructOut WGPU_STRUCTURE_ATTRIBUTE;


#define WGPU_COMMA ,

typedef struct WGPUAdapterInfo {
    WGPUChainedStructOut * nextInChain;
    char const * vendor;
    char const * architecture;
    char const * device;
    char const * description;
    WGPUBackendType backendType;
    WGPUAdapterType adapterType;
    uint32_t vendorID;
    uint32_t deviceID;
    WGPUBool compatibilityMode;
} WGPUAdapterInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_ADAPTER_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUAdapterInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.vendor=*/nullptr WGPU_COMMA \
    /*.architecture=*/nullptr WGPU_COMMA \
    /*.device=*/nullptr WGPU_COMMA \
    /*.description=*/nullptr WGPU_COMMA \
    /*.backendType=*/{} WGPU_COMMA \
    /*.adapterType=*/{} WGPU_COMMA \
    /*.vendorID=*/{} WGPU_COMMA \
    /*.deviceID=*/{} WGPU_COMMA \
    /*.compatibilityMode=*/false WGPU_COMMA \
})

typedef struct WGPUAdapterProperties {
    WGPUChainedStructOut * nextInChain;
    uint32_t vendorID;
    char const * vendorName;
    char const * architecture;
    uint32_t deviceID;
    char const * name;
    char const * driverDescription;
    WGPUAdapterType adapterType;
    WGPUBackendType backendType;
    WGPUBool compatibilityMode;
} WGPUAdapterProperties WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_ADAPTER_PROPERTIES_INIT WGPU_MAKE_INIT_STRUCT(WGPUAdapterProperties, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.vendorID=*/{} WGPU_COMMA \
    /*.vendorName=*/nullptr WGPU_COMMA \
    /*.architecture=*/nullptr WGPU_COMMA \
    /*.deviceID=*/{} WGPU_COMMA \
    /*.name=*/nullptr WGPU_COMMA \
    /*.driverDescription=*/nullptr WGPU_COMMA \
    /*.adapterType=*/{} WGPU_COMMA \
    /*.backendType=*/{} WGPU_COMMA \
    /*.compatibilityMode=*/false WGPU_COMMA \
})

// Can be chained in WGPUAdapterInfo
// Can be chained in WGPUAdapterProperties
typedef struct WGPUAdapterPropertiesD3D {
    WGPUChainedStructOut chain;
    uint32_t shaderModel;
} WGPUAdapterPropertiesD3D WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_ADAPTER_PROPERTIES_D3D_INIT WGPU_MAKE_INIT_STRUCT(WGPUAdapterPropertiesD3D, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.shaderModel=*/{} WGPU_COMMA \
})

// Can be chained in WGPUAdapterInfo
// Can be chained in WGPUAdapterProperties
typedef struct WGPUAdapterPropertiesVk {
    WGPUChainedStructOut chain;
    uint32_t driverVersion;
} WGPUAdapterPropertiesVk WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_ADAPTER_PROPERTIES_VK_INIT WGPU_MAKE_INIT_STRUCT(WGPUAdapterPropertiesVk, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.driverVersion=*/{} WGPU_COMMA \
})

typedef struct WGPUBindGroupEntry {
    WGPUChainedStruct const * nextInChain;
    uint32_t binding;
    WGPU_NULLABLE WGPUBuffer buffer;
    uint64_t offset;
    uint64_t size;
    WGPU_NULLABLE WGPUSampler sampler;
    WGPU_NULLABLE WGPUTextureView textureView;
} WGPUBindGroupEntry WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_BIND_GROUP_ENTRY_INIT WGPU_MAKE_INIT_STRUCT(WGPUBindGroupEntry, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.binding=*/{} WGPU_COMMA \
    /*.buffer=*/nullptr WGPU_COMMA \
    /*.offset=*/0 WGPU_COMMA \
    /*.size=*/WGPU_WHOLE_SIZE WGPU_COMMA \
    /*.sampler=*/nullptr WGPU_COMMA \
    /*.textureView=*/nullptr WGPU_COMMA \
})

typedef struct WGPUBlendComponent {
    WGPUBlendOperation operation;
    WGPUBlendFactor srcFactor;
    WGPUBlendFactor dstFactor;
} WGPUBlendComponent WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_BLEND_COMPONENT_INIT WGPU_MAKE_INIT_STRUCT(WGPUBlendComponent, { \
    /*.operation=*/WGPUBlendOperation_Add WGPU_COMMA \
    /*.srcFactor=*/WGPUBlendFactor_One WGPU_COMMA \
    /*.dstFactor=*/WGPUBlendFactor_Zero WGPU_COMMA \
})

typedef struct WGPUBufferBindingLayout {
    WGPUChainedStruct const * nextInChain;
    WGPUBufferBindingType type;
    WGPUBool hasDynamicOffset;
    uint64_t minBindingSize;
} WGPUBufferBindingLayout WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_BUFFER_BINDING_LAYOUT_INIT WGPU_MAKE_INIT_STRUCT(WGPUBufferBindingLayout, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.type=*/WGPUBufferBindingType_Undefined WGPU_COMMA \
    /*.hasDynamicOffset=*/false WGPU_COMMA \
    /*.minBindingSize=*/0 WGPU_COMMA \
})

typedef struct WGPUBufferDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    WGPUBufferUsageFlags usage;
    uint64_t size;
    WGPUBool mappedAtCreation;
} WGPUBufferDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_BUFFER_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUBufferDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.usage=*/{} WGPU_COMMA \
    /*.size=*/{} WGPU_COMMA \
    /*.mappedAtCreation=*/false WGPU_COMMA \
})

// Can be chained in WGPUBufferDescriptor
typedef struct WGPUBufferHostMappedPointer {
    WGPUChainedStruct chain;
    void * pointer;
    WGPUCallback disposeCallback;
    void * userdata;
} WGPUBufferHostMappedPointer WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_BUFFER_HOST_MAPPED_POINTER_INIT WGPU_MAKE_INIT_STRUCT(WGPUBufferHostMappedPointer, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.pointer=*/{} WGPU_COMMA \
    /*.disposeCallback=*/{} WGPU_COMMA \
    /*.userdata=*/{} WGPU_COMMA \
})

typedef struct WGPUBufferMapCallbackInfo {
    WGPUChainedStruct const * nextInChain;
    WGPUCallbackMode mode;
    WGPUBufferMapCallback callback;
    void * userdata;
} WGPUBufferMapCallbackInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_BUFFER_MAP_CALLBACK_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUBufferMapCallbackInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.mode=*/{} WGPU_COMMA \
    /*.callback=*/{} WGPU_COMMA \
    /*.userdata=*/{} WGPU_COMMA \
})

typedef struct WGPUColor {
    double r;
    double g;
    double b;
    double a;
} WGPUColor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COLOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUColor, { \
    /*.r=*/{} WGPU_COMMA \
    /*.g=*/{} WGPU_COMMA \
    /*.b=*/{} WGPU_COMMA \
    /*.a=*/{} WGPU_COMMA \
})

// Can be chained in WGPUColorTargetState
typedef struct WGPUColorTargetStateExpandResolveTextureDawn {
    WGPUChainedStruct chain;
    WGPUBool enabled;
} WGPUColorTargetStateExpandResolveTextureDawn WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COLOR_TARGET_STATE_EXPAND_RESOLVE_TEXTURE_DAWN_INIT WGPU_MAKE_INIT_STRUCT(WGPUColorTargetStateExpandResolveTextureDawn, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.enabled=*/false WGPU_COMMA \
})

typedef struct WGPUCommandBufferDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
} WGPUCommandBufferDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COMMAND_BUFFER_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUCommandBufferDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
})

typedef struct WGPUCommandEncoderDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
} WGPUCommandEncoderDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COMMAND_ENCODER_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUCommandEncoderDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
})

typedef struct WGPUCompilationInfoCallbackInfo {
    WGPUChainedStruct const * nextInChain;
    WGPUCallbackMode mode;
    WGPUCompilationInfoCallback callback;
    void * userdata;
} WGPUCompilationInfoCallbackInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COMPILATION_INFO_CALLBACK_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUCompilationInfoCallbackInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.mode=*/{} WGPU_COMMA \
    /*.callback=*/{} WGPU_COMMA \
    /*.userdata=*/nullptr WGPU_COMMA \
})

typedef struct WGPUCompilationMessage {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * message;
    WGPUCompilationMessageType type;
    uint64_t lineNum;
    uint64_t linePos;
    uint64_t offset;
    uint64_t length;
    uint64_t utf16LinePos;
    uint64_t utf16Offset;
    uint64_t utf16Length;
} WGPUCompilationMessage WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COMPILATION_MESSAGE_INIT WGPU_MAKE_INIT_STRUCT(WGPUCompilationMessage, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.message=*/nullptr WGPU_COMMA \
    /*.type=*/{} WGPU_COMMA \
    /*.lineNum=*/{} WGPU_COMMA \
    /*.linePos=*/{} WGPU_COMMA \
    /*.offset=*/{} WGPU_COMMA \
    /*.length=*/{} WGPU_COMMA \
    /*.utf16LinePos=*/{} WGPU_COMMA \
    /*.utf16Offset=*/{} WGPU_COMMA \
    /*.utf16Length=*/{} WGPU_COMMA \
})

typedef struct WGPUComputePassTimestampWrites {
    WGPUQuerySet querySet;
    uint32_t beginningOfPassWriteIndex;
    uint32_t endOfPassWriteIndex;
} WGPUComputePassTimestampWrites WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COMPUTE_PASS_TIMESTAMP_WRITES_INIT WGPU_MAKE_INIT_STRUCT(WGPUComputePassTimestampWrites, { \
    /*.querySet=*/{} WGPU_COMMA \
    /*.beginningOfPassWriteIndex=*/WGPU_QUERY_SET_INDEX_UNDEFINED WGPU_COMMA \
    /*.endOfPassWriteIndex=*/WGPU_QUERY_SET_INDEX_UNDEFINED WGPU_COMMA \
})

typedef struct WGPUConstantEntry {
    WGPUChainedStruct const * nextInChain;
    char const * key;
    double value;
} WGPUConstantEntry WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_CONSTANT_ENTRY_INIT WGPU_MAKE_INIT_STRUCT(WGPUConstantEntry, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.key=*/{} WGPU_COMMA \
    /*.value=*/{} WGPU_COMMA \
})

typedef struct WGPUCopyTextureForBrowserOptions {
    WGPUChainedStruct const * nextInChain;
    WGPUBool flipY;
    WGPUBool needsColorSpaceConversion;
    WGPUAlphaMode srcAlphaMode;
    WGPU_NULLABLE float const * srcTransferFunctionParameters;
    WGPU_NULLABLE float const * conversionMatrix;
    WGPU_NULLABLE float const * dstTransferFunctionParameters;
    WGPUAlphaMode dstAlphaMode;
    WGPUBool internalUsage;
} WGPUCopyTextureForBrowserOptions WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COPY_TEXTURE_FOR_BROWSER_OPTIONS_INIT WGPU_MAKE_INIT_STRUCT(WGPUCopyTextureForBrowserOptions, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.flipY=*/false WGPU_COMMA \
    /*.needsColorSpaceConversion=*/false WGPU_COMMA \
    /*.srcAlphaMode=*/WGPUAlphaMode_Unpremultiplied WGPU_COMMA \
    /*.srcTransferFunctionParameters=*/nullptr WGPU_COMMA \
    /*.conversionMatrix=*/nullptr WGPU_COMMA \
    /*.dstTransferFunctionParameters=*/nullptr WGPU_COMMA \
    /*.dstAlphaMode=*/WGPUAlphaMode_Unpremultiplied WGPU_COMMA \
    /*.internalUsage=*/false WGPU_COMMA \
})

typedef struct WGPUCreateComputePipelineAsyncCallbackInfo {
    WGPUChainedStruct const * nextInChain;
    WGPUCallbackMode mode;
    WGPUCreateComputePipelineAsyncCallback callback;
    void * userdata;
} WGPUCreateComputePipelineAsyncCallbackInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_CREATE_COMPUTE_PIPELINE_ASYNC_CALLBACK_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUCreateComputePipelineAsyncCallbackInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.mode=*/{} WGPU_COMMA \
    /*.callback=*/{} WGPU_COMMA \
    /*.userdata=*/{} WGPU_COMMA \
})

typedef struct WGPUCreateRenderPipelineAsyncCallbackInfo {
    WGPUChainedStruct const * nextInChain;
    WGPUCallbackMode mode;
    WGPUCreateRenderPipelineAsyncCallback callback;
    void * userdata;
} WGPUCreateRenderPipelineAsyncCallbackInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_CREATE_RENDER_PIPELINE_ASYNC_CALLBACK_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUCreateRenderPipelineAsyncCallbackInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.mode=*/{} WGPU_COMMA \
    /*.callback=*/{} WGPU_COMMA \
    /*.userdata=*/{} WGPU_COMMA \
})

// Can be chained in WGPUInstanceDescriptor
typedef struct WGPUDawnWGSLBlocklist {
    WGPUChainedStruct chain;
    size_t blocklistedFeatureCount;
    const char* const * blocklistedFeatures;
} WGPUDawnWGSLBlocklist WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_WGSL_BLOCKLIST_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnWGSLBlocklist, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.blocklistedFeatureCount=*/0 WGPU_COMMA \
    /*.blocklistedFeatures=*/{} WGPU_COMMA \
})

// Can be chained in WGPUAdapterInfo
// Can be chained in WGPUAdapterProperties
typedef struct WGPUDawnAdapterPropertiesPowerPreference {
    WGPUChainedStructOut chain;
    WGPUPowerPreference powerPreference;
} WGPUDawnAdapterPropertiesPowerPreference WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_ADAPTER_PROPERTIES_POWER_PREFERENCE_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnAdapterPropertiesPowerPreference, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.powerPreference=*/WGPUPowerPreference_Undefined WGPU_COMMA \
})

// Can be chained in WGPUBufferDescriptor
typedef struct WGPUDawnBufferDescriptorErrorInfoFromWireClient {
    WGPUChainedStruct chain;
    WGPUBool outOfMemory;
} WGPUDawnBufferDescriptorErrorInfoFromWireClient WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_BUFFER_DESCRIPTOR_ERROR_INFO_FROM_WIRE_CLIENT_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnBufferDescriptorErrorInfoFromWireClient, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.outOfMemory=*/false WGPU_COMMA \
})

// Can be chained in WGPUDeviceDescriptor
typedef struct WGPUDawnCacheDeviceDescriptor {
    WGPUChainedStruct chain;
    char const * isolationKey;
    WGPUDawnLoadCacheDataFunction loadDataFunction;
    WGPUDawnStoreCacheDataFunction storeDataFunction;
    void * functionUserdata;
} WGPUDawnCacheDeviceDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_CACHE_DEVICE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnCacheDeviceDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.isolationKey=*/"" WGPU_COMMA \
    /*.loadDataFunction=*/nullptr WGPU_COMMA \
    /*.storeDataFunction=*/nullptr WGPU_COMMA \
    /*.functionUserdata=*/nullptr WGPU_COMMA \
})

// Can be chained in WGPUComputePipelineDescriptor
typedef struct WGPUDawnComputePipelineFullSubgroups {
    WGPUChainedStruct chain;
    WGPUBool requiresFullSubgroups;
} WGPUDawnComputePipelineFullSubgroups WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_COMPUTE_PIPELINE_FULL_SUBGROUPS_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnComputePipelineFullSubgroups, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.requiresFullSubgroups=*/false WGPU_COMMA \
})

// Can be chained in WGPUCommandEncoderDescriptor
typedef struct WGPUDawnEncoderInternalUsageDescriptor {
    WGPUChainedStruct chain;
    WGPUBool useInternalUsages;
} WGPUDawnEncoderInternalUsageDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_ENCODER_INTERNAL_USAGE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnEncoderInternalUsageDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.useInternalUsages=*/false WGPU_COMMA \
})

// Can be chained in WGPUSupportedLimits
typedef struct WGPUDawnExperimentalSubgroupLimits {
    WGPUChainedStructOut chain;
    uint32_t minSubgroupSize;
    uint32_t maxSubgroupSize;
} WGPUDawnExperimentalSubgroupLimits WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_EXPERIMENTAL_SUBGROUP_LIMITS_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnExperimentalSubgroupLimits, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.minSubgroupSize=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxSubgroupSize=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
})

// Can be chained in WGPURenderPassColorAttachment
typedef struct WGPUDawnRenderPassColorAttachmentRenderToSingleSampled {
    WGPUChainedStruct chain;
    uint32_t implicitSampleCount;
} WGPUDawnRenderPassColorAttachmentRenderToSingleSampled WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_RENDER_PASS_COLOR_ATTACHMENT_RENDER_TO_SINGLE_SAMPLED_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnRenderPassColorAttachmentRenderToSingleSampled, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.implicitSampleCount=*/1 WGPU_COMMA \
})

// Can be chained in WGPUShaderModuleDescriptor
typedef struct WGPUDawnShaderModuleSPIRVOptionsDescriptor {
    WGPUChainedStruct chain;
    WGPUBool allowNonUniformDerivatives;
} WGPUDawnShaderModuleSPIRVOptionsDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_SHADER_MODULE_SPIRV_OPTIONS_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnShaderModuleSPIRVOptionsDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.allowNonUniformDerivatives=*/false WGPU_COMMA \
})

// Can be chained in WGPUTextureDescriptor
typedef struct WGPUDawnTextureInternalUsageDescriptor {
    WGPUChainedStruct chain;
    WGPUTextureUsageFlags internalUsage;
} WGPUDawnTextureInternalUsageDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_TEXTURE_INTERNAL_USAGE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnTextureInternalUsageDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.internalUsage=*/WGPUTextureUsage_None WGPU_COMMA \
})

// Can be chained in WGPUInstanceDescriptor
// Can be chained in WGPURequestAdapterOptions
// Can be chained in WGPUDeviceDescriptor
typedef struct WGPUDawnTogglesDescriptor {
    WGPUChainedStruct chain;
    size_t enabledToggleCount;
    const char* const * enabledToggles;
    size_t disabledToggleCount;
    const char* const * disabledToggles;
} WGPUDawnTogglesDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_TOGGLES_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnTogglesDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.enabledToggleCount=*/0 WGPU_COMMA \
    /*.enabledToggles=*/{} WGPU_COMMA \
    /*.disabledToggleCount=*/0 WGPU_COMMA \
    /*.disabledToggles=*/{} WGPU_COMMA \
})

// Can be chained in WGPUInstanceDescriptor
typedef struct WGPUDawnWireWGSLControl {
    WGPUChainedStruct chain;
    WGPUBool enableExperimental;
    WGPUBool enableUnsafe;
    WGPUBool enableTesting;
} WGPUDawnWireWGSLControl WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DAWN_WIRE_WGSL_CONTROL_INIT WGPU_MAKE_INIT_STRUCT(WGPUDawnWireWGSLControl, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.enableExperimental=*/false WGPU_COMMA \
    /*.enableUnsafe=*/false WGPU_COMMA \
    /*.enableTesting=*/false WGPU_COMMA \
})

// Can be chained in WGPUDepthStencilState
typedef struct WGPUDepthStencilStateDepthWriteDefinedDawn {
    WGPUChainedStruct chain;
    WGPUBool depthWriteDefined;
} WGPUDepthStencilStateDepthWriteDefinedDawn WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DEPTH_STENCIL_STATE_DEPTH_WRITE_DEFINED_DAWN_INIT WGPU_MAKE_INIT_STRUCT(WGPUDepthStencilStateDepthWriteDefinedDawn, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.depthWriteDefined=*/{} WGPU_COMMA \
})

typedef struct WGPUDeviceLostCallbackInfo {
    WGPUChainedStruct const * nextInChain;
    WGPUCallbackMode mode;
    WGPUDeviceLostCallbackNew callback;
    void * userdata;
} WGPUDeviceLostCallbackInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DEVICE_LOST_CALLBACK_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUDeviceLostCallbackInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.mode=*/WGPUCallbackMode_WaitAnyOnly WGPU_COMMA \
    /*.callback=*/nullptr WGPU_COMMA \
    /*.userdata=*/nullptr WGPU_COMMA \
})

typedef struct WGPUDrmFormatProperties {
    uint64_t modifier;
    uint32_t modifierPlaneCount;
} WGPUDrmFormatProperties WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DRM_FORMAT_PROPERTIES_INIT WGPU_MAKE_INIT_STRUCT(WGPUDrmFormatProperties, { \
    /*.modifier=*/{} WGPU_COMMA \
    /*.modifierPlaneCount=*/{} WGPU_COMMA \
})

typedef struct WGPUExtent2D {
    uint32_t width;
    uint32_t height;
} WGPUExtent2D WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_EXTENT_2D_INIT WGPU_MAKE_INIT_STRUCT(WGPUExtent2D, { \
    /*.width=*/{} WGPU_COMMA \
    /*.height=*/{} WGPU_COMMA \
})

typedef struct WGPUExtent3D {
    uint32_t width;
    uint32_t height;
    uint32_t depthOrArrayLayers;
} WGPUExtent3D WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_EXTENT_3D_INIT WGPU_MAKE_INIT_STRUCT(WGPUExtent3D, { \
    /*.width=*/{} WGPU_COMMA \
    /*.height=*/1 WGPU_COMMA \
    /*.depthOrArrayLayers=*/1 WGPU_COMMA \
})

// Can be chained in WGPUBindGroupEntry
typedef struct WGPUExternalTextureBindingEntry {
    WGPUChainedStruct chain;
    WGPUExternalTexture externalTexture;
} WGPUExternalTextureBindingEntry WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_EXTERNAL_TEXTURE_BINDING_ENTRY_INIT WGPU_MAKE_INIT_STRUCT(WGPUExternalTextureBindingEntry, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.externalTexture=*/{} WGPU_COMMA \
})

// Can be chained in WGPUBindGroupLayoutEntry
typedef struct WGPUExternalTextureBindingLayout {
    WGPUChainedStruct chain;
} WGPUExternalTextureBindingLayout WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_EXTERNAL_TEXTURE_BINDING_LAYOUT_INIT WGPU_MAKE_INIT_STRUCT(WGPUExternalTextureBindingLayout, { \
    /*.chain=*/{} WGPU_COMMA \
})

typedef struct WGPUFormatCapabilities {
    WGPUChainedStructOut * nextInChain;
} WGPUFormatCapabilities WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_FORMAT_CAPABILITIES_INIT WGPU_MAKE_INIT_STRUCT(WGPUFormatCapabilities, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
})

typedef struct WGPUFuture {
    uint64_t id;
} WGPUFuture WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_FUTURE_INIT WGPU_MAKE_INIT_STRUCT(WGPUFuture, { \
    /*.id=*/{} WGPU_COMMA \
})

typedef struct WGPUInstanceFeatures {
    WGPUChainedStruct const * nextInChain;
    WGPUBool timedWaitAnyEnable;
    size_t timedWaitAnyMaxCount;
} WGPUInstanceFeatures WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_INSTANCE_FEATURES_INIT WGPU_MAKE_INIT_STRUCT(WGPUInstanceFeatures, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.timedWaitAnyEnable=*/false WGPU_COMMA \
    /*.timedWaitAnyMaxCount=*/0 WGPU_COMMA \
})

typedef struct WGPULimits {
    uint32_t maxTextureDimension1D;
    uint32_t maxTextureDimension2D;
    uint32_t maxTextureDimension3D;
    uint32_t maxTextureArrayLayers;
    uint32_t maxBindGroups;
    uint32_t maxBindGroupsPlusVertexBuffers;
    uint32_t maxBindingsPerBindGroup;
    uint32_t maxDynamicUniformBuffersPerPipelineLayout;
    uint32_t maxDynamicStorageBuffersPerPipelineLayout;
    uint32_t maxSampledTexturesPerShaderStage;
    uint32_t maxSamplersPerShaderStage;
    uint32_t maxStorageBuffersPerShaderStage;
    uint32_t maxStorageTexturesPerShaderStage;
    uint32_t maxUniformBuffersPerShaderStage;
    uint64_t maxUniformBufferBindingSize;
    uint64_t maxStorageBufferBindingSize;
    uint32_t minUniformBufferOffsetAlignment;
    uint32_t minStorageBufferOffsetAlignment;
    uint32_t maxVertexBuffers;
    uint64_t maxBufferSize;
    uint32_t maxVertexAttributes;
    uint32_t maxVertexBufferArrayStride;
    uint32_t maxInterStageShaderComponents;
    uint32_t maxInterStageShaderVariables;
    uint32_t maxColorAttachments;
    uint32_t maxColorAttachmentBytesPerSample;
    uint32_t maxComputeWorkgroupStorageSize;
    uint32_t maxComputeInvocationsPerWorkgroup;
    uint32_t maxComputeWorkgroupSizeX;
    uint32_t maxComputeWorkgroupSizeY;
    uint32_t maxComputeWorkgroupSizeZ;
    uint32_t maxComputeWorkgroupsPerDimension;
} WGPULimits WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_LIMITS_INIT WGPU_MAKE_INIT_STRUCT(WGPULimits, { \
    /*.maxTextureDimension1D=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxTextureDimension2D=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxTextureDimension3D=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxTextureArrayLayers=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxBindGroups=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxBindGroupsPlusVertexBuffers=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxBindingsPerBindGroup=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxDynamicUniformBuffersPerPipelineLayout=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxDynamicStorageBuffersPerPipelineLayout=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxSampledTexturesPerShaderStage=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxSamplersPerShaderStage=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxStorageBuffersPerShaderStage=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxStorageTexturesPerShaderStage=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxUniformBuffersPerShaderStage=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxUniformBufferBindingSize=*/WGPU_LIMIT_U64_UNDEFINED WGPU_COMMA \
    /*.maxStorageBufferBindingSize=*/WGPU_LIMIT_U64_UNDEFINED WGPU_COMMA \
    /*.minUniformBufferOffsetAlignment=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.minStorageBufferOffsetAlignment=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxVertexBuffers=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxBufferSize=*/WGPU_LIMIT_U64_UNDEFINED WGPU_COMMA \
    /*.maxVertexAttributes=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxVertexBufferArrayStride=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxInterStageShaderComponents=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxInterStageShaderVariables=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxColorAttachments=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxColorAttachmentBytesPerSample=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxComputeWorkgroupStorageSize=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxComputeInvocationsPerWorkgroup=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxComputeWorkgroupSizeX=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxComputeWorkgroupSizeY=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxComputeWorkgroupSizeZ=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
    /*.maxComputeWorkgroupsPerDimension=*/WGPU_LIMIT_U32_UNDEFINED WGPU_COMMA \
})

typedef struct WGPUMemoryHeapInfo {
    WGPUHeapPropertyFlags properties;
    uint64_t size;
} WGPUMemoryHeapInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_MEMORY_HEAP_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUMemoryHeapInfo, { \
    /*.properties=*/{} WGPU_COMMA \
    /*.size=*/{} WGPU_COMMA \
})

typedef struct WGPUMultisampleState {
    WGPUChainedStruct const * nextInChain;
    uint32_t count;
    uint32_t mask;
    WGPUBool alphaToCoverageEnabled;
} WGPUMultisampleState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_MULTISAMPLE_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUMultisampleState, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.count=*/1 WGPU_COMMA \
    /*.mask=*/0xFFFFFFFF WGPU_COMMA \
    /*.alphaToCoverageEnabled=*/false WGPU_COMMA \
})

typedef struct WGPUOrigin2D {
    uint32_t x;
    uint32_t y;
} WGPUOrigin2D WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_ORIGIN_2D_INIT WGPU_MAKE_INIT_STRUCT(WGPUOrigin2D, { \
    /*.x=*/0 WGPU_COMMA \
    /*.y=*/0 WGPU_COMMA \
})

typedef struct WGPUOrigin3D {
    uint32_t x;
    uint32_t y;
    uint32_t z;
} WGPUOrigin3D WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_ORIGIN_3D_INIT WGPU_MAKE_INIT_STRUCT(WGPUOrigin3D, { \
    /*.x=*/0 WGPU_COMMA \
    /*.y=*/0 WGPU_COMMA \
    /*.z=*/0 WGPU_COMMA \
})

typedef struct WGPUPipelineLayoutDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    size_t bindGroupLayoutCount;
    WGPUBindGroupLayout const * bindGroupLayouts;
} WGPUPipelineLayoutDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_PIPELINE_LAYOUT_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUPipelineLayoutDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.bindGroupLayoutCount=*/{} WGPU_COMMA \
    /*.bindGroupLayouts=*/{} WGPU_COMMA \
})

typedef struct WGPUPipelineLayoutStorageAttachment {
    WGPUChainedStruct const * nextInChain;
    uint64_t offset;
    WGPUTextureFormat format;
} WGPUPipelineLayoutStorageAttachment WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_PIPELINE_LAYOUT_STORAGE_ATTACHMENT_INIT WGPU_MAKE_INIT_STRUCT(WGPUPipelineLayoutStorageAttachment, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.offset=*/0 WGPU_COMMA \
    /*.format=*/{} WGPU_COMMA \
})

typedef struct WGPUPopErrorScopeCallbackInfo {
    WGPUChainedStruct const * nextInChain;
    WGPUCallbackMode mode;
    WGPUPopErrorScopeCallback callback;
    WGPUErrorCallback oldCallback;
    void * userdata;
} WGPUPopErrorScopeCallbackInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_POP_ERROR_SCOPE_CALLBACK_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUPopErrorScopeCallbackInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.mode=*/WGPUCallbackMode_WaitAnyOnly WGPU_COMMA \
    /*.callback=*/{} WGPU_COMMA \
    /*.oldCallback=*/{} WGPU_COMMA \
    /*.userdata=*/nullptr WGPU_COMMA \
})

// Can be chained in WGPUPrimitiveState
typedef struct WGPUPrimitiveDepthClipControl {
    WGPUChainedStruct chain;
    WGPUBool unclippedDepth;
} WGPUPrimitiveDepthClipControl WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_PRIMITIVE_DEPTH_CLIP_CONTROL_INIT WGPU_MAKE_INIT_STRUCT(WGPUPrimitiveDepthClipControl, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.unclippedDepth=*/false WGPU_COMMA \
})

typedef struct WGPUPrimitiveState {
    WGPUChainedStruct const * nextInChain;
    WGPUPrimitiveTopology topology;
    WGPUIndexFormat stripIndexFormat;
    WGPUFrontFace frontFace;
    WGPUCullMode cullMode;
} WGPUPrimitiveState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_PRIMITIVE_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUPrimitiveState, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.topology=*/WGPUPrimitiveTopology_TriangleList WGPU_COMMA \
    /*.stripIndexFormat=*/WGPUIndexFormat_Undefined WGPU_COMMA \
    /*.frontFace=*/WGPUFrontFace_CCW WGPU_COMMA \
    /*.cullMode=*/WGPUCullMode_None WGPU_COMMA \
})

typedef struct WGPUQuerySetDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    WGPUQueryType type;
    uint32_t count;
} WGPUQuerySetDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_QUERY_SET_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUQuerySetDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.type=*/{} WGPU_COMMA \
    /*.count=*/{} WGPU_COMMA \
})

typedef struct WGPUQueueDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
} WGPUQueueDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_QUEUE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUQueueDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
})

typedef struct WGPUQueueWorkDoneCallbackInfo {
    WGPUChainedStruct const * nextInChain;
    WGPUCallbackMode mode;
    WGPUQueueWorkDoneCallback callback;
    void * userdata;
} WGPUQueueWorkDoneCallbackInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_QUEUE_WORK_DONE_CALLBACK_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUQueueWorkDoneCallbackInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.mode=*/{} WGPU_COMMA \
    /*.callback=*/{} WGPU_COMMA \
    /*.userdata=*/{} WGPU_COMMA \
})

typedef struct WGPURenderBundleDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
} WGPURenderBundleDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_RENDER_BUNDLE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPURenderBundleDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
})

typedef struct WGPURenderBundleEncoderDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    size_t colorFormatCount;
    WGPUTextureFormat const * colorFormats;
    WGPUTextureFormat depthStencilFormat;
    uint32_t sampleCount;
    WGPUBool depthReadOnly;
    WGPUBool stencilReadOnly;
} WGPURenderBundleEncoderDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_RENDER_BUNDLE_ENCODER_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPURenderBundleEncoderDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.colorFormatCount=*/{} WGPU_COMMA \
    /*.colorFormats=*/{} WGPU_COMMA \
    /*.depthStencilFormat=*/WGPUTextureFormat_Undefined WGPU_COMMA \
    /*.sampleCount=*/1 WGPU_COMMA \
    /*.depthReadOnly=*/false WGPU_COMMA \
    /*.stencilReadOnly=*/false WGPU_COMMA \
})

typedef struct WGPURenderPassDepthStencilAttachment {
    WGPUTextureView view;
    WGPULoadOp depthLoadOp;
    WGPUStoreOp depthStoreOp;
    float depthClearValue;
    WGPUBool depthReadOnly;
    WGPULoadOp stencilLoadOp;
    WGPUStoreOp stencilStoreOp;
    uint32_t stencilClearValue;
    WGPUBool stencilReadOnly;
} WGPURenderPassDepthStencilAttachment WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_RENDER_PASS_DEPTH_STENCIL_ATTACHMENT_INIT WGPU_MAKE_INIT_STRUCT(WGPURenderPassDepthStencilAttachment, { \
    /*.view=*/{} WGPU_COMMA \
    /*.depthLoadOp=*/WGPULoadOp_Undefined WGPU_COMMA \
    /*.depthStoreOp=*/WGPUStoreOp_Undefined WGPU_COMMA \
    /*.depthClearValue=*/NAN WGPU_COMMA \
    /*.depthReadOnly=*/false WGPU_COMMA \
    /*.stencilLoadOp=*/WGPULoadOp_Undefined WGPU_COMMA \
    /*.stencilStoreOp=*/WGPUStoreOp_Undefined WGPU_COMMA \
    /*.stencilClearValue=*/0 WGPU_COMMA \
    /*.stencilReadOnly=*/false WGPU_COMMA \
})

// Can be chained in WGPURenderPassDescriptor
typedef struct WGPURenderPassDescriptorMaxDrawCount {
    WGPUChainedStruct chain;
    uint64_t maxDrawCount;
} WGPURenderPassDescriptorMaxDrawCount WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_RENDER_PASS_DESCRIPTOR_MAX_DRAW_COUNT_INIT WGPU_MAKE_INIT_STRUCT(WGPURenderPassDescriptorMaxDrawCount, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.maxDrawCount=*/50000000 WGPU_COMMA \
})

typedef struct WGPURenderPassTimestampWrites {
    WGPUQuerySet querySet;
    uint32_t beginningOfPassWriteIndex;
    uint32_t endOfPassWriteIndex;
} WGPURenderPassTimestampWrites WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_RENDER_PASS_TIMESTAMP_WRITES_INIT WGPU_MAKE_INIT_STRUCT(WGPURenderPassTimestampWrites, { \
    /*.querySet=*/{} WGPU_COMMA \
    /*.beginningOfPassWriteIndex=*/WGPU_QUERY_SET_INDEX_UNDEFINED WGPU_COMMA \
    /*.endOfPassWriteIndex=*/WGPU_QUERY_SET_INDEX_UNDEFINED WGPU_COMMA \
})

typedef struct WGPURequestAdapterCallbackInfo {
    WGPUChainedStruct const * nextInChain;
    WGPUCallbackMode mode;
    WGPURequestAdapterCallback callback;
    void * userdata;
} WGPURequestAdapterCallbackInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_REQUEST_ADAPTER_CALLBACK_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPURequestAdapterCallbackInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.mode=*/{} WGPU_COMMA \
    /*.callback=*/{} WGPU_COMMA \
    /*.userdata=*/{} WGPU_COMMA \
})

typedef struct WGPURequestAdapterOptions {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE WGPUSurface compatibleSurface;
    WGPUPowerPreference powerPreference;
    WGPUBackendType backendType;
    WGPUBool forceFallbackAdapter;
    WGPUBool compatibilityMode;
} WGPURequestAdapterOptions WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_REQUEST_ADAPTER_OPTIONS_INIT WGPU_MAKE_INIT_STRUCT(WGPURequestAdapterOptions, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.compatibleSurface=*/nullptr WGPU_COMMA \
    /*.powerPreference=*/WGPUPowerPreference_Undefined WGPU_COMMA \
    /*.backendType=*/WGPUBackendType_Undefined WGPU_COMMA \
    /*.forceFallbackAdapter=*/false WGPU_COMMA \
    /*.compatibilityMode=*/false WGPU_COMMA \
})

typedef struct WGPURequestDeviceCallbackInfo {
    WGPUChainedStruct const * nextInChain;
    WGPUCallbackMode mode;
    WGPURequestDeviceCallback callback;
    void * userdata;
} WGPURequestDeviceCallbackInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_REQUEST_DEVICE_CALLBACK_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPURequestDeviceCallbackInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.mode=*/{} WGPU_COMMA \
    /*.callback=*/{} WGPU_COMMA \
    /*.userdata=*/{} WGPU_COMMA \
})

typedef struct WGPUSamplerBindingLayout {
    WGPUChainedStruct const * nextInChain;
    WGPUSamplerBindingType type;
} WGPUSamplerBindingLayout WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SAMPLER_BINDING_LAYOUT_INIT WGPU_MAKE_INIT_STRUCT(WGPUSamplerBindingLayout, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.type=*/WGPUSamplerBindingType_Undefined WGPU_COMMA \
})

typedef struct WGPUSamplerDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    WGPUAddressMode addressModeU;
    WGPUAddressMode addressModeV;
    WGPUAddressMode addressModeW;
    WGPUFilterMode magFilter;
    WGPUFilterMode minFilter;
    WGPUMipmapFilterMode mipmapFilter;
    float lodMinClamp;
    float lodMaxClamp;
    WGPUCompareFunction compare;
    uint16_t maxAnisotropy;
} WGPUSamplerDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SAMPLER_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSamplerDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.addressModeU=*/WGPUAddressMode_ClampToEdge WGPU_COMMA \
    /*.addressModeV=*/WGPUAddressMode_ClampToEdge WGPU_COMMA \
    /*.addressModeW=*/WGPUAddressMode_ClampToEdge WGPU_COMMA \
    /*.magFilter=*/WGPUFilterMode_Nearest WGPU_COMMA \
    /*.minFilter=*/WGPUFilterMode_Nearest WGPU_COMMA \
    /*.mipmapFilter=*/WGPUMipmapFilterMode_Nearest WGPU_COMMA \
    /*.lodMinClamp=*/0.0f WGPU_COMMA \
    /*.lodMaxClamp=*/32.0f WGPU_COMMA \
    /*.compare=*/WGPUCompareFunction_Undefined WGPU_COMMA \
    /*.maxAnisotropy=*/1 WGPU_COMMA \
})

// Can be chained in WGPUShaderModuleDescriptor
typedef struct WGPUShaderModuleSPIRVDescriptor {
    WGPUChainedStruct chain;
    uint32_t codeSize;
    uint32_t const * code;
} WGPUShaderModuleSPIRVDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHADER_MODULE_SPIRV_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUShaderModuleSPIRVDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.codeSize=*/{} WGPU_COMMA \
    /*.code=*/{} WGPU_COMMA \
})

// Can be chained in WGPUShaderModuleDescriptor
typedef struct WGPUShaderModuleWGSLDescriptor {
    WGPUChainedStruct chain;
    char const * code;
} WGPUShaderModuleWGSLDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHADER_MODULE_WGSL_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUShaderModuleWGSLDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.code=*/{} WGPU_COMMA \
})

// Can be chained in WGPUShaderModuleDescriptor
typedef struct WGPUShaderModuleCompilationOptions {
    WGPUChainedStruct chain;
    WGPUBool strictMath;
} WGPUShaderModuleCompilationOptions WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHADER_MODULE_COMPILATION_OPTIONS_INIT WGPU_MAKE_INIT_STRUCT(WGPUShaderModuleCompilationOptions, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.strictMath=*/{} WGPU_COMMA \
})

typedef struct WGPUShaderModuleDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
} WGPUShaderModuleDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHADER_MODULE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUShaderModuleDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
})

typedef struct WGPUSharedBufferMemoryBeginAccessDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPUBool initialized;
    size_t fenceCount;
    WGPUSharedFence const * fences;
    uint64_t const * signaledValues;
} WGPUSharedBufferMemoryBeginAccessDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_BUFFER_MEMORY_BEGIN_ACCESS_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedBufferMemoryBeginAccessDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.initialized=*/{} WGPU_COMMA \
    /*.fenceCount=*/0 WGPU_COMMA \
    /*.fences=*/{} WGPU_COMMA \
    /*.signaledValues=*/{} WGPU_COMMA \
})

typedef struct WGPUSharedBufferMemoryDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
} WGPUSharedBufferMemoryDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_BUFFER_MEMORY_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedBufferMemoryDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
})

typedef struct WGPUSharedBufferMemoryEndAccessState {
    WGPUChainedStructOut * nextInChain;
    WGPUBool initialized;
    size_t fenceCount;
    WGPUSharedFence const * fences;
    uint64_t const * signaledValues;
} WGPUSharedBufferMemoryEndAccessState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_BUFFER_MEMORY_END_ACCESS_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedBufferMemoryEndAccessState, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.initialized=*/{} WGPU_COMMA \
    /*.fenceCount=*/0 WGPU_COMMA \
    /*.fences=*/{} WGPU_COMMA \
    /*.signaledValues=*/{} WGPU_COMMA \
})

typedef struct WGPUSharedBufferMemoryProperties {
    WGPUChainedStructOut * nextInChain;
    WGPUBufferUsageFlags usage;
    uint64_t size;
} WGPUSharedBufferMemoryProperties WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_BUFFER_MEMORY_PROPERTIES_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedBufferMemoryProperties, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.usage=*/{} WGPU_COMMA \
    /*.size=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedFenceDescriptor
typedef struct WGPUSharedFenceDXGISharedHandleDescriptor {
    WGPUChainedStruct chain;
    void * handle;
} WGPUSharedFenceDXGISharedHandleDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_DXGI_SHARED_HANDLE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceDXGISharedHandleDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.handle=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedFenceExportInfo
typedef struct WGPUSharedFenceDXGISharedHandleExportInfo {
    WGPUChainedStructOut chain;
    void * handle;
} WGPUSharedFenceDXGISharedHandleExportInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_DXGI_SHARED_HANDLE_EXPORT_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceDXGISharedHandleExportInfo, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.handle=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedFenceDescriptor
typedef struct WGPUSharedFenceMTLSharedEventDescriptor {
    WGPUChainedStruct chain;
    void * sharedEvent;
} WGPUSharedFenceMTLSharedEventDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_MTL_SHARED_EVENT_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceMTLSharedEventDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.sharedEvent=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedFenceExportInfo
typedef struct WGPUSharedFenceMTLSharedEventExportInfo {
    WGPUChainedStructOut chain;
    void * sharedEvent;
} WGPUSharedFenceMTLSharedEventExportInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_MTL_SHARED_EVENT_EXPORT_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceMTLSharedEventExportInfo, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.sharedEvent=*/{} WGPU_COMMA \
})

typedef struct WGPUSharedFenceDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
} WGPUSharedFenceDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
})

typedef struct WGPUSharedFenceExportInfo {
    WGPUChainedStructOut * nextInChain;
    WGPUSharedFenceType type;
} WGPUSharedFenceExportInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_EXPORT_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceExportInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.type=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedFenceDescriptor
typedef struct WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor {
    WGPUChainedStruct chain;
    int handle;
} WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_VK_SEMAPHORE_OPAQUE_FD_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.handle=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedFenceExportInfo
typedef struct WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo {
    WGPUChainedStructOut chain;
    int handle;
} WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_VK_SEMAPHORE_OPAQUE_FD_EXPORT_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.handle=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedFenceDescriptor
typedef struct WGPUSharedFenceVkSemaphoreSyncFDDescriptor {
    WGPUChainedStruct chain;
    int handle;
} WGPUSharedFenceVkSemaphoreSyncFDDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_VK_SEMAPHORE_SYNC_FD_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceVkSemaphoreSyncFDDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.handle=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedFenceExportInfo
typedef struct WGPUSharedFenceVkSemaphoreSyncFDExportInfo {
    WGPUChainedStructOut chain;
    int handle;
} WGPUSharedFenceVkSemaphoreSyncFDExportInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_VK_SEMAPHORE_SYNC_FD_EXPORT_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceVkSemaphoreSyncFDExportInfo, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.handle=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedFenceDescriptor
typedef struct WGPUSharedFenceVkSemaphoreZirconHandleDescriptor {
    WGPUChainedStruct chain;
    uint32_t handle;
} WGPUSharedFenceVkSemaphoreZirconHandleDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_VK_SEMAPHORE_ZIRCON_HANDLE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceVkSemaphoreZirconHandleDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.handle=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedFenceExportInfo
typedef struct WGPUSharedFenceVkSemaphoreZirconHandleExportInfo {
    WGPUChainedStructOut chain;
    uint32_t handle;
} WGPUSharedFenceVkSemaphoreZirconHandleExportInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_FENCE_VK_SEMAPHORE_ZIRCON_HANDLE_EXPORT_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedFenceVkSemaphoreZirconHandleExportInfo, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.handle=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryBeginAccessDescriptor
typedef struct WGPUSharedTextureMemoryD3DSwapchainBeginState {
    WGPUChainedStruct chain;
    WGPUBool isSwapchain;
} WGPUSharedTextureMemoryD3DSwapchainBeginState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_D3D_SWAPCHAIN_BEGIN_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryD3DSwapchainBeginState, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.isSwapchain=*/false WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryDescriptor
typedef struct WGPUSharedTextureMemoryDXGISharedHandleDescriptor {
    WGPUChainedStruct chain;
    void * handle;
    WGPUBool useKeyedMutex;
} WGPUSharedTextureMemoryDXGISharedHandleDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_DXGI_SHARED_HANDLE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryDXGISharedHandleDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.handle=*/{} WGPU_COMMA \
    /*.useKeyedMutex=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryDescriptor
typedef struct WGPUSharedTextureMemoryEGLImageDescriptor {
    WGPUChainedStruct chain;
    void * image;
} WGPUSharedTextureMemoryEGLImageDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_EGL_IMAGE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryEGLImageDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.image=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryDescriptor
typedef struct WGPUSharedTextureMemoryIOSurfaceDescriptor {
    WGPUChainedStruct chain;
    void * ioSurface;
} WGPUSharedTextureMemoryIOSurfaceDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_IO_SURFACE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryIOSurfaceDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.ioSurface=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryDescriptor
typedef struct WGPUSharedTextureMemoryAHardwareBufferDescriptor {
    WGPUChainedStruct chain;
    void * handle;
    WGPUBool useExternalFormat;
} WGPUSharedTextureMemoryAHardwareBufferDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_A_HARDWARE_BUFFER_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryAHardwareBufferDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.handle=*/{} WGPU_COMMA \
    /*.useExternalFormat=*/{} WGPU_COMMA \
})

typedef struct WGPUSharedTextureMemoryBeginAccessDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPUBool concurrentRead;
    WGPUBool initialized;
    size_t fenceCount;
    WGPUSharedFence const * fences;
    uint64_t const * signaledValues;
} WGPUSharedTextureMemoryBeginAccessDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_BEGIN_ACCESS_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryBeginAccessDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.concurrentRead=*/{} WGPU_COMMA \
    /*.initialized=*/{} WGPU_COMMA \
    /*.fenceCount=*/{} WGPU_COMMA \
    /*.fences=*/{} WGPU_COMMA \
    /*.signaledValues=*/{} WGPU_COMMA \
})

typedef struct WGPUSharedTextureMemoryDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
} WGPUSharedTextureMemoryDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
})

typedef struct WGPUSharedTextureMemoryDmaBufPlane {
    int fd;
    uint64_t offset;
    uint32_t stride;
} WGPUSharedTextureMemoryDmaBufPlane WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_DMA_BUF_PLANE_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryDmaBufPlane, { \
    /*.fd=*/{} WGPU_COMMA \
    /*.offset=*/{} WGPU_COMMA \
    /*.stride=*/{} WGPU_COMMA \
})

typedef struct WGPUSharedTextureMemoryEndAccessState {
    WGPUChainedStructOut * nextInChain;
    WGPUBool initialized;
    size_t fenceCount;
    WGPUSharedFence const * fences;
    uint64_t const * signaledValues;
} WGPUSharedTextureMemoryEndAccessState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_END_ACCESS_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryEndAccessState, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.initialized=*/{} WGPU_COMMA \
    /*.fenceCount=*/{} WGPU_COMMA \
    /*.fences=*/{} WGPU_COMMA \
    /*.signaledValues=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryDescriptor
typedef struct WGPUSharedTextureMemoryOpaqueFDDescriptor {
    WGPUChainedStruct chain;
    void const * vkImageCreateInfo;
    int memoryFD;
    uint32_t memoryTypeIndex;
    uint64_t allocationSize;
    WGPUBool dedicatedAllocation;
} WGPUSharedTextureMemoryOpaqueFDDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_OPAQUE_FD_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryOpaqueFDDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.vkImageCreateInfo=*/{} WGPU_COMMA \
    /*.memoryFD=*/{} WGPU_COMMA \
    /*.memoryTypeIndex=*/{} WGPU_COMMA \
    /*.allocationSize=*/{} WGPU_COMMA \
    /*.dedicatedAllocation=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryDescriptor
typedef struct WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor {
    WGPUChainedStruct chain;
    WGPUBool dedicatedAllocation;
} WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_VK_DEDICATED_ALLOCATION_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.dedicatedAllocation=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryBeginAccessDescriptor
typedef struct WGPUSharedTextureMemoryVkImageLayoutBeginState {
    WGPUChainedStruct chain;
    int32_t oldLayout;
    int32_t newLayout;
} WGPUSharedTextureMemoryVkImageLayoutBeginState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_VK_IMAGE_LAYOUT_BEGIN_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryVkImageLayoutBeginState, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.oldLayout=*/{} WGPU_COMMA \
    /*.newLayout=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryEndAccessState
typedef struct WGPUSharedTextureMemoryVkImageLayoutEndState {
    WGPUChainedStructOut chain;
    int32_t oldLayout;
    int32_t newLayout;
} WGPUSharedTextureMemoryVkImageLayoutEndState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_VK_IMAGE_LAYOUT_END_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryVkImageLayoutEndState, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.oldLayout=*/{} WGPU_COMMA \
    /*.newLayout=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryDescriptor
typedef struct WGPUSharedTextureMemoryZirconHandleDescriptor {
    WGPUChainedStruct chain;
    uint32_t memoryFD;
    uint64_t allocationSize;
} WGPUSharedTextureMemoryZirconHandleDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_ZIRCON_HANDLE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryZirconHandleDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.memoryFD=*/{} WGPU_COMMA \
    /*.allocationSize=*/{} WGPU_COMMA \
})

// Can be chained in WGPUBindGroupLayoutEntry
typedef struct WGPUStaticSamplerBindingLayout {
    WGPUChainedStruct chain;
    WGPUSampler sampler;
} WGPUStaticSamplerBindingLayout WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_STATIC_SAMPLER_BINDING_LAYOUT_INIT WGPU_MAKE_INIT_STRUCT(WGPUStaticSamplerBindingLayout, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.sampler=*/{} WGPU_COMMA \
})

typedef struct WGPUStencilFaceState {
    WGPUCompareFunction compare;
    WGPUStencilOperation failOp;
    WGPUStencilOperation depthFailOp;
    WGPUStencilOperation passOp;
} WGPUStencilFaceState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_STENCIL_FACE_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUStencilFaceState, { \
    /*.compare=*/WGPUCompareFunction_Always WGPU_COMMA \
    /*.failOp=*/WGPUStencilOperation_Keep WGPU_COMMA \
    /*.depthFailOp=*/WGPUStencilOperation_Keep WGPU_COMMA \
    /*.passOp=*/WGPUStencilOperation_Keep WGPU_COMMA \
})

typedef struct WGPUStorageTextureBindingLayout {
    WGPUChainedStruct const * nextInChain;
    WGPUStorageTextureAccess access;
    WGPUTextureFormat format;
    WGPUTextureViewDimension viewDimension;
} WGPUStorageTextureBindingLayout WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_STORAGE_TEXTURE_BINDING_LAYOUT_INIT WGPU_MAKE_INIT_STRUCT(WGPUStorageTextureBindingLayout, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.access=*/WGPUStorageTextureAccess_Undefined WGPU_COMMA \
    /*.format=*/WGPUTextureFormat_Undefined WGPU_COMMA \
    /*.viewDimension=*/WGPUTextureViewDimension_2D WGPU_COMMA \
})

typedef struct WGPUSurfaceCapabilities {
    WGPUChainedStructOut * nextInChain;
    WGPUTextureUsageFlags usages;
    size_t formatCount;
    WGPUTextureFormat const * formats;
    size_t presentModeCount;
    WGPUPresentMode const * presentModes;
    size_t alphaModeCount;
    WGPUCompositeAlphaMode const * alphaModes;
} WGPUSurfaceCapabilities WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_CAPABILITIES_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceCapabilities, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.usages=*/{} WGPU_COMMA \
    /*.formatCount=*/{} WGPU_COMMA \
    /*.formats=*/{} WGPU_COMMA \
    /*.presentModeCount=*/{} WGPU_COMMA \
    /*.presentModes=*/{} WGPU_COMMA \
    /*.alphaModeCount=*/{} WGPU_COMMA \
    /*.alphaModes=*/{} WGPU_COMMA \
})

typedef struct WGPUSurfaceConfiguration {
    WGPUChainedStruct const * nextInChain;
    WGPUDevice device;
    WGPUTextureFormat format;
    WGPUTextureUsageFlags usage;
    size_t viewFormatCount;
    WGPUTextureFormat const * viewFormats;
    WGPUCompositeAlphaMode alphaMode;
    uint32_t width;
    uint32_t height;
    WGPUPresentMode presentMode;
} WGPUSurfaceConfiguration WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_CONFIGURATION_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceConfiguration, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.device=*/{} WGPU_COMMA \
    /*.format=*/{} WGPU_COMMA \
    /*.usage=*/WGPUTextureUsage_RenderAttachment WGPU_COMMA \
    /*.viewFormatCount=*/0 WGPU_COMMA \
    /*.viewFormats=*/{} WGPU_COMMA \
    /*.alphaMode=*/WGPUCompositeAlphaMode_Auto WGPU_COMMA \
    /*.width=*/{} WGPU_COMMA \
    /*.height=*/{} WGPU_COMMA \
    /*.presentMode=*/WGPUPresentMode_Fifo WGPU_COMMA \
})

typedef struct WGPUSurfaceDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
} WGPUSurfaceDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
})

// Can be chained in WGPUSurfaceDescriptor
typedef struct WGPUSurfaceDescriptorFromAndroidNativeWindow {
    WGPUChainedStruct chain;
    void * window;
} WGPUSurfaceDescriptorFromAndroidNativeWindow WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_DESCRIPTOR_FROM_ANDROID_NATIVE_WINDOW_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceDescriptorFromAndroidNativeWindow, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.window=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSurfaceDescriptor
typedef struct WGPUSurfaceDescriptorFromCanvasHTMLSelector {
    WGPUChainedStruct chain;
    char const * selector;
} WGPUSurfaceDescriptorFromCanvasHTMLSelector WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_DESCRIPTOR_FROM_CANVAS_HTML_SELECTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceDescriptorFromCanvasHTMLSelector, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.selector=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSurfaceDescriptor
typedef struct WGPUSurfaceDescriptorFromMetalLayer {
    WGPUChainedStruct chain;
    void * layer;
} WGPUSurfaceDescriptorFromMetalLayer WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_DESCRIPTOR_FROM_METAL_LAYER_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceDescriptorFromMetalLayer, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.layer=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSurfaceDescriptor
typedef struct WGPUSurfaceDescriptorFromWaylandSurface {
    WGPUChainedStruct chain;
    void * display;
    void * surface;
} WGPUSurfaceDescriptorFromWaylandSurface WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_DESCRIPTOR_FROM_WAYLAND_SURFACE_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceDescriptorFromWaylandSurface, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.display=*/{} WGPU_COMMA \
    /*.surface=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSurfaceDescriptor
typedef struct WGPUSurfaceDescriptorFromWindowsHWND {
    WGPUChainedStruct chain;
    void * hinstance;
    void * hwnd;
} WGPUSurfaceDescriptorFromWindowsHWND WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_DESCRIPTOR_FROM_WINDOWS_HWND_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceDescriptorFromWindowsHWND, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.hinstance=*/{} WGPU_COMMA \
    /*.hwnd=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSurfaceDescriptor
typedef struct WGPUSurfaceDescriptorFromWindowsCoreWindow {
    WGPUChainedStruct chain;
    void * coreWindow;
} WGPUSurfaceDescriptorFromWindowsCoreWindow WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_DESCRIPTOR_FROM_WINDOWS_CORE_WINDOW_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceDescriptorFromWindowsCoreWindow, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.coreWindow=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSurfaceDescriptor
typedef struct WGPUSurfaceDescriptorFromWindowsSwapChainPanel {
    WGPUChainedStruct chain;
    void * swapChainPanel;
} WGPUSurfaceDescriptorFromWindowsSwapChainPanel WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_DESCRIPTOR_FROM_WINDOWS_SWAP_CHAIN_PANEL_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceDescriptorFromWindowsSwapChainPanel, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.swapChainPanel=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSurfaceDescriptor
typedef struct WGPUSurfaceDescriptorFromXlibWindow {
    WGPUChainedStruct chain;
    void * display;
    uint64_t window;
} WGPUSurfaceDescriptorFromXlibWindow WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_DESCRIPTOR_FROM_XLIB_WINDOW_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceDescriptorFromXlibWindow, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.display=*/{} WGPU_COMMA \
    /*.window=*/{} WGPU_COMMA \
})

typedef struct WGPUSurfaceTexture {
    WGPUTexture texture;
    WGPUBool suboptimal;
    WGPUSurfaceGetCurrentTextureStatus status;
} WGPUSurfaceTexture WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SURFACE_TEXTURE_INIT WGPU_MAKE_INIT_STRUCT(WGPUSurfaceTexture, { \
    /*.texture=*/{} WGPU_COMMA \
    /*.suboptimal=*/{} WGPU_COMMA \
    /*.status=*/{} WGPU_COMMA \
})

typedef struct WGPUSwapChainDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    WGPUTextureUsageFlags usage;
    WGPUTextureFormat format;
    uint32_t width;
    uint32_t height;
    WGPUPresentMode presentMode;
} WGPUSwapChainDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SWAP_CHAIN_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSwapChainDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.usage=*/{} WGPU_COMMA \
    /*.format=*/{} WGPU_COMMA \
    /*.width=*/{} WGPU_COMMA \
    /*.height=*/{} WGPU_COMMA \
    /*.presentMode=*/{} WGPU_COMMA \
})

typedef struct WGPUTextureBindingLayout {
    WGPUChainedStruct const * nextInChain;
    WGPUTextureSampleType sampleType;
    WGPUTextureViewDimension viewDimension;
    WGPUBool multisampled;
} WGPUTextureBindingLayout WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_TEXTURE_BINDING_LAYOUT_INIT WGPU_MAKE_INIT_STRUCT(WGPUTextureBindingLayout, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.sampleType=*/WGPUTextureSampleType_Undefined WGPU_COMMA \
    /*.viewDimension=*/WGPUTextureViewDimension_2D WGPU_COMMA \
    /*.multisampled=*/false WGPU_COMMA \
})

// Can be chained in WGPUTextureDescriptor
typedef struct WGPUTextureBindingViewDimensionDescriptor {
    WGPUChainedStruct chain;
    WGPUTextureViewDimension textureBindingViewDimension;
} WGPUTextureBindingViewDimensionDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_TEXTURE_BINDING_VIEW_DIMENSION_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUTextureBindingViewDimensionDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.textureBindingViewDimension=*/WGPUTextureViewDimension_Undefined WGPU_COMMA \
})

typedef struct WGPUTextureDataLayout {
    WGPUChainedStruct const * nextInChain;
    uint64_t offset;
    uint32_t bytesPerRow;
    uint32_t rowsPerImage;
} WGPUTextureDataLayout WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_TEXTURE_DATA_LAYOUT_INIT WGPU_MAKE_INIT_STRUCT(WGPUTextureDataLayout, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.offset=*/0 WGPU_COMMA \
    /*.bytesPerRow=*/WGPU_COPY_STRIDE_UNDEFINED WGPU_COMMA \
    /*.rowsPerImage=*/WGPU_COPY_STRIDE_UNDEFINED WGPU_COMMA \
})

typedef struct WGPUTextureViewDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    WGPUTextureFormat format;
    WGPUTextureViewDimension dimension;
    uint32_t baseMipLevel;
    uint32_t mipLevelCount;
    uint32_t baseArrayLayer;
    uint32_t arrayLayerCount;
    WGPUTextureAspect aspect;
} WGPUTextureViewDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_TEXTURE_VIEW_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUTextureViewDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.format=*/WGPUTextureFormat_Undefined WGPU_COMMA \
    /*.dimension=*/WGPUTextureViewDimension_Undefined WGPU_COMMA \
    /*.baseMipLevel=*/0 WGPU_COMMA \
    /*.mipLevelCount=*/WGPU_MIP_LEVEL_COUNT_UNDEFINED WGPU_COMMA \
    /*.baseArrayLayer=*/0 WGPU_COMMA \
    /*.arrayLayerCount=*/WGPU_ARRAY_LAYER_COUNT_UNDEFINED WGPU_COMMA \
    /*.aspect=*/WGPUTextureAspect_All WGPU_COMMA \
})

typedef struct WGPUUncapturedErrorCallbackInfo {
    WGPUChainedStruct const * nextInChain;
    WGPUErrorCallback callback;
    void * userdata;
} WGPUUncapturedErrorCallbackInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_UNCAPTURED_ERROR_CALLBACK_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUUncapturedErrorCallbackInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.callback=*/nullptr WGPU_COMMA \
    /*.userdata=*/nullptr WGPU_COMMA \
})

typedef struct WGPUVertexAttribute {
    WGPUVertexFormat format;
    uint64_t offset;
    uint32_t shaderLocation;
} WGPUVertexAttribute WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_VERTEX_ATTRIBUTE_INIT WGPU_MAKE_INIT_STRUCT(WGPUVertexAttribute, { \
    /*.format=*/{} WGPU_COMMA \
    /*.offset=*/{} WGPU_COMMA \
    /*.shaderLocation=*/{} WGPU_COMMA \
})

// Can be chained in WGPUSamplerDescriptor
// Can be chained in WGPUTextureViewDescriptor
typedef struct WGPUYCbCrVkDescriptor {
    WGPUChainedStruct chain;
    uint32_t vkFormat;
    uint32_t vkYCbCrModel;
    uint32_t vkYCbCrRange;
    uint32_t vkComponentSwizzleRed;
    uint32_t vkComponentSwizzleGreen;
    uint32_t vkComponentSwizzleBlue;
    uint32_t vkComponentSwizzleAlpha;
    uint32_t vkXChromaOffset;
    uint32_t vkYChromaOffset;
    WGPUFilterMode vkChromaFilter;
    WGPUBool forceExplicitReconstruction;
    uint64_t externalFormat;
} WGPUYCbCrVkDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_Y_CB_CR_VK_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUYCbCrVkDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.vkFormat=*/0 WGPU_COMMA \
    /*.vkYCbCrModel=*/0 WGPU_COMMA \
    /*.vkYCbCrRange=*/0 WGPU_COMMA \
    /*.vkComponentSwizzleRed=*/0 WGPU_COMMA \
    /*.vkComponentSwizzleGreen=*/0 WGPU_COMMA \
    /*.vkComponentSwizzleBlue=*/0 WGPU_COMMA \
    /*.vkComponentSwizzleAlpha=*/0 WGPU_COMMA \
    /*.vkXChromaOffset=*/0 WGPU_COMMA \
    /*.vkYChromaOffset=*/0 WGPU_COMMA \
    /*.vkChromaFilter=*/WGPUFilterMode_Nearest WGPU_COMMA \
    /*.forceExplicitReconstruction=*/false WGPU_COMMA \
    /*.externalFormat=*/0 WGPU_COMMA \
})

typedef struct WGPUAHardwareBufferProperties {
    WGPUYCbCrVkDescriptor yCbCrInfo;
} WGPUAHardwareBufferProperties WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_A_HARDWARE_BUFFER_PROPERTIES_INIT WGPU_MAKE_INIT_STRUCT(WGPUAHardwareBufferProperties, { \
    /*.yCbCrInfo=*/WGPU_Y_CB_CR_VK_DESCRIPTOR_INIT WGPU_COMMA \
})

// Can be chained in WGPUAdapterInfo
// Can be chained in WGPUAdapterProperties
typedef struct WGPUAdapterPropertiesMemoryHeaps {
    WGPUChainedStructOut chain;
    size_t heapCount;
    WGPUMemoryHeapInfo const * heapInfo;
} WGPUAdapterPropertiesMemoryHeaps WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_ADAPTER_PROPERTIES_MEMORY_HEAPS_INIT WGPU_MAKE_INIT_STRUCT(WGPUAdapterPropertiesMemoryHeaps, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.heapCount=*/{} WGPU_COMMA \
    /*.heapInfo=*/{} WGPU_COMMA \
})

typedef struct WGPUBindGroupDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    WGPUBindGroupLayout layout;
    size_t entryCount;
    WGPUBindGroupEntry const * entries;
} WGPUBindGroupDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_BIND_GROUP_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUBindGroupDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.layout=*/{} WGPU_COMMA \
    /*.entryCount=*/{} WGPU_COMMA \
    /*.entries=*/{} WGPU_COMMA \
})

typedef struct WGPUBindGroupLayoutEntry {
    WGPUChainedStruct const * nextInChain;
    uint32_t binding;
    WGPUShaderStageFlags visibility;
    WGPUBufferBindingLayout buffer;
    WGPUSamplerBindingLayout sampler;
    WGPUTextureBindingLayout texture;
    WGPUStorageTextureBindingLayout storageTexture;
} WGPUBindGroupLayoutEntry WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_BIND_GROUP_LAYOUT_ENTRY_INIT WGPU_MAKE_INIT_STRUCT(WGPUBindGroupLayoutEntry, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.binding=*/{} WGPU_COMMA \
    /*.visibility=*/{} WGPU_COMMA \
    /*.buffer=*/WGPU_BUFFER_BINDING_LAYOUT_INIT WGPU_COMMA \
    /*.sampler=*/WGPU_SAMPLER_BINDING_LAYOUT_INIT WGPU_COMMA \
    /*.texture=*/WGPU_TEXTURE_BINDING_LAYOUT_INIT WGPU_COMMA \
    /*.storageTexture=*/WGPU_STORAGE_TEXTURE_BINDING_LAYOUT_INIT WGPU_COMMA \
})

typedef struct WGPUBlendState {
    WGPUBlendComponent color;
    WGPUBlendComponent alpha;
} WGPUBlendState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_BLEND_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUBlendState, { \
    /*.color=*/WGPU_BLEND_COMPONENT_INIT WGPU_COMMA \
    /*.alpha=*/WGPU_BLEND_COMPONENT_INIT WGPU_COMMA \
})

typedef struct WGPUCompilationInfo {
    WGPUChainedStruct const * nextInChain;
    size_t messageCount;
    WGPUCompilationMessage const * messages;
} WGPUCompilationInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COMPILATION_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUCompilationInfo, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.messageCount=*/{} WGPU_COMMA \
    /*.messages=*/{} WGPU_COMMA \
})

typedef struct WGPUComputePassDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    WGPU_NULLABLE WGPUComputePassTimestampWrites const * timestampWrites;
} WGPUComputePassDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COMPUTE_PASS_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUComputePassDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.timestampWrites=*/nullptr WGPU_COMMA \
})

typedef struct WGPUDepthStencilState {
    WGPUChainedStruct const * nextInChain;
    WGPUTextureFormat format;
    WGPUBool depthWriteEnabled;
    WGPUCompareFunction depthCompare;
    WGPUStencilFaceState stencilFront;
    WGPUStencilFaceState stencilBack;
    uint32_t stencilReadMask;
    uint32_t stencilWriteMask;
    int32_t depthBias;
    float depthBiasSlopeScale;
    float depthBiasClamp;
} WGPUDepthStencilState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DEPTH_STENCIL_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUDepthStencilState, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.format=*/{} WGPU_COMMA \
    /*.depthWriteEnabled=*/false WGPU_COMMA \
    /*.depthCompare=*/WGPUCompareFunction_Undefined WGPU_COMMA \
    /*.stencilFront=*/WGPU_STENCIL_FACE_STATE_INIT WGPU_COMMA \
    /*.stencilBack=*/WGPU_STENCIL_FACE_STATE_INIT WGPU_COMMA \
    /*.stencilReadMask=*/0xFFFFFFFF WGPU_COMMA \
    /*.stencilWriteMask=*/0xFFFFFFFF WGPU_COMMA \
    /*.depthBias=*/0 WGPU_COMMA \
    /*.depthBiasSlopeScale=*/0.0f WGPU_COMMA \
    /*.depthBiasClamp=*/0.0f WGPU_COMMA \
})

// Can be chained in WGPUFormatCapabilities
typedef struct WGPUDrmFormatCapabilities {
    WGPUChainedStructOut chain;
    size_t propertiesCount;
    WGPUDrmFormatProperties const * properties;
} WGPUDrmFormatCapabilities WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DRM_FORMAT_CAPABILITIES_INIT WGPU_MAKE_INIT_STRUCT(WGPUDrmFormatCapabilities, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.propertiesCount=*/{} WGPU_COMMA \
    /*.properties=*/{} WGPU_COMMA \
})

typedef struct WGPUExternalTextureDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    WGPUTextureView plane0;
    WGPU_NULLABLE WGPUTextureView plane1;
    WGPUOrigin2D visibleOrigin;
    WGPUExtent2D visibleSize;
    WGPUBool doYuvToRgbConversionOnly;
    WGPU_NULLABLE float const * yuvToRgbConversionMatrix;
    float const * srcTransferFunctionParameters;
    float const * dstTransferFunctionParameters;
    float const * gamutConversionMatrix;
    WGPUBool mirrored;
    WGPUExternalTextureRotation rotation;
} WGPUExternalTextureDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_EXTERNAL_TEXTURE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUExternalTextureDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.plane0=*/{} WGPU_COMMA \
    /*.plane1=*/nullptr WGPU_COMMA \
    /*.visibleOrigin=*/WGPU_ORIGIN_2D_INIT WGPU_COMMA \
    /*.visibleSize=*/WGPU_EXTENT_2D_INIT WGPU_COMMA \
    /*.doYuvToRgbConversionOnly=*/false WGPU_COMMA \
    /*.yuvToRgbConversionMatrix=*/nullptr WGPU_COMMA \
    /*.srcTransferFunctionParameters=*/{} WGPU_COMMA \
    /*.dstTransferFunctionParameters=*/{} WGPU_COMMA \
    /*.gamutConversionMatrix=*/{} WGPU_COMMA \
    /*.mirrored=*/false WGPU_COMMA \
    /*.rotation=*/WGPUExternalTextureRotation_Rotate0Degrees WGPU_COMMA \
})

typedef struct WGPUFutureWaitInfo {
    WGPUFuture future;
    WGPUBool completed;
} WGPUFutureWaitInfo WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_FUTURE_WAIT_INFO_INIT WGPU_MAKE_INIT_STRUCT(WGPUFutureWaitInfo, { \
    /*.future=*/WGPU_FUTURE_INIT WGPU_COMMA \
    /*.completed=*/false WGPU_COMMA \
})

typedef struct WGPUImageCopyBuffer {
    WGPUTextureDataLayout layout;
    WGPUBuffer buffer;
} WGPUImageCopyBuffer WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_IMAGE_COPY_BUFFER_INIT WGPU_MAKE_INIT_STRUCT(WGPUImageCopyBuffer, { \
    /*.layout=*/WGPU_TEXTURE_DATA_LAYOUT_INIT WGPU_COMMA \
    /*.buffer=*/{} WGPU_COMMA \
})

typedef struct WGPUImageCopyExternalTexture {
    WGPUChainedStruct const * nextInChain;
    WGPUExternalTexture externalTexture;
    WGPUOrigin3D origin;
    WGPUExtent2D naturalSize;
} WGPUImageCopyExternalTexture WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_IMAGE_COPY_EXTERNAL_TEXTURE_INIT WGPU_MAKE_INIT_STRUCT(WGPUImageCopyExternalTexture, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.externalTexture=*/{} WGPU_COMMA \
    /*.origin=*/WGPU_ORIGIN_3D_INIT WGPU_COMMA \
    /*.naturalSize=*/WGPU_EXTENT_2D_INIT WGPU_COMMA \
})

typedef struct WGPUImageCopyTexture {
    WGPUTexture texture;
    uint32_t mipLevel;
    WGPUOrigin3D origin;
    WGPUTextureAspect aspect;
} WGPUImageCopyTexture WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_IMAGE_COPY_TEXTURE_INIT WGPU_MAKE_INIT_STRUCT(WGPUImageCopyTexture, { \
    /*.texture=*/{} WGPU_COMMA \
    /*.mipLevel=*/0 WGPU_COMMA \
    /*.origin=*/WGPU_ORIGIN_3D_INIT WGPU_COMMA \
    /*.aspect=*/WGPUTextureAspect_All WGPU_COMMA \
})

typedef struct WGPUInstanceDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPUInstanceFeatures features;
} WGPUInstanceDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_INSTANCE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUInstanceDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.features=*/WGPU_INSTANCE_FEATURES_INIT WGPU_COMMA \
})

// Can be chained in WGPUPipelineLayoutDescriptor
typedef struct WGPUPipelineLayoutPixelLocalStorage {
    WGPUChainedStruct chain;
    uint64_t totalPixelLocalStorageSize;
    size_t storageAttachmentCount;
    WGPUPipelineLayoutStorageAttachment const * storageAttachments;
} WGPUPipelineLayoutPixelLocalStorage WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_PIPELINE_LAYOUT_PIXEL_LOCAL_STORAGE_INIT WGPU_MAKE_INIT_STRUCT(WGPUPipelineLayoutPixelLocalStorage, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.totalPixelLocalStorageSize=*/{} WGPU_COMMA \
    /*.storageAttachmentCount=*/0 WGPU_COMMA \
    /*.storageAttachments=*/{} WGPU_COMMA \
})

typedef struct WGPUProgrammableStageDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPUShaderModule module;
    WGPU_NULLABLE char const * entryPoint;
    size_t constantCount;
    WGPUConstantEntry const * constants;
} WGPUProgrammableStageDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_PROGRAMMABLE_STAGE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUProgrammableStageDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.module=*/{} WGPU_COMMA \
    /*.entryPoint=*/nullptr WGPU_COMMA \
    /*.constantCount=*/0 WGPU_COMMA \
    /*.constants=*/{} WGPU_COMMA \
})

typedef struct WGPURenderPassColorAttachment {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE WGPUTextureView view;
    uint32_t depthSlice;
    WGPU_NULLABLE WGPUTextureView resolveTarget;
    WGPULoadOp loadOp;
    WGPUStoreOp storeOp;
    WGPUColor clearValue;
} WGPURenderPassColorAttachment WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_RENDER_PASS_COLOR_ATTACHMENT_INIT WGPU_MAKE_INIT_STRUCT(WGPURenderPassColorAttachment, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.view=*/nullptr WGPU_COMMA \
    /*.depthSlice=*/WGPU_DEPTH_SLICE_UNDEFINED WGPU_COMMA \
    /*.resolveTarget=*/nullptr WGPU_COMMA \
    /*.loadOp=*/{} WGPU_COMMA \
    /*.storeOp=*/{} WGPU_COMMA \
    /*.clearValue=*/WGPU_COLOR_INIT WGPU_COMMA \
})

typedef struct WGPURenderPassStorageAttachment {
    WGPUChainedStruct const * nextInChain;
    uint64_t offset;
    WGPUTextureView storage;
    WGPULoadOp loadOp;
    WGPUStoreOp storeOp;
    WGPUColor clearValue;
} WGPURenderPassStorageAttachment WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_RENDER_PASS_STORAGE_ATTACHMENT_INIT WGPU_MAKE_INIT_STRUCT(WGPURenderPassStorageAttachment, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.offset=*/0 WGPU_COMMA \
    /*.storage=*/{} WGPU_COMMA \
    /*.loadOp=*/{} WGPU_COMMA \
    /*.storeOp=*/{} WGPU_COMMA \
    /*.clearValue=*/WGPU_COLOR_INIT WGPU_COMMA \
})

typedef struct WGPURequiredLimits {
    WGPUChainedStruct const * nextInChain;
    WGPULimits limits;
} WGPURequiredLimits WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_REQUIRED_LIMITS_INIT WGPU_MAKE_INIT_STRUCT(WGPURequiredLimits, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.limits=*/WGPU_LIMITS_INIT WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryProperties
typedef struct WGPUSharedTextureMemoryAHardwareBufferProperties {
    WGPUChainedStructOut chain;
    WGPUYCbCrVkDescriptor yCbCrInfo;
} WGPUSharedTextureMemoryAHardwareBufferProperties WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_A_HARDWARE_BUFFER_PROPERTIES_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryAHardwareBufferProperties, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.yCbCrInfo=*/WGPU_Y_CB_CR_VK_DESCRIPTOR_INIT WGPU_COMMA \
})

// Can be chained in WGPUSharedTextureMemoryDescriptor
typedef struct WGPUSharedTextureMemoryDmaBufDescriptor {
    WGPUChainedStruct chain;
    WGPUExtent3D size;
    uint32_t drmFormat;
    uint64_t drmModifier;
    size_t planeCount;
    WGPUSharedTextureMemoryDmaBufPlane const * planes;
} WGPUSharedTextureMemoryDmaBufDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_DMA_BUF_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryDmaBufDescriptor, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.size=*/WGPU_EXTENT_3D_INIT WGPU_COMMA \
    /*.drmFormat=*/{} WGPU_COMMA \
    /*.drmModifier=*/{} WGPU_COMMA \
    /*.planeCount=*/{} WGPU_COMMA \
    /*.planes=*/{} WGPU_COMMA \
})

typedef struct WGPUSharedTextureMemoryProperties {
    WGPUChainedStructOut * nextInChain;
    WGPUTextureUsageFlags usage;
    WGPUExtent3D size;
    WGPUTextureFormat format;
} WGPUSharedTextureMemoryProperties WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SHARED_TEXTURE_MEMORY_PROPERTIES_INIT WGPU_MAKE_INIT_STRUCT(WGPUSharedTextureMemoryProperties, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.usage=*/{} WGPU_COMMA \
    /*.size=*/WGPU_EXTENT_3D_INIT WGPU_COMMA \
    /*.format=*/{} WGPU_COMMA \
})

typedef struct WGPUSupportedLimits {
    WGPUChainedStructOut * nextInChain;
    WGPULimits limits;
} WGPUSupportedLimits WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_SUPPORTED_LIMITS_INIT WGPU_MAKE_INIT_STRUCT(WGPUSupportedLimits, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.limits=*/WGPU_LIMITS_INIT WGPU_COMMA \
})

typedef struct WGPUTextureDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    WGPUTextureUsageFlags usage;
    WGPUTextureDimension dimension;
    WGPUExtent3D size;
    WGPUTextureFormat format;
    uint32_t mipLevelCount;
    uint32_t sampleCount;
    size_t viewFormatCount;
    WGPUTextureFormat const * viewFormats;
} WGPUTextureDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_TEXTURE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUTextureDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.usage=*/{} WGPU_COMMA \
    /*.dimension=*/WGPUTextureDimension_2D WGPU_COMMA \
    /*.size=*/WGPU_EXTENT_3D_INIT WGPU_COMMA \
    /*.format=*/{} WGPU_COMMA \
    /*.mipLevelCount=*/1 WGPU_COMMA \
    /*.sampleCount=*/1 WGPU_COMMA \
    /*.viewFormatCount=*/0 WGPU_COMMA \
    /*.viewFormats=*/{} WGPU_COMMA \
})

typedef struct WGPUVertexBufferLayout {
    uint64_t arrayStride;
    WGPUVertexStepMode stepMode;
    size_t attributeCount;
    WGPUVertexAttribute const * attributes;
} WGPUVertexBufferLayout WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_VERTEX_BUFFER_LAYOUT_INIT WGPU_MAKE_INIT_STRUCT(WGPUVertexBufferLayout, { \
    /*.arrayStride=*/{} WGPU_COMMA \
    /*.stepMode=*/WGPUVertexStepMode_Vertex WGPU_COMMA \
    /*.attributeCount=*/{} WGPU_COMMA \
    /*.attributes=*/{} WGPU_COMMA \
})

typedef struct WGPUBindGroupLayoutDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    size_t entryCount;
    WGPUBindGroupLayoutEntry const * entries;
} WGPUBindGroupLayoutDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_BIND_GROUP_LAYOUT_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUBindGroupLayoutDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.entryCount=*/{} WGPU_COMMA \
    /*.entries=*/{} WGPU_COMMA \
})

typedef struct WGPUColorTargetState {
    WGPUChainedStruct const * nextInChain;
    WGPUTextureFormat format;
    WGPU_NULLABLE WGPUBlendState const * blend;
    WGPUColorWriteMaskFlags writeMask;
} WGPUColorTargetState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COLOR_TARGET_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUColorTargetState, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.format=*/{} WGPU_COMMA \
    /*.blend=*/nullptr WGPU_COMMA \
    /*.writeMask=*/WGPUColorWriteMask_All WGPU_COMMA \
})

typedef struct WGPUComputePipelineDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    WGPU_NULLABLE WGPUPipelineLayout layout;
    WGPUProgrammableStageDescriptor compute;
} WGPUComputePipelineDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COMPUTE_PIPELINE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUComputePipelineDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.layout=*/nullptr WGPU_COMMA \
    /*.compute=*/WGPU_PROGRAMMABLE_STAGE_DESCRIPTOR_INIT WGPU_COMMA \
})

typedef struct WGPUDeviceDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    size_t requiredFeatureCount;
    WGPUFeatureName const * requiredFeatures;
    WGPU_NULLABLE WGPURequiredLimits const * requiredLimits;
    WGPUQueueDescriptor defaultQueue;
    WGPUDeviceLostCallback deviceLostCallback;
    void * deviceLostUserdata;
    WGPUDeviceLostCallbackInfo deviceLostCallbackInfo;
    WGPUUncapturedErrorCallbackInfo uncapturedErrorCallbackInfo;
} WGPUDeviceDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_DEVICE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPUDeviceDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.requiredFeatureCount=*/0 WGPU_COMMA \
    /*.requiredFeatures=*/nullptr WGPU_COMMA \
    /*.requiredLimits=*/nullptr WGPU_COMMA \
    /*.defaultQueue=*/WGPU_QUEUE_DESCRIPTOR_INIT WGPU_COMMA \
    /*.deviceLostCallback=*/nullptr WGPU_COMMA \
    /*.deviceLostUserdata=*/nullptr WGPU_COMMA \
    /*.deviceLostCallbackInfo=*/WGPU_DEVICE_LOST_CALLBACK_INFO_INIT WGPU_COMMA \
    /*.uncapturedErrorCallbackInfo=*/WGPU_UNCAPTURED_ERROR_CALLBACK_INFO_INIT WGPU_COMMA \
})

typedef struct WGPURenderPassDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    size_t colorAttachmentCount;
    WGPURenderPassColorAttachment const * colorAttachments;
    WGPU_NULLABLE WGPURenderPassDepthStencilAttachment const * depthStencilAttachment;
    WGPU_NULLABLE WGPUQuerySet occlusionQuerySet;
    WGPU_NULLABLE WGPURenderPassTimestampWrites const * timestampWrites;
} WGPURenderPassDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_RENDER_PASS_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPURenderPassDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.colorAttachmentCount=*/{} WGPU_COMMA \
    /*.colorAttachments=*/{} WGPU_COMMA \
    /*.depthStencilAttachment=*/nullptr WGPU_COMMA \
    /*.occlusionQuerySet=*/nullptr WGPU_COMMA \
    /*.timestampWrites=*/nullptr WGPU_COMMA \
})

// Can be chained in WGPURenderPassDescriptor
typedef struct WGPURenderPassPixelLocalStorage {
    WGPUChainedStruct chain;
    uint64_t totalPixelLocalStorageSize;
    size_t storageAttachmentCount;
    WGPURenderPassStorageAttachment const * storageAttachments;
} WGPURenderPassPixelLocalStorage WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_RENDER_PASS_PIXEL_LOCAL_STORAGE_INIT WGPU_MAKE_INIT_STRUCT(WGPURenderPassPixelLocalStorage, { \
    /*.chain=*/{} WGPU_COMMA \
    /*.totalPixelLocalStorageSize=*/{} WGPU_COMMA \
    /*.storageAttachmentCount=*/0 WGPU_COMMA \
    /*.storageAttachments=*/{} WGPU_COMMA \
})

typedef struct WGPUVertexState {
    WGPUChainedStruct const * nextInChain;
    WGPUShaderModule module;
    WGPU_NULLABLE char const * entryPoint;
    size_t constantCount;
    WGPUConstantEntry const * constants;
    size_t bufferCount;
    WGPUVertexBufferLayout const * buffers;
} WGPUVertexState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_VERTEX_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUVertexState, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.module=*/{} WGPU_COMMA \
    /*.entryPoint=*/nullptr WGPU_COMMA \
    /*.constantCount=*/0 WGPU_COMMA \
    /*.constants=*/{} WGPU_COMMA \
    /*.bufferCount=*/0 WGPU_COMMA \
    /*.buffers=*/{} WGPU_COMMA \
})

typedef struct WGPUFragmentState {
    WGPUChainedStruct const * nextInChain;
    WGPUShaderModule module;
    WGPU_NULLABLE char const * entryPoint;
    size_t constantCount;
    WGPUConstantEntry const * constants;
    size_t targetCount;
    WGPUColorTargetState const * targets;
} WGPUFragmentState WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_FRAGMENT_STATE_INIT WGPU_MAKE_INIT_STRUCT(WGPUFragmentState, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.module=*/{} WGPU_COMMA \
    /*.entryPoint=*/nullptr WGPU_COMMA \
    /*.constantCount=*/0 WGPU_COMMA \
    /*.constants=*/{} WGPU_COMMA \
    /*.targetCount=*/{} WGPU_COMMA \
    /*.targets=*/{} WGPU_COMMA \
})

typedef struct WGPURenderPipelineDescriptor {
    WGPUChainedStruct const * nextInChain;
    WGPU_NULLABLE char const * label;
    WGPU_NULLABLE WGPUPipelineLayout layout;
    WGPUVertexState vertex;
    WGPUPrimitiveState primitive;
    WGPU_NULLABLE WGPUDepthStencilState const * depthStencil;
    WGPUMultisampleState multisample;
    WGPU_NULLABLE WGPUFragmentState const * fragment;
} WGPURenderPipelineDescriptor WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_RENDER_PIPELINE_DESCRIPTOR_INIT WGPU_MAKE_INIT_STRUCT(WGPURenderPipelineDescriptor, { \
    /*.nextInChain=*/nullptr WGPU_COMMA \
    /*.label=*/nullptr WGPU_COMMA \
    /*.layout=*/nullptr WGPU_COMMA \
    /*.vertex=*/WGPU_VERTEX_STATE_INIT WGPU_COMMA \
    /*.primitive=*/WGPU_PRIMITIVE_STATE_INIT WGPU_COMMA \
    /*.depthStencil=*/nullptr WGPU_COMMA \
    /*.multisample=*/WGPU_MULTISAMPLE_STATE_INIT WGPU_COMMA \
    /*.fragment=*/nullptr WGPU_COMMA \
})

typedef struct WGPUBufferMapCallbackInfo2 {
    WGPUChainedStruct const* nextInChain;
    WGPUCallbackMode mode;
    WGPUBufferMapCallback2 callback;
    void* userdata1;
    void* userdata2;
} WGPUBufferMapCallbackInfo2 WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_BUFFER_MAP_CALLBACK_INFO_2_INIT WGPU_MAKE_INIT_STRUCT(WGPUBufferMapCallbackInfo2, { \
    /*.mode=*/WGPUCallbackMode_Undefined WGPU_COMMA \
    /*.callback=*/nullptr WGPU_COMMA \
    /*.userdata1=*/nullptr WGPU_COMMA \
    /*.userdata2=*/nullptr WGPU_COMMA \
})

typedef struct WGPUCompilationInfoCallbackInfo2 {
    WGPUChainedStruct const* nextInChain;
    WGPUCallbackMode mode;
    WGPUCompilationInfoCallback2 callback;
    void* userdata1;
    void* userdata2;
} WGPUCompilationInfoCallbackInfo2 WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_COMPILATION_INFO_CALLBACK_INFO_2_INIT WGPU_MAKE_INIT_STRUCT(WGPUCompilationInfoCallbackInfo2, { \
    /*.mode=*/WGPUCallbackMode_Undefined WGPU_COMMA \
    /*.callback=*/nullptr WGPU_COMMA \
    /*.userdata1=*/nullptr WGPU_COMMA \
    /*.userdata2=*/nullptr WGPU_COMMA \
})

typedef struct WGPUCreateComputePipelineAsyncCallbackInfo2 {
    WGPUChainedStruct const* nextInChain;
    WGPUCallbackMode mode;
    WGPUCreateComputePipelineAsyncCallback2 callback;
    void* userdata1;
    void* userdata2;
} WGPUCreateComputePipelineAsyncCallbackInfo2 WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_CREATE_COMPUTE_PIPELINE_ASYNC_CALLBACK_INFO_2_INIT WGPU_MAKE_INIT_STRUCT(WGPUCreateComputePipelineAsyncCallbackInfo2, { \
    /*.mode=*/WGPUCallbackMode_Undefined WGPU_COMMA \
    /*.callback=*/nullptr WGPU_COMMA \
    /*.userdata1=*/nullptr WGPU_COMMA \
    /*.userdata2=*/nullptr WGPU_COMMA \
})

typedef struct WGPUCreateRenderPipelineAsyncCallbackInfo2 {
    WGPUChainedStruct const* nextInChain;
    WGPUCallbackMode mode;
    WGPUCreateRenderPipelineAsyncCallback2 callback;
    void* userdata1;
    void* userdata2;
} WGPUCreateRenderPipelineAsyncCallbackInfo2 WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_CREATE_RENDER_PIPELINE_ASYNC_CALLBACK_INFO_2_INIT WGPU_MAKE_INIT_STRUCT(WGPUCreateRenderPipelineAsyncCallbackInfo2, { \
    /*.mode=*/WGPUCallbackMode_Undefined WGPU_COMMA \
    /*.callback=*/nullptr WGPU_COMMA \
    /*.userdata1=*/nullptr WGPU_COMMA \
    /*.userdata2=*/nullptr WGPU_COMMA \
})

typedef struct WGPUPopErrorScopeCallbackInfo2 {
    WGPUChainedStruct const* nextInChain;
    WGPUCallbackMode mode;
    WGPUPopErrorScopeCallback2 callback;
    void* userdata1;
    void* userdata2;
} WGPUPopErrorScopeCallbackInfo2 WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_POP_ERROR_SCOPE_CALLBACK_INFO_2_INIT WGPU_MAKE_INIT_STRUCT(WGPUPopErrorScopeCallbackInfo2, { \
    /*.mode=*/WGPUCallbackMode_Undefined WGPU_COMMA \
    /*.callback=*/nullptr WGPU_COMMA \
    /*.userdata1=*/nullptr WGPU_COMMA \
    /*.userdata2=*/nullptr WGPU_COMMA \
})

typedef struct WGPUQueueWorkDoneCallbackInfo2 {
    WGPUChainedStruct const* nextInChain;
    WGPUCallbackMode mode;
    WGPUQueueWorkDoneCallback2 callback;
    void* userdata1;
    void* userdata2;
} WGPUQueueWorkDoneCallbackInfo2 WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_QUEUE_WORK_DONE_CALLBACK_INFO_2_INIT WGPU_MAKE_INIT_STRUCT(WGPUQueueWorkDoneCallbackInfo2, { \
    /*.mode=*/WGPUCallbackMode_Undefined WGPU_COMMA \
    /*.callback=*/nullptr WGPU_COMMA \
    /*.userdata1=*/nullptr WGPU_COMMA \
    /*.userdata2=*/nullptr WGPU_COMMA \
})

typedef struct WGPURequestAdapterCallbackInfo2 {
    WGPUChainedStruct const* nextInChain;
    WGPUCallbackMode mode;
    WGPURequestAdapterCallback2 callback;
    void* userdata1;
    void* userdata2;
} WGPURequestAdapterCallbackInfo2 WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_REQUEST_ADAPTER_CALLBACK_INFO_2_INIT WGPU_MAKE_INIT_STRUCT(WGPURequestAdapterCallbackInfo2, { \
    /*.mode=*/WGPUCallbackMode_Undefined WGPU_COMMA \
    /*.callback=*/nullptr WGPU_COMMA \
    /*.userdata1=*/nullptr WGPU_COMMA \
    /*.userdata2=*/nullptr WGPU_COMMA \
})

typedef struct WGPURequestDeviceCallbackInfo2 {
    WGPUChainedStruct const* nextInChain;
    WGPUCallbackMode mode;
    WGPURequestDeviceCallback2 callback;
    void* userdata1;
    void* userdata2;
} WGPURequestDeviceCallbackInfo2 WGPU_STRUCTURE_ATTRIBUTE;

#define WGPU_REQUEST_DEVICE_CALLBACK_INFO_2_INIT WGPU_MAKE_INIT_STRUCT(WGPURequestDeviceCallbackInfo2, { \
    /*.mode=*/WGPUCallbackMode_Undefined WGPU_COMMA \
    /*.callback=*/nullptr WGPU_COMMA \
    /*.userdata1=*/nullptr WGPU_COMMA \
    /*.userdata2=*/nullptr WGPU_COMMA \
})

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(WGPU_SKIP_PROCS)

typedef void (*WGPUProcAdapterInfoFreeMembers)(WGPUAdapterInfo value) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcAdapterPropertiesFreeMembers)(WGPUAdapterProperties value) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcAdapterPropertiesMemoryHeapsFreeMembers)(WGPUAdapterPropertiesMemoryHeaps value) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUInstance (*WGPUProcCreateInstance)(WGPUInstanceDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDrmFormatCapabilitiesFreeMembers)(WGPUDrmFormatCapabilities value) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcGetInstanceFeatures)(WGPUInstanceFeatures * features) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUProc (*WGPUProcGetProcAddress)(WGPUDevice device, char const * procName) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSharedBufferMemoryEndAccessStateFreeMembers)(WGPUSharedBufferMemoryEndAccessState value) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSharedTextureMemoryEndAccessStateFreeMembers)(WGPUSharedTextureMemoryEndAccessState value) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSurfaceCapabilitiesFreeMembers)(WGPUSurfaceCapabilities value) WGPU_FUNCTION_ATTRIBUTE;

// Procs of Adapter
typedef WGPUDevice (*WGPUProcAdapterCreateDevice)(WGPUAdapter adapter, WGPU_NULLABLE WGPUDeviceDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef size_t (*WGPUProcAdapterEnumerateFeatures)(WGPUAdapter adapter, WGPUFeatureName * features) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcAdapterGetFormatCapabilities)(WGPUAdapter adapter, WGPUTextureFormat format, WGPUFormatCapabilities * capabilities) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcAdapterGetInfo)(WGPUAdapter adapter, WGPUAdapterInfo * info) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUInstance (*WGPUProcAdapterGetInstance)(WGPUAdapter adapter) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcAdapterGetLimits)(WGPUAdapter adapter, WGPUSupportedLimits * limits) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcAdapterGetProperties)(WGPUAdapter adapter, WGPUAdapterProperties * properties) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUBool (*WGPUProcAdapterHasFeature)(WGPUAdapter adapter, WGPUFeatureName feature) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcAdapterRequestDevice)(WGPUAdapter adapter, WGPU_NULLABLE WGPUDeviceDescriptor const * descriptor, WGPURequestDeviceCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcAdapterRequestDevice2)(WGPUAdapter adapter, WGPU_NULLABLE WGPUDeviceDescriptor const * options, WGPURequestDeviceCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcAdapterRequestDeviceF)(WGPUAdapter adapter, WGPU_NULLABLE WGPUDeviceDescriptor const * options, WGPURequestDeviceCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcAdapterAddRef)(WGPUAdapter adapter) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcAdapterRelease)(WGPUAdapter adapter) WGPU_FUNCTION_ATTRIBUTE;

// Procs of BindGroup
typedef void (*WGPUProcBindGroupSetLabel)(WGPUBindGroup bindGroup, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcBindGroupAddRef)(WGPUBindGroup bindGroup) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcBindGroupRelease)(WGPUBindGroup bindGroup) WGPU_FUNCTION_ATTRIBUTE;

// Procs of BindGroupLayout
typedef void (*WGPUProcBindGroupLayoutSetLabel)(WGPUBindGroupLayout bindGroupLayout, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcBindGroupLayoutAddRef)(WGPUBindGroupLayout bindGroupLayout) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcBindGroupLayoutRelease)(WGPUBindGroupLayout bindGroupLayout) WGPU_FUNCTION_ATTRIBUTE;

// Procs of Buffer
typedef void (*WGPUProcBufferDestroy)(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
typedef void const * (*WGPUProcBufferGetConstMappedRange)(WGPUBuffer buffer, size_t offset, size_t size) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUBufferMapState (*WGPUProcBufferGetMapState)(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
typedef void * (*WGPUProcBufferGetMappedRange)(WGPUBuffer buffer, size_t offset, size_t size) WGPU_FUNCTION_ATTRIBUTE;
typedef uint64_t (*WGPUProcBufferGetSize)(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUBufferUsageFlags (*WGPUProcBufferGetUsage)(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcBufferMapAsync)(WGPUBuffer buffer, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcBufferMapAsync2)(WGPUBuffer buffer, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcBufferMapAsyncF)(WGPUBuffer buffer, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcBufferSetLabel)(WGPUBuffer buffer, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcBufferUnmap)(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcBufferAddRef)(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcBufferRelease)(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;

// Procs of CommandBuffer
typedef void (*WGPUProcCommandBufferSetLabel)(WGPUCommandBuffer commandBuffer, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandBufferAddRef)(WGPUCommandBuffer commandBuffer) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandBufferRelease)(WGPUCommandBuffer commandBuffer) WGPU_FUNCTION_ATTRIBUTE;

// Procs of CommandEncoder
typedef WGPUComputePassEncoder (*WGPUProcCommandEncoderBeginComputePass)(WGPUCommandEncoder commandEncoder, WGPU_NULLABLE WGPUComputePassDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPURenderPassEncoder (*WGPUProcCommandEncoderBeginRenderPass)(WGPUCommandEncoder commandEncoder, WGPURenderPassDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderClearBuffer)(WGPUCommandEncoder commandEncoder, WGPUBuffer buffer, uint64_t offset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderCopyBufferToBuffer)(WGPUCommandEncoder commandEncoder, WGPUBuffer source, uint64_t sourceOffset, WGPUBuffer destination, uint64_t destinationOffset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderCopyBufferToTexture)(WGPUCommandEncoder commandEncoder, WGPUImageCopyBuffer const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderCopyTextureToBuffer)(WGPUCommandEncoder commandEncoder, WGPUImageCopyTexture const * source, WGPUImageCopyBuffer const * destination, WGPUExtent3D const * copySize) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderCopyTextureToTexture)(WGPUCommandEncoder commandEncoder, WGPUImageCopyTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUCommandBuffer (*WGPUProcCommandEncoderFinish)(WGPUCommandEncoder commandEncoder, WGPU_NULLABLE WGPUCommandBufferDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderInjectValidationError)(WGPUCommandEncoder commandEncoder, char const * message) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderInsertDebugMarker)(WGPUCommandEncoder commandEncoder, char const * markerLabel) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderPopDebugGroup)(WGPUCommandEncoder commandEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderPushDebugGroup)(WGPUCommandEncoder commandEncoder, char const * groupLabel) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderResolveQuerySet)(WGPUCommandEncoder commandEncoder, WGPUQuerySet querySet, uint32_t firstQuery, uint32_t queryCount, WGPUBuffer destination, uint64_t destinationOffset) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderSetLabel)(WGPUCommandEncoder commandEncoder, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderWriteBuffer)(WGPUCommandEncoder commandEncoder, WGPUBuffer buffer, uint64_t bufferOffset, uint8_t const * data, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderWriteTimestamp)(WGPUCommandEncoder commandEncoder, WGPUQuerySet querySet, uint32_t queryIndex) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderAddRef)(WGPUCommandEncoder commandEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcCommandEncoderRelease)(WGPUCommandEncoder commandEncoder) WGPU_FUNCTION_ATTRIBUTE;

// Procs of ComputePassEncoder
typedef void (*WGPUProcComputePassEncoderDispatchWorkgroups)(WGPUComputePassEncoder computePassEncoder, uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePassEncoderDispatchWorkgroupsIndirect)(WGPUComputePassEncoder computePassEncoder, WGPUBuffer indirectBuffer, uint64_t indirectOffset) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePassEncoderEnd)(WGPUComputePassEncoder computePassEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePassEncoderInsertDebugMarker)(WGPUComputePassEncoder computePassEncoder, char const * markerLabel) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePassEncoderPopDebugGroup)(WGPUComputePassEncoder computePassEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePassEncoderPushDebugGroup)(WGPUComputePassEncoder computePassEncoder, char const * groupLabel) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePassEncoderSetBindGroup)(WGPUComputePassEncoder computePassEncoder, uint32_t groupIndex, WGPU_NULLABLE WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePassEncoderSetLabel)(WGPUComputePassEncoder computePassEncoder, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePassEncoderSetPipeline)(WGPUComputePassEncoder computePassEncoder, WGPUComputePipeline pipeline) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePassEncoderWriteTimestamp)(WGPUComputePassEncoder computePassEncoder, WGPUQuerySet querySet, uint32_t queryIndex) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePassEncoderAddRef)(WGPUComputePassEncoder computePassEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePassEncoderRelease)(WGPUComputePassEncoder computePassEncoder) WGPU_FUNCTION_ATTRIBUTE;

// Procs of ComputePipeline
typedef WGPUBindGroupLayout (*WGPUProcComputePipelineGetBindGroupLayout)(WGPUComputePipeline computePipeline, uint32_t groupIndex) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePipelineSetLabel)(WGPUComputePipeline computePipeline, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePipelineAddRef)(WGPUComputePipeline computePipeline) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcComputePipelineRelease)(WGPUComputePipeline computePipeline) WGPU_FUNCTION_ATTRIBUTE;

// Procs of Device
typedef WGPUBindGroup (*WGPUProcDeviceCreateBindGroup)(WGPUDevice device, WGPUBindGroupDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUBindGroupLayout (*WGPUProcDeviceCreateBindGroupLayout)(WGPUDevice device, WGPUBindGroupLayoutDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUBuffer (*WGPUProcDeviceCreateBuffer)(WGPUDevice device, WGPUBufferDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUCommandEncoder (*WGPUProcDeviceCreateCommandEncoder)(WGPUDevice device, WGPU_NULLABLE WGPUCommandEncoderDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUComputePipeline (*WGPUProcDeviceCreateComputePipeline)(WGPUDevice device, WGPUComputePipelineDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceCreateComputePipelineAsync)(WGPUDevice device, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcDeviceCreateComputePipelineAsync2)(WGPUDevice device, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcDeviceCreateComputePipelineAsyncF)(WGPUDevice device, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUBuffer (*WGPUProcDeviceCreateErrorBuffer)(WGPUDevice device, WGPUBufferDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUExternalTexture (*WGPUProcDeviceCreateErrorExternalTexture)(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUShaderModule (*WGPUProcDeviceCreateErrorShaderModule)(WGPUDevice device, WGPUShaderModuleDescriptor const * descriptor, char const * errorMessage) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUTexture (*WGPUProcDeviceCreateErrorTexture)(WGPUDevice device, WGPUTextureDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUExternalTexture (*WGPUProcDeviceCreateExternalTexture)(WGPUDevice device, WGPUExternalTextureDescriptor const * externalTextureDescriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUPipelineLayout (*WGPUProcDeviceCreatePipelineLayout)(WGPUDevice device, WGPUPipelineLayoutDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUQuerySet (*WGPUProcDeviceCreateQuerySet)(WGPUDevice device, WGPUQuerySetDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPURenderBundleEncoder (*WGPUProcDeviceCreateRenderBundleEncoder)(WGPUDevice device, WGPURenderBundleEncoderDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPURenderPipeline (*WGPUProcDeviceCreateRenderPipeline)(WGPUDevice device, WGPURenderPipelineDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceCreateRenderPipelineAsync)(WGPUDevice device, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcDeviceCreateRenderPipelineAsync2)(WGPUDevice device, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcDeviceCreateRenderPipelineAsyncF)(WGPUDevice device, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUSampler (*WGPUProcDeviceCreateSampler)(WGPUDevice device, WGPU_NULLABLE WGPUSamplerDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUShaderModule (*WGPUProcDeviceCreateShaderModule)(WGPUDevice device, WGPUShaderModuleDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUSwapChain (*WGPUProcDeviceCreateSwapChain)(WGPUDevice device, WGPUSurface surface, WGPUSwapChainDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUTexture (*WGPUProcDeviceCreateTexture)(WGPUDevice device, WGPUTextureDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceDestroy)(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
typedef size_t (*WGPUProcDeviceEnumerateFeatures)(WGPUDevice device, WGPUFeatureName * features) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceForceLoss)(WGPUDevice device, WGPUDeviceLostReason type, char const * message) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcDeviceGetAHardwareBufferProperties)(WGPUDevice device, void * handle, WGPUAHardwareBufferProperties * properties) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUAdapter (*WGPUProcDeviceGetAdapter)(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcDeviceGetLimits)(WGPUDevice device, WGPUSupportedLimits * limits) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUQueue (*WGPUProcDeviceGetQueue)(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUTextureUsageFlags (*WGPUProcDeviceGetSupportedSurfaceUsage)(WGPUDevice device, WGPUSurface surface) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUBool (*WGPUProcDeviceHasFeature)(WGPUDevice device, WGPUFeatureName feature) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUSharedBufferMemory (*WGPUProcDeviceImportSharedBufferMemory)(WGPUDevice device, WGPUSharedBufferMemoryDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUSharedFence (*WGPUProcDeviceImportSharedFence)(WGPUDevice device, WGPUSharedFenceDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUSharedTextureMemory (*WGPUProcDeviceImportSharedTextureMemory)(WGPUDevice device, WGPUSharedTextureMemoryDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceInjectError)(WGPUDevice device, WGPUErrorType type, char const * message) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDevicePopErrorScope)(WGPUDevice device, WGPUErrorCallback oldCallback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcDevicePopErrorScope2)(WGPUDevice device, WGPUPopErrorScopeCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcDevicePopErrorScopeF)(WGPUDevice device, WGPUPopErrorScopeCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDevicePushErrorScope)(WGPUDevice device, WGPUErrorFilter filter) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceSetDeviceLostCallback)(WGPUDevice device, WGPUDeviceLostCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceSetLabel)(WGPUDevice device, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceSetLoggingCallback)(WGPUDevice device, WGPULoggingCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceSetUncapturedErrorCallback)(WGPUDevice device, WGPUErrorCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceTick)(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceValidateTextureDescriptor)(WGPUDevice device, WGPUTextureDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceAddRef)(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcDeviceRelease)(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;

// Procs of ExternalTexture
typedef void (*WGPUProcExternalTextureDestroy)(WGPUExternalTexture externalTexture) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcExternalTextureExpire)(WGPUExternalTexture externalTexture) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcExternalTextureRefresh)(WGPUExternalTexture externalTexture) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcExternalTextureSetLabel)(WGPUExternalTexture externalTexture, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcExternalTextureAddRef)(WGPUExternalTexture externalTexture) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcExternalTextureRelease)(WGPUExternalTexture externalTexture) WGPU_FUNCTION_ATTRIBUTE;

// Procs of Instance
typedef WGPUSurface (*WGPUProcInstanceCreateSurface)(WGPUInstance instance, WGPUSurfaceDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef size_t (*WGPUProcInstanceEnumerateWGSLLanguageFeatures)(WGPUInstance instance, WGPUWGSLFeatureName * features) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUBool (*WGPUProcInstanceHasWGSLLanguageFeature)(WGPUInstance instance, WGPUWGSLFeatureName feature) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcInstanceProcessEvents)(WGPUInstance instance) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcInstanceRequestAdapter)(WGPUInstance instance, WGPU_NULLABLE WGPURequestAdapterOptions const * options, WGPURequestAdapterCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcInstanceRequestAdapter2)(WGPUInstance instance, WGPU_NULLABLE WGPURequestAdapterOptions const * options, WGPURequestAdapterCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcInstanceRequestAdapterF)(WGPUInstance instance, WGPU_NULLABLE WGPURequestAdapterOptions const * options, WGPURequestAdapterCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUWaitStatus (*WGPUProcInstanceWaitAny)(WGPUInstance instance, size_t futureCount, WGPUFutureWaitInfo * futures, uint64_t timeoutNS) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcInstanceAddRef)(WGPUInstance instance) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcInstanceRelease)(WGPUInstance instance) WGPU_FUNCTION_ATTRIBUTE;

// Procs of PipelineLayout
typedef void (*WGPUProcPipelineLayoutSetLabel)(WGPUPipelineLayout pipelineLayout, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcPipelineLayoutAddRef)(WGPUPipelineLayout pipelineLayout) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcPipelineLayoutRelease)(WGPUPipelineLayout pipelineLayout) WGPU_FUNCTION_ATTRIBUTE;

// Procs of QuerySet
typedef void (*WGPUProcQuerySetDestroy)(WGPUQuerySet querySet) WGPU_FUNCTION_ATTRIBUTE;
typedef uint32_t (*WGPUProcQuerySetGetCount)(WGPUQuerySet querySet) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUQueryType (*WGPUProcQuerySetGetType)(WGPUQuerySet querySet) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcQuerySetSetLabel)(WGPUQuerySet querySet, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcQuerySetAddRef)(WGPUQuerySet querySet) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcQuerySetRelease)(WGPUQuerySet querySet) WGPU_FUNCTION_ATTRIBUTE;

// Procs of Queue
typedef void (*WGPUProcQueueCopyExternalTextureForBrowser)(WGPUQueue queue, WGPUImageCopyExternalTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize, WGPUCopyTextureForBrowserOptions const * options) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcQueueCopyTextureForBrowser)(WGPUQueue queue, WGPUImageCopyTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize, WGPUCopyTextureForBrowserOptions const * options) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcQueueOnSubmittedWorkDone)(WGPUQueue queue, WGPUQueueWorkDoneCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcQueueOnSubmittedWorkDone2)(WGPUQueue queue, WGPUQueueWorkDoneCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcQueueOnSubmittedWorkDoneF)(WGPUQueue queue, WGPUQueueWorkDoneCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcQueueSetLabel)(WGPUQueue queue, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcQueueSubmit)(WGPUQueue queue, size_t commandCount, WGPUCommandBuffer const * commands) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcQueueWriteBuffer)(WGPUQueue queue, WGPUBuffer buffer, uint64_t bufferOffset, void const * data, size_t size) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcQueueWriteTexture)(WGPUQueue queue, WGPUImageCopyTexture const * destination, void const * data, size_t dataSize, WGPUTextureDataLayout const * dataLayout, WGPUExtent3D const * writeSize) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcQueueAddRef)(WGPUQueue queue) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcQueueRelease)(WGPUQueue queue) WGPU_FUNCTION_ATTRIBUTE;

// Procs of RenderBundle
typedef void (*WGPUProcRenderBundleSetLabel)(WGPURenderBundle renderBundle, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleAddRef)(WGPURenderBundle renderBundle) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleRelease)(WGPURenderBundle renderBundle) WGPU_FUNCTION_ATTRIBUTE;

// Procs of RenderBundleEncoder
typedef void (*WGPUProcRenderBundleEncoderDraw)(WGPURenderBundleEncoder renderBundleEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderDrawIndexed)(WGPURenderBundleEncoder renderBundleEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderDrawIndexedIndirect)(WGPURenderBundleEncoder renderBundleEncoder, WGPUBuffer indirectBuffer, uint64_t indirectOffset) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderDrawIndirect)(WGPURenderBundleEncoder renderBundleEncoder, WGPUBuffer indirectBuffer, uint64_t indirectOffset) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPURenderBundle (*WGPUProcRenderBundleEncoderFinish)(WGPURenderBundleEncoder renderBundleEncoder, WGPU_NULLABLE WGPURenderBundleDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderInsertDebugMarker)(WGPURenderBundleEncoder renderBundleEncoder, char const * markerLabel) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderPopDebugGroup)(WGPURenderBundleEncoder renderBundleEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderPushDebugGroup)(WGPURenderBundleEncoder renderBundleEncoder, char const * groupLabel) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderSetBindGroup)(WGPURenderBundleEncoder renderBundleEncoder, uint32_t groupIndex, WGPU_NULLABLE WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderSetIndexBuffer)(WGPURenderBundleEncoder renderBundleEncoder, WGPUBuffer buffer, WGPUIndexFormat format, uint64_t offset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderSetLabel)(WGPURenderBundleEncoder renderBundleEncoder, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderSetPipeline)(WGPURenderBundleEncoder renderBundleEncoder, WGPURenderPipeline pipeline) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderSetVertexBuffer)(WGPURenderBundleEncoder renderBundleEncoder, uint32_t slot, WGPU_NULLABLE WGPUBuffer buffer, uint64_t offset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderAddRef)(WGPURenderBundleEncoder renderBundleEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderBundleEncoderRelease)(WGPURenderBundleEncoder renderBundleEncoder) WGPU_FUNCTION_ATTRIBUTE;

// Procs of RenderPassEncoder
typedef void (*WGPUProcRenderPassEncoderBeginOcclusionQuery)(WGPURenderPassEncoder renderPassEncoder, uint32_t queryIndex) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderDraw)(WGPURenderPassEncoder renderPassEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderDrawIndexed)(WGPURenderPassEncoder renderPassEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderDrawIndexedIndirect)(WGPURenderPassEncoder renderPassEncoder, WGPUBuffer indirectBuffer, uint64_t indirectOffset) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderDrawIndirect)(WGPURenderPassEncoder renderPassEncoder, WGPUBuffer indirectBuffer, uint64_t indirectOffset) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderEnd)(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderEndOcclusionQuery)(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderExecuteBundles)(WGPURenderPassEncoder renderPassEncoder, size_t bundleCount, WGPURenderBundle const * bundles) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderInsertDebugMarker)(WGPURenderPassEncoder renderPassEncoder, char const * markerLabel) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderPixelLocalStorageBarrier)(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderPopDebugGroup)(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderPushDebugGroup)(WGPURenderPassEncoder renderPassEncoder, char const * groupLabel) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderSetBindGroup)(WGPURenderPassEncoder renderPassEncoder, uint32_t groupIndex, WGPU_NULLABLE WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderSetBlendConstant)(WGPURenderPassEncoder renderPassEncoder, WGPUColor const * color) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderSetIndexBuffer)(WGPURenderPassEncoder renderPassEncoder, WGPUBuffer buffer, WGPUIndexFormat format, uint64_t offset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderSetLabel)(WGPURenderPassEncoder renderPassEncoder, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderSetPipeline)(WGPURenderPassEncoder renderPassEncoder, WGPURenderPipeline pipeline) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderSetScissorRect)(WGPURenderPassEncoder renderPassEncoder, uint32_t x, uint32_t y, uint32_t width, uint32_t height) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderSetStencilReference)(WGPURenderPassEncoder renderPassEncoder, uint32_t reference) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderSetVertexBuffer)(WGPURenderPassEncoder renderPassEncoder, uint32_t slot, WGPU_NULLABLE WGPUBuffer buffer, uint64_t offset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderSetViewport)(WGPURenderPassEncoder renderPassEncoder, float x, float y, float width, float height, float minDepth, float maxDepth) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderWriteTimestamp)(WGPURenderPassEncoder renderPassEncoder, WGPUQuerySet querySet, uint32_t queryIndex) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderAddRef)(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPassEncoderRelease)(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;

// Procs of RenderPipeline
typedef WGPUBindGroupLayout (*WGPUProcRenderPipelineGetBindGroupLayout)(WGPURenderPipeline renderPipeline, uint32_t groupIndex) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPipelineSetLabel)(WGPURenderPipeline renderPipeline, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPipelineAddRef)(WGPURenderPipeline renderPipeline) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcRenderPipelineRelease)(WGPURenderPipeline renderPipeline) WGPU_FUNCTION_ATTRIBUTE;

// Procs of Sampler
typedef void (*WGPUProcSamplerSetLabel)(WGPUSampler sampler, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSamplerAddRef)(WGPUSampler sampler) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSamplerRelease)(WGPUSampler sampler) WGPU_FUNCTION_ATTRIBUTE;

// Procs of ShaderModule
typedef void (*WGPUProcShaderModuleGetCompilationInfo)(WGPUShaderModule shaderModule, WGPUCompilationInfoCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcShaderModuleGetCompilationInfo2)(WGPUShaderModule shaderModule, WGPUCompilationInfoCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUFuture (*WGPUProcShaderModuleGetCompilationInfoF)(WGPUShaderModule shaderModule, WGPUCompilationInfoCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcShaderModuleSetLabel)(WGPUShaderModule shaderModule, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcShaderModuleAddRef)(WGPUShaderModule shaderModule) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcShaderModuleRelease)(WGPUShaderModule shaderModule) WGPU_FUNCTION_ATTRIBUTE;

// Procs of SharedBufferMemory
typedef WGPUStatus (*WGPUProcSharedBufferMemoryBeginAccess)(WGPUSharedBufferMemory sharedBufferMemory, WGPUBuffer buffer, WGPUSharedBufferMemoryBeginAccessDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUBuffer (*WGPUProcSharedBufferMemoryCreateBuffer)(WGPUSharedBufferMemory sharedBufferMemory, WGPU_NULLABLE WGPUBufferDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcSharedBufferMemoryEndAccess)(WGPUSharedBufferMemory sharedBufferMemory, WGPUBuffer buffer, WGPUSharedBufferMemoryEndAccessState * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcSharedBufferMemoryGetProperties)(WGPUSharedBufferMemory sharedBufferMemory, WGPUSharedBufferMemoryProperties * properties) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUBool (*WGPUProcSharedBufferMemoryIsDeviceLost)(WGPUSharedBufferMemory sharedBufferMemory) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSharedBufferMemorySetLabel)(WGPUSharedBufferMemory sharedBufferMemory, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSharedBufferMemoryAddRef)(WGPUSharedBufferMemory sharedBufferMemory) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSharedBufferMemoryRelease)(WGPUSharedBufferMemory sharedBufferMemory) WGPU_FUNCTION_ATTRIBUTE;

// Procs of SharedFence
typedef void (*WGPUProcSharedFenceExportInfo)(WGPUSharedFence sharedFence, WGPUSharedFenceExportInfo * info) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSharedFenceAddRef)(WGPUSharedFence sharedFence) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSharedFenceRelease)(WGPUSharedFence sharedFence) WGPU_FUNCTION_ATTRIBUTE;

// Procs of SharedTextureMemory
typedef WGPUStatus (*WGPUProcSharedTextureMemoryBeginAccess)(WGPUSharedTextureMemory sharedTextureMemory, WGPUTexture texture, WGPUSharedTextureMemoryBeginAccessDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUTexture (*WGPUProcSharedTextureMemoryCreateTexture)(WGPUSharedTextureMemory sharedTextureMemory, WGPU_NULLABLE WGPUTextureDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcSharedTextureMemoryEndAccess)(WGPUSharedTextureMemory sharedTextureMemory, WGPUTexture texture, WGPUSharedTextureMemoryEndAccessState * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcSharedTextureMemoryGetProperties)(WGPUSharedTextureMemory sharedTextureMemory, WGPUSharedTextureMemoryProperties * properties) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUBool (*WGPUProcSharedTextureMemoryIsDeviceLost)(WGPUSharedTextureMemory sharedTextureMemory) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSharedTextureMemorySetLabel)(WGPUSharedTextureMemory sharedTextureMemory, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSharedTextureMemoryAddRef)(WGPUSharedTextureMemory sharedTextureMemory) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSharedTextureMemoryRelease)(WGPUSharedTextureMemory sharedTextureMemory) WGPU_FUNCTION_ATTRIBUTE;

// Procs of Surface
typedef void (*WGPUProcSurfaceConfigure)(WGPUSurface surface, WGPUSurfaceConfiguration const * config) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUStatus (*WGPUProcSurfaceGetCapabilities)(WGPUSurface surface, WGPUAdapter adapter, WGPUSurfaceCapabilities * capabilities) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSurfaceGetCurrentTexture)(WGPUSurface surface, WGPUSurfaceTexture * surfaceTexture) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUTextureFormat (*WGPUProcSurfaceGetPreferredFormat)(WGPUSurface surface, WGPUAdapter adapter) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSurfacePresent)(WGPUSurface surface) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSurfaceUnconfigure)(WGPUSurface surface) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSurfaceAddRef)(WGPUSurface surface) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSurfaceRelease)(WGPUSurface surface) WGPU_FUNCTION_ATTRIBUTE;

// Procs of SwapChain
typedef WGPUTexture (*WGPUProcSwapChainGetCurrentTexture)(WGPUSwapChain swapChain) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUTextureView (*WGPUProcSwapChainGetCurrentTextureView)(WGPUSwapChain swapChain) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSwapChainPresent)(WGPUSwapChain swapChain) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSwapChainAddRef)(WGPUSwapChain swapChain) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcSwapChainRelease)(WGPUSwapChain swapChain) WGPU_FUNCTION_ATTRIBUTE;

// Procs of Texture
typedef WGPUTextureView (*WGPUProcTextureCreateErrorView)(WGPUTexture texture, WGPU_NULLABLE WGPUTextureViewDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUTextureView (*WGPUProcTextureCreateView)(WGPUTexture texture, WGPU_NULLABLE WGPUTextureViewDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcTextureDestroy)(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
typedef uint32_t (*WGPUProcTextureGetDepthOrArrayLayers)(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUTextureDimension (*WGPUProcTextureGetDimension)(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUTextureFormat (*WGPUProcTextureGetFormat)(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
typedef uint32_t (*WGPUProcTextureGetHeight)(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
typedef uint32_t (*WGPUProcTextureGetMipLevelCount)(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
typedef uint32_t (*WGPUProcTextureGetSampleCount)(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
typedef WGPUTextureUsageFlags (*WGPUProcTextureGetUsage)(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
typedef uint32_t (*WGPUProcTextureGetWidth)(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcTextureSetLabel)(WGPUTexture texture, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcTextureAddRef)(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcTextureRelease)(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;

// Procs of TextureView
typedef void (*WGPUProcTextureViewSetLabel)(WGPUTextureView textureView, char const * label) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcTextureViewAddRef)(WGPUTextureView textureView) WGPU_FUNCTION_ATTRIBUTE;
typedef void (*WGPUProcTextureViewRelease)(WGPUTextureView textureView) WGPU_FUNCTION_ATTRIBUTE;


#endif  // !defined(WGPU_SKIP_PROCS)

#if !defined(WGPU_SKIP_DECLARATIONS)

WGPU_EXPORT void wgpuAdapterInfoFreeMembers(WGPUAdapterInfo value) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuAdapterPropertiesFreeMembers(WGPUAdapterProperties value) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuAdapterPropertiesMemoryHeapsFreeMembers(WGPUAdapterPropertiesMemoryHeaps value) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUInstance wgpuCreateInstance(WGPU_NULLABLE WGPUInstanceDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDrmFormatCapabilitiesFreeMembers(WGPUDrmFormatCapabilities value) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuGetInstanceFeatures(WGPUInstanceFeatures * features) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUProc wgpuGetProcAddress(WGPU_NULLABLE WGPUDevice device, char const * procName) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSharedBufferMemoryEndAccessStateFreeMembers(WGPUSharedBufferMemoryEndAccessState value) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSharedTextureMemoryEndAccessStateFreeMembers(WGPUSharedTextureMemoryEndAccessState value) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSurfaceCapabilitiesFreeMembers(WGPUSurfaceCapabilities value) WGPU_FUNCTION_ATTRIBUTE;

// Methods of Adapter
WGPU_EXPORT WGPUDevice wgpuAdapterCreateDevice(WGPUAdapter adapter, WGPU_NULLABLE WGPUDeviceDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT size_t wgpuAdapterEnumerateFeatures(WGPUAdapter adapter, WGPUFeatureName * features) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuAdapterGetFormatCapabilities(WGPUAdapter adapter, WGPUTextureFormat format, WGPUFormatCapabilities * capabilities) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuAdapterGetInfo(WGPUAdapter adapter, WGPUAdapterInfo * info) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUInstance wgpuAdapterGetInstance(WGPUAdapter adapter) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuAdapterGetLimits(WGPUAdapter adapter, WGPUSupportedLimits * limits) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuAdapterGetProperties(WGPUAdapter adapter, WGPUAdapterProperties * properties) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUBool wgpuAdapterHasFeature(WGPUAdapter adapter, WGPUFeatureName feature) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuAdapterRequestDevice(WGPUAdapter adapter, WGPU_NULLABLE WGPUDeviceDescriptor const * descriptor, WGPURequestDeviceCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuAdapterRequestDevice2(WGPUAdapter adapter, WGPU_NULLABLE WGPUDeviceDescriptor const * options, WGPURequestDeviceCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuAdapterRequestDeviceF(WGPUAdapter adapter, WGPU_NULLABLE WGPUDeviceDescriptor const * options, WGPURequestDeviceCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuAdapterAddRef(WGPUAdapter adapter) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuAdapterRelease(WGPUAdapter adapter) WGPU_FUNCTION_ATTRIBUTE;

// Methods of BindGroup
WGPU_EXPORT void wgpuBindGroupSetLabel(WGPUBindGroup bindGroup, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuBindGroupAddRef(WGPUBindGroup bindGroup) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuBindGroupRelease(WGPUBindGroup bindGroup) WGPU_FUNCTION_ATTRIBUTE;

// Methods of BindGroupLayout
WGPU_EXPORT void wgpuBindGroupLayoutSetLabel(WGPUBindGroupLayout bindGroupLayout, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuBindGroupLayoutAddRef(WGPUBindGroupLayout bindGroupLayout) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuBindGroupLayoutRelease(WGPUBindGroupLayout bindGroupLayout) WGPU_FUNCTION_ATTRIBUTE;

// Methods of Buffer
WGPU_EXPORT void wgpuBufferDestroy(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void const * wgpuBufferGetConstMappedRange(WGPUBuffer buffer, size_t offset, size_t size) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUBufferMapState wgpuBufferGetMapState(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void * wgpuBufferGetMappedRange(WGPUBuffer buffer, size_t offset, size_t size) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT uint64_t wgpuBufferGetSize(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUBufferUsageFlags wgpuBufferGetUsage(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuBufferMapAsync(WGPUBuffer buffer, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuBufferMapAsync2(WGPUBuffer buffer, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuBufferMapAsyncF(WGPUBuffer buffer, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuBufferSetLabel(WGPUBuffer buffer, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuBufferUnmap(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuBufferAddRef(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuBufferRelease(WGPUBuffer buffer) WGPU_FUNCTION_ATTRIBUTE;

// Methods of CommandBuffer
WGPU_EXPORT void wgpuCommandBufferSetLabel(WGPUCommandBuffer commandBuffer, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandBufferAddRef(WGPUCommandBuffer commandBuffer) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandBufferRelease(WGPUCommandBuffer commandBuffer) WGPU_FUNCTION_ATTRIBUTE;

// Methods of CommandEncoder
WGPU_EXPORT WGPUComputePassEncoder wgpuCommandEncoderBeginComputePass(WGPUCommandEncoder commandEncoder, WGPU_NULLABLE WGPUComputePassDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPURenderPassEncoder wgpuCommandEncoderBeginRenderPass(WGPUCommandEncoder commandEncoder, WGPURenderPassDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderClearBuffer(WGPUCommandEncoder commandEncoder, WGPUBuffer buffer, uint64_t offset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderCopyBufferToBuffer(WGPUCommandEncoder commandEncoder, WGPUBuffer source, uint64_t sourceOffset, WGPUBuffer destination, uint64_t destinationOffset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderCopyBufferToTexture(WGPUCommandEncoder commandEncoder, WGPUImageCopyBuffer const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderCopyTextureToBuffer(WGPUCommandEncoder commandEncoder, WGPUImageCopyTexture const * source, WGPUImageCopyBuffer const * destination, WGPUExtent3D const * copySize) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderCopyTextureToTexture(WGPUCommandEncoder commandEncoder, WGPUImageCopyTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUCommandBuffer wgpuCommandEncoderFinish(WGPUCommandEncoder commandEncoder, WGPU_NULLABLE WGPUCommandBufferDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderInjectValidationError(WGPUCommandEncoder commandEncoder, char const * message) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderInsertDebugMarker(WGPUCommandEncoder commandEncoder, char const * markerLabel) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderPopDebugGroup(WGPUCommandEncoder commandEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderPushDebugGroup(WGPUCommandEncoder commandEncoder, char const * groupLabel) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderResolveQuerySet(WGPUCommandEncoder commandEncoder, WGPUQuerySet querySet, uint32_t firstQuery, uint32_t queryCount, WGPUBuffer destination, uint64_t destinationOffset) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderSetLabel(WGPUCommandEncoder commandEncoder, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderWriteBuffer(WGPUCommandEncoder commandEncoder, WGPUBuffer buffer, uint64_t bufferOffset, uint8_t const * data, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderWriteTimestamp(WGPUCommandEncoder commandEncoder, WGPUQuerySet querySet, uint32_t queryIndex) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderAddRef(WGPUCommandEncoder commandEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuCommandEncoderRelease(WGPUCommandEncoder commandEncoder) WGPU_FUNCTION_ATTRIBUTE;

// Methods of ComputePassEncoder
WGPU_EXPORT void wgpuComputePassEncoderDispatchWorkgroups(WGPUComputePassEncoder computePassEncoder, uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePassEncoderDispatchWorkgroupsIndirect(WGPUComputePassEncoder computePassEncoder, WGPUBuffer indirectBuffer, uint64_t indirectOffset) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePassEncoderEnd(WGPUComputePassEncoder computePassEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePassEncoderInsertDebugMarker(WGPUComputePassEncoder computePassEncoder, char const * markerLabel) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePassEncoderPopDebugGroup(WGPUComputePassEncoder computePassEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePassEncoderPushDebugGroup(WGPUComputePassEncoder computePassEncoder, char const * groupLabel) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePassEncoderSetBindGroup(WGPUComputePassEncoder computePassEncoder, uint32_t groupIndex, WGPU_NULLABLE WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePassEncoderSetLabel(WGPUComputePassEncoder computePassEncoder, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePassEncoderSetPipeline(WGPUComputePassEncoder computePassEncoder, WGPUComputePipeline pipeline) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePassEncoderWriteTimestamp(WGPUComputePassEncoder computePassEncoder, WGPUQuerySet querySet, uint32_t queryIndex) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePassEncoderAddRef(WGPUComputePassEncoder computePassEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePassEncoderRelease(WGPUComputePassEncoder computePassEncoder) WGPU_FUNCTION_ATTRIBUTE;

// Methods of ComputePipeline
WGPU_EXPORT WGPUBindGroupLayout wgpuComputePipelineGetBindGroupLayout(WGPUComputePipeline computePipeline, uint32_t groupIndex) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePipelineSetLabel(WGPUComputePipeline computePipeline, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePipelineAddRef(WGPUComputePipeline computePipeline) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuComputePipelineRelease(WGPUComputePipeline computePipeline) WGPU_FUNCTION_ATTRIBUTE;

// Methods of Device
WGPU_EXPORT WGPUBindGroup wgpuDeviceCreateBindGroup(WGPUDevice device, WGPUBindGroupDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUBindGroupLayout wgpuDeviceCreateBindGroupLayout(WGPUDevice device, WGPUBindGroupLayoutDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUBuffer wgpuDeviceCreateBuffer(WGPUDevice device, WGPUBufferDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUCommandEncoder wgpuDeviceCreateCommandEncoder(WGPUDevice device, WGPU_NULLABLE WGPUCommandEncoderDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUComputePipeline wgpuDeviceCreateComputePipeline(WGPUDevice device, WGPUComputePipelineDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceCreateComputePipelineAsync(WGPUDevice device, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuDeviceCreateComputePipelineAsync2(WGPUDevice device, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuDeviceCreateComputePipelineAsyncF(WGPUDevice device, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUBuffer wgpuDeviceCreateErrorBuffer(WGPUDevice device, WGPUBufferDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUExternalTexture wgpuDeviceCreateErrorExternalTexture(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUShaderModule wgpuDeviceCreateErrorShaderModule(WGPUDevice device, WGPUShaderModuleDescriptor const * descriptor, char const * errorMessage) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUTexture wgpuDeviceCreateErrorTexture(WGPUDevice device, WGPUTextureDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUExternalTexture wgpuDeviceCreateExternalTexture(WGPUDevice device, WGPUExternalTextureDescriptor const * externalTextureDescriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUPipelineLayout wgpuDeviceCreatePipelineLayout(WGPUDevice device, WGPUPipelineLayoutDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUQuerySet wgpuDeviceCreateQuerySet(WGPUDevice device, WGPUQuerySetDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPURenderBundleEncoder wgpuDeviceCreateRenderBundleEncoder(WGPUDevice device, WGPURenderBundleEncoderDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPURenderPipeline wgpuDeviceCreateRenderPipeline(WGPUDevice device, WGPURenderPipelineDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceCreateRenderPipelineAsync(WGPUDevice device, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuDeviceCreateRenderPipelineAsync2(WGPUDevice device, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuDeviceCreateRenderPipelineAsyncF(WGPUDevice device, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUSampler wgpuDeviceCreateSampler(WGPUDevice device, WGPU_NULLABLE WGPUSamplerDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUShaderModule wgpuDeviceCreateShaderModule(WGPUDevice device, WGPUShaderModuleDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUSwapChain wgpuDeviceCreateSwapChain(WGPUDevice device, WGPUSurface surface, WGPUSwapChainDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUTexture wgpuDeviceCreateTexture(WGPUDevice device, WGPUTextureDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceDestroy(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT size_t wgpuDeviceEnumerateFeatures(WGPUDevice device, WGPUFeatureName * features) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceForceLoss(WGPUDevice device, WGPUDeviceLostReason type, char const * message) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuDeviceGetAHardwareBufferProperties(WGPUDevice device, void * handle, WGPUAHardwareBufferProperties * properties) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUAdapter wgpuDeviceGetAdapter(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuDeviceGetLimits(WGPUDevice device, WGPUSupportedLimits * limits) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUQueue wgpuDeviceGetQueue(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUTextureUsageFlags wgpuDeviceGetSupportedSurfaceUsage(WGPUDevice device, WGPUSurface surface) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUBool wgpuDeviceHasFeature(WGPUDevice device, WGPUFeatureName feature) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUSharedBufferMemory wgpuDeviceImportSharedBufferMemory(WGPUDevice device, WGPUSharedBufferMemoryDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUSharedFence wgpuDeviceImportSharedFence(WGPUDevice device, WGPUSharedFenceDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUSharedTextureMemory wgpuDeviceImportSharedTextureMemory(WGPUDevice device, WGPUSharedTextureMemoryDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceInjectError(WGPUDevice device, WGPUErrorType type, char const * message) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDevicePopErrorScope(WGPUDevice device, WGPUErrorCallback oldCallback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuDevicePopErrorScope2(WGPUDevice device, WGPUPopErrorScopeCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuDevicePopErrorScopeF(WGPUDevice device, WGPUPopErrorScopeCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDevicePushErrorScope(WGPUDevice device, WGPUErrorFilter filter) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceSetDeviceLostCallback(WGPUDevice device, WGPUDeviceLostCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceSetLabel(WGPUDevice device, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceSetLoggingCallback(WGPUDevice device, WGPULoggingCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceSetUncapturedErrorCallback(WGPUDevice device, WGPUErrorCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceTick(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceValidateTextureDescriptor(WGPUDevice device, WGPUTextureDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceAddRef(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuDeviceRelease(WGPUDevice device) WGPU_FUNCTION_ATTRIBUTE;

// Methods of ExternalTexture
WGPU_EXPORT void wgpuExternalTextureDestroy(WGPUExternalTexture externalTexture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuExternalTextureExpire(WGPUExternalTexture externalTexture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuExternalTextureRefresh(WGPUExternalTexture externalTexture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuExternalTextureSetLabel(WGPUExternalTexture externalTexture, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuExternalTextureAddRef(WGPUExternalTexture externalTexture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuExternalTextureRelease(WGPUExternalTexture externalTexture) WGPU_FUNCTION_ATTRIBUTE;

// Methods of Instance
WGPU_EXPORT WGPUSurface wgpuInstanceCreateSurface(WGPUInstance instance, WGPUSurfaceDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT size_t wgpuInstanceEnumerateWGSLLanguageFeatures(WGPUInstance instance, WGPUWGSLFeatureName * features) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUBool wgpuInstanceHasWGSLLanguageFeature(WGPUInstance instance, WGPUWGSLFeatureName feature) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuInstanceProcessEvents(WGPUInstance instance) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuInstanceRequestAdapter(WGPUInstance instance, WGPU_NULLABLE WGPURequestAdapterOptions const * options, WGPURequestAdapterCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuInstanceRequestAdapter2(WGPUInstance instance, WGPU_NULLABLE WGPURequestAdapterOptions const * options, WGPURequestAdapterCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuInstanceRequestAdapterF(WGPUInstance instance, WGPU_NULLABLE WGPURequestAdapterOptions const * options, WGPURequestAdapterCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUWaitStatus wgpuInstanceWaitAny(WGPUInstance instance, size_t futureCount, WGPUFutureWaitInfo * futures, uint64_t timeoutNS) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuInstanceAddRef(WGPUInstance instance) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuInstanceRelease(WGPUInstance instance) WGPU_FUNCTION_ATTRIBUTE;

// Methods of PipelineLayout
WGPU_EXPORT void wgpuPipelineLayoutSetLabel(WGPUPipelineLayout pipelineLayout, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuPipelineLayoutAddRef(WGPUPipelineLayout pipelineLayout) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuPipelineLayoutRelease(WGPUPipelineLayout pipelineLayout) WGPU_FUNCTION_ATTRIBUTE;

// Methods of QuerySet
WGPU_EXPORT void wgpuQuerySetDestroy(WGPUQuerySet querySet) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT uint32_t wgpuQuerySetGetCount(WGPUQuerySet querySet) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUQueryType wgpuQuerySetGetType(WGPUQuerySet querySet) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuQuerySetSetLabel(WGPUQuerySet querySet, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuQuerySetAddRef(WGPUQuerySet querySet) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuQuerySetRelease(WGPUQuerySet querySet) WGPU_FUNCTION_ATTRIBUTE;

// Methods of Queue
WGPU_EXPORT void wgpuQueueCopyExternalTextureForBrowser(WGPUQueue queue, WGPUImageCopyExternalTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize, WGPUCopyTextureForBrowserOptions const * options) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuQueueCopyTextureForBrowser(WGPUQueue queue, WGPUImageCopyTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize, WGPUCopyTextureForBrowserOptions const * options) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuQueueOnSubmittedWorkDone(WGPUQueue queue, WGPUQueueWorkDoneCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuQueueOnSubmittedWorkDone2(WGPUQueue queue, WGPUQueueWorkDoneCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuQueueOnSubmittedWorkDoneF(WGPUQueue queue, WGPUQueueWorkDoneCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuQueueSetLabel(WGPUQueue queue, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuQueueSubmit(WGPUQueue queue, size_t commandCount, WGPUCommandBuffer const * commands) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuQueueWriteBuffer(WGPUQueue queue, WGPUBuffer buffer, uint64_t bufferOffset, void const * data, size_t size) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuQueueWriteTexture(WGPUQueue queue, WGPUImageCopyTexture const * destination, void const * data, size_t dataSize, WGPUTextureDataLayout const * dataLayout, WGPUExtent3D const * writeSize) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuQueueAddRef(WGPUQueue queue) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuQueueRelease(WGPUQueue queue) WGPU_FUNCTION_ATTRIBUTE;

// Methods of RenderBundle
WGPU_EXPORT void wgpuRenderBundleSetLabel(WGPURenderBundle renderBundle, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleAddRef(WGPURenderBundle renderBundle) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleRelease(WGPURenderBundle renderBundle) WGPU_FUNCTION_ATTRIBUTE;

// Methods of RenderBundleEncoder
WGPU_EXPORT void wgpuRenderBundleEncoderDraw(WGPURenderBundleEncoder renderBundleEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderDrawIndexed(WGPURenderBundleEncoder renderBundleEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderDrawIndexedIndirect(WGPURenderBundleEncoder renderBundleEncoder, WGPUBuffer indirectBuffer, uint64_t indirectOffset) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderDrawIndirect(WGPURenderBundleEncoder renderBundleEncoder, WGPUBuffer indirectBuffer, uint64_t indirectOffset) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPURenderBundle wgpuRenderBundleEncoderFinish(WGPURenderBundleEncoder renderBundleEncoder, WGPU_NULLABLE WGPURenderBundleDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderInsertDebugMarker(WGPURenderBundleEncoder renderBundleEncoder, char const * markerLabel) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderPopDebugGroup(WGPURenderBundleEncoder renderBundleEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderPushDebugGroup(WGPURenderBundleEncoder renderBundleEncoder, char const * groupLabel) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderSetBindGroup(WGPURenderBundleEncoder renderBundleEncoder, uint32_t groupIndex, WGPU_NULLABLE WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderSetIndexBuffer(WGPURenderBundleEncoder renderBundleEncoder, WGPUBuffer buffer, WGPUIndexFormat format, uint64_t offset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderSetLabel(WGPURenderBundleEncoder renderBundleEncoder, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderSetPipeline(WGPURenderBundleEncoder renderBundleEncoder, WGPURenderPipeline pipeline) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderSetVertexBuffer(WGPURenderBundleEncoder renderBundleEncoder, uint32_t slot, WGPU_NULLABLE WGPUBuffer buffer, uint64_t offset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderAddRef(WGPURenderBundleEncoder renderBundleEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderBundleEncoderRelease(WGPURenderBundleEncoder renderBundleEncoder) WGPU_FUNCTION_ATTRIBUTE;

// Methods of RenderPassEncoder
WGPU_EXPORT void wgpuRenderPassEncoderBeginOcclusionQuery(WGPURenderPassEncoder renderPassEncoder, uint32_t queryIndex) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderDraw(WGPURenderPassEncoder renderPassEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderDrawIndexed(WGPURenderPassEncoder renderPassEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderDrawIndexedIndirect(WGPURenderPassEncoder renderPassEncoder, WGPUBuffer indirectBuffer, uint64_t indirectOffset) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderDrawIndirect(WGPURenderPassEncoder renderPassEncoder, WGPUBuffer indirectBuffer, uint64_t indirectOffset) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderEnd(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderEndOcclusionQuery(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderExecuteBundles(WGPURenderPassEncoder renderPassEncoder, size_t bundleCount, WGPURenderBundle const * bundles) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderInsertDebugMarker(WGPURenderPassEncoder renderPassEncoder, char const * markerLabel) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderPixelLocalStorageBarrier(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderPopDebugGroup(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderPushDebugGroup(WGPURenderPassEncoder renderPassEncoder, char const * groupLabel) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderSetBindGroup(WGPURenderPassEncoder renderPassEncoder, uint32_t groupIndex, WGPU_NULLABLE WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderSetBlendConstant(WGPURenderPassEncoder renderPassEncoder, WGPUColor const * color) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderSetIndexBuffer(WGPURenderPassEncoder renderPassEncoder, WGPUBuffer buffer, WGPUIndexFormat format, uint64_t offset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderSetLabel(WGPURenderPassEncoder renderPassEncoder, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderSetPipeline(WGPURenderPassEncoder renderPassEncoder, WGPURenderPipeline pipeline) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderSetScissorRect(WGPURenderPassEncoder renderPassEncoder, uint32_t x, uint32_t y, uint32_t width, uint32_t height) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderSetStencilReference(WGPURenderPassEncoder renderPassEncoder, uint32_t reference) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderSetVertexBuffer(WGPURenderPassEncoder renderPassEncoder, uint32_t slot, WGPU_NULLABLE WGPUBuffer buffer, uint64_t offset, uint64_t size) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderSetViewport(WGPURenderPassEncoder renderPassEncoder, float x, float y, float width, float height, float minDepth, float maxDepth) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderWriteTimestamp(WGPURenderPassEncoder renderPassEncoder, WGPUQuerySet querySet, uint32_t queryIndex) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderAddRef(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPassEncoderRelease(WGPURenderPassEncoder renderPassEncoder) WGPU_FUNCTION_ATTRIBUTE;

// Methods of RenderPipeline
WGPU_EXPORT WGPUBindGroupLayout wgpuRenderPipelineGetBindGroupLayout(WGPURenderPipeline renderPipeline, uint32_t groupIndex) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPipelineSetLabel(WGPURenderPipeline renderPipeline, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPipelineAddRef(WGPURenderPipeline renderPipeline) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuRenderPipelineRelease(WGPURenderPipeline renderPipeline) WGPU_FUNCTION_ATTRIBUTE;

// Methods of Sampler
WGPU_EXPORT void wgpuSamplerSetLabel(WGPUSampler sampler, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSamplerAddRef(WGPUSampler sampler) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSamplerRelease(WGPUSampler sampler) WGPU_FUNCTION_ATTRIBUTE;

// Methods of ShaderModule
WGPU_EXPORT void wgpuShaderModuleGetCompilationInfo(WGPUShaderModule shaderModule, WGPUCompilationInfoCallback callback, void * userdata) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuShaderModuleGetCompilationInfo2(WGPUShaderModule shaderModule, WGPUCompilationInfoCallbackInfo2 callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUFuture wgpuShaderModuleGetCompilationInfoF(WGPUShaderModule shaderModule, WGPUCompilationInfoCallbackInfo callbackInfo) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuShaderModuleSetLabel(WGPUShaderModule shaderModule, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuShaderModuleAddRef(WGPUShaderModule shaderModule) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuShaderModuleRelease(WGPUShaderModule shaderModule) WGPU_FUNCTION_ATTRIBUTE;

// Methods of SharedBufferMemory
WGPU_EXPORT WGPUStatus wgpuSharedBufferMemoryBeginAccess(WGPUSharedBufferMemory sharedBufferMemory, WGPUBuffer buffer, WGPUSharedBufferMemoryBeginAccessDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUBuffer wgpuSharedBufferMemoryCreateBuffer(WGPUSharedBufferMemory sharedBufferMemory, WGPU_NULLABLE WGPUBufferDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuSharedBufferMemoryEndAccess(WGPUSharedBufferMemory sharedBufferMemory, WGPUBuffer buffer, WGPUSharedBufferMemoryEndAccessState * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuSharedBufferMemoryGetProperties(WGPUSharedBufferMemory sharedBufferMemory, WGPUSharedBufferMemoryProperties * properties) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUBool wgpuSharedBufferMemoryIsDeviceLost(WGPUSharedBufferMemory sharedBufferMemory) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSharedBufferMemorySetLabel(WGPUSharedBufferMemory sharedBufferMemory, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSharedBufferMemoryAddRef(WGPUSharedBufferMemory sharedBufferMemory) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSharedBufferMemoryRelease(WGPUSharedBufferMemory sharedBufferMemory) WGPU_FUNCTION_ATTRIBUTE;

// Methods of SharedFence
WGPU_EXPORT void wgpuSharedFenceExportInfo(WGPUSharedFence sharedFence, WGPUSharedFenceExportInfo * info) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSharedFenceAddRef(WGPUSharedFence sharedFence) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSharedFenceRelease(WGPUSharedFence sharedFence) WGPU_FUNCTION_ATTRIBUTE;

// Methods of SharedTextureMemory
WGPU_EXPORT WGPUStatus wgpuSharedTextureMemoryBeginAccess(WGPUSharedTextureMemory sharedTextureMemory, WGPUTexture texture, WGPUSharedTextureMemoryBeginAccessDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUTexture wgpuSharedTextureMemoryCreateTexture(WGPUSharedTextureMemory sharedTextureMemory, WGPU_NULLABLE WGPUTextureDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuSharedTextureMemoryEndAccess(WGPUSharedTextureMemory sharedTextureMemory, WGPUTexture texture, WGPUSharedTextureMemoryEndAccessState * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuSharedTextureMemoryGetProperties(WGPUSharedTextureMemory sharedTextureMemory, WGPUSharedTextureMemoryProperties * properties) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUBool wgpuSharedTextureMemoryIsDeviceLost(WGPUSharedTextureMemory sharedTextureMemory) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSharedTextureMemorySetLabel(WGPUSharedTextureMemory sharedTextureMemory, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSharedTextureMemoryAddRef(WGPUSharedTextureMemory sharedTextureMemory) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSharedTextureMemoryRelease(WGPUSharedTextureMemory sharedTextureMemory) WGPU_FUNCTION_ATTRIBUTE;

// Methods of Surface
WGPU_EXPORT void wgpuSurfaceConfigure(WGPUSurface surface, WGPUSurfaceConfiguration const * config) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUStatus wgpuSurfaceGetCapabilities(WGPUSurface surface, WGPUAdapter adapter, WGPUSurfaceCapabilities * capabilities) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSurfaceGetCurrentTexture(WGPUSurface surface, WGPUSurfaceTexture * surfaceTexture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUTextureFormat wgpuSurfaceGetPreferredFormat(WGPUSurface surface, WGPUAdapter adapter) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSurfacePresent(WGPUSurface surface) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSurfaceUnconfigure(WGPUSurface surface) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSurfaceAddRef(WGPUSurface surface) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSurfaceRelease(WGPUSurface surface) WGPU_FUNCTION_ATTRIBUTE;

// Methods of SwapChain
WGPU_EXPORT WGPUTexture wgpuSwapChainGetCurrentTexture(WGPUSwapChain swapChain) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUTextureView wgpuSwapChainGetCurrentTextureView(WGPUSwapChain swapChain) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSwapChainPresent(WGPUSwapChain swapChain) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSwapChainAddRef(WGPUSwapChain swapChain) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuSwapChainRelease(WGPUSwapChain swapChain) WGPU_FUNCTION_ATTRIBUTE;

// Methods of Texture
WGPU_EXPORT WGPUTextureView wgpuTextureCreateErrorView(WGPUTexture texture, WGPU_NULLABLE WGPUTextureViewDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUTextureView wgpuTextureCreateView(WGPUTexture texture, WGPU_NULLABLE WGPUTextureViewDescriptor const * descriptor) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuTextureDestroy(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT uint32_t wgpuTextureGetDepthOrArrayLayers(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUTextureDimension wgpuTextureGetDimension(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUTextureFormat wgpuTextureGetFormat(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT uint32_t wgpuTextureGetHeight(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT uint32_t wgpuTextureGetMipLevelCount(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT uint32_t wgpuTextureGetSampleCount(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT WGPUTextureUsageFlags wgpuTextureGetUsage(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT uint32_t wgpuTextureGetWidth(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuTextureSetLabel(WGPUTexture texture, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuTextureAddRef(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuTextureRelease(WGPUTexture texture) WGPU_FUNCTION_ATTRIBUTE;

// Methods of TextureView
WGPU_EXPORT void wgpuTextureViewSetLabel(WGPUTextureView textureView, char const * label) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuTextureViewAddRef(WGPUTextureView textureView) WGPU_FUNCTION_ATTRIBUTE;
WGPU_EXPORT void wgpuTextureViewRelease(WGPUTextureView textureView) WGPU_FUNCTION_ATTRIBUTE;


#endif  // !defined(WGPU_SKIP_DECLARATIONS)

#ifdef __cplusplus
} // extern "C"
#endif

#endif // WEBGPU_H_
