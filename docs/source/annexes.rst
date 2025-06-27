.. _sd_card_setup:

Preparing an SD Card for Raspberry Pi 4
======================================

This guide explains how to format an SD card, create partitions, and copy a kernel image for Raspberry Pi 4.

1. Identify the SD Card
-----------------------

.. code-block:: bash

   lsblk

Look for your SD card (typically ``/dev/mmcblk0`` or ``/dev/sdX``).

.. danger::
   All commands below use ``/dev/sdX`` as placeholder. Replace with your actual device!

2. Unmount Partitions
---------------------

.. code-block:: bash

   sudo umount /dev/sdX*

3. Formatting Options
--------------------

Option A: Single Boot Partition (FAT32)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

   sudo mkfs.vfat -F 32 -n "RPI_BOOT" /dev/sdX

Option B: Dual Partition (Recommended)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. Create partitions:

   .. code-block:: bash

      sudo fdisk /dev/sdX

   - Press in sequence: ``o`` → ``n`` → ``p`` → ``1`` → (Enter) → ``+256M``
   - Then: ``n`` → ``p`` → ``2`` → (Enter) → (Enter)
   - Set type: ``t`` → ``1`` → ``c``
   - Write: ``w``

2. Format partitions:

   .. code-block:: bash

      sudo mkfs.vfat -F 32 -n "RPI_BOOT" /dev/sdX1  # Boot
      sudo mkfs.ext4 -L "RPI_ROOT" /dev/sdX2        # RootFS

4. Mount Boot Partition
-----------------------

.. code-block:: bash

   sudo mkdir -p /mnt/sd_boot
   sudo mount /dev/sdX1 /mnt/sd_boot

5. Copy Kernel Files
--------------------

Minimum required files:

.. code-block:: bash

   sudo cp kernel8.img /mnt