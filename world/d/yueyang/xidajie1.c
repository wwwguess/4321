// Room: /city/xidajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
	����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�����
ϡ�٣������ĵغ������塣������һ�����ֵĹ㳡��
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"guangchang",
		"west" : __DIR__"ximen",
	]));
        set("objects", ([
                __DIR__"npc/wolfdog" : 1,
        ]));


	setup();
	replace_program(ROOM);
}

