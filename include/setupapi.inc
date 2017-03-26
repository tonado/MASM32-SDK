; --------------------------------------------------------------------------------------------------
;                          setupapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SETUPAPI_INC
SETUPAPI_INC equ <1>

CMP_GetBlockedDriverInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CMP_GetServerSideDeviceInstallFlags PROTO STDCALL :DWORD,:DWORD,:DWORD
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

CM_Get_DevNode_Custom_PropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_DevNode_Custom_Property equ <CM_Get_DevNode_Custom_PropertyA>
ENDIF

CM_Get_DevNode_Custom_PropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_DevNode_Custom_Property equ <CM_Get_DevNode_Custom_PropertyW>
ENDIF

CM_Get_DevNode_Custom_Property_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Get_DevNode_Custom_Property_Ex equ <CM_Get_DevNode_Custom_Property_ExA>
ENDIF

CM_Get_DevNode_Custom_Property_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Get_DevNode_Custom_Property_Ex equ <CM_Get_DevNode_Custom_Property_ExW>
ENDIF

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
CM_Is_Version_Available PROTO STDCALL :DWORD
CM_Is_Version_Available_Ex PROTO STDCALL :DWORD,:DWORD

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

CM_Request_Device_EjectA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Request_Device_Eject equ <CM_Request_Device_EjectA>
ENDIF

CM_Request_Device_EjectW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Request_Device_Eject equ <CM_Request_Device_EjectW>
ENDIF

CM_Request_Device_Eject_ExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CM_Request_Device_Eject_Ex equ <CM_Request_Device_Eject_ExA>
ENDIF

CM_Request_Device_Eject_ExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CM_Request_Device_Eject_Ex equ <CM_Request_Device_Eject_ExW>
ENDIF

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

ExtensionPropSheetPageProc PROTO STDCALL :DWORD,:DWORD,:DWORD

InstallHinfSectionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InstallHinfSection equ <InstallHinfSectionA>
ENDIF

InstallHinfSectionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InstallHinfSection equ <InstallHinfSectionW>
ENDIF

SetupAddInstallSectionToDiskSpaceListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupAddInstallSectionToDiskSpaceList equ <SetupAddInstallSectionToDiskSpaceListA>
ENDIF

SetupAddInstallSectionToDiskSpaceListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupAddInstallSectionToDiskSpaceList equ <SetupAddInstallSectionToDiskSpaceListW>
ENDIF

SetupAddSectionToDiskSpaceListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupAddSectionToDiskSpaceList equ <SetupAddSectionToDiskSpaceListA>
ENDIF

SetupAddSectionToDiskSpaceListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupAddSectionToDiskSpaceList equ <SetupAddSectionToDiskSpaceListW>
ENDIF

SetupAddToDiskSpaceListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupAddToDiskSpaceList equ <SetupAddToDiskSpaceListA>
ENDIF

SetupAddToDiskSpaceListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupAddToDiskSpaceList equ <SetupAddToDiskSpaceListW>
ENDIF

SetupAddToSourceListA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetupAddToSourceList equ <SetupAddToSourceListA>
ENDIF

SetupAddToSourceListW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetupAddToSourceList equ <SetupAddToSourceListW>
ENDIF

SetupAdjustDiskSpaceListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupAdjustDiskSpaceList equ <SetupAdjustDiskSpaceListA>
ENDIF

SetupAdjustDiskSpaceListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupAdjustDiskSpaceList equ <SetupAdjustDiskSpaceListW>
ENDIF

SetupBackupErrorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupBackupError equ <SetupBackupErrorA>
ENDIF

SetupBackupErrorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupBackupError equ <SetupBackupErrorW>
ENDIF

SetupCancelTemporarySourceList PROTO STDCALL
SetupCloseFileQueue PROTO STDCALL :DWORD
SetupCloseInfFile PROTO STDCALL :DWORD
SetupCloseLog PROTO STDCALL

SetupCommitFileQueueA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupCommitFileQueue equ <SetupCommitFileQueueA>
ENDIF

SetupCommitFileQueueW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupCommitFileQueue equ <SetupCommitFileQueueW>
ENDIF

SetupCopyErrorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupCopyError equ <SetupCopyErrorA>
ENDIF

SetupCopyErrorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupCopyError equ <SetupCopyErrorW>
ENDIF

SetupCopyOEMInfA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupCopyOEMInf equ <SetupCopyOEMInfA>
ENDIF

SetupCopyOEMInfW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupCopyOEMInf equ <SetupCopyOEMInfW>
ENDIF

SetupCreateDiskSpaceListA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupCreateDiskSpaceList equ <SetupCreateDiskSpaceListA>
ENDIF

