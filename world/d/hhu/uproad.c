// Room: /d/hhu/uproad.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
���������ںӺ���ѧУ�ڵ��������
    ���ܷ羰������
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"hhucross",
  "northup" : __DIR__"uproad1",
]));
	set("no_clean_up", 0);

	setup();
}
