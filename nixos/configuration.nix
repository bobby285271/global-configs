# Edit this configuration file to define what should be installed on
# your system.  Help is available in the configuration.nix(5) man page
# and in the NixOS manual (accessible by running ‘nixos-help’).

{ config, pkgs, ... }:

{
    imports = [
        ./hardware-configuration.nix
    ];

    nix.binaryCaches = [ 
        "https://mirrors.tuna.tsinghua.edu.cn/nix-channels/store"
    ];

    boot = {
        extraModprobeConfig = ''
            options bbswitch load_state=0 unload_state=1
        '';
        extraModulePackages = [ pkgs.linuxPackages.bbswitch ];
        kernelModules = [ "bbswitch" ];
        loader = {
            efi.canTouchEfiVariables = true;
            grub = {
                enable = true;
                device = "nodev";
                useOSProber = true;
                efiSupport = true;
            };
        };
        blacklistedKernelModules = [
            "nouveau"
            "rivafb"
            "nvidiafb"
            "rivatv"
            "nv"
            "uvcvideo"
        ];
    };

    networking = {
        hostName = "inspiron";
        networkmanager.enable = true;
    };

    i18n = {
        defaultLocale = "zh_CN.UTF-8";
        supportedLocales = [ "zh_CN.UTF-8/UTF-8" "en_US.UTF-8/UTF-8" ];
        inputMethod.enabled = "fcitx";
    };

    time.timeZone = "Asia/Shanghai";

    location = {
        latitude = 23.0;
        longitude = 113.0;
    };

    nixpkgs.config.allowUnfree = true;
    environment.systemPackages = with pkgs; 
    [
        dos2unix
        chromium
        fcitx
        fcitx-configtool
        firefox
        gcc
        git
        gptfdisk
        libreoffice-fresh
        neofetch
        pciutils
        python
        transmission
        vim
        wget
        ( vscode-with-extensions.override {
            vscodeExtensions = with vscode-extensions; [
                bbenoist.Nix
                ms-vscode.cpptools
                # ms-python.python
                ms-azuretools.vscode-docker
            ]
            ++ vscode-utils.extensionsFromVscodeMarketplace [ {
                    name = "bracket-pair-colorizer-2";
                    publisher = "CoenraadS";
                    version = "0.0.29";
                    sha256 = "cadb50a21944e6e0293e3872d2fe23b5d2fd2b603ed2bf4a0675fd29bcfb130c";
                } {
                    name = "python";
                    publisher = "ms-python";
                    version = "2020.3.71113";
                    sha256 = "1d8a98a1eed7588dd3b57e4bbe518fcc88f883e066f1b3342453e9bc1a283fdb";
                } {
                    name = "php-intellisense";
                    publisher = "felixfbecker";
                    version = "2.3.14";
                    sha256 = "3798a5de1172b5803877357d0057e3e129d8d82b8fbe0b53ae28c777a0075ca6";
                } {
                    name = "vscode-language-pack-zh-hans";
                    publisher = "MS-CEINTL";
                    version = "1.44.2";
                    sha256 = "4f6ee18ada0e71dd1545ef49f8810f52fe872d2074612faa908d8bf2687400a0";
                }
            ];
        } )
    ];

    fonts = {
        enableDefaultFonts = true;
        fontconfig.enable = true;
        enableFontDir = true;
        enableGhostscriptFonts = true;
        fonts = with pkgs; [
            noto-fonts
            noto-fonts-cjk
            noto-fonts-emoji
            wqy_microhei
            wqy_zenhei
        ];
    };

    services = {
        openssh.enable = true;
        xserver = {
            enable = true;
            layout = "us";
            displayManager.lightdm = {
                enable = true;
                greeters.pantheon.enable = true;
            };
            desktopManager.pantheon.enable = true;
            
        };
        tlp.enable = true;
        mysql = {
            enable = true;
            package = pkgs.mariadb;
        };
        httpd = {
            enable = true;
            adminAddr = "admin@bobby285271.top";
            virtualHosts.localhost.documentRoot = "/srv/html";
            enablePHP = true;
        };
        redshift.enable = true;
    };

    programs.bash.enableCompletion = true;
    sound.enable = true;
    hardware.pulseaudio.enable = true;
    virtualisation.docker.enable = true;
  
    users.users.bobby285271 = { 
        isNormalUser = true;
        home = "/home/bobby285271";
        description = "Bobby Rong";
        extraGroups = [ "wheel" "networkmanager" "docker" ];
    };

    system.stateVersion = "20.03";
}
