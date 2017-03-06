// Room: /d/waterfog/entrance.c

inherit ROOM;

void create()
{
	set("short", "ˮ�̸�����");
	set("long", @LONG
������ˮ�̸�����ţ�һ��������Ƣ��̴��ʹ�㾫��Ϊ֮һ����
�Ź���������ȫ�������ϵȵ�̴ľ��ɣ��������������һ���Ҷ��
�����ɷ����д���������֣�������ȫȻ������������ʲô�֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"frontyard",
		"west" : __DIR__"westhall",
		"east" : __DIR__"easthall",
		"north" : CLASS_D("fighter") + "/guildhall",
	]));
	set("objects", ([
		__DIR__"npc/guard": 2
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir != "north" || wizardp(me) ) return 1;
	if( me->query_temp("weapon")
	&&	present("waterfog guard", this_object()) ) {
		message("vision", "ˮ�̸���ʿ�ȵ�����������ˮ�̸��ȷ�����ı��У�\n", this_object());
		return notify_fail("ˮ�̸���ʿ��ס�����ȥ·��\n");
	}
	return 1;
}
