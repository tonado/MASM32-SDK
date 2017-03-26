; --------------------------------------------------------------------------------------------------
;                          cfgmgr32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF CFGMGR32_INC
CFGMGR32_INC equ <1>

CMP_Init_Detection PROTO STDCALL :DWORD
CMP_RegisterNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CMP_Report_LogOn PROTO STDCALL :DWORD,:DWORD
CMP_UnregisterNotification PROTO STDCALL :DWORD
CMP_WaitNoPendingInstallEvents PROTO STDCALL :DWORD
CMP_WaitServicesAvailable PROTO STDCALL :DWORD
CM_Add_Empty_Log_Conf PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Add_Empty_Log_Conf_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CM_Add_IDA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Add_ID equ <CM_Add_IDA>
ENDIF

CM_Add_IDW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Add_ID equ <CM_Add_IDW>
ENDIF

CM_Add_ID_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Add_ID_Ex equ <CM_Add_ID_ExA>
ENDIF

CM_Add_ID_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Add_ID_Ex equ <CM_Add_ID_ExW>
ENDIF

CM_Add_Range PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Add_Res_Des PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Add_Res_Des_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CM_Connect_MachineA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Connect_Machine equ <CM_Connect_MachineA>
ENDIF

CM_Connect_MachineW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CM_Connect_Machine equ <CM_Connect_MachineW>
ENDIF

CM_Create_DevNodeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Create_DevNode equ <CM_Create_DevNodeA>
ENDIF

CM_Create_DevNodeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Create_DevNode equ <CM_Create_DevNodeW>
ENDIF

CM_Create_DevNode_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Create_DevNode_Ex equ <CM_Create_DevNode_ExA>
ENDIF

CM_Create_DevNode_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Create_DevNode_Ex equ <CM_Create_DevNode_ExW>
ENDIF

CM_Create_Range_List PROTO STDCALL :DWORD,:DWORD
CM_Delete_Class_Key PROTO STDCALL :DWORD,:DWORD
CM_Delete_Class_Key_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Delete_DevNode_Key PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Delete_DevNode_Key_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Delete_Range PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Detect_Resource_Conflict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Detect_Resource_Conflict_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Disable_DevNode PROTO STDCALL :DWORD,:DWORD
CM_Disable_DevNode_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Disconnect_Machine PROTO STDCALL :DWORD
CM_Dup_Range_List PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Enable_DevNode PROTO STDCALL :DWORD,:DWORD
CM_Enable_DevNode_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Enumerate_Classes PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Enumerate_Classes_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CM_Enumerate_EnumeratorsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Enumerate_Enumerators equ <CM_Enumerate_EnumeratorsA>
ENDIF

CM_Enumerate_EnumeratorsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Enumerate_Enumerators equ <CM_Enumerate_EnumeratorsW>
ENDIF

CM_Enumerate_Enumerators_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Enumerate_Enumerators_Ex equ <CM_Enumerate_Enumerators_ExA>
ENDIF

CM_Enumerate_Enumerators_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Enumerate_Enumerators_Ex equ <CM_Enumerate_Enumerators_ExW>
ENDIF

CM_Find_Range PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_First_Range PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Free_Log_Conf PROTO STDCALL :DWORD,:DWORD
CM_Free_Log_Conf_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Free_Log_Conf_Handle PROTO STDCALL :DWORD
CM_Free_Range_List PROTO STDCALL :DWORD,:DWORD
CM_Free_Res_Des PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Free_Res_Des_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Free_Res_Des_Handle PROTO STDCALL :DWORD
CM_Free_Resource_Conflict_Handle PROTO STDCALL :DWORD
CM_Get_Child PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Get_Child_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CM_Get_Class_Key_NameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Class_Key_Name equ <CM_Get_Class_Key_NameA>
ENDIF

CM_Get_Class_Key_NameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Class_Key_Name equ <CM_Get_Class_Key_NameW>
ENDIF

CM_Get_Class_Key_Name_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Class_Key_Name_Ex equ <CM_Get_Class_Key_Name_ExA>
ENDIF

CM_Get_Class_Key_Name_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Class_Key_Name_Ex equ <CM_Get_Class_Key_Name_ExW>
ENDIF

CM_Get_Class_NameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Class_Name equ <CM_Get_Class_NameA>
ENDIF

CM_Get_Class_NameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Class_Name equ <CM_Get_Class_NameW>
ENDIF

CM_Get_Class_Name_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Class_Name_Ex equ <CM_Get_Class_Name_ExA>
ENDIF

CM_Get_Class_Name_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Class_Name_Ex equ <CM_Get_Class_Name_ExW>
ENDIF

CM_Get_Class_Registry_PropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Class_Registry_Property equ <CM_Get_Class_Registry_PropertyA>
ENDIF

CM_Get_Class_Registry_PropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Class_Registry_Property equ <CM_Get_Class_Registry_PropertyW>
ENDIF

CM_Get_Depth PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Get_Depth_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CM_Get_DevNode_Registry_PropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_DevNode_Registry_Property equ <CM_Get_DevNode_Registry_PropertyA>
ENDIF

CM_Get_DevNode_Registry_PropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_DevNode_Registry_Property equ <CM_Get_DevNode_Registry_PropertyW>
ENDIF

CM_Get_DevNode_Registry_Property_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_DevNode_Registry_Property_Ex equ <CM_Get_DevNode_Registry_Property_ExA>
ENDIF

CM_Get_DevNode_Registry_Property_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_DevNode_Registry_Property_Ex equ <CM_Get_DevNode_Registry_Property_ExW>
ENDIF

CM_Get_DevNode_Status PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_DevNode_Status_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CM_Get_Device_IDA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_ID equ <CM_Get_Device_IDA>
ENDIF

CM_Get_Device_IDW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_ID equ <CM_Get_Device_IDW>
ENDIF

CM_Get_Device_ID_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_ID_Ex equ <CM_Get_Device_ID_ExA>
ENDIF

CM_Get_Device_ID_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_ID_Ex equ <CM_Get_Device_ID_ExW>
ENDIF

CM_Get_Device_ID_ListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_ID_List equ <CM_Get_Device_ID_ListA>
ENDIF

CM_Get_Device_ID_ListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_ID_List equ <CM_Get_Device_ID_ListW>
ENDIF

CM_Get_Device_ID_List_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_ID_List_Ex equ <CM_Get_Device_ID_List_ExA>
ENDIF

CM_Get_Device_ID_List_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_ID_List_Ex equ <CM_Get_Device_ID_List_ExW>
ENDIF

CM_Get_Device_ID_List_SizeA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_ID_List_Size equ <CM_Get_Device_ID_List_SizeA>
ENDIF

CM_Get_Device_ID_List_SizeW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_ID_List_Size equ <CM_Get_Device_ID_List_SizeW>
ENDIF

CM_Get_Device_ID_List_Size_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_ID_List_Size_Ex equ <CM_Get_Device_ID_List_Size_ExA>
ENDIF

CM_Get_Device_ID_List_Size_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_ID_List_Size_Ex equ <CM_Get_Device_ID_List_Size_ExW>
ENDIF

CM_Get_Device_ID_Size PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Get_Device_ID_Size_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CM_Get_Device_Interface_AliasA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_Interface_Alias equ <CM_Get_Device_Interface_AliasA>
ENDIF

CM_Get_Device_Interface_AliasW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_Interface_Alias equ <CM_Get_Device_Interface_AliasW>
ENDIF

CM_Get_Device_Interface_Alias_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_Interface_Alias_Ex equ <CM_Get_Device_Interface_Alias_ExA>
ENDIF

CM_Get_Device_Interface_Alias_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_Interface_Alias_Ex equ <CM_Get_Device_Interface_Alias_ExW>
ENDIF

CM_Get_Device_Interface_ListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_Interface_List equ <CM_Get_Device_Interface_ListA>
ENDIF

CM_Get_Device_Interface_ListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_Interface_List equ <CM_Get_Device_Interface_ListW>
ENDIF

CM_Get_Device_Interface_List_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_Interface_List_Ex equ <CM_Get_Device_Interface_List_ExA>
ENDIF

CM_Get_Device_Interface_List_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_Interface_List_Ex equ <CM_Get_Device_Interface_List_ExW>
ENDIF

CM_Get_Device_Interface_List_SizeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_Interface_List_Size equ <CM_Get_Device_Interface_List_SizeA>
ENDIF

CM_Get_Device_Interface_List_SizeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_Interface_List_Size equ <CM_Get_Device_Interface_List_SizeW>
ENDIF

CM_Get_Device_Interface_List_Size_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Device_Interface_List_Size_Ex equ <CM_Get_Device_Interface_List_Size_ExA>
ENDIF

