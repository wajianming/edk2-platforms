## @file
# X64 Platform with 64-bit DXE.
#
# @copyright
# Copyright 2008 - 2021 Intel Corporation. <BR>
# Copyright (c) 2021, American Megatrends International LLC. <BR>
#
# SPDX-License-Identifier: BSD-2-Clause-Patent
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PEI_ARCH                            = IA32
  DXE_ARCH                            = X64

  !include AdvancedFeaturePkg/Include/AdvancedFeaturesPcd.dsc

[PcdsFixedAtBuild]
  gMinPlatformPkgTokenSpaceGuid.PcdBootStage|6

[PcdsFeatureFlag]
!if $(gMinPlatformPkgTokenSpaceGuid.PcdBootStage) >= 5
  gIpmiFeaturePkgTokenSpaceGuid.PcdIpmiFeatureEnable        |FALSE
  gNetworkFeaturePkgTokenSpaceGuid.PcdNetworkFeatureEnable  |TRUE
!else
  gIpmiFeaturePkgTokenSpaceGuid.PcdIpmiFeatureEnable        |FALSE
  gNetworkFeaturePkgTokenSpaceGuid.PcdNetworkFeatureEnable  |FALSE
!endif

  !include AdvancedFeaturePkg/Include/AdvancedFeatures.dsc
  !include WhitleyOpenBoardPkg/PlatformPkg.dsc

[Defines]
  BOARD_NAME                = SMCIx12SPW
  PLATFORM_NAME             = $(BOARD_NAME)
  PLATFORM_GUID             = F5798629-30B2-42EC-A1CA-825FEAA8A22A
  FLASH_DEFINITION          = $(RP_PKG)/$(BOARD_NAME)/PlatformPkg.fdf

[PcdsFixedAtBuild]

!if $(TARGET) == "RELEASE"
  gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0x0
  gEfiMdePkgTokenSpaceGuid.PcdReportStatusCodePropertyMask|0x03
  gEfiMdeModulePkgTokenSpaceGuid.PcdStatusCodeUseSerial|FALSE
!else
  gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0x2F                   # Enable asserts, prints, code, clear memory, and deadloops on asserts.
  gEfiMdePkgTokenSpaceGuid.PcdReportStatusCodePropertyMask|0x07
  gEfiMdeModulePkgTokenSpaceGuid.PcdStatusCodeUseSerial|FALSE
  #gEfiMdePkgTokenSpaceGuid.PcdFixedDebugPrintErrorLevel|0x80200043      # Built in messages:  Error, MTRR, info, load, warn, init
  gEfiMdePkgTokenSpaceGuid.PcdFixedDebugPrintErrorLevel|0x80200002      # Built in messages:  Error, MTRR, info, load, warn, init
  #gEfiSourceLevelDebugPkgTokenSpaceGuid.PcdDebugLoadImageMethod|0x2     # This is set to INT3 (0x2) for Simics source level debugging
!endif
  gPlatformTokenSpaceGuid.PcdBoardId|0xa0                               # SMCI: IMPORTANT TO NON-INTEL BOARD.

[PcdsFixedAtBuild.X64]
  gPcAtChipsetPkgTokenSpaceGuid.PcdMinimalValidYear|1900
  gPcAtChipsetPkgTokenSpaceGuid.PcdMaximalValidYear|9999

  gMinPlatformPkgTokenSpaceGuid.PcdTrustedConsoleInputDevicePath|{    0x02, 0x01, 0x0C, 0x00, 0xD0, 0x41, 0x03, 0x0A,     0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x06, 0x00,    0x00, 0x1F, 0x02, 0x01, 0x0C, 0x00, 0xD0, 0x41,     0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0e,    0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC2,     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x01,    0x01, 0x03, 0x0a, 0x14, 0x00, 0x53, 0x47, 0xC1,     0xe0, 0xbe, 0xf9, 0xd2, 0x11, 0x9a, 0x0c, 0x00,    0x90, 0x27, 0x3f, 0xc1, 0x4d, 0x7F, 0x01, 0x04, 0x00, 0x03,      0x0F, 0x0B, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x03,       0x01, 0x01, 0x7F, 0xFF, 0x04, 0x00}
  # gMinPlatformPkgTokenSpaceGuid.PcdTrustedConsoleOutputDevicePath|{   0x02, 0x01, 0x0C, 0x00, 0xD0, 0x41, 0x03, 0x0A,     0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x06, 0x00,    0x00, 0x1F, 0x02, 0x01, 0x0C, 0x00, 0xD0, 0x41,     0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0e,    0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC2,     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x01,    0x01, 0x03, 0x0a, 0x14, 0x00, 0x53, 0x47, 0xC1,     0xe0, 0xbe, 0xf9, 0xd2, 0x11, 0x9a, 0x0c, 0x00,    0x90, 0x27, 0x3f, 0xc1, 0x4d, 0x7F, 0x01, 0x04, 0x05, 0x1C,       0x01, 0x0C, 0x00, 0xd0, 0x41, 0x03, 0x0A, 0x00,       0x00, 0x00, 0x00, 0x01, 0x01, 0x06, 0x00,  0x00,       0x02, 0x7F, 0xFF, 0x04, 0x00}
  gMinPlatformPkgTokenSpaceGuid.PcdTrustedConsoleOutputDevicePath|{  0x02,0x01,0x0c,0x00,0xd0,0x41,0x03,0x0a,0x00,0x00,0x00,0x00,   0x01,0x01,0x06,0x00,0x05,0x1C,   0x01,0x01,0x06,0x00,0x00,0x00,   0x01,0x01,0x06,0x00,0x00,0x00,   0x7f,0xff,0x04,0x00} 

  gBoardModulePkgTokenSpaceGuid.PcdSuperIoPciIsaBridgeDevice|{0x0, 0x0, 0x1F, 0x0}

