; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    RUN_SYNCH_PROCESS_EX STRUCT
      priority dd ?       ; priority setting
      timeout  dd ?       ; timeout interval
      rvcreate dd ?       ; CreateProcess() return value
      exitcode dd ?       ; GetExitCodeProcess() exit code
      rvwait   dd ?       ; WaitForSingleObjectEx() return value
    RUN_SYNCH_PROCESS_EX ENDS

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

run_synch_process_ex proc lpfilename:DWORD,lpstruct:DWORD

    LOCAL priority  :DWORD
    LOCAL timeout   :DWORD
    LOCAL rvcreate  :DWORD       ; create process return value
    LOCAL exitcode  :DWORD       ; run process exit code
    LOCAL rvwait    :DWORD       ; wait return value
    LOCAL st_info   :STARTUPINFO
    LOCAL pr_info   :PROCESS_INFORMATION

    mov eax, lpstruct
    mov ecx, (RUN_SYNCH_PROCESS_EX PTR [eax]).priority
    mov priority, eax
    mov ecx, (RUN_SYNCH_PROCESS_EX PTR [eax]).timeout
    mov timeout, eax

  ; ---------------------
  ; zero fill STARTUPINFO
  ; ---------------------
    mov ecx, 17                 ; 68 bytes SIZEOF STARTUPINFO
    lea edx, st_info
    xor eax, eax
  @@:
    mov [edx], eax
    add edx, 4
    sub ecx, 1
    jnz @B

    mov st_info.cb, 68          ; set the structure size member

    invoke CreateProcess,NULL,lpfilename,NULL,NULL,
                         NULL,NULL,NULL,NULL,
                         ADDR st_info,
                         ADDR pr_info
    mov rvcreate, eax

    test eax, eax               ; if CreateProcess fails
    jz quit

    invoke SetPriorityClass,pr_info.hProcess,priority

    invoke WaitForSingleObjectEx,pr_info.hProcess,timeout,0
    mov rvwait, eax

    invoke GetExitCodeProcess,pr_info.hProcess,ADDR exitcode

    invoke CloseHandle, pr_info.hThread
    invoke CloseHandle, pr_info.hProcess

    mov eax, lpstruct
    mov ecx, rvcreate
    mov (RUN_SYNCH_PROCESS_EX PTR [eax]).rvcreate, ecx
    mov ecx, exitcode
    mov (RUN_SYNCH_PROCESS_EX PTR [eax]).exitcode, ecx
    mov ecx, rvwait
    mov (RUN_SYNCH_PROCESS_EX PTR [eax]).rvwait, ecx

    mov eax, rvwait
    mov ecx, exitcode
    mov edx, rvcreate

    ret

  quit:
    mov eax, lpstruct
    mov (RUN_SYNCH_PROCESS_EX PTR [eax]).rvcreate, 0
    mov (RUN_SYNCH_PROCESS_EX PTR [eax]).exitcode, 0
    mov (RUN_SYNCH_PROCESS_EX PTR [eax]).rvwait, 0

    xor eax, eax
    xor ecx, ecx
    xor edx, edx

    ret

run_synch_process_ex endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
