// Room: /d/snow/mstreet4.c

inherit ROOM;

void create()
{
	set("short", "ѩͤ��ֵ�");
	set("long", @LONG
������ѩͤ��Ĵ�֣�һ��С����ͨ�����ߣ���������һ����վ��
����ѩͤ�����������á���Ա�����ܶ࣬�����Ȼ�ǹٸ�����վ��Ҳ��
�ܰ��յ��ż������������һ��ɽ�꣬������ԶԶ�ؿ�������������Ұ
��ɽ������ɽ�����һ����ʯ·ͨ��ɽ�ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/snow/crossroad",
  "south" : "/d/snow/mstreet3",
  "west" : "/d/snow/postoffice",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