SetupCreateDiskSpaceListW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupCreateDiskSpaceList equ <SetupCreateDiskSpaceListW>
ENDIF

SetupDecompressOrCopyFileA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDecompressOrCopyFile equ <SetupDecompressOrCopyFileA>
ENDIF

SetupDecompressOrCopyFileW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDecompressOrCopyFile equ <SetupDecompressOrCopyFileW>
ENDIF


SetupDefaultQueueCallbackA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDefaultQueueCallback equ <SetupDefaultQueueCallbackA>
ENDIF

SetupDefaultQueueCallbackW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDefaultQueueCallback equ <SetupDefaultQueueCallbackW>
ENDIF

SetupDeleteErrorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDeleteError equ <SetupDeleteErrorA>
ENDIF

SetupDeleteErrorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDeleteError equ <SetupDeleteErrorW>
ENDIF

SetupDestroyDiskSpaceList PROTO STDCALL :DWORD
SetupDiAskForOEMDisk PROTO STDCALL :DWORD,:DWORD
SetupDiBuildClassInfoList PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SetupDiBuildClassInfoListExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiBuildClassInfoListEx equ <SetupDiBuildClassInfoListExA>
ENDIF

SetupDiBuildClassInfoListExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiBuildClassInfoListEx equ <SetupDiBuildClassInfoListExW>
ENDIF

SetupDiBuildDriverInfoList PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupDiCallClassInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupDiCancelDriverInfoSearch PROTO STDCALL :DWORD
SetupDiChangeState PROTO STDCALL :DWORD,:DWORD

SetupDiClassGuidsFromNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiClassGuidsFromName equ <SetupDiClassGuidsFromNameA>
ENDIF

SetupDiClassGuidsFromNameExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiClassGuidsFromNameEx equ <SetupDiClassGuidsFromNameExA>
ENDIF

SetupDiClassGuidsFromNameExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiClassGuidsFromNameEx equ <SetupDiClassGuidsFromNameExW>
ENDIF

SetupDiClassGuidsFromNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiClassGuidsFromName equ <SetupDiClassGuidsFromNameW>
ENDIF

SetupDiClassNameFromGuidA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiClassNameFromGuid equ <SetupDiClassNameFromGuidA>
ENDIF

SetupDiClassNameFromGuidExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiClassNameFromGuidEx equ <SetupDiClassNameFromGuidExA>
ENDIF

SetupDiClassNameFromGuidExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiClassNameFromGuidEx equ <SetupDiClassNameFromGuidExW>
ENDIF

SetupDiClassNameFromGuidW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiClassNameFromGuid equ <SetupDiClassNameFromGuidW>
ENDIF

SetupDiCreateDevRegKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiCreateDevRegKey equ <SetupDiCreateDevRegKeyA>
ENDIF

SetupDiCreateDevRegKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiCreateDevRegKey equ <SetupDiCreateDevRegKeyW>
ENDIF

SetupDiCreateDeviceInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiCreateDeviceInfo equ <SetupDiCreateDeviceInfoA>
ENDIF

SetupDiCreateDeviceInfoList PROTO STDCALL :DWORD,:DWORD

SetupDiCreateDeviceInfoListExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiCreateDeviceInfoListEx equ <SetupDiCreateDeviceInfoListExA>
ENDIF

SetupDiCreateDeviceInfoListExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiCreateDeviceInfoListEx equ <SetupDiCreateDeviceInfoListExW>
ENDIF

SetupDiCreateDeviceInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiCreateDeviceInfo equ <SetupDiCreateDeviceInfoW>
ENDIF

SetupDiCreateDeviceInterfaceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiCreateDeviceInterface equ <SetupDiCreateDeviceInterfaceA>
ENDIF

SetupDiCreateDeviceInterfaceRegKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiCreateDeviceInterfaceRegKey equ <SetupDiCreateDeviceInterfaceRegKeyA>
ENDIF

SetupDiCreateDeviceInterfaceRegKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiCreateDeviceInterfaceRegKey equ <SetupDiCreateDeviceInterfaceRegKeyW>
ENDIF

SetupDiCreateDeviceInterfaceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiCreateDeviceInterface equ <SetupDiCreateDeviceInterfaceW>
ENDIF

SetupDiDeleteDevRegKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiDeleteDeviceInfo PROTO STDCALL :DWORD,:DWORD
SetupDiDeleteDeviceInterfaceData PROTO STDCALL :DWORD,:DWORD
SetupDiDeleteDeviceInterfaceRegKey PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupDiDestroyClassImageList PROTO STDCALL :DWORD
SetupDiDestroyDeviceInfoList PROTO STDCALL :DWORD
SetupDiDestroyDriverInfoList PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupDiDrawMiniIcon PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiEnumDeviceInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupDiEnumDeviceInterfaces PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

SetupDiEnumDriverInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiEnumDriverInfo equ <SetupDiEnumDriverInfoA>
ENDIF

SetupDiEnumDriverInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiEnumDriverInfo equ <SetupDiEnumDriverInfoW>
ENDIF

SetupDiGetActualSectionToInstallA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetActualSectionToInstall equ <SetupDiGetActualSectionToInstallA>
ENDIF

SetupDiGetActualSectionToInstallExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetActualSectionToInstallEx equ <SetupDiGetActualSectionToInstallExA>
ENDIF

SetupDiGetActualSectionToInstallExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetActualSectionToInstallEx equ <SetupDiGetActualSectionToInstallExW>
ENDIF

SetupDiGetActualSectionToInstallW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetActualSectionToInstall equ <SetupDiGetActualSectionToInstallW>
ENDIF

SetupDiGetClassBitmapIndex PROTO STDCALL :DWORD,:DWORD

SetupDiGetClassDescriptionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetClassDescription equ <SetupDiGetClassDescriptionA>
ENDIF

SetupDiGetClassDescriptionExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetClassDescriptionEx equ <SetupDiGetClassDescriptionExA>
ENDIF

SetupDiGetClassDescriptionExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetClassDescriptionEx equ <SetupDiGetClassDescriptionExW>
ENDIF

SetupDiGetClassDescriptionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetClassDescription equ <SetupDiGetClassDescriptionW>
ENDIF

SetupDiGetClassDevPropertySheetsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetClassDevPropertySheets equ <SetupDiGetClassDevPropertySheetsA>
ENDIF

SetupDiGetClassDevPropertySheetsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetClassDevPropertySheets equ <SetupDiGetClassDevPropertySheetsW>
ENDIF

SetupDiGetClassDevsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetClassDevs equ <SetupDiGetClassDevsA>
ENDIF

SetupDiGetClassDevsExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetClassDevsEx equ <SetupDiGetClassDevsExA>
ENDIF

SetupDiGetClassDevsExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetClassDevsEx equ <SetupDiGetClassDevsExW>
ENDIF

SetupDiGetClassDevsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetClassDevs equ <SetupDiGetClassDevsW>
ENDIF

SetupDiGetClassImageIndex PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupDiGetClassImageList PROTO STDCALL :DWORD

SetupDiGetClassImageListExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetClassImageListEx equ <SetupDiGetClassImageListExA>
ENDIF

SetupDiGetClassImageListExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetClassImageListEx equ <SetupDiGetClassImageListExW>
ENDIF

SetupDiGetClassInstallParamsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetClassInstallParams equ <SetupDiGetClassInstallParamsA>
ENDIF

SetupDiGetClassInstallParamsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetClassInstallParams equ <SetupDiGetClassInstallParamsW>
ENDIF

SetupDiGetClassRegistryPropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetClassRegistryProperty equ <SetupDiGetClassRegistryPropertyA>
ENDIF

SetupDiGetClassRegistryPropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetClassRegistryProperty equ <SetupDiGetClassRegistryPropertyW>
ENDIF

SetupDiGetCustomDevicePropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetCustomDeviceProperty equ <SetupDiGetCustomDevicePropertyA>
ENDIF

SetupDiGetCustomDevicePropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetCustomDeviceProperty equ <SetupDiGetCustomDevicePropertyW>
ENDIF

SetupDiGetDeviceInfoListClass PROTO STDCALL :DWORD,:DWORD

SetupDiGetDeviceInfoListDetailA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetDeviceInfoListDetail equ <SetupDiGetDeviceInfoListDetailA>
ENDIF

SetupDiGetDeviceInfoListDetailW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetDeviceInfoListDetail equ <SetupDiGetDeviceInfoListDetailW>
ENDIF

SetupDiGetDeviceInstallParamsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetDeviceInstallParams equ <SetupDiGetDeviceInstallParamsA>
ENDIF

SetupDiGetDeviceInstallParamsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetDeviceInstallParams equ <SetupDiGetDeviceInstallParamsW>
ENDIF

SetupDiGetDeviceInstanceIdA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetDeviceInstanceId equ <SetupDiGetDeviceInstanceIdA>
ENDIF

SetupDiGetDeviceInstanceIdW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetDeviceInstanceId equ <SetupDiGetDeviceInstanceIdW>
ENDIF

