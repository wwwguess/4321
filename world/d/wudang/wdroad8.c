// wdroad8.c ����·
// by Xiang

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
	������һ����������Ļ���·�ϣ���������ɭɭ�����֡�������һ����ɽ��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
//		"southwest" : "/d/dali/shanlu1",
		"east" : __DIR__"wdroad7",
		"west" : __DIR__"shanmen",
	]));
	set("objects", ([
		__DIR__"npc/yetu" : 2 ]));

	setup();
	replace_program(ROOM);
}

