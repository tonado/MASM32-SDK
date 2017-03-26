; --------------------------------------------------------------------------------------------------
;                           rpcrt4.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RPCRT4_INC
RPCRT4_INC equ <1>

CStdStubBuffer_AddRef PROTO STDCALL :DWORD
CStdStubBuffer_Connect PROTO STDCALL :DWORD,:DWORD
CStdStubBuffer_CountRefs PROTO STDCALL :DWORD
CStdStubBuffer_DebugServerQueryInterface PROTO STDCALL :DWORD,:DWORD
CStdStubBuffer_DebugServerRelease PROTO STDCALL :DWORD,:DWORD
CStdStubBuffer_Disconnect PROTO STDCALL :DWORD
CStdStubBuffer_Invoke PROTO STDCALL :DWORD,:DWORD,:DWORD
CStdStubBuffer_IsIIDSupported PROTO STDCALL :DWORD,:DWORD
CStdStubBuffer_QueryInterface PROTO STDCALL :DWORD,:DWORD,:DWORD
CheckVerificationTrailer PROTO STDCALL :DWORD,:DWORD,:DWORD

DceErrorInqTextA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DceErrorInqText equ <DceErrorInqTextA>
ENDIF

DceErrorInqTextW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DceErrorInqText equ <DceErrorInqTextW>
ENDIF

GlobalMutexClearExternal PROTO STDCALL
GlobalMutexRequestExternal PROTO STDCALL
IUnknown_AddRef_Proxy PROTO STDCALL :DWORD
IUnknown_QueryInterface_Proxy PROTO STDCALL :DWORD,:DWORD,:DWORD
IUnknown_Release_Proxy PROTO STDCALL :DWORD
I_RpcAbortAsyncCall PROTO STDCALL :DWORD,:DWORD
I_RpcAllocate PROTO STDCALL :DWORD
I_RpcAsyncAbortCall PROTO STDCALL :DWORD,:DWORD
I_RpcAsyncSetHandle PROTO STDCALL :DWORD,:DWORD
I_RpcBCacheAllocate PROTO STDCALL :DWORD
I_RpcBCacheFree PROTO STDCALL :DWORD
I_RpcBindingCopy PROTO STDCALL :DWORD,:DWORD
I_RpcBindingHandleToAsyncHandle PROTO STDCALL :DWORD,:DWORD
I_RpcBindingInqConnId PROTO STDCALL :DWORD,:DWORD,:DWORD

I_RpcBindingInqDynamicEndpointA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  I_RpcBindingInqDynamicEndpoint equ <I_RpcBindingInqDynamicEndpointA>
ENDIF

I_RpcBindingInqDynamicEndpointW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  I_RpcBindingInqDynamicEndpoint equ <I_RpcBindingInqDynamicEndpointW>
ENDIF

I_RpcBindingInqLocalClientPID PROTO STDCALL :DWORD,:DWORD
I_RpcBindingInqSecurityContext PROTO STDCALL :DWORD,:DWORD
I_RpcBindingInqTransportType PROTO STDCALL :DWORD,:DWORD
I_RpcBindingInqWireIdForSnego PROTO STDCALL :DWORD,:DWORD
I_RpcBindingIsClientLocal PROTO STDCALL :DWORD,:DWORD

I_RpcBindingToStaticStringBindingW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  I_RpcBindingToStaticStringBinding equ <I_RpcBindingToStaticStringBindingW>
ENDIF

I_RpcClearMutex PROTO STDCALL :DWORD
I_RpcConnectionInqSockBuffSize PROTO STDCALL :DWORD,:DWORD
I_RpcConnectionSetSockBuffSize PROTO STDCALL :DWORD,:DWORD
I_RpcDeleteMutex PROTO STDCALL :DWORD
I_RpcEnableWmiTrace PROTO STDCALL :DWORD,:DWORD
I_RpcExceptionFilter PROTO STDCALL :DWORD
I_RpcFree PROTO STDCALL :DWORD
I_RpcFreeBuffer PROTO STDCALL :DWORD
I_RpcFreePipeBuffer PROTO STDCALL :DWORD
I_RpcGetBuffer PROTO STDCALL :DWORD
I_RpcGetBufferWithObject PROTO STDCALL :DWORD,:DWORD
I_RpcGetCurrentCallHandle PROTO STDCALL
I_RpcGetExtendedError PROTO STDCALL
I_RpcIfInqTransferSyntaxes PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
I_RpcLogEvent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_RpcMapWin32Status PROTO STDCALL :DWORD
I_RpcNegotiateTransferSyntax PROTO STDCALL :DWORD

I_RpcNsBindingSetEntryNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  I_RpcNsBindingSetEntryName equ <I_RpcNsBindingSetEntryNameA>
ENDIF

I_RpcNsBindingSetEntryNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  I_RpcNsBindingSetEntryName equ <I_RpcNsBindingSetEntryNameW>
ENDIF

I_RpcNsInterfaceExported PROTO STDCALL :DWORD,:DWORD,:DWORD
I_RpcNsInterfaceUnexported PROTO STDCALL :DWORD,:DWORD,:DWORD
I_RpcParseSecurity PROTO STDCALL :DWORD,:DWORD
I_RpcPauseExecution PROTO STDCALL :DWORD
I_RpcReallocPipeBuffer PROTO STDCALL :DWORD,:DWORD
I_RpcReceive PROTO STDCALL :DWORD,:DWORD
I_RpcRequestMutex PROTO STDCALL :DWORD
I_RpcSend PROTO STDCALL :DWORD
I_RpcSendReceive PROTO STDCALL :DWORD
I_RpcServerAllocateIpPort PROTO STDCALL :DWORD,:DWORD
I_RpcServerCheckClientRestriction PROTO STDCALL :DWORD
I_RpcServerInqAddressChangeFn PROTO STDCALL
I_RpcServerInqLocalConnAddress PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
I_RpcServerInqTransportType PROTO STDCALL :DWORD
I_RpcServerRegisterForwardFunction PROTO STDCALL :DWORD
I_RpcServerSetAddressChangeFn PROTO STDCALL :DWORD

I_RpcServerUseProtseq2A PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  I_RpcServerUseProtseq2 equ <I_RpcServerUseProtseq2A>
ENDIF

I_RpcServerUseProtseq2W PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  I_RpcServerUseProtseq2 equ <I_RpcServerUseProtseq2W>
ENDIF

I_RpcServerUseProtseqEp2A PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  I_RpcServerUseProtseqEp2 equ <I_RpcServerUseProtseqEp2A>
ENDIF

I_RpcServerUseProtseqEp2W PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  I_RpcServerUseProtseqEp2 equ <I_RpcServerUseProtseqEp2W>
ENDIF

I_RpcSessionStrictContextHandle PROTO STDCALL
I_RpcSetAsyncHandle PROTO STDCALL :DWORD,:DWORD
I_RpcSsDontSerializeContext PROTO STDCALL
I_RpcSystemFunction001 PROTO STDCALL :DWORD,:DWORD,:DWORD
I_RpcTransConnectionAllocatePacket PROTO STDCALL :DWORD,:DWORD
I_RpcTransConnectionFreePacket PROTO STDCALL :DWORD,:DWORD
I_RpcTransConnectionReallocPacket PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
I_RpcTransDatagramAllocate2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
I_RpcTransDatagramAllocate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
I_RpcTransDatagramFree PROTO STDCALL :DWORD,:DWORD
I_RpcTransGetThreadEvent PROTO STDCALL
I_RpcTransIoCancelled PROTO STDCALL :DWORD,:DWORD
I_RpcTransServerNewConnection PROTO STDCALL :DWORD
I_RpcTurnOnEEInfoPropagation PROTO STDCALL
I_UuidCreate PROTO STDCALL :DWORD
MesBufferHandleReset PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MesDecodeBufferHandleCreate PROTO STDCALL :DWORD,:DWORD,:DWORD
MesDecodeIncrementalHandleCreate PROTO STDCALL :DWORD,:DWORD,:DWORD
MesEncodeDynBufferHandleCreate PROTO STDCALL :DWORD,:DWORD,:DWORD
MesEncodeFixedBufferHandleCreate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
MesEncodeIncrementalHandleCreate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
MesHandleFree PROTO STDCALL :DWORD
MesIncrementalHandleReset PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MesInqProcEncodingId PROTO STDCALL :DWORD,:DWORD,:DWORD
NDRCContextBinding PROTO STDCALL :DWORD
NDRCContextMarshall PROTO STDCALL :DWORD,:DWORD
NDRCContextUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NDRSContextMarshall2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDRSContextMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NDRSContextMarshallEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NDRSContextUnmarshall2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDRSContextUnmarshall PROTO STDCALL :DWORD,:DWORD
NDRSContextUnmarshallEx PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrAllocate PROTO STDCALL :DWORD,:DWORD
NdrAsyncClientCall PROTO C :VARARG
NdrAsyncServerCall PROTO STDCALL :DWORD
NdrByteCountPointerBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrByteCountPointerFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrByteCountPointerMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrByteCountPointerUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrCStdStubBuffer2_Release PROTO STDCALL :DWORD,:DWORD
NdrCStdStubBuffer_Release PROTO STDCALL :DWORD,:DWORD
NdrClearOutParameters PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrClientCall PROTO C :VARARG
NdrClientCall2 PROTO C :VARARG
NdrClientContextMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrClientContextUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrClientInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrClientInitializeNew PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrComplexArrayBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrComplexArrayFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrComplexArrayMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrComplexArrayMemorySize PROTO STDCALL :DWORD,:DWORD
NdrComplexArrayUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrComplexStructBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrComplexStructFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrComplexStructMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrComplexStructMemorySize PROTO STDCALL :DWORD,:DWORD
NdrComplexStructUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantArrayBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantArrayFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantArrayMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantArrayMemorySize PROTO STDCALL :DWORD,:DWORD
NdrConformantArrayUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantStringBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantStringMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantStringMemorySize PROTO STDCALL :DWORD,:DWORD
NdrConformantStringUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantStructBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantStructFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantStructMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantStructMemorySize PROTO STDCALL :DWORD,:DWORD
NdrConformantStructUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantVaryingArrayBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantVaryingArrayFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantVaryingArrayMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantVaryingArrayMemorySize PROTO STDCALL :DWORD,:DWORD
NdrConformantVaryingArrayUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantVaryingStructBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantVaryingStructFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantVaryingStructMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConformantVaryingStructMemorySize PROTO STDCALL :DWORD,:DWORD
NdrConformantVaryingStructUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrContextHandleInitialize PROTO STDCALL :DWORD,:DWORD
NdrContextHandleSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConvert2 PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrConvert PROTO STDCALL :DWORD,:DWORD
NdrCorrelationFree PROTO STDCALL :DWORD
NdrCorrelationInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrCorrelationPass PROTO STDCALL :DWORD
NdrCreateServerInterfaceFromStub PROTO STDCALL :DWORD,:DWORD
NdrDcomAsyncClientCall PROTO C :VARARG
NdrDcomAsyncStubCall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrDllCanUnloadNow PROTO STDCALL :DWORD
NdrDllGetClassObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrDllRegisterProxy PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrDllUnregisterProxy PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrEncapsulatedUnionBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrEncapsulatedUnionFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrEncapsulatedUnionMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrEncapsulatedUnionMemorySize PROTO STDCALL :DWORD,:DWORD
NdrEncapsulatedUnionUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrFixedArrayBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrFixedArrayFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrFixedArrayMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrFixedArrayMemorySize PROTO STDCALL :DWORD,:DWORD
NdrFixedArrayUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrFreeBuffer PROTO STDCALL :DWORD
NdrFullPointerFree PROTO STDCALL :DWORD,:DWORD
NdrFullPointerInsertRefId PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrFullPointerQueryPointer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrFullPointerQueryRefId PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrFullPointerXlatFree PROTO STDCALL :DWORD
NdrFullPointerXlatInit PROTO STDCALL :DWORD,:DWORD
NdrGetBuffer PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrGetDcomProtocolVersion PROTO STDCALL :DWORD,:DWORD
NdrGetSimpleTypeBufferAlignment PROTO STDCALL :DWORD
NdrGetSimpleTypeBufferSize PROTO STDCALL :DWORD
NdrGetSimpleTypeMemorySize PROTO STDCALL :DWORD
NdrGetTypeFlags PROTO STDCALL :DWORD
NdrGetUserMarshalInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrInterfacePointerBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrInterfacePointerFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrInterfacePointerMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrInterfacePointerMemorySize PROTO STDCALL :DWORD,:DWORD
NdrInterfacePointerUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrMapCommAndFaultStatus PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrMesProcEncodeDecode PROTO C :VARARG
NdrMesProcEncodeDecode2 PROTO C :VARARG
NdrMesSimpleTypeAlignSize PROTO STDCALL :DWORD
NdrMesSimpleTypeDecode PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrMesSimpleTypeEncode PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrMesTypeAlignSize2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrMesTypeAlignSize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrMesTypeDecode2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrMesTypeDecode PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrMesTypeEncode2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrMesTypeEncode PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrMesTypeFree2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrNonConformantStringBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrNonConformantStringMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrNonConformantStringMemorySize PROTO STDCALL :DWORD,:DWORD
NdrNonConformantStringUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrNonEncapsulatedUnionBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrNonEncapsulatedUnionFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrNonEncapsulatedUnionMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrNonEncapsulatedUnionMemorySize PROTO STDCALL :DWORD,:DWORD
NdrNonEncapsulatedUnionUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrNsGetBuffer PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrNsSendReceive PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrOleAllocate PROTO STDCALL :DWORD
NdrOleFree PROTO STDCALL :DWORD
NdrOutInit PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrPartialIgnoreClientBufferSize PROTO STDCALL :DWORD,:DWORD
NdrPartialIgnoreClientMarshall PROTO STDCALL :DWORD,:DWORD
NdrPartialIgnoreServerInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrPartialIgnoreServerUnmarshall PROTO STDCALL :DWORD,:DWORD
NdrPointerBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrPointerFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrPointerMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrPointerMemorySize PROTO STDCALL :DWORD,:DWORD
NdrPointerUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrProxyErrorHandler PROTO STDCALL :DWORD
NdrProxyFreeBuffer PROTO STDCALL :DWORD,:DWORD
NdrProxyGetBuffer PROTO STDCALL :DWORD,:DWORD
NdrProxyInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrProxySendReceive PROTO STDCALL :DWORD,:DWORD
NdrRangeUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrRpcSmClientAllocate PROTO STDCALL :DWORD
NdrRpcSmClientFree PROTO STDCALL :DWORD
NdrRpcSmSetClientToOsf PROTO STDCALL :DWORD
NdrRpcSsDefaultAllocate PROTO STDCALL :DWORD
NdrRpcSsDefaultFree PROTO STDCALL :DWORD
NdrRpcSsDisableAllocate PROTO STDCALL :DWORD
NdrRpcSsEnableAllocate PROTO STDCALL :DWORD
NdrSendReceive PROTO STDCALL :DWORD,:DWORD
NdrServerCall2 PROTO STDCALL :DWORD
NdrServerCall PROTO STDCALL :DWORD
NdrServerContextMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrServerContextNewMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrServerContextNewUnmarshall PROTO STDCALL :DWORD,:DWORD
NdrServerContextUnmarshall PROTO STDCALL :DWORD
NdrServerInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrServerInitializeMarshall PROTO STDCALL :DWORD,:DWORD
NdrServerInitializeNew PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrServerInitializePartial PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrServerInitializeUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrServerMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrServerUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrSimpleStructBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrSimpleStructFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrSimpleStructMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrSimpleStructMemorySize PROTO STDCALL :DWORD,:DWORD
NdrSimpleStructUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrSimpleTypeMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrSimpleTypeUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrStubCall2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrStubCall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrStubForwardingFunction PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrStubGetBuffer PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrStubInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrStubInitializeMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrTypeFlags PROTO C :VARARG
NdrTypeFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrTypeMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrTypeSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrTypeUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrUnmarshallBasetypeInline PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrUserMarshalBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrUserMarshalFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrUserMarshalMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrUserMarshalMemorySize PROTO STDCALL :DWORD,:DWORD
NdrUserMarshalSimpleTypeConvert PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrUserMarshalUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrVaryingArrayBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrVaryingArrayFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrVaryingArrayMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrVaryingArrayMemorySize PROTO STDCALL :DWORD,:DWORD
NdrVaryingArrayUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrXmitOrRepAsBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrXmitOrRepAsFree PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrXmitOrRepAsMarshall PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrXmitOrRepAsMemorySize PROTO STDCALL :DWORD,:DWORD
NdrXmitOrRepAsUnmarshall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrpCreateProxy PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NdrpCreateStub PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrpGetProcFormatString PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NdrpGetTypeFormatString PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrpGetTypeGenCookie PROTO STDCALL :DWORD
NdrpMemoryIncrement PROTO STDCALL :DWORD,:DWORD,:DWORD
NdrpReleaseTypeFormatString PROTO STDCALL :DWORD
NdrpReleaseTypeGenCookie PROTO STDCALL :DWORD
NdrpSetRpcSsDefaults PROTO STDCALL :DWORD,:DWORD
NdrpVarVtOfTypeDesc PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcAbortAsyncCall PROTO STDCALL :DWORD,:DWORD
RpcAsyncAbortCall PROTO STDCALL :DWORD,:DWORD
RpcAsyncCancelCall PROTO STDCALL :DWORD,:DWORD
RpcAsyncCompleteCall PROTO STDCALL :DWORD,:DWORD
RpcAsyncGetCallStatus PROTO STDCALL :DWORD
RpcAsyncInitializeHandle PROTO STDCALL :DWORD,:DWORD
RpcAsyncRegisterInfo PROTO STDCALL :DWORD
RpcBindingCopy PROTO STDCALL :DWORD,:DWORD
RpcBindingFree PROTO STDCALL :DWORD

RpcBindingFromStringBindingA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RpcBindingFromStringBinding equ <RpcBindingFromStringBindingA>
ENDIF

RpcBindingFromStringBindingW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcBindingFromStringBinding equ <RpcBindingFromStringBindingW>
ENDIF

RpcBindingInqAuthClientA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcBindingInqAuthClient equ <RpcBindingInqAuthClientA>
ENDIF

RpcBindingInqAuthClientExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcBindingInqAuthClientEx equ <RpcBindingInqAuthClientExA>
ENDIF

RpcBindingInqAuthClientExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcBindingInqAuthClientEx equ <RpcBindingInqAuthClientExW>
ENDIF

RpcBindingInqAuthClientW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcBindingInqAuthClient equ <RpcBindingInqAuthClientW>
ENDIF

RpcBindingInqAuthInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcBindingInqAuthInfo equ <RpcBindingInqAuthInfoA>
ENDIF

RpcBindingInqAuthInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcBindingInqAuthInfoEx equ <RpcBindingInqAuthInfoExA>
ENDIF

RpcBindingInqAuthInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcBindingInqAuthInfoEx equ <RpcBindingInqAuthInfoExW>
ENDIF

RpcBindingInqAuthInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcBindingInqAuthInfo equ <RpcBindingInqAuthInfoW>
ENDIF