[PcdsDynamicExHii]
  gEfiMdePkgTokenSpaceGuid.PcdPlatformBootTimeOut|L"Timeout"|gEfiGlobalVariableGuid|0x0|5 # Variable: L"Timeout"

[LibraryClasses]
  PlatformHooksLib|$(RP_PKG)/$(BOARD_NAME)/Library/PlatformHooksLib/PlatformHooksLib.inf

[LibraryClasses.Common.PEI_CORE, LibraryClasses.Common.PEIM]
  PeiPlatformHookLib|$(RP_PKG)/$(BOARD_NAME)/Library/PeiPlatformHookLib/PeiPlatformHooklib.inf

!if gIpmiFeaturePkgTokenSpaceGuid.PcdIpmiFeatureEnable == TRUE
  IpmiPlatformHookLib| $(RP_PKG)/$(BOARD_NAME)/Library/IpmiPlatformHookLib/IpmiPlatformHookLib.inf
!endif

[LibraryClasses.X64]
  BoardAcpiTableLib|$(RP_PKG)/$(BOARD_NAME)/Library/BoardAcpiLib/DxeBoardAcpiTableLib.inf

[Components.IA32]
  $(RP_PKG)/Uba/BoardInit/Pei/BoardInitPei.inf {
    <LibraryClasses>
      NULL|$(RP_PKG)/$(BOARD_NAME)/Uba/TypeSMCIx12SPW/Pei/PeiBoardInitLib.inf
      NULL|$(RP_PKG)/Uba/UbaMain/Common/Pei/PeiCommonBoardInitLib.inf
      BiosIdLib|BoardModulePkg/Library/BiosIdLib/PeiBiosIdLib.inf
  }

[Components.X64]
  $(RP_PKG)/Acpi/BoardAcpiDxe/BoardAcpiDxe.inf {
    <BuildOptions>
        MSFT:*_*_*_ASLCC_FLAGS = /D PURLEY_FLAG /D PCH_SPT
        GCC:*_*_*_ASLCC_FLAGS  = -D PURLEY_FLAG -D PCH_SPT
  }

# This is for prebuild only. No need to include in final FDF.
  $(RP_PKG)/Acpi/BoardAcpiDxe/Dsdt.inf {
    <BuildOptions>
        MSFT:*_*_*_ASLCC_FLAGS = /D PURLEY_FLAG /D PCH_SPT
        GCC:*_*_*_ASLCC_FLAGS  = -D PURLEY_FLAG -D PCH_SPT
  }

  # $(RP_PKG)/$(BOARD_NAME)/Uba/TypeSMCIx12SPW/Dxe/BoardInit/BoardInitDxe.inf
  $(RP_PKG)/$(BOARD_NAME)/Uba/TypeSMCIx12SPW/Dxe/UsbOcUpdateDxe/UsbOcUpdateDxe.inf
  $(RP_PKG)/$(BOARD_NAME)/Uba/TypeSMCIx12SPW/Dxe/IioCfgUpdateDxe/IioCfgUpdateDxe.inf
  $(RP_PKG)/$(BOARD_NAME)/Uba/TypeSMCIx12SPW/Dxe/SlotDataUpdateDxe/SlotDataUpdateDxe.inf
  #MdeModulePkg/Bus/Pci/SataControllerDxe/SataControllerDxe.inf
  #edk2-non-osi/Drivers/ASpeed/AST2600BinPkg/AST2600GopDxe.inf
