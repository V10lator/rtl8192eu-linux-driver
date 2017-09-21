/******************************************************************************
 *
 * Copyright(c) 2013 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
/*
 * Description:
 *	This file can be applied to following platforms:
 *	CONFIG_PLATFORM_ARM_SUNXI Series platform 
 *	
 */
 
#include <drv_types.h>

#ifdef CONFIG_PLATFORM_ARM_SUNxI
extern int sw_usb_disable_hcd(__u32 usbc_no);
extern int sw_usb_enable_hcd(__u32 usbc_no);
static int usb_wifi_host = 2;
extern void wifi_pm_power(int on);
#endif

int platform_wifi_power_on(void)
{
	int ret = 0;
	int usb_no = sunxi_wlan_get_usb_index();

	printk("platform_wifi_power_on(), usb_index: %d\n", usb_no);

	return ret;
}

void platform_wifi_power_off(void)
{
	int usb_no = sunxi_wlan_get_usb_index();

	printk("platform_wifi_power_off(), usb_index: %d\n", usb_no);
#ifdef CONFIG_PLATFORM_ARM_SUNxI
#ifndef CONFIG_RTL8723A
	//DBG_8192C("sw_usb_disable_hcd: usbc_num = %d\n", usb_wifi_host);
	sw_usb_disable_hcd(item.val);
	mdelay(100);
	sunxi_wlan_set_power(0);
//	wifi_pm_power(0);
#endif //ifndef CONFIG_RTL8723A
#endif	//CONFIG_PLATFORM_ARM_SUNxI
}

