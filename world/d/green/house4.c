// Room: /d/green/house4.c

inherit ROOM;

void create()
{
	set("short", "�峤�ļ�");
	set("long", @LONG
����һ�俴�����е㲻һ������լ�����ӵ�������һ��ʯ�Ƶ�¯�ӣ�
��������һ�ѻ����ܵĻ��������յ�������ƵĹ�����ǽ�Ϲ�������
�ֻ���һ�߻�����һ��ľ�Ƶ���ܣ��������������һЩ�ɵò����پɵ�
�顣¯�ӵ��Ա߰���һ���ֹ�������ʯ�Σ������������Ҫ��λ�á�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/green/field0",
]));
	set("objects", ([
	"/d/green/npc/oldman2" : 1,
	]) );

	setup();
	replace_program(ROOM);
}

