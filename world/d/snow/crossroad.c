// Room: /d/snow/crossroad.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ��ɽ�꣬���Ͼ���ѩͤ��һ�����ѵ�С������ͨ����һ
���ڽ���Сɽ�壬һ��ٸ����ĸ�ʾ������·�ԣ�����д���й�Ұ��ɽ
���˳�û�ľ����־��
LONG
	);
	set("outdoors", "snow");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
		"north" : "/d/goathill/mroad1",
		"east" : "/d/green/path6",
		"south" : __DIR__"mstreet4",
                 "west" : "/d/quicksand/huangyie0",
]));

	setup();
	replace_program(ROOM);
}
