# Image deployment

## Burn to USB
Identify the block device of the USB stick and burn using deploytool.
```bash
sudo ./deploytool -e intel-baytrail-64-hdc22-docker_releasegold.tar.bz2 -d /dev/sdX -s 1G -L 90%VG
```
When the tool asks confirmation, verify you are burning to the correct device.

## Burn to GW
Boot from the USB stick and then burn to the gateway flash or internal drive:
```bash
deploytool -d /dev/sda --reset-media -s 1G -F
```

After burning is complete, remove USB Stick and reboot.

## Deploy ConnectedWorker solution
Login as root, uncompress sources and build the containers:
```bash
# login as root:root
cd /root
tar xf connected-worker.tar.gz
cd connected-worker
docker-compose up -d
```
This process may take 20 minutes plus the required time to build the needed docker images.