SetupDiGetDeviceInterfaceAlias PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SetupDiGetDeviceInterfaceDetailA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetDeviceInterfaceDetail equ <SetupDiGetDeviceInterfaceDetailA>
ENDIF

SetupDiGetDeviceInterfaceDetailW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetDeviceInterfaceDetail equ <SetupDiGetDeviceInterfaceDetailW>
ENDIF

SetupDiGetDeviceRegistryPropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetDeviceRegistryProperty equ <SetupDiGetDeviceRegistryPropertyA>
ENDIF

SetupDiGetDeviceRegistryPropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetDeviceRegistryProperty equ <SetupDiGetDeviceRegistryPropertyW>
ENDIF

SetupDiGetDriverInfoDetailA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetDriverInfoDetail equ <SetupDiGetDriverInfoDetailA>
ENDIF

SetupDiGetDriverInfoDetailW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetDriverInfoDetail equ <SetupDiGetDriverInfoDetailW>
ENDIF

SetupDiGetDriverInstallParamsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetDriverInstallParams equ <SetupDiGetDriverInstallParamsA>
ENDIF

SetupDiGetDriverInstallParamsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetDriverInstallParams equ <SetupDiGetDriverInstallParamsW>
ENDIF

SetupDiGetHwProfileFriendlyNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetHwProfileFriendlyName equ <SetupDiGetHwProfileFriendlyNameA>
ENDIF

SetupDiGetHwProfileFriendlyNameExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetHwProfileFriendlyNameEx equ <SetupDiGetHwProfileFriendlyNameExA>
ENDIF

SetupDiGetHwProfileFriendlyNameExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetHwProfileFriendlyNameEx equ <SetupDiGetHwProfileFriendlyNameExW>
ENDIF

SetupDiGetHwProfileFriendlyNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetHwProfileFriendlyName equ <SetupDiGetHwProfileFriendlyNameW>
ENDIF

SetupDiGetHwProfileList PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SetupDiGetHwProfileListExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetHwProfileListEx equ <SetupDiGetHwProfileListExA>
ENDIF

SetupDiGetHwProfileListExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetHwProfileListEx equ <SetupDiGetHwProfileListExW>
ENDIF

SetupDiGetINFClassA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetINFClass equ <SetupDiGetINFClassA>
ENDIF

SetupDiGetINFClassW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetINFClass equ <SetupDiGetINFClassW>
ENDIF

SetupDiGetSelectedDevice PROTO STDCALL :DWORD,:DWORD

SetupDiGetSelectedDriverA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiGetSelectedDriver equ <SetupDiGetSelectedDriverA>
ENDIF

SetupDiGetSelectedDriverW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiGetSelectedDriver equ <SetupDiGetSelectedDriverW>
ENDIF

SetupDiGetWizardPage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

SetupDiInstallClassA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiInstallClass equ <SetupDiInstallClassA>
ENDIF

SetupDiInstallClassExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiInstallClassEx equ <SetupDiInstallClassExA>
ENDIF

SetupDiInstallClassExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiInstallClassEx equ <SetupDiInstallClassExW>
ENDIF

SetupDiInstallClassW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiInstallClass equ <SetupDiInstallClassW>
ENDIF

SetupDiInstallDevice PROTO STDCALL :DWORD,:DWORD
SetupDiInstallDeviceInterfaces PROTO STDCALL :DWORD,:DWORD
SetupDiInstallDriverFiles PROTO STDCALL :DWORD,:DWORD
SetupDiLoadClassIcon PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupDiMoveDuplicateDevice PROTO STDCALL :DWORD,:DWORD
SetupDiOpenClassRegKey PROTO STDCALL :DWORD,:DWORD

SetupDiOpenClassRegKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiOpenClassRegKeyEx equ <SetupDiOpenClassRegKeyExA>
ENDIF

SetupDiOpenClassRegKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiOpenClassRegKeyEx equ <SetupDiOpenClassRegKeyExW>
ENDIF

SetupDiOpenDevRegKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

SetupDiOpenDeviceInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiOpenDeviceInfo equ <SetupDiOpenDeviceInfoA>
ENDIF

SetupDiOpenDeviceInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiOpenDeviceInfo equ <SetupDiOpenDeviceInfoW>
ENDIF

SetupDiOpenDeviceInterfaceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiOpenDeviceInterface equ <SetupDiOpenDeviceInterfaceA>
ENDIF

SetupDiOpenDeviceInterfaceRegKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SetupDiOpenDeviceInterfaceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiOpenDeviceInterface equ <SetupDiOpenDeviceInterfaceW>
ENDIF

