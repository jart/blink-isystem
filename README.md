# blink-isystem

This repository provides a subset of the Musl Libc and Linux Kernel
headers, where APIs that are incompatible with the [Blink Virtual
Machine](https://github.com/jart/blink) have been commented out. This
will help you compile Linux programs from source that will stand a much
better chance of being successfully emulated across platforms.

The recommended approach is to use GNU Autotools to build your project
on the Alpine Linux distro. We prefer Alpine because it uses Musl Libc
rather than Glibc. Musl works better with Blink right now, because Glibc
uses a lot of esoteric system calls in its implementation details that
are highly Linux-specific and currently not supported by Blink.

## Usage

Clone this repository somewhere on your Alpine Linux machine:

```
cd $HOME
git clone https://github.com/jart/blink-isystem
```

Autotools projects can then be configured as follows:

```
./configure CFLAGS="-isystem $HOME/blink-isystem" \
            CXXFLAGS="-isystem $HOME/blink-isystem" \
            LDFLAGS="-static -Wl,-z,common-page-size=65536,-z,max-page-size=65536"
make -j
```

Using the above flag will cause the headers in this repository to be
favored over the ones provided by Alpine, but only for Musl and Linux.
That way, when autoconf looks for an unsupported interface (e.g.
`timer_create`) it won't be able to find it, in which case the project
should hopefully choose a better interface (e.g. `setitimer`) instead.

## Removed APIs

See the commit log for the definitive information. At a high-level, a
lot of the stuff that's been removed is:

- `syscall(2)`
- `vfork(2)`
- `chroot(2)`
- `*xattr(2)`
- `timer_*(2)`
- `aio_*(2)`
- `mq_*(2)`
- `eventfd*(2)`
- `fanotify*(2)`
- `inotify*(2)`
- `iopl/ioperm`
- `MAP_GROWSDOWN`
- `MAP_STACK`
- `MAP_HUGETLB`
- `MAP_NORESERVE`
- `MAP_LOCKED`
- `PROT_GROWSDOWN`
- `PROT_GROWSUP`
- `madvise(2)`
- `mlock(2)`
- `mount(2)`
- `personality(2)`
- `prctl(2)`
- `ptrace(2)`
- `sendfile(2)`
- `signalfd(2)`
- `sendmmsg(2)`
- `recvmmsg(2)`
- `timerfd*(2)`
- `waitid(2)`
- `__WALL`
- `SIGSTKFLT`
- `O_DIRECT`
- `O_NOATIME`
- `F_GETOWNER_UIDS`
- `F_OFD_*`
- `GIO_UNIMAP` and other framebuffer console stuff
- so many socket options
