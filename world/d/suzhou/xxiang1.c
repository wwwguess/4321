// Room: /d/suzhou/xxiang1.c
//by dwolf
//97.11.5
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"С����"NOR);
	set("long", @LONG
����һ���谵��С���ӣ���������˲������Ϣ����˵�и��������������û�����˾�
ɱ��������ม��㻹�Ǳ�������ߺá�������Ʀ��������ε���
LONG
	);

	set("exits", ([
		"north" : __DIR__"xx",
		"south" : __DIR__"wroad2",
        ]));

	set("objects", ([
		__DIR__"npc/liumang" : 2,
	]));

	setup();
}