RpcBindingInqObject PROTO STDCALL :DWORD,:DWORD
RpcBindingInqOption PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcBindingReset PROTO STDCALL :DWORD
RpcBindingServerFromClient PROTO STDCALL :DWORD,:DWORD

RpcBindingSetAuthInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcBindingSetAuthInfo equ <RpcBindingSetAuthInfoA>
ENDIF

RpcBindingSetAuthInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcBindingSetAuthInfoEx equ <RpcBindingSetAuthInfoExA>
ENDIF

RpcBindingSetAuthInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcBindingSetAuthInfoEx equ <RpcBindingSetAuthInfoExW>
ENDIF

RpcBindingSetAuthInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcBindingSetAuthInfo equ <RpcBindingSetAuthInfoW>
ENDIF

RpcBindingSetObject PROTO STDCALL :DWORD,:DWORD
RpcBindingSetOption PROTO STDCALL :DWORD,:DWORD,:DWORD

RpcBindingToStringBindingA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RpcBindingToStringBinding equ <RpcBindingToStringBindingA>
ENDIF

RpcBindingToStringBindingW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcBindingToStringBinding equ <RpcBindingToStringBindingW>
ENDIF

RpcBindingVectorFree PROTO STDCALL :DWORD
RpcCancelAsyncCall PROTO STDCALL :DWORD,:DWORD
RpcCancelThread PROTO STDCALL :DWORD
RpcCancelThreadEx PROTO STDCALL :DWORD,:DWORD

RpcCertGeneratePrincipalNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcCertGeneratePrincipalName equ <RpcCertGeneratePrincipalNameA>
ENDIF

RpcCertGeneratePrincipalNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcCertGeneratePrincipalName equ <RpcCertGeneratePrincipalNameW>
ENDIF

RpcCompleteAsyncCall PROTO STDCALL :DWORD,:DWORD

RpcEpRegisterA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcEpRegister equ <RpcEpRegisterA>
ENDIF

RpcEpRegisterNoReplaceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcEpRegisterNoReplace equ <RpcEpRegisterNoReplaceA>
ENDIF

RpcEpRegisterNoReplaceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcEpRegisterNoReplace equ <RpcEpRegisterNoReplaceW>
ENDIF

RpcEpRegisterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcEpRegister equ <RpcEpRegisterW>
ENDIF

RpcEpResolveBinding PROTO STDCALL :DWORD,:DWORD
RpcEpUnregister PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcErrorAddRecord PROTO STDCALL :DWORD
RpcErrorClearInformation PROTO STDCALL
RpcErrorEndEnumeration PROTO STDCALL :DWORD
RpcErrorGetNextRecord PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcErrorGetNumberOfRecords PROTO STDCALL :DWORD,:DWORD
RpcErrorLoadErrorInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcErrorResetEnumeration PROTO STDCALL :DWORD
RpcErrorSaveErrorInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcErrorStartEnumeration PROTO STDCALL :DWORD
RpcFreeAuthorizationContext PROTO STDCALL :DWORD
RpcGetAsyncCallStatus PROTO STDCALL :DWORD
RpcGetAuthorizationContextForClient PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcIfIdVectorFree PROTO STDCALL :DWORD
RpcIfInqId PROTO STDCALL :DWORD,:DWORD
RpcImpersonateClient PROTO STDCALL :DWORD
RpcInitializeAsyncHandle PROTO STDCALL :DWORD,:DWORD
RpcMgmtEnableIdleCleanup PROTO STDCALL
RpcMgmtEpEltInqBegin PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcMgmtEpEltInqDone PROTO STDCALL :DWORD

RpcMgmtEpEltInqNextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcMgmtEpEltInqNext equ <RpcMgmtEpEltInqNextA>
ENDIF

RpcMgmtEpEltInqNextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcMgmtEpEltInqNext equ <RpcMgmtEpEltInqNextW>
ENDIF

RpcMgmtEpUnregister PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RpcMgmtInqComTimeout PROTO STDCALL :DWORD,:DWORD
RpcMgmtInqDefaultProtectLevel PROTO STDCALL :DWORD,:DWORD
RpcMgmtInqIfIds PROTO STDCALL :DWORD,:DWORD

RpcMgmtInqServerPrincNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcMgmtInqServerPrincName equ <RpcMgmtInqServerPrincNameA>
ENDIF

RpcMgmtInqServerPrincNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcMgmtInqServerPrincName equ <RpcMgmtInqServerPrincNameW>
ENDIF

RpcMgmtInqStats PROTO STDCALL :DWORD,:DWORD
RpcMgmtIsServerListening PROTO STDCALL :DWORD
RpcMgmtSetAuthorizationFn PROTO STDCALL :DWORD
RpcMgmtSetCancelTimeout PROTO STDCALL :DWORD
RpcMgmtSetComTimeout PROTO STDCALL :DWORD,:DWORD
RpcMgmtSetServerStackSize PROTO STDCALL :DWORD
RpcMgmtStatsVectorFree PROTO STDCALL :DWORD
RpcMgmtStopServerListening PROTO STDCALL :DWORD
RpcMgmtWaitServerListen PROTO STDCALL

