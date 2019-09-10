# Getting Started for Development

When a Jetson board is connected using USB a USB-otg network interface
is created and assigned the address of 192.168.55.1.

## Host

The build scripts utilize `rsync` to efficiently copy files to the
development board.

Edit `~/.ssh/config` to contain the following. You should also create
a key pair stored at `~/.ssh/nvidia`. This key will be used whenever
files are copied or when you create a remote shell. With this config
you do not have to specify the `nvidia` username every time you ssh to
the system.

This config snippet disabled strict host checking and does not record
to the known hosts list. This is done to avoid having to edit the
known hosts file. This would be very bad practice ordinarily but is OK
for development boards.


Contents of `~/.ssh/config`
```
Host 192.168.55.1
	User nvidia
    IdentityFile ~/.ssh/nvidia
    StrictHostKeyChecking no
    UserKnownHostsFile /dev/null
```



## Host
The `configure` script is generated by the `bootstrap` script. A few
options are available:

* --with-system-type: tx2, xavier, or nano. This defaults to 'tx2' and
  influences other defaults like the --with-l4t option.

* --with-l4t: Specify an alternate L4T host directory if you did not
  use the defaults from Nvidia's SDK Manager (e.g. on a build
  machine). This will default to the SDK Manager install path and is
  based on the system-type.

* --with-dtb: Specify a dtb file path for the `flash-dtb` make target.


```sh
# Create configure script
./bootstrap
# Configure the build for xavier with ov10640 on 2xOcto
./configure --with-system-type=xavier --with-dtb=$(realpath build/deploy/boot/d3-xavier-2xocto-ov10640.dtb)

# Prepare the target board for developer use
debug/prep-new-system-from-host
```

## Target
The host side `debug` directory is copied to the target when `make
sync-debug` is executed. This directory contains useful scripts for
developer use on the target.

## Host
The final step is to build and install the kernel and device tree.

```bash
make linux-defconfig
make -j8

# Copy kernel and modules to target. On Xavier use make flash-kernel
#  and make modules-sync instead.
make sync

# Flash device tree (target must be in recovery mode)
make flash-dtb
```