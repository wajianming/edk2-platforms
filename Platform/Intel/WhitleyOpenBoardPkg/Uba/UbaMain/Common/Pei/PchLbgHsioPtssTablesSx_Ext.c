/** @file
  LbgPchH Sx HSIO PTSS C File

  @copyright
  Copyright 2014 - 2021 Intel Corporation. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "PchLbgHsioPtssTablesSx_Ext.h"
#include <PlatformInfoTypes.h>

HSIO_PTSS_TABLES PchLbgHsioPtss_Sx_Ext[] = {
  {{0xA9, 12, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 13, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 14, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 15, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 16, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 17, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 18, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 19, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 20, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 21, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 22, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 23, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 24, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xA9, 25, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x02000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
};

UINT32 PchLbgHsioPtss_Sx_Size_Ext = sizeof (PchLbgHsioPtss_Sx_Ext) / sizeof (PchLbgHsioPtss_Sx_Ext[0]);

