; --------------------------------------------------------------------------------------------------
;                           wldap32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WLDAP32_INC
WLDAP32_INC equ <1>

LdapGetLastError PROTO C :VARARG
LdapMapErrorToWin32 PROTO C :VARARG
LdapUTF8ToUnicode PROTO C :VARARG
LdapUnicodeToUTF8 PROTO C :VARARG
ber_alloc_t PROTO C :VARARG
ber_bvdup PROTO C :VARARG
ber_bvecfree PROTO C :VARARG
ber_bvfree PROTO C :VARARG
ber_first_element PROTO C :VARARG
ber_flatten PROTO C :VARARG
ber_free PROTO C :VARARG
ber_init PROTO C :VARARG
ber_next_element PROTO C :VARARG
ber_peek_tag PROTO C :VARARG
ber_printf PROTO C :VARARG
ber_scanf PROTO C :VARARG
ber_skip_tag PROTO C :VARARG

cldap_openA PROTO C :VARARG
IFNDEF __UNICODE__
  cldap_open equ <cldap_openA>
ENDIF

cldap_openW PROTO C :VARARG
IFDEF __UNICODE__
  cldap_open equ <cldap_openW>
ENDIF

ldap_abandon PROTO C :VARARG

ldap_addA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_add equ <ldap_addA>
ENDIF

ldap_addW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_add equ <ldap_addW>
ENDIF


ldap_add_extA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_add_ext equ <ldap_add_extA>
ENDIF

ldap_add_extW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_add_ext equ <ldap_add_extW>
ENDIF


ldap_add_ext_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_add_ext_s equ <ldap_add_ext_sA>
ENDIF

ldap_add_ext_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_add_ext_s equ <ldap_add_ext_sW>
ENDIF


ldap_add_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_add_s equ <ldap_add_sA>
ENDIF

ldap_add_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_add_s equ <ldap_add_sW>
ENDIF


ldap_bindA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_bind equ <ldap_bindA>
ENDIF

ldap_bindW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_bind equ <ldap_bindW>
ENDIF


ldap_bind_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_bind_s equ <ldap_bind_sA>
ENDIF

ldap_bind_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_bind_s equ <ldap_bind_sW>
ENDIF

ldap_check_filterA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_check_filter equ <ldap_check_filterA>
ENDIF

ldap_check_filterW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_check_filter equ <ldap_check_filterW>
ENDIF

ldap_cleanup PROTO C :VARARG
ldap_close_extended_op PROTO C :VARARG

ldap_compareA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_compare equ <ldap_compareA>
ENDIF

ldap_compareW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_compare equ <ldap_compareW>
ENDIF


ldap_compare_extA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_compare_ext equ <ldap_compare_extA>
ENDIF

ldap_compare_extW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_compare_ext equ <ldap_compare_extW>
ENDIF


ldap_compare_ext_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_compare_ext_s equ <ldap_compare_ext_sA>
ENDIF

ldap_compare_ext_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_compare_ext_s equ <ldap_compare_ext_sW>
ENDIF


ldap_compare_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_compare_s equ <ldap_compare_sA>
ENDIF

ldap_compare_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_compare_s equ <ldap_compare_sW>
ENDIF

ldap_conn_from_msg PROTO C :VARARG
ldap_connect PROTO C :VARARG

ldap_control_freeA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_control_free equ <ldap_control_freeA>
ENDIF

ldap_control_freeW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_control_free equ <ldap_control_freeW>
ENDIF


ldap_controls_freeA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_controls_free equ <ldap_controls_freeA>
ENDIF

ldap_controls_freeW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_controls_free equ <ldap_controls_freeW>
ENDIF

ldap_count_entries PROTO C :VARARG
ldap_count_references PROTO C :VARARG

ldap_count_valuesA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_count_values equ <ldap_count_valuesA>
ENDIF

ldap_count_valuesW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_count_values equ <ldap_count_valuesW>
ENDIF