CM_Get_Device_Interface_List_Size_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Device_Interface_List_Size_Ex equ <CM_Get_Device_Interface_List_Size_ExW>
ENDIF

CM_Get_First_Log_Conf PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Get_First_Log_Conf_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Global_State PROTO STDCALL :DWORD,:DWORD
CM_Get_Global_State_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD

CM_Get_HW_Prof_FlagsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_HW_Prof_Flags equ <CM_Get_HW_Prof_FlagsA>
ENDIF

CM_Get_HW_Prof_FlagsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_HW_Prof_Flags equ <CM_Get_HW_Prof_FlagsW>
ENDIF

CM_Get_HW_Prof_Flags_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_HW_Prof_Flags_Ex equ <CM_Get_HW_Prof_Flags_ExA>
ENDIF

CM_Get_HW_Prof_Flags_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_HW_Prof_Flags_Ex equ <CM_Get_HW_Prof_Flags_ExW>
ENDIF

CM_Get_Hardware_Profile_InfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Hardware_Profile_Info equ <CM_Get_Hardware_Profile_InfoA>
ENDIF

CM_Get_Hardware_Profile_InfoW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Hardware_Profile_Info equ <CM_Get_Hardware_Profile_InfoW>
ENDIF

CM_Get_Hardware_Profile_Info_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Hardware_Profile_Info_Ex equ <CM_Get_Hardware_Profile_Info_ExA>
ENDIF

CM_Get_Hardware_Profile_Info_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Hardware_Profile_Info_Ex equ <CM_Get_Hardware_Profile_Info_ExW>
ENDIF

CM_Get_Log_Conf_Priority PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Get_Log_Conf_Priority_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Next_Log_Conf PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Get_Next_Log_Conf_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Next_Res_Des PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Next_Res_Des_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Parent PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Get_Parent_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Res_Des_Data PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Res_Des_Data_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Res_Des_Data_Size PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Get_Res_Des_Data_Size_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Resource_Conflict_Count PROTO STDCALL :DWORD,:DWORD

CM_Get_Resource_Conflict_DetailsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_Resource_Conflict_Details equ <CM_Get_Resource_Conflict_DetailsA>
ENDIF

CM_Get_Resource_Conflict_DetailsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_Resource_Conflict_Details equ <CM_Get_Resource_Conflict_DetailsW>
ENDIF

CM_Get_Sibling PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Get_Sibling_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Version PROTO STDCALL
CM_Get_Version_Ex PROTO STDCALL :DWORD
CM_Intersect_Range_List PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Invert_Range_List PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Is_Dock_Station_Present PROTO STDCALL :DWORD
CM_Is_Dock_Station_Present_Ex PROTO STDCALL :DWORD,:DWORD

CM_Locate_DevNodeA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Locate_DevNode equ <CM_Locate_DevNodeA>
ENDIF

CM_Locate_DevNodeW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Locate_DevNode equ <CM_Locate_DevNodeW>
ENDIF

CM_Locate_DevNode_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Locate_DevNode_Ex equ <CM_Locate_DevNode_ExA>
ENDIF

CM_Locate_DevNode_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Locate_DevNode_Ex equ <CM_Locate_DevNode_ExW>
ENDIF

CM_Merge_Range_List PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Modify_Res_Des PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Modify_Res_Des_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Move_DevNode PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Move_DevNode_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Next_Range PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CM_Open_Class_KeyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Open_Class_Key equ <CM_Open_Class_KeyA>
ENDIF

CM_Open_Class_KeyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Open_Class_Key equ <CM_Open_Class_KeyW>
ENDIF

CM_Open_Class_Key_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Open_Class_Key_Ex equ <CM_Open_Class_Key_ExA>
ENDIF

CM_Open_Class_Key_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Open_Class_Key_Ex equ <CM_Open_Class_Key_ExW>
ENDIF

CM_Open_DevNode_Key PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Open_DevNode_Key_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CM_Query_And_Remove_SubTreeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Query_And_Remove_SubTree equ <CM_Query_And_Remove_SubTreeA>
ENDIF

CM_Query_And_Remove_SubTreeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Query_And_Remove_SubTree equ <CM_Query_And_Remove_SubTreeW>
ENDIF

CM_Query_And_Remove_SubTree_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Query_And_Remove_SubTree_Ex equ <CM_Query_And_Remove_SubTree_ExA>
ENDIF

