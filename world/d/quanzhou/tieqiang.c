// Room: /d/quanzhou/tieqiang.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "��ǹ��");
	set("long", @LONG
����ǹ�����������ʱ������ǹ�����¡�������������������
Ⱥѻ����Ϊ������������˵��ǹ�����ѻ������񽫣�����������
��������������ֳ��Խ��Խ�ࡣ
LONG
	);

	set("exits", ([
                "west" : __DIR__"jxnanmen",
		"north" : __DIR__"nanhu",
	]));

        set("objects", ([
		__DIR__"npc/wuya": 4]));

	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

