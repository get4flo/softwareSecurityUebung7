
/* WARNING: Unknown calling convention */

int 01_main(void)

{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  ulong uVar4;
  char buf [3];
  
  02_setup();
  puts("Hello and welcome to my new experimental Fotispy app !");
  puts("====================================== ===============");
  03_create_user();
  do {
    04_menu();
    iVar1 = getc(stdin);
    buf[0] = (char)iVar1;
    pcVar3 = buf;
    if (buf[0] == '\n') {
LAB_00101253:
      *pcVar3 = '\0';
    }
    else {
      iVar1 = getc(stdin);
      buf[1] = (char)iVar1;
      if (buf[1] == '\n') {
LAB_0010124e:
        pcVar3 = buf + 1;
        goto LAB_00101253;
      }
      do {
        iVar1 = getc(stdin);
      } while ((char)iVar1 != '\n');
      if (buf[1] == '\n') goto LAB_0010124e;
    }
    uVar2 = strtol(buf,(char **)0x0,10);
    switch(uVar2 & 0xffffffff) {
    case 0:
      puts("Bye bye");
      return 0;
    case 1:
      05_edit_user();
      break;
    case 2:
      06_create_playlist();
      break;
    case 3:
      07_edit_playlist();
      break;
    case 4:
      08_show_playlist();
      break;
    case 5:
      09_delete_playlist();
      break;
    case 6:
      10_create_song();
      break;
    case 7:
      11_edit_song();
      break;
    case 8:
      12_show_songs();
      break;
    case 9:
      13_delete_song();
      break;
    case 10:
      if (user.playlist != (playlist *)0x0) {
        uVar2 = 0;
        do {
          pcVar3 = (user.playlist)->name + uVar2;
          uVar4 = uVar2 & 0xffffffff;
          uVar2 = uVar2 + 8;
          __printf_chk(1,"[%#06x] %lx\n",uVar4,*(undefined8 *) pcVar3);
        } while (uVar2 != 0x128);
      }
    }
  } while( true );
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 02_setup(void)

{
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 03_create_user(void)

{
  char *pcVar1;
  user *puVar2;
  int iVar3;
  user *puVar4;
  char *pcVar5;
  
  __printf_chk(1,"[+] Please enter a username: ");
  puVar2 = &user;
  do {
    puVar4 = puVar2;
    iVar3 = getc(stdin);
    puVar4->name[0] = (char)iVar3;
    if ((char)iVar3 == '\n') goto LAB_00101490;
    puVar2 = (user *)(puVar4->name + 1);
  } while ((user *)(puVar4->name + 1) != (user *)user.pass);
  do {
    iVar3 = getc(stdin);
  } while ((char)iVar3 != '\n');
LAB_00101490:
  if (puVar4->name[0] == '\n') {
    puVar4->name[0] = '\0';
  }
  __printf_chk(1,"[+] Please enter a password: ");
  pcVar1 = user.pass;
  do {
    pcVar5 = pcVar1;
    iVar3 = getc(stdin);
    *pcVar5 = (char)iVar3;
    if ((char)iVar3 == '\n') goto LAB_001014f0;
    pcVar1 = pcVar5 + 1;
  } while ((playlist **)(pcVar5 + 1) != &user.playlist);
  do {
    iVar3 = getc(stdin);
  } while ((char)iVar3 != '\n');
LAB_001014f0:
  if (*pcVar5 == '\n') {
    *pcVar5 = '\0';
  }
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 04_menu(void)

{
  __printf_chk(1," === %s ===\n",&user);
  puts("[0] Exit");
  puts("[1] Create Playlist");
  puts("[2] Edit Playlist");
  puts("[3] Show Playlist");
  puts("[4] Delete Playlist");
  puts("[5] Create Song");
  puts("[6] Edit Song");
  puts("[7] Show Song");
  puts("[8] Delete Song");
  __printf_chk(1,"[~] Choice: ");
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 05_edit_user(void)

{
  user *puVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  user *puVar5;
  char buf [2];
  
  __printf_chk(1,"[~] What do you want to edit? [U]sername/[P ]assword: ");
  iVar3 = getc(stdin);
  bVar2 = (byte)iVar3;
  buf[0] = bVar2;
  if (bVar2 == 10) {
    pcVar4 = buf;
  }
  else {
    iVar3 = getc(stdin);
    buf[1] = (char)iVar3;
    if (buf[1] != '\n') {
      do {
        iVar3 = getc(stdin);
      } while ((char)iVar3 != '\n');
      goto LAB_00101560;
    }
    pcVar4 = buf + 1;
  }
  *pcVar4 = '\0';
  bVar2 = buf[0];
LAB_00101560:
  if ((bVar2 & 0xdf) == 0x55) {
    __printf_chk(1,"[+] Please enter the new username: ");
    puVar1 = &user;
    do {
      puVar5 = puVar1;
      iVar3 = getc(stdin);
      puVar5->name[0] = (char)iVar3;
      if ((char)iVar3 == '\n') goto LAB_001015c0;
      puVar1 = (user *)(puVar5->name + 1);
    } while ((user *)(puVar5->name + 1) != (user *)user.pass);
    do {
      iVar3 = getc(stdin);
      if ((char)iVar3 == '\n') break;
      iVar3 = getc(stdin);
    } while ((char)iVar3 != '\n');
  }
  else {
    if ((bVar2 & 0xdf) != 0x50) {
      puts("[-] Please enter a valid choice");
      return;
    }
    __printf_chk(1,"[+] Please enter the new password: ");
    puVar1 = (user *)user.pass;
    do {
      puVar5 = puVar1;
      iVar3 = getc(stdin);
      puVar5->name[0] = (char)iVar3;
      if ((char)iVar3 == '\n') goto LAB_001015c0;
      puVar1 = (user *)(puVar5->name + 1);
    } while ((user *)(puVar5->name + 1) != (user *)&user.playlis t);
    do {
      iVar3 = getc(stdin);
    } while ((char)iVar3 != '\n');
  }
LAB_001015c0:
  if (puVar5->name[0] == '\n') {
    puVar5->name[0] = '\0';
  }
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 06_create_playlist(void)

{
  playlist *ppVar1;
  int iVar2;
  playlist *ppVar3;
  playlist *ppVar4;
  
  ppVar3 = (playlist *)malloc(0x128);
  __printf_chk(1,"[+] Please enter the name of the playlist: ");
  ppVar1 = ppVar3;
  do {
    ppVar4 = ppVar1;
    iVar2 = getc(stdin);
    ppVar4->name[0] = (char)iVar2;
    if ((char)iVar2 == '\n') goto LAB_001016e0;
    ppVar1 = (playlist *)(ppVar4->name + 1);
  } while ((playlist *)(ppVar4->name + 1) != (playlist *)ppVar3- >info);
  do {
    iVar2 = getc(stdin);
  } while ((char)iVar2 != '\n');
LAB_001016e0:
  if (ppVar4->name[0] == '\n') {
    ppVar4->name[0] = '\0';
  }
  __printf_chk(1,"[+] Please enter a fitting description: ");
  ppVar1 = (playlist *)ppVar3->info;
  do {
    ppVar4 = ppVar1;
    iVar2 = getc(stdin);
    ppVar4->name[0] = (char)iVar2;
    if ((char)iVar2 == '\n') goto LAB_00101740;
    ppVar1 = (playlist *)(ppVar4->name + 1);
  } while ((playlist *)(ppVar4->name + 1) != ppVar3 + 1);
  do {
    iVar2 = getc(stdin);
  } while ((char)iVar2 != '\n');
LAB_00101740:
  if (ppVar4->name[0] == '\n') {
    ppVar4->name[0] = '\0';
  }
  user.playlist = ppVar3;
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 07_edit_playlist(void)

{
  playlist *ppVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  playlist *ppVar5;
  playlist *ppVar6;
  char buf [2];
  
  __printf_chk(1,"[~] What do you want to edit? [N]ame/[I]nfo:  ");
  iVar3 = getc(stdin);
  bVar2 = (byte)iVar3;
  buf[0] = bVar2;
  if (bVar2 == 10) {
    pcVar4 = buf;
  }
  else {
    iVar3 = getc(stdin);
    buf[1] = (char)iVar3;
    if (buf[1] != '\n') {
      do {
        iVar3 = getc(stdin);
      } while ((char)iVar3 != '\n');
      goto LAB_001017c0;
    }
    pcVar4 = buf + 1;
  }
  *pcVar4 = '\0';
  bVar2 = buf[0];
LAB_001017c0:
  if ((bVar2 & 0xdf) == 0x4e) {
    __printf_chk(1,"[+] Please enter the new name: ");
    pcVar4 = (user.playlist)->info;
    ppVar1 = user.playlist;
    do {
      ppVar6 = ppVar1;
      iVar3 = getc(stdin);
      ppVar6->name[0] = (char)iVar3;
      if ((char)iVar3 == '\n') goto LAB_001018b0;
      ppVar1 = (playlist *)(ppVar6->name + 1);
    } while ((playlist *)(ppVar6->name + 1) != (playlist *)pcVar4 );
    do {
      iVar3 = getc(stdin);
    } while ((char)iVar3 != '\n');
LAB_001018b0:
    if (ppVar6->name[0] == '\n') {
      ppVar6->name[0] = '\0';
      return;
    }
  }
  else {
    if ((bVar2 & 0xdf) != 0x49) {
      puts("[-] Please enter a valid choice");
      return;
    }
    __printf_chk(1,"[+] Please enter the new description: ");
    ppVar6 = user.playlist + 1;
    ppVar1 = (playlist *)(user.playlist)->info;
    do {
      ppVar5 = ppVar1;
      iVar3 = getc(stdin);
      ppVar5->name[0] = (char)iVar3;
      if ((char)iVar3 == '\n') goto LAB_00101830;
      ppVar1 = (playlist *)(ppVar5->name + 1);
    } while (ppVar6 != (playlist *)(ppVar5->name + 1));
    do {
      iVar3 = getc(stdin);
    } while ((char)iVar3 != '\n');
LAB_00101830:
    if (ppVar5->name[0] == '\n') {
      ppVar5->name[0] = '\0';
    }
  }
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 08_show_playlist(void)

{
  if (user.playlist != (playlist *)0x0) {
    __printf_chk(1,"[~] Name: %s\n");
    __printf_chk(1,"[~] Description: %s\n",(user.playlist)->info);
    return;
  }
  puts("[-] Please create a playlist first.");
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 09_delete_playlist(void)

{
  if (user.playlist != (playlist *)0x0) {
    free(user.playlist);
    return;
  }
  puts("[-] Please create a playlist first.");
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 10_create_song(void)

{
  song *psVar1;
  char *pcVar2;
  int iVar3;
  song *psVar4;
  ulong uVar5;
  song *psVar6;
  char *pcVar7;
  
  uVar5 = 0;
  while (user.songs[uVar5] != (song *)0x0) {
    uVar5 = uVar5 + 1;
    if (uVar5 == 0x20) {
      puts("[-] You already have added too many songs.");
      return;
    }
  }
  psVar4 = (song *)malloc(0xf8);
  __printf_chk(1,"[+] Please enter the title of the song: ");
  psVar1 = psVar4;
  do {
    psVar6 = psVar1;
    iVar3 = getc(stdin);
    psVar6->title[0] = (char)iVar3;
    if ((char)iVar3 == '\n') goto LAB_00101a10;
    psVar1 = (song *)(psVar6->title + 1);
  } while ((song *)(psVar6->title + 1) != (song *)psVar4->albu m);
  do {
    iVar3 = getc(stdin);
  } while ((char)iVar3 != '\n');
LAB_00101a10:
  if (psVar6->title[0] == '\n') {
    psVar6->title[0] = '\0';
  }
  __printf_chk(1,"[+] Please enter the album of the song: ");
  pcVar2 = psVar4->album;
  do {
    pcVar7 = pcVar2;
    iVar3 = getc(stdin);
    *pcVar7 = (char)iVar3;
    if ((char)iVar3 == '\n') goto LAB_00101a70;
    pcVar2 = pcVar7 + 1;
  } while (pcVar7 + 1 != psVar4->artist);
  do {
    iVar3 = getc(stdin);
  } while ((char)iVar3 != '\n');
LAB_00101a70:
  if (*pcVar7 == '\n') {
    *pcVar7 = '\0';
  }
  __printf_chk(1,"[+] Please enter the artist of the song: ");
  psVar1 = (song *)psVar4->artist;
  do {
    psVar6 = psVar1;
    iVar3 = getc(stdin);
    psVar6->title[0] = (char)iVar3;
    if ((char)iVar3 == '\n') goto LAB_00101ad0;
    psVar1 = (song *)(psVar6->title + 1);
  } while ((song *)(psVar6->title + 1) != psVar4 + 1);
  do {
    iVar3 = getc(stdin);
  } while ((char)iVar3 != '\n');
LAB_00101ad0:
  if (psVar6->title[0] == '\n') {
    psVar6->title[0] = '\0';
  }
  user.songs[(int)uVar5] = psVar4;
  __printf_chk(1,"[+] Your song has id: %d\n",uVar5 & 0xfffff fff);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 11_edit_song(void)

{
  song *psVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  song *psVar9;
  char *pcVar10;
  char buf [3];
  
  __printf_chk(1);
  pcVar8 = buf;
  pcVar10 = pcVar8;
  do {
    pcVar6 = pcVar10;
    iVar2 = getc(stdin);
    *pcVar6 = (char)iVar2;
    if ((char)iVar2 == '\n') goto LAB_00101b90;
    pcVar10 = pcVar6 + 1;
  } while (pcVar6 + 1 != &stack0xffffffffffffffd8);
  do {
    iVar2 = getc(stdin);
  } while ((char)iVar2 != '\n');
LAB_00101b90:
  if (*pcVar6 == '\n') {
    *pcVar6 = '\0';
  }
  uVar4 = strtol(pcVar8,(char **)0x0,10);
  if ((0x1f < (byte)uVar4) || (uVar4 = uVar4 & 0xff, user.songs[ uVar4] == (song *)0x0)) {
    puts("[-] Please only enter valid indeces.");
    return;
  }
  __printf_chk(1,"[~] What do you want to change? [T]itle/a[L] bum/a[R]tist: ");
  iVar2 = getc(stdin);
  buf[0] = (char)iVar2;
  if (buf[0] != '\n') {
    iVar2 = getc(stdin);
    buf[1] = (char)iVar2;
    if (buf[1] != '\n') {
      do {
        iVar2 = getc(stdin);
      } while ((char)iVar2 != '\n');
      if (buf[1] != '\n') goto LAB_00101c2b;
    }
    pcVar8 = buf + 1;
  }
  *pcVar8 = '\0';
LAB_00101c2b:
  if ((byte)(buf[0] + 0xb4U) < 0x29) {
    uVar5 = 1L << (buf[0] + 0xb4U & 0x3f);
    if ((uVar5 & 0x4000000040) != 0) {
      __printf_chk(1,"[+] Please enter the new artist of the song: " );
      pcVar8 = user.songs[uVar4]->artist;
      iVar2 = 0;
      do {
        pcVar10 = pcVar8;
        iVar3 = getc(stdin);
        iVar7 = iVar2 + 1;
        *pcVar10 = (char)iVar3;
        if ((char)iVar3 == '\n') goto LAB_00101e65;
        pcVar8 = pcVar10 + 1;
        iVar2 = iVar7;
      } while (iVar7 != 0x58);
      do {
        iVar2 = getc(stdin);
      } while ((char)iVar2 != '\n');
      iVar2 = 0x57;
LAB_00101e65:
      if (*pcVar10 == '\n') {
        *pcVar10 = '\0';
        iVar7 = iVar2;
      }
      user.songs[uVar4]->artist[iVar7] = '\0';
      return;
    }
    if ((uVar5 & 0x100000001) != 0) {
      __printf_chk(1,"[+] Please enter the new album of the song:  ");
      pcVar8 = user.songs[uVar4]->album;
      iVar2 = 0;
      do {
        pcVar10 = pcVar8;
        iVar3 = getc(stdin);
        iVar7 = iVar2 + 1;
        *pcVar10 = (char)iVar3;
        if ((char)iVar3 == '\n') goto LAB_00101dc5;
        pcVar8 = pcVar10 + 1;
        iVar2 = iVar7;
      } while (iVar7 != 0x58);
      do {
        iVar2 = getc(stdin);
      } while ((char)iVar2 != '\n');
      iVar2 = 0x57;
LAB_00101dc5:
      if (*pcVar10 == '\n') {
        *pcVar10 = '\0';
        iVar7 = iVar2;
      }
      user.songs[uVar4]->album[iVar7] = '\0';
      return;
    }
    if ((uVar5 & 0x10000000100) != 0) {
      __printf_chk(1,"[+] Please enter the new title of the song: ") ;
      psVar1 = user.songs[uVar4];
      iVar2 = 0;
      do {
        psVar9 = psVar1;
        iVar3 = getc(stdin);
        iVar7 = iVar2 + 1;
        psVar9->title[0] = (char)iVar3;
        if ((char)iVar3 == '\n') goto LAB_00101ce5;
        psVar1 = (song *)(psVar9->title + 1);
        iVar2 = iVar7;
      } while (iVar7 != 0x48);
      do {
        iVar2 = getc(stdin);
      } while ((char)iVar2 != '\n');
      iVar2 = 0x47;
LAB_00101ce5:
      if (psVar9->title[0] == '\n') {
        psVar9->title[0] = '\0';
        iVar7 = iVar2;
      }
      user.songs[uVar4]->title[iVar7] = '\0';
      return;
    }
  }
  puts("[-] Please enter a valid choice");
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 12_show_songs(void)

{
  song **ppsVar1;
  int iVar2;
  
  iVar2 = 0;
  ppsVar1 = user.songs;
  do {
    if (*ppsVar1 != (song *)0x0) {
      __printf_chk(1,"[%2d] ",iVar2);
      __printf_chk(1,"  Title: %s\n",*ppsVar1);
      __printf_chk(1,"  Album: %s\n",(*ppsVar1)->album);
      __printf_chk(1,"  Artist: %s\n",(*ppsVar1)->artist);
    }
    iVar2 = iVar2 + 1;
    ppsVar1 = ppsVar1 + 1;
  } while (iVar2 != 0x20);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void 13_delete_song(void)

{
  char *pcVar1;
  int iVar2;
  ulong uVar3;
  char *pcVar4;
  char buf [3];
  char local_28 [8];
  
  __printf_chk(1);
  pcVar1 = buf;
  do {
    pcVar4 = pcVar1;
    iVar2 = getc(stdin);
    *pcVar4 = (char)iVar2;
    if ((char)iVar2 == '\n') goto LAB_00101fb0;
    pcVar1 = pcVar4 + 1;
  } while (pcVar4 + 1 != local_28);
  do {
    iVar2 = getc(stdin);
  } while ((char)iVar2 != '\n');
LAB_00101fb0:
  if (*pcVar4 == '\n') {
    *pcVar4 = '\0';
  }
  uVar3 = strtol(buf,(char **)0x0,10);
  if ((byte)uVar3 < 0x20) {
    if (user.songs[uVar3 & 0xff] != (song *)0x0) {
      free(user.songs[uVar3 & 0xff]);
      user.songs[uVar3 & 0xff] = (song *)0x0;
      return;
    }
  }
  puts("[-] Please only enter valid indeces.");
  return;
}


/* WARNING: Unknown calling convention -- yet parameter s torage is locked */

void debug(void)

{
  char *pcVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (user.playlist == (playlist *)0x0) {
    return;
  }
  uVar3 = 0;
  do {
    pcVar1 = (user.playlist)->name + uVar3;
    uVar2 = uVar3 & 0xffffffff;
    uVar3 = uVar3 + 8;
    __printf_chk(1,"[%#06x] %lx\n",uVar2,*(undefined8 *)pcV ar1);
  } while (uVar3 != 0x128);
  return;
}


uint32_t getsn(char *buf,ssize_t len)

{
  int iVar1;
  uint32_t uVar2;
  long lVar3;
  
  lVar3 = 0;
  do {
    uVar2 = (uint32_t)lVar3;
    if (len <= lVar3) goto LAB_001013f0;
    iVar1 = getc(stdin);
    buf[lVar3] = (char)iVar1;
    lVar3 = lVar3 + 1;
  } while ((char)iVar1 != '\n');
  uVar2 = uVar2 + 1;
LAB_00101402:
  if (buf[(long)(int)uVar2 + -1] == '\n') {
    buf[(long)(int)uVar2 + -1] = '\0';
    uVar2 = uVar2 - 1;
  }
  return uVar2;
LAB_001013f0:
  do {
    iVar1 = getc(stdin);
  } while ((char)iVar1 != '\n');
  goto LAB_00101402;
}