CM_Query_And_Remove_SubTree_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Query_And_Remove_SubTree_Ex equ <CM_Query_And_Remove_SubTree_ExW>
ENDIF

CM_Query_Arbitrator_Free_Data PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Query_Arbitrator_Free_Data_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Query_Arbitrator_Free_Size PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CM_Query_Arbitrator_Free_Size_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Query_Remove_SubTree PROTO STDCALL :DWORD,:DWORD
CM_Query_Remove_SubTree_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Query_Resource_Conflict_List PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Reenumerate_DevNode PROTO STDCALL :DWORD,:DWORD
CM_Reenumerate_DevNode_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Register_Device_Driver PROTO STDCALL :DWORD,:DWORD
CM_Register_Device_Driver_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD

CM_Register_Device_InterfaceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Register_Device_Interface equ <CM_Register_Device_InterfaceA>
ENDIF

CM_Register_Device_InterfaceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Register_Device_Interface equ <CM_Register_Device_InterfaceW>
ENDIF

CM_Register_Device_Interface_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Register_Device_Interface_Ex equ <CM_Register_Device_Interface_ExA>
ENDIF

CM_Register_Device_Interface_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Register_Device_Interface_Ex equ <CM_Register_Device_Interface_ExW>
ENDIF

CM_Remove_SubTree PROTO STDCALL :DWORD,:DWORD
CM_Remove_SubTree_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Request_Eject_PC PROTO STDCALL
CM_Request_Eject_PC_Ex PROTO STDCALL :DWORD
CM_Run_Detection PROTO STDCALL :DWORD
CM_Run_Detection_Ex PROTO STDCALL :DWORD,:DWORD

CM_Set_Class_Registry_PropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Set_Class_Registry_Property equ <CM_Set_Class_Registry_PropertyA>
ENDIF

CM_Set_Class_Registry_PropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Set_Class_Registry_Property equ <CM_Set_Class_Registry_PropertyW>
ENDIF

CM_Set_DevNode_Problem PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Set_DevNode_Problem_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CM_Set_DevNode_Registry_PropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Set_DevNode_Registry_Property equ <CM_Set_DevNode_Registry_PropertyA>
ENDIF

CM_Set_DevNode_Registry_PropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Set_DevNode_Registry_Property equ <CM_Set_DevNode_Registry_PropertyW>
ENDIF

CM_Set_DevNode_Registry_Property_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Set_DevNode_Registry_Property_Ex equ <CM_Set_DevNode_Registry_Property_ExA>
ENDIF

CM_Set_DevNode_Registry_Property_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Set_DevNode_Registry_Property_Ex equ <CM_Set_DevNode_Registry_Property_ExW>
ENDIF

CM_Set_HW_Prof PROTO STDCALL :DWORD,:DWORD
CM_Set_HW_Prof_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD

CM_Set_HW_Prof_FlagsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Set_HW_Prof_Flags equ <CM_Set_HW_Prof_FlagsA>
ENDIF

CM_Set_HW_Prof_FlagsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Set_HW_Prof_Flags equ <CM_Set_HW_Prof_FlagsW>
ENDIF

CM_Set_HW_Prof_Flags_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Set_HW_Prof_Flags_Ex equ <CM_Set_HW_Prof_Flags_ExA>
ENDIF

CM_Set_HW_Prof_Flags_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Set_HW_Prof_Flags_Ex equ <CM_Set_HW_Prof_Flags_ExW>
ENDIF

CM_Setup_DevNode PROTO STDCALL :DWORD,:DWORD
CM_Setup_DevNode_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD
CM_Test_Range_Available PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Uninstall_DevNode PROTO STDCALL :DWORD,:DWORD
CM_Uninstall_DevNode_Ex PROTO STDCALL :DWORD,:DWORD,:DWORD

CM_Unregister_Device_InterfaceA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Unregister_Device_Interface equ <CM_Unregister_Device_InterfaceA>
ENDIF

CM_Unregister_Device_InterfaceW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CM_Unregister_Device_Interface equ <CM_Unregister_Device_InterfaceW>
ENDIF

CM_Unregister_Device_Interface_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Unregister_Device_Interface_Ex equ <CM_Unregister_Device_Interface_ExA>
ENDIF

CM_Unregister_Device_Interface_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Unregister_Device_Interface_Ex equ <CM_Unregister_Device_Interface_ExW>
ENDIF

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file cfgmgr32.inc
  echo -------------------------------------------
ENDIF
