// Room: /d/shaolin/shijie1.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��������ɽ��´������ɽɽ�š�һ��������ʯ����ͬ������
���Ѷ��ϣ�ֱû�ƶˡ���ɽȺ���������ɫ��ɽ�����˸������
����С֮�⡣�����м���������С���������ƺ�������������
Щʲô��
LONG
	);

	set("exits", ([
		"east" : __DIR__"rjdtoly1",
		"west" : __DIR__"rjdtoly3",
		"northup" : "/d/shaolin/shijie2",
	]));

	set("objects",([
		"/d/shaolin/npc/xiao-fan" : 1,
		"/d/shaolin/npc/tiao-fu" : 2,
	]));

	set("outdoors", "shaolin");
	setup();replace_program(ROOM);
	replace_program(ROOM);
}



void init() {
	return;
}
