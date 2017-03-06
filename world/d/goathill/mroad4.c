// Room: /d/goathill/mroad4.c

inherit ROOM;

void create()
{
	set("short", "ɽ·ת��");
	set("long", @LONG
������������һ�����ɽ·��ת�Ǵ���ɽ·����ͨ��Ұ��ɽ�ϣ���
��������������߲�Զ����һ��ʯ�������ұڱ��ϣ����������Ǹ��ڻ�
ʲô�ģ����ߵ�ɽ����һ���ѿ�(crack)���������Լ���������ɣ� ��
�ϵ�ɽ·�Ƕζ��͵����£������Ҫ��ɽ����ž�������·�ˡ�
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"mroad5",
		"southdown" : __DIR__"mroad3",
	]));
	set("objects", ([
		__DIR__"npc/bandit" : 3,
		__DIR__"npc/bandit_leader" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
