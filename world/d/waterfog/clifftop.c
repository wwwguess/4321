// Room: /d/waterfog/clifftop.c

inherit ROOM;

void create()
{
	set("short", "ˮ�̸��ɽͤ");
	set("long", @LONG
������һ���ð�ʯ���ɵ�ͤ�ӣ�ͤ�ӵĶ���ͱ��涼������׵�
���£�����������ȥֻ��һƬ����֮��ͻ������ɽ�壬����֮��������
�Կ�������ˮ����΢�⣬ʹ��һʱ֮���ݷ���Ϊ����ͤ���ǽ���һ����
�У���������ȥ���Կ���ˮ�̸�Ư��������֮�С�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : "/d/waterfog/stair5",
  "southdown" : "/d/waterfog/stair4",
]));
	set("objects", ([
		__DIR__"npc/watcher": 1,
		__DIR__"npc/celes_tiger": 1 ]) );
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
