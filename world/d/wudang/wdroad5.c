// wdroad5.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
	������һ����ʯ����ϣ����ܾ����ĵġ����Ϸ����ƺ���һ������·��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southwest" : __DIR__"wdroad6",
		"north" : __DIR__"wdroad4",
	]));

	setup();
	replace_program(ROOM);
}

