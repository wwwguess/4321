// Room: /d/green/station1.c

inherit ROOM;

void create()
{
	set("short", "����վ");
	set("long", @LONG
�����ǲ�ʯ���Ĺ���վ�����䰫С�ķ�������ɽ�ڽ��졣���ϵ�ɽ��
��һ�������Ա߻�����ɽһ���Ǭ�����ϣ����������õĳ���ͣ���Ա�
��������ȥ�ǲ�ʯ���Ŀյ�������һ����ʯ���̳ɵ�Сб�£�ͨ����ǰ��
����վ�����߲�Զ����һ�������൱�ر�ķ��ᡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/green/field1",
  "southwest" : "/d/green/station0",
]));
	set("outdoors", "green");
	set("objects", ([
	"/d/green/npc/worker2" :2,
	]) );

	setup();
	replace_program(ROOM);
}