ldap_count_values_len PROTO C :VARARG

ldap_create_page_controlA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_create_page_control equ <ldap_create_page_controlA>
ENDIF

ldap_create_page_controlW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_create_page_control equ <ldap_create_page_controlW>
ENDIF


ldap_create_sort_controlA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_create_sort_control equ <ldap_create_sort_controlA>
ENDIF

ldap_create_sort_controlW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_create_sort_control equ <ldap_create_sort_controlW>
ENDIF

ldap_create_vlv_controlA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_create_vlv_control equ <ldap_create_vlv_controlA>
ENDIF

ldap_create_vlv_controlW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_create_vlv_control equ <ldap_create_vlv_controlW>
ENDIF


ldap_deleteA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_delete equ <ldap_deleteA>
ENDIF

ldap_deleteW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_delete equ <ldap_deleteW>
ENDIF


ldap_delete_extA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_delete_ext equ <ldap_delete_extA>
ENDIF

ldap_delete_extW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_delete_ext equ <ldap_delete_extW>
ENDIF


ldap_delete_ext_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_delete_ext_s equ <ldap_delete_ext_sA>
ENDIF

ldap_delete_ext_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_delete_ext_s equ <ldap_delete_ext_sW>
ENDIF


ldap_delete_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_delete_s equ <ldap_delete_sA>
ENDIF

ldap_delete_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_delete_s equ <ldap_delete_sW>
ENDIF


ldap_dn2ufnA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_dn2ufn equ <ldap_dn2ufnA>
ENDIF

ldap_dn2ufnW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_dn2ufn equ <ldap_dn2ufnW>
ENDIF

ldap_encode_sort_controlA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_encode_sort_control equ <ldap_encode_sort_controlA>
ENDIF

ldap_encode_sort_controlW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_encode_sort_control equ <ldap_encode_sort_controlW>
ENDIF


ldap_err2stringA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_err2string equ <ldap_err2stringA>
ENDIF

ldap_err2stringW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_err2string equ <ldap_err2stringW>
ENDIF


ldap_escape_filter_elementA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_escape_filter_element equ <ldap_escape_filter_elementA>
ENDIF

ldap_escape_filter_elementW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_escape_filter_element equ <ldap_escape_filter_elementW>
ENDIF


ldap_explode_dnA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_explode_dn equ <ldap_explode_dnA>
ENDIF

ldap_explode_dnW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_explode_dn equ <ldap_explode_dnW>
ENDIF


ldap_extended_operationA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_extended_operation equ <ldap_extended_operationA>
ENDIF

ldap_extended_operationW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_extended_operation equ <ldap_extended_operationW>
ENDIF

ldap_extended_operation_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_extended_operation_s equ <ldap_extended_operation_sA>
ENDIF

ldap_extended_operation_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_extended_operation_s equ <ldap_extended_operation_sW>
ENDIF


ldap_first_attributeA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_first_attribute equ <ldap_first_attributeA>
ENDIF

ldap_first_attributeW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_first_attribute equ <ldap_first_attributeW>
ENDIF

ldap_first_entry PROTO C :VARARG
ldap_first_reference PROTO C :VARARG

ldap_free_controlsA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_free_controls equ <ldap_free_controlsA>
ENDIF

ldap_free_controlsW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_free_controls equ <ldap_free_controlsW>
ENDIF


ldap_get_dnA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_get_dn equ <ldap_get_dnA>
ENDIF

ldap_get_dnW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_get_dn equ <ldap_get_dnW>
ENDIF

ldap_get_next_page PROTO C :VARARG
ldap_get_next_page_s PROTO C :VARARG

ldap_get_optionA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_get_option equ <ldap_get_optionA>
ENDIF

ldap_get_optionW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_get_option equ <ldap_get_optionW>
ENDIF

ldap_get_paged_count PROTO C :VARARG

ldap_get_valuesA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_get_values equ <ldap_get_valuesA>
ENDIF