RpcNetworkInqProtseqsA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RpcNetworkInqProtseqs equ <RpcNetworkInqProtseqsA>
ENDIF

RpcNetworkInqProtseqsW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RpcNetworkInqProtseqs equ <RpcNetworkInqProtseqsW>
ENDIF

RpcNetworkIsProtseqValidA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RpcNetworkIsProtseqValid equ <RpcNetworkIsProtseqValidA>
ENDIF

RpcNetworkIsProtseqValidW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RpcNetworkIsProtseqValid equ <RpcNetworkIsProtseqValidW>
ENDIF

RpcNsBindingInqEntryNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsBindingInqEntryName equ <RpcNsBindingInqEntryNameA>
ENDIF

RpcNsBindingInqEntryNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsBindingInqEntryName equ <RpcNsBindingInqEntryNameW>
ENDIF

RpcObjectInqType PROTO STDCALL :DWORD,:DWORD
RpcObjectSetInqFn PROTO STDCALL :DWORD
RpcObjectSetType PROTO STDCALL :DWORD,:DWORD

RpcProtseqVectorFreeA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RpcProtseqVectorFree equ <RpcProtseqVectorFreeA>
ENDIF

RpcProtseqVectorFreeW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RpcProtseqVectorFree equ <RpcProtseqVectorFreeW>
ENDIF

RpcRaiseException PROTO STDCALL :DWORD
RpcRegisterAsyncInfo PROTO STDCALL :DWORD
RpcRevertToSelf PROTO STDCALL
RpcRevertToSelfEx PROTO STDCALL :DWORD
RpcServerInqBindings PROTO STDCALL :DWORD

RpcServerInqCallAttributesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RpcServerInqCallAttributes equ <RpcServerInqCallAttributesA>
ENDIF

RpcServerInqCallAttributesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcServerInqCallAttributes equ <RpcServerInqCallAttributesW>
ENDIF

RpcServerInqDefaultPrincNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RpcServerInqDefaultPrincName equ <RpcServerInqDefaultPrincNameA>
ENDIF

RpcServerInqDefaultPrincNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcServerInqDefaultPrincName equ <RpcServerInqDefaultPrincNameW>
ENDIF

RpcServerInqIf PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcServerListen PROTO STDCALL :DWORD,:DWORD,:DWORD

RpcServerRegisterAuthInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcServerRegisterAuthInfo equ <RpcServerRegisterAuthInfoA>
ENDIF

RpcServerRegisterAuthInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcServerRegisterAuthInfo equ <RpcServerRegisterAuthInfoW>
ENDIF

RpcServerRegisterIf2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcServerRegisterIf PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcServerRegisterIfEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcServerTestCancel PROTO STDCALL :DWORD
RpcServerUnregisterIf PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcServerUnregisterIfEx PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcServerUseAllProtseqs PROTO STDCALL :DWORD,:DWORD
RpcServerUseAllProtseqsEx PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcServerUseAllProtseqsIf PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcServerUseAllProtseqsIfEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

RpcServerUseProtseqA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcServerUseProtseq equ <RpcServerUseProtseqA>
ENDIF

RpcServerUseProtseqEpA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcServerUseProtseqEp equ <RpcServerUseProtseqEpA>
ENDIF

RpcServerUseProtseqEpExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcServerUseProtseqEpEx equ <RpcServerUseProtseqEpExA>
ENDIF

RpcServerUseProtseqEpExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcServerUseProtseqEpEx equ <RpcServerUseProtseqEpExW>
ENDIF

RpcServerUseProtseqEpW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcServerUseProtseqEp equ <RpcServerUseProtseqEpW>
ENDIF

RpcServerUseProtseqExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcServerUseProtseqEx equ <RpcServerUseProtseqExA>
ENDIF

RpcServerUseProtseqExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcServerUseProtseqEx equ <RpcServerUseProtseqExW>
ENDIF

RpcServerUseProtseqIfA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcServerUseProtseqIf equ <RpcServerUseProtseqIfA>
ENDIF

RpcServerUseProtseqIfExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcServerUseProtseqIfEx equ <RpcServerUseProtseqIfExA>
ENDIF

RpcServerUseProtseqIfExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcServerUseProtseqIfEx equ <RpcServerUseProtseqIfExW>
ENDIF

RpcServerUseProtseqIfW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcServerUseProtseqIf equ <RpcServerUseProtseqIfW>
ENDIF

RpcServerUseProtseqW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcServerUseProtseq equ <RpcServerUseProtseqW>
ENDIF

RpcServerYield PROTO STDCALL
RpcSmAllocate PROTO STDCALL :DWORD,:DWORD
RpcSmClientFree PROTO STDCALL :DWORD
RpcSmDestroyClientContext PROTO STDCALL :DWORD
RpcSmDisableAllocate PROTO STDCALL
RpcSmEnableAllocate PROTO STDCALL
RpcSmFree PROTO STDCALL :DWORD
RpcSmGetThreadHandle PROTO STDCALL :DWORD
RpcSmSetClientAllocFree PROTO STDCALL :DWORD,:DWORD
RpcSmSetThreadHandle PROTO STDCALL :DWORD
RpcSmSwapClientAllocFree PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RpcSsAllocate PROTO STDCALL :DWORD
RpcSsContextLockExclusive PROTO STDCALL :DWORD,:DWORD
RpcSsContextLockShared PROTO STDCALL :DWORD,:DWORD
RpcSsDestroyClientContext PROTO STDCALL :DWORD
RpcSsDisableAllocate PROTO STDCALL
RpcSsDontSerializeContext PROTO STDCALL
RpcSsEnableAllocate PROTO STDCALL
RpcSsFree PROTO STDCALL :DWORD
RpcSsGetContextBinding PROTO STDCALL :DWORD,:DWORD
RpcSsGetThreadHandle PROTO STDCALL
RpcSsSetClientAllocFree PROTO STDCALL :DWORD,:DWORD
RpcSsSetThreadHandle PROTO STDCALL :DWORD
RpcSsSwapClientAllocFree PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

RpcStringBindingComposeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcStringBindingCompose equ <RpcStringBindingComposeA>
ENDIF

RpcStringBindingComposeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcStringBindingCompose equ <RpcStringBindingComposeW>
ENDIF

RpcStringBindingParseA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcStringBindingParse equ <RpcStringBindingParseA>
ENDIF

RpcStringBindingParseW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcStringBindingParse equ <RpcStringBindingParseW>
ENDIF

RpcStringFreeA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RpcStringFree equ <RpcStringFreeA>
ENDIF

RpcStringFreeW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RpcStringFree equ <RpcStringFreeW>
ENDIF

RpcTestCancel PROTO STDCALL
RpcUserFree PROTO STDCALL :DWORD,:DWORD
SimpleTypeAlignment PROTO C :VARARG
SimpleTypeBufferSize PROTO C :VARARG
SimpleTypeMemorySize PROTO C :VARARG
TowerConstruct PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TowerExplode PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UuidCompare PROTO STDCALL :DWORD,:DWORD,:DWORD
UuidCreate PROTO STDCALL :DWORD
UuidCreateNil PROTO STDCALL :DWORD
UuidCreateSequential PROTO STDCALL :DWORD
UuidEqual PROTO STDCALL :DWORD,:DWORD,:DWORD

UuidFromStringA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  UuidFromString equ <UuidFromStringA>
ENDIF

UuidFromStringW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  UuidFromString equ <UuidFromStringW>
ENDIF

UuidHash PROTO STDCALL :DWORD,:DWORD
UuidIsNil PROTO STDCALL :DWORD,:DWORD

UuidToStringA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  UuidToString equ <UuidToStringA>
ENDIF

UuidToStringW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  UuidToString equ <UuidToStringW>
ENDIF

pfnFreeRoutines PROTO C :VARARG
pfnMarshallRoutines PROTO C :VARARG
pfnSizeRoutines PROTO C :VARARG
  ; pfnUnmarshallRoutines arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file rpcrt4.inc
  echo -----------------------------------------
ENDIF
