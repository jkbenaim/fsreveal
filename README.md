fsreveal
===

A tool for showing filesystems known to the IRIX kernel. Basically an exercise of the `sysfs` system call.

The `sysfs` syscall gives information about the filesystems that are understood by the kernel. In particular, it maps filesystem type names like "xfs" to filesystem type indexes like "1". The index is meant to be used with the `mount` system call to indicate the filesystem type to be mounted.

Here's the output on my system, an SGI O2 running IRIX 6.5.30:
```
0
1       xfs
2       umfs
3       lofs
4       autofs
5       nfs
6       nfs3
7       udf
8       efs
9       namefs
10      fd
11      hwgfs
12      fifofs
13      proc
14      pipefs
15      specfs
16
17
18
19
```