ldap_get_valuesW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_get_values equ <ldap_get_valuesW>
ENDIF


ldap_get_values_lenA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_get_values_len equ <ldap_get_values_lenA>
ENDIF

ldap_get_values_lenW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_get_values_len equ <ldap_get_values_lenW>
ENDIF


ldap_initA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_init equ <ldap_initA>
ENDIF

ldap_initW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_init equ <ldap_initW>
ENDIF


ldap_memfreeA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_memfree equ <ldap_memfreeA>
ENDIF

ldap_memfreeW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_memfree equ <ldap_memfreeW>
ENDIF


ldap_modifyA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_modify equ <ldap_modifyA>
ENDIF

ldap_modifyW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_modify equ <ldap_modifyW>
ENDIF


ldap_modify_extA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_modify_ext equ <ldap_modify_extA>
ENDIF

ldap_modify_extW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_modify_ext equ <ldap_modify_extW>
ENDIF


ldap_modify_ext_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_modify_ext_s equ <ldap_modify_ext_sA>
ENDIF

ldap_modify_ext_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_modify_ext_s equ <ldap_modify_ext_sW>
ENDIF


ldap_modify_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_modify_s equ <ldap_modify_sA>
ENDIF

ldap_modify_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_modify_s equ <ldap_modify_sW>
ENDIF

ldap_modrdn PROTO C :VARARG

ldap_modrdn2A PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_modrdn2 equ <ldap_modrdn2A>
ENDIF

ldap_modrdn2W PROTO C :VARARG
IFDEF __UNICODE__
  ldap_modrdn2 equ <ldap_modrdn2W>
ENDIF


ldap_modrdn2_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_modrdn2_s equ <ldap_modrdn2_sA>
ENDIF

ldap_modrdn2_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_modrdn2_s equ <ldap_modrdn2_sW>
ENDIF

ldap_modrdnA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_modrdn equ <ldap_modrdnA>
ENDIF

ldap_modrdnW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_modrdn equ <ldap_modrdnW>
ENDIF


ldap_modrdn_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_modrdn_s equ <ldap_modrdn_sA>
ENDIF

ldap_modrdn_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_modrdn_s equ <ldap_modrdn_sW>
ENDIF

ldap_msgfree PROTO C :VARARG

ldap_next_attributeA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_next_attribute equ <ldap_next_attributeA>
ENDIF

ldap_next_attributeW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_next_attribute equ <ldap_next_attributeW>
ENDIF

ldap_next_entry PROTO C :VARARG
ldap_next_reference PROTO C :VARARG

ldap_openA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_open equ <ldap_openA>
ENDIF

ldap_openW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_open equ <ldap_openW>
ENDIF

ldap_parse_extended_resultA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_parse_extended_result equ <ldap_parse_extended_resultA>
ENDIF

ldap_parse_extended_resultW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_parse_extended_result equ <ldap_parse_extended_resultW>
ENDIF


ldap_parse_page_controlA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_parse_page_control equ <ldap_parse_page_controlA>
ENDIF

ldap_parse_page_controlW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_parse_page_control equ <ldap_parse_page_controlW>
ENDIF


ldap_parse_referenceA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_parse_reference equ <ldap_parse_referenceA>
ENDIF

ldap_parse_referenceW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_parse_reference equ <ldap_parse_referenceW>
ENDIF


ldap_parse_resultA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_parse_result equ <ldap_parse_resultA>
ENDIF

ldap_parse_resultW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_parse_result equ <ldap_parse_resultW>
ENDIF


ldap_parse_sort_controlA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_parse_sort_control equ <ldap_parse_sort_controlA>
ENDIF

ldap_parse_sort_controlW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_parse_sort_control equ <ldap_parse_sort_controlW>
ENDIF

ldap_parse_vlv_controlA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_parse_vlv_control equ <ldap_parse_vlv_controlA>
ENDIF

