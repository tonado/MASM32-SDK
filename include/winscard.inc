; --------------------------------------------------------------------------------------------------
;                          winscard.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WINSCARD_INC
WINSCARD_INC equ <1>

SCardAccessStartedEvent PROTO STDCALL

SCardAddReaderToGroupA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardAddReaderToGroup equ <SCardAddReaderToGroupA>
ENDIF

SCardAddReaderToGroupW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardAddReaderToGroup equ <SCardAddReaderToGroupW>
ENDIF

SCardBeginTransaction PROTO STDCALL :DWORD
SCardCancel PROTO STDCALL :DWORD

SCardConnectA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardConnect equ <SCardConnectA>
ENDIF

SCardConnectW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardConnect equ <SCardConnectW>
ENDIF

SCardControl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardDisconnect PROTO STDCALL :DWORD,:DWORD
SCardEndTransaction PROTO STDCALL :DWORD,:DWORD
SCardEstablishContext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SCardForgetCardTypeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SCardForgetCardType equ <SCardForgetCardTypeA>
ENDIF

SCardForgetCardTypeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SCardForgetCardType equ <SCardForgetCardTypeW>
ENDIF

SCardForgetReaderA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SCardForgetReader equ <SCardForgetReaderA>
ENDIF

SCardForgetReaderGroupA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SCardForgetReaderGroup equ <SCardForgetReaderGroupA>
ENDIF

SCardForgetReaderGroupW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SCardForgetReaderGroup equ <SCardForgetReaderGroupW>
ENDIF

SCardForgetReaderW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SCardForgetReader equ <SCardForgetReaderW>
ENDIF

SCardFreeMemory PROTO STDCALL :DWORD,:DWORD
SCardGetAttrib PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SCardGetCardTypeProviderNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardGetCardTypeProviderName equ <SCardGetCardTypeProviderNameA>
ENDIF

SCardGetCardTypeProviderNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardGetCardTypeProviderName equ <SCardGetCardTypeProviderNameW>
ENDIF

SCardGetProviderIdA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardGetProviderId equ <SCardGetProviderIdA>
ENDIF

SCardGetProviderIdW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardGetProviderId equ <SCardGetProviderIdW>
ENDIF

SCardGetStatusChangeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardGetStatusChange equ <SCardGetStatusChangeA>
ENDIF

SCardGetStatusChangeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardGetStatusChange equ <SCardGetStatusChangeW>
ENDIF

SCardIntroduceCardTypeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardIntroduceCardType equ <SCardIntroduceCardTypeA>
ENDIF

SCardIntroduceCardTypeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardIntroduceCardType equ <SCardIntroduceCardTypeW>
ENDIF

SCardIntroduceReaderA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardIntroduceReader equ <SCardIntroduceReaderA>
ENDIF

SCardIntroduceReaderGroupA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SCardIntroduceReaderGroup equ <SCardIntroduceReaderGroupA>
ENDIF

SCardIntroduceReaderGroupW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SCardIntroduceReaderGroup equ <SCardIntroduceReaderGroupW>
ENDIF

SCardIntroduceReaderW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardIntroduceReader equ <SCardIntroduceReaderW>
ENDIF

SCardIsValidContext PROTO STDCALL :DWORD

SCardListCardsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardListCards equ <SCardListCardsA>
ENDIF

SCardListCardsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardListCards equ <SCardListCardsW>
ENDIF

SCardListInterfacesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardListInterfaces equ <SCardListInterfacesA>
ENDIF

SCardListInterfacesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardListInterfaces equ <SCardListInterfacesW>
ENDIF

SCardListReaderGroupsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardListReaderGroups equ <SCardListReaderGroupsA>
ENDIF

SCardListReaderGroupsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardListReaderGroups equ <SCardListReaderGroupsW>
ENDIF

SCardListReadersA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardListReaders equ <SCardListReadersA>
ENDIF

SCardListReadersW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardListReaders equ <SCardListReadersW>
ENDIF

SCardLocateCardsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardLocateCards equ <SCardLocateCardsA>
ENDIF

SCardLocateCardsByATRA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardLocateCardsByATR equ <SCardLocateCardsByATRA>
ENDIF

SCardLocateCardsByATRW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardLocateCardsByATR equ <SCardLocateCardsByATRW>
ENDIF

SCardLocateCardsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardLocateCards equ <SCardLocateCardsW>
ENDIF

SCardReconnect PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardReleaseContext PROTO STDCALL :DWORD
SCardReleaseStartedEvent PROTO STDCALL

SCardRemoveReaderFromGroupA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardRemoveReaderFromGroup equ <SCardRemoveReaderFromGroupA>
ENDIF

SCardRemoveReaderFromGroupW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardRemoveReaderFromGroup equ <SCardRemoveReaderFromGroupW>
ENDIF

SCardSetAttrib PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SCardSetCardTypeProviderNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardSetCardTypeProviderName equ <SCardSetCardTypeProviderNameA>
ENDIF

SCardSetCardTypeProviderNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardSetCardTypeProviderName equ <SCardSetCardTypeProviderNameW>
ENDIF

SCardState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

SCardStatusA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SCardStatus equ <SCardStatusA>
ENDIF

SCardStatusW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SCardStatus equ <SCardStatusW>
ENDIF

SCardTransmit PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
g_rgSCardRawPci PROTO C :VARARG
g_rgSCardT0Pci PROTO C :VARARG
  ; g_rgSCardT1Pci arg type unknown

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file winscard.inc
  echo -------------------------------------------
ENDIF