SetupDiRegisterCoDeviceInstallers PROTO STDCALL :DWORD,:DWORD
SetupDiRegisterDeviceInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiRemoveDevice PROTO STDCALL :DWORD,:DWORD
SetupDiRemoveDeviceInterface PROTO STDCALL :DWORD,:DWORD
SetupDiSelectBestCompatDrv PROTO STDCALL :DWORD,:DWORD
SetupDiSelectDevice PROTO STDCALL :DWORD,:DWORD
SetupDiSelectOEMDrv PROTO STDCALL :DWORD,:DWORD,:DWORD

SetupDiSetClassInstallParamsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiSetClassInstallParams equ <SetupDiSetClassInstallParamsA>
ENDIF

SetupDiSetClassInstallParamsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiSetClassInstallParams equ <SetupDiSetClassInstallParamsW>
ENDIF

SetupDiSetClassRegistryPropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiSetClassRegistryProperty equ <SetupDiSetClassRegistryPropertyA>
ENDIF

SetupDiSetClassRegistryPropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiSetClassRegistryProperty equ <SetupDiSetClassRegistryPropertyW>
ENDIF

SetupDiSetDeviceInstallParamsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiSetDeviceInstallParams equ <SetupDiSetDeviceInstallParamsA>
ENDIF

SetupDiSetDeviceInstallParamsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiSetDeviceInstallParams equ <SetupDiSetDeviceInstallParamsW>
ENDIF

SetupDiSetDeviceInterfaceDefault PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SetupDiSetDeviceRegistryPropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiSetDeviceRegistryProperty equ <SetupDiSetDeviceRegistryPropertyA>
ENDIF

SetupDiSetDeviceRegistryPropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiSetDeviceRegistryProperty equ <SetupDiSetDeviceRegistryPropertyW>
ENDIF

SetupDiSetDriverInstallParamsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiSetDriverInstallParams equ <SetupDiSetDriverInstallParamsA>
ENDIF

SetupDiSetDriverInstallParamsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiSetDriverInstallParams equ <SetupDiSetDriverInstallParamsW>
ENDIF

SetupDiSetSelectedDevice PROTO STDCALL :DWORD,:DWORD

SetupDiSetSelectedDriverA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDiSetSelectedDriver equ <SetupDiSetSelectedDriverA>
ENDIF

SetupDiSetSelectedDriverW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDiSetSelectedDriver equ <SetupDiSetSelectedDriverW>
ENDIF

SetupDiUnremoveDevice PROTO STDCALL :DWORD,:DWORD

SetupDuplicateDiskSpaceListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupDuplicateDiskSpaceList equ <SetupDuplicateDiskSpaceListA>
ENDIF

SetupDuplicateDiskSpaceListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDuplicateDiskSpaceList equ <SetupDuplicateDiskSpaceListW>
ENDIF

SetupEnumInfSectionsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupEnumInfSections equ <SetupEnumInfSectionsA>
ENDIF

SetupEnumInfSectionsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupEnumInfSections equ <SetupEnumInfSectionsW>
ENDIF

SetupFindFirstLineA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupFindFirstLine equ <SetupFindFirstLineA>
ENDIF

SetupFindFirstLineW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupFindFirstLine equ <SetupFindFirstLineW>
ENDIF

SetupFindNextLine PROTO STDCALL :DWORD,:DWORD

SetupFindNextMatchLineA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupFindNextMatchLine equ <SetupFindNextMatchLineA>
ENDIF

SetupFindNextMatchLineW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupFindNextMatchLine equ <SetupFindNextMatchLineW>
ENDIF

SetupFreeSourceListA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetupFreeSourceList equ <SetupFreeSourceListA>
ENDIF

SetupFreeSourceListW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetupFreeSourceList equ <SetupFreeSourceListW>
ENDIF

SetupGetBackupInformationA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetBackupInformation equ <SetupGetBackupInformationA>
ENDIF

SetupGetBackupInformationW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetBackupInformation equ <SetupGetBackupInformationW>
ENDIF

SetupGetBinaryField PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetFieldCount PROTO STDCALL :DWORD

SetupGetFileCompressionInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetFileCompressionInfo equ <SetupGetFileCompressionInfoA>
ENDIF

SetupGetFileCompressionInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetFileCompressionInfoEx equ <SetupGetFileCompressionInfoExA>
ENDIF

SetupGetFileCompressionInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetFileCompressionInfoEx equ <SetupGetFileCompressionInfoExW>
ENDIF

SetupGetFileCompressionInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetFileCompressionInfo equ <SetupGetFileCompressionInfoW>
ENDIF

SetupGetFileQueueCount PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupGetFileQueueFlags PROTO STDCALL :DWORD,:DWORD

SetupGetInfFileListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetInfFileList equ <SetupGetInfFileListA>
ENDIF

SetupGetInfFileListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetInfFileList equ <SetupGetInfFileListW>
ENDIF

SetupGetInfInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetInfInformation equ <SetupGetInfInformationA>
ENDIF

SetupGetInfInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetInfInformation equ <SetupGetInfInformationW>
ENDIF

SetupGetInfSections PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetupGetIntField PROTO STDCALL :DWORD,:DWORD,:DWORD

SetupGetLineByIndexA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetLineByIndex equ <SetupGetLineByIndexA>
ENDIF

SetupGetLineByIndexW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetLineByIndex equ <SetupGetLineByIndexW>
ENDIF

SetupGetLineCountA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetLineCount equ <SetupGetLineCountA>
ENDIF

SetupGetLineCountW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetLineCount equ <SetupGetLineCountW>
ENDIF

SetupGetLineTextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetLineText equ <SetupGetLineTextA>
ENDIF

SetupGetLineTextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetLineText equ <SetupGetLineTextW>
ENDIF

SetupGetMultiSzFieldA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetMultiSzField equ <SetupGetMultiSzFieldA>
ENDIF

SetupGetMultiSzFieldW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetMultiSzField equ <SetupGetMultiSzFieldW>
ENDIF

SetupGetNonInteractiveMode PROTO STDCALL

SetupGetSourceFileLocationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetSourceFileLocation equ <SetupGetSourceFileLocationA>
ENDIF

SetupGetSourceFileLocationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetSourceFileLocation equ <SetupGetSourceFileLocationW>
ENDIF

SetupGetSourceFileSizeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetSourceFileSize equ <SetupGetSourceFileSizeA>
ENDIF

SetupGetSourceFileSizeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetSourceFileSize equ <SetupGetSourceFileSizeW>
ENDIF

SetupGetSourceInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetSourceInfo equ <SetupGetSourceInfoA>
ENDIF

SetupGetSourceInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetSourceInfo equ <SetupGetSourceInfoW>
ENDIF

SetupGetStringFieldA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetStringField equ <SetupGetStringFieldA>
ENDIF

SetupGetStringFieldW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetStringField equ <SetupGetStringFieldW>
ENDIF

SetupGetTargetPathA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetTargetPath equ <SetupGetTargetPathA>
ENDIF

SetupGetTargetPathW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetTargetPath equ <SetupGetTargetPathW>
ENDIF

SetupInitDefaultQueueCallback PROTO STDCALL :DWORD
SetupInitDefaultQueueCallbackEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

SetupInitializeFileLogA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetupInitializeFileLog equ <SetupInitializeFileLogA>
ENDIF

SetupInitializeFileLogW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetupInitializeFileLog equ <SetupInitializeFileLogW>
ENDIF

SetupInstallFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupInstallFile equ <SetupInstallFileA>
ENDIF

SetupInstallFileExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupInstallFileEx equ <SetupInstallFileExA>
ENDIF

SetupInstallFileExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupInstallFileEx equ <SetupInstallFileExW>
ENDIF

SetupInstallFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupInstallFile equ <SetupInstallFileW>
ENDIF

SetupInstallFilesFromInfSectionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupInstallFilesFromInfSection equ <SetupInstallFilesFromInfSectionA>
ENDIF

SetupInstallFilesFromInfSectionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupInstallFilesFromInfSection equ <SetupInstallFilesFromInfSectionW>
ENDIF

SetupInstallFromInfSectionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupInstallFromInfSection equ <SetupInstallFromInfSectionA>
ENDIF

SetupInstallFromInfSectionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupInstallFromInfSection equ <SetupInstallFromInfSectionW>
ENDIF

SetupInstallServicesFromInfSectionA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupInstallServicesFromInfSection equ <SetupInstallServicesFromInfSectionA>
ENDIF

SetupInstallServicesFromInfSectionExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupInstallServicesFromInfSectionEx equ <SetupInstallServicesFromInfSectionExA>
ENDIF

SetupInstallServicesFromInfSectionExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupInstallServicesFromInfSectionEx equ <SetupInstallServicesFromInfSectionExW>
ENDIF

SetupInstallServicesFromInfSectionW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupInstallServicesFromInfSection equ <SetupInstallServicesFromInfSectionW>
ENDIF

SetupIterateCabinetA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupIterateCabinet equ <SetupIterateCabinetA>
ENDIF

SetupIterateCabinetW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupIterateCabinet equ <SetupIterateCabinetW>
ENDIF

SetupLogErrorA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetupLogError equ <SetupLogErrorA>
ENDIF