ldap_parse_vlv_controlW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_parse_vlv_control equ <ldap_parse_vlv_controlW>
ENDIF

ldap_perror PROTO C :VARARG

ldap_rename_extA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_rename_ext equ <ldap_rename_extA>
ENDIF

ldap_rename_extW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_rename_ext equ <ldap_rename_extW>
ENDIF


ldap_rename_ext_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_rename_ext_s equ <ldap_rename_ext_sA>
ENDIF

ldap_rename_ext_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_rename_ext_s equ <ldap_rename_ext_sW>
ENDIF

ldap_result PROTO C :VARARG
ldap_result2error PROTO C :VARARG

ldap_sasl_bindA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_sasl_bind equ <ldap_sasl_bindA>
ENDIF

ldap_sasl_bindW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_sasl_bind equ <ldap_sasl_bindW>
ENDIF

ldap_sasl_bind_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_sasl_bind_s equ <ldap_sasl_bind_sA>
ENDIF

ldap_sasl_bind_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_sasl_bind_s equ <ldap_sasl_bind_sW>
ENDIF


ldap_searchA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_search equ <ldap_searchA>
ENDIF

ldap_searchW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_search equ <ldap_searchW>
ENDIF

ldap_search_abandon_page PROTO C :VARARG

ldap_search_extA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_search_ext equ <ldap_search_extA>
ENDIF

ldap_search_extW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_search_ext equ <ldap_search_extW>
ENDIF


ldap_search_ext_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_search_ext_s equ <ldap_search_ext_sA>
ENDIF

ldap_search_ext_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_search_ext_s equ <ldap_search_ext_sW>
ENDIF


ldap_search_init_pageA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_search_init_page equ <ldap_search_init_pageA>
ENDIF

ldap_search_init_pageW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_search_init_page equ <ldap_search_init_pageW>
ENDIF


ldap_search_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_search_s equ <ldap_search_sA>
ENDIF

ldap_search_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_search_s equ <ldap_search_sW>
ENDIF


ldap_search_stA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_search_st equ <ldap_search_stA>
ENDIF

ldap_search_stW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_search_st equ <ldap_search_stW>
ENDIF

ldap_set_dbg_flags PROTO C :VARARG
ldap_set_dbg_routine PROTO C :VARARG

ldap_set_optionA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_set_option equ <ldap_set_optionA>
ENDIF

ldap_set_optionW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_set_option equ <ldap_set_optionW>
ENDIF


ldap_simple_bindA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_simple_bind equ <ldap_simple_bindA>
ENDIF

ldap_simple_bindW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_simple_bind equ <ldap_simple_bindW>
ENDIF


ldap_simple_bind_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_simple_bind_s equ <ldap_simple_bind_sA>
ENDIF

ldap_simple_bind_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_simple_bind_s equ <ldap_simple_bind_sW>
ENDIF


ldap_sslinitA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_sslinit equ <ldap_sslinitA>
ENDIF

ldap_sslinitW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_sslinit equ <ldap_sslinitW>
ENDIF

ldap_start_tls_sA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_start_tls_s equ <ldap_start_tls_sA>
ENDIF

ldap_start_tls_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_start_tls_s equ <ldap_start_tls_sW>
ENDIF

ldap_startup PROTO C :VARARG
ldap_stop_tls_s PROTO C :VARARG

ldap_ufn2dnA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_ufn2dn equ <ldap_ufn2dnA>
ENDIF

ldap_ufn2dnW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_ufn2dn equ <ldap_ufn2dnW>
ENDIF

ldap_unbind PROTO C :VARARG
ldap_unbind_s PROTO C :VARARG

ldap_value_freeA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_value_free equ <ldap_value_freeA>
ENDIF

ldap_value_freeW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_value_free equ <ldap_value_freeW>
ENDIF

  ; ldap_value_free_len arg type unknown

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file wldap32.inc
  echo ------------------------------------------
ENDIF
