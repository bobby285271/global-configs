#!/bin/bash
echo "begin clean: $(date)" >> /root/buildarchiso.log
rm -rf /root/Archiso/work /root/Archiso/out
echo "end clean: $(date)" >> /root/buildarchiso.log
echo "begin build: $(date)" >> /root/buildarchiso.log
cd /root/Archiso
./build.sh -v
echo "end build: $(date)" >> /root/buildarchiso.log
if [ -d /root/Archiso/out ]
then
        echo "begin deploy: $(date)" >> /root/buildarchiso.log
        cp /root/Archiso/out/* /srv/http/archiso
        echo "build date:" > /srv/http/archiso/lastbuild.txt
        echo "$(date)" >> /srv/http/archiso/lastbuild.txt
        echo "" >> /srv/http/archiso/lastbuild.txt
        echo "sha256sum:" >> /srv/http/archiso/lastbuild.txt
        sha256sum /srv/http/archiso/dasyatis-autobuild-x86_64.iso |tr -s " " "\t"|cut -f1 >> /srv/http/archiso/lastbuild.txt
        cp /root/Archiso/work/iso/arch/pkglist.x86_64.txt /srv/http/archiso
        echo "end deploy: $(date)" >> /root/buildarchiso.log
else
        echo "reboot: $(date)" >> /root/buildarchiso.log
        reboot
fi
