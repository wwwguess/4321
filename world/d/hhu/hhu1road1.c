// Room: /d/hhu/hhu1road1.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���������ںӺ���ѧУ�ڵ��������
    ���ܷ羰������
LONG
	);
	set("item_desc", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"hhucross",
  "southwest" : __DIR__"hhu1road2",
]));
	set("no_clean_up", 0);

	setup();
}
