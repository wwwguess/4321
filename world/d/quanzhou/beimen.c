// Room: /d/quanzhou/beimen.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "Ȫ�ݱ���");
	set("long", @LONG
�������Ϸ���һ��Ȫ�ݵı��š��������򱱿ɵ���ԭ,
������һ�Ҳ����۵���վ.
LONG
	);

	set("exits", ([
                "north" : __DIR__"qzroad5",
                "south" : __DIR__"zhongxin",
		"west"  :__DIR__"yizhan",
	]));

	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

