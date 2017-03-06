// Room: /d/snow/eroad2.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ����ͨ�Ļ���С����С��������ͨ��һ��ɽ���ƽ�أ�����
������������ٷ��ݴ�����ƽ���ϣ���������һ·��ɽ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : "/d/snow/eroad3",
  "southwest" : "/d/snow/eroad1",
]));
	set("outdoors", "snow");

	set("objects", ([
		__DIR__"npc/dog": 2 ]) );

	setup();
	replace_program(ROOM);
}
