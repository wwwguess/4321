// Room: /d/waterfog/sroad3.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ������ʵ����ʯ������������ɽ��������ɽ�����죬һ
�������İ�ʯ���ݴ�������������ɽ���������������ݵľ�ͷ��һ����
ΰ��¥���Ǿ��������ġ�ˮ�̸󡹡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/d/waterfog/stair1",
  "east" : "/d/waterfog/sroad2",
//  "west" : "/d/temple/sroad"
]));
	set("objects", ([
		__DIR__"npc/guard": 2 ]) );

	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
