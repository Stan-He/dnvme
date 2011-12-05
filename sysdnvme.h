/*
* NVM Express Compliance Suite
* Copyright (c) 2011, Intel Corporation.
*
* This program is free software; you can redistribute it and/or modify it
* under the terms and conditions of the GNU General Public License,
* version 2, as published by the Free Software Foundation.
*
* This program is distributed in the hope it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along with
* this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef _SYSDNVME_H_
#define _SYSDNVME_H_

#define APPNAME         "dnvme"
#define LEVEL           APPNAME
#define LOG_NRM(fmt, ...)    \
    printk("%s: " fmt "\n", LEVEL, ## __VA_ARGS__)
#define LOG_ERR(fmt, ...)    \
    printk("%s-err:%s:%d: " fmt "\n", \
    LEVEL, __FILE__, __LINE__, ## __VA_ARGS__)
#ifdef DEBUG
#define LOG_DBG(fmt, ...)    \
    printk("%s-dbg:%s:%d: " fmt "\n", \
    LEVEL, __FILE__, __LINE__, ## __VA_ARGS__)
#else
#define LOG_DBG(fmt, ...)
#endif

/* Debug flag for IOCT_SEND_64B module */
#define TEST_PRP_DEBUG

/**
* This definition is intended for making modification or quirks necessary to
* make the driver work with QEMU. This can be commented when an actual NVME
* hardware device is being tested.
*/
#define QEMU

/**
*  NVME Express Device Structure Parameters.
*  the list of devices is maintained in this structure
*  using kernel linked list structure list_head
*/
struct nvme_device_entry {
    struct list_head list; /** linked list head pointer */
    struct pci_dev *pdev; /** pointer to pci device */
    int bus; /** bus number of the pci device */
    int slot; /** slot number of this pci device */
    int func; /** function no. of this pci device*/
    struct gendisk *disk; /** if block device then gendisk type */
    u32    *bar;   /**base address 0 for this device */
    struct list_head namespaces; /** list head linked list for namespaces. */
    char   serial[20]; /** Serial no. for the PCI device. */
    char   model[40]; /** Model no. for this device. */
    char   firmware_rev[8]; /** Firmware revision of NVME device */
};

#endif /* sysdnvme.h*/