SetupLogErrorW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetupLogError equ <SetupLogErrorW>
ENDIF

SetupLogFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupLogFile equ <SetupLogFileA>
ENDIF

SetupLogFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupLogFile equ <SetupLogFileW>
ENDIF

SetupOpenAppendInfFileA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupOpenAppendInfFile equ <SetupOpenAppendInfFileA>
ENDIF

SetupOpenAppendInfFileW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupOpenAppendInfFile equ <SetupOpenAppendInfFileW>
ENDIF

SetupOpenFileQueue PROTO STDCALL

SetupOpenInfFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupOpenInfFile equ <SetupOpenInfFileA>
ENDIF

SetupOpenInfFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupOpenInfFile equ <SetupOpenInfFileW>
ENDIF

SetupOpenLog PROTO STDCALL :DWORD
SetupOpenMasterInf PROTO STDCALL

SetupPrepareQueueForRestoreA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupPrepareQueueForRestore equ <SetupPrepareQueueForRestoreA>
ENDIF

SetupPrepareQueueForRestoreW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupPrepareQueueForRestore equ <SetupPrepareQueueForRestoreW>
ENDIF

SetupPromptForDiskA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupPromptForDisk equ <SetupPromptForDiskA>
ENDIF

SetupPromptForDiskW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupPromptForDisk equ <SetupPromptForDiskW>
ENDIF

SetupPromptReboot PROTO STDCALL :DWORD,:DWORD,:DWORD

SetupQueryDrivesInDiskSpaceListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueryDrivesInDiskSpaceList equ <SetupQueryDrivesInDiskSpaceListA>
ENDIF

SetupQueryDrivesInDiskSpaceListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueryDrivesInDiskSpaceList equ <SetupQueryDrivesInDiskSpaceListW>
ENDIF

SetupQueryFileLogA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueryFileLog equ <SetupQueryFileLogA>
ENDIF

SetupQueryFileLogW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueryFileLog equ <SetupQueryFileLogW>
ENDIF

SetupQueryInfFileInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueryInfFileInformation equ <SetupQueryInfFileInformationA>
ENDIF

SetupQueryInfFileInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueryInfFileInformation equ <SetupQueryInfFileInformationW>
ENDIF

SetupQueryInfOriginalFileInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueryInfOriginalFileInformation equ <SetupQueryInfOriginalFileInformationA>
ENDIF

SetupQueryInfOriginalFileInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueryInfOriginalFileInformation equ <SetupQueryInfOriginalFileInformationW>
ENDIF

SetupQueryInfVersionInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueryInfVersionInformation equ <SetupQueryInfVersionInformationA>
ENDIF

SetupQueryInfVersionInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueryInfVersionInformation equ <SetupQueryInfVersionInformationW>
ENDIF

SetupQuerySourceListA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQuerySourceList equ <SetupQuerySourceListA>
ENDIF

SetupQuerySourceListW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQuerySourceList equ <SetupQuerySourceListW>
ENDIF

SetupQuerySpaceRequiredOnDriveA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQuerySpaceRequiredOnDrive equ <SetupQuerySpaceRequiredOnDriveA>
ENDIF

SetupQuerySpaceRequiredOnDriveW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQuerySpaceRequiredOnDrive equ <SetupQuerySpaceRequiredOnDriveW>
ENDIF

SetupQueueCopyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueueCopy equ <SetupQueueCopyA>
ENDIF

SetupQueueCopyIndirectA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SetupQueueCopyIndirect equ <SetupQueueCopyIndirectA>
ENDIF

SetupQueueCopyIndirectW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SetupQueueCopyIndirect equ <SetupQueueCopyIndirectW>
ENDIF

SetupQueueCopySectionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueueCopySection equ <SetupQueueCopySectionA>
ENDIF

SetupQueueCopySectionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueueCopySection equ <SetupQueueCopySectionW>
ENDIF

SetupQueueCopyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueueCopy equ <SetupQueueCopyW>
ENDIF

SetupQueueDefaultCopyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueueDefaultCopy equ <SetupQueueDefaultCopyA>
ENDIF

SetupQueueDefaultCopyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueueDefaultCopy equ <SetupQueueDefaultCopyW>
ENDIF

SetupQueueDeleteA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueueDelete equ <SetupQueueDeleteA>
ENDIF

SetupQueueDeleteSectionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueueDeleteSection equ <SetupQueueDeleteSectionA>
ENDIF

SetupQueueDeleteSectionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueueDeleteSection equ <SetupQueueDeleteSectionW>
ENDIF

SetupQueueDeleteW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueueDelete equ <SetupQueueDeleteW>
ENDIF

SetupQueueRenameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueueRename equ <SetupQueueRenameA>
ENDIF

SetupQueueRenameSectionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupQueueRenameSection equ <SetupQueueRenameSectionA>
ENDIF

SetupQueueRenameSectionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueueRenameSection equ <SetupQueueRenameSectionW>
ENDIF

SetupQueueRenameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupQueueRename equ <SetupQueueRenameW>
ENDIF

SetupRemoveFileLogEntryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupRemoveFileLogEntry equ <SetupRemoveFileLogEntryA>
ENDIF

SetupRemoveFileLogEntryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupRemoveFileLogEntry equ <SetupRemoveFileLogEntryW>
ENDIF

SetupRemoveFromDiskSpaceListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupRemoveFromDiskSpaceList equ <SetupRemoveFromDiskSpaceListA>
ENDIF

SetupRemoveFromDiskSpaceListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupRemoveFromDiskSpaceList equ <SetupRemoveFromDiskSpaceListW>
ENDIF

SetupRemoveFromSourceListA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetupRemoveFromSourceList equ <SetupRemoveFromSourceListA>
ENDIF

SetupRemoveFromSourceListW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetupRemoveFromSourceList equ <SetupRemoveFromSourceListW>
ENDIF

SetupRemoveInstallSectionFromDiskSpaceListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupRemoveInstallSectionFromDiskSpaceList equ <SetupRemoveInstallSectionFromDiskSpaceListA>
ENDIF

SetupRemoveInstallSectionFromDiskSpaceListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupRemoveInstallSectionFromDiskSpaceList equ <SetupRemoveInstallSectionFromDiskSpaceListW>
ENDIF

SetupRemoveSectionFromDiskSpaceListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupRemoveSectionFromDiskSpaceList equ <SetupRemoveSectionFromDiskSpaceListA>
ENDIF

SetupRemoveSectionFromDiskSpaceListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupRemoveSectionFromDiskSpaceList equ <SetupRemoveSectionFromDiskSpaceListW>
ENDIF

SetupRenameErrorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupRenameError equ <SetupRenameErrorA>
ENDIF

SetupRenameErrorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupRenameError equ <SetupRenameErrorW>
ENDIF


SetupScanFileQueueA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupScanFileQueue equ <SetupScanFileQueueA>
ENDIF

SetupScanFileQueueW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupScanFileQueue equ <SetupScanFileQueueW>
ENDIF

SetupSetDirectoryIdA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupSetDirectoryId equ <SetupSetDirectoryIdA>
ENDIF

SetupSetDirectoryIdExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupSetDirectoryIdEx equ <SetupSetDirectoryIdExA>
ENDIF

SetupSetDirectoryIdExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupSetDirectoryIdEx equ <SetupSetDirectoryIdExW>
ENDIF

SetupSetDirectoryIdW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupSetDirectoryId equ <SetupSetDirectoryIdW>
ENDIF

SetupSetFileQueueAlternatePlatformA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupSetFileQueueAlternatePlatform equ <SetupSetFileQueueAlternatePlatformA>
ENDIF

SetupSetFileQueueAlternatePlatformW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupSetFileQueueAlternatePlatform equ <SetupSetFileQueueAlternatePlatformW>
ENDIF

SetupSetFileQueueFlags PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupSetNonInteractiveMode PROTO STDCALL :DWORD

SetupSetPlatformPathOverrideA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SetupSetPlatformPathOverride equ <SetupSetPlatformPathOverrideA>
ENDIF

SetupSetPlatformPathOverrideW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SetupSetPlatformPathOverride equ <SetupSetPlatformPathOverrideW>
ENDIF

SetupSetSourceListA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupSetSourceList equ <SetupSetSourceListA>
ENDIF

SetupSetSourceListW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupSetSourceList equ <SetupSetSourceListW>
ENDIF

SetupTermDefaultQueueCallback PROTO STDCALL :DWORD
SetupTerminateFileLog PROTO STDCALL :DWORD
SetupUninstallNewlyCopiedInfs PROTO STDCALL :DWORD,:DWORD,:DWORD

SetupUninstallOEMInfA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupUninstallOEMInf equ <SetupUninstallOEMInfA>
ENDIF

SetupUninstallOEMInfW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupUninstallOEMInf equ <SetupUninstallOEMInfW>
ENDIF

SetupVerifyInfFileA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupVerifyInfFile equ <SetupVerifyInfFileA>
ENDIF

SetupVerifyInfFileW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupVerifyInfFile equ <SetupVerifyInfFileW>
ENDIF

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file setupapi.inc
  echo -------------------------------------------
ENDIF
