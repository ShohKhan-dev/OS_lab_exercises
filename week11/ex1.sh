#!/bin/bash

fallocate lofs.img -l 50M  # allocate 50M file 

DEVICE=$(sudo losetup -f) # detect free device

sudo losetup $DEVICE lofs.img # create lofset.img

sudo mkfs.ext4 $DEVICE # create filesystem

mkdir -p lofsdisk  # lo
sudo mount $DEVICE lofsdisk

df -h | grep lofsdisk # and demonstrate our points:
